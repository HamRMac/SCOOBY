import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
import pigpio
import time

class ServoController(Node):

    def __init__(self):
        super().__init__('servo_controller')
        
        # Declare parameters
        self.declare_parameter('input_pin', 17)  # Default GPIO pin 17
        self.declare_parameter('servo_pin', 18)  # Default GPIO pin 18
        self.declare_parameter('min_angle', 0.0)  # Default GPIO pin 17
        self.declare_parameter('max_angle', 180.0)  # Default GPIO pin 18
        self.declare_parameter('debug', True)  # Debug mode
        self.declare_parameter('name', "DEFAULT")  # Debug mode

        # Get parameters
        self.input_pin = self.get_parameter('input_pin').get_parameter_value().integer_value
        self.servo_pin = self.get_parameter('servo_pin').get_parameter_value().integer_value
        self.debug = self.get_parameter('debug').get_parameter_value().bool_value
        self.min_angle = self.get_parameter('min_angle').get_parameter_value().double_value
        self.max_angle = self.get_parameter('max_angle').get_parameter_value().double_value
        self.publish_topic = f"{self.get_parameter('name').get_parameter_value().string_value}_actuating"

        if self.debug:
            self.get_logger().info("ServoController node V1.0 initialized with:")
            self.get_logger().info(f"Input pin: {self.input_pin}")
            self.get_logger().info(f"Servo pin: {self.servo_pin}")
            self.get_logger().info(f"Debug mode: {self.debug}")
            self.get_logger().info(f"Min angle: {self.min_angle}")
            self.get_logger().info(f"Max angle: {self.max_angle}")
            self.get_logger().info(f"Publish topic: {self.publish_topic}")

        # Initialize pigpio
        self.pi = pigpio.pi()

        self.clamp_val = lambda x, l, u: l if x < l else u if x > u else x

        if not self.pi.connected:
            self.get_logger().error("pigpio daemon not running")
            rclpy.shutdown()
            return

        # Set up input pin
        self.pi.set_mode(self.input_pin, pigpio.INPUT)
        self.pi.set_pull_up_down(self.input_pin, pigpio.PUD_DOWN)
        self.pi.set_glitch_filter(self.input_pin, 300)  # Adjust the debounce time (in microseconds)

        # Publisher for lifter_actuating topic
        self.lifter_publisher = self.create_publisher(Bool, self.publish_topic, 5)

        # Set up interrupt on the input pin
        self.pi.callback(self.input_pin, pigpio.RISING_EDGE, self.input_callback)
            
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(self.min_angle))

    def input_callback(self, gpio, level, tick):
        if self.debug:
            self.get_logger().info(f"Interrupt triggered (GPIO{gpio}- {level} signal detected on input pin (t={tick})")
        self.actuate_servo()

    def actuate_servo(self):
        if self.debug:
            self.get_logger().info("Actuating servo to full deflection")
        
        # Publish lifter_actuating as True
        self.publish_lifter_actuating(True)

        # Move servo to full deflection (e.g., 180 degrees)
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(self.max_angle))
        time.sleep(1)  # Give the servo time to move
        
        if self.debug:
            self.get_logger().info("Servo at full deflection. Waiting for 4 seconds.")
        
        # Wait for 4 seconds
        time.sleep(2)
        
        if self.debug:
            self.get_logger().info("Returning servo to resting position")
        
        # Move servo back to resting position (Change as required)
        self.pi.set_servo_pulsewidth(self.servo_pin, self.angle_to_pulsewidth(self.min_angle))
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
    
    servo_controller = ServoController()
    
    try:
        rclpy.spin(servo_controller)
    except KeyboardInterrupt:
        pass
    
    servo_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
