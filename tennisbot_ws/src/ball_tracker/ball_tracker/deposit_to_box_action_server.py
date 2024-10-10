import rclpy
import threading
import time
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Point, Twist
from std_msgs.msg import Bool
from ball_tracker_msgs.action import DepositToBox  # Ensure this action is defined
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion
from math import pi

def normalize_angle(angle):
    # Normalize the angle to be between -pi and pi
    angle = (angle + pi) % (2 * pi) - pi
    return angle

class DepositToBoxActionServer(Node):

    def __init__(self):
        super().__init__('deposit_to_box_action_server')
        self.get_logger().info('deposit_to_box_action_server V1.2 is starting... Please wait')
        self._goal_handle = None
        self._goal_lock = threading.Lock()

        # Parameters
        self.declare_parameter('centroid_threshold', 0.1)
        self.centroid_threshold = self.get_parameter('centroid_threshold').value

        self.declare_parameter('alignment_threshold', 0.1)
        self.alignment_threshold = self.get_parameter('alignment_threshold').value

        self.declare_parameter('backup_time', 5.0)  # Maximum time to back up in seconds
        self.backup_time = self.get_parameter('backup_time').value

        self.declare_parameter('forward_speed', 0.3)
        self.forward_speed = self.get_parameter('forward_speed').get_parameter_value().double_value

        self.declare_parameter('turn_speed', 2.2)
        self.turn_speed = self.get_parameter('turn_speed').get_parameter_value().double_value

        self.declare_parameter('min_turn_speed', 1.9)
        self.min_turn_speed = self.get_parameter('min_turn_speed').get_parameter_value().double_value

        self.declare_parameter('search_turn_speed', 2.0)
        self.search_turn_speed = self.get_parameter('search_turn_speed').get_parameter_value().double_value

        self.declare_parameter('backup_speed', -0.2)  # Negative for backing up
        self.backup_speed = self.get_parameter('backup_speed').get_parameter_value().double_value

        self.turn180_speed = 2.4

        # State variables
        self.state = 'IDLE'
        self.box_msg = None
        self.rear_door_actuating = False
        self.backup_start_time = None
        self.turn_start_time = None
        self.initial_yaw = None
        self.has_changed_ta_speed = False

        # Calculate turn velocity gradient
        self.turn_speed_gradient = (self.turn_speed - self.min_turn_speed)/(1 - self.alignment_threshold)

        # Publishers and subscribers
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        self.detected_box_sub = self.create_subscription(
            Point,
            '/detected_box',
            self.detected_box_callback,
            10
        )

        self.rear_door_actuating_sub = self.create_subscription(
            Bool,
            '/rear_flap_actuating',
            self.rear_door_actuating_callback,
            10
        )

        # Initialize tf2 buffer and listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.get_logger().info('Setting up action server...')

        # Setup the action server
        self.action_server = ActionServer(
            node=self,
            action_type=DepositToBox,
            action_name='follow_box',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            cancel_callback=self.cancel_callback
        )

        self.get_logger().info('deposit_to_box_action_server has started! Waiting for requests!')

    def goal_callback(self, goal_request):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
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
        # Start the execution in a new thread to avoid blocking
        goal_handle.execute()

    def execute_callback(self, goal_handle):
    #    threading.Thread(target=self.execute_callback_threaded, args=(goal_handle,)).start()

    #def execute_callback_threaded(self, goal_handle):
        self.get_logger().info("Executing goal")

        feedback_msg = DepositToBox.Feedback()
        result = DepositToBox.Result()

        # Initialize variables
        self.get_logger().info("Init Vars")
        self.state = 'SEARCHING'
        self.box_msg = None
        self.rear_door_actuating = False
        self.backup_start_time = None
        self.turn_start_time = None
        self.initial_yaw = None
        self.lastrcvtime = 0

        # Timer for control loop
        self.get_logger().info("Starting Loop...")
        while rclpy.ok():
            # Check for cancellation
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('Goal canceled')
                self.stop_robot()
                self.state = 'IDLE'
                return DepositToBox.Result()

            # Update control loop
            self.control_loop()

            # Provide feedback
            feedback_msg.current_state = self.state
            goal_handle.publish_feedback(feedback_msg)

            # Check if the goal is succeeded
            if self.state == 'STOPPED':
                self.get_logger().info('Goal succeeded')
                result.success = True
                goal_handle.succeed()
                self.state = 'IDLE'
                return result

    def detected_box_callback(self, msg):
        # Use the data directly; assume it's validated
        self.box_msg = msg
        self.lastrcvtime = time.time()

    def rear_door_actuating_callback(self, msg):
        self.rear_door_actuating = msg.data

    def control_loop(self):
        current_time = self.get_clock().now().nanoseconds / 1e9  # Current time in seconds
        #self.get_logger().info(f"State: {self.state}")
        #self.get_logger().info(f"Box: {self.box_msg}")

        if self.state == 'SEARCHING':
            # Spin slowly to search for the box
            twist = Twist()
            twist.angular.z = self.search_turn_speed
            self.cmd_vel_pub.publish(twist)
            if self.box_msg:
                self.state = 'MOVING_TOWARDS_BOX'
                self.get_logger().info("Box detected, moving towards it.")
        
        elif self.state == 'MOVING_TOWARDS_BOX':
            if time.time() - self.lastrcvtime > 5:
                self.get_logger().info("Box was lost. Returning to search")
                self.state = 'SEARCHING'
            elif self.box_msg:
                # Move towards the box based on its position
                twist = Twist()
                if abs(self.box_msg.x) < self.alignment_threshold:
                    self.get_logger().info("Box is centered. Approaching...")
                    # Box is alligned move forward
                    twist.linear.x = self.forward_speed
                else:
                    self.get_logger().info("Box is NOT centered. Aligning...")
                    # Realign before moving forward
                    # This calculates the required speed using a min speed and and max speed
                    requested_speed = self.turn_speed_gradient * -self.box_msg.x
                    if requested_speed < 0:
                        # Need negative so subtract
                        twist.angular.z = requested_speed - self.min_turn_speed
                    else:
                        # Need positive so add
                        twist.angular.z = requested_speed + self.min_turn_speed
                    self.get_logger().info(f"b.x = {self.box_msg.x} ; RS = {requested_speed} ; t.a.z = {twist.angular.z}")

                # Cmd robot to move
                self.cmd_vel_pub.publish(twist)

                # Check if the box is close enough by checking y height
                if self.box_msg.y > self.centroid_threshold:
                    self.get_logger().info("Box is close enough, aligning.")
                    self.state = 'ALIGNING'

            else:
                # Lost sight of the box
                self.get_logger().info("Lost sight of the box, searching.")
                self.state = 'SEARCHING'

        elif self.state == 'ALIGNING':
            twist = Twist()
            # Ensure robot can always turn by clamping speed
            twist.angular.z = min(self.turn_speed*abs(self.box_msg.x),1.8)

            if self.box_msg.x > 0: # If ball is to the right turn to the left
                twist.angular.z = -twist.angular.z

            self.cmd_vel_pub.publish(twist)
            # Check alignment
            if abs(self.box_msg.x) < self.alignment_threshold:
                self.get_logger().info("Box is roughly centered. Turning around")
                self.state = 'TURNING_AROUND'
                self.turn_start_time = current_time
                self.initial_yaw = self.get_yaw()
                self.current_TS = self.turn180_speed
                if self.initial_yaw is None:
                    self.get_logger().warn("Cannot get initial yaw, defaulting to time-based turn.")
                    self.turn_duration = pi / self.turn180_speed
            
        elif self.state == 'TURNING_AROUND':
            # Turn 180 degrees using odometry
            #self.get_logger().info("Creating TA twist")
            #self.get_logger().info(f"Type of turn180_speed: {type(self.forward_speed)}")

            twist = Twist()
            twist.angular.z = float(self.current_TS)
            #self.get_logger().info("Publish Twist")
            self.cmd_vel_pub.publish(twist)

            #self.get_logger().info("Begin TA")

            if self.initial_yaw is not None:
                current_yaw = self.get_yaw()
                if current_yaw is not None:
                    yaw_diff = normalize_angle(current_yaw - self.initial_yaw)
                    self.get_logger().info(f"yaw_diff = {current_yaw} - {self.initial_yaw} = {current_yaw - self.initial_yaw} = norm {yaw_diff}")
                    if abs(yaw_diff) >= pi-0.2 and not self.has_changed_ta_speed:
                        self.has_changed_ta_speed = True
                        self.get_logger().info("Approaching 180. Slowing turn")
                        self.current_TS = 2*self.turn180_speed/3
                    if abs(yaw_diff) >= pi-0.03:  # Allowing a small margin
                        self.get_logger().info("Turned 180 degrees, backing up.")
                        self.state = 'BACKING_UP'
                        self.has_changed_ta_speed = False
                        self.backup_start_time = current_time
                        self.initial_yaw = None
                        self.turn_start_time = None
            else:
                # Fallback to time-based turning
                elapsed_time = current_time - self.turn_start_time
                if elapsed_time >= self.turn_duration:
                    self.get_logger().info("WARN: Turned 180 degrees (time-based), backing up.")
                    self.state = 'BACKING_UP'
                    self.backup_start_time = current_time
                    self.turn_start_time = None

        elif self.state == 'BACKING_UP':
            # Back up into the box
            twist = Twist()
            twist.linear.x = self.backup_speed
            #twist.angular.z = -0.5 # Compensation for not travelling straight
            self.cmd_vel_pub.publish(twist)

            # Check if we need to stop
            elapsed_time = current_time - self.backup_start_time
            if self.rear_door_actuating:
                self.get_logger().info("Rear door actuated, stopping.")
                time.sleep(0.5)
                self.shake_robot() # Shake to dislodge balls
                self.state = 'STOPPED'
                self.stop_robot()
            elif elapsed_time >= self.backup_time:
                self.get_logger().info("Backed up for maximum time, stopping.")
                self.state = 'STOPPED'
                self.stop_robot()

        elif self.state == 'STOPPED':
            # Stop all movements
            self.stop_robot()

        else:
            self.get_logger().error(f"CRITICAL ERROR: Unknown state: {self.state}")

    def stop_robot(self):
        twist = Twist()
        self.cmd_vel_pub.publish(twist)

    def get_yaw(self):
        try:
            now = rclpy.time.Time()
            trans = self.tf_buffer.lookup_transform('odom', 'base_link', now)
            rotation = trans.transform.rotation
            _, _, yaw = euler_from_quaternion([rotation.x, rotation.y, rotation.z, rotation.w])
            return yaw
        except Exception as e:
            self.get_logger().warn(f"Failed to get transform: {e}")
            return None
    def shake_robot(self):
        twist = Twist()
        start_time = time.time()
        
        # Shake left and right for 2 seconds
        while time.time() - start_time < 2.0:
            twist.angular.z = 2.0  # Rotate left
            self.publisher_.publish(twist)
            time.sleep(0.1)  # Shake frequency

            twist.angular.z = -2.0  # Rotate right
            self.publisher_.publish(twist)
            time.sleep(0.1)  # Shake frequency
        
        # Stop the robot
        twist.angular.z = 0.0
        self.publisher_.publish(twist)
        
        # Wait for 2 seconds
        self.get_logger().info('Shaking complete, now waiting for 2 seconds.')
        time.sleep(2.0)
        return

def main(args=None):
    rclpy.init(args=args)
    action_server = DepositToBoxActionServer()
    multi_thread_executor = MultiThreadedExecutor()
    try:
        rclpy.spin(action_server, executor=multi_thread_executor)
    except KeyboardInterrupt:
        pass
    action_server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
