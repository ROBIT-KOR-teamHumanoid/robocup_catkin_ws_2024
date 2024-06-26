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
#include "../include/best_supporting_spot/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace best_supporting_spot {

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
    ros::init(init_argc,init_argv,"best_supporting_spot");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.

    //ROS TOPIC=====================================================================
    imuSub          = n.subscribe("imu", 100, &QNode::imuCallback, this);
    localSub        = n.subscribe("robocup_localization24",100, &QNode::localCallback, this);
    visionSub       = n.subscribe("robocup_vision24",100, &QNode::visionCallback, this);
    ikSub           = n.subscribe("ikend", 100, &QNode::ikCallback, this);
    udpR1Sub        = n.subscribe("udp_RB1", 100, &QNode::udpCallback, this);
    udpR2Sub        = n.subscribe("udp_RB2", 100, &QNode::udpCallback, this);
    udpR3Sub        = n.subscribe("udp_RB3", 100, &QNode::udpCallback, this);
    //gamecontrolSub  = n.subscribe("gamecontroller", 100, &MasterRcko::gameCallback, this);



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


void QNode::imuCallback(const msg_generate::imu_msg::ConstPtr &msg)
{
    imu.pitch           = msg->pitch;
    imu.roll            = msg->roll;
    imu.yaw             = msg->yaw;
}

void QNode::localCallback(const msg_generate::robocup_localization24::ConstPtr &msg)
{

    std:: cout<<"callback"<<std::endl;
    std:: cout<<local.Ball_X<<local.Ball_Y<<std::endl;
    local.Ball_X        = msg->Ball_X;
    local.Ball_Y        = msg->Ball_Y;
    local.Robot_X       = msg->Robot_X;
    local.Robot_Y       = msg->Robot_Y;
    local.Ball_speed_X  = msg->Ball_speed_X;
    local.Ball_speed_Y  = msg->Ball_speed_Y;

    local.Obstacle0_X   = msg->Obstacle0_X;
    local.Obstacle0_Y   = msg->Obstacle0_Y;
    local.Obstacle1_X   = msg->Obstacle1_X;
    local.Obstacle1_Y   = msg->Obstacle1_Y;
    local.Obstacle2_X   = msg->Obstacle2_X;
    local.Obstacle2_Y   = msg->Obstacle2_Y;
    local.Obstacle3_X   = msg->Obstacle3_X;
    local.Obstacle3_Y   = msg->Obstacle3_Y;

}

void QNode::visionCallback(const msg_generate::robocup_vision24::ConstPtr &msg)
{
    int bias = 0;

#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_1
    bias = 3;
#endif
#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_2
    bias = -31;
#endif
#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_3
    bias = -5;
#endif
#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_4
    bias = 12;
#endif
#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_5
    bias = 0;
#endif
#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_6
    bias = 3;
#endif

    vision.Ball_2d_X        = msg->Ball_2d_X + bias;
    vision.Ball_2d_Y        = msg->Ball_2d_Y;
    vision.Ball_cam_X       = msg->Ball_cam_X;
    vision.Ball_cam_Y       = msg->Ball_cam_Y;
    vision.Ball_D           = msg->Ball_D;
    vision.Ball_speed_level = msg->Ball_speed_level;
}

void QNode::ikCallback(const msg_generate::ikend_msg::ConstPtr &msg)
{
    ikEnd.ikend         = msg->ikend;
}

//void QNode::motionCallback(const msg_generate::motion_end::ConstPtr &msg)
//{
//    motionEnd.motion_end = msg->motion_end;
//}

void QNode::udpCallback(const msg_generate::localv2_msg::ConstPtr &msg)
{
    int i = static_cast<int>(msg->robot_num - 1);
    udp[i].robot_num    = msg->robot_num;
    udp[i].robot_case   = msg->robot_case;
    udp[i].local_x      = msg->local_x;
    udp[i].local_y      = msg->local_y;
    udp[i].local_yaw    = msg->local_yaw;
    udp[i].ballDist     = msg->ballDist;


    udp[3].ballDist = 0;
}

void QNode::gameCallback(const msg_generate::game_control_data::ConstPtr &msg)
{
    gameControlData.robotNum    = msg->robotNum;
    gameControlData.state       = msg->state;
    gameControlData.readyTime   = msg->readyTime;
    gameControlData.penalty     = msg->penalty;
    gameControlData.mySide      = msg->mySide;
    gameControlData.iskickoff   = msg->iskickoff;
    gameControlData.position    = msg->position;
    gameControlData.secondState = msg->secondState;
    gameControlData.secondInfo  = msg->secondInfo;
    gameControlData.myTeam      = msg->myTeam;

}

}  // namespace best_supporting_spot
