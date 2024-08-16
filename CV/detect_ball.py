import cv2
import numpy as np
import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, join

# colour calibration
hsv_range = np.load('colour calibration/hsv_value.npy')
print(hsv_range)

# Known parameters
known_diameter = 6.7  # Diameter of a tennis ball in cm
focal_length = 700  # Adjust this based on your camera calibration
min_distance_between_balls = 100  # Minimum distance between centers of detected balls
min_ball_radius = 15

test_image_folder = 'test images'
test_images = [f for f in listdir(test_image_folder) if isfile(join(test_image_folder, f))]
print(test_images)

# Capture video from the camera
#cap = cv2.VideoCapture(1)

def is_too_close(new_center, centers, min_dist):
    for center in centers:
        if np.linalg.norm(np.array(new_center) - np.array(center)) < min_dist:
            return True
    return False


def process_image(image_path):
    # Read the image
    frame = cv2.imread(f'{test_image_folder}/{image_path}')
    
    if frame is None:
        print(f"Could not read image {image_path}")
        return None
    
    # Convert the image to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Define the HSV range for the tennis ball color
    lower_green = np.array(hsv_range[0])
    upper_green = np.array(hsv_range[1])
    
    # Create a mask to filter out the green color
    mask = cv2.inRange(hsv, lower_green, upper_green)
    
    # Find contours in the mask
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    
    # Sort contours by area and keep the largest ones
    contours = sorted(contours, key=cv2.contourArea, reverse=True)
    
    centers = []
    ball_count = 0
    
    for contour in contours:
        if ball_count >= 10:
            break  # Stop after drawing 10 non-overlapping circles
        
        ((x, y), radius) = cv2.minEnclosingCircle(contour)
        
        if radius > min_ball_radius:  # Only consider contours with a significant size
            new_center = (int(x), int(y))
            if not is_too_close(new_center, centers, min_distance_between_balls):
                distance = (known_diameter * focal_length) / (2 * radius)
                cv2.circle(frame, new_center, int(radius), (0, 0, 255), 2)
                cv2.putText(frame, f"{int(distance)} cm", (new_center[0]-10, new_center[1]-10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
                centers.append(new_center)
                ball_count += 1

    # Overlay the ball count on the top-right corner of the image
    text = f"Balls: {ball_count}"
    cv2.putText(frame, text, (frame.shape[1] - 150, 30),
    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2, cv2.LINE_AA)
    
    # Convert the image back to RGB for displaying with matplotlib
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    return frame_rgb

# Prepare subplots over 3 rows
num_images = len(test_images)
rows = 3
cols = (num_images + rows - 1) // rows  # Calculate the number of columns needed

fig, axs = plt.subplots(rows, cols, figsize=(15, 5 * rows))

# Flatten the axs array for easier iteration
axs = axs.ravel()

for i, image_path in enumerate(test_images):
    result_image = process_image(image_path)
    
    if result_image is not None:
        # Display the image in the subplot
        axs[i].imshow(result_image)
        axs[i].set_title(f"Image {i+1}")
        axs[i].axis('off')

# Hide any unused subplots
for j in range(i + 1, len(axs)):
    axs[j].axis('off')

# Show the results
plt.tight_layout()
plt.show()