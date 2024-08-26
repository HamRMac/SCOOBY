// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state_machine.h"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'states'
#include "yasmin_msgs/msg/detail/state__struct.h"

/// Struct defined in msg/StateMachine in the package yasmin_msgs.
typedef struct yasmin_msgs__msg__StateMachine
{
  yasmin_msgs__msg__State__Sequence states;
} yasmin_msgs__msg__StateMachine;

// Struct for a sequence of yasmin_msgs__msg__StateMachine.
typedef struct yasmin_msgs__msg__StateMachine__Sequence
{
  yasmin_msgs__msg__StateMachine * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yasmin_msgs__msg__StateMachine__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
