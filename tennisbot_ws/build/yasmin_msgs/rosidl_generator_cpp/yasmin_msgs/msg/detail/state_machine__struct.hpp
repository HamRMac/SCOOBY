// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state_machine.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'states'
#include "yasmin_msgs/msg/detail/state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yasmin_msgs__msg__StateMachine __attribute__((deprecated))
#else
# define DEPRECATED__yasmin_msgs__msg__StateMachine __declspec(deprecated)
#endif

namespace yasmin_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StateMachine_
{
  using Type = StateMachine_<ContainerAllocator>;

  explicit StateMachine_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit StateMachine_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _states_type =
    std::vector<yasmin_msgs::msg::State_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yasmin_msgs::msg::State_<ContainerAllocator>>>;
  _states_type states;

  // setters for named parameter idiom
  Type & set__states(
    const std::vector<yasmin_msgs::msg::State_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yasmin_msgs::msg::State_<ContainerAllocator>>> & _arg)
  {
    this->states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yasmin_msgs::msg::StateMachine_<ContainerAllocator> *;
  using ConstRawPtr =
    const yasmin_msgs::msg::StateMachine_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::StateMachine_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::StateMachine_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yasmin_msgs__msg__StateMachine
    std::shared_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yasmin_msgs__msg__StateMachine
    std::shared_ptr<yasmin_msgs::msg::StateMachine_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateMachine_ & other) const
  {
    if (this->states != other.states) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateMachine_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateMachine_

// alias to use template instance with default allocator
using StateMachine =
  yasmin_msgs::msg::StateMachine_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
