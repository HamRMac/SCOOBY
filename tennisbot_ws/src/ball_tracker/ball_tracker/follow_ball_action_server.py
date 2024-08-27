import rclpy
import threading
import time
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Point, Twist
from ball_tracker_msgs.action import FollowBallAction  # Ensure this action is defined in your package

class FollowBallActionServer(Node):

    def __init__(self):
        super().__init__('follow_ball_action_server')
        self._goal_handle = None
        self._goal_lock = threading.Lock()

        # Declare parameters with default values
        self.declare_parameter("rcv_timeout_secs", 1.0)
        self.declare_parameter("angular_chase_multiplier", 0.7)
        self.declare_parameter("forward_chase_speed", 0.1)
        self.declare_parameter("search_angular_speed", 0.5)
        self.declare_parameter("max_size_thresh", 0.1)
        self.declare_parameter("filter_value", 0.9)

        # Retrieve parameters
        self.rcv_timeout_secs = self.get_parameter('rcv_timeout_secs').get_parameter_value().double_value
        self.angular_chase_multiplier = self.get_parameter('angular_chase_multiplier').get_parameter_value().double_value
        self.forward_chase_speed = self.get_parameter('forward_chase_speed').get_parameter_value().double_value
        self.search_angular_speed = self.get_parameter('search_angular_speed').get_parameter_value().double_value
        self.max_size_thresh = self.get_parameter('max_size_thresh').get_parameter_value().double_value
        self.filter_value = self.get_parameter('filter_value').get_parameter_value().double_value

        # Setup the action server
        self.action_server = ActionServer(
            node=self,
            action_type=FollowBallAction,
            action_name='follow_ball',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            cancel_callback=self.cancel_callback,
            result_timeout=2000
        )

        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription = self.create_subscription(Point, '/detected_ball', self.listener_callback, 10)
        
        self.target_val = 0.0
        self.target_dist = 0.0
        self.lastrcvtime = time.time() - 10000

    def goal_callback(self, goal_handle):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal):
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

    def execute_callback(self, goal_handle):
        self.get_logger().info("Executing goal")

        feedback_msg = FollowBallAction.Feedback()
        result = FollowBallAction.Result()

        while rclpy.ok():
            msg = Twist()
            if (time.time() - self.lastrcvtime < self.rcv_timeout_secs):
                self.get_logger().info('Target: x={} @ dist={}'.format(self.target_val, self.target_dist))
                if (self.target_dist < self.max_size_thresh):
                    msg.linear.x = self.forward_chase_speed
                else:
                    self.get_logger().info('Reached Target Size')
                msg.angular.z = -self.angular_chase_multiplier * self.target_val
            else:
                self.get_logger().info('Target lost')
                msg.angular.z = self.search_angular_speed

            self.publisher_.publish(msg)

            # Provide feedback to the client
            feedback_msg.current_distance = self.target_dist
            goal_handle.publish_feedback(feedback_msg)

            if self.target_dist < self.max_size_thresh:
                self.get_logger().info('Goal threshold reached, completing goal')
                result.success = True
                goal_handle.succeed()
                return result

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Goal canceled')
                return FollowBallAction.Result()

    def listener_callback(self, msg):
        f = self.filter_value
        self.target_val = self.target_val * f + msg.x * (1 - f)
        self.target_dist = self.target_dist * f + msg.z * (1 - f)
        self.lastrcvtime = time.time()


def main(args=None):
    rclpy.init(args=args)
    action_server = FollowBallActionServer()
    multi_thread_executor = MultiThreadedExecutor()
    rclpy.spin(action_server, executor=multi_thread_executor)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
