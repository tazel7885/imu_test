cmake_minimum_required(VERSION 3.0.2)
project(imu_test)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
  tf
)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES imu_test
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs sensor_msgs tf
  DEPENDS system_lib
)

include_directories(
    include 
    ${catkin_INCLUDE_DIRS} 
)

add_executable(imu_test src/imu_test_node.cpp)
target_link_libraries(imu_test ${catkin_LIBRARIES} ${${PROJECT_NAME}_EXPORTED_TARGETS})
add_dependencies(imu_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
