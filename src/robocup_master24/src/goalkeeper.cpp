#include "robocup_master24/goalkeeper.hpp"

#define REG2(X, MIN, MAX) (X - MIN) / (MAX - MIN)
#define come true;
#define far false;
namespace robocup_master24 {

using namespace std;

Goalkeeper::Goalkeeper(MasterRcko* master) :
    Player(master)
{
    //Robocup Korea Yongpyeong 2023 version 1.0
    //Robocup Bordeaux 2023 Goalkeeper version 1.3
}

void Goalkeeper::selectRobotState()
{
    Point ballPoint(static_cast<int>(master->local.Ball_X), static_cast<int>(master->local.Ball_Y));
    bool keeperZoneX = false;
    double res = sqrt(pow(120 - master -> local.Robot_X, 2) + pow(400 - master -> local.Robot_Y, 2));

    cout << res << endl;
    if(master->gameControlData.mySide == RIGHT)
    {
        targetyaw = 90;
        if(ballPoint.x() > 1000 - 100)
        {
            keeperZoneX = true;
        }
    }
    else
    {
        targetyaw = -90;
        if(ballPoint.x() < 100 + 100)
        {
            keeperZoneX = true;
        }
    }


    if(master->gameControlData.secondState == STATE2_PENALTYKICK)
    {
        robot_state = MODE_Penalty;
    }
    else if(master->local.Robot_Y < 400 - goalOffset || master->local.Robot_Y > 400 + goalOffset)
    {
         robot_state = KEEPER_STATE_QUICK_BACK;
    }
    else if(ballPoint.x() == 0.0 && ballPoint.y() == 0.0)
    {
        robot_state = ROBOT_STATE_NOBALL;
    }
    //origin 250 550
    else if(200 < ballPoint.y() && ballPoint.y() < 600 && keeperZoneX)
    {
        robot_state = KEEPER_STATE_KEEPERZONE;
    }
    else if(400 - goalOffset < ballPoint.y() && ballPoint.y() < 400 + goalOffset)
    {
        robot_state = KEEPER_STATE_CENTER;
    }
    //normal mode
    else
    {
        robot_state = NORMAL;
    }
}

void Goalkeeper::stateInitial()
{
    cout << "keeper state init" << endl;
    visionPublish(VISION_SCAN_MODE_INIT);
    walkStop();

    //1000  100
    if(master->gameControlData.mySide == RIGHT)
    {
        homePoint = Point(1100 - frontOffset, 400);
    }
    else
    {
        homePoint = Point(0 + frontOffset, 400);
    }
}

void Goalkeeper::stateReady()
{
    if(master->gameControlData.mySide == RIGHT)
    {
        homePoint = Point(1100 - frontOffset, 400);
    }
    else
    {
        homePoint = Point(0 + frontOffset, 400);
    }

    visionPublish(VISION_SCAN_MODE_BALL);
    cout << "keeper state ready" << endl;

    Player::stateReady(homePoint);
}

void Goalkeeper::stateSet()
{
    visionPublish(VISION_SCAN_MODE_BALL);
    cout << "keeper state set" << endl;
    walkStop();
}

//dribble --> <= 200
//save >= 250 && <= 600
void Goalkeeper::statePlay()
{
    //Penalty_Kick을 test할때는 밑에 줄을 활성화
    //    robot_state = MODE_Penalty;
    //아무 함수나 변수 테스트 할 때 사용
    //robot_state = MODE_TEST;

    visionPublish(VISION_SCAN_MODE_BALL);
    cout << "keeper state play" << endl;

    Point ballPoint(static_cast<int>(master->local.Ball_X), static_cast<int>(master->local.Ball_Y));
    Point myPoint(static_cast<int>(master->local.Robot_X), static_cast<int>(master->local.Robot_Y));

    //playSaveMotion();
    //gksave();
    switch (robot_state) {

    case MODE_TEST:
    {
        //kick3();
        //gksave();
        break;
    }
    case ROBOT_STATE_NOBALL:
    {
        cout << "  ROBOT_STATE_NOBALL" << endl;

        //공이 없는 경우 예외처리
        if(moveSideOnly(homePoint))
        {
            walkStop();
        }
        break;
    }
    case KEEPER_STATE_KEEPERZONE:
    {
        cout << "  KEEPER_STATE_KEEPERZONE" << endl;
        //당장 공을 걷어내기
        kick3();

        break;
    }
    case KEEPER_STATE_CENTER:
    {
        cout << "  KEEPER_STATE_CENTER  " << endl;

        //공과 직선이 되도록 위치 선정
        int target_x = homePoint.x();
        int target_y = ballPoint.y();

        Point targetPoint(target_x, target_y);
        if(moveSideOnly(targetPoint))
        {
            walkStop();
        }
        break;
    }
    case KEEPER_STATE_QUICK_BACK :
    {
        cout << "  KEEPER_STATE_QUICK_BACK  " << endl;
        Player::stateReady(homePoint);
        break;
    }
    case NORMAL:
    {
        cout << "  KEEPER_STATE_SIDEBALL  " << endl;

        //offset point에서 공 바라보기
        int target_x = homePoint.x();
        int target_y = ballPoint.y();

        //400 + 65 = 465, NORMAL mode move side to
        int xLimitH = 400 + goalOffset;
        //400 - 65 = 335, NORMAL mode move side to
        int xLimitL = 400 - goalOffset;

        if(ballPoint.y() > xLimitH)
        {
            target_y = xLimitH;
        }
        else if(ballPoint.y() < xLimitL)
        {
            target_y = xLimitL;
        }

        Point targetPoint(target_x, target_y);
        if(moveSideOnly(targetPoint))
        {
            double robot_yaw = static_cast<int>(master->imu.yaw);
            double targetAngle = calcTargetAngle(ballPoint, myPoint, robot_yaw);
            if(alignRobot(robot_yaw, targetAngle))
            {
                walkStop();
            }
        }
        double res = sqrt(pow(120 - master -> local.Robot_X, 2) + pow(400 - master -> local.Robot_Y, 2));

        if(res >= 166.0)
        {
            qb = true;
            robot_state = KEEPER_STATE_QUICK_BACK;
            if(res <= 25.0)
                qb = false;
        }
        break;
    }
    case MODE_Penalty:
    {
        PenaltySave();
        break;
    }
    }
}

void Goalkeeper::stateFinished()
{
    cout << "keeper state finished" << endl;
    walkStop();
}

int Goalkeeper::playSaveMotion()
{
    //    int doSaveMotion = 0; // 0: 모션 안 함, 1: 오른쪽 방어 모션, 2: 왼쪽 방어 모션
    cout << "keeper state Motion" << endl;

    //사용 변수 설정
    double ballSpeedX = master->local.Ball_speed_X;
    double ballSpeedY = master->local.Ball_speed_Y;
    double ballSpeedLevel = master->vision.Ball_speed_level;
    int myY = static_cast<int>(master->local.Robot_Y);
    int condition = 100;

    if(master->gameControlData.mySide == RIGHT)
    {
        ballSpeedX = 1100 - ballSpeedX;
        ballSpeedY = 800 - ballSpeedY;
        myY = 800 - myY;
        condition = 1000;
    }

    bool dir = (ballSpeedX > master->local.Ball_X) ? true : false;

    ballSpeedY = ballSpeedY - myY;

    cout << "ballSpeedX    : " << ballSpeedX << endl;
    cout << "ballSpeedY    : " << ballSpeedY << endl;
    cout << "ballSpeedLevel: " << ballSpeedLevel << endl;

    if(ballSpeedX < condition && ballSpeedLevel > 250 && dir)
    {
        directionprt(static_cast<int>(ballSpeedY));
        int motion;

        if(ballSpeedY >= 0)
        {
            motion = MOTION_ARM_RIGHT;
        }
        else
        {
            motion = MOTION_ARM_LEFT;
        }
        playMotion(motion);
    }

    return 0;
}

bool Goalkeeper::moveSideOnly(Point targetPoint)
{
    cout << "  moveSideOnly  " << endl;

    bool isArrive = false;

    Point myPoint(static_cast<int>(master->local.Robot_X), static_cast<int>(master->local.Robot_Y));

    const double arriveThreshold = 10;

    if(abs(targetPoint.y() - myPoint.y()) < arriveThreshold)
    {
        isArrive = true;
        return isArrive;
    }
    else
    {
        //최종 출력
        int x = 0;
        int y = 0;
        int z = 0;

        //오차
        double err_x = targetPoint.x() - myPoint.x();
        double err_y = targetPoint.y() - myPoint.y();

        //z값의 목표(reference)는 mySide에 따라서 다르다
        double ref_z = master->gameControlData.mySide == RIGHT ? 90 : -90;
        double err_z = ref_z - static_cast<double>(master->imu.yaw);

        //예외처리 하지 않은 순수 오차 출력
        cout << "err_x: " << err_x << endl;
        cout << "err_y: " << err_y << endl;
        cout << "err_z: " << err_z << endl;

        //오차의 최대값(=최소값)
        const int max_x = -10;
        const int max_y = 30;
        const int max_z = 90;

        //최대, 최소 값을 넘는 오차 예외처리
        if(err_x > max_x)       err_x = max_x;
        else if(err_x < -max_x) err_x = -max_x;
        if(err_y > max_y)       err_y = max_y;
        else if(err_y < -max_y) err_y = -max_y;
        if(err_z > max_z)       err_z = max_z;
        else if(err_z < -max_z) err_z = -max_z;

        //정규화
        double reg_err_x = REG2(err_x, 0, max_x);
        double reg_err_y = REG2(err_y, 0, max_y);
        double reg_err_z = REG2(err_z, 0, max_z);

        //정규화된 오차 출력
        cout << "reg_err_x: " << reg_err_x << endl;
        cout << "reg_err_y: " << reg_err_y << endl;
        cout << "reg_err_z: " << reg_err_z << endl;

        //각 제어량의 비례 상수 설정
        const double Kp_x = -10;
        const double Kp_y = 30;
        //        const double Kp_z = R_YAW_MAX;
        const double Kp_z = 10;
        //출력값 결정
        x = Kp_x * reg_err_x;
        y = Kp_y * reg_err_y;
        z = Kp_z * reg_err_z;

        //Side가 바뀌면 YAW방향이 바뀌므로 X, Y는 방향을 바꿔줘야 한다.
        int dir = master->gameControlData.mySide == RIGHT ? 1 : -1;

        //최종 출력
        walkStart(dir*x, dir*y, z);
    }

    return  isArrive;
}
void Goalkeeper::directionprt(int errorx)
{
    for(int i=-0;i<5;i++)
    {
        cout << (errorx >= 0 ? "R                -###############-" : " -###############-                L") << endl;
    }
}

int Goalkeeper::PenaltySave()
{
    cout << "KEEPER_STATE_PENALTY" << endl << endl;
    double ballcamy = master->vision.Ball_cam_Y;
    double ballcamx = master->vision.Ball_cam_X;
    double bs = master->vision.Ball_speed_level;
    double bd = master->vision.Ball_D;
    int errorx = static_cast<int>(ballcamx) - 330;  //230
    int errory = static_cast<int>(ballcamy) - 120;  //110
    dribble = (bs != 0.0 && bd < 1300 && bd != 0.0) ? (bs > 1300 ? false : (bs < 1000 ? true : dribble)) : dribble;
    cout << "errorx --> " << errorx << endl;
    cout << "errory --> " << errory << endl;
    //Oringinal Ball_Cam_X, Ball_Cam_Y --> 230 110

    //로봇이 드리블을 하고있을 때와 하고있지 않을 때의 경우를 나뉘었다.
    if(!dribble)
    {
        cout << "judging ball clac" << endl;
        if(errory > 20 && ballcamy != 0.0)
        {
            directionprt(errorx);
            playMotion(errorx >= 0 ? MOTION_ARM_RIGHT : MOTION_ARM_LEFT);
        }
    }
    else
    {
        robot_state = KEEPER_STATE_KEEPERZONE;
    }

    return 0;
}

void Goalkeeper::gksave()
{
    cout << "keeper state gksave" << endl;
    double lastballx,lastbally;
    double ballcamy = master->vision.Ball_cam_Y;
    double ballcamx = master->vision.Ball_cam_X;
    double bs = master->vision.Ball_speed_level;
    double bd = master->vision.Ball_D;

    if(bs == 0.0 && bd != 0.0)
    {
        lastballx = master->vision.Ball_cam_X;
        lastbally = master->vision.Ball_cam_Y;

        cout << "lastballx  -->"  << lastballx << endl;
        cout << "lastbally  -->"  << lastbally << endl;
        cout << "ballcamx   -->"  << ballcamx  << endl;
        cout << "ballcamy   -->"  << ballcamy  << endl;
        cout << "Ballspeed  -->"  << bs        << endl;
        cout << "Balld      -->"  << bd        << endl;

        if(master->vision.Ball_speed_level >= 1000 && master->vision.Ball_speed_level <= 1500)
        {
            double errory = ballcamy - lastbally;
            double errorx = ballcamx - lastballx;
            if(errory > 20)
            {
                if(errorx > 20 && ballcamy != 0.0)

                    playMotion(errorx >= 0 ? MOTION_ARM_RIGHT : MOTION_ARM_LEFT);
            }
        }
    }
}

} //robocup_master24
