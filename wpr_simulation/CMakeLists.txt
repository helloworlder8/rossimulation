cmake_minimum_required(VERSION 2.8.3)
project(wpr_simulation)

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
  cv_bridge 
  image_transport
  nav_msgs
)

# Find Gazebo
find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

# Find OpenCV
find_package(OpenCV REQUIRED)

catkin_package(

)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)



add_library(wpr_plugin SHARED src/wpr_plugin.cpp)
target_link_libraries(wpr_plugin ${GAZEBO_LIBRARIES})

add_executable(wpb_home_sim
  src/wpb_home_sim.cpp
)
add_dependencies(wpb_home_sim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(wpb_home_sim
  ${catkin_LIBRARIES}
)

add_executable(wpr1_sim
  src/wpr1_sim.cpp
)
add_dependencies(wpr1_sim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(wpr1_sim
  ${catkin_LIBRARIES}
)

add_executable(demo_vel_ctrl
  src/demo_vel_ctrl.cpp
)
add_dependencies(demo_vel_ctrl ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_vel_ctrl
  ${catkin_LIBRARIES}
)

# add_executable(keyboard_vel_ctrl
#   src/keyboard_vel_ctrl.cpp
# )
# add_dependencies(keyboard_vel_ctrl ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# target_link_libraries(keyboard_vel_ctrl
#   ${catkin_LIBRARIES}
# )

add_executable(demo_simple_goal
  src/demo_simple_goal.cpp
)
add_dependencies(demo_simple_goal ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_simple_goal
  ${catkin_LIBRARIES}
)

add_executable(demo_map_tool
  src/demo_map_tool.cpp
)
add_dependencies(demo_map_tool ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_map_tool
  ${catkin_LIBRARIES}
)

add_executable(demo_sr_navigation
  src/demo_sr_navigation.cpp
)
add_dependencies(demo_sr_navigation ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_sr_navigation
  ${catkin_LIBRARIES}
)

add_executable(ball_random_move
  src/ball_random_move.cpp
)
add_dependencies(ball_random_move ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ball_random_move
  ${catkin_LIBRARIES}
)

add_executable(demo_lidar_data
  src/demo_lidar_data.cpp
)
add_dependencies(demo_lidar_data ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_lidar_data
  ${catkin_LIBRARIES}
)

add_executable(demo_lidar_behavior
  src/demo_lidar_behavior.cpp
)
add_dependencies(demo_lidar_behavior ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_lidar_behavior
  ${catkin_LIBRARIES}
)

add_executable(demo_imu_data
  src/demo_imu_data.cpp
)
add_dependencies(demo_imu_data ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_imu_data
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(demo_imu_behavior
  src/demo_imu_behavior.cpp
)
add_dependencies(demo_imu_behavior ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_imu_behavior
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(demo_map_pub
  src/demo_map_pub.cpp
)
add_dependencies(demo_map_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_map_pub
  ${catkin_LIBRARIES}
)

add_executable(demo_cv_image
  src/demo_cv_image.cpp
)
add_dependencies(demo_cv_image ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_cv_image
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(demo_cv_hsv
  src/demo_cv_hsv.cpp
)
add_dependencies(demo_cv_hsv ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_cv_hsv
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(demo_cv_follow
  src/demo_cv_follow.cpp
)
add_dependencies(demo_cv_follow ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_cv_follow
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(demo_cv_face_detect
  src/demo_cv_face_detect.cpp
)
add_dependencies(demo_cv_face_detect ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(demo_cv_face_detect
  ${catkin_LIBRARIES} ${OpenCV_LIBS}
)

add_executable(teleop_js_node
  src/teleop_js_node.cpp
)
add_dependencies(teleop_js_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(teleop_js_node
  ${catkin_LIBRARIES}
)
