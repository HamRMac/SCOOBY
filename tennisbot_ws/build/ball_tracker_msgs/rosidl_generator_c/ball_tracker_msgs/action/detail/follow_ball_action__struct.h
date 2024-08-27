// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ball_tracker_msgs:action/FollowBallAction.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_tracker_msgs/action/follow_ball_action.h"


#ifndef BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__STRUCT_H_
#define BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_Goal
{
  float timeout;
} ball_tracker_msgs__action__FollowBallAction_Goal;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_Goal.
typedef struct ball_tracker_msgs__action__FollowBallAction_Goal__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_Goal__Sequence;

// Constants defined in the message

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_Result
{
  float current_distance;
} ball_tracker_msgs__action__FollowBallAction_Result;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_Result.
typedef struct ball_tracker_msgs__action__FollowBallAction_Result__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_Feedback
{
  bool success;
} ball_tracker_msgs__action__FollowBallAction_Feedback;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_Feedback.
typedef struct ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "ball_tracker_msgs/action/detail/follow_ball_action__struct.h"

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  ball_tracker_msgs__action__FollowBallAction_Goal goal;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Request;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_SendGoal_Request.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Response;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_SendGoal_Response.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Request__Sequence request;
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Response__Sequence response;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Event;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_SendGoal_Event.
typedef struct ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Request;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_GetResult_Request.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__struct.h"

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Response
{
  int8_t status;
  ball_tracker_msgs__action__FollowBallAction_Result result;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Response;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_GetResult_Response.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ball_tracker_msgs__action__FollowBallAction_GetResult_Request__Sequence request;
  ball_tracker_msgs__action__FollowBallAction_GetResult_Response__Sequence response;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Event;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_GetResult_Event.
typedef struct ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "ball_tracker_msgs/action/detail/follow_ball_action__struct.h"

/// Struct defined in action/FollowBallAction in the package ball_tracker_msgs.
typedef struct ball_tracker_msgs__action__FollowBallAction_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  ball_tracker_msgs__action__FollowBallAction_Feedback feedback;
} ball_tracker_msgs__action__FollowBallAction_FeedbackMessage;

// Struct for a sequence of ball_tracker_msgs__action__FollowBallAction_FeedbackMessage.
typedef struct ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence
{
  ball_tracker_msgs__action__FollowBallAction_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_tracker_msgs__action__FollowBallAction_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BALL_TRACKER_MSGS__ACTION__DETAIL__FOLLOW_BALL_ACTION__STRUCT_H_
