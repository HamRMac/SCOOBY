// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/transition.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__TRANSITION__BUILDER_HPP_
#define YASMIN_MSGS__MSG__DETAIL__TRANSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yasmin_msgs/msg/detail/transition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yasmin_msgs
{

namespace msg
{

namespace builder
{

class Init_Transition_state
{
public:
  explicit Init_Transition_state(::yasmin_msgs::msg::Transition & msg)
  : msg_(msg)
  {}
  ::yasmin_msgs::msg::Transition state(::yasmin_msgs::msg::Transition::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yasmin_msgs::msg::Transition msg_;
};

class Init_Transition_outcome
{
public:
  Init_Transition_outcome()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Transition_state outcome(::yasmin_msgs::msg::Transition::_outcome_type arg)
  {
    msg_.outcome = std::move(arg);
    return Init_Transition_state(msg_);
  }

private:
  ::yasmin_msgs::msg::Transition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yasmin_msgs::msg::Transition>()
{
  return yasmin_msgs::msg::builder::Init_Transition_outcome();
}

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__TRANSITION__BUILDER_HPP_
