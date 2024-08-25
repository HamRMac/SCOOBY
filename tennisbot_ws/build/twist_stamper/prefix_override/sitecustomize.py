import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/E14Raspberry/ScooperBot/tennisbot_ws/install/twist_stamper'
