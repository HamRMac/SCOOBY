from setuptools import find_packages
from setuptools import setup

setup(
    name='yasmin_demos',
    version='2.3.1',
    packages=find_packages(
        include=('yasmin_demos', 'yasmin_demos.*')),
)
