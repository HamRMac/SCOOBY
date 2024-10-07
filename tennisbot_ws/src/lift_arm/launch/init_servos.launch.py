import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro


def generate_launch_description():

    # Create a robot_state_publisher node
    params_main_arm= {'input_pin': 17, 'servo_pin': 18, 'debug': True, 'min_angle': 0.0, "max_angle": 180.0,"name":"main_arm"}
    main_arm_ctrl = Node(
        package='lift_arm',
        executable='servo_controller',
        output='screen',
        parameters=[params_main_arm],
        name="main_arm_servo"
    )

    # Add the image_rotator node
    params_rear_flap= {'input_pin': 22, 'servo_pin': 27, 'debug': True, 'min_angle': 5.0, "max_angle": 110.0,"name":"rear_flap"}
    rear_flap_ctrl = Node(
        package='lift_arm',
        executable='servo_controller',
        output='screen',
        parameters=[params_rear_flap],
        name="rear_flap_servo"
    )

    # Launch!
    return LaunchDescription([
        main_arm_ctrl,
        rear_flap_ctrl
    ])
