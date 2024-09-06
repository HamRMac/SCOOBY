from .helpersv2 import PurePursuitController, SimpleNavHelpers

import rclpy.action
import rclpy.node
import rclpy.qos
import rclpy

from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.action.server import ServerGoalHandle

from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Twist
from ros2_nav_to_pose_msgs.action import NavigateToPose

import threading
import time


class ROS2ActionServer(rclpy.node.Node):

    def __init__(self, *args):

        super(ROS2ActionServer, self).__init__("ROS2ActionServer")
        self._goal_handle = None
        self._goal_lock = threading.Lock()

        # Declare parameters with default values
        self.declare_parameter('lin_gain', 1.0)
        self.declare_parameter('rot_gain', 1.0)
        self.declare_parameter('lin_max', 1.0)
        self.declare_parameter('rot_max', 1.5)
        self.declare_parameter('rotation_error_tolerance', 0.1)  # Adjusted for PID
        self.declare_parameter('dist_error_tolerance', 0.15)

        # Retrieve parameters
        lin_gain = self.get_parameter('lin_gain').get_parameter_value().double_value
        rot_gain = self.get_parameter('rot_gain').get_parameter_value().double_value
        lin_max = self.get_parameter('lin_max').get_parameter_value().double_value
        rot_max = self.get_parameter('rot_max').get_parameter_value().double_value
        self.rotation_error_tolerance = self.get_parameter('rotation_error_tolerance').get_parameter_value().double_value
        self.dist_error_tolerance = self.get_parameter('dist_error_tolerance').get_parameter_value().double_value

        self.loop_rate = self.create_rate(10, self.get_clock())

        self.action_server = ActionServer(
            node=self,
            action_type=NavigateToPose,
            action_name="navigate_to_pose",
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            cancel_callback=self.cancel_callback,
            result_timeout=2000)

        self.qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )

        self.pub = self.create_publisher(
            msg_type=Twist,
            topic="cmd_vel",
            qos_profile=self.qos_profile
        )

        self.helpers = SimpleNavHelpers(node=self)

        # Define PID controller parameters
        linear_pid_params = (lin_gain, 0.0, 0.1, -lin_max, lin_max)
        angular_pid_params = (rot_gain, 0.0, 0.1, -rot_max, rot_max)

        min_linear_velocity = 0.3  # Minimum linear velocity to keep wheels moving
        min_angular_velocity = 1.2  # Minimum angular velocity to ensure turning

        self.controller = PurePursuitController(linear_pid_params, angular_pid_params, self.rotation_error_tolerance,min_linear_velocity,min_angular_velocity)

        self.get_logger().info(("Loaded with params:"+
            "lin_gain="+str(lin_gain)+", "
            "rot_gain="+str(rot_gain)+", "
            "lin_max="+str(lin_max)+", "
            "rot_max="+str(rot_max)+", "
            "rotation_error_tolerance="+str(self.rotation_error_tolerance)+", "
            "dist_error_tolerance="+str(self.dist_error_tolerance)
        ))
        self.get_logger().info("Created the navigate_to_pose server v2 (new and improved!) node")

    def goal_callback(self, goal_handle):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal):
        """Accept or reject a client request to cancel an action."""
        self.get_logger().info('Received cancel request')
        return CancelResponse.ACCEPT

    def handle_accepted_callback(self, goal_handle):
        with self._goal_lock:
            # This server only allows one goal at a time
            if self._goal_handle is not None and self._goal_handle.is_active:
                self.get_logger().info('Aborting previous goal')
                # Abort the existing goal
                self._goal_handle.abort()
            self._goal_handle = goal_handle
        goal_handle.execute()

    def execute_callback(self, goal_handle: ServerGoalHandle):
        goal_pose = goal_handle.request.goal_pose
        self.get_logger().info("Received a goal from client")
        self.get_logger().info(str(goal_pose))
        self.get_logger().info("Using frame: "+str(goal_pose.header.frame_id))

        dist_to_goal_satisfied = False
        rot_to_goal_satisfied = False

        feedback_msg = NavigateToPose.Feedback()
        result = NavigateToPose.Result()

        last_time = self.get_clock().now()

        while not (dist_to_goal_satisfied and rot_to_goal_satisfied) and rclpy.ok():

            self.get_logger().debug("Processing goal")

            curr_robot_pose = self.helpers.get_curr_robot_pose(
                now=self.get_clock().now(),
                logger=self.get_logger(),
                frame_id=str(goal_pose.header.frame_id))

            curr_dist_to_goal = self.helpers.pose_euclidean_dist(
                curr_robot_pose.pose, goal_pose.pose)

            dist_error, rot_error = self.controller.compute_error(
                curr_robot_pose, goal_pose)

            if not goal_handle.is_active:
                self.get_logger().info('Goal aborted')
                return NavigateToPose.Result()

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Goal canceled')
                return NavigateToPose.Result()

            if dist_error < self.dist_error_tolerance:
                self.get_logger().info(
                    "We are at goal now! (dist="+str(dist_error)+")")
                dist_to_goal_satisfied = True
                rot_to_goal_satisfied = True

            self.get_logger().debug('Publishing Feedback')
            feedback_msg.remaining_distance_to_goal = curr_dist_to_goal
            goal_handle.publish_feedback(feedback_msg)

            if (dist_to_goal_satisfied and rot_to_goal_satisfied):
                goal_handle.succeed()
                result.success = True
                self.get_logger().info("Navigation was a success")
                self.get_logger().info("Final errors: dist="+str(dist_error)+" rot="+str(rot_error))
                self.pub.publish(Twist())  # Stop the robot
                break

            current_time = self.get_clock().now()
            delta_time = (current_time - last_time).nanoseconds / 1e9
            last_time = current_time

            v_in, w_in = self.controller.compute_velocities(
                curr_robot_pose, goal_pose, delta_time)

            computed_velocity = Twist()
            computed_velocity.linear.x = v_in
            computed_velocity.angular.z = w_in
            self.pub.publish(computed_velocity)

            self.loop_rate.sleep()

        self.get_logger().info('Goal Success!')
        return result


def main():
    rclpy.init()
    action_server = ROS2ActionServer()
    multi_thread_executor = MultiThreadedExecutor()
    rclpy.spin(action_server, executor=multi_thread_executor)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
