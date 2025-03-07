# Copyright 2023 Josh Newans
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from sensor_msgs.msg        import Image
from geometry_msgs.msg      import Point
from cv_bridge              import CvBridge, CvBridgeError
import ball_tracker.process_image as proc

import cv2



class DetectBall(Node):

    def __init__(self):
        super().__init__('detect_ball')

        self.get_logger().info('Looking for the ball...')
        self.image_sub = self.create_subscription(Image,"/image_in",self.callback,rclpy.qos.QoSPresetProfiles.SENSOR_DATA.value)
        self.image_out_pub = self.create_publisher(Image, "/image_out", 1)
        self.ball_pub  = self.create_publisher(Point,"/detected_ball",1)

        self.bridge = CvBridge()

        config_file = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
        frozen_model = 'frozen_inference_graph.pb'

        self.model = cv2.dnn_DetectionModel(frozen_model, config_file)

        self.classLabels = []
        filename = 'labels.txt'  # Ensure this file contains the COCO class labels
        with open(filename, 'rt') as spt:
            self.classLabels = spt.read().rstrip('\n').split('\n')

        self.model.setInputSize(320, 320)  # The input size expected by the model
        self.model.setInputScale(1.0/127.5)
        self.model.setInputMean((127.5, 127.5, 127.5))
        self.model.setInputSwapRB(True)


    def callback(self,data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print(e)

        try:
           #keypoints_norm, out_image, tuning_image = proc.find_circles(cv_image, self.tuning_params)

            classIndex, confidence, bbox = self.model.detect(cv_image, confThreshold=0.5)
            centrelist = []
            if len(classIndex) > 0:
                # Draw bounding boxes and labels on the frame
                for classInd, conf, boxes in zip(classIndex.flatten(), confidence.flatten(), bbox):
                    if classInd <= len(self.classLabels):
                        cv2.rectangle(cv_image, boxes, (255, 0, 0), 2)
                        centrelist.append(boxes[0]+boxes[2]/2,boxes[1]+boxes[3]/2,boxes[2]*boxes[3])
                    else:
                        print(f"Warning: Detected class index {classInd} out of range")
            img_to_pub = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            img_to_pub.header = data.header
            self.image_out_pub.publish(img_to_pub)

            point_out = Point()

            # Keep the biggest point
            # They are already converted to normalised coordinates
            for i, kp in enumerate(centrelist):
                x = kp[0]
                y = kp[1]
                s = kp[2]

                self.get_logger().info(f"Pt {i}: ({x},{y},{s})")

                if (s > point_out.z):                    
                    point_out.x = x
                    point_out.y = y
                    point_out.z = s

            if (point_out.z > 0):
                self.ball_pub.publish(point_out) 
        except CvBridgeError as e:
            print(e)  


def main(args=None):

    rclpy.init(args=args)

    detect_ball = DetectBall()
    while rclpy.ok():
        rclpy.spin_once(detect_ball)
        proc.wait_on_gui()

    detect_ball.destroy_node()
    rclpy.shutdown()

