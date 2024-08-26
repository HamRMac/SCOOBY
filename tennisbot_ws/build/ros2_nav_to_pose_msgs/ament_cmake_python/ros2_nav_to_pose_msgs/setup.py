from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_nav_to_pose_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('ros2_nav_to_pose_msgs', 'ros2_nav_to_pose_msgs.*')),
)
