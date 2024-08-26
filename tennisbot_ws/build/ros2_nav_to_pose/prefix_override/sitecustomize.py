import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/E14Raspberry/ScooperBot/tennisbot_ws/install/ros2_nav_to_pose'
