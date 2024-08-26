// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state.hpp"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_
#define YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'transitions'
#include "yasmin_msgs/msg/detail/transition__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yasmin_msgs__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__yasmin_msgs__msg__State __declspec(deprecated)
#endif

namespace yasmin_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->parent = -1l;
      this->current_state = -1l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->id = 0l;
      this->parent = 0l;
      this->name = "";
      this->is_fsm = false;
      this->current_state = 0l;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->is_fsm = false;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->parent = -1l;
      this->current_state = -1l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->id = 0l;
      this->parent = 0l;
      this->name = "";
      this->is_fsm = false;
      this->current_state = 0l;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->is_fsm = false;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _parent_type =
    int32_t;
  _parent_type parent;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _transitions_type =
    std::vector<yasmin_msgs::msg::Transition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yasmin_msgs::msg::Transition_<ContainerAllocator>>>;
  _transitions_type transitions;
  using _outcomes_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _outcomes_type outcomes;
  using _is_fsm_type =
    bool;
  _is_fsm_type is_fsm;
  using _current_state_type =
    int32_t;
  _current_state_type current_state;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__parent(
    const int32_t & _arg)
  {
    this->parent = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__transitions(
    const std::vector<yasmin_msgs::msg::Transition_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<yasmin_msgs::msg::Transition_<ContainerAllocator>>> & _arg)
  {
    this->transitions = _arg;
    return *this;
  }
  Type & set__outcomes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->outcomes = _arg;
    return *this;
  }
  Type & set__is_fsm(
    const bool & _arg)
  {
    this->is_fsm = _arg;
    return *this;
  }
  Type & set__current_state(
    const int32_t & _arg)
  {
    this->current_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yasmin_msgs::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const yasmin_msgs::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yasmin_msgs::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yasmin_msgs::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yasmin_msgs::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yasmin_msgs::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yasmin_msgs::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yasmin_msgs::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yasmin_msgs__msg__State
    std::shared_ptr<yasmin_msgs::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yasmin_msgs__msg__State
    std::shared_ptr<yasmin_msgs::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->parent != other.parent) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->transitions != other.transitions) {
      return false;
    }
    if (this->outcomes != other.outcomes) {
      return false;
    }
    if (this->is_fsm != other.is_fsm) {
      return false;
    }
    if (this->current_state != other.current_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  yasmin_msgs::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yasmin_msgs

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_HPP_
