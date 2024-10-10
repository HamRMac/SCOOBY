from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.conditions import UnlessCondition

import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():


    params_file = LaunchConfiguration('params_file')
    params_file_dec = DeclareLaunchArgument(
        'params_file',
        default_value=os.path.join(get_package_share_directory('ball_tracker'),'config','ball_tracker_params_example.yaml'),
        description='Full path to params file for all ball_tracker nodes.')

    cmd_vel_topic = LaunchConfiguration('cmd_vel_topic')
    cmd_vel_topic_dec = DeclareLaunchArgument(
    'cmd_vel_topic',
    default_value='/cmd_vel',
    description='The name of the output command vel topic.')

    image_topic = LaunchConfiguration('image_topic')
    image_topic_dec = DeclareLaunchArgument(
        'image_topic',
        default_value='/camera/image_raw',
        description='The name of the input image topic.')

    follow_action_server_node = Node(
            package='ball_tracker',
            executable='follow_ball_action_server',
            parameters=[params_file],
            remappings=[('/cmd_vel',cmd_vel_topic)]
         )

    detect_node = Node(
            package='ball_tracker',
            executable='detect_ball',
            remappings=[('/image_in',image_topic)],
            parameters=[params_file]
         )



    return LaunchDescription([
        params_file_dec,
        cmd_vel_topic_dec,
        detect_node,
        follow_action_server_node,    
    ])
