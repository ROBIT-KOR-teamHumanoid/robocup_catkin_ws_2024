#ifndef TECHNICAL_OB_HPP
#define TECHNICAL_OB_HPP

//obstacle_state : 노드의 전반적인 상태
#define OBSTACLE_READY 0
#define OBSTACLE_START 1

//start_state : 시작 후 상태
#define OBSTACLE_START_N 0
#define OBSTACLE_START_O 1
#define OBSTACLE_START_T 2
#define OBSTACLE_START_L 3
#define OBSTACLE_START_A 4

//color_state : 색상 상태
#define NONE_COLOR 0
#define RED 1
#define BLUE 2

//위치 상태
#define NONE -1
#define LEFT_OB 1
#define CENTER_OB 3
#define RIGHT_OB 2

//sector : 현재 진행 단계
#define SECTOR1     1
#define SECTOR2     2
#define SECTOR3     3
#define SECTOR4     4



#include "player.hpp"

namespace robocup_master23 {

class TECHNICAL_OB : public Player
{
public:
    TECHNICAL_OB(MasterRcko *master);
    void statePlay();

    msg_generate::master2localization23_technical_obstacle obs;


    //L값은 장애물 좌측값, R값은 장애물 우측값, 장애물이 하나만 인식되면 L에만 저장되고 R에는 저장 안됨
    int red_Lthe = 0, red_Rthe = 0;
    int blue_Lthe = 0, blue_Rthe = 0;

    int distL = 0, distR = 0;

    //TWO OBSTACLE MODE시 제어값
    int theta1 = 10 - master->imu.yaw;
    int theta2 = 20 - master->imu.yaw;


    //ONE OBSTACLE MODE시 제어값
    int theta3 = 15 - master->imu.yaw;
    int theta4 = 25 - master->imu.yaw;

    //avoidence
    int theta_a1 = 13;
    int theta_a2 = 23;


    //사전 입력된 장애물 및 로봇 이동위치 -- 현장 디버깅때 위치가 다르다면 꼭 수정해야함!!!
    int localX[3] = {587, 625, 663};
    int localY[3] = {540, 390, 240};
    int tem_point_x = 0;
    int tem_point_y = 0;

    void stateInitial(){};
    void stateReady(){}
    void stateReady(Point init_coor){};

    //flag
    bool color_select_flag = false;
    bool one_ob_flag = false;
    bool last_flag = false;
    bool error_flag = false;
    bool emergency_flag = false;
    bool holdon_flag = false;
    bool avoidance_flag = false;

    //state
    int technical_state = OBSTACLE_READY;
    int start_state = OBSTACLE_START_N;
    int obstacle1_state = NONE;
    int obstacle2_state = NONE;
    int robot_standing_state = CENTER_OB;
    int robot_next_standing_state = NONE;
    int color_state = NONE_COLOR;
    int sector_state = SECTOR1;
    int sector_state_tem = SECTOR1;

    //input
    int start_input = 0;
    int color_input = 0;

    //function
    void print_state();
    void calc_robotstanding();
    int calc_destination();
    int calc_startstate();
    int calc_sector();
    void change_robot_standing();
    bool calc_sector_change();
    bool calc_emergency();
    bool calc_avoidance();
    void calc_localerror();
    void obstaclemove(int sector, int way);
    void obstacleerror(int sector);
    void errormove(int sector, int way);
    bool move2point(Point targetPoint);

    void sort_theta();

};

}

#endif // TECHNICAL_OB_HPP
