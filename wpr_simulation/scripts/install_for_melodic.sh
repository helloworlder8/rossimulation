#!/bin/bash
sudo apt-get install -y ros-melodic-desktop-full
# ros-melodic-desktop-full：这是ROS Melodic的完整桌面安装，包含了ROS核心组件、常用工具、仿真和可视化工具以及大量常用软件包
sudo apt-get install -y ros-melodic-navigation
# 提供了用于机器人导航的软件包集合，包括地图构建、路径规划和导航执行等功能
sudo apt-get install -y ros-melodic-joy
# 用于接收游戏手柄输入的软件包，可以将游戏手柄的输入转换为ROS中的控制命令
sudo apt-get install -y ros-melodic-gazebo-ros-control
# 提供了将Gazebo仿真器与ROS控制器进行集成的软件包，用于在仿真环境中控制机器人
sudo apt-get install -y ros-melodic-joint-state-controller
# 用于控制机器人关节状态的软件包，包括获取和发布关节状态信息
sudo apt-get install -y ros-melodic-position-controllers
# 提供了用于位置控制的软件包，可用于控制机器人的关节位
sudo apt-get install -y ros-melodic-effort-controllers
# 提供了用于力/扭矩控制的软件包，可用于控制机器人的关节力/扭矩
sudo apt-get install -y ros-melodic-cv-bridge
# 用于在ROS和OpenCV之间进行图像转换和传递的软件包，方便在ROS系统中处理和分析图像数据
sudo apt-get install -y ros-melodic-controller-manager
# 提供了管理ROS控制器的软件包，包括加载、卸载和切换控制器等功能
sudo apt-get install -y ros-melodic-hector-mapping
# 用于建立SLAM（Simultaneous Localization and Mapping，同时定位与地图构建）的软件包，可以利用机器人传感器数据生成环境地图
sudo apt-get install -y ros-melodic-gmapping
# 提供了用于实时构建机器人环境地图的软件包，使用激光传感器数据进行SLAM