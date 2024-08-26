from setuptools import find_packages
from setuptools import setup

setup(
    name='yasmin_ros',
    version='2.3.1',
    packages=find_packages(
        include=('yasmin_ros', 'yasmin_ros.*')),
)
