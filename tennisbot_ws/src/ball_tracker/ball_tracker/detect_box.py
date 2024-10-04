import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np

class DetectBox(Node):

    def __init__(self):
        super().__init__('detect_box')

        # Initialize subscriptions and publishers
        self.get_logger().info('Initializing parameters...')
        self.image_sub = self.create_subscription(
            Image,
            "/image_in",
            self.callback,
            rclpy.qos.QoSPresetProfiles.SENSOR_DATA.value
        )
        self.image_out_pub = self.create_publisher(Image, "/image_out_box", 1)
        self.box_pub = self.create_publisher(Point, "/detected_box", 1)
        self.bridge = CvBridge()

        # Declare a parameter for minimum contour area
        self.declare_parameter('min_area_threshold', 500)  # Adjust this value as needed
        self.min_area_threshold = self.get_parameter('min_area_threshold').value

    def callback(self, data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            self.get_logger().error(str(e))
            return

        # Resize image to (320, 320)
        cv_image = cv2.resize(cv_image, (320, 320), interpolation=cv2.INTER_NEAREST)

        # Convert to HSV color space
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)

        # Define range of brown color in HSV
        lower_brown = np.array([10, 60, 20])
        upper_brown = np.array([50, 255, 230])

        # Threshold the HSV image to get only brown colors
        mask = cv2.inRange(hsv, lower_brown, upper_brown)

        # Morphological operations to remove small noises
        kernel = np.ones((5, 5), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

        # Find contours
        contours, _ = cv2.findContours(
            mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
        )

        if len(contours) > 0:
            # Find the largest contour assuming it's the box
            largest_contour = max(contours, key=cv2.contourArea)
            # Calculate size (area)
            area = cv2.contourArea(largest_contour)

            # Check if the area exceeds the threshold
            if area > self.min_area_threshold:
                # Calculate centroid
                M = cv2.moments(largest_contour)
                if M["m00"] != 0:
                    cX = int(M["m10"] / M["m00"])
                    cY = int(M["m01"] / M["m00"])
                else:
                    cX, cY = 0, 0

                # Draw circle at centroid
                cv2.circle(cv_image, (cX, cY), radius=4, color=(0, 0, 255), thickness=-1)

                # Create and publish Point message
                point_out = Point()
                # Normalize x and y between -1 and 1
                point_out.x = (cX - 160) / 160.0
                point_out.y = (cY - 160) / 160.0
                point_out.z = area / (320 * 320)  # area normalized

                self.box_pub.publish(point_out)
            else:
                # Area too small, ignore detection
                self.get_logger().info(f"Detected contour area too small ({area}), ignoring.")
        else:
            # No box found
            self.get_logger().info("No box found.")

        # Publish the image with the circle drawn
        img_to_pub = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
        img_to_pub.header = data.header
        self.image_out_pub.publish(img_to_pub)

def main(args=None):
    rclpy.init(args=args)
    detect_box = DetectBox()
    detect_box.get_logger().info('Starting loop...')
    try:
        rclpy.spin(detect_box)
    except KeyboardInterrupt:
        pass
    detect_box.get_logger().info('Detector closed. Goodbye!')
    detect_box.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
