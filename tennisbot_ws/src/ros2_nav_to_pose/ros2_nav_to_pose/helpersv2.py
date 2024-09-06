import struct
import math
from transforms3d.euler import quat2euler
import sys

from rclpy.time import Duration
from rclpy.time import Time as rclpTime
import tf2_ros
import sensor_msgs.msg as sensor_msgs
from geometry_msgs.msg import PoseStamped
import std_msgs.msg as std_msgs
from sensor_msgs.msg import PointField
from sensor_msgs.msg import PointCloud2
import numpy as np

from math import pi as pi

sys.dont_write_bytecode = True

def normalize_angle(angle):
    # Normalize the angle to be between -pi and pi
    angle = (angle + pi) % (2 * pi) - pi
    return angle

class SimpleNavHelpers():
    def __init__(self, node):
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(
            buffer=self.tf_buffer, node=node)
        self.parent_node = node

    def pose_euclidean_dist(self, a, b):

        return math.sqrt((a.position.x - b.position.x) ** 2 +
                         (a.position.y - b.position.y) ** 2 +
                         (a.position.z - b.position.z) ** 2)

    def get_curr_robot_pose(self, now, logger, frame_id):
        curr_robot_pose = PoseStamped()
        curr_robot_pose.header.frame_id = frame_id
        curr_robot_pose.header.stamp = now.to_msg()
        try:
            transform = self.tf_buffer.lookup_transform(
                frame_id, "base_link", time=rclpTime(seconds=0), timeout=Duration(seconds=0.5))
            curr_robot_pose.pose.position.x = transform.transform.translation.x
            curr_robot_pose.pose.position.y = transform.transform.translation.y
            curr_robot_pose.pose.position.z = transform.transform.translation.z
            curr_robot_pose.pose.orientation = transform.transform.rotation
            # self.parent_node.get_logger().info(str(transform))

        except (tf2_ros.TypeException, tf2_ros.NotImplementedException):
            logger.info("Failed to get current robot pose")
        return curr_robot_pose

    def clip(self, val, min_, max_):
        return min_ if val < min_ else max_ if val > max_ else val


class PIDController():
    def __init__(self, kp, ki, kd, output_min, output_max):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.output_min = output_min
        self.output_max = output_max
        self.integral = 0.0
        self.prev_error = 0.0

    def compute(self, error, delta_time):
        # Proportional term
        p = self.kp * error

        # Integral term
        self.integral += error * delta_time
        i = self.ki * self.integral

        # Derivative term
        d = self.kd * (error - self.prev_error) / delta_time

        # PID output
        output = p + i + d
        output = self.clip(output, self.output_min, self.output_max)

        # Store the error for the next derivative calculation
        self.prev_error = error

        return output

    def clip(self, val, min_, max_):
        return min_ if val < min_ else max_ if val > max_ else val


class PurePursuitController():
    def __init__(self, linear_pid_params, angular_pid_params, heading_threshold=0.1, min_linear_velocity=0.05, min_angular_velocity=0.05):
        self.linear_pid = PIDController(*linear_pid_params)
        self.angular_pid = PIDController(*angular_pid_params)
        self.heading_threshold = heading_threshold  # Heading error tolerance
        self.min_linear_velocity = min_linear_velocity
        self.min_angular_velocity = min_angular_velocity

    def clip(self, val, min_, max_):
        return min_ if val < min_ else max_ if val > max_ else val

    def apply_min_velocity(self, velocity, min_velocity):
        if abs(velocity) > 0 and abs(velocity) < min_velocity:
            return min_velocity if velocity > 0 else -min_velocity
        return velocity

    def compute_error(self, curr_robot_pose, curr_goal_pose):
        robot_quat_exp = [curr_robot_pose.pose.orientation.w, curr_robot_pose.pose.orientation.x,
                          curr_robot_pose.pose.orientation.y, curr_robot_pose.pose.orientation.z]
        robot_euler = quat2euler(robot_quat_exp)

        goal_quat_exp = [curr_goal_pose.pose.orientation.w, curr_goal_pose.pose.orientation.x,
                         curr_goal_pose.pose.orientation.y, curr_goal_pose.pose.orientation.z]
        goal_euler = quat2euler(goal_quat_exp)

        robot_yaw = robot_euler[2]
        goal_yaw = goal_euler[2]

        err_local = [curr_goal_pose.pose.position.x - curr_robot_pose.pose.position.x,
                     curr_goal_pose.pose.position.y - curr_robot_pose.pose.position.y]

        rot_error = math.atan2(err_local[1], err_local[0]) - robot_yaw
        dist_error = math.sqrt(err_local[0]**2 + err_local[1]**2)

        return dist_error, rot_error

    def compute_velocities(self, curr_robot_pose, curr_goal_pose, delta_time):
        dist_error, rot_error = self.compute_error(curr_robot_pose, curr_goal_pose)

        # If the heading error is larger than the threshold, prioritize rotation
        rot_error = normalize_angle(rot_error)
        print(f"RErr: {rot_error}")
        if abs(rot_error) > self.heading_threshold:
            linear_vel = 0.0
            angular_vel = self.angular_pid.compute(rot_error, delta_time)
            angular_vel = self.apply_min_velocity(angular_vel, self.min_angular_velocity)
        else:
            linear_vel = self.linear_pid.compute(dist_error, delta_time)
            angular_vel = self.angular_pid.compute(rot_error, delta_time)
            linear_vel = self.apply_min_velocity(linear_vel, self.min_linear_velocity)

        linear_vel = self.clip(linear_vel, self.linear_pid.output_min, self.linear_pid.output_max)
        angular_vel = self.clip(angular_vel, self.angular_pid.output_min, self.angular_pid.output_max)

        return linear_vel, angular_vel
