// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/transition.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_HPP_
#define YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yasmin_msgs__msg__Transition __attribute__((deprecated))
#else
# define DEPRECATED__yasmin_msgs__msg__Transition __declspec(deprecated)
#endif

namespace yasmin_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Transition_
{
  using Type = Transition_<ContainerAllocator>;

  explicit Transition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->outcome = "";
      this->state = "";
    }
  }

  explicit Transition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : outcome(_alloc),
    state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->outcome = "";
      this->state = "";
    }
  }

  // field types and members
  using _outcome_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _outcome_type outcome;
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__outcome(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->outcome = _arg;
    return *this;
  }
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yasmin_msgs::msg::Transition_<ContainerAllocator> *;
  using ConstRawPtr =
    const yasmin_msgs::msg::Transition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::Transition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::Transition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yasmin_msgs__msg__Transition
    std::shared_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yasmin_msgs__msg__Transition
    std::shared_ptr<yasmin_msgs::msg::Transition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Transition_ & other) const
  {
    if (this->outcome != other.outcome) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const Transition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Transition_

// alias to use template instance with default allocator
using Transition =
  yasmin_msgs::msg::Transition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_HPP_
