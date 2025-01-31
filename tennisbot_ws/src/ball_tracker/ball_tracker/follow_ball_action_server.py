import rclpy
import threading
import time
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Point, Twist
from std_msgs.msg import Bool
from ball_tracker_msgs.action import FollowBallAction  # Ensure this action is defined in your package
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion
from math import pi as pi

def normalize_angle(angle):
    # Normalize the angle to be between -pi and pi
    angle = (angle + pi) % (2 * pi) - pi
    return angle

class FollowBallActionServer(Node):

    def __init__(self):
        super().__init__('follow_ball_action_server')
        self.get_logger().info('follow_ball_action_server is starting... Please wait')
        self._goal_handle = None
        self._goal_lock = threading.Lock()

        # Declare parameters with default values
        self.declare_parameter("rcv_timeout_secs", 1.0)
        self.declare_parameter("angular_chase_multiplier", 0.7)
        self.declare_parameter("forward_chase_speed", 0.3)
        self.declare_parameter("min_forward_chase_speed", 0.25)
        self.declare_parameter("search_angular_speed", 2.0)
        self.declare_parameter("max_angular_speed", 2.0)
        self.declare_parameter("min_angular_speed", 1.8)
        self.declare_parameter("max_size_thresh", 0.1)
        self.declare_parameter("filter_value", 0.9)
        self.declare_parameter("forward_distance", 0.1)
        self.declare_parameter("creep_speed", 0.6)  # New parameter for creep speed
        self.declare_parameter("creep_rotation_compensation", 0)  # New parameter for rotation compensation
        self.declare_parameter("creep_timeout_secs", 10.0)  # Timeout for forward creep motion
        self.declare_parameter('alignment_threshold', 0.1)
        

        # Retrieve parameters
        self.rcv_timeout_secs = self.get_parameter('rcv_timeout_secs').get_parameter_value().double_value
        self.angular_chase_multiplier = self.get_parameter('angular_chase_multiplier').get_parameter_value().double_value
        self.forward_chase_speed = self.get_parameter('forward_chase_speed').get_parameter_value().double_value
        self.min_forward_chase_speed = self.get_parameter('min_forward_chase_speed').get_parameter_value().double_value
        self.search_angular_speed = self.get_parameter('search_angular_speed').get_parameter_value().double_value
        self.max_size_thresh = self.get_parameter('max_size_thresh').get_parameter_value().double_value
        self.filter_value = self.get_parameter('filter_value').get_parameter_value().double_value
        self.max_angular_speed = self.get_parameter('max_angular_speed').get_parameter_value().double_value
        self.min_angular_speed = self.get_parameter('min_angular_speed').get_parameter_value().double_value
        self.return_scan_scale = self.search_angular_speed - self.min_angular_speed
        self.forward_distance = self.get_parameter('forward_distance').get_parameter_value().double_value
        self.creep_speed = self.get_parameter('creep_speed').get_parameter_value().double_value
        self.creep_rotation_compensation = self.get_parameter('creep_rotation_compensation').get_parameter_value().double_value
        self.creep_timeout_secs = self.get_parameter('creep_timeout_secs').get_parameter_value().double_value
        self.alignment_threshold = self.get_parameter('alignment_threshold').value

        self.get_logger().info('Using parameters:'+
                               " rcv_timeout_secs: "+str(self.rcv_timeout_secs)+
                                " angular_chase_multiplier: "+str(self.angular_chase_multiplier)+
                                " forward_chase_speed: "+str(self.forward_chase_speed)+
                                " min_forward_chase_speed: "+str(self.min_forward_chase_speed)+
                                " search_angular_speed: "+str(self.search_angular_speed)+
                                " max_size_thresh: "+str(self.max_size_thresh)+
                                " filter_value: "+str(self.filter_value)+
                                " min_angular_speed: "+str(self.min_angular_speed)+
                                " return_scan_scale: "+str(self.return_scan_scale)+
                                " forward_distance: "+str(self.forward_distance) +
                                " creep_speed: "+str(self.creep_speed)+
                                " creep_rotation_compensation: "+str(self.creep_rotation_compensation)+
                                " creep_timeout_secs: "+str(self.creep_timeout_secs)
                               )

        # Initialize tf2 buffer and listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.scan_direction = 1  # 1 for left, -1 for right
        self.scan_angle = 0.0  # Current scan angle
        self.scan_angle_limit = 75.0  # Maximum scan angle in degrees
        self.scan_angle_limit_rad = self.scan_angle_limit * (3.14159 / 180.0)

        self.initial_yaw = None
        self.current_yaw = None
        self.is_scanning = False
        self.moving_forward = False
        self.forward_start_time = None
        self.scan_sweep_returning = False

        self.turn_speed_gradient = (self.max_angular_speed - self.min_angular_speed)/(1 - self.alignment_threshold)

        self.settling_time = 2000
        self.settling_time_init = 0

        # Setup the action server
        self.action_server = ActionServer(
            node=self,
            action_type=FollowBallAction,
            action_name='follow_ball',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            cancel_callback=self.cancel_callback,
            result_timeout=2000
        )

        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription = self.create_subscription(Point, '/detected_ball', self.listener_callback, 10)

        # New variable to track if lifter_actuating is True
        self.lifter_actuating = False
        # Subscribe to /lifter_actuating topic
        self.lifter_sub = self.create_subscription(
            Bool, '/main_arm_actuating', self.lifter_callback, 10)
        
        self.target_val = 0.0
        self.target_dist = 0.0
        self.lastrcvtime = time.time() - 10000

        self.get_logger().info('follow_ball_action_server has started! Waiting for requests!')

    def goal_callback(self, goal_handle):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal):
        self.get_logger().info('Received cancel request')
        return CancelResponse.ACCEPT

    def handle_accepted_callback(self, goal_handle):
        with self._goal_lock:
            # This server only allows one goal at a time
            if self._goal_handle is not None and self._goal_handle.is_active:
                self.get_logger().info('Aborting previous goal')
                # Abort the existing goal
                self._goal_handle.abort()
            self._goal_handle = goal_handle
        goal_handle.execute()

    def execute_callback(self, goal_handle):
        self.get_logger().info("Executing goal")

        feedback_msg = FollowBallAction.Feedback()
        result = FollowBallAction.Result()

        #Reset Chase Params
        self.target_val = 0.0
        self.target_dist = 0.0
        self.lastrcvtime = time.time() - 10000
        self.initial_yaw = None
        self.lifter_actuating = False
        self.is_close = False

        while rclpy.ok():
            msg = Twist()
            if (time.time() - self.lastrcvtime < self.rcv_timeout_secs):
                self.initial_yaw = None
                self.is_scanning = False
                self.get_logger().info('Target: x={} @ dist={}'.format(self.target_val, self.target_dist))
                
                if abs(self.target_val) < self.alignment_threshold:
                    if (self.target_dist < self.max_size_thresh):
                        self.get_logger().info("Ball is centered. Approaching...")
                        # Box is alligned move forward
                        msg.linear.x = self.forward_chase_speed
                    else:
                        self.get_logger().info('Reached Target Size + Alignment')
                        self.is_close = True
                else:
                    self.get_logger().info("Ball is NOT centered. Aligning...")
                    # Realign before moving forward
                    # This calculates the required speed using a min speed and and max speed
                    requested_speed = self.turn_speed_gradient * -self.target_val
                    if requested_speed < 0:
                        # Need negative so subtract
                        msg.angular.z = requested_speed - self.min_angular_speed
                    else:
                        # Need positive so add
                        msg.angular.z = requested_speed + self.min_angular_speed
                    # msg.linear.x = self.forward_chase_speed*(1/2)
                    #self.get_logger().info(f"b.x = {self.target_val} ; RS = {requested_speed} ; t.a.z = {msg.angular.z}")

                # Cmd robot to move
                self.publisher_.publish(msg)

            else:
                self.is_scanning = True
                self.is_close = False
                self.get_logger().info('Target lost')
                if self.moving_forward:
                    self.continue_forward(msg)
                else:
                    self.perform_scan(msg)
                self.get_logger().debug(str(msg))

                # Cmd robot to move
                self.publisher_.publish(msg)


            # Provide feedback to the client
            feedback_msg.current_distance = self.target_dist
            goal_handle.publish_feedback(feedback_msg)

            # Check ball is close enough
            if self.is_close:
                self.get_logger().info(f'Ball Close Enough')
                # Check ball is roughly centered
                if abs(self.target_val) < 0.3:
                    self.get_logger().info(f'Ball Centered Enough')
                    # If settling time is un set start it
                    #if self.settling_time_init == -1:
                    #    self.get_logger().info(f'Reached target size and angle. Allowing time for result to settle')
                    #    self.settling_time_init = time.time()
                    # Check if the time is up
                    #if (time.time() - self.settling_time_init > self.settling_time):
                    self.get_logger().info(f'Reached target size and angle for required time. Moving forward at creep speed.')
                    self.move_forward_with_creep(goal_handle)
                    self.get_logger().info(f'Goal Finished')
                    result.success = True
                    return result
                # Set the timeout to -1
                #elif not (self.settling_time_init == -1):
                #    self.settling_time_init == -1

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Goal canceled')
                return FollowBallAction.Result()

    def move_forward_with_creep(self, goal_handle):
        start_time = time.time()
        while rclpy.ok() and (time.time() - start_time < self.creep_timeout_secs):
            if self.lifter_actuating:
                self.get_logger().info('Lifter actuated. Creep ended successfully.')
                goal_handle.succeed()
                return

            msg = Twist()
            msg.linear.x = self.creep_speed
            msg.angular.z = self.creep_rotation_compensation
            self.publisher_.publish(msg)
            time.sleep(0.1)

        self.get_logger().info('Creep forward motion complete with no pickup. Goal Failed')
        goal_handle.abort()

    def lifter_callback(self, msg: Bool):
        if msg.data:
            self.lifter_actuating = True
        else:
            self.lifter_actuating = False

    def perform_scan(self, msg):
        if self.initial_yaw is None:
            self.initial_yaw = self.get_yaw_from_odom()
            self.get_logger().info('Starting 360-degree turn')
            self.quarter_turns = 0

        if self.initial_yaw is not None:
            self.current_yaw = self.get_yaw_from_odom()

            if self.current_yaw is not None:
                yaw_diff = abs(self.current_yaw - self.initial_yaw)
                self.get_logger().info(f'Current yaw difference (qt {self.quarter_turns}): {yaw_diff}')

                # Perform a 360-degree turn
                if yaw_diff < pi/2:
                    msg.angular.z = self.search_angular_speed * self.scan_direction
                elif self.quarter_turns <= 3:
                    # This should hopefully cause the robot to turn 360 degrees
                    self.quarter_turns += 1
                    self.initial_yaw = self.current_yaw
                else:
                    self.get_logger().info('360-degree turn completed, starting forward motion')
                    self.start_forward_motion()

    def get_yaw_from_odom(self):
        try:
            trans = self.tf_buffer.lookup_transform('odom', 'base_link', rclpy.time.Time())
            rotation = trans.transform.rotation
            _, _, yaw = euler_from_quaternion([rotation.x, rotation.y, rotation.z, rotation.w])
            return yaw
        except Exception as e:
            self.get_logger().warn(f"Failed to get transform: {e}")
            return None

    def start_forward_motion(self):
        self.moving_forward = True
        self.forward_start_time = time.time()

    def continue_forward(self, msg):
        if self.forward_start_time is None:
            return

        elapsed_time = time.time() - self.forward_start_time
        distance_covered = elapsed_time * self.forward_chase_speed

        if distance_covered < self.forward_distance:
            msg.linear.x = self.forward_chase_speed*1.2
            msg.angular.z = -0.2 # Prevent drift maybe
        else:
            self.moving_forward = False
            self.initial_yaw = None

    def listener_callback(self, msg):
        f = self.filter_value
        self.target_val = self.target_val * f + msg.x * (1 - f)
        self.target_dist = self.target_dist * f + msg.y * (1 - f)
        self.lastrcvtime = time.time()
        self.scan_start_time = time.time()


def main(args=None):
    rclpy.init(args=args)
    action_server = FollowBallActionServer()
    multi_thread_executor = MultiThreadedExecutor()
    rclpy.spin(action_server, executor=multi_thread_executor)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
