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

        self.FRAME_SIZE = 400

        self.apply_bounds_check = True

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
        cv_image = cv2.resize(cv_image, (self.FRAME_SIZE, self.FRAME_SIZE), interpolation=cv2.INTER_NEAREST)

        # Send image to server and receive processed points
        process_time_start = time.time()
        points = self.extract_balls(cv_image) # Detection function goes here
        centrelist = []
        for point in points:
            #print(point)
            x = point['x']
            y = point['y']
            w = point['w']
            h = point['h']
            cx = point['cx']
            cy = point['cy']
            area = point['area']

            centrelist.append([cx, cy, area,point['in_bounds']])
            if point['in_bounds']:
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (255, 0, 0), 2)
            else:
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 0, 255), 2)

        # Determine and publish the biggest point
        point_out = Point()
        point_out.y = 0
        
        for kp in centrelist:
            # Check for the largest detected ball
            if not kp[3]:
                continue
            if kp[1] > point_out.y:
                point_out.x = float(kp[0])
                point_out.y = float(kp[1])
                point_out.z = float(kp[2])

        if point_out.z > 0:
            point_out.x = (point_out.x-200)/200
            point_out.y = (point_out.y-200)/200
            self.ball_pub.publish(point_out)

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

        # Global check for boundary lines
        if self.apply_bounds_check:
            lines_mask = find_lines(cv_image)

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

            # Global check for boundary lines
            if self.apply_bounds_check:
                # Create mask for line and combine with detected lines
                path_line_mask = draw_path_line(cx,cy,w)
                masks_combined = cv2.addWeighted(lines_mask, 0.5, path_line_mask, 0.5, 0)

                # Determine if the center is in bounds (within the central region)
                # check for overlap of masks
                green_mask = np.all(masks_combined == [0, 255, 0], axis=-1)
                has_collision = np.any(green_mask)
            else:
                has_collision = False

            # Create list of points
            point = {'x': x, 'y': y, 'w': w, 'h': h, 'cx': cx, 'cy': cy, 'area': area, 'in_bounds': not has_collision}
            points.append(point)

        return points

def find_lines(img): 
    """
    input 
        img: camera frame image
    output
        hough_lines image, where the image is all black ([0,0,0]) except for red lines

    """
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blurred_image = cv2.GaussianBlur(gray_image, (9, 9), 2)
    edges_image = cv2.Canny(blurred_image, 50, 120)
    
    rho_resolution = 1
    theta_resolution = np.pi/180
    threshold = 155
    
    hough_lines = cv2.HoughLines(edges_image, rho_resolution , theta_resolution , threshold)

    if hough_lines is None:
        return np.zeros_like(img)

    hough_lines_image = np.zeros_like(img)
    draw_lines(hough_lines_image, hough_lines)

    return hough_lines_image

def draw_lines(img, houghLines, color=[0, 255, 0], thickness=4):
    for line in houghLines:
        for rho,theta in line:
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a*rho
            y0 = b*rho
            x1 = int(x0 + 10000*(-b))
            y1 = int(y0 + 10000*(a))
            x2 = int(x0 - 10000*(-b))
            y2 = int(y0 - 10000*(a))

            cv2.line(img,(x1,y1),(x2,y2),color,thickness)

def draw_path_line(center_x, center_y, boundarylength):
    FRAME_SIZE = 400
    # Create a black image of size 300x300
    img = np.zeros((FRAME_SIZE, FRAME_SIZE, 3), dtype=np.uint8)
    frame_bottom_middle = (FRAME_SIZE//2, FRAME_SIZE-1)

    # Calculate the half boundary length to find top-left and bottom-right points
    half_length = boundarylength // 2
    top_left = (center_x - half_length, center_y - half_length)
    bottom_right = (center_x + half_length, center_y + half_length)

    ball_bottom_middle = (int(center_x), int(center_y + half_length))
    cv2.line(img, frame_bottom_middle, ball_bottom_middle, (0,255,0), 2)

    # Draw the green bounding box
    # cv2.rectangle(img, top_left, bottom_right, (0, 255, 0), 2)

    return img

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