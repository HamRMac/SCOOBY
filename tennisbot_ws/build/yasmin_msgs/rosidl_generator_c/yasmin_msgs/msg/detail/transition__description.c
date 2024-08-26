// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice

#include "yasmin_msgs/msg/detail/transition__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_type_hash_t *
yasmin_msgs__msg__Transition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa0, 0x19, 0x9d, 0x36, 0x27, 0xa1, 0x3b, 0xe5,
      0xc0, 0xfb, 0xfb, 0x9d, 0x15, 0x30, 0x85, 0x54,
      0x57, 0xd1, 0x90, 0x67, 0xa0, 0xf5, 0x17, 0x4b,
      0x99, 0xb9, 0xec, 0x91, 0x99, 0x70, 0x1a, 0x29,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char yasmin_msgs__msg__Transition__TYPE_NAME[] = "yasmin_msgs/msg/Transition";

// Define type names, field names, and default values
static char yasmin_msgs__msg__Transition__FIELD_NAME__outcome[] = "outcome";
static char yasmin_msgs__msg__Transition__FIELD_NAME__state[] = "state";

static rosidl_runtime_c__type_description__Field yasmin_msgs__msg__Transition__FIELDS[] = {
  {
    {yasmin_msgs__msg__Transition__FIELD_NAME__outcome, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {yasmin_msgs__msg__Transition__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
yasmin_msgs__msg__Transition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {yasmin_msgs__msg__Transition__TYPE_NAME, 26, 26},
      {yasmin_msgs__msg__Transition__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "\n"
  "string outcome\n"
  "string state";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
yasmin_msgs__msg__Transition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {yasmin_msgs__msg__Transition__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
yasmin_msgs__msg__Transition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *yasmin_msgs__msg__Transition__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
