// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice
#include "yasmin_msgs/msg/detail/state_machine__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `states`
#include "yasmin_msgs/msg/detail/state__functions.h"

bool
yasmin_msgs__msg__StateMachine__init(yasmin_msgs__msg__StateMachine * msg)
{
  if (!msg) {
    return false;
  }
  // states
  if (!yasmin_msgs__msg__State__Sequence__init(&msg->states, 0)) {
    yasmin_msgs__msg__StateMachine__fini(msg);
    return false;
  }
  return true;
}

void
yasmin_msgs__msg__StateMachine__fini(yasmin_msgs__msg__StateMachine * msg)
{
  if (!msg) {
    return;
  }
  // states
  yasmin_msgs__msg__State__Sequence__fini(&msg->states);
}

bool
yasmin_msgs__msg__StateMachine__are_equal(const yasmin_msgs__msg__StateMachine * lhs, const yasmin_msgs__msg__StateMachine * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // states
  if (!yasmin_msgs__msg__State__Sequence__are_equal(
      &(lhs->states), &(rhs->states)))
  {
    return false;
  }
  return true;
}

bool
yasmin_msgs__msg__StateMachine__copy(
  const yasmin_msgs__msg__StateMachine * input,
  yasmin_msgs__msg__StateMachine * output)
{
  if (!input || !output) {
    return false;
  }
  // states
  if (!yasmin_msgs__msg__State__Sequence__copy(
      &(input->states), &(output->states)))
  {
    return false;
  }
  return true;
}

yasmin_msgs__msg__StateMachine *
yasmin_msgs__msg__StateMachine__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__StateMachine * msg = (yasmin_msgs__msg__StateMachine *)allocator.allocate(sizeof(yasmin_msgs__msg__StateMachine), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yasmin_msgs__msg__StateMachine));
  bool success = yasmin_msgs__msg__StateMachine__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yasmin_msgs__msg__StateMachine__destroy(yasmin_msgs__msg__StateMachine * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yasmin_msgs__msg__StateMachine__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yasmin_msgs__msg__StateMachine__Sequence__init(yasmin_msgs__msg__StateMachine__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__StateMachine * data = NULL;

  if (size) {
    data = (yasmin_msgs__msg__StateMachine *)allocator.zero_allocate(size, sizeof(yasmin_msgs__msg__StateMachine), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yasmin_msgs__msg__StateMachine__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yasmin_msgs__msg__StateMachine__fini(&data[i - 1]);
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
yasmin_msgs__msg__StateMachine__Sequence__fini(yasmin_msgs__msg__StateMachine__Sequence * array)
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
      yasmin_msgs__msg__StateMachine__fini(&array->data[i]);
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

yasmin_msgs__msg__StateMachine__Sequence *
yasmin_msgs__msg__StateMachine__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yasmin_msgs__msg__StateMachine__Sequence * array = (yasmin_msgs__msg__StateMachine__Sequence *)allocator.allocate(sizeof(yasmin_msgs__msg__StateMachine__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yasmin_msgs__msg__StateMachine__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yasmin_msgs__msg__StateMachine__Sequence__destroy(yasmin_msgs__msg__StateMachine__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yasmin_msgs__msg__StateMachine__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yasmin_msgs__msg__StateMachine__Sequence__are_equal(const yasmin_msgs__msg__StateMachine__Sequence * lhs, const yasmin_msgs__msg__StateMachine__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yasmin_msgs__msg__StateMachine__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yasmin_msgs__msg__StateMachine__Sequence__copy(
  const yasmin_msgs__msg__StateMachine__Sequence * input,
  yasmin_msgs__msg__StateMachine__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yasmin_msgs__msg__StateMachine);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yasmin_msgs__msg__StateMachine * data =
      (yasmin_msgs__msg__StateMachine *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yasmin_msgs__msg__StateMachine__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yasmin_msgs__msg__StateMachine__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yasmin_msgs__msg__StateMachine__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
