// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice
#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "yasmin_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yasmin_msgs/msg/detail/state_machine__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_serialize_yasmin_msgs__msg__StateMachine(
  const yasmin_msgs__msg__StateMachine * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_deserialize_yasmin_msgs__msg__StateMachine(
  eprosima::fastcdr::Cdr &,
  yasmin_msgs__msg__StateMachine * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t get_serialized_size_yasmin_msgs__msg__StateMachine(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t max_serialized_size_yasmin_msgs__msg__StateMachine(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_serialize_key_yasmin_msgs__msg__StateMachine(
  const yasmin_msgs__msg__StateMachine * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t get_serialized_size_key_yasmin_msgs__msg__StateMachine(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t max_serialized_size_key_yasmin_msgs__msg__StateMachine(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yasmin_msgs, msg, StateMachine)();

#ifdef __cplusplus
}
#endif

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
