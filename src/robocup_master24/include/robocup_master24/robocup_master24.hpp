#ifndef MASTER_RICO_HPP
#define MASTER_RICO_HPP

#include "/home/robit/catkin_ws/src/robot_config.h"

#include <ros/ros.h>
#include "point.hpp"
#include <ros/param.h>
#include <vector>
#include <string>


//ebimu_v5
#include <msg_generate/imu_msg.h>

//vision
#include <msg_generate/robocup_vision24.h>
#include <msg_generate/master_2_robocup_vision24.h>

//localization_v2
#include <msg_generate/robocup_localization24.h>
#include <msg_generate/master2localization24.h>

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

#define POSITION    0
#define POSITION_GK 1
#define POSITION_FW 2

#define VISION_SAVE_CAMERA_B  -1
#define VISION_SAVE_CAMERA_F  -2
#define VISION_SCAN_MODE_INIT   0
#define VISION_SCAN_MODE_BALL   2
#define VISION_SCAN_MODE_LINE   3
#define VISION_SCAN_MODE_CNTR   4

namespace robocup_master24 {

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

    msg_generate::imu_msg imu;
//    msg_generate::localv2_msg local;
    msg_generate::robocup_localization24 local;
    msg_generate::master2localization24 master2local;
    msg_generate::robocup_vision24 vision;
    msg_generate::master_2_robocup_vision24 master2vision;
    msg_generate::ik_msg ik;
    msg_generate::ikend_msg ikEnd;
    msg_generate::motionNum_msg motion;
    msg_generate::motion_end motionEnd;
    msg_generate::localv2_msg udp[4];
    msg_generate::robocup24_master2udp master2udp;
    msg_generate::game_control_data gameControlData;
    msg_generate::game_control_return_data gameControlReturnData;
    msg_generate::pid_tuning pid;


    void paramCallback(const ros::TimerEvent& );
    ros::Timer timer;
    double kp;
    double kd;
    double ki;


    //walk limit
    int FRONT_MAX;
    int X_MIN;
    int REAR_MAX;
    int RIGHT_MAX;
    int Y_MIN;
    int ROUND_Y;
    int ROUND_YAW_MIN;
    int LEFT_MAX;
    int R_YAW_MAX;
    int L_YAW_MAX;


private:
    int init_argc;
    char** init_argv;

    void imuCallback(const msg_generate::imu_msg::ConstPtr &msg);
    void localCallback(const msg_generate::robocup_localization24::ConstPtr &msg);
    void visionCallback(const msg_generate::robocup_vision24::ConstPtr &msg);
    void ikCallback(const msg_generate::ikend_msg::ConstPtr &msg);
    void motionCallback(const msg_generate::motion_end::ConstPtr &msg);
    void udpCallback(const msg_generate::localv2_msg::ConstPtr &msg);
    void gameCallback(const msg_generate::game_control_data::ConstPtr &msg);
    void pidCallback(const msg_generate::pid_tuning::ConstPtr &msg);
};

} //robocup_master24

#endif //MASTER_RICO_HPP
