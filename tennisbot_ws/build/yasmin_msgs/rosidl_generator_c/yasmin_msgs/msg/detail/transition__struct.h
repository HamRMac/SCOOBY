// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/transition.h"


#ifndef YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_H_
#define YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'outcome'
// Member 'state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Transition in the package yasmin_msgs.
typedef struct yasmin_msgs__msg__Transition
{
  rosidl_runtime_c__String outcome;
  rosidl_runtime_c__String state;
} yasmin_msgs__msg__Transition;

// Struct for a sequence of yasmin_msgs__msg__Transition.
typedef struct yasmin_msgs__msg__Transition__Sequence
{
  yasmin_msgs__msg__Transition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yasmin_msgs__msg__Transition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YASMIN_MSGS__MSG__DETAIL__TRANSITION__STRUCT_H_
