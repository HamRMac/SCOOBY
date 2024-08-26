// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state_machine.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yasmin_msgs/msg/detail/state_machine__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'states'
#include "yasmin_msgs/msg/detail/state__traits.hpp"

namespace yasmin_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const StateMachine & msg,
  std::ostream & out)
{
  out << "{";
  // member: states
  {
    if (msg.states.size() == 0) {
      out << "states: []";
    } else {
      out << "states: [";
      size_t pending_items = msg.states.size();
      for (auto item : msg.states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateMachine & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.states.size() == 0) {
      out << "states: []\n";
    } else {
      out << "states:\n";
      for (auto item : msg.states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateMachine & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace yasmin_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yasmin_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yasmin_msgs::msg::StateMachine & msg,
  std::ostream & out, size_t indentation = 0)
{
  yasmin_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yasmin_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yasmin_msgs::msg::StateMachine & msg)
{
  return yasmin_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yasmin_msgs::msg::StateMachine>()
{
  return "yasmin_msgs::msg::StateMachine";
}

template<>
inline const char * name<yasmin_msgs::msg::StateMachine>()
{
  return "yasmin_msgs/msg/StateMachine";
}

template<>
struct has_fixed_size<yasmin_msgs::msg::StateMachine>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yasmin_msgs::msg::StateMachine>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yasmin_msgs::msg::StateMachine>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__TRAITS_HPP_
