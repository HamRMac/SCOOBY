#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from yasmin import CbState
from yasmin import StateMachine
from yasmin import Blackboard
from yasmin_ros import ActionState
from yasmin_ros.basic_outcomes import SUCCEED, ABORT
from yasmin_viewer import YasminViewerPub
from ball_tracker_msgs.action import FollowBallAction
from ros2_nav_to_pose_msgs.action import NavigateToPose

from geometry_msgs.msg import Twist

import time

import tf2_ros
from tf2_ros import StaticTransformBroadcaster
from tf2_ros import LookupException, ConnectivityException, ExtrapolationException

from rclpy.time import Duration as rclpDuration
from rclpy.time import Time as rclpTime

import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener, StaticTransformBroadcaster
from geometry_msgs.msg import TransformStamped
from tf2_ros import LookupException, ConnectivityException, ExtrapolationException
from builtin_interfaces.msg import Duration

class WaypointManager:
    def __init__(self, node: Node):
        self.node = node
        self.tf_broadcaster = StaticTransformBroadcaster(self.node)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self.node)

    def create_waypoint(self) -> None:
        t = TransformStamped()
        t.header.stamp = self.node.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'waypoint_frame'

        # Get current transform from 'odom' to 'base_link'
        transform = self.get_current_transform('odom', 'base_link')  # Correct frame order
        if transform:
            t.transform.translation.x = transform.transform.translation.x
            t.transform.translation.y = transform.transform.translation.y
            t.transform.translation.z = transform.transform.translation.z
            t.transform.rotation = transform.transform.rotation

            # Broadcast the transform
            self.tf_broadcaster.sendTransform(t)
            self.node.get_logger().info(f"Waypoint frame 'waypoint_frame' created at {t.transform.translation}")

    def destroy_waypoint(self) -> None:
        # Broadcasting a transform with zero timestamp will remove it
        t = TransformStamped()
        t.header.stamp.sec = 0
        t.header.stamp.nanosec = 0
        t.header.frame_id = 'odom'
        t.child_frame_id = 'waypoint_frame'
        self.tf_broadcaster.sendTransform(t)
        self.node.get_logger().info(f"Waypoint frame 'waypoint_frame' destroyed.")

    def get_current_transform(self, target_frame, source_frame):
        retry_count = 50  # Number of retries to check for the transform
        sleep_duration = 0.5  # Time to wait between retries
        for attempt in range(retry_count):
            rclpy.spin_once(self.node)
            try:
                # Attempt to lookup the transform with a timeout
                self.node.get_logger().info(f"Attempt {attempt+1}: Looking up transform from '{target_frame}' to '{source_frame}'")
                transform = self.tf_buffer.lookup_transform(
                    target_frame, source_frame, time=rclpTime(seconds=0), timeout=rclpDuration(seconds=0.5))  # Correct the time and timeout usage
                self.node.get_logger().info(f"Transform found: {transform}")
                return transform
            except (LookupException, ConnectivityException, ExtrapolationException) as e:
                self.node.get_logger().warn(f'Failed to get transform: {str(e)}. Retrying in {sleep_duration} seconds...')
                self.node.get_clock().sleep_for(rclpy.time.Duration(seconds=sleep_duration))

        self.node.get_logger().error(f'Failed to get transform from {source_frame} to {target_frame} after {retry_count} attempts.')
        return None



class FollowBallActionState(ActionState):
    def __init__(self, node: Node):
        super().__init__(
            FollowBallAction,
            "/follow_ball",
            self.create_goal_handler,
            ["completed", "aborted", "canceled"],
            self.result_handler,
            self.feedback_handler,
        )
        self.node = node

    def create_goal_handler(self, blackboard: Blackboard) -> FollowBallAction.Goal:
        goal = FollowBallAction.Goal()
        return goal

    def feedback_handler(self, blackboard: Blackboard, feedback: FollowBallAction.Feedback) -> None:
        blackboard.current_distance = feedback.current_distance

    def result_handler(self, blackboard: Blackboard, result: FollowBallAction.Result) -> str:
        if result.success:
            return "completed"
        else:
            return "aborted"


def send_goal_pose(node: Node) -> str:
    action_client = ActionClient(node, NavigateToPose, "/navigate_to_pose")

    while not action_client.wait_for_server(timeout_sec=1.0):
        node.get_logger().info("Waiting for action server...")

    goal_msg = NavigateToPose.Goal()
    goal_msg.goal_pose.header.frame_id = "waypoint_frame"
    goal_msg.goal_pose.header.stamp = node.get_clock().now().to_msg()

    goal_msg.goal_pose.pose.position.x = 0.0
    goal_msg.goal_pose.pose.position.y = 0.0
    goal_msg.goal_pose.pose.position.z = 0.0
    goal_msg.goal_pose.pose.orientation.w = 1.0

    send_goal_future = action_client.send_goal_async(goal_msg)

    rclpy.spin_until_future_complete(node, send_goal_future)

    goal_handle = send_goal_future.result()

    if not goal_handle.accepted:
        node.get_logger().info("Goal rejected")
        return ABORT

    result_future = goal_handle.get_result_async()

    rclpy.spin_until_future_complete(node, result_future)

    result = result_future.result().result

    if result.success:
        node.get_logger().info("Goal succeeded!")
        return SUCCEED
    else:
        node.get_logger().info("Goal failed!")
        return ABORT


