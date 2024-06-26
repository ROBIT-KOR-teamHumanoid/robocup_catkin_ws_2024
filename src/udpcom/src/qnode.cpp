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
#include "../include/udpcom/qnode.hpp"



/*****************************************************************************
** Namespaces
*****************************************************************************/

using namespace std;

namespace udpcom {

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
    ros::init(init_argc,init_argv,"udpcom");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    udp_RB1_pub = n.advertise<msg_generate::localv2_msg>("udp_RB1",100);
    udp_RB2_pub = n.advertise<msg_generate::localv2_msg>("udp_RB2",100);
    udp_RB3_pub = n.advertise<msg_generate::localv2_msg>("udp_RB3",100);
    udp_RB4_pub = n.advertise<msg_generate::localv2_msg>("udp_RB4",100);

    udp_dataSub = n.subscribe("robocup24_master2udp", 100, &QNode::udpDataCallback, this);
    start();
    return true;
}

void QNode::run() {
    ros::spin();
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::udpDataCallback(const msg_generate::robocup24_master2udp::ConstPtr& msg)
{
    robot_num = msg->robot_num;
    robot_case = msg->robot_state;
    robot_coor_x = msg->robot_coor_x;
    robot_coor_y = msg->robot_coor_y;
    robot_imu_yaw = msg->roboy_imu_yaw;
    robot_imu_yaw += 180;

    ball_dist = msg->ball_dist;
    ball_coor_x = msg->ball_coor_x;
    ball_coor_y = msg->ball_coor_y;
    myTeam = msg->myTeam;

    cout << "robot_num:     " << robot_num << endl;
    cout << "robot_coor_x:  " << robot_coor_x << endl;
    cout << "robot_coor_y:  " << robot_coor_y << endl;
    cout << "robot_imu_yaw: " << robot_imu_yaw << endl;
    cout << "ball_dist:     " << ball_dist << endl;
    cout << "ball_coor_x:   " << ball_coor_x << endl;
    cout << "ball_coor_y:   " << ball_coor_y << endl;
    cout << "my team:       " << myTeam << endl;
}
}
