//GK Version 1.5

#ifndef GOALKEEPER_HPP
#define GOALKEEPER_HPP

#include "player.hpp"
#include <cmath>

//Playing Mode Define
#define MODE_Penalty            6
#define MODE_TEST               7

#define Just_My_Ball        0
#define Judging_Ball_D      1
#define three_back          2
//Team define
#define RED                 true
#define BLUE                false

namespace robocup_master23 {

class Goalkeeper : public Player
{
public:
    Goalkeeper(MasterRcko *master);
    void selectRobotState();

private:
    void stateInitial();
    void stateReady();
    void stateSet();
    void statePlay();
    void stateFinished();

    //keeper value;
    const int goalOffset    = 65; //cm

    //35
    const int frontOffset   = 120; //cm
    bool dribble = false;
    int targetyaw;
    double gkbs;
    bool qb = false;
    Point homePoint;
    //Normal TypeFunction
    bool moveSideOnly(Point targetPoint);
    int PenaltySave();
    int playSaveMotion();
    void directionprt(int errorx);
    void gksave();
    bool TargetYaw(float robot_yaw, float target_yaw,int z);

};

} // namespace robocup_master23


#endif //GOALKEEPER_HPP
