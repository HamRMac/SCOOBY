#!/usr/bin/env python3

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

class CollectBallState(ActionState):
    def __init__(self, node: Node):
        super().__init__(
            FollowBallAction,
            "/follow_ball",
            self.create_goal_handler,
            ["completed", "aborted", "canceled"],
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
            return "completed"
        else:
            return "aborted"


class DepositBallState(ActionState):
    def __init__(self, node: Node):
        super().__init__(
            DepositToBox,
            "/follow_box",
            self.create_goal_handler,
            ["completed", "aborted", "canceled"],
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
            return "completed"
        else:
            return "aborted"


def main():
    print("Starting robot_collect_and_deposit fsm")
    rclpy.init()

    # Create a ROS node
    node = rclpy.create_node('robot_collect_and_deposit')

    # Create the State Machine
    sm = StateMachine(outcomes=["outcome_final"])

    # Add the COLLECT_BALL state twice
    sm.add_state(
        "COLLECT_BALL_1",
        CollectBallState(node),
        transitions={
            "completed": "COLLECT_BALL_2",
            "aborted": "outcome_final",
            "canceled": "outcome_final"
        }
    )

    sm.add_state(
        "COLLECT_BALL_2",
        CollectBallState(node),
        transitions={
            "completed": "DEPOSIT_BALL",
            "aborted": "outcome_final",
            "canceled": "outcome_final"
        }
    )

    # Add the DEPOSIT_BALL state
    sm.add_state(
        "DEPOSIT_BALL",
        DepositBallState(node),
        transitions={
            "completed": "outcome_final",
            "aborted": "outcome_final",
            "canceled": "outcome_final"
        }
    )

    # Publish FSM info to the YASMIN viewer for visualization
    YasminViewerPub("YASMIN_COLLECT_AND_DEPOSIT", sm)

    # Execute the FSM
    blackboard = Blackboard()
    outcome = sm(blackboard)
    print(outcome)

    # Clean up
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()