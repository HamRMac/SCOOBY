// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state.h"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_H_
#define YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'outcomes'
#include "rosidl_runtime_c/string.h"
// Member 'transitions'
#include "yasmin_msgs/msg/detail/transition__struct.h"

/// Struct defined in msg/State in the package yasmin_msgs.
typedef struct yasmin_msgs__msg__State
{
  int32_t id;
  int32_t parent;
  rosidl_runtime_c__String name;
  yasmin_msgs__msg__Transition__Sequence transitions;
  rosidl_runtime_c__String__Sequence outcomes;
  bool is_fsm;
  int32_t current_state;
} yasmin_msgs__msg__State;

// Struct for a sequence of yasmin_msgs__msg__State.
typedef struct yasmin_msgs__msg__State__Sequence
{
  yasmin_msgs__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yasmin_msgs__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE__STRUCT_H_
