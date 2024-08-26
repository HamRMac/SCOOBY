// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_nav_to_pose_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_nav_to_pose_msgs/action/navigate_to_pose.h"


#ifndef ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
#define ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Goal
{
  geometry_msgs__msg__PoseStamped goal_pose;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Goal;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_Goal.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Goal__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Goal__Sequence;

// Constants defined in the message

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Result
{
  bool success;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Result;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_Result.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Result__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback
{
  double remaining_distance_to_goal;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "ros2_nav_to_pose_msgs/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  ros2_nav_to_pose_msgs__action__NavigateToPose_Goal goal;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Request__Sequence request;
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Response__Sequence response;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "ros2_nav_to_pose_msgs/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response
{
  int8_t status;
  ros2_nav_to_pose_msgs__action__NavigateToPose_Result result;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Request__Sequence request;
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Response__Sequence response;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "ros2_nav_to_pose_msgs/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package ros2_nav_to_pose_msgs.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  ros2_nav_to_pose_msgs__action__NavigateToPose_Feedback feedback;
} ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage;

// Struct for a sequence of ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage.
typedef struct ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage__Sequence
{
  ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_nav_to_pose_msgs__action__NavigateToPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_NAV_TO_POSE_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
