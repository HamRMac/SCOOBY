import cv2
import websockets
import asyncio
import numpy as np
import json
import time

# Paths to the configuration and model files
config_file = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
frozen_model = 'frozen_inference_graph.pb'

# Load the MobileNetV3 model
model = cv2.dnn_DetectionModel(frozen_model, config_file)

# Load the class labels
classLabels = []
filename = 'labels.txt'
with open(filename, 'rt') as spt:
    classLabels = spt.read().rstrip('\n').split('\n')

# Set model parameters
model.setInputSize(320, 320)
model.setInputScale(1.0 / 127.5)
model.setInputMean((127.5, 127.5, 127.5))
model.setInputSwapRB(True)

connected_clients = set()

print("Detector Ready! (With decode)")

async def detect_ball(websocket, path):
    # Extract client IP address and port
    client_ip, client_port = websocket.remote_address
    connected_clients.add(websocket)
    print(f"Client connected: {client_ip}:{client_port}. Total clients: {len(connected_clients)}")

    try:
        frame_count = 0
        start_time = time.time()
        receive_start = time.time()

        async for message in websocket:
            # Measure time to receive the frame from the client
            #receive_start = time.time()

            # Convert received bytes to image
            img_in = np.frombuffer(message, dtype=np.uint8)
            img_recv = cv2.imdecode(img_in, cv2.IMREAD_COLOR)

            # Measure time taken to receive the frame
            receive_end = time.time()
            receive_time = receive_end - receive_start

            # Measure time taken to process the frame
            process_start = time.time()

            # Perform object detection
            classIndex, confidence, bbox = model.detect(img_recv, confThreshold=0.5)
            detected_points = []
            if len(classIndex) > 0:
                for classInd, conf, boxes in zip(classIndex.flatten(), confidence.flatten(), bbox):
                    if classInd <= len(classLabels) and classInd == 37:
                        x, y, w, h = boxes.tolist()
                        detected_points.append({"x": int(x), "y": int(y), "w": int(w), "h": int(h)})

            # Measure processing time
            process_end = time.time()
            process_time = process_end - process_start

            # Send all detected points back to the client
            await websocket.send(json.dumps(detected_points))
            receive_start = time.time()

            # Print the time measurements
            print(f"Frame {frame_count + 1} - Receive Time: {receive_time:.4f} sec, Processing Time: {process_time:.4f} sec")

            # Increment frame count
            frame_count += 1

            # Calculate and display FPS every 10 frames
            if frame_count % 10 == 0:
                elapsed_time = time.time() - start_time
                fps = frame_count / elapsed_time
                print(f"Average FPS: {fps:.2f}")
                # Reset the frame count and start time
                frame_count = 0
                start_time = time.time()

    except websockets.exceptions.ConnectionClosedError:
        print(f"Client {client_ip}:{client_port} disconnected unexpectedly.")
    finally:
        connected_clients.remove(websocket)
        print(f"Client disconnected: {client_ip}:{client_port}. Total clients: {len(connected_clients)}")


print("Starting websocket...")

uri = "172.20.10.3"
uri_port = 8765

print("Opening websocket at " + uri + ":" + str(uri_port))
start_server = websockets.serve(detect_ball, uri, uri_port)
print("Websocket has started")

print("Getting event loop")
loop = asyncio.get_event_loop()
print("Specifying to run event loop")
loop.run_until_complete(start_server)
print("Running event loop")
loop.run_forever()

cv2.destroyAllWindows()
print("Detector Closed!")