def create_waypoint(node: Node) -> str:
    waypoint_manager = WaypointManager(node)
    waypoint_manager.create_waypoint()
    # Store waypoint_manager to be accessed later for destruction
    node.get_logger().info("Waypoint created successfully.")
    node.get_clock().destroy_timer = waypoint_manager
    return SUCCEED


def destroy_waypoint(node: Node) -> str:
    if hasattr(node.get_clock(), 'destroy_timer'):
        node.get_clock().destroy_timer.destroy_waypoint()
    node.get_logger().info("Waypoint destroyed successfully.")
    return SUCCEED


class DriveForwardState(CbState):
    def __init__(self, node: Node):
        super().__init__([SUCCEED, ABORT], self.drive_forward)
        self.node = node
        self.publisher = self.node.create_publisher(Twist, '/cmd_vel', 10)

    def drive_forward(self, blackboard: Blackboard) -> str:
        # Create a Twist message to drive forward
        twist = Twist()
        twist.linear.x = 1.5  # 2 m/s forward
        twist.angular.z = 0.0  # No rotation

        # Publish the message and wait for 2 seconds
        self.node.get_logger().info('Driving forward at 2 m/s for 2 seconds...')
        start_time = time.time()

        while time.time() - start_time < 3.0:
            self.publisher.publish(twist)
            self.node.get_clock().sleep_for(rclpy.time.Duration(seconds=0.1))  # Publish at approximately 10 Hz

        # Stop the robot after 2 seconds
        self.node.get_logger().info('Stopping the robot.')
        twist.linear.x = 0.0
        self.publisher.publish(twist)
        self.node.get_clock().sleep_for(rclpy.time.Duration(seconds=1))  # Publish at approximately 10 Hz

        # Return the outcome of the state
        return SUCCEED

class ReverseState(CbState):
    def __init__(self, node: Node):
        super().__init__([SUCCEED, ABORT], self.drive_forward)
        self.node = node
        self.publisher = self.node.create_publisher(Twist, '/cmd_vel', 10)

    def drive_forward(self, blackboard: Blackboard) -> str:
        # Create a Twist message to drive forward
        twist = Twist()
        twist.linear.x = -2.0  # 2 m/s forward
        twist.angular.z = 0.0  # No rotation

        # Publish the message and wait for 2 seconds
        self.node.get_logger().info('Driving backwards at 2 m/s for 2 seconds...')
        start_time = time.time()

        while time.time() - start_time < 2.0:
            self.publisher.publish(twist)
            self.node.get_clock().sleep_for(rclpy.time.Duration(seconds=0.1))  # Publish at approximately 10 Hz

        # Stop the robot after 2 seconds
        self.node.get_logger().info('Stopping the robot.')
        twist.linear.x = 0.0
        self.publisher.publish(twist)

        # Return the outcome of the state
        return SUCCEED

def main():
    print("Starting robot_find_and_return fsm")
    rclpy.init()

    # Create a ROS node
    node = rclpy.create_node('robot_find_and_return')

    # Create the State Machine
    sm = StateMachine(outcomes=["outcome_final"])

    # Add the CREATE_WAYPOINT state
    sm.add_state(
        "CREATE_WAYPOINT",
        CbState([SUCCEED], lambda _: create_waypoint(node)),
        transitions={
            SUCCEED: "FOLLOW_BALL"
        }
    )

    # Add the FOLLOW_BALL state
    sm.add_state(
        "FOLLOW_BALL",
        FollowBallActionState(node),
        transitions={
            "completed": "DRIVE_FORWARD",
            "aborted": "NAVIGATE_HOME",
            "canceled": "NAVIGATE_HOME"
        }
    )

    sm.add_state(
        "DRIVE_FORWARD",
        DriveForwardState(node),
        transitions={
            SUCCEED: 'REVERSE',
            ABORT: 'NAVIGATE_HOME'
        }
    )

    sm.add_state(
        "REVERSE",
        ReverseState(node),
        transitions={
            SUCCEED: 'NAVIGATE_HOME',
            ABORT: 'NAVIGATE_HOME'
        }
    )

    # Add the NAVIGATE_TO_POSE state
    sm.add_state(
        "NAVIGATE_HOME",
        CbState([SUCCEED, ABORT], lambda _: send_goal_pose(node)),
        transitions={
            SUCCEED: "DESTROY_WAYPOINT",
            ABORT: "DESTROY_WAYPOINT"
        }
    )

    # Add the DESTROY_WAYPOINT state
    sm.add_state(
        "DESTROY_WAYPOINT",
        CbState([SUCCEED], lambda _: destroy_waypoint(node)),
        transitions={
            SUCCEED: "outcome_final"
        }
    )

    # Publish FSM info to the YASMIN viewer for visualization
    YasminViewerPub("YASMIN_FIND_AND_RETURN", sm)

    # Execute the FSM
    blackboard = Blackboard()
    outcome = sm(blackboard)
    print(outcome)

    # Clean up
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
