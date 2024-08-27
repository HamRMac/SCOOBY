# Copyright 2023 Josh Newans
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from geometry_msgs.msg import Twist
import time
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion

class FollowBall(Node):

    def __init__(self):
        super().__init__('follow_ball')
        self.subscription = self.create_subscription(
            Point,
            '/detected_ball',
            self.listener_callback,
            10)
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)


        self.declare_parameter("rcv_timeout_secs", 1.0)
        self.declare_parameter("angular_chase_multiplier", 0.7)
        self.declare_parameter("forward_chase_speed", 0.1)
        self.declare_parameter("search_angular_speed", 0.5)
        self.declare_parameter("max_size_thresh", 0.1)
        self.declare_parameter("filter_value", 0.9)


        self.rcv_timeout_secs = self.get_parameter('rcv_timeout_secs').get_parameter_value().double_value
        self.angular_chase_multiplier = self.get_parameter('angular_chase_multiplier').get_parameter_value().double_value
        self.forward_chase_speed = self.get_parameter('forward_chase_speed').get_parameter_value().double_value
        self.search_angular_speed = self.get_parameter('search_angular_speed').get_parameter_value().double_value
        self.max_size_thresh = self.get_parameter('max_size_thresh').get_parameter_value().double_value
        self.filter_value = self.get_parameter('filter_value').get_parameter_value().double_value

        # Initialize tf2 buffer and listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.scan_direction = 1  # 1 for left, -1 for right
        self.scan_angle = 0.0  # Current scan angle
        self.scan_angle_limit = 45.0  # Maximum scan angle in degrees
        self.initial_yaw = None
        self.current_yaw = None

        self.timer_period = 0.1  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.target_val = 0.0
        self.target_dist = 0.0
        self.lastrcvtime = time.time() - 10000

    def timer_callback(self):
        msg = Twist()
        if (time.time() - self.lastrcvtime < self.rcv_timeout_secs):
            self.get_logger().info('Target: x={} @ dist={}'.format(self.target_val,self.target_dist))
            print(self.target_dist)
            if (self.target_dist < self.max_size_thresh):
                #self.get_logger().info('Approaching Target')
                msg.linear.x = self.forward_chase_speed
            else:
                self.get_logger().info('Reached Target Size')
            msg.angular.z = -self.angular_chase_multiplier*self.target_val
        else:
            self.get_logger().info('Target lost')
            self.perform_scan(msg)
            self.get_logger().info(str(msg))
        self.publisher_.publish(msg)

    def perform_scan(self, msg):
        if self.initial_yaw is None:
            self.initial_yaw = self.get_yaw_from_odom()

        if self.initial_yaw is not None:
            self.current_yaw = self.get_yaw_from_odom()

            if self.current_yaw is not None:
                yaw_diff = self.current_yaw - self.initial_yaw
                self.get_logger().info(str(yaw_diff))
                if self.scan_direction == 1:
                    if yaw_diff >= (self.scan_angle_limit * (3.14159 / 180.0)):  # Convert degrees to radians
                        self.scan_direction = -1
                else:
                    if yaw_diff <= -(self.scan_angle_limit * (3.14159 / 180.0)):
                        self.scan_direction = 1


                msg.angular.z = self.search_angular_speed * self.scan_direction

    def get_yaw_from_odom(self):
        try:
            trans = self.tf_buffer.lookup_transform('odom', 'base_link', rclpy.time.Time())
            rotation = trans.transform.rotation
            _, _, yaw = euler_from_quaternion([rotation.x, rotation.y, rotation.z, rotation.w])
            return yaw
        except Exception as e:
            self.get_logger().warn(f"Failed to get transform: {e}")
            return None

    def listener_callback(self, msg):
        f = self.filter_value
        self.target_val = self.target_val * f + msg.x * (1-f)
        self.target_dist = self.target_dist * f + msg.z * (1-f)
        self.lastrcvtime = time.time()
        self.scan_start_time = time.time()  # Reset the scan start time
        # self.get_logger().info('Received: {} {}'.format(msg.x, msg.y))


def main(args=None):
    rclpy.init(args=args)
    follow_ball = FollowBall()
    rclpy.spin(follow_ball)
    follow_ball.destroy_node()
    rclpy.shutdown()
