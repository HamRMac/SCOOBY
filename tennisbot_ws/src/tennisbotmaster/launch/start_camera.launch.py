import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro


def generate_launch_description():

    # Create a robot_state_publisher node
    params_camera = {'image_size': [640, 480], 'camera_frame_id': "camera_optical_link"}
    node_camera_pub = Node(
        package='v4l2_camera',
        executable='v4l2_camera_node',
        output='screen',
        parameters=[params_camera]
    )

    # Add the image_rotator node
    params_image_rotator = {
        'input_topic': '/image_raw',
        'output_topic': '/camera/rotated_image'
    }
    node_image_rotator = Node(
        package='image_rotator',
        executable='image_rotator_node',
        output='screen',
        parameters=[params_image_rotator]
    )

    # Launch!
    return LaunchDescription([
        node_camera_pub,
        node_image_rotator
    ])
