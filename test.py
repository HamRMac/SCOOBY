#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from tf2_ros import Buffer, TransformListener, StaticTransformBroadcaster
from tf2_ros import LookupException, ConnectivityException, ExtrapolationException
from rclpy.time import Time
from builtin_interfaces.msg import Duration
from geometry_msgs.msg import TransformStamped


class WaypointManager:
    def __init__(self, node: Node):
        self.node = node
        self.tf_broadcaster = StaticTransformBroadcaster(self.node)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self.node, spin_thread=True)

    def create_waypoint(self) -> None:
        t = TransformStamped()
        t.header.stamp = self.node.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'waypoint_frame'

        # Get current transform from 'odom' to 'base_link'
        transform = self.get_current_transform('odom', 'base_link')
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
        retry_count = 10  # Number of retries to check for the transform
        sleep_duration = 0.5  # Time to wait between retries
        for attempt in range(retry_count):
            try:
                # Attempt to lookup the transform with a timeout
                self.node.get_logger().info(f"Attempt {attempt+1}: Looking up transform from '{target_frame}' to '{source_frame}'")
                transform = self.tf_buffer.lookup_transform(
                    target_frame, source_frame, Time(seconds=0))
                self.node.get_logger().info(f"Transform found: {transform}")
                return transform
            except (LookupException, ConnectivityException, ExtrapolationException) as e:
                self.node.get_logger().warn(f'Failed to get transform: {str(e)}. Retrying in {sleep_duration} seconds...')
                self.node.get_clock().sleep_for(rclpy.time.Duration(seconds=sleep_duration))

        self.node.get_logger().error(f'Failed to get transform from {source_frame} to {target_frame} after {retry_count} attempts.')
        return None


def main(args=None):
    rclpy.init(args=args)

    # Create a ROS 2 node
    node = Node('waypoint_manager_test')

    # Instantiate the WaypointManager
    waypoint_manager = WaypointManager(node)

    # Attempt to create a waypoint
    node.get_logger().info("Creating waypoint...")
    waypoint_manager.create_waypoint()

    # Sleep for 2 seconds to observe the waypoint creation
    node.get_clock().sleep_for(rclpy.time.Duration(seconds=2))

    # Attempt to destroy the waypoint
    node.get_logger().info("Destroying waypoint...")
    waypoint_manager.destroy_waypoint()

    # Shutdown ROS 2
    waypoint_manager.tf_listener.clear()  # Clear the listener data (if applicable)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

