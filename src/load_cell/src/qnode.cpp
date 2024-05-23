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
#include "../include/load_cell/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace load_cell {

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
    ros::init(init_argc,init_argv,"load_cell");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;

    // Add your ros communications here.
    loadcell_sub = n.subscribe("serial2LC", 100, &QNode::LoadCell_Callback,this);
    COM_sub = n.subscribe("COM", 100, &QNode::COM_Callback,this);
    //ard_sub = n.subscribe("ZMP_arduino", 100, &QNode::ard_Callback,this);
    Zmp_Pub = n.advertise<msg_generate::zmp_msg>("zmp_msg",100);

    start();
    return true;
}

void QNode::LoadCell_Callback(const msg_generate::Serial2LC_msg::ConstPtr &msg)
{
    LC_info.L_LC_Data.push_back(msg->R_LC_Data[0]);//이때 R과 L이 반전된 이유는 받아오는 로드셀 값은 사람이 로봇을 봤을 때의 방향을 기준으로 하고있기 때문
    LC_info.L_LC_Data.push_back(msg->R_LC_Data[1]);
    LC_info.L_LC_Data.push_back(msg->R_LC_Data[2]);
    LC_info.L_LC_Data.push_back(msg->R_LC_Data[3]);
    LC_info.R_LC_Data.push_back(msg->L_LC_Data[0]);
    LC_info.R_LC_Data.push_back(msg->L_LC_Data[1]);
    LC_info.R_LC_Data.push_back(msg->L_LC_Data[2]);
    LC_info.R_LC_Data.push_back(msg->L_LC_Data[3]);

    Q_EMIT LC_callback();
    LC_info.R_LC_Data.clear();
    LC_info.L_LC_Data.clear();
}

void QNode::COM_Callback(const msg_generate::com_msg::ConstPtr &msg)
{
    COM_info.X_com = msg->X_com;
    COM_info.Y_com = msg->Y_com;
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


}  // namespace load_cell
