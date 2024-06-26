#ifndef TECHNICAL_PK_HPP
#define TECHNICAL_PK_HPP

#include "player.hpp"

namespace robocup_master23 {

#define MODE_IDLE           0
#define MODE_PARKOUR        1
#define MODE_MOTION         2
#define MODE_STOP           3

class TECHNICAL_PK : public Player
{
public:
    TECHNICAL_PK(MasterRcko *master);
    void statePlay();

    void stateInitial(){};
    void stateReady(){};
    void stateReady(Point init_coor){};

    int parkour_mode=0;

};

}

#endif // TECHNICAL_PK_HPP
