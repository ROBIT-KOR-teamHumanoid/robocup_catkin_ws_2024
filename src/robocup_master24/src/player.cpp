#include "robocup_master24/player.hpp"
#define REG2(X, MIN, MAX) (X - MIN) / (MAX - MIN)

namespace robocup_master24 {

using namespace std;

//public



Player::~Player()
{

}

bool Player::falldownExeption()
{
    int falldownWhere;

    static int cnt;
    static int delay; //모션이 끝난 이후 바로 보행을 시작하면 급발진하기 때문에 딜레이를 조금 줘야한다.

    bool rst = false;

    if(isFalldown(20, 40, falldownWhere)) {
        rst = true;
        walkStop();
        cnt++;
        cout << "cnt: " << cnt <<  endl;
        if(cnt > 500) {
            delay = 1;
            raisetUp(falldownWhere);
        }
    } else {
        cnt = 0;
    }

    if(delay > 0 && delay < 1000) {
        rst = true;
        walkStop();
        delay++;
        if(delay == 500) {
            delay = 0;
        }
    }

    return rst;
}

void Player::selectGoalPost()
{
    if(master->gameControlData.mySide == RIGHT){
        cout << "SIDE: RIGHT" << endl;
        opponent_goal = Point(0, 400);
        opponent_goal_high = Point(100, 270);
        opponent_goal_low = Point(100,530);
        opponent_goal_middle = Point(0, 400);
        opponent_goal_middle_high = Point(100,450);
        opponent_goal_middle_low = Point(100,350);
    } else {
        cout << "SIDE: left" << endl;
        opponent_goal = Point(1100, 400);
        opponent_goal_high = Point(1000, 270);
        opponent_goal_low = Point(1000,530);
        opponent_goal_middle = Point(1000,400);
        opponent_goal_middle_high = Point(1000,450);
        opponent_goal_middle_low = Point(1000,350);
    }
}

void Player::penaltyControl(bool& isPenalty)
{
    isPenalty = true;
    switch (master->gameControlData.penalty) {
    case HL_BALL_MANIPULATION:
        cout << "!!PENALTY: HL_BALL_MANIPULATION!!" << endl;
        break;
    case HL_ILLEGAL_ATTACK:
        cout << "!!PENALTY: HL_ILLEGAL_ATTACK!!" << endl;
        break;
    case HL_ILLEGAL_DEFENSE:
        cout << "!!PENALTY: HL_ILLEGAL_DEFENSE!!" << endl;
        break;
    case HL_PHYSICAL_CONTACT:
        cout << "!!PENALTY: HL_PHYSICAL_CONTACT!!" << endl;
        break;
    case HL_PICKUP_OR_INCAPABLE:
        cout << "!!PENALTY: HL_PICKUP_OR_INCAPABLE!!" << endl;
        walkStop();
        break;
    case HL_SERVICE:
        cout << "!!PENALTY: HL_SERVICE!!" << endl;
        break;
    case SUBSTITUTE:
        cout << "!!THIS ROBOT IS SUBSTITIUTE!!" << endl;
        walkStop();
        visionPublish(VISION_SCAN_MODE_CNTR);
        break;
    default:
        isPenalty = false;
        break;
    }

    return;
}

void Player::gameStateControl(bool control_on, int state)
{
    if(!control_on){
        return;
    }
    switch (state) {
    case STATE_INITIAL:
        stateInitial();
        break;
    case STATE_READY:
        stateReady();
        break;
    case STATE_SET:
        stateSet();
        break;
    case STATE_PLAYING:
        statePlay();
        break;
    case STATE_FINISHED:
        stateFinished();
        break;
    default:
        break;
    }
}

//void Player::selectRobotState()
//{
//    master->udp[master->gameControlData.robotNum - 1].ballDist = master->vision.Ball_D;

//    int close_robot = static_cast<int>(master->gameControlData.robotNum);
//    double ball_dist;
//    double close_dist = 10000000;

//    for(int i = 0; i < 4; i++) {
//        ball_dist = master->udp[i].ballDist;
//        if(ball_dist > 0 && ball_dist < close_dist) {
//            close_dist = ball_dist;
//            close_robot = i + 1;
//        }
//    }

//    if(close_robot == master->gameControlData.robotNum && master->vision.Ball_D > 0) {
//        cout << "robot state: ROBOT_STATE_CONTROLL" << endl;
//        robot_state = ROBOT_STATE_CONTROLL;
//    } else {
//        cout << "robot state: ROBOT_STATE_SUPPORT" << endl;
//        robot_state = ROBOT_STATE_SUPPORT;
//    }
//}

bool Player::compareIndices(const std::vector<double>& arr, int i, int j) {
    return arr[i] < arr[j];
}

std::vector<int> Player::sortArrayByElementSize(const std::vector<double>& arr) {
    std::vector<int> indices(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        indices[i] = i;  // 초기 인덱스 리스트 생성
    }

    std::sort(indices.begin(), indices.end(), [&](int i, int j) {
        return compareIndices(arr, i, j);
    });

    return indices;
}

void Player::selectRobotState(bool isPenalty)
{
    Point ballPosition(master->local.Ball_X, master->local.Ball_Y);
    Point myPosition(master->local.Robot_X, master->local.Robot_Y);

    if(ballPosition.x() == 0 && ballPosition.y() == 0) //공이 없는 경우 예외처리
    {
        cout << "robot state: ROBOT_STATE_SUPPORT" << endl;
        robot_state = ROBOT_STATE_SUPPORT;

        return;
    }

    if(isPenalty)
    {
        cout << "robot state: ROBOT_STATE_PICKUP" << endl;
        robot_state = ROBOT_STATE_PICKUP;
        return;
    }

    //공과 로봇의 거리 측정
    vector<double> robotDist;
    robotDist.assign(MAX_ROBOT_NUM, 10000);
    robotDist.at(master->gameControlData.robotNum - 1) = calcDistance(myPosition, ballPosition);
    for (int robotIndex = 0; robotIndex < MAX_ROBOT_NUM - 1; robotIndex++) {

        cout<<"udp robot "<<master->udp[robotIndex].robot_num<<" robot state : "<<master->udp[robotIndex].robot_case<<endl;

        if(master->udp[robotIndex].robot_num == 0 || master->udp[robotIndex].robot_case == ROBOT_STATE_PICKUP) continue;
        Point robotPosition(master->udp[robotIndex].local_x, master->udp[robotIndex].local_y);
        robotDist.at(master->udp[robotIndex].robot_num - 1) = calcDistance(robotPosition, ballPosition);
    }

    vector<int> sortedIndices = sortArrayByElementSize(robotDist);

    //로봇끼리 거리 비교해서 컨트롤 로봇 정하기
    int tempControlRobotNum = 0;
    double dist1, dist2;
    dist1 = robotDist.at(sortedIndices.at(0));
    dist2 = robotDist.at(sortedIndices.at(1));

    for (int robotn = 0; robotn < sortedIndices.size() ; robotn++) {
        cout<<"robot "<<sortedIndices[robotn] + 1<<" dist : "<< robotDist.at(sortedIndices[robotn])<<endl;
    }

//    cout << "dist1: " << dist1 << endl;
//    cout << "dist2: " << dist2 << endl;

//    cout << "index: " << endl;
//    for (int index : sortedIndices) {
//            std::cout << index + 1 << " ";
//        }
//    std::cout << std::endl;


    tempControlRobotNum =  sortedIndices.at(0);


//    if((dist1 + 50) > dist2)
//    {
//        if(sortedIndices.at(0) < sortedIndices.at(1))
//        {
//            tempControlRobotNum = sortedIndices.at(1);
//        }
//    }
    tempControlRobotNum++;


    cout << "##tempControlRobotNum: " << tempControlRobotNum << endl;
    cout << "##robotNum           : " << master->gameControlData.robotNum << endl;

    //내 상태 결정
    if(isPenalty)
    {
        cout << "robot state: ROBOT_STATE_PICKUP2" << endl;
        robot_state = ROBOT_STATE_PICKUP;
    }
    else if(tempControlRobotNum == master->gameControlData.robotNum)
    {
        cout << "robot state: ROBOT_STATE_CONTROLL" << endl;
        robot_state = ROBOT_STATE_CONTROLL;
    }
    else
    {
        cout << "robot state: ROBOT_STATE_SUPPORT" << endl;
        robot_state = ROBOT_STATE_SUPPORT;
    }
}

void Player::publishMsg()
{
    walkPublish();
    udpPublish();
    localPublish();
}

void Player::move(bool flag)
{
    if(!flag){
        walkStop();
    }
}

void Player::move(int x, int y, int angle_mode, int target, int target_yaw)
{
    Point target_coor;
    target_coor.setX(x);
    target_coor.setY(y);
    move(target_coor, angle_mode, target, target_yaw);
}

void Player::move(Point target_coor, int angle_mode, int target, int target_yaw)
{

    cout<<"5555555555555555555555555555555555 in"<<endl;
    master->master2local.target_x = target_coor.x();
    master->master2local.target_y = target_coor.y();

    Point robot_coor;
    robot_coor.setX(master->local.Robot_X);
    robot_coor.setY(master->local.Robot_Y);
    double robot_yaw;
    robot_yaw = master->imu.yaw;

    if(target == BALL){
        Point ball_coor = target_coor;
        double ball_dist = master->vision.Ball_D;

        if(0 < master->vision.Ball_D && master->vision.Ball_D < kick_threshold) {
            int kick_mode = FRONT_KICK;
            if(kick_mode != NONE){
                Point ball_cam_coor;
                ball_cam_coor.setX(master->vision.Ball_cam_X);
                ball_cam_coor.setY(master->vision.Ball_cam_Y);
                bool isCalibrate;
                calibratePosition(robot_coor, ball_cam_coor, kick_mode, isCalibrate);
                if(isCalibrate){
                    cout << "cali OK" << endl;
                    if(playKickMotion(kick_mode)) {
                        cout << "kick" << endl;
                    }
                }
            }
        } else {
            if(moveToTarget(robot_coor, robot_yaw, ball_coor, RELATIVE, 0))
                cout<<"651180dfsdfsdfsafasdf"<<endl;
        }
    } else {
        int dist = sqrt(pow(robot_coor.x() - target_coor.x(), 2) + pow(robot_coor.y() - target_coor.y(), 2));
        if(dist > 100){fixyawflag = 0;}
        if((dist < 40 && !target_yaw) || fixyawflag){fixyawflag = 0; moveFixYaw(robot_coor, robot_yaw, target_coor, true);}
        else{moveToTarget(robot_coor, robot_yaw, target_coor, angle_mode, target_yaw);}
    }
}

bool Player::playMotion(int motion_num)
{
    cout << "playMotion" << endl;
    master->motion.Motion_Mode = 1;
    master->motion.Motion_Num = motion_num;
    cout<<"motion num :"<<motion_num<<endl;

    master->motionPub.publish(master->motion);

    bool motion_end = false;

    if(master->motionEnd.motion_end) {
        motion_end = true;
    }

    return motion_end;
}

//protected

void Player::stateReady(Point init_coor)
{
    move(init_coor, OPPONENT);
}

void Player::stateSet()
{

}

void Player::stateFinished()
{

}

//private

int Player::isFalldown(const double pitch_threshold, const double roll_threshold, int& falldownWhere)
{
    int result = FALLDOWN;
    double pitch = master->imu.pitch;
    double roll = master->imu.roll;

    if(roll > roll_threshold) {
        falldownWhere = FALLDOWN_RIGHT;
        cout << "FALLDOWN_RIGHT" << endl;
    } else if(roll < -roll_threshold) {
        falldownWhere = FALLDOWN_LEFT;
        cout << "FALLDOWN_LEFT" << endl;
    } else if(pitch > pitch_threshold) {
        falldownWhere = FALLDOWN_FRONT;
        cout << "FALLDOWN_FRONT" << endl;
    } else if(pitch < -pitch_threshold) {
        falldownWhere = FALLDOWN_REAR;
        cout << "FALLDOWN_REAR" << endl;
    } else {
        result = NOT_FALLDOWN;
    }

    return result;
}

void Player::raisetUp(int falldownWhere)
{

    switch (falldownWhere) {
    case FALLDOWN_FRONT:
        playMotion(MOTION_RASEUP_FRONT);
        break;
    case FALLDOWN_REAR:
        playMotion(MOTION_RASEUP_REAR);
        break;
    case FALLDOWN_RIGHT:
        playMotion(MOTION_RASEUP_RIGHT);
        break;
    case FALLDOWN_LEFT:
        playMotion(MOTION_RASEUP_LEFT);
        break;
    default:
        break;
    }
}

void Player::calcBallKickPosCoor(Point goal_coordinates, Point ball_coordinates, Point &OUTPUT_target_coor, double kick_radius)
{
    // Refer to the formula of the exturnal section.
    Point A = goal_coordinates;
    Point B = ball_coordinates;
    Point Q;                           //target coor.

    int delta_x = A.x() - B.x();
    int delta_y = A.y() - B.y();

    double m = hypot(delta_x, delta_y); //distance of AQ
    double n = kick_radius;             //distance of BQ
    //----------------------------------------------

    if(!(m - n)){

    } else {
        Q.setX((m * B.x() - n * A.x()) / (m - n));
        Q.setY((m * B.y() - n * B.y()) / (m - n));
    }
    OUTPUT_target_coor = Q;
}

int Player::selectKickType(Point ball_coordinates, Point robot_coordinates)
{
    cout << "selectKickType" << endl;

    Point opponent_goal_high = this->opponent_goal_high;
    Point opponent_goal_low = this->opponent_goal_low;
    Point ref_point = ball_coordinates;
    opponent_goal_high -= ref_point;
    opponent_goal_low -= ref_point;
    robot_coordinates -= ref_point;

    //    cout << "opponent_goal_high: (" << opponent_goal_high.x() << ", "<< opponent_goal_high.y() << ")" << endl;
    //    cout << "opponent_goal_low:  (" << opponent_goal_low.x() << ", "<< opponent_goal_low.y() << ")" << endl;
    //    cout << "robot_coordinates:  (" << robot_coordinates.x() << ", "<< robot_coordinates.y() << ")" << endl;

    double ref_theta = 0; //reference angle
    double com_theta = 0; //comparative angle

    ref_theta = (180 / PI) * atan2(opponent_goal_high.y() * opponent_goal_low.x() - opponent_goal_high.x() * opponent_goal_low.y(),
                                   opponent_goal_high.x() * opponent_goal_low.x() + opponent_goal_high.y() * opponent_goal_low.y());

    com_theta = (180 / PI) * atan2(opponent_goal_high.y() * robot_coordinates.x() - opponent_goal_high.x() * robot_coordinates.y(),
                                   opponent_goal_high.x() * robot_coordinates.x() + opponent_goal_high.y() * robot_coordinates.y());

    int kick_mode = NONE;

    if(com_theta > 0) {
        if(com_theta > 0 && com_theta < 180 + ref_theta) {
            cout << "SIDE RIGHT" << endl;
            kick_mode = SIDE_RIGHT;
        } else if(com_theta > 180 + ref_theta && com_theta < 180) {
            cout << "FRONT KICK" << endl;
            kick_mode = FRONT_KICK;
        }
    } else if(com_theta < 0) {
        com_theta = fabs(com_theta);
        ref_theta = fabs(ref_theta);

        if(0 < com_theta && com_theta < ref_theta) {
            cout << "BANNED POSITION" << endl;
        } else if (ref_theta < com_theta && com_theta < 180) {
            cout << "SIDE LEFT" << endl;
            kick_mode = SIDE_LEFT;
        }
    }

    return kick_mode;
}

void Player::calibratePosition(Point robot_coor, Point ball_cam_coor, int& kick_mode, bool& isCalibrate)
{
    visionPublish(VISION_SCAN_MODE_CNTR, 0, -70);
    cout << "calibratePosition" << endl;
    isCalibrate = false;

    if(kick_mode == FRONT_KICK) {
        if(ball_cam_coor.x() > 320) {
            kick_mode = FRONT_RIGHT;
            cout << "FRONT_RIGHT" << endl;
        } else {
            kick_mode = FRONT_LEFT;
            cout << "FRONT_LEFT" << endl;
        }
    }
    Point ref_point;
    Point allowance = Point(50, 25);
    switch (kick_mode) {
    case FRONT_RIGHT:
        ref_point = Point(420, 425);
        break;
    case FRONT_LEFT:
        ref_point = Point(250, 425);
        break;
    case SIDE_RIGHT:
        ref_point = Point(320, 425);
        break;
    case SIDE_LEFT:
        ref_point = Point(320, 425);
        break;
    default:
        break;
    }

    int x = X_MIN;
    int y = Y_MIN;

    if(ball_cam_coor.x() > ref_point.x() + allowance.x()) {
        cout << "SETTING : X" << endl;
        walkStart(0,-y,0);
    } else if(ball_cam_coor.x() < ref_point.x() - allowance.x()) {
        cout << "SETTING : -X" << endl;
        walkStart(0,y,0);
    } else {
        if(ball_cam_coor.y() > ref_point.y() + allowance.y()) {
            cout << "SETTING : Y" << endl;
            //            walkStart(-x,0,0);
        } else if(ball_cam_coor.y() < ref_point.y() - allowance.y()) {
            cout << "SETTING : -Y" << endl;
            walkStart(x,0,0);
        } else {
            cout << "CALI OK" << endl;
            if(walkStop()){
                isCalibrate = true;
            }
        }
    }
}

bool Player::playKickMotion(int kick_mode)
{
    bool motion_end = false;

    switch (kick_mode) {
    case FRONT_RIGHT:
        motion_end = playMotion(MOTION_KICK_FRONT_R);
        break;
    case FRONT_LEFT:
        motion_end = playMotion(MOTION_KICK_FRONT_L);
        break;
    case SIDE_RIGHT:
        motion_end = playMotion(MOTION_KICK_SIDE_R);
        break;
    case SIDE_LEFT:
        motion_end = playMotion(MOTION_KICK_SIDE_L);
        break;
    default:
        break;
    }

    return motion_end;
}

bool Player::moveFixYaw(Point current_coordinates, double current_yaw, Point target_coordinates, bool dontStop)
{
    int target_yaw = 0;
    int x_param = 0;
    int y_param = 0;

    if(opponent_goal.x() < 550){target_yaw = 90;}
    else{target_yaw = -90;}

    if(isArrive(current_coordinates, target_coordinates))
    {
        if(abs(target_yaw - current_yaw) < 15){walkStop();}
        else
        {
            target_angle = target_yaw - current_yaw;
            if(target_angle > 180) target_angle -= 360;
            else if(target_angle < -180) target_angle += 360;

            walkStart(x_param, y_param, static_cast<int>(target_angle));}
    }
    else
    {
        if(walk_switch == -1)
        {
            if(abs(target_yaw - current_yaw) > 15){walk_switch = 2;}
            else if(abs(current_coordinates.x() - target_coordinates.x()) > abs(current_coordinates.y() - target_coordinates.y())){walk_switch = 0;}
            else{walk_switch = 1;}
        }
        else if(walk_switch == 0)
        {
            fixyawflag = 1;
            if(abs(current_coordinates.x() - target_coordinates.x()) <= 5){walk_switch = -1; return false;}
            if(opponent_goal.x() < 550){if(current_coordinates.x() - target_coordinates.x() > 0){x_param = FRONT_MAX;} else{x_param = -10;}}
            else{if(current_coordinates.x() - target_coordinates.x() > 0){x_param = -10;} else{x_param = FRONT_MAX;}}
            target_angle = target_yaw - current_yaw;
        }
        else if(walk_switch == 1)
        {
            fixyawflag = 1;
            if(abs(current_coordinates.y() - target_coordinates.y()) <= 5){walk_switch = -1; return false;}
            if(opponent_goal.x() < 550){if(current_coordinates.y() - target_coordinates.y() > 0){y_param = LEFT_MAX;} else{y_param = RIGHT_MAX;}}
            else{if(current_coordinates.y() - target_coordinates.y() > 0){y_param = RIGHT_MAX;} else{y_param = LEFT_MAX;}}
            target_angle = target_yaw - current_yaw;
        }
        else if(walk_switch == 2)
        {
            fixyawflag = 1;
            if(abs(target_yaw - current_yaw) < 5){walk_switch = -1; return false;}
            target_angle = target_yaw - current_yaw;
        }

        if(target_angle > 180) target_angle -= 360;
        else if(target_angle < -180) target_angle += 360;

        walkStart(x_param, y_param, static_cast<int>(target_angle));
    }



    cout << "target_yaw:   " << target_yaw << endl;
    cout << "current_yaw:  " << current_yaw << endl;
    cout << "target angle: " << target_angle << endl;

    return false;
}

bool Player::moveToTarget(Point current_coordinates, double current_yaw, Point target_coordinates, int angle_mode, double target_angle, bool dontStop)
{
    cout << "moveToTarget" << endl;

    static double ref_angle;

    if(isArrive(current_coordinates, target_coordinates) && master->local.Ball_X == 0 && master->local.Ball_Y == 0)
    {
        cout<<"+++++++++++++++++++++++++"<<endl;
        walkStart(0,0,8);

    }
    else if(isArrive(current_coordinates, target_coordinates)){
        cout << "ARRIVE" << endl;
        static int stop_once;
        if(!stop_once){
            stop_once = walkStop();
        }

        if(angle_mode == ABSOLUTE){
            target_angle = (target_angle - current_yaw);
        } else if(angle_mode == RELATIVE){
            target_angle = target_angle + ref_angle;
            target_angle = target_angle - current_yaw;
        } else if(angle_mode == OPPONENT){
            target_angle = 0;
            calcTargetAngle(opponent_goal, current_coordinates, current_yaw, target_angle);
        }
        cout << "target_angle: " << target_angle << endl;
        if(alignRobot(current_yaw, target_angle)){
            if(dontStop) {
                return true;
            }
            if(walkStop()){
                cout<<"stop where"<<endl;

                return true;
            }
        }


    } else {
        ref_angle = current_yaw;
        double target_angle = 0;
        calcTargetAngle(target_coordinates, current_coordinates, current_yaw, target_angle);
        cout << "target angle: " << target_angle << endl;

        int max = 30;
        int min = -30;

        double yaw;

        int x = FRONT_MAX * calcDistance(current_coordinates,target_coordinates)/150.0;//73 // first: 50 -> 53 -> 55 -> 53 -> 51 -> 52 -> 53
        if(x < X_MIN)           x = X_MIN;
        else if( x > FRONT_MAX) x = FRONT_MAX;
        cout<<" FRONT X!! : "<<x<<endl;



        if(fabs(target_angle) > max) {
            yaw = target_angle > 0 ? R_YAW_MAX : L_YAW_MAX;
            x = 0;
        }
        else {
            double reg_err = (target_angle - min) / (max - min) * 2 - 1;

//            double Kp = 6.0;
//            double Ki = 0.0001;
//            double Kd = 0.0;

//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_1
//    Kp = 15.000000;//30.0000000;//8.000000;
//    Ki = 0.0000000;
//    Kd = 15.000000;//3.500000;
//#endif
//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_2
//    Kp = 3.0;
//    Ki = 0.0001;
//    Kd = 0;
//#endif
//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_3
//    Kp = 30;
//    Ki = 0.04;
//    Kd = 30;

//#endif
//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_4

//#endif
//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_5

//#endif
//#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_6

//#endif

            static PIDControll yawControl(Kp, Ki, Kd, R_YAW_MAX, 1);
            //yawControl.setParams(master->pid.Kp, master->pid.Ki, master->pid.Kd, 1);
            yaw = yawControl.controller(reg_err);
            yawControl.print();

        }

        walkStart(x, 0 , static_cast<int>(yaw));
    }
    return false;

}

void Player::calcDistance(Point starting_point, Point end_point, double &result)
{
    double delta_x = end_point.x() - starting_point.x();
    double delta_y = -end_point.y() + starting_point.y();

    result = hypot(delta_x, delta_y);
}

double Player::calcDistance(Point starting_point, Point end_point)
{
    double result;
    calcDistance(starting_point, end_point, result);
    return result;
}

bool Player::isArrive(Point robot_coor, Point target_coor, double threshold)
{
    calcDistance(robot_coor, target_coor, remaining_distance);

    bool status = remaining_distance < threshold ? true : false;
    return status;
}

void Player::calcTargetAngle(Point target_coor, Point robot_coor, double robot_yaw, double &target_angle)
{
    double delta_x = target_coor.x() - robot_coor.x();
    double delta_y = -target_coor.y() + robot_coor.y();

    abs_target_angle = -atan2(delta_x, delta_y);
    abs_target_angle = abs_target_angle * 180 / PI;

    target_angle += abs_target_angle - robot_yaw;

    if(target_angle > 180) target_angle -= 360;
    if(target_angle < -180) target_angle += 360;
}

double Player::calcTargetAngle(Point target_coor, Point robot_coor, double robot_yaw)
{
    double rst = 0;
    calcTargetAngle(target_coor, robot_coor, robot_yaw, rst);
    return rst;
}

bool Player::alignRobot(double robot_yaw, double target_angle, int yaw_factor, int angle_mode, double align_threshold)
{
    static bool off_course = false;
    if(fabs(target_angle) < align_threshold / 2) {
        off_course = false;
    }

    if((fabs(target_angle) < align_threshold) && !off_course) {
        return true;
    } else {
        off_course = true;

//        double yaw = yaw_factor * target_angle / fabs(target_angle);
        int max = 30;
        int min = -30;
        target_angle = target_angle > max ? max : target_angle;
        target_angle = target_angle < min ? min : target_angle;
        double yaw = 6 * ((target_angle - min) / (max - min) * 2 - 1);

        cout << "yaw: " << yaw << endl;

        walkStart(0, 0, yaw);

        return false;
    }
}

Point Player::setPoint(int point_number)
{
    int n = point_number;
    Point result;
    //중간을 기준으로 대칭 포인트
    Point p[] = {
        Point(550, 400),
        Point(-100, 0),
        Point(-100, 120),
        Point(-100, -120),
        Point(-150, 60),
        Point(-150, 220),
        Point(-150, -60),
        Point(-150, -220),
        Point(-200, 120),
        Point(-200, -120),
        Point(200, 120),
        Point(200, -120),
        Point(300, 120),
        Point(300, -120),
        Point(0,0)
    };

    if(master->gameControlData.mySide == RIGHT) {
        p[n].setX(-p[n].x());
        p[n].setY(-p[n].y());
    }

    result = p[0] + p[n];

    return result;
}

Point Player::calcShootPoint(double cali_radius, Point goal_coor, Point ball_coor)
{
//    Point A, B;
//    A = goal_coor;
//    B = ball_coor;

    double Qx, Qy;
    int x1, x2, y1, y2;

    x1 = goal_coor.x();
    x2 = ball_coor.x();
    y1 = goal_coor.y();
    y2 = ball_coor.y();

    double ball_dist = hypot(x2 - x1, y2 - y1);

    double m, n;
    m = 1;
    n = 1 + cali_radius / ball_dist;

    Qx = (x2 - x1) * n + x1;
    Qy = (y2 - y1) * n + y1;

    Point target_coor = Point(Qx, Qy);

    return target_coor;
}

void Player::dribble()
{
    //
    Point globalBall(master->local.Ball_X, master->local.Ball_Y);
    Point globalRobot(master->local.Robot_X, master->local.Robot_Y);

//    //보정 오차범위 파라미터
//    double cail_threshold = 15;
//    if(master->gameControlData.mySide == LEFT)
//    {
//        if(master->local.Robot_X > 800)
//        {
//            cail_threshold = 30;
//        }
//    }
//    else
//    {
//        if(master->local.Robot_X < 300)
//        {
//            cail_threshold = 30;
//        }
//    }

//    Point goalPoint = opponent_goal;

//    //패스 여부 결정 - 골대와 가까운 로봇이 있으면 그 로봇의 목표 위치에 패스
//    double shortestDist = calcDistance(globalRobot, opponent_goal);
//    for(int i = 0; i < 3; i ++)
//    {
//        Point udpRobot(master->udp[i].local_x, master->udp[i].local_y);
//        double isCheck = true;
//        if(udpRobot.x() == 0 && udpRobot.y() == 0) isCheck = false;
//        double dist = calcDistance(udpRobot, opponent_goal);
//        if(dist < shortestDist && isCheck) {
//            shortestDist = dist;
//            goalPoint = setPoint(12);

//            if(master->udp[i].local_y > 400) goalPoint.setY(520); //로봇 위치 기반 패스 위치 선정
//            else                             goalPoint.setY(280);

//            cail_threshold = 5;
//            cout << "PASS" << endl;
//        }
//    }

    //dribble

    //

    Point home(250,400);
    move(home);
    //move(p, ABSOLUTE, COORDINATE, angle);
   // moveToTarget(globalRobot,master->imu.yaw,home,OPPONENT,0,true);

//moveToTarget(globalRobot, master->imu.yaw, globalBall, OPPONENT, 0, true);


}


void Player::kick3()
{
    Point globalBall(master->local.Ball_X, master->local.Ball_Y);
    Point globalRobot(master->local.Robot_X, master->local.Robot_Y);

    //보정 오차범위 파라미터
    double cail_threshold = 15;
    //
    if(master->gameControlData.mySide == LEFT)
    {
        if(master->local.Robot_X > 800)
        {
            cail_threshold = 30;
        }
    }
    else
    {
        if(master->local.Robot_X < 300)
        {
            cail_threshold = 30;
        }
    }

    //슛 목표 지점 선정
    Point goalPoint = opponent_goal;

    //패스 여부 결정 - 골대와 가까운 로봇이 있으면 그 로봇의 목표 위치에 패스
    double shortestDist = calcDistance(globalRobot, opponent_goal);
    for(int i = 0; i < 3; i ++)
    {
        Point udpRobot(master->udp[i].local_x, master->udp[i].local_y);
        double isCheck = true;
        if(udpRobot.x() == 0 && udpRobot.y() == 0) isCheck = false;
        double dist = calcDistance(udpRobot, opponent_goal);
        if(dist < shortestDist && isCheck) {
            shortestDist = dist;
            goalPoint = setPoint(12);

            if(master->udp[i].local_y > 400) goalPoint.setY(520); //로봇 위치 기반 패스 위치 선정
            else                             goalPoint.setY(280);

            cail_threshold = 5;
            cout << "PASS" << endl;
        }
    }

    //상대 로봇이랑 가까이 있는 경우 - 정확도 낮추고 빠르게 걷어내기
    const double obstacle_threshold = 70; //상대 로봇과의 거리 파라미터: 이 값보다 작으면 빠르게 보정한다.

    Point obstaclePoint = Point(master->local.Obstacle0_X, master->local.Obstacle0_Y);
    double obstacle_dist = calcDistance(globalRobot, obstaclePoint);
    if(obstacle_dist < obstacle_threshold) {
        cail_threshold = 180;
    }


    static int state;
    const int refDist = 30;//cm  30
    const int distBias = 10;

    Point pointWhereIGo = calcShootPoint(refDist, goalPoint, globalBall);

    if(state < 3) {
        if(calcDistance(globalRobot, globalBall) > refDist + distBias)//공멀어지면 다시 케이스 0으로
        {
            state = 0;
        }
        if(master->vision.Ball_D == 0)
        {
//            state = 0;
            walkStart(0,0,7); // 한 방향으로 돌아서 공 찾기
        }
    }


    switch (state) {
    case 0:
    {
        cout << endl << " MOVE TO TARGET " << endl << endl;
        moveToTarget(globalRobot, master->imu.yaw, globalBall, OPPONENT, 0, true);
        if(calcDistance(globalRobot, globalBall) < refDist + distBias)// 오느정도 가까워 지면 다음 케이스인 어라운드 볼로 간다.￣
        {
            state = 1;
        }
        break;
    }
    case 1:
    {
        cout << endl << " MOVE ROBOT AROUND BALL " << endl << endl;

        if(moveRobotAroundBall(cail_threshold, refDist, pointWhereIGo, goalPoint))
        {
            state = 10;
        }
        break;
    }
    case 10:
     {   cout << endl << " move stop and watch ball " << endl << endl;

        static int delay_previous_cnt;
        delay_previous_cnt++;
        cout << "delay_cnt: " <<  delay_previous_cnt << endl;
         walkStop();

        const int twosecond = 2000;
        if(delay_previous_cnt > twosecond)
        {
            delay_previous_cnt = 0;
            state = 2;
      }
    }
        break;
    case 2:
        cout << endl << " CALI TO BALL " << endl << endl;

        if(caliToBall(goalPoint))
        {
            state = 3;
        }

        break;
    case 3:
    {
        cout << endl << " DELAY BEFORE MOTION" << endl << endl;

        if(before_cnt < 300){walkStart(0,0,0);before_cnt++; break;}


        walkStop();

        static int cnt_delayBeforeMotion;
        cnt_delayBeforeMotion++;

        cout << "cnt_delayBeforeMotion: " << cnt_delayBeforeMotion << endl;

        if(cnt_delayBeforeMotion > 500) { //1s
            cnt_delayBeforeMotion = 0;
            state = 4;
        }

        break;
    }
    case 4:
        cout << endl << " PLAY KICK MOTION " << endl << endl;
        int kick_mode;
        if(master->vision.Ball_2d_X > 0)
        {
            kick_mode = FRONT_LEFT;
        }
        else
        {
            kick_mode = FRONT_RIGHT;
        }
        state = 5;
        playKickMotion(kick_mode);
        master->motionEnd.motion_end = 0;

        break;
    case 5:
        cout << endl << " READY KICK MOTION " << endl << endl;

        walkStop();
        if(master->motionEnd.motion_end) state = 6;

        static int motionReadyCnt;
        motionReadyCnt++;

        cout << "motionReadyCnt: " << motionReadyCnt << endl;

        if(motionReadyCnt > 4000)//5000
        {
            motionReadyCnt = 0;

            state = 4;
        }

        break;
    case 6:
        cout << endl << " DELAY MOTION BEFORE WALK " << endl << endl;

        static int delay_cnt;
        delay_cnt++;
        cout << "delay_cnt: " <<  delay_cnt << endl;

        if(delay_cnt > 700)
        {
            delay_cnt = 0;
            state = 0;
        }

        break;
    }

    master->master2local.target_x = pointWhereIGo.x();
    master->master2local.target_y = pointWhereIGo.y();
}

bool Player::moveRobotAroundBall(double cail_threshold, int refDist, Point localTarget, Point goalPoint)
{
    Point localBall(static_cast<int>(master->local.Ball_X), static_cast<int>(master->local.Ball_Y));
    Point localRobot(static_cast<int>(master->local.Robot_X), static_cast<int>(master->local.Robot_Y));

    double robotYaw = static_cast<double>(master->imu.yaw);
    double ballAngle = calcTargetAngle(localBall, localRobot, robotYaw);

    double radTheta = (robotYaw + ballAngle) * (PI/180);

    double EndPointX = cos(radTheta)*localTarget.x()-sin(radTheta)*localTarget.y();
    double StartPointX = cos(radTheta)*localRobot.x()-sin(radTheta)*localRobot.y();

    double O_dir = EndPointX - StartPointX;

    double goalAngle = calcTargetAngle(goalPoint, localRobot, robotYaw);


    double radius_err = refDist - calcDistance(localBall, localRobot);

    if(abs(O_dir) < 30 &&
       abs(goalAngle) < cail_threshold /*&&*/
//       abs(ballAngle) < 20 &&
       /*radius_err > 3*/)
    {
        return true;
    }

    int dir = O_dir > 0 ? -1 : 1;
    cout << "DIR: " << dir << endl;

    double y = ROUND_Y;
    if(fabs(O_dir) < 5) y = 0;

    cout << "DIR ORG    : " << O_dir << endl;
    cout << "GOAL ANGLE : " << goalAngle << endl;
    cout << "BALL ANGLE : " << ballAngle << endl;
    cout << "radius_err : " << radius_err << endl;

//    if(radius_err > 0) {
//        radius_err = 10;
//        ballAngle = 0;
//        y = 0;
//    }

    if(ballAngle >= 10) ballAngle = 10;
    else if(ballAngle <= -10) ballAngle = -10;
    double reg_ballAngle = REG2(ballAngle, 0, 10);
    cout << "reg_ballAngle: " << reg_ballAngle << endl;


    int z = 5*reg_ballAngle -dir*3;
    if(z < -ROUND_YAW_MIN) z = -ROUND_YAW_MIN;
    else if(z > ROUND_YAW_MIN) z = ROUND_YAW_MIN;

    if(radius_err >= 0) radius_err = 0;
    else if(radius_err <= -20) radius_err = -20;
    cout<<"radius_err : "<<radius_err<<endl;
    double reg_radiusErr = double(radius_err - 0) / (double)(20 - 0); //REG2(radius_err, 0, 20);
    cout << "reg_radiusErr: " << reg_radiusErr << endl;

    walkStart(-10 * reg_radiusErr, dir*y, 1.2*z);

    return false;
}

bool Player::caliToBall(Point goalPoint) //local base
{
    const int velX = X_MIN; //-16
    const int velY = 11; //7

    Point localBall(master->vision.Ball_2d_X, master->vision.Ball_2d_Y);

    //30~100, 40~120
    const int in = 45; // number2: 15 -> 13 --17
    const int out = 125;//100; // first: 110 -> 100 -> 110
    const int back = 60;//40//80  --100
    const int front = 200; // number2: 120 -> 150 //least  116  190

    cout << "local Ball X: " << localBall.x() << endl;
    cout << "local Ball Y: " << localBall.y() << endl;


    //보정 완료 조건
//    if(/*abs*/-(localBall.x()) > in &&
//       /*abs*/-(localBall.x()) < out &&
//       localBall.y() > back &&
//       localBall.y() < front)
//    {
//        return true;
//    }

    if(abs(localBall.x()) > in &&
       abs(localBall.x()) < out &&
       localBall.y() > back &&
       localBall.y() < front)
    {
        return true;
    }


    int y = 0;
    int x = 0;

    //전후좌우 보정
    if(localBall.x() > out)
    {// LEFT
        cout << "OUT: GO LEFT" << endl;
        y = velY;
    }
    else if(localBall.x() > 0)
    {// LEFT
        cout << "IN" << endl;
//        y = -velY;
        y = velY;
    }
    else if(localBall.x() < -out)
    {// RIGHT
        cout << "OUT: GO RIGHT" << endl;
        y = -(velY);
    }
    else
    {// RIGHT
        cout << "IN: GO RIGHT" << endl;
        y = -(velY);
    }

    if(localBall.y() > front)
    {
        cout << "GO FRONT" << endl;
        x = velX;
    }
    else if(localBall.y() < back)
    {
        cout << "GO BACK" << endl;
        //x = velX;
        x = REAR_MAX;
    }
    else
    {
        x = 0;

    }




//    if(localBall.x() < right)
//    {
//        cout << "GO LEFT" << endl;

//        y = velY;
//    }
//    else if(localBall.x() > left || abs(localBall.x()) < in)
//    {
//        cout << "GO RIGHT" << endl;

//        y = -velY;
//    }
//    else
//    {
//        cout<<"DONT GO"<<endl;
//        y = 0;
//    }

//    if(localBall.y() > front)
//    {
//        cout << "GO FRONT" << endl;
//        x = velX;

//    }
//    else if(localBall.y() < back )
//    {
//        cout << "GO BACK" << endl;
//        x = -(velX-3);

//    }
//    else
//    {
//        cout<<"DONE GO"<<endl;
//        x = 0;
//    }

    //YAW축 보정
    int z = 0;

    int max = 10;
    double target_angle = calcTargetAngle(goalPoint, Point(master->local.Robot_X, master->local.Robot_Y), master->imu.yaw);
    target_angle = target_angle > max ? max : target_angle;
    if(target_angle > max) target_angle = max;
    else if(target_angle < -max) target_angle = -max;
    PIDControll yawControl(Kp, Ki, Kd, R_YAW_MAX, 0);
    double yaw_err = REG2(target_angle, 0, max);
    double yaw = yawControl.controller(yaw_err);


    z = static_cast<int>(yaw);


    cout<< "x , y , z : "<<x<< " "<<y<<" "<<z<<endl;
    walkStart(x,y,z);

    return false;
}

bool Player::walkStart(int x, int y, int yaw)
{
    master->ik.flag = true;

    master->ik.X_length = x;
    master->ik.Y_length = y;
    master->ik.Yaw = yaw;

    return master->ikEnd.ikend;
}

bool Player::walkStop()
{

    master->ik.flag = false;
    master->ik.X_length = 0;
    master->ik.Y_length = 0;
    master->ik.Yaw = 0;

    return master->ikEnd.ikend;
}

bool Player::walkPublish()
{
    bool error = false;
    if(master->ik.X_length > FRONT_MAX) {
        master->ik.X_length = FRONT_MAX;
        error = true;
    } else if(master->ik.X_length < REAR_MAX) {
        master->ik.X_length = REAR_MAX;
        error = true;
    }

    if(master->ik.Y_length > RIGHT_MAX) {
        master->ik.Y_length = RIGHT_MAX;
        error = true;
    } else if(master->ik.Y_length < LEFT_MAX) {
        master->ik.Y_length = LEFT_MAX;
        error = true;
    }

    if(master->ik.Yaw > R_YAW_MAX) {
        master->ik.Yaw = R_YAW_MAX;
        error = true;
    } else if(master->ik.Yaw < L_YAW_MAX) {
        master->ik.Yaw = L_YAW_MAX;
        error = true;
    }

    master->ikPub.publish(master->ik);

    return error;
}

bool Player::visionPublish(int scan_mode, int pan, int tilt)
{
    master->master2vision.Scan_Mode = scan_mode;
    master->master2vision.TILT = -45;
    master->master2vision.PAN = 0;
    master->visionPub.publish(master->master2vision);

    return true;
}

bool Player::udpPublish()
{
    master->master2udp.robot_num = master->gameControlData.robotNum;
    master->master2udp.robot_state = robot_state;
    //master->master2udp.robot_state = robot_panalty_state;
    master->master2udp.robot_coor_x = static_cast<int>(master->local.Robot_X);
    master->master2udp.robot_coor_y = static_cast<int>(master->local.Robot_Y);
    master->master2udp.roboy_imu_yaw = static_cast<int>(master->imu.yaw);
    master->master2udp.ball_dist = 0;
    master->master2udp.ball_coor_x = static_cast<int>(master->local.Ball_X);
    master->master2udp.ball_coor_y = static_cast<int>(master->local.Ball_Y);
    master->master2udp.myTeam = static_cast<int>(master->gameControlData.myTeam);

    if(static_cast<int>(master->vision.Ball_D) == 0) {
        master->master2udp.ball_coor_x = 0;
        master->master2udp.ball_coor_y = 0;
    }

    master->udpPub.publish(master->master2udp);

    return true;
}

bool Player::localPublish()
{
    if(static_cast<int>(master->ik.flag) == false){
        master->master2local.target_x = 0;
        master->master2local.target_y = 0;
    }
    else
    cout<<"1111111111111111111pub"<<endl;
    master->localPub.publish(master->master2local);

    return true;
}

} //robocup_master24
