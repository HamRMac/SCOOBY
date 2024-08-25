from setuptools import setup
from glob import glob
import os

package_name = 'ros2_nav_to_pose'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*')),
        (os.path.join('share', package_name), glob('params/*')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='E14',
    maintainer_email='NA',
    description='Contains an action server to navigate to location based on a given frame',
    license='TODO: License declaration',
    # Actual ROS nodes
    entry_points={
        'console_scripts': [
            'nav_to_pose_action_server = ros2_nav_to_pose.nav_to_pose_action_server:main',
            'nav_to_pose_action_client = ros2_nav_to_pose.nav_to_pose_action_client:main',
        ],
    },
)
