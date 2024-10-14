<div align="center">
<img src="https://github.com/HamRMac/SCOOBY/blob/main/assets/scooby.png" width="600" alt="Project S.C.O.O.B.Y" align="center"/>

<h1>Project "S.C.O.O.B.Y"</h1>
<p>A <b>S</b>earch, <b>C</b>ollect, <b>O</b>rientate and <b>O</b>rganise Tennis <b>B</b>alls S<b>y</b>stem</p>
<p>This repository contains the code for the prototype version of the robot desinged and built by the 2024 ECE4132 Team, E14. There will be no ongoing support for this repository. All code is provided as is.</p>
</div>

## About S.C.O.O.B.Y
S.C.O.O.B.Y is an autonomous robot designed to detect and collect tennisballs on a tennis court and deposit them to a storage box (kind of like a dog). The robot uses a scooper system to lift up balls into a carrying chamber and a servo operated gate to deposit the balls into a cardboard box. This system was designed for Monash University's 2024 ECE4132 Project. The following sections will help you setup and install the code required for operation of the robot.
## Required Hardware, Operating System, and Software
### Hardware, OS, and ROS
S.C.O.O.B.Y operates using a Raspberry Pi 4 4GB model running Ubuntu LTS Server 24.04 (installed via the Raspberry Pi installer). The system requires [ROS2 Jazzy](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html) to be installed on the system. It is assumed you have installed ROS2 already. It is also **highly** recommended that you add the [source command](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html#setup-environment) to your ~/.bashrc file to auto-source ROS2 on startup. You must also have the [Colcon](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html#install-colcon) build system installed to be able to build the required files for the operation of the robot.
### GPIO Control and UART
The servos on the robot requires the [pigpio](https://abyz.me.uk/rpi/pigpio/download.html) library to provide hardware control over the PWM timings required for accurate operation of the servos. You must also enable the pigpio daemon service to ensure that the ROS2 nodes can control the PWM directly. [This StackExchange](https://raspberrypi.stackexchange.com/questions/70568/how-to-run-pigpiod-on-boot) post provides information on setting up the daemon for auto-start. You must have the UART port enabled on the Raspberry Pi and the motor controller connected to the primary UART0 port of the Pi.
<div>
  <em><b>THIS REPOSITORY DOES NOT WORK ON THE RASPBERRY PI 5</b></em>
  <p>Serveral changes were made to the underlying GPIO control hardware for the Raspberry Pi 5 compared to earlier versions which means hardware control of the PWM system does not currently work as of writing this. The UART ports of the Pi have also been changed so current node configurations given in this repo will mean that the motor controller node will fail to bind to the UART without changes. There are no plans to support the Raspberry Pi 5</p>
</div>

## Installation steps
0. If you haven't already, source the ROS2 library
```console
user@scooby:/$ source /opt/ros/jazzy/setup.bash
```
1. Rercursively clone this repository into your home folder
```console
user@scooby:/$ cd ~
user@scooby:~$ git clone --recurse-submodules -j8 https://github.com/HamRMac/SCOOBY
```
2. CD into the workspace folder of the cloned repository
```console
user@scooby:~$ cd SCOOBY/tennisbot_ws
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
For each of the following blocks they should be run in a new terminal session. All nodes assume that the hardware is configured as described in the accompanying report. If your hardware is different you may need to modify the [config file](https://github.com/HamRMac/SCOOBY/blob/main/SCOOBY_params.yaml) supplied or the nodes themselves to adjust pins and other parameters.
1. Start [FoxGlove Bridge](https://docs.foxglove.dev/docs/connecting-to-data/ros-foxglove-bridge) (Optional. Used for monitoring the robot. You must install this package with apt if you wish to use it)
```console
user@scooby:~$ ros2 launch foxglove_bridge foxglove_bridge_launch.xml
```
2. Disable the UART getty service and start the robot motor controller
```console
user@scooby:~$ sudo systemctl stop serial-getty@ttyS0.service
user@scooby:~$ ros2 launch tennisbotmaster start_robot_ctlr.launch.py
```
3. Start the camera and image rotator nodes
```console
user@scooby:~$ ros2 launch tennisbotmaster start_camera.launch.py
```
4. Start the servo controller and switch detectors
```console
user@scooby:~$ ros2 launch lift_arm init_servos.launch.py
```
5. Start the box detection/tracking node
```console
user@scooby:~$ ros2 run ball_tracker detect_box --ros-args -r image_in:=/camera/rotated_image
```
6. Start the action server responsible for the robot navigating to and depositing the balls into the box
```console
user@scooby:~$ ros2 run ball_tracker deposit_to_box_action_server --ros-args --params-file /home/user/SCOOBY_params.yaml
```
7. Start the ball detection node and accompanying action server responsible for the robot navigating to and collecting the tennis balls.
```console
user@scooby:~$ ros2 launch ball_tracker follow_ball_action.launch.py params_file:=/home/user/SCOOBY_params.yaml image_topic:=/camera/rotated_image detect_only:=false
```
8. Start the state machine (only run once all the other nodes have started and initialised correctly)
```console
user@scooby:~$ ros2 run yasmin_fsms robot_collect_and_deposit.py
```
The robot should begin momentarily.
<br><br>
<i>Optionally, you can also activate the boundary guard to prevent the robot from leaving the bounds of the court. This was not required during the demo but it may be required for your use case.</i>
```console
user@scooby:~$ ros2 run line_detector detect_lines --ros-args -p input_topic:=/camera/rotated_image
...
IN A SEPARATE CONSOLE
...
user@scooby:~$ ros2 run line_detector boundary_guard
```
## Our Thanks
<img src="https://github.com/HamRMac/SCOOBY/blob/main/assets/1st-place-medal.png" width="200" alt="1st Place Trophy" align="right"/>
A big thanks to the ECE4132 teaching staff for coming up with such an interesting and challenging project. Thanks to Josh Newans (https://github.com/joshnewans) for his repositories and guide videos that helped us learn how to use ROS and which provided the Differential Drive controller used to control the arduino used as the motor controller. Thanks to the ROS2 community for such a versatile and powerful open-source project.<br>
Of course the biggest thanks go to our team members. Well done to everyone for your contributions to both the physical robot and the code-base. Your combined efforts contributed to our great 1st place outcome in the demonstration. Kudos to you all!
