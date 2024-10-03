import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
import pigpio
import time

class ServoControllerRemote(Node):

    def __init__(self):
        super().__init__('servo_controller_remote')
        
        # Declare parameters
        self.declare_parameter('servo_pin', 27)  # Default GPIO pin 18
        self.declare_parameter('debug', True)  # Debug mode

        # Get parameters
        self.servo_pin = self.get_parameter('servo_pin').get_parameter_value().integer_value
        self.debug = self.get_parameter('debug').get_parameter_value().bool_value

        # Initialize pigpio
        self.pi = pigpio.pi()

        self.clamp_val = lambda x, l, u: l if x < l else u if x > u else x

        if not self.pi.connected:
            self.get_logger().error("pigpio daemon not running")
            rclpy.shutdown()
            return

        # Publisher for lifter_actuating topic
        self.lifter_publisher = self.create_publisher(Bool, 'lifter_actuating', 5)
        
        # Subscriber for triggering the servo
        self.trigger_subscriber = self.create_subscription(
            Bool,
            'trigger_servo',  # Topic name
            self.trigger_callback,
            10
        )
        
        if self.debug:
            self.get_logger().info("ServoControllerRemote node initialized with:")
            self.get_logger().info(f"Servo pin: {self.servo_pin}")
            self.get_logger().info(f"Debug mode: {self.debug}")
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(5))

    def trigger_callback(self, msg):
        if msg.data:
            if self.debug:
                self.get_logger().info("Received trigger message to actuate servo")
            self.actuate_servo()

    def actuate_servo(self):
        if self.debug:
            self.get_logger().info("Actuating servo to full deflection")
        
        # Publish lifter_actuating as True
        self.publish_lifter_actuating(True)

        # Move servo to full deflection (e.g., 180 degrees)
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(110))
        time.sleep(1)  # Give the servo time to move
        
        if self.debug:
            self.get_logger().info("Servo at full deflection. Waiting for 4 seconds.")
        
        # Wait for 4 seconds
        time.sleep(2)
        
        if self.debug:
            self.get_logger().info("Returning servo to resting position")
        
        # Move servo back to resting position (Change as required)
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(5))
        time.sleep(1)  # Give the servo time to move back
        
        # Stop servo
        self.pi.set_servo_pulsewidth(self.servo_pin, 0)
        
        # Publish lifter_actuating as False
        self.publish_lifter_actuating(False)

    def angle_to_pulsewidth(self, angle):
        # Converts angle to pulse width for the servo (e.g., 1000µs for 0° to 2000µs for 180°)
        # Ensure requested angle is within specified limits
        return 600 + (self.clamp_val(180-angle,0,180) / 180.0) * 1800

    def publish_lifter_actuating(self, state):
        msg = Bool()
        msg.data = state
        self.lifter_publisher.publish(msg)
        if self.debug:
            self.get_logger().info(f'Lifter actuating state published: {state}')

    def destroy_node(self):
        if self.debug:
            self.get_logger().info("Cleaning up resources")
        # Clean up pigpio
        self.pi.stop()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    
    servo_controller = ServoControllerRemote()
    
    try:
        rclpy.spin(servo_controller)
    except KeyboardInterrupt:
        pass
    
    servo_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()