import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
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
        self.declare_parameter("websocket_url", "ws://192.168.0.0:8765")
        self.websocket_url = self.get_parameter('rcv_timeout_secs').get_parameter_value().string_value
        super().__init__('detect_ball')
        self.get_logger().info('Initialising WS Params...')
        self.image_sub = self.create_subscription(Image, "/image_in", self.callback, rclpy.qos.QoSPresetProfiles.SENSOR_DATA.value)
        self.image_out_pub = self.create_publisher(Image, "/image_out", 1)
        self.ball_pub = self.create_publisher(Point, "/detected_ball", 1)
        self.bridge = CvBridge()

        self.loop = asyncio.get_event_loop()
        self.get_logger().info('Connecting to WS Detector!')
        self.lastrcvtime = 0
        self.to_interval = 0.5

        self.client = WebSocketClient(self.websocket_url)

    def get_client(self):
        return self.client

    def callback(self, data):
        if time.time() - self.lastrcvtime < self.to_interval:
            return
        self.lastrcvtime = time.time()
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            self.get_logger().error(str(e))
            return

        # Resize and convert to uint8
        #img_resized = cv2.resize(cv_image, (320, 320))
        img_uint8 = cv_image.astype(np.uint8)

        # Send image to server and receive processed points
        try:
            points = self.loop.run_until_complete(client.send_receive(img_uint8))
            centrelist = []
            for point in points:
                x = point['x']
                y = point['y']
                w = point['w']
                h = point['h']
                centrelist.append([x + w/2, y + h/2, w * h])
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (255, 0, 0), 2)

            # Determine and publish the biggest point
            point_out = Point()
            for i, kp in enumerate(centrelist):
                if kp[2] > point_out.z:
                    point_out.x = float(kp[0])
                    point_out.y = float(kp[1])
                    point_out.z = float(kp[2])

            if point_out.z > 0:
                point_out.x = (point_out.x-320)/320
                point_out.y = (point_out.y-240)/240
                point_out.z = point_out.z/307200
                self.ball_pub.publish(point_out)


            # Publish the image with bounding boxes
            img_to_pub = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            img_to_pub.header = data.header
            self.image_out_pub.publish(img_to_pub)

        except Exception as e:
            self.get_logger().error(f'Error during websocket communication: {e}')

async def close_client(client):
    await client.close()

def main(args=None):
    rclpy.init(args=args)
    detect_ball = DetectBall()
    try:
        rclpy.spin(detect_ball)
    except KeyboardInterrupt:
        pass
    detect_ball.destroy_node()
    asyncio.run(close_client(detect_ball.client))
    rclpy.shutdown()

if __name__ == '__main__':
    main()
