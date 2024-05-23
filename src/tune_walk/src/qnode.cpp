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
#include "../include/tune_walk/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace tune_walk {

/*****************************************************************************
** Implementation
*****************************************************************************/

ros::Publisher tune2walk_Pub;
ros::Subscriber imu_Sub;
ros::Subscriber zmp_Sub;
ros::Subscriber walkpatternSub;
ros::Subscriber LandingSub;
double xlpattern,ylpattern,zlpattern,slpattern,tlpattern,xrpattern,yrpattern,zrpattern,srpattern,trpattern;
double pitch,roll,yaw;
double left_x_zmp,left_y_zmp,right_x_zmp,right_y_zmp,total_x_zmp,total_y_zmp;
bool Left_Foot, Right_Foot, Both_Feet;

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
	ros::init(init_argc,init_argv,"tune_walk");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
        tune2walk_Pub = n.advertise<msg_generate::tune2walk>("tune2walk",100);
        imuSub = n.subscribe("imu", 100, &QNode::imuCallback, this);
        zmpSub = n.subscribe("zmp_msg",100,&QNode::zmpCallback,this);
        walkpatternSub = n.subscribe("walk_pattern",100,&QNode::walkpatternCallback,this);
        LandingSub = n.subscribe("Landing_Time_Control", 100, &QNode::LandingCallback, this);
        // Add your ros communications here.
	start();
	return true;
}

void QNode::LandingCallback(const msg_generate::Landing_Time_Control::ConstPtr &msg)
{
    Landing_info.Entire_Time = msg->Entire_Time;
    Landing_info.Swing_Gain_L = msg->Swing_Gain_L;
    Landing_info.Swing_Gain_R = msg->Swing_Gain_R;
    Landing_info.Warning = msg->Warning;
    Landing_info.Safe = msg->Safe;

    Landing_info.Landing_Time_L = msg->Landing_Time_L;
    Landing_info.Landing_Time_R = msg->Landing_Time_R;
    Landing_info.Landing_Error_L = msg->Landing_Error_L;
    Landing_info.Landing_Error_R = msg->Landing_Error_R;

    Q_EMIT Landing_callback();
}

void QNode::imuCallback(const msg_generate::imu_msg::ConstPtr &msg)
{

    pitch = msg->pitch;
    roll = msg->roll;
    yaw = msg->yaw;

    //Q_EMIT recvImu();
}
void QNode::zmpCallback(const msg_generate::zmp_msg::ConstPtr &msg)
{
     left_x_zmp = msg->Left_X_zmp;
     left_y_zmp = msg->Left_Y_zmp;
     right_x_zmp = msg->Right_X_zmp;
     right_y_zmp = msg->Right_Y_zmp;
     total_x_zmp = msg->Total_X_zmp;
     total_y_zmp = msg->Total_Y_zmp;
     Left_Foot = msg->Left_Foot;
     Right_Foot = msg->Right_Foot;
     Both_Feet = msg->Both_Feet;
}
void QNode::walkpatternCallback(const msg_generate::walk_pattern::ConstPtr &msg)
{
    xlpattern = msg->xlpattern;
    ylpattern = msg->ylpattern;
    zlpattern = msg->zlpattern;
    slpattern = msg->slpattern;
    tlpattern = msg->tlpattern;

    xrpattern = msg->xrpattern;
    yrpattern = msg->yrpattern;
    zrpattern = msg->zrpattern;
    srpattern = msg->srpattern;
    trpattern = msg->trpattern;

//std::cout<<xrpattern<<std::endl;
}


void QNode::run() {
	ros::Rate loop_rate(1);
	int count = 0;
	while ( ros::ok() ) {
            ros::spinOnce();
	}
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}





}  // namespace tune_walk
