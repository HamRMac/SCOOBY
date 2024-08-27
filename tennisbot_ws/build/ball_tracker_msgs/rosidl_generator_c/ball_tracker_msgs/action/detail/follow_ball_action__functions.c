// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ball_tracker_msgs:action/FollowBallAction.idl
// generated code does not contain a copyright notice
#include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ball_tracker_msgs__action__FollowBallAction_Goal__init(ball_tracker_msgs__action__FollowBallAction_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // timeout
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_Goal__fini(ball_tracker_msgs__action__FollowBallAction_Goal * msg)
{
  if (!msg) {
    return;
  }
  // timeout
}

bool
ball_tracker_msgs__action__FollowBallAction_Goal__are_equal(const ball_tracker_msgs__action__FollowBallAction_Goal * lhs, const ball_tracker_msgs__action__FollowBallAction_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timeout
  if (lhs->timeout != rhs->timeout) {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Goal__copy(
  const ball_tracker_msgs__action__FollowBallAction_Goal * input,
  ball_tracker_msgs__action__FollowBallAction_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // timeout
  output->timeout = input->timeout;
  return true;
}

ball_tracker_msgs__action__FollowBallAction_Goal *
ball_tracker_msgs__action__FollowBallAction_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Goal * msg = (ball_tracker_msgs__action__FollowBallAction_Goal *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_Goal));
  bool success = ball_tracker_msgs__action__FollowBallAction_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_Goal__destroy(ball_tracker_msgs__action__FollowBallAction_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__init(ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Goal * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_Goal *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_Goal__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_Goal__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_Goal__Sequence *
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_Goal__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Goal__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_Goal * data =
      (ball_tracker_msgs__action__FollowBallAction_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ball_tracker_msgs__action__FollowBallAction_Result__init(ball_tracker_msgs__action__FollowBallAction_Result * msg)
{
  if (!msg) {
    return false;
  }
  // current_distance
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_Result__fini(ball_tracker_msgs__action__FollowBallAction_Result * msg)
{
  if (!msg) {
    return;
  }
  // current_distance
}

bool
ball_tracker_msgs__action__FollowBallAction_Result__are_equal(const ball_tracker_msgs__action__FollowBallAction_Result * lhs, const ball_tracker_msgs__action__FollowBallAction_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_distance
  if (lhs->current_distance != rhs->current_distance) {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Result__copy(
  const ball_tracker_msgs__action__FollowBallAction_Result * input,
  ball_tracker_msgs__action__FollowBallAction_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // current_distance
  output->current_distance = input->current_distance;
  return true;
}

ball_tracker_msgs__action__FollowBallAction_Result *
ball_tracker_msgs__action__FollowBallAction_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Result * msg = (ball_tracker_msgs__action__FollowBallAction_Result *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_Result));
  bool success = ball_tracker_msgs__action__FollowBallAction_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_Result__destroy(ball_tracker_msgs__action__FollowBallAction_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__init(ball_tracker_msgs__action__FollowBallAction_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Result * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_Result *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_Result__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_Result__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_Result__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_Result__Sequence *
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Result__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_Result__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_Result__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Result__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_Result__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_Result * data =
      (ball_tracker_msgs__action__FollowBallAction_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ball_tracker_msgs__action__FollowBallAction_Feedback__init(ball_tracker_msgs__action__FollowBallAction_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_Feedback__fini(ball_tracker_msgs__action__FollowBallAction_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
ball_tracker_msgs__action__FollowBallAction_Feedback__are_equal(const ball_tracker_msgs__action__FollowBallAction_Feedback * lhs, const ball_tracker_msgs__action__FollowBallAction_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Feedback__copy(
  const ball_tracker_msgs__action__FollowBallAction_Feedback * input,
  ball_tracker_msgs__action__FollowBallAction_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

ball_tracker_msgs__action__FollowBallAction_Feedback *
ball_tracker_msgs__action__FollowBallAction_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Feedback * msg = (ball_tracker_msgs__action__FollowBallAction_Feedback *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_Feedback));
  bool success = ball_tracker_msgs__action__FollowBallAction_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_Feedback__destroy(ball_tracker_msgs__action__FollowBallAction_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__init(ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Feedback * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_Feedback *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_Feedback__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_Feedback__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence *
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_Feedback * data =
      (ball_tracker_msgs__action__FollowBallAction_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!ball_tracker_msgs__action__FollowBallAction_Goal__init(&msg->goal)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  ball_tracker_msgs__action__FollowBallAction_Goal__fini(&msg->goal);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!ball_tracker_msgs__action__FollowBallAction_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!ball_tracker_msgs__action__FollowBallAction_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_SendGoal_Request *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * msg = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Request *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request));
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Request *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * data =
      (ball_tracker_msgs__action__FollowBallAction_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_SendGoal_Response *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * msg = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Response *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response));
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Response *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * data =
      (ball_tracker_msgs__action__FollowBallAction_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_SendGoal_Event *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * msg = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Event *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event));
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__init(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Event *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence *
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * data =
      (ball_tracker_msgs__action__FollowBallAction_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Request * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Request * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_GetResult_Request *
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request * msg = (ball_tracker_msgs__action__FollowBallAction_GetResult_Request *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Request));
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_GetResult_Request *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence *
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_GetResult_Request * data =
      (ball_tracker_msgs__action__FollowBallAction_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!ball_tracker_msgs__action__FollowBallAction_Result__init(&msg->result)) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  ball_tracker_msgs__action__FollowBallAction_Result__fini(&msg->result);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Response * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!ball_tracker_msgs__action__FollowBallAction_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Response * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!ball_tracker_msgs__action__FollowBallAction_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_GetResult_Response *
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response * msg = (ball_tracker_msgs__action__FollowBallAction_GetResult_Response *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Response));
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_GetResult_Response *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence *
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_GetResult_Response * data =
      (ball_tracker_msgs__action__FollowBallAction_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__init(&msg->request, 0)) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__init(&msg->response, 0)) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__fini(&msg->request);
  // response
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__fini(&msg->response);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Event * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Event * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_GetResult_Event *
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event * msg = (ball_tracker_msgs__action__FollowBallAction_GetResult_Event *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Event));
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__init(ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_GetResult_Event *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence *
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_GetResult_Event * data =
      (ball_tracker_msgs__action__FollowBallAction_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__functions.h"

bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__init(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!ball_tracker_msgs__action__FollowBallAction_Feedback__init(&msg->feedback)) {
    ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  ball_tracker_msgs__action__FollowBallAction_Feedback__fini(&msg->feedback);
}

bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__are_equal(const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * lhs, const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!ball_tracker_msgs__action__FollowBallAction_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__copy(
  const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * input,
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!ball_tracker_msgs__action__FollowBallAction_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

ball_tracker_msgs__action__FollowBallAction_FeedbackMessage *
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * msg = (ball_tracker_msgs__action__FollowBallAction_FeedbackMessage *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage));
  bool success = ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__destroy(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__init(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * data = NULL;

  if (size) {
    data = (ball_tracker_msgs__action__FollowBallAction_FeedbackMessage *)allocator.zero_allocate(size, sizeof(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(&data[i - 1]);
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
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__fini(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * array)
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
      ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(&array->data[i]);
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

ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence *
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * array = (ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence *)allocator.allocate(sizeof(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__destroy(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__are_equal(const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * lhs, const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence__copy(
  const ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * input,
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_tracker_msgs__action__FollowBallAction_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * data =
      (ball_tracker_msgs__action__FollowBallAction_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
