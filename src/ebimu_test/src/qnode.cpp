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
#include "../include/ebimu_test/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ebimu_test {

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
    ros::init(init_argc,init_argv,"ebimu_test");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    ik_sub  = n.subscribe("master2ik", 100, &QNode::ikCallback, this);
    imu_pub = n.advertise<msg_generate::imu_msg>("imu", 100);
    pid_pub = n.advertise<msg_generate::pid_tuning>("pid", 100);

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

void ebimu_test::QNode::ikCallback(const msg_generate::ik_msg::ConstPtr &msg)
{
    walk_flag = msg->flag;
    robot_yaw = msg->Yaw;
}

}  // namespace ebimu_test
