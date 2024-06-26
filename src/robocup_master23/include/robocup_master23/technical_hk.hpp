#ifndef TECHNICAL_HK_HPP
#define TECHNICAL_HK_HPP

#include "player.hpp"

namespace robocup_master23 {

#define MODE_IDLE           1
#define MODE_BALL_WALK      2
#define MODE_KICK           3
#define MODE_STOP           4


#define MOTION_SLIDEKICK    0x25
#define MOTION_HIGHKICK     0x26

class TECHNICAL_HK :public Player
{
public:
    TECHNICAL_HK(MasterRcko *master);

    void statePlay();


    void stateInitial(){};
    void stateReady(){};
    void stateSet(){};
    void stateFinished(){};

    int highkick_case = 1;

    int slide_check = 0;

    int moveOkCnt = 0;
    int ball_check = 0;
    int mode_fix = 0;

    bool moveToTarget(Point current_coordinates, double current_yaw, Point target_coordinates, int angle_mode, double target_angle, bool dontStop = false);

    bool TargetYaw(float robot_yaw, float target_yaw,int z);
    bool TargetYaw2(float robot_yaw, float target_yaw,int z);

};
}



#endif // TECHNICAL_HK_HPP
