import cv2

# Paths to the configuration and model files
config_file = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
frozen_model = 'frozen_inference_graph.pb'

# Load the MobileNetV3 model
model = cv2.dnn_DetectionModel(frozen_model, config_file)

# Load the class labels
classLabels = []
filename = 'labels.txt'  # Ensure this file contains the COCO class labels
with open(filename, 'rt') as spt:
    classLabels = spt.read().rstrip('\n').split('\n')

# Set model parameters
model.setInputSize(320, 320)  # The input size expected by the model
model.setInputScale(1.0/127.5)
model.setInputMean((127.5, 127.5, 127.5))
model.setInputSwapRB(True)

# Initialize webcam
cap = cv2.VideoCapture(0)

# Set the webcam resolution
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

font = cv2.FONT_HERSHEY_PLAIN

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Check if the frame was successfully captured
    if not ret:
        print("Failed to grab frame")
        break

    # Perform object detection
    classIndex, confidence, bbox = model.detect(frame, confThreshold=0.5)

    # Ensure that detections were returned
    if len(classIndex) > 0:
        # Draw bounding boxes and labels on the frame
        for classInd, conf, boxes in zip(classIndex.flatten(), confidence.flatten(), bbox):
            if classInd <= len(classLabels):
                cv2.rectangle(frame, boxes, (255, 0, 0), 2)
                cv2.putText(frame, f'{classLabels[classInd-1]}: {conf:.2f}', 
                            (boxes[0] + 10, boxes[1] + 30), font, 2, (0, 255, 0), 2)
            else:
                print(f"Warning: Detected class index {classInd} out of range")

    # Display the resulting frame
    cv2.imshow('MobileNetV3 Detection', frame)

    # Exit the loop if the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and close all OpenCV windows
cap.release()
cv2.destroyAllWindows()
