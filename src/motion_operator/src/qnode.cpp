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
#include "../include/motion_operator/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/


namespace motion_operator {

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
    ros::init(init_argc,init_argv,"motion_operator");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    imu_Sub = n.subscribe("imu", 100, &QNode::imuCallback, this); //tw
    MotionN_sub = n.subscribe("Motion",100,&QNode::MotionNumCallback,this);
    Motor_Sub = n.subscribe("Dynamixel",100,&QNode::MotorCallback,this);
    //Motion_Pub = n.advertise("mt", 100, &QNode::MotionCallback, this); // 20240402tw
    Motion_Sub = n.subscribe("Dxl_Motion", 100, &QNode::MotionCallback,this);
    motion_operate = n.advertise<msg_generate::Motion_msg>("Motion_232",100);
    Motor_Pub = n.advertise<msg_generate::Motor_msg>("Dynamixel", 100);
    Serial_pub = n.advertise<msg_generate::motion_end>("motion_end", 100);
    // Add your ros communications here.
    start();
    return true;
}


void QNode::run() {
    ros::spin();
//    ros::Rate loop_rate(7);

//    while ( ros::ok() ) {

//		ros::spinOnce();
//		loop_rate.sleep();
//	}

    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::imuCallback(const msg_generate::imu_msg::ConstPtr &msg){
    imu.pitch           = msg->pitch;
    imu.roll            = msg->roll;
    imu.yaw             = msg->yaw;
}

//void QNode::MotionNumCallback(const std_msgs::Int32::ConstPtr &msg){
//    motionNum = msg->data;
//    motionMode = msg->data; //20240403
//    Q_EMIT Motion_Sig();
//}

void QNode::MotionNumCallback(const msg_generate::motionNum_msg::ConstPtr &msg){
    motionNum = msg->Motion_Num;
    motionMode = msg->Motion_Mode; //20240403
    Q_EMIT Motion_Sig();
}

void QNode::MotorCallback(const msg_generate::Motor_msg::ConstPtr &msg)
{
    Dx_msg_l.length = msg->length;
    Dx_msg_l.mode = msg->mode;
    Dx_msg_l.id = msg->id;
    Dx_msg_l.speed = msg->speed;
    Dx_msg_l.position = msg->position;
    Dx_msg_l.type = msg->type;
    Dx_msg_l.acceleration = msg->acceleration;
    Q_EMIT Rx_MotorData();
}

void QNode::MotionCallback(const msg_generate::Motion_msg::ConstPtr &msg){
    Motion_msg.max_step = msg->max_step;
    Motion_msg.motion_data = msg->motion_data;
    Motion_msg.repeat = msg->repeat;
    Motion_msg.acc = msg->acc;
    Q_EMIT Rx_MotionData();
}

}  // namespace motion_operator
