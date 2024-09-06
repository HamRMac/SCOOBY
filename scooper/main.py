import tkinter as tk
from gpiozero import AngularServo
from time import sleep

# Initialize the servo
servo = AngularServo(18, min_angle=0, max_angle=180, min_pulse_width=0.0006, max_pulse_width=0.0024)
servo.angle = 0  # Start with the servo angle set to 0

# Define functions to control the servo
def move_up():
    servo.angle = 180

def move_down():
    servo.angle = 0

# Create the GUI application
root = tk.Tk()
root.title("Servo Control")

# Create the 'Up' and 'Down' buttons
up_button = tk.Button(root, text="Up", command=move_up, height=2, width=10)
up_button.pack(pady=10)

down_button = tk.Button(root, text="Down", command=move_down, height=2, width=10)
down_button.pack(pady=10)

# Run the GUI loop
root.mainloop()
