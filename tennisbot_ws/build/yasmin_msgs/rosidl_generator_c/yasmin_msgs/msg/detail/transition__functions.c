// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yasmin_msgs:msg/Transition.idl
// generated code does not contain a copyright notice
#include "yasmin_msgs/msg/detail/transition__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `outcome`
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
yasmin_msgs__msg__Transition__init(yasmin_msgs__msg__Transition * msg)
{
  if (!msg) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__init(&msg->outcome)) {
    yasmin_msgs__msg__Transition__fini(msg);
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    yasmin_msgs__msg__Transition__fini(msg);
    return false;
  }
  return true;
}

void
yasmin_msgs__msg__Transition__fini(yasmin_msgs__msg__Transition * msg)
{
  if (!msg) {
    return;
  }
  // outcome
  rosidl_runtime_c__String__fini(&msg->outcome);
  // state
  rosidl_runtime_c__String__fini(&msg->state);
}

bool
yasmin_msgs__msg__Transition__are_equal(const yasmin_msgs__msg__Transition * lhs, const yasmin_msgs__msg__Transition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->outcome), &(rhs->outcome)))
  {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
yasmin_msgs__msg__Transition__copy(
  const yasmin_msgs__msg__Transition * input,
  yasmin_msgs__msg__Transition * output)
{
  if (!input || !output) {
    return false;
  }
  // outcome
  if (!rosidl_runtime_c__String__copy(
      &(input->outcome), &(output->outcome)))
  {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

yasmin_msgs__msg__Transition *
yasmin_msgs__msg__Transition__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__Transition * msg = (yasmin_msgs__msg__Transition *)allocator.allocate(sizeof(yasmin_msgs__msg__Transition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yasmin_msgs__msg__Transition));
  bool success = yasmin_msgs__msg__Transition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yasmin_msgs__msg__Transition__destroy(yasmin_msgs__msg__Transition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yasmin_msgs__msg__Transition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yasmin_msgs__msg__Transition__Sequence__init(yasmin_msgs__msg__Transition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__Transition * data = NULL;

  if (size) {
    data = (yasmin_msgs__msg__Transition *)allocator.zero_allocate(size, sizeof(yasmin_msgs__msg__Transition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yasmin_msgs__msg__Transition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yasmin_msgs__msg__Transition__fini(&data[i - 1]);
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
yasmin_msgs__msg__Transition__Sequence__fini(yasmin_msgs__msg__Transition__Sequence * array)
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
      yasmin_msgs__msg__Transition__fini(&array->data[i]);
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

yasmin_msgs__msg__Transition__Sequence *
yasmin_msgs__msg__Transition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__Transition__Sequence * array = (yasmin_msgs__msg__Transition__Sequence *)allocator.allocate(sizeof(yasmin_msgs__msg__Transition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yasmin_msgs__msg__Transition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yasmin_msgs__msg__Transition__Sequence__destroy(yasmin_msgs__msg__Transition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yasmin_msgs__msg__Transition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yasmin_msgs__msg__Transition__Sequence__are_equal(const yasmin_msgs__msg__Transition__Sequence * lhs, const yasmin_msgs__msg__Transition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yasmin_msgs__msg__Transition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yasmin_msgs__msg__Transition__Sequence__copy(
  const yasmin_msgs__msg__Transition__Sequence * input,
  yasmin_msgs__msg__Transition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yasmin_msgs__msg__Transition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yasmin_msgs__msg__Transition * data =
      (yasmin_msgs__msg__Transition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yasmin_msgs__msg__Transition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yasmin_msgs__msg__Transition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yasmin_msgs__msg__Transition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
