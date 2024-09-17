import cv2
import numpy as np
import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, join

# Known parameters
lower_green = np.array([24,  24, 114])
upper_green = np.array([94, 229, 255])
known_diameter = 6.7  # Diameter of a tennis ball in cm
focal_length = 700  # Adjust this based on your camera calibration
min_distance_between_balls = 100  # Minimum distance between centers of detected balls
min_ball_radius = 15

test_image_folder = 'tennisbot_ws\\src\\ball_tracker\\ball_tracker\\test_images_real'
test_images = [f for f in listdir(test_image_folder) if isfile(join(test_image_folder, f))]
test_images = test_images[18:]
print(test_images)


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
    radii = []
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
                # cv2.putText(frame, f"{int(distance)} cm", (new_center[0]-10, new_center[1]-10),
                #             cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
                centers.append(new_center)
                radii.append(radius)
                ball_count += 1

    # Overlay the ball count on the top-right corner of the image
    text = f"Balls: {ball_count}\n centre(s) = {centers}"
    # Set the font, scale, and thickness
    font = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 0.5  # Half the size
    thickness = 2

    # Get the size of the text (width and height)
    (text_width, text_height), _ = cv2.getTextSize(text, font, font_scale, thickness)

    # Calculate the x-coordinate to right-align the text
    x = frame.shape[1] - text_width - 10  # Subtract some padding (e.g., 10 pixels)

    # Define the y-coordinate (you can set this to any vertical position you want)
    y = 30

    # Put the text on the frame
    cv2.putText(frame, text, (x, y), font, font_scale, (0, 0, 255), thickness, cv2.LINE_AA)
    
    # draw lines to each ball centre
    frame = draw_lines_to_ball_edges(frame, zip(centers,radii))

    # Convert the image back to RGB for displaying with matplotlib
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    return frame_rgb


def draw_lines_to_ball_edges(image, balls):
    # Get the image dimensions
    height, width, _ = image.shape
    
    # Define the bottom center of the image
    bottom_center = np.array([width // 2, height - 1])
    
    # Loop through each ball (center, radius) tuple
    for (center, radius) in balls:
        # Get the center of the ball
        centerX, centerY = center
        
        # Create a vector from the bottom center to the ball's center
        direction = np.array([centerX, centerY]) - bottom_center
        
        # Normalize the direction vector
        direction_normalized = direction / np.linalg.norm(direction)
        
        # Calculate the point on the edge of the ball in the direction of the vector
        edge_point = np.array([centerX, centerY]) - direction_normalized * radius
        edge_point = tuple(edge_point.astype(int))  # Convert to integer for OpenCV
        
        # Draw a line from the bottom center to the edge of the ball
        cv2.line(image, tuple(bottom_center), edge_point, (0, 255, 0), 2)  # Green line, thickness 2

    return image

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