import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Bool
from cv_bridge import CvBridge, CvBridgeError
import time
import cv2
import websockets
import asyncio
import json
import numpy as np

from .helper import WebSocketClient

class DetectBall(Node):

    def __init__(self):
        super().__init__('detect_ball')

        self.get_logger().info(f'Starting Threshold based detector')

        self.image_sub = self.create_subscription(Image, "/image_in", self.callback, rclpy.qos.QoSPresetProfiles.SENSOR_DATA.value)
        self.process_img_sub = self.create_subscription(Bool, "/process_img_ball", self.process_img_callback, 10)
        self.image_out_pub = self.create_publisher(Image, "/image_out", 1)
        self.image_mask_pub = self.create_publisher(Image, "/image_mask", 1)
        self.ball_pub = self.create_publisher(Point, "/detected_ball", 1)
        self.all_balls_pub = self.create_publisher(PointStamped, "/detected_balls_all", 1)
        self.bridge = CvBridge()

        # State variable to control image processing
        self.process_img_box = True

        # Get the async event loop
        self.loop = asyncio.get_event_loop()
        self.lastrcvtime = 0
        self.to_interval = 0.5

        # Define the HSV range for green-yellow balls
        self.lower_green_yellow = np.array([20, 60, 60])  # Adjust these values as needed
        self.upper_green_yellow = np.array([100, 255, 255])

    def process_img_callback(self, msg):
        # Update the state variable based on the incoming Bool message
        self.process_img_box = msg.data
        self.get_logger().info(f'Updated process_img_box state to: {self.process_img_box}')

    def callback(self, data):
        # Only process the image if process_img_box is True
        if not self.process_img_box:
            return

        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            self.get_logger().error(str(e))
            return

        # Resize and convert to uint8
        #img_uint8 = cv_image.astype(np.uint8)
        cv_image = cv2.resize(cv_image, (400, 400), interpolation=cv2.INTER_NEAREST)

        # Send image to server and receive processed points
        points = self.extract_balls(cv_image) # Detection function goes here
        process_time_start = time.time()
        centrelist = []
        for point in points:
            #print(point)
            x = point['x']
            y = point['y']
            w = point['w']
            h = point['h']

            centrelist.append([x + w/2, y + h/2, w * h])
            if point['in_bounds']:
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (255, 0, 0), 2)
            else:
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 0, 255), 2)

        # Determine and publish the biggest point
        point_out = Point()
        all_points_msg = PointStamped()
        all_points_msg.header = data.header
        
        for i, kp in enumerate(centrelist):
            # Append all detected ball points to the message
            pt = Point()
            pt.x = float(kp[0])
            pt.y = float(kp[1])
            pt.z = float(kp[2])
            all_points_msg.point = pt

            # Check for the largest detected ball
            if kp[1] > point_out.y:
                point_out.x = float(kp[0])
                point_out.y = float(kp[1])
                point_out.z = float(kp[2])

        if point_out.z > 0:
            point_out.x = (point_out.x-160)/160
            point_out.y = (point_out.y-160)/160
            point_out.z = point_out.z/102400
            self.ball_pub.publish(point_out)

        # Publish all detected balls
        self.all_balls_pub.publish(all_points_msg)

        process_time_end = time.time()
        process_time = process_time_end - process_time_start
        self.get_logger().debug(f'Processing Time: {process_time:.4f}')

        # Publish the image with bounding boxes
        img_to_pub = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
        img_to_pub.header = data.header
        self.image_out_pub.publish(img_to_pub)

    def extract_balls(self,cv_image):
        # Convert image to HSV color space
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)

        # Create a mask for the green-yellow color
        mask = cv2.inRange(hsv, self.lower_green_yellow, self.upper_green_yellow)

        bgr_image = cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)
        mask_img = self.bridge.cv2_to_imgmsg(bgr_image, "bgr8")
        self.image_mask_pub.publish(mask_img)

        # Apply morphological operations to remove small noises in the mask
        kernel = np.ones((5, 5), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        
        

        # Find contours in the mask
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        points = []

        for contour in contours:
            area = cv2.contourArea(contour)
            if area < 100 or area > 10000:
                continue  # Ignore contours that are too small or too large

            # Get bounding box of the contour
            x, y, w, h = cv2.boundingRect(contour)
            x = int(x)
            y = int(y)
            w = int(w)
            h = int(h)
            cx = x + w / 2
            cy = y + h / 2

            # Determine if the center is in bounds (within the central region)
            if abs(cx - 160) <= 80 and abs(cy - 160) <= 80:
                in_bounds = True
            else:
                in_bounds = False

            point = {'x': x, 'y': y, 'w': w, 'h': h, 'in_bounds': in_bounds}
            points.append(point)

        return points


def main(args=None):
    rclpy.init(args=args)
    detect_ball = DetectBall()
    detect_ball.get_logger().info('Starting Loop')
    try:
        rclpy.spin(detect_ball)
    except KeyboardInterrupt:
        pass
    detect_ball.get_logger().info('Detector closed. Goodbye!')
    detect_ball.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()