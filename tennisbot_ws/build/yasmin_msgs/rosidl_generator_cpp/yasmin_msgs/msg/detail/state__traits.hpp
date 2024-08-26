// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yasmin_msgs/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'transitions'
#include "yasmin_msgs/msg/detail/transition__traits.hpp"

namespace yasmin_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: parent
  {
    out << "parent: ";
    rosidl_generator_traits::value_to_yaml(msg.parent, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: transitions
  {
    if (msg.transitions.size() == 0) {
      out << "transitions: []";
    } else {
      out << "transitions: [";
      size_t pending_items = msg.transitions.size();
      for (auto item : msg.transitions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: outcomes
  {
    if (msg.outcomes.size() == 0) {
      out << "outcomes: []";
    } else {
      out << "outcomes: [";
      size_t pending_items = msg.outcomes.size();
      for (auto item : msg.outcomes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_fsm
  {
    out << "is_fsm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fsm, out);
    out << ", ";
  }

  // member: current_state
  {
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: parent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "parent: ";
    rosidl_generator_traits::value_to_yaml(msg.parent, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: transitions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.transitions.size() == 0) {
      out << "transitions: []\n";
    } else {
      out << "transitions:\n";
      for (auto item : msg.transitions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: outcomes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.outcomes.size() == 0) {
      out << "outcomes: []\n";
    } else {
      out << "outcomes:\n";
      for (auto item : msg.outcomes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: is_fsm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_fsm: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fsm, out);
    out << "\n";
  }

  // member: current_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
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
  const yasmin_msgs::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  yasmin_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yasmin_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yasmin_msgs::msg::State & msg)
{
  return yasmin_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yasmin_msgs::msg::State>()
{
  return "yasmin_msgs::msg::State";
}

template<>
inline const char * name<yasmin_msgs::msg::State>()
{
  return "yasmin_msgs/msg/State";
}

template<>
struct has_fixed_size<yasmin_msgs::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yasmin_msgs::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yasmin_msgs::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
