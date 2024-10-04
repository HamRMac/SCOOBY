import cv2
import numpy as np
import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, join
import random

def test_one_image(path):
    frame = cv2.imread(path)
    lines = find_lines(frame) # lines is BGR image with red lines overlaying original img
    balls = find_balls(lines)
    plt.imshow(lines)
    plt.show()


def test_image_folder(test_image_folder='tennisbot_ws\\src\\ball_tracker\\ball_tracker\\test_images_real',plot_rows=4,first_idx=0,last_idx=-1,rdmize=False):
    test_images = [f for f in listdir(test_image_folder) if isfile(join(test_image_folder, f))][first_idx:last_idx]

    if rdmize:
        random.shuffle(test_images)

    num_images = len(test_images)
    rows = plot_rows
    cols = (num_images + rows - 1) // rows  # Calculate the number of columns needed

    fig, axs = plt.subplots(rows, cols, figsize=(15, 5 * rows))

    # Flatten the axs array for easier iteration
    axs = axs.ravel()

    for i, image_path in enumerate(test_images):
        image = cv2.imread(f'{test_image_folder}/{image_path}')
        result_image = find_lines(image)
        result_image = find_balls(result_image)
        
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
    

def is_too_close(new_center, centers, min_dist):
    for center in centers:
        if np.linalg.norm(np.array(new_center) - np.array(center)) < min_dist:
            return True
    return False


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
        path_trace = np.zeros_like(image)
        cv2.line(path_trace, tuple(bottom_center), edge_point, (0, 255, 0), 2)  # Green line, thickness 2

    return path_trace


def find_balls(frame):
    # Convert the image to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Known parameters
    lower_green = np.array([24,  24, 114])
    upper_green = np.array([94, 229, 255])
    known_diameter = 6.7  # Diameter of a tennis ball in cm
    focal_length = 700  # Adjust this based on your camera calibration
    min_distance_between_balls = 100  # Minimum distance between centers of detected balls
    min_ball_radius = 15
    
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
                # cv2.circle(frame, new_center, int(radius), (0, 0, 255), 2)
                # centers.append(new_center)
                # radii.append(radius)
                # ball_count += 1
                path_frame = draw_lines_to_ball_edges(frame, [(new_center, radius)])
                mask = np.all(path_frame == [0, 255, 0], axis=-1)
                combined_image = np.where(mask[:, :, None], frame, path_frame)
                combined_image = weighted_img(combined_image, frame,0.5,0.5)

                mask = np.all(combined_image == [255, 0, 0], axis=-1)

                # Check if any pixel matches the condition
                has_blue_pixel = np.any(mask) # if true, then discard

                # plt.imshow(combined_image)
                # plt.title(has_blue_pixel)
                # plt.show()

                if not has_blue_pixel:
                    cv2.circle(frame, new_center, int(radius), (0, 0, 255), 2)
                    centers.append(new_center)
                    radii.append(radius)
                    ball_count += 1
                    # TODO: change centers and radii from list to pqueue, using y_pos as priority



    # Overlay the ball count on the top-right corner of the image
    text = f"Balls: {ball_count}, centre(s) = {centers}"
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
    
    if len(centers) == 0:
        return cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # draw lines to each ball centre
    path_lines = draw_lines_to_ball_edges(frame, zip(centers,radii))

    frame = weighted_img(path_lines,frame)

    # Convert the image back to RGB for displaying with matplotlib
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    return frame_rgb


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
            
def weighted_img(img, initial_img, α=0.8, β=1., λ=0.):
    return cv2.addWeighted(initial_img, α, img, β, λ)

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
    resized_lines_mask = cv2.resize(hough_lines_image, (300, 300))

    return resized_lines_mask

def draw_path_line(xratio, yratio, boundarylength):
    FRAME_SIZE = 300
    # Create a black image of size 300x300
    img = np.zeros((FRAME_SIZE, FRAME_SIZE, 3), dtype=np.uint8)
    frame_bottom_middle = (FRAME_SIZE//2, FRAME_SIZE-1)

    # Map xratio and yratio from (-1, 1) to (0, 300)
    center_x = int((xratio + 1) * (FRAME_SIZE/2))
    center_y = int((yratio + 1) * (FRAME_SIZE/2))

    # Calculate the half boundary length to find top-left and bottom-right points
    half_length = boundarylength // 2
    top_left = (center_x - half_length, center_y - half_length)
    bottom_right = (center_x + half_length, center_y + half_length)

    ball_bottom_middle = (center_x, center_y + half_length)
    cv2.line(img, frame_bottom_middle, ball_bottom_middle, (0,255,0), 2)

    # Draw the green bounding box
    # cv2.rectangle(img, top_left, bottom_right, (0, 255, 0), 2)

    return img

img_false = 'tennisbot_ws\\src\\ball_tracker\\ball_tracker\\test_images_real\\WIN_20240913_12_49_14_Pro.jpg'
img_true = 'tennisbot_ws\\src\\ball_tracker\\ball_tracker\\test_images_real\\WIN_20240913_12_50_05_Pro.jpg'

img = cv2.imread(img_true)
img = cv2.resize(img, (300,300))
lines_mask = find_lines(img)
draw_path_line = draw_path_line(-0.85,-0.36,20)
# draw_path_line = draw_path_line(-0.1,-0.36,20)

masks_combined = weighted_img(lines_mask, draw_path_line,0.5,0.5)

three_combined = weighted_img(masks_combined,img,0.5,0.5)

# check for overlap of masks
green_mask = np.all(masks_combined == [0, 255, 0], axis=-1)
has_collision = np.any(green_mask)


fig, axes = plt.subplots(1, 2, figsize=(10, 5))

# Display the first image in the first subplot
axes[0].imshow(masks_combined)
axes[0].axis('off')  # Hide the axis for better display
axes[0].set_title('has collision: ' + str(has_collision))

# Display the second image in the second subplot
axes[1].imshow(three_combined)
axes[1].axis('off')  # Hide the axis for better display
axes[1].set_title('image with mask')

# Show the plot
plt.tight_layout()
plt.show()


# test_one_image('tennisbot_ws\\src\\ball_tracker\\ball_tracker\\test_images_real\\WIN_20240913_12_50_05_Pro.jpg')

# test_image_folder(first_idx=10,last_idx=-1,rdmize=True,plot_rows=3)
