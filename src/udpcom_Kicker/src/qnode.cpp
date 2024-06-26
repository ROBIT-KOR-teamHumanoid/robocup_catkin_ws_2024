/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/udpcom_Kicker/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom_Kicker {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
{}

QNode::~QNode() {
    if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();
}

bool QNode::init() {
    ros::init(init_argc,init_argv,"udpcom_Kicker");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    udp_RB1_pub     = n.advertise<msg_generate::localv2_msg>("udp_RB1",100);          //udpcom -> Master
    udp_RB2_pub     = n.advertise<msg_generate::localv2_msg>("udp_RB2",100);          //udpcom -> Master
    udp_RB_K_pub    = n.advertise<msg_generate::udp_msg_TC_Kicker>("udp_RB_K",100);   //udpcom -> Master
    udp_RB_H_pub    = n.advertise<msg_generate::udp_msg_TC_Helper>("udp_RB_H",100);   //udpcom -> Master
    udp_dataSub     = n.subscribe("localxy", 100, &QNode::udpDataCallback,this);      //Local -> udpcom
    vision_Sub      = n.subscribe("robocup2019_vision", 100,&QNode::visionCallback,this);

    master2udp_sub  = n.subscribe("udp_data",100,&QNode::master2udpCallback2,this);

    gamecon_sub     = n.subscribe("gamecontroller",100,&QNode::gameconCallback,this);
    km2udpsub       = n.subscribe("master2Kudp",100,&QNode::master2udpCallback,this);   //kicker master -> udp
    udp2hoderpub    = n.advertise<msg_generate::udp_helper_msg>("Hudp2master",100);     //udp -> kicker master(helper's order) doum'


    start();
    return true;
}


void QNode::run() {
    ros::Rate loop_rate(33);
    while ( ros::ok() ) {

        ros::spinOnce();
        loop_rate.sleep();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::udpDataCallback(const msg_generate::localv2_msg::ConstPtr& msg)
{
    robot_X     = msg->local_x;
    robot_Y     = msg->local_y;
    robot_Yaw   = msg->local_yaw;
    robot_Yaw   += 180;

    Q_EMIT getUdpdata();

}

void QNode::visionCallback(const msg_generate::robocupvision::ConstPtr &msg){

    ball_D = msg->ballDist;
    ball_T = msg->ballTheta;
    ball_T += 180;
}

void QNode::gameconCallback(const msg_generate::game_control_data::ConstPtr &msg)
{
    robot_Num = msg->robotNum;
    robot_Pan = msg->penalty;

    if(robot_Num != past_robot_Num){
        Q_EMIT getrobotNum();
    }

    past_robot_Num = robot_Num;
}

void QNode::master2udpCallback2(const msg_generate::udp_msg::ConstPtr &msg)
{
    robot_case = msg->robocup_case;
}
void QNode::master2udpCallback(const msg_generate::udp_kicker_msg::ConstPtr &msg)
{
    std::cout<<"case :: "<<msg->robot_case<<std::endl;
    robot_case = msg->robot_case;
}

}  // namespace udpcom_Kicker
