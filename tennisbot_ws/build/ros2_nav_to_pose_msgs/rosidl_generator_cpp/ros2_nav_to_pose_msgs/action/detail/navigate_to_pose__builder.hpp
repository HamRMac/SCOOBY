// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_nav_to_pose_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_nav_to_pose_msgs/action/navigate_to_pose.hpp"


#ifndef ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
#define ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_nav_to_pose_msgs/action/detail/navigate_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Goal_goal_pose
{
public:
  Init_NavigateToPose_Goal_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Goal goal_pose(::ros2_nav_to_pose_msgs::action::NavigateToPose_Goal::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_Goal>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_Goal_goal_pose();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Result_success
{
public:
  Init_NavigateToPose_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Result success(::ros2_nav_to_pose_msgs::action::NavigateToPose_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_Result>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_Result_success();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Feedback_remaining_distance_to_goal
{
public:
  Init_NavigateToPose_Feedback_remaining_distance_to_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Feedback remaining_distance_to_goal(::ros2_nav_to_pose_msgs::action::NavigateToPose_Feedback::_remaining_distance_to_goal_type arg)
  {
    msg_.remaining_distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_Feedback>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_Feedback_remaining_distance_to_goal();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Request_goal
{
public:
  explicit Init_NavigateToPose_SendGoal_Request_goal(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request goal(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

class Init_NavigateToPose_SendGoal_Request_goal_id
{
public:
  Init_NavigateToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Request_goal goal_id(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Request>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_SendGoal_Request_goal_id();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Response_stamp
{
public:
  explicit Init_NavigateToPose_SendGoal_Response_stamp(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response stamp(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

class Init_NavigateToPose_SendGoal_Response_accepted
{
public:
  Init_NavigateToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Response_stamp accepted(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigateToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Response>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_SendGoal_Response_accepted();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Event_response
{
public:
  explicit Init_NavigateToPose_SendGoal_Event_response(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event response(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

class Init_NavigateToPose_SendGoal_Event_request
{
public:
  explicit Init_NavigateToPose_SendGoal_Event_request(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateToPose_SendGoal_Event_response request(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateToPose_SendGoal_Event_response(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

class Init_NavigateToPose_SendGoal_Event_info
{
public:
  Init_NavigateToPose_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Event_request info(::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateToPose_SendGoal_Event_request(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_SendGoal_Event>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_SendGoal_Event_info();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Request_goal_id
{
public:
  Init_NavigateToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Request goal_id(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Request>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_GetResult_Request_goal_id();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Response_result
{
public:
  explicit Init_NavigateToPose_GetResult_Response_result(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response result(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response msg_;
};

class Init_NavigateToPose_GetResult_Response_status
{
public:
  Init_NavigateToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_GetResult_Response_result status(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigateToPose_GetResult_Response_result(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Response>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_GetResult_Response_status();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Event_response
{
public:
  explicit Init_NavigateToPose_GetResult_Event_response(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event response(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event msg_;
};

class Init_NavigateToPose_GetResult_Event_request
{
public:
  explicit Init_NavigateToPose_GetResult_Event_request(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateToPose_GetResult_Event_response request(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateToPose_GetResult_Event_response(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event msg_;
};

class Init_NavigateToPose_GetResult_Event_info
{
public:
  Init_NavigateToPose_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_GetResult_Event_request info(::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateToPose_GetResult_Event_request(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_GetResult_Event>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_GetResult_Event_info();
}

}  // namespace ros2_nav_to_pose_msgs


namespace ros2_nav_to_pose_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_FeedbackMessage_feedback
{
public:
  explicit Init_NavigateToPose_FeedbackMessage_feedback(::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage feedback(::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

class Init_NavigateToPose_FeedbackMessage_goal_id
{
public:
  Init_NavigateToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_FeedbackMessage_feedback goal_id(::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_nav_to_pose_msgs::action::NavigateToPose_FeedbackMessage>()
{
  return ros2_nav_to_pose_msgs::action::builder::Init_NavigateToPose_FeedbackMessage_goal_id();
}

}  // namespace ros2_nav_to_pose_msgs

#endif  // ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
