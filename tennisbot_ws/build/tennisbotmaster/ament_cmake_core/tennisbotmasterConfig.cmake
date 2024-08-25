# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tennisbotmaster_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tennisbotmaster_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tennisbotmaster_FOUND FALSE)
  elseif(NOT tennisbotmaster_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tennisbotmaster_FOUND FALSE)
  endif()
  return()
endif()
set(_tennisbotmaster_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tennisbotmaster_FIND_QUIETLY)
  message(STATUS "Found tennisbotmaster: 0.0.0 (${tennisbotmaster_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tennisbotmaster' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT tennisbotmaster_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tennisbotmaster_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tennisbotmaster_DIR}/${_extra}")
endforeach()
