import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/E14Raspberry/tennisbot_ws/install/serial_motor_demo'
