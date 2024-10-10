#!/usr/bin/env python3
# ST for final Demo
# Written by Team E14
# Wrtten on 11/10/24
# Written using the awesome YASMIN library avaliable at https://github.com/uleroboticsgroup/yasmin

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from yasmin import CbState
from yasmin import StateMachine
from yasmin import Blackboard
from yasmin_ros import ActionState
from yasmin_ros.basic_outcomes import SUCCEED, ABORT
from yasmin_viewer import YasminViewerPub
from ball_tracker_msgs.action import FollowBallAction, DepositToBox
from std_msgs.msg import Bool
import time
from math import floor

class CollectBallState(ActionState):
    def __init__(self, node: Node):
        super().__init__(
            FollowBallAction,
            "/follow_ball",
            self.create_goal_handler,
            ["drop_off", "next_pickup", "canceled"],
            self.result_handler,
            self.feedback_handler,
        )
        self.node = node
        self.process_img_ball_publisher = self.node.create_publisher(Bool, '/process_img_ball', 10)

    def create_goal_handler(self, blackboard: Blackboard) -> FollowBallAction.Goal:
        # Publish true to process_img_ball if detecting the ball, otherwise false
        msg = Bool()
        msg.data = True  # Assuming we are detecting the ball during goal creation
        self.process_img_ball_publisher.publish(msg)
        print("Setting process_img_ball = true")
        return FollowBallAction.Goal()

    def feedback_handler(self, blackboard: Blackboard, feedback: FollowBallAction.Feedback) -> None:
        blackboard.current_distance = feedback.current_distance

    def result_handler(self, blackboard: Blackboard, result: FollowBallAction.Result) -> str:
        # Publish false to process_img_ball after action is completed
        msg = Bool()
        msg.data = False
        self.process_img_ball_publisher.publish(msg)
        print("Setting process_img_ball = false")

        if result.success:
            # Increment the number of collected balls by 1
            blackboard.balls_collected += 1
            print(f"Collected ball. Have now collected {blackboard.balls_collected} of {blackboard.max_balls} balls")
            # Check to see if we are out of time
            elapsed_time = blackboard.start_time-time.time()
            if (elapsed_time > blackboard.max_time):
                print(f"Max Time Exceeded. Dropping Off now")
                return "drop_off"
            print(f"We have {floor(blackboard.max_time-elapsed_time)} seconds remaining")
            # Check if we have the required balls
            if (blackboard.balls_collected >= blackboard.max_balls):
                
                return "drop_off"
            else:
                return "next_pickup"
        else:
            print(f"Failed to collect ball. Have collected {blackboard.balls_collected} balls")
            return "next_pickup"


class DepositBallState(ActionState):
    def __init__(self, node: Node):
        super().__init__(
            DepositToBox,
            "/follow_box",
            self.create_goal_handler,
            ["completed", "failed", "canceled"],
            self.result_handler,
        )
        self.node = node
        self.process_img_box_publisher = self.node.create_publisher(Bool, '/process_img_box', 10)

    def create_goal_handler(self, blackboard: Blackboard) -> DepositToBox.Goal:
        # Publish true to process_img_box if detecting the box, otherwise false
        msg = Bool()
        msg.data = True  # Assuming we are detecting the box during goal creation
        self.process_img_box_publisher.publish(msg)
        print("Setting process_img_box = true")
        return DepositToBox.Goal()

    def result_handler(self, blackboard: Blackboard, result: DepositToBox.Result) -> str:
        # Publish false to process_img_box after action is completed
        msg = Bool()
        msg.data = False
        self.process_img_box_publisher.publish(msg)
        print("Setting process_img_box = false")

        if result.success:
            # Rest the number of collected balls
            blackboard.balls_collected = 0
            blackboard.failed_dropoff_attempts = 0
            print(f"Drop-off complete. Reset ball counter to {blackboard.balls_collected} balls")
            elapsed_time = blackboard.start_time-time.time()
            if elapsed_time > blackboard.max_time:
                print(f"Max Time Exceeded. Stopping")
                return "canceled"
            print(f"We have {floor(blackboard.max_time-elapsed_time)} seconds remaining")
            return "completed"
        else:
            # Failed to drop off the balls
            blackboard.failed_dropoff_attempts += 1
            print(f"Failed to deposit balls {blackboard.failed_dropoff_attempts} time(s)")
            if blackboard.failed_dropoff_attempts == blackboard.max_failed_dropoff_attempts:
                # Give up
                print("WARN!!!: Max retries reached. Giving Up.")
                return "canceled"
            else:
                # Try again
                print(f"Trying again. {blackboard.max_failed_dropoff_attempts-blackboard.failed_dropoff_attempts} retry/retries left")
                return "failed"


def main():
    print("Starting robot_collect_and_deposit fsm")
    rclpy.init()

    # Create a ROS node
    node = rclpy.create_node('robot_collect_and_deposit')

    # Create the State Machine
    sm = StateMachine(outcomes=["outcome_final"])

    # Add the COLLECT_BALL state twice
    sm.add_state(
        "COLLECT_BALL",
        CollectBallState(node),
        transitions={
            "next_pickup": "COLLECT_BALL",
            "drop_off": "DEPOSIT_BALL",
            "canceled": "outcome_final"
        }
    )

    # Add the DEPOSIT_BALL state
    sm.add_state(
        "DEPOSIT_BALL",
        DepositBallState(node),
        transitions={
            "completed": "COLLECT_BALL",
            "failed": "DEPOSIT_BALL",
            "canceled": "outcome_final"
        }
    )

    # Publish FSM info to the YASMIN viewer for visualization
    YasminViewerPub("YASMIN_COLLECT_AND_DEPOSIT", sm)

    # Set Params
    blackboard = Blackboard()
    blackboard.balls_collected = 0
    blackboard.max_balls = 5
    blackboard.failed_dropoff_attempts = 0
    blackboard.max_failed_dropoff_attempts = 2
    blackboard.start_time = time.time()  # Record the global start time
    blackboard.max_time = 9*60

    # Execute the FSM
    outcome = sm(blackboard)
    print(outcome)

    # Clean up
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()