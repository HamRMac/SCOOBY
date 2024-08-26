// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yasmin_msgs/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yasmin_msgs
{

namespace msg
{

namespace builder
{

class Init_State_current_state
{
public:
  explicit Init_State_current_state(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  ::yasmin_msgs::msg::State current_state(::yasmin_msgs::msg::State::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_is_fsm
{
public:
  explicit Init_State_is_fsm(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_current_state is_fsm(::yasmin_msgs::msg::State::_is_fsm_type arg)
  {
    msg_.is_fsm = std::move(arg);
    return Init_State_current_state(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_outcomes
{
public:
  explicit Init_State_outcomes(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_is_fsm outcomes(::yasmin_msgs::msg::State::_outcomes_type arg)
  {
    msg_.outcomes = std::move(arg);
    return Init_State_is_fsm(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_transitions
{
public:
  explicit Init_State_transitions(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_outcomes transitions(::yasmin_msgs::msg::State::_transitions_type arg)
  {
    msg_.transitions = std::move(arg);
    return Init_State_outcomes(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_name
{
public:
  explicit Init_State_name(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_transitions name(::yasmin_msgs::msg::State::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_State_transitions(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_parent
{
public:
  explicit Init_State_parent(::yasmin_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_name parent(::yasmin_msgs::msg::State::_parent_type arg)
  {
    msg_.parent = std::move(arg);
    return Init_State_name(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

class Init_State_id
{
public:
  Init_State_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_parent id(::yasmin_msgs::msg::State::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_State_parent(msg_);
  }

private:
  ::yasmin_msgs::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yasmin_msgs::msg::State>()
{
  return yasmin_msgs::msg::builder::Init_State_id();
}

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
