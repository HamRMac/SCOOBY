from setuptools import setup
from glob import glob

package_name = 'ball_tracker'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*launch.py')),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='e14',
    maintainer_email='NA@mmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'detect_ball = ball_tracker.detect_ball:main',
            'detect_box = ball_tracker.detect_box:main',
            'detect_ball_3d = ball_tracker.detect_ball_3d:main',
            'follow_ball = ball_tracker.follow_ball:main',
            'detect_ball_nn = ball_tracker.detect_ball_nn:main',
            'detect_ball_nn_offload = ball_tracker.detect_ball_nn_offload:main',
            'follow_ball_action_server = ball_tracker.follow_ball_action_server:main',
            'deposit_to_box_action_server = ball_tracker.deposit_to_box_action_server:main'
        ],
    },
)
