// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yasmin_msgs:msg/State.idl
// generated code does not contain a copyright notice
#include "yasmin_msgs/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `outcomes`
#include "rosidl_runtime_c/string_functions.h"
// Member `transitions`
#include "yasmin_msgs/msg/detail/transition__functions.h"

bool
yasmin_msgs__msg__State__init(yasmin_msgs__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // parent
  msg->parent = -1l;
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    yasmin_msgs__msg__State__fini(msg);
    return false;
  }
  // transitions
  if (!yasmin_msgs__msg__Transition__Sequence__init(&msg->transitions, 0)) {
    yasmin_msgs__msg__State__fini(msg);
    return false;
  }
  // outcomes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->outcomes, 0)) {
    yasmin_msgs__msg__State__fini(msg);
    return false;
  }
  // is_fsm
  // current_state
  msg->current_state = -1l;
  return true;
}

void
yasmin_msgs__msg__State__fini(yasmin_msgs__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // id
  // parent
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // transitions
  yasmin_msgs__msg__Transition__Sequence__fini(&msg->transitions);
  // outcomes
  rosidl_runtime_c__String__Sequence__fini(&msg->outcomes);
  // is_fsm
  // current_state
}

bool
yasmin_msgs__msg__State__are_equal(const yasmin_msgs__msg__State * lhs, const yasmin_msgs__msg__State * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // parent
  if (lhs->parent != rhs->parent) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // transitions
  if (!yasmin_msgs__msg__Transition__Sequence__are_equal(
      &(lhs->transitions), &(rhs->transitions)))
  {
    return false;
  }
  // outcomes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->outcomes), &(rhs->outcomes)))
  {
    return false;
  }
  // is_fsm
  if (lhs->is_fsm != rhs->is_fsm) {
    return false;
  }
  // current_state
  if (lhs->current_state != rhs->current_state) {
    return false;
  }
  return true;
}

bool
yasmin_msgs__msg__State__copy(
  const yasmin_msgs__msg__State * input,
  yasmin_msgs__msg__State * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // parent
  output->parent = input->parent;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // transitions
  if (!yasmin_msgs__msg__Transition__Sequence__copy(
      &(input->transitions), &(output->transitions)))
  {
    return false;
  }
  // outcomes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->outcomes), &(output->outcomes)))
  {
    return false;
  }
  // is_fsm
  output->is_fsm = input->is_fsm;
  // current_state
  output->current_state = input->current_state;
  return true;
}

yasmin_msgs__msg__State *
yasmin_msgs__msg__State__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__State * msg = (yasmin_msgs__msg__State *)allocator.allocate(sizeof(yasmin_msgs__msg__State), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yasmin_msgs__msg__State));
  bool success = yasmin_msgs__msg__State__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yasmin_msgs__msg__State__destroy(yasmin_msgs__msg__State * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yasmin_msgs__msg__State__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yasmin_msgs__msg__State__Sequence__init(yasmin_msgs__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__State * data = NULL;

  if (size) {
    data = (yasmin_msgs__msg__State *)allocator.zero_allocate(size, sizeof(yasmin_msgs__msg__State), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yasmin_msgs__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yasmin_msgs__msg__State__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yasmin_msgs__msg__State__Sequence__fini(yasmin_msgs__msg__State__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yasmin_msgs__msg__State__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yasmin_msgs__msg__State__Sequence *
yasmin_msgs__msg__State__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__State__Sequence * array = (yasmin_msgs__msg__State__Sequence *)allocator.allocate(sizeof(yasmin_msgs__msg__State__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yasmin_msgs__msg__State__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yasmin_msgs__msg__State__Sequence__destroy(yasmin_msgs__msg__State__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yasmin_msgs__msg__State__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yasmin_msgs__msg__State__Sequence__are_equal(const yasmin_msgs__msg__State__Sequence * lhs, const yasmin_msgs__msg__State__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yasmin_msgs__msg__State__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yasmin_msgs__msg__State__Sequence__copy(
  const yasmin_msgs__msg__State__Sequence * input,
  yasmin_msgs__msg__State__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yasmin_msgs__msg__State);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yasmin_msgs__msg__State * data =
      (yasmin_msgs__msg__State *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yasmin_msgs__msg__State__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yasmin_msgs__msg__State__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yasmin_msgs__msg__State__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
