// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yasmin_msgs/msg/detail/state_machine__rosidl_typesupport_introspection_c.h"
#include "yasmin_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yasmin_msgs/msg/detail/state_machine__functions.h"
#include "yasmin_msgs/msg/detail/state_machine__struct.h"


// Include directives for member types
// Member `states`
#include "yasmin_msgs/msg/state.h"
// Member `states`
#include "yasmin_msgs/msg/detail/state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yasmin_msgs__msg__StateMachine__init(message_memory);
}

void yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_fini_function(void * message_memory)
{
  yasmin_msgs__msg__StateMachine__fini(message_memory);
}

size_t yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__size_function__StateMachine__states(
  const void * untyped_member)
{
  const yasmin_msgs__msg__State__Sequence * member =
    (const yasmin_msgs__msg__State__Sequence *)(untyped_member);
  return member->size;
}

const void * yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_const_function__StateMachine__states(
  const void * untyped_member, size_t index)
{
  const yasmin_msgs__msg__State__Sequence * member =
    (const yasmin_msgs__msg__State__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_function__StateMachine__states(
  void * untyped_member, size_t index)
{
  yasmin_msgs__msg__State__Sequence * member =
    (yasmin_msgs__msg__State__Sequence *)(untyped_member);
  return &member->data[index];
}

void yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__fetch_function__StateMachine__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const yasmin_msgs__msg__State * item =
    ((const yasmin_msgs__msg__State *)
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_const_function__StateMachine__states(untyped_member, index));
  yasmin_msgs__msg__State * value =
    (yasmin_msgs__msg__State *)(untyped_value);
  *value = *item;
}

void yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__assign_function__StateMachine__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  yasmin_msgs__msg__State * item =
    ((yasmin_msgs__msg__State *)
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_function__StateMachine__states(untyped_member, index));
  const yasmin_msgs__msg__State * value =
    (const yasmin_msgs__msg__State *)(untyped_value);
  *item = *value;
}

bool yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__resize_function__StateMachine__states(
  void * untyped_member, size_t size)
{
  yasmin_msgs__msg__State__Sequence * member =
    (yasmin_msgs__msg__State__Sequence *)(untyped_member);
  yasmin_msgs__msg__State__Sequence__fini(member);
  return yasmin_msgs__msg__State__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_member_array[1] = {
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yasmin_msgs__msg__StateMachine, states),  // bytes offset in struct
    NULL,  // default value
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__size_function__StateMachine__states,  // size() function pointer
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_const_function__StateMachine__states,  // get_const(index) function pointer
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__get_function__StateMachine__states,  // get(index) function pointer
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__fetch_function__StateMachine__states,  // fetch(index, &value) function pointer
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__assign_function__StateMachine__states,  // assign(index, value) function pointer
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__resize_function__StateMachine__states  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_members = {
  "yasmin_msgs__msg",  // message namespace
  "StateMachine",  // message name
  1,  // number of fields
  sizeof(yasmin_msgs__msg__StateMachine),
  false,  // has_any_key_member_
  yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_member_array,  // message members
  yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_init_function,  // function to initialize message memory (memory has to be allocated)
  yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_type_support_handle = {
  0,
  &yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_members,
  get_message_typesupport_handle_function,
  &yasmin_msgs__msg__StateMachine__get_type_hash,
  &yasmin_msgs__msg__StateMachine__get_type_description,
  &yasmin_msgs__msg__StateMachine__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yasmin_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yasmin_msgs, msg, StateMachine)() {
  yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yasmin_msgs, msg, State)();
  if (!yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_type_support_handle.typesupport_identifier) {
    yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yasmin_msgs__msg__StateMachine__rosidl_typesupport_introspection_c__StateMachine_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
