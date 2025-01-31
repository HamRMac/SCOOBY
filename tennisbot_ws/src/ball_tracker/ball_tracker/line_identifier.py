import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import cv2
from os import listdir
from os.path import isfile, join

def draw_lines(img, houghLines, color=[0, 255, 0], thickness=2):
    for line in houghLines:
        for rho,theta in line:
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a*rho
            y0 = b*rho
            x1 = int(x0 + 1000*(-b))
            y1 = int(y0 + 1000*(a))
            x2 = int(x0 - 1000*(-b))
            y2 = int(y0 - 1000*(a))

            cv2.line(img,(x1,y1),(x2,y2),color,thickness)   
            

def weighted_img(img, initial_img, α=0.8, β=1., λ=0.):
    return cv2.addWeighted(initial_img, α, img, β, λ)


def get_line_equations(houghLines):
    if houghLines is None:
        return None
    
    line_equations = []
    for line in houghLines:
        for rho, theta in line:
            a = np.cos(theta)
            b = np.sin(theta)
            
            # Check if the line is vertical (theta close to 0 or pi)
            if b == 0:  # Vertical line case
                x_intercept = rho / a
                line_equations.append(f"x = {x_intercept}")
            else:
                # For non-vertical lines, calculate slope (m) and y-intercept (c)
                m = -a / b
                c = rho / b
                line_equations.append(f"y = {m}x + {c}")
    
    return line_equations

def find_lines(img): 
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blurred_image = cv2.GaussianBlur(gray_image, (9, 9), 2)
    edges_image = cv2.Canny(blurred_image, 50, 120)
    
    rho_resolution = 1
    theta_resolution = np.pi/180
    threshold = 155
    
    hough_lines = cv2.HoughLines(edges_image, rho_resolution , theta_resolution , threshold)
    
    if hough_lines is None:
        return []


    hough_lines_image = np.zeros_like(img)
    draw_lines(hough_lines_image, hough_lines)
    original_image_with_hough_lines = weighted_img(hough_lines_image,img)

    return original_image_with_hough_lines



test_image_folder = 'tennisbot_ws/src/ball_tracker/ball_tracker/test_images_real'
test_images = [f for f in listdir(test_image_folder) if isfile(join(test_image_folder, f))]

for image_path in test_images:
    image = cv2.cvtColor(cv2.imread(f'{test_image_folder}/{image_path}'), cv2.COLOR_BGR2RGB)
    image = find_lines(image)
    
    plt.imshow(image, cmap='gray') 
    plt.show()