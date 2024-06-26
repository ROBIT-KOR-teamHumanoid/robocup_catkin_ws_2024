#include "robocup_master23/technical_ob.hpp"

#define REG2(X, MIN, MAX) (X - MIN) / (MAX - MIN)

namespace robocup_master23
{

using namespace std;

TECHNICAL_OB::TECHNICAL_OB(MasterRcko *master) :
    Player(master)
{
    cout << endl << "TECHNICAL_OB!!" << endl << endl;
}

void TECHNICAL_OB::statePlay()
{

    switch (technical_state) {
    case OBSTACLE_READY:
    {
        if(color_select_flag == false)
        {
            if(master->hsv.red1_dis != -999 && master->hsv.red2_dis != -999){color_state = RED; cout << "RED IS SELECTED COLOR"<< endl;}
            else if(master->hsv.blue1_dis != -999 && master->hsv.blue2_dis != -999){color_state = BLUE; cout << "BLUE IS SELECTED COLOR"<< endl;}
            else
            {
                color_state = NONE_COLOR;
                cout << "!!!!!!!!!!!!       COLOR IS NOT SELECTED, CHECK HSV SETTING        !!!!!!!!!!!!" << endl;
            }
            cout << "IF YOU WANT COLOR RESELECT, PRESS 0 IF YOU WANT THIS COLOR, PRESS 1" << endl;
            cin >> color_input;
            if(color_input == 1) color_select_flag = true;
        }
        else
        {
            cout << "ENTER 1 WHEN START ROBOT" << endl;
            cin >> start_input;
            if(start_input == 1){technical_state = OBSTACLE_START;}
            else{cout << "ENTER 1 IF YOU WANT START" << endl;}
        }

        break;
    }
    case OBSTACLE_START:
    {
        sort_theta(); //hsv로 받는 theta값 정렬 및 현재 상황 판단
        sector_state = calc_sector(); //현재 섹터 판단
        calc_robotstanding(); //로봇의 좌 중 우 위치 판단
        if(calc_sector_change()){change_robot_standing(); holdon_flag = false;} //섹터 변경시 초기화
        if(!holdon_flag)
        {
            start_state = calc_startstate(); //판단된 상황에 따라 start state 변환
            robot_next_standing_state = calc_destination(); //theta값 및 start state에 따라 목적지 설정
        }
        emergency_flag = calc_emergency(); //맵 밖으로 나가는 긴급상황 판단 && HSV 인식 못하는 상황 판단

        if(calc_avoidance()){start_state = OBSTACLE_START_A;}


        obs.obs_1 = obstacle1_state;
        obs.obs_2 = obstacle2_state;
        obs.sector = sector_state;

        master->obsPublish(obs);

        if(emergency_flag){start_state = OBSTACLE_START_N;}

        print_state();



        switch (start_state) {
        case OBSTACLE_START_N:
        {
            cout << "START 'ERROR CONTROLL' MODE !!!"<< endl;
            obstacleerror(sector_state);
            break;
        }
        case OBSTACLE_START_O:
        {
            cout << "START 'ONE OBSTACLE' MODE !!!"<< endl;

            obstaclemove(sector_state, robot_next_standing_state);
            break;
        }
        case OBSTACLE_START_T:
        {
            cout << "START 'TWO OBSTACLE' MODE !!!"<< endl;

            obstaclemove(sector_state, robot_next_standing_state);
            break;
        }
        case OBSTACLE_START_L:
        {
            cout << "START 'LAST RUNNING' MODE !!!"<< endl;
            move2point(Point(625, 100));
            break;
        }
        case OBSTACLE_START_A:
        {
            cout << "START 'AVOIDANCE RUNNING' MODE !!!" << endl;
            move2point(Point(master->local.Robot_X, master->local.Robot_Y + 10));
            break;
        }
        default:
        {
            for(int i = 0 ; i < 100 ; i++) cout << "!!!!!!!!!!!!!!!!!!!!       ?       !!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }
        }
        break;
    }
    default:
        cout << "?" << endl;
        ros::shutdown();
        break;

    }
}

void TECHNICAL_OB::sort_theta()
{
    //theta값은 오른쪽으로 갈수록 작아짐 !!!!!

    last_flag = false;
    one_ob_flag = false;
    error_flag = false;

    if(color_state == RED)
    {
        if(master->hsv.red1_dis == -999 && master->hsv.red2_dis != -999)
        {
            one_ob_flag = true;
            last_flag = false;
            error_flag = false;

            red_Lthe = master->hsv.red1_the; red_Rthe = -999;
            distL = master->hsv.red1_dis; distR = -999;
            return;
        }
        else if(master->hsv.red1_dis == -999 && master->hsv.red2_dis == -999)
        {
            one_ob_flag = false;
            last_flag = true;
            error_flag = false;

            red_Lthe = -999; red_Rthe = -999;
            distL = -999; distR = -999;

            return;
        }
        else
        {
            last_flag = false;
            one_ob_flag = false;
            error_flag = false;

            if(master->hsv.red1_the < master->hsv.red2_the)
            {
                red_Rthe = master->hsv.red1_the; red_Lthe = master->hsv.red2_the;
                distR = master->hsv.red1_dis; distL = master->hsv.red2_dis;
            }
            else
            {
                red_Rthe = master->hsv.red2_the; red_Lthe = master->hsv.red1_the;
                distR = master->hsv.red2_dis; distL = master->hsv.red1_dis;
            }

            return;
        }
    }
    else if(color_state == BLUE)
    {
        if((master->hsv.blue1_dis == -999 && master->hsv.blue2_dis != -999) || (master->hsv.blue1_dis != -999 && master->hsv.blue2_dis == -999))
        {
            one_ob_flag = true;
            last_flag = false;
            error_flag = false;

            blue_Lthe = master->hsv.blue1_the; blue_Rthe = -999;
            distL = master->hsv.blue1_dis; distR = -999;
            return;
        }
        else if(master->hsv.blue1_dis == -999 && master->hsv.blue2_dis == -999)
        {
            one_ob_flag = false;
            last_flag = true;
            error_flag = false;

            blue_Lthe = -999; blue_Rthe = -999;
            distL = -999; distR = -999;

            return;
        }
        else
        {
            last_flag = false;
            one_ob_flag = false;
            error_flag = false;

            if(master->hsv.blue1_the < master->hsv.blue2_the)
            {
                blue_Rthe = master->hsv.blue1_the; blue_Lthe = master->hsv.blue2_the;
                distR = master->hsv.blue1_dis; distL = master->hsv.blue2_dis;
            }
            else
            {
                blue_Rthe = master->hsv.blue2_the; blue_Lthe = master->hsv.blue1_the;
                distR = master->hsv.blue2_dis; distL = master->hsv.blue1_dis;
            }
            return;
        }
    }

    //애초에 HSV 색상이 선택되지 않았으면 해당 문구 발생
    error_flag = true;
    for(int i = 0 ; i < 100 ; i++) cout << "!!!!!!!!!!!!!!!!!!!!       HSV ERROR       !!!!!!!!!!!!!!!!!!!!" << endl;

}

void TECHNICAL_OB::calc_robotstanding()
{
    if(master->local.Robot_X > 550 && master->local.Robot_X < 600){robot_standing_state = LEFT_OB;}
    else if(master->local.Robot_X > 600 && master->local.Robot_X < 650){robot_standing_state = CENTER_OB;}
    else if(master->local.Robot_X > 650 && master->local.Robot_X < 700){robot_standing_state = RIGHT_OB;}
}

int TECHNICAL_OB::calc_sector()
{
    if(master->local.Robot_Y <= 700 && master->local.Robot_Y >550){return SECTOR1;}
    else if(master->local.Robot_Y <= 550 && master->local.Robot_Y >400){return SECTOR2;}
    else if(master->local.Robot_Y <= 400 && master->local.Robot_Y >250){return SECTOR3;}
    else if(master->local.Robot_Y <= 250 && master->local.Robot_Y >100){return SECTOR4;}
}

int TECHNICAL_OB::calc_startstate()
{
    if(one_ob_flag == true){return OBSTACLE_START_O;}
    if(last_flag == true && sector_state == SECTOR4){return OBSTACLE_START_L;}
    if(error_flag == true || (last_flag == true && sector_state != SECTOR4)){return OBSTACLE_START_N;}
    return OBSTACLE_START_T;
}

int TECHNICAL_OB::calc_destination()
{
    int ob_L = NONE; int ob_R = NONE;

    if(start_state == OBSTACLE_START_T)
    {
        if(color_state == RED)
        {
            if(robot_standing_state == CENTER_OB)
            {
                if(red_Lthe > theta1){ob_L = LEFT_OB;}
                else{ob_L = CENTER_OB;}

                if(red_Rthe < -theta1){ob_R = RIGHT_OB;}
                else{ob_R = CENTER_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = LEFT_OB;
                    ob_R = RIGHT_OB;
                }
            }
            else if(robot_standing_state == RIGHT_OB)
            {
                if(red_Lthe > theta2){ob_L = LEFT_OB;}
                else{ob_L = CENTER_OB;}

                if(red_Rthe > theta1 && red_Rthe < theta2){ob_R = CENTER_OB;}
                else{ob_R = RIGHT_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = CENTER_OB ;
                    ob_R = RIGHT_OB;
                }
            }
            else if(robot_standing_state == LEFT_OB)
            {
                if(red_Rthe < -theta2){ob_R = RIGHT_OB;}
                else{ob_R = CENTER_OB;}

                if(red_Lthe < -theta1 && red_Lthe > -theta2){ob_L = CENTER_OB;}
                else{ob_L = LEFT_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = LEFT_OB;
                    ob_R = CENTER_OB;
                }
            }
        }
        else if(color_state == BLUE)
        {
            if(robot_standing_state == CENTER_OB)
            {
                if(blue_Lthe > theta1){ob_L = LEFT_OB;}
                else{ob_L = CENTER_OB;}

                if(blue_Rthe < -theta1){ob_R = RIGHT_OB;}
                else{ob_R = CENTER_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = LEFT_OB;
                    ob_R = RIGHT_OB;
                }
            }
            else if(robot_standing_state == RIGHT_OB)
            {
                if(blue_Lthe > theta2){ob_L = LEFT_OB;}
                else{ob_L = CENTER_OB;}

                if(blue_Rthe > theta1 && blue_Rthe < theta2){ob_R = CENTER_OB;}
                else{ob_R = RIGHT_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = CENTER_OB ;
                    ob_R = RIGHT_OB;
                }
            }
            else if(robot_standing_state == LEFT_OB)
            {
                if(blue_Rthe < -theta2){ob_R = RIGHT_OB;}
                else{ob_R = CENTER_OB;}

                if(blue_Lthe < -theta1 && blue_Lthe > -theta2){ob_L = CENTER_OB;}
                else{ob_L = LEFT_OB;}

                if(ob_L == ob_R)
                {
                    //해당 부분 필요하면 추가적인 코드 필요
                    ob_L = LEFT_OB;
                    ob_R = CENTER_OB;
                }
            }
        }

        obstacle1_state = ob_L;
        obstacle2_state = ob_R;

        if(ob_L == LEFT_OB)
        {
            if(ob_R == CENTER_OB){return RIGHT_OB;}
            else if(ob_R == RIGHT_OB){return CENTER_OB;}
            else if(ob_R == LEFT_OB){return RIGHT_OB;}
        }
        else if(ob_L == CENTER_OB)
        {
            if(ob_R == RIGHT_OB){return LEFT_OB;}
            if(ob_R == CENTER_OB){return LEFT_OB;} //해당 경우 애매함
        }
        else if(ob_L == RIGHT_OB)
        {
            return LEFT_OB;
        }
    }
    else if(start_state == OBSTACLE_START_O)
    {
        if(robot_standing_state == CENTER_OB)
        {
            if(color_state == RED)
            {
                if(red_Lthe > -theta3 && red_Lthe < theta3){ob_L = CENTER_OB; ob_R = NONE;}
                else if(red_Lthe > theta3){ob_L = LEFT_OB; ob_R = NONE;}
                else if(red_Lthe < -theta3){ob_L = RIGHT_OB; ob_R = NONE;}
            }

            if(color_state == BLUE)
            {
                if(blue_Lthe > -theta3 && blue_Lthe < theta3){ob_L = CENTER_OB; ob_R = NONE;}
                else if(blue_Lthe > theta3){ob_L = LEFT_OB; ob_R = NONE;}
                else if(blue_Lthe < -theta3){ob_L = RIGHT_OB; ob_R = NONE;}
            }
        }
        else if(robot_standing_state == LEFT_OB)
        {
            if(color_state == RED)
            {
                if(red_Lthe < -theta3 && red_Lthe > -theta4){ob_L = CENTER_OB; ob_R = NONE;}
                else if(red_Lthe > -theta3){ob_L = LEFT_OB; ob_R = NONE;}
                else if(red_Lthe < -theta4){ob_L = RIGHT_OB; ob_R = NONE;}
            }

            if(color_state == BLUE)
            {
                if(blue_Lthe < -theta3 && blue_Lthe > -theta4){ob_L = CENTER_OB; ob_R = NONE;}
                else if(blue_Lthe > -theta3){ob_L = LEFT_OB; ob_R = NONE;}
                else if(blue_Lthe < -theta4){ob_L = RIGHT_OB; ob_R = NONE;}
            }
        }
        else if(robot_standing_state == RIGHT_OB)
        {
            if(color_state == RED)
            {
                if(red_Lthe > theta3 && red_Lthe < theta4){ob_L = CENTER_OB; ob_R = NONE;}
                else if(red_Lthe < theta3){ob_L = RIGHT_OB; ob_R = NONE;}
                else if(red_Lthe > theta4){ob_L = LEFT_OB; ob_R = NONE;}
            }

            if(color_state == BLUE)
            {
                if(blue_Lthe > theta3 && blue_Lthe < theta4){ob_L = CENTER_OB; ob_R = NONE;}
                else if(blue_Lthe < theta3){ob_L = RIGHT_OB; ob_R = NONE;}
                else if(blue_Lthe > theta4){ob_L = LEFT_OB; ob_R = NONE;}
            }
        }

        obstacle1_state = ob_L;
        obstacle2_state = ob_R;

        if(ob_L == LEFT_OB)
        {
            if(robot_standing_state != RIGHT_OB)
            {
                return CENTER_OB;
            }
            else
            {
                return RIGHT_OB;
            }
        }
        else if(ob_L == CENTER_OB)
        {
            if(robot_standing_state != RIGHT_OB)
            {
                return LEFT_OB;
            }
            else
            {
                return RIGHT_OB;
            }
        }
        else if(ob_L == RIGHT_OB)
        {
            if(robot_standing_state != LEFT_OB)
            {
                return CENTER_OB;
            }
            else
            {
                return LEFT_OB;
            }
        }

    }
    else if(start_state == OBSTACLE_START_L)
    {
        obstacle1_state = NONE;
        obstacle2_state = NONE;
        return NONE;
    }
}

bool TECHNICAL_OB::calc_emergency()
{
    if(master->local.Robot_X > 690 || master->local.Robot_X < 560){return true;}
    if(sector_state != 4 && start_state == (OBSTACLE_START_L)){return true;}
    return false;
}

bool TECHNICAL_OB::calc_avoidance()
{
    if(color_state == RED)
    {
        if(distL < 500 && red_Lthe < theta_a2) //100 & theta_a2 value need to chang
        {
            return true;
        }
    }

    if(color_state == BLUE)
    {
        if(distL < 500 && blue_Lthe < theta_a2) //100 & theta_a2 value need to chang
        {
            return true;
        }
    }



    return false;

}

void TECHNICAL_OB::calc_localerror()
{
    if(sector_state == SECTOR1)
    {

    }
    else if(sector_state == SECTOR2)
    {

    }
    else if(sector_state == SECTOR3)
    {

    }

}

bool TECHNICAL_OB::calc_sector_change()
{
    if(sector_state != sector_state_tem){sector_state_tem = sector_state; holdon_flag = false; return true;}
    return false;
}

void TECHNICAL_OB::change_robot_standing()
{
    robot_next_standing_state = NONE;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "           SECTOR CHANGE!!         " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;
    cout << "                                   " << endl;

}

void TECHNICAL_OB::print_state()
{
    if(color_state == RED){cout << "    RED    " << endl;}
    else if(color_state == BLUE){cout << "    BLUE    " << endl;}

    if(start_state == OBSTACLE_START_N){cout << "OBSTACLE START     : N " << endl;}
    else if(start_state == OBSTACLE_START_T){cout << "OBSTACLE START     : T " << endl;}
    else if(start_state == OBSTACLE_START_O){cout << "OBSTACLE START     : O " << endl;}
    else if(start_state == OBSTACLE_START_L){cout << "OBSTACLE START     : L " << endl;}
    else if(start_state == OBSTACLE_START_A){cout << "OBSTACLE START     : A " << endl;}


    if(robot_standing_state == LEFT_OB)cout << "ROBOT STANDING            :          LEFT_OB"<< endl;
    else if(robot_standing_state == RIGHT_OB)cout << "ROBOT STANDING              :          RIGHT_OB"<< endl;
    else if(robot_standing_state == CENTER_OB)cout << "ROBOT STANDING              :          CENTER_OB"<< endl;

    if(robot_next_standing_state == LEFT_OB)cout << "DESTINATION            :          LEFT_OB"<< endl;
    else if(robot_next_standing_state == RIGHT_OB)cout << "DESTINATION            :          RIGHT_OB"<< endl;
    else if(robot_next_standing_state == CENTER_OB)cout << "DESTINATION            :          CENTER_OB"<< endl;

    if(obstacle1_state == LEFT_OB)cout << "OBSTACLE1            :          LEFT_OB"<< endl;
    else if(obstacle1_state == CENTER_OB)cout << "OBSTACLE1            :          CENTER_OB"<< endl;
    else if(obstacle1_state == RIGHT_OB)cout << "OBSTACLE1            :          RIGHT_OB"<< endl;

    if(obstacle2_state == LEFT_OB)cout << "OBSTACLE2            :          LEFT_OB"<< endl;
    else if(obstacle2_state == CENTER_OB)cout << "OBSTACLE2            :          CENTER_OB"<< endl;
    else if(obstacle2_state == RIGHT_OB)cout << "OBSTACLE2            :          RIGHT_OB"<< endl;

    if(color_state == RED)
    {
        cout << "OB_L THETA :       " << red_Lthe << endl;
        cout << "OB_R THETA :       " << red_Rthe << endl;
    }
    else
    {
        cout << "OB_L THETA :       " << blue_Lthe << endl;
        cout << "OB_R THETA :       " << blue_Rthe << endl;
    }

    if(sector_state == SECTOR1){cout << "SECTOR     1   " << endl;}
    else if(sector_state == SECTOR2){cout << "SECTOR     2   " << endl;}
    else if(sector_state == SECTOR3){cout << "SECTOR     3   " << endl;}
    else if(sector_state == SECTOR4){cout << "SECTOR     4   " << endl;}

//        if(sector_state_tem == SECTOR1){cout << "SECTOR_TEM     1   " << endl;}
//        else if(sector_state_tem == SECTOR2){cout << "SECTOR_TEM     2   " << endl;}
//        else if(sector_state_tem == SECTOR3){cout << "SECTOR_TEM     3   " << endl;}
//        else if(sector_state_tem == SECTOR4){cout << "SECTOR_TEM     4   " << endl;}


        if(holdon_flag){cout << "           HOLD ON FLAG IN TRUE            " << endl;}
        else{}


    if(emergency_flag)cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        EMERGENCY       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void TECHNICAL_OB::obstaclemove(int sector, int way)
{
    if(sector == SECTOR1)
    {
        if(master->local.Robot_Y < 700 && master->local.Robot_Y > localY[0] + 105)
        {
            if(way == LEFT_OB)
            {
                move2point(Point(localX[0], localY[0]));
            }
            else if(way == CENTER_OB)
            {
                move2point(Point(localX[1], localY[0]));
            }
            else if(way == RIGHT_OB)
            {
                move2point(Point(localX[2], localY[0]));
            }

            holdon_flag = false;
        }
        else
        {
            cout << "           HOLD ON         " << endl;
            move2point(Point(tem_point_x, tem_point_y));
            holdon_flag = true;
        }
    }
    else if(sector == SECTOR2)
    {
        if(master->local.Robot_Y > localY[1] + 10 && master->local.Robot_Y < localY[1] + 105)
        {
            cout << "           HOLD ON         " << endl;
            move2point(Point(tem_point_x, tem_point_y));
            holdon_flag = true;

        }
        else
        {
            if(way == LEFT_OB)
            {
                move2point(Point(localX[0], localY[1]));
            }
            else if(way == CENTER_OB)
            {
                move2point(Point(localX[1], localY[1]));
            }
            else if(way == RIGHT_OB)
            {
                move2point(Point(localX[2], localY[1]));
            }

            holdon_flag = false;
        }
    }
    else if(sector == SECTOR3)
    {
        if(master->local.Robot_Y > localY[2] + 10 && master->local.Robot_Y < localY[2] + 105)
        {
            cout << "           HOLD ON         " << endl;
            move2point(Point(tem_point_x, tem_point_y));
            holdon_flag = true;

        }
        else
        {
            if(way == LEFT_OB)
            {
                move2point(Point(localX[0], localY[2]));
            }
            else if(way == CENTER_OB)
            {
                move2point(Point(localX[1], localY[2]));
            }
            else if(way == RIGHT_OB)
            {
                move2point(Point(localX[2], localY[2]));
            }
            holdon_flag = false;
        }
    }
//    else if(sector == SECTOR4)
//    {
//        if(way == LEFT_OB)
//        {

//        }
//        else if(way == CENTER_OB)
//        {

//        }
//        else if(way == RIGHT_OB)
//        {

//        }
//    }
}

void TECHNICAL_OB::obstacleerror(int sector)
{
    if(sector == SECTOR1)
    {
        move2point(Point(625, 650));
    }
    else if(sector == SECTOR2)
    {
        move2point(Point(625, 500));
    }
    else if(sector == SECTOR3)
    {
        move2point(Point(625, 350));
    }
}

bool TECHNICAL_OB::move2point(Point targetPoint)
{
    cout << "  move2point  " << endl;

    tem_point_x = targetPoint.x();
    tem_point_y = targetPoint.y();

    bool isArrive = false;

    Point myPoint(static_cast<int>(master->local.Robot_X), static_cast<int>(master->local.Robot_Y));

    const double arriveThreshold = 20;
    const double yawThreshold = 2;

    //오차
    double err_x = myPoint.x() - targetPoint.x();
    double err_y =  myPoint.y() - targetPoint.y();

    //z값의 목표(reference)는 mySide에 따라서 다르다
    double ref_z = 0;
    double err_z = ref_z - static_cast<double>(master->imu.yaw);

    if(abs(targetPoint.y() - myPoint.y()) < arriveThreshold && abs(targetPoint.x() - myPoint.x()) < arriveThreshold && abs(err_z) < yawThreshold)
    {
        isArrive = true;
        cout << "################   isAriive   ################" << endl;
        cout<<"err_X : " << err_x << " err_Y : " << err_y << " err_z : " << err_z << endl;
        return isArrive;
    }
    else
    {

        //최종 출력
        int x = 0;
        int y = 0;
        int z = 0;

        //        //오차
        //        double err_x = targetPoint.x() - myPoint.x();
        //        double err_y = targetPoint.y() - myPoint.y();

        //        //z값의 목표(reference)는 mySide에 따라서 다르다
        //        double ref_z = master->gameControlData.mySide == RIGHT_OB ? 90 : -90;
        //        double err_z = ref_z - static_cast<double>(master->imu.yaw);

        //예외처리 하지 않은 순수 오차 출력
        //            cout << "err_x: " << err_x;
        //            cout << " err_y: " << err_y;
        //            cout << " err_z: " << err_z;

        //오차의 최대값(=최소값)
        const int max_x = 100;
        const int max_y = 100;
        const int max_z = 90;

        //최대, 최소 값을 넘는 오차 예외처리
        if(err_x > max_x)       err_x = max_x;
        else if(err_x < -max_x) err_x = -max_x;
        if(err_y > max_y)       err_y = max_y;
        else if(err_y < -max_y) err_y = -max_y;
        if(err_z > max_z)       err_z = max_z;
        else if(err_z < -max_z) err_z = -max_z;

        double reg_err_x = 1;
        double reg_err_y = 1;
        double reg_err_z = 1;

        //정규화
        //            if(err_x < 0.4*max_x){
        //                reg_err_x = REG2(err_x, 0, max_x);
        //            }
        //            else{
        //                reg_err_x = 1;
        //            }

        //            if(err_y < 0.4*max_y){
        //                reg_err_y = REG2(err_y, 0, max_y);
        //            }
        //            else{
        //                reg_err_y = 1;
        //            }

        //            if(err_z < 0.5*max_z){
        //                reg_err_z = REG2(err_z, 0, max_z);
        //            }
        //            else{
        //                reg_err_z = 1;
        //            }

        reg_err_x = REG2(err_x, 0, max_x);
        reg_err_y = REG2(err_y, 0, max_y);
        reg_err_z = REG2(err_z, 0, max_z);
        //        double reg_err_z = err_z;

        //정규화된 오차 출력
        //            cout << "reg_err_x: " << reg_err_x;
        //            cout << " reg_err_y: " << reg_err_y;
        //            cout << " reg_err_z: " << reg_err_z;

        //각 제어량의 비례 상수 설정
        const double Kp_x = 8;
        const double Kp_y = 10;
        //        const double Kp_z = R_YAW_MAX;
        const double Kp_z = 5;

        int sign_x;
        int sign_y;
        int sign_z;

        if(err_x > 0){sign_x = 1;}else if(err_x < 0){sign_x = -1;}
        if(err_y > 0){sign_y = 1;}else if(err_y < 0){sign_y = -1;}
        if(err_z > 0){sign_z = 1;}else if(err_z < 0){sign_z = -1;}

        //출력값 결정
        x = Kp_x * reg_err_x + 3 * sign_x;
        y = Kp_y * reg_err_y + 5 * sign_y;
        z = Kp_z * reg_err_z + 1 * sign_z;

        //            cout<<"reg_err_y : "<<reg_err_y<<endl;

        //Side가 바뀌면 YAW방향이 바뀌므로 X, Y는 방향을 바꿔줘야 한다.
        int dir = master->gameControlData.mySide == /*RIGHT_OB ? 1 : -1*/1;
        int dir_x = master->gameControlData.mySide == /*RIGHT_OB ? -1 : 1*/1;

        cout << "x : " << y << " y : " << x << " z : " << z << endl;
        cout << "x point :      " << targetPoint.x() << " y point :       " << targetPoint.y() << endl;

        //최종 출력
        walkStart(y, x, z);



    }

    return  isArrive;
}

}//namespace robocup_master23
