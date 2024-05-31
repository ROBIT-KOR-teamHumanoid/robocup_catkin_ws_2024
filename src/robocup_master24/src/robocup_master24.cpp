#include "../include/robocup_master24/robocup_master24.hpp"
#include "../include/robocup_master24/player.hpp"
#include "../include/robocup_master24/goalkeeper.hpp"

#include <ros/ros.h>
#include <yaml-cpp/yaml.h>
namespace robocup_master24 {

using namespace std;

MasterRcko::MasterRcko(int argc, char **argv) :
  init_argc(argc),
  init_argv(argv)
{}

bool MasterRcko::init()
{
  ros::init(init_argc, init_argv, "robocup_master24");
  if ( ! ros::master::check() ) {
    return false;
  }

  ros::start(); // explicitly needed since our nodehandle is going out of scope.

  ros::NodeHandle n;
  ros::Time::init();
  timer = n.createTimer(ros::Duration(0.1), &MasterRcko::paramCallback,this);

  //ROS TOPIC=====================================================================
  imuSub          = n.subscribe("imu", 100, &MasterRcko::imuCallback, this);
  localSub        = n.subscribe("robocup_localization23",100, &MasterRcko::localCallback, this);
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
  udpPub          = n.advertise<msg_generate::robocup23_master2udp>("robocup23_master2udp", 100);
  gamecontrolSub  = n.subscribe("gamecontroller", 100, &MasterRcko::gameCallback, this);
  pidSub          = n.subscribe("pid", 100, &MasterRcko::pidCallback, this);

  //    pathPub= n.advertise<msg_generate::master2path_msg>("master2path", 100);
  return true;
}


void MasterRcko::paramCallback(const ros::TimerEvent& )
{


  ros::NodeHandle nh;
  string robot_Kd = "/robot" + to_string(ROBOTNUM)+"/Kd";
  string robot_Ki = "/robot" + to_string(ROBOTNUM)+"/Ki";
  string robot_Kp = "/robot" + to_string(ROBOTNUM)+"/Kp";


  nh.getParam(robot_Kd,kd);
  nh.getParam(robot_Ki,ki);
  nh.getParam(robot_Kp,kp);


  cout<<kd<<endl;
  cout<<kp<<endl;
  cout<<ki<<endl;






}

void MasterRcko::imuCallback(const msg_generate::imu_msg::ConstPtr &msg)
{

  imu.pitch           = msg->pitch;
  imu.roll            = msg->roll;
  imu.yaw             = msg->yaw;
}

void MasterRcko::localCallback(const msg_generate::robocup_localization23::ConstPtr &msg)
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

} //namespace robocup_master24

