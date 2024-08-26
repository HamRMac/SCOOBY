from setuptools import find_packages
from setuptools import setup

setup(
    name='yasmin',
    version='2.3.1',
    packages=find_packages(
        include=('yasmin', 'yasmin.*')),
)
