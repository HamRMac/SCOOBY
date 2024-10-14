<div align="center">
<img src="https://github.com/user-attachments/assets/4e8318ca-fb65-475f-a1ae-e189cb9a98f0" width="600" alt="Project S.C.O.O.B.Y" align="center"/>

<h1>Project "S.C.O.O.B.Y"</h1>
<p><b>S</b>earch, <b>C</b>ollect, <b>O</b>rientate and <b>O</b>rganise Tennis <b>B</b>alls S<b>y</b>stem</p>
<p>This repository contains the code for the prototype version of the robot desinged and built by 2024 ECE4132 Team E14. There will be no ongoing support for this repository. All code is provided as is.</p>
</div>

## About S.C.O.O.B.Y
Scooby is an autonomus robot designed to detect, collect, and deposit tennisballs on a tennis court. The robot uses a scooper system to lift up balls into a carrying chamber and a servo operated gate to deposit the balls into a cardboard box for collection. This system was desinged for the Monash University's ECE4132 Project. The following stages will help you setup and install the code required for operation of the robot
## Required Hardware, Operating System, and Software
Scooby operates on a Raspberry Pi 4 4GB model running Ubuntu LTS Server 24.04. The system requires [ROS2 Jazzy](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html) to be installed on the system. It is assumed you have followed the instructions to install ROS2 already. It is also **highly** recommended that you add the [source command](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html#setup-environment) to your ~/.bashrc file to auto-source the ROS2 commands. You must also have the [Colcon](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html#install-colcon) build system installed to be able to build the required files for the operation of the robot. The servos on the robot required the [pigpio](https://abyz.me.uk/rpi/pigpio/download.html) library to provide hardware control over the PWM timings required for accurate operation of the servos. You must also enable the pigpio daemon service to ensure that the ROS2 nodes can control the PWM directly. [This StackExchange](https://raspberrypi.stackexchange.com/questions/70568/how-to-run-pigpiod-on-boot) post provides information on setting up the daemon for auto-start. You must have the UART port enabled on the Raspberry Pi and the motor controller connected to the primary UART0 port of the Pi.
<div>
  <em><b>THIS REPOSITORY DOES NOT WORK ON THE RASPBERRY PI 5</b></em>
  <p>Serveral changes were made to the underlying GPIO control hardware for the Raspberry Pi 5 which means hardware control of the PWM system does not currently work as of writing this. The UART ports of the Pi have also been changed so current configuratiosn given in this repo will fail to bind to the UART</p>
</div>

## Installation steps
0. If you haven't already, source the ROS2 library
```console
user@scooby:/$ source /opt/ros/jazzy/setup.bash
```
2. Rercursively clone this repository into your home folder
```console
user@scooby:/$ cd ~
user@scooby:~$ git clone --recurse-submodules -j8 https://github.com/HamRMac/ScooperBot
```
2. CD into the workspace folder of the cloned repository
```console
user@scooby:~$ cd ScooperBot/tennisbot_ws
```
3. Build the workspace with colcon and the symlink install flag. This process will take a few minutes.
```console
user@scooby:tennisbot_ws$ colcon build --symlink-install
```
4. Source your workspace and return to the home folder
```console
user@scooby:tennisbot_ws$ source ./install/setup.bash
user@scooby:tennisbot_ws$ cd ~
```
## Operation Steps
The following commands are used to start the operation of the robot. It is recommended that you use the [tmux](https://github.com/tmux/tmux) library to prevent multiple ssh connections to the Pi thereby increasing performance. This is not required.<br>
For each of the following blocks they shoiuld be run in a new terminal session. They all assume that the hardware is configured as described in the accompanying report. If your hardware is different you may modify the [config file]() supplied to adjust pins and other node parameters
1. Start [FoxGlove Bridge](https://docs.foxglove.dev/docs/connecting-to-data/ros-foxglove-bridge) (Optional. Used for monitoring the robot)
```console
user@scooby:~$ ros2 launch foxglove_bridge foxglove_bridge_launch.xml
```
2. Disable the UART getty service and start the robot controler
```console
user@scooby:~$ sudo systemctl stop serial-getty@ttyS0.service
user@scooby:~$ ros2 launch tennisbotmaster start_robot_ctlr.launch.py
```
3. Start the camera and rotator nodes
```console
user@scooby:~$ ros2 launch tennisbotmaster start_camera.launch.py
```
4. Start the servo controller
```console
user@scooby:~$ ros2 launch lift_arm init_servos.launch.py
```
5. Start the box tracking and detection node
```console
user@scooby:~$ ros2 run ball_tracker detect_box --ros-args -r image_in:=/camera/rotated_image
```
6. Start the action server to have the robot navigate to and deposit into the box
```console
user@scooby:~$ ros2 run ball_tracker deposit_to_box_action_server --ros-args --params-file /home/user/Scooperbot_params.yaml
```
7. Start the ball detection node and the action server to have the robot navigate to and collect into the ball.
```console
user@scooby:~$ ros2 launch ball_tracker follow_ball_action.launch.py params_file:=/home/user/Scooperbot_params.yaml image_topic:=/camera/rotated_image detect_only:=false
```
8. Start the state machine (only run once all the other nodes have started and initialised correctly
```console
user@scooby:~$ ros2 run yasmin_fsms robot_collect_and_deposit.py
```
The robot should begin momentarily.<b>
Optionally, you can also activate the boundary guard to prevent the robot from leaving the bounds of the court. This was not required during the demo but it may be required for your use case
```console
user@scooby:~$ ros2 run line_detector detect_lines --ros-args -p input_topic:=/camera/rotated_image
...
IN SEPARATE CONSOLE
...
user@scooby:~$ ros2 run line_detector boundary_guard
```
## Our Thanks
<img src="https://github.com/user-attachments/assets/717f8cea-8902-41a6-a6a1-21f10e9621d8" width="200" alt="1st Place Trophy" align="right"/>
<b>A big thanks to the ECE4132 teaching staff for coming up with such an interesting and challenging project. Thanks to [Josh Newans](https://github.com/joshnewans) for his repositories and guide videos that helped us learn how to use ROS and which provided the Differential Drive controller used to control the arduino used as the motor controller. Thanks to the ROS2 community for such a versatile and powerful open-source project.<br>
Of course the biggest thanks goes to our team members. Well done with all of your contributions to the physical robot and to the code-base. Our efforts contributed to our great 1st place outcome in the demonstration. Kudos to you all!</b>

