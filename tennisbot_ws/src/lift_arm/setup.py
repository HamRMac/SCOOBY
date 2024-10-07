import os
from setuptools import find_packages, setup
from glob import glob

package_name = 'lift_arm'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all launch files.
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='E14Raspberry',
    maintainer_email='E14Tennisbot@MonashBots.bots',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'servo_controller = lift_arm.servo_controller:main',
            'servo_controller_remote = lift_arm.servo_controller_remote:main'
        ],
    },
)
