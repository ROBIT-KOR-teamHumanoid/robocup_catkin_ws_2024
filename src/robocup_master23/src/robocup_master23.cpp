#include "../include/robocup_master23/robocup_master23.hpp"
#include "../include/robocup_master23/player.hpp"
#include "../include/robocup_master23/goalkeeper.hpp"

namespace robocup_master23 {

using namespace std;

MasterRcko::MasterRcko(int argc, char **argv) :
    init_argc(argc),
    init_argv(argv)
{}

bool MasterRcko::init()
{
    ros::init(init_argc, init_argv, "robocup_master23");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;

    //ROS TOPIC=====================================================================
    imuSub          = n.subscribe("imu", 100, &MasterRcko::imuCallback, this);
    localSub        = n.subscribe("robocup_localization24_obstacle",100, &MasterRcko::localCallback, this);
    localPub        = n.advertise<msg_generate::master2localization23>("master2localization23", 100);
    visionSub       = n.subscribe("robocup_vision23",100, &MasterRcko::visionCallback, this);
    visionPub       = n.advertise<msg_generate::master_2_robocup_vision23>("master_2_robocup_vision23", 100);
    ikSub           = n.subscribe("ikend", 100, &MasterRcko::ikCallback, this);
    ikPub           = n.advertise<msg_generate::ik_msg>("master2ik", 100);
    motionSub       = n.subscribe("motion_end", 100, &MasterRcko::motionCallback, this);
    motionPub       = n.advertise<msg_generate::motionNum_msg>("Motion", 100);
    udpR1Sub        = n.subscribe("udp_RB1", 100, &MasterRcko::udpCallback, this);
    udpR2Sub        = n.subscribe("udp_RB2", 100, &MasterRcko::udpCallback, this);
    udpR3Sub        = n.subscribe("udp_RB3", 100, &MasterRcko::udpCallback, this);
    udpPub          = n.advertise<msg_generate::robocup24_master2udp>("robocup24_master2udp", 100);
    gamecontrolSub  = n.subscribe("gamecontroller", 100, &MasterRcko::gameCallback, this);
    pidSub          = n.subscribe("pid", 100, &MasterRcko::pidCallback, this);
    hsvSub          = n.subscribe("hsv", 100, &MasterRcko::hsvCallback, this);
    obsPub          = n.advertise<msg_generate::master2localization23_technical_obstacle>("obs", 100);
    //collabo topic
        //(SUB)
        udp2helperdata = n.subscribe("Hudp2master", 100, &MasterRcko::helperdataCallback, this);
        udp2kickerdata = n.subscribe("Kudp2master", 100, &MasterRcko::kickerdataCallback, this);
        //(pub)
        helper2udp = n.advertise<msg_generate::udp_helper_msg>("master2Hudp", 100);// master data(helper)-> helper udp
        kicker2udp = n.advertise<msg_generate::udp_kicker_msg>("master2Kudp", 100);// master data(kicker)-> kicker udp

//    pathPub= n.advertise<msg_generate::master2path_msg>("master2path", 100);
    return true;
}

void MasterRcko::imuCallback(const msg_generate::imu_msg::ConstPtr &msg)
{
    imu.pitch           = msg->pitch;
    imu.roll            = msg->roll;
    imu.yaw             = msg->yaw;
}

void MasterRcko::localCallback(const msg_generate::robocup_localization24_obstacle::ConstPtr &msg)
{
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

void MasterRcko::hsvCallback(const msg_generate::HSV::ConstPtr &msg)
{
    hsv.red1_dis        = msg->red1_dis;
    hsv.red1_the        = msg->red1_the;
    hsv.red2_dis        = msg->red2_dis;
    hsv.red2_the        = msg->red2_the;
    hsv.blue1_dis       = msg->blue1_dis;
    hsv.blue1_the       = msg->blue1_the;
    hsv.blue2_dis       = msg->blue2_dis;
    hsv.blue2_the       = msg->blue2_the;
}

void MasterRcko::visionCallback(const msg_generate::robocup_vision23::ConstPtr &msg)
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

void MasterRcko::ikCallback(const msg_generate::ikend_msg::ConstPtr &msg)
{
    ikEnd.ikend         = msg->ikend;
}

void MasterRcko::motionCallback(const msg_generate::motion_end::ConstPtr &msg)
{
    motionEnd.motion_end = msg->motion_end;
    //motion.Motion_Num = msg->motion_num; //tw
}

void MasterRcko::udpCallback(const msg_generate::localv2_msg::ConstPtr &msg)
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

void MasterRcko::gameCallback(const msg_generate::game_control_data::ConstPtr &msg)
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

    cout<<"gameControlData.penalty : "<<gameControlData.penalty<<endl;
    cout<<"gameControlData.state : "<<gameControlData.state<<endl;
}

void MasterRcko::pidCallback(const msg_generate::pid_tuning::ConstPtr &msg)
{
    pid.Kp = msg->Kp;
    pid.Ki = msg->Ki;
    pid.Kd = msg->Kd;
}

void MasterRcko::helperdataCallback(const msg_generate::udp_helper_msg::ConstPtr &msg){


    udp_Helper_msg.robot_num            = msg->robot_num;
    udp_Helper_msg.robot_case           = msg->robot_case;

    udp_Helper_msg.robot_x_order        = msg->robot_x_order;
    udp_Helper_msg.robot_y_order        = msg->robot_y_order;

    udp_Helper_msg.robot_ik_x_order     = msg->robot_ik_x_order;
    udp_Helper_msg.robot_ik_y_order     = msg->robot_ik_y_order;
    udp_Helper_msg.robot_ik_yaw_order   = msg->robot_ik_yaw_order;

    udp_Helper_msg.ball_x               = msg->ball_x;
    udp_Helper_msg.ball_y               = msg->ball_y;
    udp_Helper_msg.ballDist             = msg->ballDist;
    udp_Helper_msg.ballTheta            = msg->ballTheta;

    cout<<"oooook"<<endl;


}
void MasterRcko::kickerdataCallback(const msg_generate::udp_kicker_msg::ConstPtr &msg){

    udp_Kicker_msg.robot_num            = msg->robot_num;
    udp_Kicker_msg.robot_case           = msg->robot_case;

    udp_Kicker_msg.local_x              = msg->local_x;
    udp_Kicker_msg.local_y              = msg->local_y;
    udp_Kicker_msg.local_yaw            = msg->local_yaw;
    cout<<"noooo"<<endl;
}

void MasterRcko::collabo_helper_publish(const msg_generate::udp_helper_msg msg){//helper order



    helper2udp.publish(msg);
    //helper2udp.publish(udp_Helper_msg);
}
void MasterRcko::collabo_kicker_publish(const msg_generate::udp_kicker_msg msg){//kicker state

    //kicker2udp.publish(udp_Kicker_msg);

    kicker2udp.publish(msg);
}

void MasterRcko::obsPublish(const msg_generate::master2localization23_technical_obstacle msg)
{


    obsPub.publish(msg);
}

} //namespace robocup_master23

