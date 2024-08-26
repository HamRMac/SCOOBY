# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yasmin_msgs:msg/State.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_State(type):
    """Metaclass of message 'State'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yasmin_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yasmin_msgs.msg.State')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__state

            from yasmin_msgs.msg import Transition
            if Transition.__class__._TYPE_SUPPORT is None:
                Transition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PARENT__DEFAULT': -1,
            'CURRENT_STATE__DEFAULT': -1,
        }

    @property
    def PARENT__DEFAULT(cls):
        """Return default value for message field 'parent'."""
        return -1

    @property
    def CURRENT_STATE__DEFAULT(cls):
        """Return default value for message field 'current_state'."""
        return -1


class State(metaclass=Metaclass_State):
    """Message class 'State'."""

    __slots__ = [
        '_id',
        '_parent',
        '_name',
        '_transitions',
        '_outcomes',
        '_is_fsm',
        '_current_state',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'parent': 'int32',
        'name': 'string',
        'transitions': 'sequence<yasmin_msgs/Transition>',
        'outcomes': 'sequence<string>',
        'is_fsm': 'boolean',
        'current_state': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['yasmin_msgs', 'msg'], 'Transition')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.parent = kwargs.get(
            'parent', State.PARENT__DEFAULT)
        self.name = kwargs.get('name', str())
        self.transitions = kwargs.get('transitions', [])
        self.outcomes = kwargs.get('outcomes', [])
        self.is_fsm = kwargs.get('is_fsm', bool())
        self.current_state = kwargs.get(
            'current_state', State.CURRENT_STATE__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.id != other.id:
            return False
        if self.parent != other.parent:
            return False
        if self.name != other.name:
            return False
        if self.transitions != other.transitions:
            return False
        if self.outcomes != other.outcomes:
            return False
        if self.is_fsm != other.is_fsm:
            return False
        if self.current_state != other.current_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @builtins.property
    def parent(self):
        """Message field 'parent'."""
        return self._parent

    @parent.setter
    def parent(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'parent' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'parent' field must be an integer in [-2147483648, 2147483647]"
        self._parent = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def transitions(self):
        """Message field 'transitions'."""
        return self._transitions

    @transitions.setter
    def transitions(self, value):
        if self._check_fields:
            from yasmin_msgs.msg import Transition
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Transition) for v in value) and
                 True), \
                "The 'transitions' field must be a set or sequence and each value of type 'Transition'"
        self._transitions = value

    @builtins.property
    def outcomes(self):
        """Message field 'outcomes'."""
        return self._outcomes

    @outcomes.setter
    def outcomes(self, value):
        if self._check_fields:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'outcomes' field must be a set or sequence and each value of type 'str'"
        self._outcomes = value

    @builtins.property
    def is_fsm(self):
        """Message field 'is_fsm'."""
        return self._is_fsm

    @is_fsm.setter
    def is_fsm(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'is_fsm' field must be of type 'bool'"
        self._is_fsm = value

    @builtins.property
    def current_state(self):
        """Message field 'current_state'."""
        return self._current_state

    @current_state.setter
    def current_state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'current_state' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_state' field must be an integer in [-2147483648, 2147483647]"
        self._current_state = value
