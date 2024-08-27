// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ball_tracker_msgs:action/FollowBallAction.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_tracker_msgs/action/follow_ball_action.hpp"


#ifndef BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__BUILDER_HPP_
#define BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ball_tracker_msgs/action/detail/follow_ball_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_Goal_timeout
{
public:
  Init_FollowBallAction_Goal_timeout()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_Goal timeout(::ball_tracker_msgs::action::FollowBallAction_Goal::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_Goal>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_Goal_timeout();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_Result_current_distance
{
public:
  Init_FollowBallAction_Result_current_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_Result current_distance(::ball_tracker_msgs::action::FollowBallAction_Result::_current_distance_type arg)
  {
    msg_.current_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_Result>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_Result_current_distance();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_Feedback_success
{
public:
  Init_FollowBallAction_Feedback_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_Feedback success(::ball_tracker_msgs::action::FollowBallAction_Feedback::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_Feedback>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_Feedback_success();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_SendGoal_Request_goal
{
public:
  explicit Init_FollowBallAction_SendGoal_Request_goal(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request goal(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request msg_;
};

class Init_FollowBallAction_SendGoal_Request_goal_id
{
public:
  Init_FollowBallAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_SendGoal_Request_goal goal_id(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowBallAction_SendGoal_Request_goal(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_SendGoal_Request>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_SendGoal_Request_goal_id();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_SendGoal_Response_stamp
{
public:
  explicit Init_FollowBallAction_SendGoal_Response_stamp(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response stamp(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response msg_;
};

class Init_FollowBallAction_SendGoal_Response_accepted
{
public:
  Init_FollowBallAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_SendGoal_Response_stamp accepted(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_FollowBallAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_SendGoal_Response>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_SendGoal_Response_accepted();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_SendGoal_Event_response
{
public:
  explicit Init_FollowBallAction_SendGoal_Event_response(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event response(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event msg_;
};

class Init_FollowBallAction_SendGoal_Event_request
{
public:
  explicit Init_FollowBallAction_SendGoal_Event_request(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_FollowBallAction_SendGoal_Event_response request(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_FollowBallAction_SendGoal_Event_response(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event msg_;
};

class Init_FollowBallAction_SendGoal_Event_info
{
public:
  Init_FollowBallAction_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_SendGoal_Event_request info(::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_FollowBallAction_SendGoal_Event_request(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_SendGoal_Event>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_SendGoal_Event_info();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_GetResult_Request_goal_id
{
public:
  Init_FollowBallAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Request goal_id(::ball_tracker_msgs::action::FollowBallAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_GetResult_Request>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_GetResult_Request_goal_id();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_GetResult_Response_result
{
public:
  explicit Init_FollowBallAction_GetResult_Response_result(::ball_tracker_msgs::action::FollowBallAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Response result(::ball_tracker_msgs::action::FollowBallAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Response msg_;
};

class Init_FollowBallAction_GetResult_Response_status
{
public:
  Init_FollowBallAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_GetResult_Response_result status(::ball_tracker_msgs::action::FollowBallAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_FollowBallAction_GetResult_Response_result(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_GetResult_Response>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_GetResult_Response_status();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_GetResult_Event_response
{
public:
  explicit Init_FollowBallAction_GetResult_Event_response(::ball_tracker_msgs::action::FollowBallAction_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Event response(::ball_tracker_msgs::action::FollowBallAction_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Event msg_;
};

class Init_FollowBallAction_GetResult_Event_request
{
public:
  explicit Init_FollowBallAction_GetResult_Event_request(::ball_tracker_msgs::action::FollowBallAction_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_FollowBallAction_GetResult_Event_response request(::ball_tracker_msgs::action::FollowBallAction_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_FollowBallAction_GetResult_Event_response(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Event msg_;
};

class Init_FollowBallAction_GetResult_Event_info
{
public:
  Init_FollowBallAction_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_GetResult_Event_request info(::ball_tracker_msgs::action::FollowBallAction_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_FollowBallAction_GetResult_Event_request(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_GetResult_Event>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_GetResult_Event_info();
}

}  // namespace ball_tracker_msgs


namespace ball_tracker_msgs
{

namespace action
{

namespace builder
{

class Init_FollowBallAction_FeedbackMessage_feedback
{
public:
  explicit Init_FollowBallAction_FeedbackMessage_feedback(::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage feedback(::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage msg_;
};

class Init_FollowBallAction_FeedbackMessage_goal_id
{
public:
  Init_FollowBallAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowBallAction_FeedbackMessage_feedback goal_id(::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowBallAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_tracker_msgs::action::FollowBallAction_FeedbackMessage>()
{
  return ball_tracker_msgs::action::builder::Init_FollowBallAction_FeedbackMessage_goal_id();
}

}  // namespace ball_tracker_msgs

#endif  // BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__BUILDER_HPP_
