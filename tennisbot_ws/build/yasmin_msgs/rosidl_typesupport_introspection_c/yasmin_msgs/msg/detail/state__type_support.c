// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yasmin_msgs/msg/detail/state__rosidl_typesupport_introspection_c.h"
#include "yasmin_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yasmin_msgs/msg/detail/state__functions.h"
#include "yasmin_msgs/msg/detail/state__struct.h"


// Include directives for member types
// Member `name`
// Member `outcomes`
#include "rosidl_runtime_c/string_functions.h"
// Member `transitions`
#include "yasmin_msgs/msg/transition.h"
// Member `transitions`
#include "yasmin_msgs/msg/detail/transition__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yasmin_msgs__msg__State__init(message_memory);
}

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_fini_function(void * message_memory)
{
  yasmin_msgs__msg__State__fini(message_memory);
}

size_t yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__size_function__State__transitions(
  const void * untyped_member)
{
  const yasmin_msgs__msg__Transition__Sequence * member =
    (const yasmin_msgs__msg__Transition__Sequence *)(untyped_member);
  return member->size;
}

const void * yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__transitions(
  const void * untyped_member, size_t index)
{
  const yasmin_msgs__msg__Transition__Sequence * member =
    (const yasmin_msgs__msg__Transition__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__transitions(
  void * untyped_member, size_t index)
{
  yasmin_msgs__msg__Transition__Sequence * member =
    (yasmin_msgs__msg__Transition__Sequence *)(untyped_member);
  return &member->data[index];
}

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__fetch_function__State__transitions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const yasmin_msgs__msg__Transition * item =
    ((const yasmin_msgs__msg__Transition *)
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__transitions(untyped_member, index));
  yasmin_msgs__msg__Transition * value =
    (yasmin_msgs__msg__Transition *)(untyped_value);
  *value = *item;
}

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__assign_function__State__transitions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  yasmin_msgs__msg__Transition * item =
    ((yasmin_msgs__msg__Transition *)
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__transitions(untyped_member, index));
  const yasmin_msgs__msg__Transition * value =
    (const yasmin_msgs__msg__Transition *)(untyped_value);
  *item = *value;
}

bool yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__resize_function__State__transitions(
  void * untyped_member, size_t size)
{
  yasmin_msgs__msg__Transition__Sequence * member =
    (yasmin_msgs__msg__Transition__Sequence *)(untyped_member);
  yasmin_msgs__msg__Transition__Sequence__fini(member);
  return yasmin_msgs__msg__Transition__Sequence__init(member, size);
}

size_t yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__size_function__State__outcomes(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__outcomes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__outcomes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__fetch_function__State__outcomes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__outcomes(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__assign_function__State__outcomes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__outcomes(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__resize_function__State__outcomes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_member_array[7] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "parent",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, parent),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "transitions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, transitions),  // bytes offset in struct
    NULL,  // default value
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__size_function__State__transitions,  // size() function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__transitions,  // get_const(index) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__transitions,  // get(index) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__fetch_function__State__transitions,  // fetch(index, &value) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__assign_function__State__transitions,  // assign(index, value) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__resize_function__State__transitions  // resize(index) function pointer
  },
  {
    "outcomes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, outcomes),  // bytes offset in struct
    NULL,  // default value
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__size_function__State__outcomes,  // size() function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_const_function__State__outcomes,  // get_const(index) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__get_function__State__outcomes,  // get(index) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__fetch_function__State__outcomes,  // fetch(index, &value) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__assign_function__State__outcomes,  // assign(index, value) function pointer
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__resize_function__State__outcomes  // resize(index) function pointer
  },
  {
    "is_fsm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, is_fsm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__State, current_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_members = {
  "yasmin_msgs__msg",  // message namespace
  "State",  // message name
  7,  // number of fields
  sizeof(yasmin_msgs__msg__State),
  false,  // has_any_key_member_
  yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_member_array,  // message members
  yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_init_function,  // function to initialize message memory (memory has to be allocated)
  yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle = {
  0,
  &yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_members,
  get_message_typesupport_handle_function,
  &yasmin_msgs__msg__State__get_type_hash,
  &yasmin_msgs__msg__State__get_type_description,
  &yasmin_msgs__msg__State__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yasmin_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yasmin_msgs, msg, State)() {
  yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yasmin_msgs, msg, Transition)();
  if (!yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle.typesupport_identifier) {
    yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yasmin_msgs__msg__State__rosidl_typesupport_introspection_c__State_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
