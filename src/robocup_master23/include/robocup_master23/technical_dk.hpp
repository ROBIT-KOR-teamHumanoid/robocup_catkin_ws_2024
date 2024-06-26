#ifndef TECHNICAL_DK_HPP
#define TECHNICAL_DK_HPP

#include "player.hpp"

namespace robocup_master23 {

#define MODE_TEST           1
#define MODE_WAIT           2
#define MODE_FAR_BALL       3
#define MODE_KICK           4
#define MODE_END            5


#define MOTION_FAIL         8
#define MOTION_READY        9
#define MOTION_KICK         10

//tuning
#define first_cam_Y         93 //38->108
#define first_cam_min_X     400 //424->400
#define first_cam_max_X     512 //470->432->484->506->508->512
//#define first_loc_Y       235
//#define first_loc_min_X   135
//#define first_loc_max_X   170

#define second_cam_Y        143 //95
#define second_cam_min_X    358 //383->375->378->355
#define second_cam_max_X    495 //450->470->415->465->470->490->495
//#define second_loc_Y      290//300
//#define second_loc_min_X  175
//#define second_loc_max_X  200

class TECHNICAL_DK_K : public Player
{
public:
    TECHNICAL_DK_K(MasterRcko* master);
    void statePlay();


    void stateInitial(){};
    void stateReady(){};
    void stateReady(Point init_coor){};

    int stop_cnt = 0;
    int kick_cnt = 0;
    int kick_delay = 0;
    double kick_time = 0;
    bool test = true;
    int kickyn = 1;
    int ready_mode = 0;
    int kick_mode = 0;
    int ball_state = 0;
    int fail_mode = 0;
    int p1balltime = 0;
    int p2balltime = 0;
    int temp_time_dk = 0;
    double p1p2d = 0;
    double temp_bv = 0;
    double temp_rp = 0;

    int p1x=0; int p1y=0;
    int p2x=0; int p2y=0;

    int mode_stop_cnt = 0;

    double paninit = (-40 * 4096) / 360; // -40 -> 40

    int Kicker_case = 1;

//    double robot_yaw  = master->imu.yaw;
//    double speedx     = master->local.Ball_speed_X; //있을 예정 좌표
//    double speedy     = master->local.Ball_speed_Y; //
//    double robotx     = master->local.Robot_X;
//    double roboty     = master->local.Robot_Y;
//    double ballcamx   = master->vision.Ball_cam_X;  //카메라기준 좌표
//    double ballcamy   = master->vision.Ball_cam_Y;
//    double ballx      = master->local.Ball_X;       //local
//    double bally      = master->local.Ball_Y;       //local
//    double ball2dx    = master->vision.Ball_2d_X;   //로봇기준
//    double ball2dy    = master->vision.Ball_2d_Y;   //로봇기준
    double balld      = master->vision.Ball_D;      //카메라랑 볼 사이 거리
    double pan       = master->vision.PAN;

    double BallSpeed();
    void PRINTDKINFO();
    void PRINTFAILINFO(int i);

};

}

#endif // TECHNICAL_DK_HPP
