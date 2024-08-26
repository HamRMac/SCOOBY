// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice
#include "yasmin_msgs/msg/detail/transition__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yasmin_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yasmin_msgs/msg/detail/transition__struct.h"
#include "yasmin_msgs/msg/detail/transition__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // outcome, state
#include "rosidl_runtime_c/string_functions.h"  // outcome, state

// forward declare type support functions


using _Transition__ros_msg_type = yasmin_msgs__msg__Transition;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_serialize_yasmin_msgs__msg__Transition(
  const yasmin_msgs__msg__Transition * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: outcome
  {
    const rosidl_runtime_c__String * str = &ros_message->outcome;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: state
  {
    const rosidl_runtime_c__String * str = &ros_message->state;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_deserialize_yasmin_msgs__msg__Transition(
  eprosima::fastcdr::Cdr & cdr,
  yasmin_msgs__msg__Transition * ros_message)
{
  // Field name: outcome
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->outcome.data) {
      rosidl_runtime_c__String__init(&ros_message->outcome);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->outcome,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'outcome'\n");
      return false;
    }
  }

  // Field name: state
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->state.data) {
      rosidl_runtime_c__String__init(&ros_message->state);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->state,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'state'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t get_serialized_size_yasmin_msgs__msg__Transition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Transition__ros_msg_type * ros_message = static_cast<const _Transition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: outcome
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->outcome.size + 1);

  // Field name: state
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->state.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t max_serialized_size_yasmin_msgs__msg__Transition(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: outcome
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yasmin_msgs__msg__Transition;
    is_plain =
      (
      offsetof(DataType, state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
bool cdr_serialize_key_yasmin_msgs__msg__Transition(
  const yasmin_msgs__msg__Transition * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: outcome
  {
    const rosidl_runtime_c__String * str = &ros_message->outcome;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: state
  {
    const rosidl_runtime_c__String * str = &ros_message->state;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t get_serialized_size_key_yasmin_msgs__msg__Transition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Transition__ros_msg_type * ros_message = static_cast<const _Transition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: outcome
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->outcome.size + 1);

  // Field name: state
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->state.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yasmin_msgs
size_t max_serialized_size_key_yasmin_msgs__msg__Transition(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: outcome
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yasmin_msgs__msg__Transition;
    is_plain =
      (
      offsetof(DataType, state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Transition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const yasmin_msgs__msg__Transition * ros_message = static_cast<const yasmin_msgs__msg__Transition *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_yasmin_msgs__msg__Transition(ros_message, cdr);
}

static bool _Transition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  yasmin_msgs__msg__Transition * ros_message = static_cast<yasmin_msgs__msg__Transition *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_yasmin_msgs__msg__Transition(cdr, ros_message);
}

static uint32_t _Transition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yasmin_msgs__msg__Transition(
      untyped_ros_message, 0));
}

static size_t _Transition__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yasmin_msgs__msg__Transition(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Transition = {
  "yasmin_msgs::msg",
  "Transition",
  _Transition__cdr_serialize,
  _Transition__cdr_deserialize,
  _Transition__get_serialized_size,
  _Transition__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Transition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Transition,
  get_message_typesupport_handle_function,
  &yasmin_msgs__msg__Transition__get_type_hash,
  &yasmin_msgs__msg__Transition__get_type_description,
  &yasmin_msgs__msg__Transition__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yasmin_msgs, msg, Transition)() {
  return &_Transition__type_support;
}

#if defined(__cplusplus)
}
#endif
