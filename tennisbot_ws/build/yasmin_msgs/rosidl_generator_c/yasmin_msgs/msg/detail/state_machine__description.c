// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#include "yasmin_msgs/msg/detail/state_machine__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_type_hash_t *
yasmin_msgs__msg__StateMachine__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x22, 0x4c, 0x8e, 0x76, 0x65, 0x79, 0x98, 0x71,
      0x2d, 0xa5, 0xd9, 0xf7, 0xa2, 0x6a, 0x1b, 0x9d,
      0x61, 0x02, 0x8d, 0x26, 0x42, 0xf4, 0xea, 0x6f,
      0x98, 0x34, 0x35, 0x27, 0xb5, 0x5c, 0xd3, 0x86,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "yasmin_msgs/msg/detail/state__functions.h"
#include "yasmin_msgs/msg/detail/transition__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t yasmin_msgs__msg__State__EXPECTED_HASH = {1, {
    0x76, 0xa6, 0xee, 0x5d, 0x9e, 0x3d, 0x5e, 0x80,
    0xc8, 0x2f, 0xdd, 0x1b, 0xc4, 0xa4, 0x61, 0xb4,
    0x55, 0x85, 0x53, 0xcd, 0xf2, 0x96, 0x34, 0x39,
    0x60, 0xdd, 0xa7, 0x33, 0xb1, 0x17, 0xc7, 0x9f,
  }};
static const rosidl_type_hash_t yasmin_msgs__msg__Transition__EXPECTED_HASH = {1, {
    0xa0, 0x19, 0x9d, 0x36, 0x27, 0xa1, 0x3b, 0xe5,
    0xc0, 0xfb, 0xfb, 0x9d, 0x15, 0x30, 0x85, 0x54,
    0x57, 0xd1, 0x90, 0x67, 0xa0, 0xf5, 0x17, 0x4b,
    0x99, 0xb9, 0xec, 0x91, 0x99, 0x70, 0x1a, 0x29,
  }};
#endif

static char yasmin_msgs__msg__StateMachine__TYPE_NAME[] = "yasmin_msgs/msg/StateMachine";
static char yasmin_msgs__msg__State__TYPE_NAME[] = "yasmin_msgs/msg/State";
static char yasmin_msgs__msg__Transition__TYPE_NAME[] = "yasmin_msgs/msg/Transition";

// Define type names, field names, and default values
static char yasmin_msgs__msg__StateMachine__FIELD_NAME__states[] = "states";

static rosidl_runtime_c__type_description__Field yasmin_msgs__msg__StateMachine__FIELDS[] = {
  {
    {yasmin_msgs__msg__StateMachine__FIELD_NAME__states, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {yasmin_msgs__msg__State__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription yasmin_msgs__msg__StateMachine__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {yasmin_msgs__msg__State__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {yasmin_msgs__msg__Transition__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
yasmin_msgs__msg__StateMachine__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {yasmin_msgs__msg__StateMachine__TYPE_NAME, 28, 28},
      {yasmin_msgs__msg__StateMachine__FIELDS, 1, 1},
    },
    {yasmin_msgs__msg__StateMachine__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&yasmin_msgs__msg__State__EXPECTED_HASH, yasmin_msgs__msg__State__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = yasmin_msgs__msg__State__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&yasmin_msgs__msg__Transition__EXPECTED_HASH, yasmin_msgs__msg__Transition__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = yasmin_msgs__msg__Transition__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "\n"
  "yasmin_msgs/State[] states";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
yasmin_msgs__msg__StateMachine__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {yasmin_msgs__msg__StateMachine__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 28, 28},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
yasmin_msgs__msg__StateMachine__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *yasmin_msgs__msg__StateMachine__get_individual_type_description_source(NULL),
    sources[1] = *yasmin_msgs__msg__State__get_individual_type_description_source(NULL);
    sources[2] = *yasmin_msgs__msg__Transition__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
