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
        if(ballPoint.x() > 1000 - 200) //origin = 10
        {
            keeperZoneX = true;
        }
    }
    else
    {
        targetyaw = -90;
        if(ballPoint.x() < 100 + 200)
        {
            keeperZoneX = true;
        }
    }

    if(master->gameControlData.mySide == RIGHT)
    {
      Robot2Box = 800 - master->local.Robot_X;
    }
    else
    {
      Robot2Box = master->local.Robot_X - 300;
    }
    Ball2Robot = abs(sqrt(pow(master->local.Robot_X - master->local.Ball_X, 2) + pow(master->local.Robot_Y - master->local.Ball_Y, 2)));

    if (ballPoint.x() != 0 && ballPoint.y() != 0)
    {
      previous_ball_x = ballPoint.x();
      previous_ball_y = ballPoint.y();
    }

    if(master->gameControlData.secondState == STATE2_PENALTYKICK)
    {
        robot_state = MODE_Penalty;
    }
//    else if(master->local.Robot_Y < 400 - goalOffset || master->local.Robot_Y > 400 + goalOffset)
//    {
//         robot_state = KEEPER_STATE_QUICK_BACK;
//    }
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
        robot_state = KEEPER_STATE_SIDEBALL;
    }

    if(Ball2Robot < 20 || (master->vision.Ball_D < 300 && master->vision.Ball_D > 0))
    {
      robot_state = KEEPER_STATE_JUST_KICK;
    }

    if(crouch_flag)
    {
      robot_state = KEEPER_STATE_CROUCH;
    }

    if(master->local.Robot_X >= 310 && master->local.Robot_X <= 790)
    {
      robot_state = KEEPER_STATE_OUT_OF_BOX;
    }

    //robot_state = MODE_TEST;
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

    //for 2024.05.07
    if(master->gameControlData.mySide == RIGHT)
    {
        homePoint = Point(1100 - frontOffset, 400);
    }
    else
    {
        homePoint = Point(0 + frontOffset, 400);
    }

    //playSaveMotion();
    //gksave();
    switch (robot_state)
    {
    case MODE_TEST:
    {
        //kick3();
        //gksave();
      cout << "---------- MODE_TEST ----------" << endl;
      cout << "test_cnt : " << test_cnt << endl;
      test_cnt++;
      if(test_cnt == 3000 && up_flag == false)
      {
        cout << "!!!!!!!! DOWN !!!!!!!!" << endl;
        playMotion(MOTION_CROUCH_1);
        up_flag = true;
      }

      if(up_flag == true)
      {
        cout << "!!!!!!!! UP !!!!!!!!" << endl;
        playMotion(MOTION_CROUCH_2);
        test_cnt = 0;
        up_flag = false;
      }
      cout << "!!!!!!!!!! UP_FLAG : " << up_flag << endl;
      break;
    }
    case KEEPER_STATE_OUT_OF_BOX:
    {
      cout<< "---------- KEEPER_STATE_OUT_OF_BOX ----------" << endl;
      stop_cnt++;
      if(stop_cnt <= 1000)
      {
        walkStop();
        cout << "THINKING,,,,,,,,,,,, STOP_CNT : " << stop_cnt << endl;
      }
      else
      {
        cout << "Ball2Robot : " << Ball2Robot << ", Robot2Box : " << Robot2Box << endl;

        if (Ball2Robot < Robot2Box)
        {
          kick3();
          cout << "!!!!!!!! JUST KICK !!!!!!!!" << endl;
        }
        else
        {
          //walkStart(-30, 0, 2);

          cout << "!!!!!!!! BACK !!!!!!!!" << endl;
        }

      }

//      if(robot_state != KEEPER_STATE_OUT_OF_BOX)
//      {
//        stop_cnt = 0;
//      }

      break;
    }
    case ROBOT_STATE_NOBALL:
    {
        cout << "---------- ROBOT_STATE_NOBALL ----------" << endl;
        cout << "HOMEPOINT.X = " << homePoint.x() << ", HOMEPOINT.Y = " << homePoint.y() << endl;

        noball_cnt++;
        cout << "THINKING,,,,,,,,,,,, NOBALL_CNT : " << noball_cnt << endl;
        if(noball_cnt == 1)
        {
          previous_yaw = master->imu.yaw;
        }

        //공이 없는 경우 예외처리
//        if(moveSideOnly(homePoint))
//        {
//            walkStop();
//            cout << "!!!!!!!! YEAH ROBOT IS ON HOMEPOINT !!!!!!!!" << endl;
//        }

        //CODE USING UDP
        /*
        if(master->master2udp.ball_coor_x != 0 && master->master2udp.ball_coor_x > 465 && master->master2udp.ball_coor_x < 635)
        {
          cout << "!!!!!!!! NOT MY BUSINESS !!!!!!!!" << endl;
          walkStop();
        }
        else
        {
          if(master->local.Robot_X >930 || master->local.Robot_X <170)
          {
            if(moveSideOnly(homePoint))
            {
                walkStop();
                cout << "!!!!!!!! YEAH ROBOT IS ON HOMEPOINT !!!!!!!!" << endl;
            }
          }
          else
          {
            if(noball_cnt >= 1000)
            {
              if(previous_ball_y >= master->local.Robot_Y)
              {
                walkStart(0, 0, 8);
                cout << "!!!!!!!! TURN LEFT TO FIND BALL !!!!!!!!" << endl;
              }
              else
              {
                walkStart(0, 0, -8);
                cout << "!!!!!!!! TURN RIGHT TO FIND BALL !!!!!!!!" << endl;
              }
//              walkStart(0, 0, 8);
//              cout << "!!!!!!!! TURN LEFT TO FIND BALL !!!!!!!!" << endl;


              if(master->local.Ball_X != 0.0 && master->local.Ball_Y != 0.0)
              {
                noball_cnt = 0;
                kick3();
                cout << "!!!!!!!! ROBOT FIND BALL !!!!!!!!" << endl;
              }
            }
          }
        }
        */


        // CODE NOT USING UDP
        if(master->local.Robot_X >930 || master->local.Robot_X <170)
        {
          if(moveSideOnly(homePoint))
          {
              walkStop();

              cout << "!!!!!!!! YEAH ROBOT IS ON HOMEPOINT !!!!!!!!" << endl;
          }
        }
        else
        {
          if(noball_cnt >= 1000)
          {
            if(previous_ball_y >= master->local.Robot_Y)
            {
              walkStart(0, 0, 8);
              if(previous_yaw + 0 >= master->imu.yaw && previous_yaw - 5 <= master->imu.yaw)
              {
                cout << "!!!!!!!! CAN'T FIND !!!!!!!!" << endl;
                walkStop();
              }
              cout << "!!!!!!!! TURN LEFT TO FIND BALL !!!!!!!!" << endl;
            }
            else
            {
              walkStart(0, 0, -8);
              if(previous_yaw + 5 >= master->imu.yaw && previous_yaw - 0 <= master->imu.yaw)
              {
                cout << "!!!!!!!! CAN'T FIND !!!!!!!!" << endl;
                walkStop();
              }
              cout << "!!!!!!!! TURN RIGHT TO FIND BALL !!!!!!!!" << endl;
            }
//            walkStart(0, 0, 8);
//            cout << "!!!!!!!! TURN AROUND TO FIND BALL !!!!!!!!" << endl;

            if(master->local.Ball_X != 0.0 && master->local.Ball_Y != 0.0)
            {
              noball_cnt = 0;
              kick3();
              cout << "!!!!!!!! ROBOT FIND BALL !!!!!!!!" << endl;
            }
          }
        }

        break;
    }
    case KEEPER_STATE_KEEPERZONE:
    {
        cout << "---------- KEEPER_STATE_KEEPERZONE ----------" << endl;
        //당장 공을 걷어내기
        kick3();

        break;
    }
    case KEEPER_STATE_CENTER:
    {
        cout << "---------- KEEPER_STATE_CENTER ----------" << endl;

        //공과 직선이 되도록 위치 선정
        int target_x = homePoint.x();
        int target_y = ballPoint.y();

        Point targetPoint(target_x, target_y);
        if ((ballPoint.x() > 310 && master->gameControlData.mySide == LEFT) || (ballPoint.x() <790 && master->gameControlData.mySide == RIGHT)) //if ball is out of KEEPER_BOX
        {
          if(moveSideOnly(targetPoint))
          {
            walkStop();
            cout <<"!!!!!!!! YEAH ROBOT IS STOP AND CENTER TO BALL !!!!!!!!" << endl;
          }
        }
        else
        {
          kick3();
          cout <<"!!!!!!!! KICK BALL !!!!!!!!" << endl;cout << "master->vision.Ball_cam_X : " << master->vision.Ball_cam_X <<endl;
        }
        break;
    }
//    case KEEPER_STATE_QUICK_BACK :
//    {
//        cout << "---------- KEEPER_STATE_QUICK_BACK ----------" << endl;
//        Player::stateReady(homePoint);
//        break;
//    }
    case KEEPER_STATE_SIDEBALL:
    {
        cout << "---------- KEEPER_STATE_SIDEBALL ----------" << endl;

        //이전 코드

        //offset point에기서 공 바라보기
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
//        double res = sqrt(pow(120 - master -> local.Robot_X, 2) + pow(400 - master -> local.Robot_Y, 2));

//        if(res >= 166.0)
//        {
//            qb = true;
//            robot_state = KEEPER_STATE_QUICK_BACK;
//            if(res <= 25.0)
//                qb = false;
//        }

        //최신 코드 (TargetYaw함수에서 오류 발생)
        /*
        //offset point에서 공 바라보기
        int target_x = homePoint.x();
        int target_y = ballPoint.y();

        int xLimitH = 400 + goalOffset;
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
          //double targetAngle = calcTargetAngle(ballPoint, myPoint, robot_yaw);

          if(TargetYaw(master->imu.yaw, static_cast<float>(targetyaw),6))
          {
            walkStop();
          }
         }up_flag = true;

         break;
         */
        break;
    }
    case KEEPER_STATE_JUST_KICK:
    {
      cout << "---------- KEEPER_STATE_JUST_KICK ----------" << endl;
      if(Ball2Opponent() > 0 && Ball2Opponent() < 30)
      {
        crouch_flag = true;
        walkStop();
      }
      else
      {
        kick3();
        cout << "!!!!!!!! JUST KICK !!!!!!!!" << endl;
      }
      break;
    }
    case KEEPER_STATE_CROUCH:
    {
      cout << "---------- KEEPER_STATE_CROUCH ----------" << endl;
      cout << "Ball2Opponent             : " << Ball2Opponent() <<endl;
      cout << "UP_FLAG                   : " << motion_cnt <<endl;
      cout << "master->vision.Ball_cam_X : " << master->vision.Ball_cam_X <<endl;
      cout << "master->vision.Ball_cam_Y : " << master->vision.Ball_cam_Y <<endl<<endl;
      //playCrouchMotion(MOTION_CROUCH_1, MOTION_CROUCH_2);

      if(up_flag == false)
      {
        cout << "!!!!!!!! DOWN !!!!!!!!" << endl;
        playCrouchMotion(MOTION_CROUCH_1);
        //motion_cnt++;-
        if(motion_end == true)
        {
          up_flag = true;
        }
      }
      else if(up_flag == true)
      {
        if((master->local.Ball_X == 0.0 && master->local.Ball_Y == 0.0) || (master->master2udp.ball_coor_x == 0 && master->master2udp.ball_coor_x == 0) || (master->vision.Ball_cam_X == 0 && master->vision.Ball_cam_Y == 0))
        {
          cout << "!!!!!!!! UP !!!!!!!!" << endl;
          playCrouchMotion(MOTION_CROUCH_2);
          //motion_cnt = 0;
          crouch_flag = false;
          up_flag = false;
        }
      }
      break;
    }
      //나중에 페널티킥 할 때 활성화시키기
//    case MODE_Penalty:
//    {
//        PenaltySave();
//        break;
//    }
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
        const double Kp_z = 12;  //origin 10
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

double Goalkeeper::Ball2Opponent()
{
  Point ballPoint(static_cast<int>(master->local.Ball_X), static_cast<int>(master->local.Ball_Y));
  Point obstacle_0(static_cast<int>(master->local.Obstacle0_X), static_cast<int>(master->local.Obstacle0_Y));
  Point obstacle_1(static_cast<int>(master->local.Obstacle1_X), static_cast<int>(master->local.Obstacle1_Y));
  Point obstacle_2(static_cast<int>(master->local.Obstacle2_X), static_cast<int>(master->local.Obstacle2_Y));
  Point obstacle_3(static_cast<int>(master->local.Obstacle3_X), static_cast<int>(master->local.Obstacle3_Y));

  double Ball2Obs[4] = {calcDistance(ballPoint, obstacle_0), calcDistance(ballPoint, obstacle_1), calcDistance(ballPoint, obstacle_2), calcDistance(ballPoint, obstacle_3)};
  Ball2Opponent_Dist = Ball2Obs[0];

  for(int i = 0; i < 4; i++)
  {
    if (Ball2Opponent_Dist > Ball2Obs[i])
    {
      Ball2Opponent_Dist = Ball2Obs[i];
    }
  }

  return Ball2Opponent_Dist;
}

bool Goalkeeper::playCrouchMotion(int motion_num_1)
{
  cout << "!!!!!!!! CROUCH MOTION !!!!!!!!"<< endl;
  cout << master->motionEnd.motion_end << endl;
  master->motion.Motion_Mode = 1;
  master->motion.Motion_Num = motion_num_1;
  cout << "MOTION_CNT : " << motion_cnt << endl;
  cout << "MOTION_END : " << motion_end << endl;

  master->motionPub.publish(master->motion);

  if(master->motionEnd.motion_end)
  {
    if(motion_end == false)
    {
      motion_end = true;
    }
    else
    {
      motion_end = false;
    }

  }

  return motion_end;
}

} //robocup_master23
