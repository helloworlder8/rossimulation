/*
自动驾驶开发实践---move base
*/

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/Bool.h>
#include <std_msgs/String.h>
#include "std_srvs/Empty.h"

#include <string>        
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <math.h>

double     goal_point[100];        //记录目标点位置

//ye
move_base_msgs::MoveBaseGoal cur_goal;   
int count_goal; //导航点数数量



typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


int main(int argc, char **argv)
{

    ros::init(argc, argv, "multi_point_node");
    ros::NodeHandle n;  //定义节点进程句柄
    ros::NodeHandle nh_private("~");

    //8个目标点
    nh_private.param<int>("count_goal", count_goal, 8); 

    nh_private.param<double>("x1", goal_point[0], 0.3); //1
    nh_private.param<double>("y1", goal_point[1], 1.0); 
    nh_private.param<double>("x2", goal_point[2], 0.3); //2
    nh_private.param<double>("y2", goal_point[3], 1.0); 
    nh_private.param<double>("x3", goal_point[4], 0.3); //3
    nh_private.param<double>("y3", goal_point[5], 1.0); 
    nh_private.param<double>("x4", goal_point[6], 0.3); 
    nh_private.param<double>("y4", goal_point[7], 1.0); 
    nh_private.param<double>("x5", goal_point[8], 0.3); 
    nh_private.param<double>("y5", goal_point[9], 1.0); 
    nh_private.param<double>("x6", goal_point[10], 0.3); 
    nh_private.param<double>("y6", goal_point[11], 1.0); 
    nh_private.param<double>("x7", goal_point[12], 0.3); 
    nh_private.param<double>("y7", goal_point[13], 1.0); 
    nh_private.param<double>("x8", goal_point[14], 0.3); 
    nh_private.param<double>("y8", goal_point[15], 1.0); 

    //要减去2
    count_goal = (count_goal*2)-2; 
    //打印目标点信息
    for(int i=0 ;i < count_goal ; i+=2 ){
        
        ROS_INFO_STREAM("goal_point[ "<<(i/2)<<"] : ( " <<goal_point[i] <<" ), ( "<<goal_point[i+1] <<" )");

    }

    ros::Rate loop_rate(50);
    while(ros::ok())
    {



        MoveBaseClient ac("move_base",true);        

        while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
        } //等待操作服务器报告它已出现并准备开始处理目标

        //当前导航点
        int curPoint=0;

        ROS_INFO_STREAM("Point count is : "<< count_goal );
        for( ; curPoint < count_goal; curPoint+=2)
        {
            //失败次数记录
            int try_times = 0;

            //设置要发布的目标点信息
            cur_goal.target_pose.header.frame_id="map";
            cur_goal.target_pose.header.stamp=ros::Time::now(); 
            cur_goal.target_pose.pose.position.x=goal_point[curPoint];
            cur_goal.target_pose.pose.position.y=goal_point[curPoint+1];
            cur_goal.target_pose.pose.position.z=0.0;
        
            cur_goal.target_pose.pose.orientation.x=0.0;
            cur_goal.target_pose.pose.orientation.y=0.0;
            cur_goal.target_pose.pose.orientation.z=1.0;
            cur_goal.target_pose.pose.orientation.w=0;

            //开始导航到当前目标点
            ac.sendGoal(cur_goal);

            while(true)
            {
                ROS_INFO_STREAM("go  cur_goal:"<<curPoint<<" cur_goal X: "<<cur_goal.target_pose.pose.position.x<<" ,goal Y: "<<cur_goal.target_pose.pose.position.y);
                ROS_INFO_STREAM("ac.getState is : "<<ac.getState().toString());
                //查看导航结果
                ac.waitForResult();
                //成功到达目标点
                if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED ){
                    ROS_INFO_STREAM("Already reached point: "<<curPoint);
                    //先取消导航，让车停止一会
                    ac.cancelAllGoals();
                    ROS_INFO_STREAM("waiting goal!  ");
                    break;
                }
                else
                {
                    //尝试5次之后，导航失败
                    if(try_times == 5) 
                    {
                        ROS_INFO("error goal, maybe it is not in map; start next goal");
                        //取消这个导航点了，继续发布下一个点
                        ac.cancelAllGoals();
                        break ;
                    }
                    ROS_INFO_STREAM("Failed to reach the point :"<<curPoint <<"  times : "<<try_times);  
                    try_times++;
                    //取消这个点，然后重新导航这个点试试
                    ac.cancelAllGoals();

                    //等待操作服务器报告它已出现并准备开始处理目标
                    while(!ac.waitForServer(ros::Duration(5.0))){
                        ROS_INFO("Waiting for the move_base action server to come up");
                    } 
                    //再次导航这个点
                    ac.sendGoal(cur_goal);

                }
            }

        }
	 loop_rate.sleep();
        ros::spinOnce();

    }
    return 0;
}



