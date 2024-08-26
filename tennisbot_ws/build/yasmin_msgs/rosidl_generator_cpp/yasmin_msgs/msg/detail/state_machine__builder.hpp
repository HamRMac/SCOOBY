// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state_machine.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yasmin_msgs/msg/detail/state_machine__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yasmin_msgs
{

namespace msg
{

namespace builder
{

class Init_StateMachine_states
{
public:
  Init_StateMachine_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yasmin_msgs::msg::StateMachine states(::yasmin_msgs::msg::StateMachine::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yasmin_msgs::msg::StateMachine msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yasmin_msgs::msg::StateMachine>()
{
  return yasmin_msgs::msg::builder::Init_StateMachine_states();
}

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
