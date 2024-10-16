cmake_minimum_required(VERSION 3.8)
project(line_detector)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(image_transport REQUIRED)

add_executable(detect_lines src/detect_lines.cpp)
target_include_directories(detect_lines PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(detect_lines PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

add_executable(boundary_guard src/boundary_guard.cpp)
target_include_directories(boundary_guard PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(boundary_guard PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(detect_lines
  rclcpp
  sensor_msgs
  geometry_msgs
  cv_bridge
  OpenCV
  image_transport
)

ament_target_dependencies(boundary_guard
  rclcpp
  sensor_msgs
  geometry_msgs
  cv_bridge
  OpenCV
  image_transport
)

install(TARGETS detect_lines
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS boundary_guard
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
