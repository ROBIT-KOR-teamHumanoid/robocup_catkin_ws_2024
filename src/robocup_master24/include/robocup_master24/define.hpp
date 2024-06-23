#ifndef DEFINE_HPP
#define DEFINE_HPP

#define MAX_ROBOT_NUM   4

#define MOTION_RASEUP_FRONT 0x01
#define MOTION_RASEUP_REAR  0x02
#define MOTION_RASEUP_RIGHT 0x03
#define MOTION_RASEUP_LEFT  0x04
#define MOTION_KICK_FRONT_R 0x05
#define MOTION_KICK_FRONT_L 0x06
#define MOTION_KICK_SIDE_R  0x07
#define MOTION_KICK_SIDE_L  0x08
//true save motion (without first init)
#define MOTION_ARM_LEFT     0x09
#define MOTION_ARM_RIGHT    0X10
#define MOTION_ARM_CENTER   0X11



//fall down
#define NOT_FALLDOWN    0
#define FALLDOWN        1
#define FALLDOWN_FRONT  2
#define FALLDOWN_REAR   3
#define FALLDOWN_RIGHT  4
#define FALLDOWN_LEFT   5

//my side
#define LEFT        0
#define RIGHT       1

//target object
#define BALL        0
#define COORDINATE  1

//angle mode
#define OPPONENT    0
#define ABSOLUTE    1
#define RELATIVE    2

//kick mode
#define NONE        0
#define FRONT_KICK  1
#define FRONT_RIGHT 2
#define FRONT_LEFT  3
#define SIDE_KICK   4
#define SIDE_RIGHT  5
#define SIDE_LEFT   6

//robot state
#define ROBOT_STATE_NONE        0
#define ROBOT_STATE_NOBALL      1
#define ROBOT_STATE_SUPPORT     2
#define ROBOT_STATE_CONTROLL    3
#define ROBOT_STATE_ATTACK      4
#define ROBOT_STATE_DEFENCE     5
#define ROBOT_STATE_PICKUP      6

#define KEEPER_STATE_KEEPERZONE 2
#define KEEPER_STATE_CENTER     3
#define NORMAL                  4
#define KEEPER_STATE_QUICK_BACK 5

#endif //DEFINE_HPP
