cmake_minimum_required(VERSION 3.0.2)
project(car_test)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
controller_manager
joint_state_controller
robot_state_publisher
roscpp
rospy
std_msgs
geometry_msgs
move_base_msgs 
actionlib
tf
nav_msgs
)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")



catkin_package(

)


include_directories(
include
${catkin_INCLUDE_DIRS}
)


add_executable(multi_point_node src/multi_point.cpp)
add_dependencies(multi_point_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(multi_point_node
   ${catkin_LIBRARIES}
 )


 add_library(myplugin SHARED src/myplugin.cpp)
 target_link_libraries(myplugin ${GAZEBO_LIBRARIES})

add_executable(keyboard_vel_ctrl src/keyboard_vel_ctrl.cpp)
add_dependencies(keyboard_vel_ctrl ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(keyboard_vel_ctrl
 ${catkin_LIBRARIES}
)





