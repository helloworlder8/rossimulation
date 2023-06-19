# 自带的运动控制
# rosrun turtlesim turtle_teleop_key /turtle1/cmd_vel:=cmd_vel

# 读取地图配置 amcl movebase路径规划 rviz  # 带有仿真环境
roslaunch car_test all.launch          roslaunch car_test all2.launch

# gmapping见建图
roslaunch car_test gmapping.launch     roslaunch car_test map_server.launch
# 地图保存
roslaunch car_test map_save.launch
# 仿真环境1
roslaunch car_test gazebo1.launch
# 仿真环境2
roslaunch car_test gazebo2.launch
# 自己写的运动控制
rosrun car_test keyboard_vel_ctrl
# w - 向前加速 
# s - 向后加速 
# a - 向左加速 
# d - 向右加速 
# q - 左旋加速 
# e - 右旋加速 
# 空格 - 刹车 
# x - 退出 

# amcl movebase不单独运行
# gmapping和mapserver二选1运行