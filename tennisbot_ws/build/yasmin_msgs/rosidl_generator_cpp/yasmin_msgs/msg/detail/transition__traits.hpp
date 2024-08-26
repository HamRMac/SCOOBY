// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/transition.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__TRANSITION__TRAITS_HPP_
#define YASMIN_MSGS__MSG__DETAIL__TRANSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yasmin_msgs/msg/detail/transition__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yasmin_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Transition & msg,
  std::ostream & out)
{
  out << "{";
  // member: outcome
  {
    out << "outcome: ";
    rosidl_generator_traits::value_to_yaml(msg.outcome, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Transition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: outcome
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "outcome: ";
    rosidl_generator_traits::value_to_yaml(msg.outcome, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Transition & msg, bool use_flow_style = false)
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
  const yasmin_msgs::msg::Transition & msg,
  std::ostream & out, size_t indentation = 0)
{
  yasmin_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yasmin_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yasmin_msgs::msg::Transition & msg)
{
  return yasmin_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yasmin_msgs::msg::Transition>()
{
  return "yasmin_msgs::msg::Transition";
}

template<>
inline const char * name<yasmin_msgs::msg::Transition>()
{
  return "yasmin_msgs/msg/Transition";
}

template<>
struct has_fixed_size<yasmin_msgs::msg::Transition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yasmin_msgs::msg::Transition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yasmin_msgs::msg::Transition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YASMIN_MSGS__MSG__DETAIL__TRANSITION__TRAITS_HPP_
