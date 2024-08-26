from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.launch_description import LaunchDescription

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    ld = LaunchDescription()

    ld.add_action(DeclareLaunchArgument('lin_gain', default_value='1.0'))
    ld.add_action(DeclareLaunchArgument('rot_gain', default_value='5.0'))
    ld.add_action(DeclareLaunchArgument('lin_max', default_value='0.8'))
    ld.add_action(DeclareLaunchArgument('rot_max', default_value='0.8'))
    ld.add_action(DeclareLaunchArgument('rotation_error_tolerance', default_value='0.2'))
    ld.add_action(DeclareLaunchArgument('dist_error_tolerance', default_value='0.1'))

    declare_node = Node(
        package="ros2_nav_to_pose",
        executable="nav_to_pose_action_server",
        name="nav_to_pose_action_server",
        parameters=[{
            'lin_gain': LaunchConfiguration('lin_gain'),
            'rot_gain': LaunchConfiguration('rot_gain'),
            'lin_max': LaunchConfiguration('Lin_max'),
            'rot_max': LaunchConfiguration('rot_max'),
            'rotation_error_tolerance': LaunchConfiguration('rotation_error_tolerance'),
            'dist_error_tolerance': LaunchConfiguration('dist_error_tolerance'),
        }]
    )

    ld.add_action(declare_node)

    return ld
