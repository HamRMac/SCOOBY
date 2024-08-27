from setuptools import find_packages
from setuptools import setup

setup(
    name='ball_tracker_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('ball_tracker_msgs', 'ball_tracker_msgs.*')),
)
