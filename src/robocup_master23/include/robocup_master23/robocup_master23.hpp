#ifndef MASTER_RICO_HPP
#define MASTER_RICO_HPP

#include "/home/robit/catkin_ws/src/robot_config.h"

#include <ros/ros.h>
#include "point.hpp"

//motion_operator


//ebimu_v5
#include <msg_generate/imu_msg.h>

//vision
#include <msg_generate/robocup_vision23.h>
#include <msg_generate/master_2_robocup_vision23.h>

//localization_v2
#include <msg_generate/robocup_localization24_obstacle.h>
#include <msg_generate/master2localization23.h>

//ikwalk
#include <msg_generate/ik_msg.h>
#include <msg_generate/ikend_msg.h>

//serial_mcu
#include <msg_generate/motionNum_msg.h>
#include <msg_generate/motion_end.h>

//udp_com
#include <msg_generate/robocup24_master2udp.h>
#include <msg_generate/localv2_msg.h>

//gamecontroller
#include <msg_generate/game_control_data.h>
#include <msg_generate/game_control_return_data.h>
#include "RoboCupGameControlData.h"

//pid
#include <msg_generate/pid_tuning.h>

//collabolocal
#include <msg_generate/udp_helper_msg.h>
#include <msg_generate/udp_kicker_msg.h>

//obstacle_navigation
#include <msg_generate/HSV.h>
#include <msg_generate/master2localization23_technical_obstacle.h>

#define POSITION    0
#define POSITION_GK 1
#define POSITION_FW 2
#define TECHNICAL   3

//technical -> state technical gamecontroldata.h
#define STATE_CL_K 1
#define STATE_CL_H 2
#define STATE_DK 3
#define STATE_PK 4
#define STATE_HK 5
#define STATE_OB 6


#define VISION_SAVE_CAMERA_B  -1
#define VISION_SAVE_CAMERA_F  -2
#define VISION_SCAN_MODE_INIT   0
#define VISION_SCAN_MODE_BALL   2
#define VISION_SCAN_MODE_LINE   3
#define VISION_SCAN_MODE_CNTR   4

namespace robocup_master23 {

class MasterRcko
{
public:
    MasterRcko(int argc, char** argv);
    bool init();

    ros::Subscriber imuSub;
    ros::Subscriber localSub;
    ros::Publisher  localPub;
    ros::Subscriber visionSub;
    ros::Publisher  visionPub;
    ros::Subscriber ikSub;
    ros::Publisher  ikPub;
    ros::Subscriber motionSub;
    ros::Publisher  motionPub;
    ros::Subscriber udpR1Sub;
    ros::Subscriber udpR2Sub;
    ros::Subscriber udpR3Sub;
    ros::Publisher  udpPub;
    ros::Subscriber gamecontrolSub;
    ros::Publisher  gamecontrolPub;
    ros::Subscriber pidSub;
    ros::Subscriber hsvSub;
    ros::Publisher obsPub;

    //collabolocal
    ros::Subscriber udp2helperdata;
    ros::Subscriber udp2kickerdata;

    ros::Publisher helper2udp;
    ros::Publisher kicker2udp;

    msg_generate::imu_msg imu;
//    msg_generate::localv2_msg local;
    msg_generate::robocup_localization24_obstacle local;
    msg_generate::master2localization23 master2local;
    msg_generate::robocup_vision23 vision;
    msg_generate::master_2_robocup_vision23 master2vision;
    msg_generate::ik_msg ik;
    msg_generate::ikend_msg ikEnd;
    msg_generate::motionNum_msg motion;
    msg_generate::motion_end motionEnd;
    msg_generate::localv2_msg udp[4];
    msg_generate::robocup24_master2udp master2udp;
    msg_generate::game_control_data gameControlData;
    msg_generate::game_control_return_data gameControlReturnData;
    msg_generate::pid_tuning pid;
    msg_generate::HSV hsv;
    msg_generate::master2localization23_technical_obstacle obs;

    //collabolocal
    msg_generate::udp_helper_msg udp_Helper_msg;
    msg_generate::udp_kicker_msg udp_Kicker_msg;

private:
    int init_argc;
    char** init_argv;

    void imuCallback(const msg_generate::imu_msg::ConstPtr &msg);
    void localCallback(const msg_generate::robocup_localization24_obstacle::ConstPtr &msg);
    void visionCallback(const msg_generate::robocup_vision23::ConstPtr &msg);
    void ikCallback(const msg_generate::ikend_msg::ConstPtr &msg);
    void motionCallback(const msg_generate::motion_end::ConstPtr &msg);
    void udpCallback(const msg_generate::localv2_msg::ConstPtr &msg);
    void gameCallback(const msg_generate::game_control_data::ConstPtr &msg);
    void pidCallback(const msg_generate::pid_tuning::ConstPtr &msg);

    void helperdataCallback(const msg_generate::udp_helper_msg::ConstPtr &msg);
    void kickerdataCallback(const msg_generate::udp_kicker_msg::ConstPtr &msg);
    void hsvCallback(const msg_generate::HSV::ConstPtr &msg);
public:
    void collabo_helper_publish(const msg_generate::udp_helper_msg msg);
    void collabo_kicker_publish(const msg_generate::udp_kicker_msg msg);
    void obsPublish(const msg_generate::master2localization23_technical_obstacle msg);
};

} //robocup_master23

#endif //MASTER_RICO_HPP
