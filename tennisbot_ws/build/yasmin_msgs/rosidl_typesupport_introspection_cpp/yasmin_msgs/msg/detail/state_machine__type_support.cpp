// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yasmin_msgs/msg/detail/state_machine__functions.h"
#include "yasmin_msgs/msg/detail/state_machine__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yasmin_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StateMachine_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yasmin_msgs::msg::StateMachine(_init);
}

void StateMachine_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yasmin_msgs::msg::StateMachine *>(message_memory);
  typed_message->~StateMachine();
}

size_t size_function__StateMachine__states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<yasmin_msgs::msg::State> *>(untyped_member);
  return member->size();
}

const void * get_const_function__StateMachine__states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<yasmin_msgs::msg::State> *>(untyped_member);
  return &member[index];
}

void * get_function__StateMachine__states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<yasmin_msgs::msg::State> *>(untyped_member);
  return &member[index];
}

void fetch_function__StateMachine__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const yasmin_msgs::msg::State *>(
    get_const_function__StateMachine__states(untyped_member, index));
  auto & value = *reinterpret_cast<yasmin_msgs::msg::State *>(untyped_value);
  value = item;
}

void assign_function__StateMachine__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<yasmin_msgs::msg::State *>(
    get_function__StateMachine__states(untyped_member, index));
  const auto & value = *reinterpret_cast<const yasmin_msgs::msg::State *>(untyped_value);
  item = value;
}

void resize_function__StateMachine__states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<yasmin_msgs::msg::State> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StateMachine_message_member_array[1] = {
  {
    "states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<yasmin_msgs::msg::State>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs::msg::StateMachine, states),  // bytes offset in struct
    nullptr,  // default value
    size_function__StateMachine__states,  // size() function pointer
    get_const_function__StateMachine__states,  // get_const(index) function pointer
    get_function__StateMachine__states,  // get(index) function pointer
    fetch_function__StateMachine__states,  // fetch(index, &value) function pointer
    assign_function__StateMachine__states,  // assign(index, value) function pointer
    resize_function__StateMachine__states  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StateMachine_message_members = {
  "yasmin_msgs::msg",  // message namespace
  "StateMachine",  // message name
  1,  // number of fields
  sizeof(yasmin_msgs::msg::StateMachine),
  false,  // has_any_key_member_
  StateMachine_message_member_array,  // message members
  StateMachine_init_function,  // function to initialize message memory (memory has to be allocated)
  StateMachine_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StateMachine_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StateMachine_message_members,
  get_message_typesupport_handle_function,
  &yasmin_msgs__msg__StateMachine__get_type_hash,
  &yasmin_msgs__msg__StateMachine__get_type_description,
  &yasmin_msgs__msg__StateMachine__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace yasmin_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yasmin_msgs::msg::StateMachine>()
{
  return &::yasmin_msgs::msg::rosidl_typesupport_introspection_cpp::StateMachine_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yasmin_msgs, msg, StateMachine)() {
  return &::yasmin_msgs::msg::rosidl_typesupport_introspection_cpp::StateMachine_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
