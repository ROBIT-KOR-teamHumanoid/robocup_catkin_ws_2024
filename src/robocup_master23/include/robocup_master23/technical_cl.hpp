#ifndef TECHNICAL_CL_HPP
#define TECHNICAL_CL_HPP

#include "player.hpp"

namespace robocup_master23 {


                                        // HELPER | //KICKER
//#define MODE_TEST           1                //testmode
//#define MODE_FINDBALL       2//
//#define MODE_GOTOBALL       3//
//#define MODE_KICK           4//
//#define MODE_STANDBY        5//
//#define MODE_END            6//
//#define MODE_SIDE           7//
#define READY            1              //testmode
#define MOVE       2//
#define KICK       3//
//#define MODE_KICK           4//
//#define MODE_STANDBY        5//
//#define MODE_END            6//
//#define MODE_SIDE           7//



class TECHNICAL_CL_K : public Player
{
public:
    TECHNICAL_CL_K(MasterRcko *master);



    void statePlay();
    int Kicker_case = READY;
    void stateInitial(){};
    void stateReady(){};
    void stateReady(Point init_coor){};

    float  robot_yaw  = master->imu.yaw;

    double robotx       = 480;//만약 로봇이 안 보였을 때를 대비하여 만들어 놓았다. kicker robot 시작 위치
    double roboty       = 400;
    int ribotyaw = 0;
    int ballx = 0;
    int bally = 0;

    int Kick_cnt        = 0;
    int kick_check_cnt  = 0;
    int moveOkCnt       = 0;//도착 확인 정확도를 위한 cnt
    bool kickOK         = false;
    bool yawCali        = false;
    bool YawOk          = false;

        //UDP
    msg_generate::udp_helper_msg orderedInfo;
    msg_generate::udp_kicker_msg mystate;
//    _udp_msg_Helper orderedInfo;

    //filter
    double filterx = 0;
    double filtery = 0;
    double filterparam = 0.1;


    Point calcShootPoint(Point goal_coor, Point ball_coor);
    void kick3();
    bool caliToBall();
    bool TargetYaw(float robot_yaw, float target_yaw,int z);

    void kick_yun(Point ball_loc, Point robot_loc);
    void kick_odo();
    bool caliToball_yun();
    bool go2target_yun();



};

class TECHNICAL_CL_H : public Player
{
public:
    TECHNICAL_CL_H(MasterRcko *master);

    void statePlay();

    void stateInitial(){};
    void stateReady(){};
    void stateReady(Point init_coor){};

    int mode = READY;

    //masters

//    double robotx     = master->local.Robot_X;
//    double roboty     = master->local.Robot_Y;
//    int goflag = 0;
//    int goalx = 0; int goaly = 0;


 bool TargetYaw(float robot_yaw, float target_yaw,int z);

    //
   msg_generate::udp_helper_msg orderInfo;
   msg_generate::udp_kicker_msg kickerstate;

   int ballOk = 0;
    int ii = 0;

};


}//namespace robocup_master23



#endif // TECHNICAL_CL_HPP
