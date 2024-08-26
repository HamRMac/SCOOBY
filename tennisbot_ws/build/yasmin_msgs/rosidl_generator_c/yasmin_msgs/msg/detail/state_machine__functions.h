// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from yasmin_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yasmin_msgs/msg/state_machine.h"


#ifndef YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__FUNCTIONS_H_
#define YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "yasmin_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "yasmin_msgs/msg/detail/state_machine__struct.h"

/// Initialize msg/StateMachine message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * yasmin_msgs__msg__StateMachine
 * )) before or use
 * yasmin_msgs__msg__StateMachine__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__init(yasmin_msgs__msg__StateMachine * msg);

/// Finalize msg/StateMachine message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
void
yasmin_msgs__msg__StateMachine__fini(yasmin_msgs__msg__StateMachine * msg);

/// Create msg/StateMachine message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * yasmin_msgs__msg__StateMachine__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
yasmin_msgs__msg__StateMachine *
yasmin_msgs__msg__StateMachine__create(void);

/// Destroy msg/StateMachine message.
/**
 * It calls
 * yasmin_msgs__msg__StateMachine__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
void
yasmin_msgs__msg__StateMachine__destroy(yasmin_msgs__msg__StateMachine * msg);

/// Check for msg/StateMachine message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__are_equal(const yasmin_msgs__msg__StateMachine * lhs, const yasmin_msgs__msg__StateMachine * rhs);

/// Copy a msg/StateMachine message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__copy(
  const yasmin_msgs__msg__StateMachine * input,
  yasmin_msgs__msg__StateMachine * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_type_hash_t *
yasmin_msgs__msg__StateMachine__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_runtime_c__type_description__TypeDescription *
yasmin_msgs__msg__StateMachine__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_runtime_c__type_description__TypeSource *
yasmin_msgs__msg__StateMachine__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
yasmin_msgs__msg__StateMachine__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/StateMachine messages.
/**
 * It allocates the memory for the number of elements and calls
 * yasmin_msgs__msg__StateMachine__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__Sequence__init(yasmin_msgs__msg__StateMachine__Sequence * array, size_t size);

/// Finalize array of msg/StateMachine messages.
/**
 * It calls
 * yasmin_msgs__msg__StateMachine__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
void
yasmin_msgs__msg__StateMachine__Sequence__fini(yasmin_msgs__msg__StateMachine__Sequence * array);

/// Create array of msg/StateMachine messages.
/**
 * It allocates the memory for the array and calls
 * yasmin_msgs__msg__StateMachine__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
yasmin_msgs__msg__StateMachine__Sequence *
yasmin_msgs__msg__StateMachine__Sequence__create(size_t size);

/// Destroy array of msg/StateMachine messages.
/**
 * It calls
 * yasmin_msgs__msg__StateMachine__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
void
yasmin_msgs__msg__StateMachine__Sequence__destroy(yasmin_msgs__msg__StateMachine__Sequence * array);

/// Check for msg/StateMachine message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__Sequence__are_equal(const yasmin_msgs__msg__StateMachine__Sequence * lhs, const yasmin_msgs__msg__StateMachine__Sequence * rhs);

/// Copy an array of msg/StateMachine messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_yasmin_msgs
bool
yasmin_msgs__msg__StateMachine__Sequence__copy(
  const yasmin_msgs__msg__StateMachine__Sequence * input,
  yasmin_msgs__msg__StateMachine__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // YASMIN_MSGS__MSG__DETAIL__STATE_MACHINE__FUNCTIONS_H_
