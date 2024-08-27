import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro


def generate_launch_description():

    # Create a robot_state_publisher node
    params = {'image_size': [640,480], 'camera_frame_id': "camera_optical_link"}
    node_camera_pub = Node(
        package='v4l2_camera',
        executable='v4l2_camera_node',
        output='screen',
        parameters=[params]
    )


    # Launch!
    return LaunchDescription([
        node_camera_pub
    ])
