#include "robocup_master23/technical_cl.hpp"
//절대 technical pull하지마!!

int helperTx;
int helperTy;
//colaboration local
namespace robocup_master23 {

using namespace std;


TECHNICAL_CL_K::TECHNICAL_CL_K(MasterRcko *master) :
    Player(master)
{
    //만약 로봇이 안 보였을 때를 대비하여 만들어 놓았다. kicker robot 시작 위치
    master->master2local.mf_robot_x = 480;
    master->master2local.mf_robot_y = 400;
    //    double robotx     = 480;
    //    double roboty     = 400;
    cout << endl << "TECHNICAL_CL_K!!" << endl << endl;
}

TECHNICAL_CL_H::TECHNICAL_CL_H(MasterRcko *master) :
    Player(master)
{
    cout << endl << "TECHNICAL_CL_H!!" << endl << endl;
}




//######################### KICKER ROBOT ###########################
void stateSet();
void TECHNICAL_CL_K::statePlay()
{
//    master->udp_Helper_msg.robot_x_order;
//    master->udp_Helper_msg.robot_y_order;
//    master->udp_Helper_msg.robot_ik_x_order;
//    master->udp_Helper_msg.robot_ik_y_order;
//    master->udp_Helper_msg.robot_ik_yaw_order;


    cout << "TECHNICAL_CL STATE: PLAY" << endl;

    master->gameControlData.mySide  = LEFT;//left

    orderedInfo.robot_num           = master->udp_Helper_msg.robot_num                ;//robot number
    orderedInfo.robot_case          = master->udp_Helper_msg.robot_case               ;//robot case

    //if((orderedInfo.robot_x_order =! 0) || (orderedInfo.robot_y_order =! 0))
    if((master->udp_Helper_msg.robot_x_order != 0) || (master->udp_Helper_msg.robot_y_order != 0))// ball coor
    {
        orderedInfo.robot_x_order       = master->udp_Helper_msg.robot_x_order        ;
        orderedInfo.robot_y_order       = master->udp_Helper_msg.robot_y_order        ;
    }


    if((master->udp_Helper_msg.robot_ik_x_order != 0) || (master->udp_Helper_msg.robot_ik_y_order != 0))//robot coor
    {
        orderedInfo.robot_ik_x_order    = master->udp_Helper_msg.robot_ik_x_order     ;
        orderedInfo.robot_ik_y_order    = master->udp_Helper_msg.robot_ik_y_order     ;
    }

    orderedInfo.ball_x              = master->udp_Helper_msg.ball_x                   ;
    orderedInfo.ball_y              = master->udp_Helper_msg.ball_y                   ;

    orderedInfo.ballDist            = master->udp_Helper_msg.ballDist             ;//쓸모 x
    orderedInfo.ballTheta           = master->udp_Helper_msg.ballTheta            ;//쓸모 x

    //Kicker_case = MODE_TEST;
    switch (Kicker_case)
    {
      case READY:
        cout << "&&&&&&&&&&&&&&&&&&&  READY  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
        walkStart(10,0,0);
        break;
      case MOVE:
        robotx = master->udp_Helper_msg.robot_x_order;
        roboty = master->udp_Helper_msg.robot_y_order;
        ballx =  master->udp_Helper_msg.ball_x;
        bally = master->udp_Helper_msg.ball_y;


        cout << "&&&&&&&&&&&&&&&&&&&  MOVE  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;

        cout << "Robot x, y : (" << robotx << ", " << roboty << " )" << endl;
        cout << "Ball x, y : (" << ballx << ", " << bally << " )" << endl;

        if(robotx == 0 && roboty == 0){
          walkStart(10,0,0);
        }
        else
          move(ballx, bally);
                if(TargetYaw(master->imu.yaw,90,3))
                {
                    if(orderedInfo.robot_y_order - 5 > roboty)//go left
                    {
                        cout<<endl<<"LEFT"<<endl;
                        walkStart(0,6,0);
                    }
                    else if(orderedInfo.robot_y_order + 5 < roboty)//go right
                    {
                        cout<<endl<<"RIGHT"<<endl;
                        walkStart(0,-6,0);
                    }
                    else
                    {
                        walkStop();
                    }
                }
        master->local.Robot_X = robotx;
        master->local.Robot_Y = roboty;

      break;
    case KICK:
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
        Kick_cnt++;
        if(Kick_cnt > 2000)
        {
            master->local.Robot_X = robotx;
            master->local.Robot_Y = roboty;

            filterx = robotx; filtery = roboty;
            if(orderedInfo.robot_ik_x_order != 0 && orderedInfo.robot_ik_y_order != 0){
            cout<<"in"<<endl;
            robotx = orderedInfo.robot_ik_x_order;
            roboty = orderedInfo.robot_ik_y_order;

            filterx = filterx*(1-filterparam) + filterparam*robotx;
            filtery = filtery*(1-filterparam) + filterparam*roboty;
                                    }
            cout<< "filter : " <<filterx << "," <<filtery <<endl;

            master->master2local.mf_robot_x = filterx;
            master->master2local.mf_robot_y = filtery;

        }
            if(kickOK){
            cout<<"kickOK"<<boolalpha<<kickOK<<endl;
            walkStop();
            //Kicker_case         = MODE_STANDBY;
            kickOK              = false;
            Kick_cnt            = 0;
        }
        break;
    default:
      break;
    }

    //kicker msg time
    mystate.robot_num            = master->gameControlData.robotNum;
    mystate.robot_case           = Kicker_case;

    mystate.local_x              = master->local.Robot_X;
    mystate.local_y              = master->local.Robot_Y;
    mystate.local_yaw            = master->imu.yaw;

    //mystate publish
    master->collabo_kicker_publish(mystate);
    publishMsg();


}



//##################################################################
//
//######################### HELPER ROBOT ###########################
//
//##################################################################

void TECHNICAL_CL_H::statePlay()
{
    cout << "TECHNICAL_CL STATE: PLAY" << endl;

    master->udp_Helper_msg.robot_ik_x_order;
    master->udp_Helper_msg.robot_ik_y_order;
    master->udp_Helper_msg.robot_case = mode;


    switch(mode)
    {
    case READY:
//kicker walk start is end
        if(master->local.Ball_X > 250)//so far
        {
            cout<<"BALL IS SO FAR"<<endl;
            //walkStart(40,0,0);
        }
        break;
    case MOVE:
        master->udp_Helper_msg.robot_x_order = master->local.Obstacle_X;
        master->udp_Helper_msg.robot_y_order = master->local.Obstacle_Y;
        master->udp_Helper_msg.ball_x = master->vision.Ball_2d_X;
        master->udp_Helper_msg.ball_y = master->vision.Ball_2d_Y;


        //compare to helper sending ik(basis local), kicker sending ik(move to target
        //kicker) callback data average position(x,y order) select
        //helper) callback kicker's ik
        if(master->local.Obstacle_X - master->vision.Ball_2d_X < 50 && master->local.Obstacle_Y - master->vision.Ball_2d_Y < 50)
        {
            mode = KICK;
        }

        break;
    case KICK:

        break;
    default:

        break;
    }

    orderInfo.ball_x = master->udp_Helper_msg.ball_x;
    orderInfo.ball_y = master->udp_Helper_msg.ball_y;
    orderInfo.robot_x_order = master->udp_Helper_msg.robot_x_order;
    orderInfo.robot_y_order = master->udp_Helper_msg.robot_y_order;
//    orderInfo.robot_case = master
    master->collabo_helper_publish(orderInfo);
    publishMsg();


}//helper


Point TECHNICAL_CL_K::calcShootPoint(Point goal_coor, Point ball_coor)
{
    const double cali_radius = 20;

    Point A, B;
    A = goal_coor;
    B = ball_coor;

    double Qx, Qy;
    int x1, x2, y1, y2;

    x1 = A.x();
    x2 = B.x();
    y1 = A.y();
    y2 = B.y();

    double ball_dist = hypot(x2 - x1, y2 - y1);

    double m, n;
    m = 1;
    n = 1 + cali_radius / ball_dist;

    Qx = (x2 - x1) * n + x1;
    Qy = (y2 - y1) * n + y1;

    Point target_coor = Point(Qx, Qy);

    return target_coor;
}
bool TECHNICAL_CL_K::TargetYaw(float robot_yaw, float target_yaw,int z)
{
    cout << "Set_Yaw" << endl;

    static bool off_course = false;

    float yaw_gap = target_yaw - robot_yaw;

    if(fabs(yaw_gap) > 180){
        yaw_gap = yaw_gap*(-1);
    }

    if(fabs(yaw_gap) < 16 / 2) {
        off_course = false;
    }

    if((fabs(yaw_gap) < 13) && !off_course)
    {
        //walkStop();
        return true;
    } else {
        off_course = true;

        float yaw = z * yaw_gap / fabs(yaw_gap);

        walkStart(0, 0, static_cast<int>(yaw));

        return false;
    }
}
bool TECHNICAL_CL_H::TargetYaw(float robot_yaw, float target_yaw,int z)
{
    cout << "Set_Yaw" << endl;

    static bool off_course = false;

    float yaw_gap = target_yaw - robot_yaw;

    if(fabs(yaw_gap) > 180){
        yaw_gap = yaw_gap*(-1);
    }

    if(fabs(yaw_gap) < 18 / 2) {
        off_course = false;
    }

    if((fabs(yaw_gap) < 15) && !off_course)
    {
        //walkStop();
        return true;
    } else {
        off_course = true;

        float yaw = z * yaw_gap / fabs(yaw_gap);

        walkStart(0, 0, static_cast<int>(yaw));

        return false;
    }
}
void TECHNICAL_CL_K::kick_odo(){





}
void TECHNICAL_CL_K::kick_yun(Point ball_loc, Point robot_loc){

    cout<<"kick yun~~"<<endl;

    //ball_loc = orderedInfo.robot_y_order
    //robot_loc = orderedInfo.robot_ik_y_order


    //    ball_loc.setX();
    //    ball_loc.setY();


    int yaw_param = 90;

    if( yawCali ){
        if(ball_loc.y() < 360)yaw_param = 100;
        else if(ball_loc.y() > 450)yaw_param = 80;
        else yaw_param = 90;
//        YawOk = true;
    }


    if(TargetYaw(master->imu.yaw,yaw_param,3)){//yaw맞추기 90은 보는 로봇의 왼쪽

        int x = 0; int y = 0; int z = 0;

        if(robot_loc.y() + 2  < ball_loc.y() - 3 ){//go left
            cout<<"!!left  ";
            y = 12;//7;//6
        }
        else if(robot_loc.y() + 2   >  ball_loc.y() +3){//right
            cout<<"!!right  ";
            y = -12;//-10;//-6
        }
        else{
            cout<<"!!center  ";
            y = 0;

            if(robot_loc.x() -/*20*/15  > ball_loc.x() + 3){
                cout<<"and front!!";
                x = 20;//30
            }
            else if(robot_loc.x() -/*20*/15 < ball_loc.x() - 3 ){
                cout<<"and back!!";
                x = -10;

            }
            else {
                cout<<"and center!!";
                x = 0;
            }
        }//shgu
        cout<<endl;
        cout<<"state robot x: "<<robot_loc.x()-5<<" y: "<<robot_loc.y()+5<<endl;
        cout<<"state ball  x: "<<ball_loc.x() <<" y: "<<ball_loc.y()<<endl;

        //cout<<" x gap :"<<robot_loc.x() - ball_loc.x()<<" y gap : "<<robot_loc.y() - ball_loc.y()<<endl;
        cout<<" x :"<<x<<" y :"<<y<<endl;

        if( x == 0 && y == 0){
            kick_check_cnt++;
        }
        else if(kick_check_cnt<50){
            kick_check_cnt = 0;
        }

        if(kick_check_cnt > 50) yawCali = true;


//        if( yawCali ){
//            if(ball_loc.y() < 360)yaw_param = 100;
//            else if(ball_loc.y() > 450)yaw_param = 80;
//            else yaw_param = 90;

//        }
//        cout<<yaw_param<<endl;
//        cout<<yaw_param<<endl;
//        cout<<yaw_param<<endl;



//        cout<<"kick_cnt"<<kick_check_cnt<<endl;
//        if(YawOk&&Kick_cnt >200){
//            if(!kickOK){
//                cout<<"kickOK play motion"<<endl;
//                if(playKickMotion(99))
//                {
//                    kickOK  = true;
//                    YawOk   = false;
//                    yawCali = false;
//                    kick_check_cnt = 0;
//                }
//            }

//        }


                cout<<"yaw_param!!"<<yaw_param<<endl;
                cout<<"yaw_param!!"<<yaw_param<<endl;
                cout<<"yaw_param!!"<<yaw_param<<endl;

        cout<<"kick_cnt"<<kick_check_cnt<<endl;
//        if(TargetYaw(master->imu.yaw,yaw_param,3))
//        {
            if(kick_check_cnt >= 50){
                if(!kickOK){
                    cout<<"kickOK play motion"<<endl;
                    if(playKickMotion(99))
                    {
                        kickOK = true;
                        kick_check_cnt = 0;
                    }
                }
            }
//        }


            walkStart(x,y,0);



    }//target yaw
}
void TECHNICAL_CL_K::kick3()
{

    //    orderedInfo.ball_x              = master->udp_Helper_msg.ball_x               ;
    //    orderedInfo.ball_y              = master->udp_Helper_msg.ball_y               ;
    Point globalBall(orderedInfo.ball_x, orderedInfo.ball_y);
    Point globalRobot(orderedInfo.robot_ik_x_order, orderedInfo.robot_ik_y_order);

    //    Point globalBall(master->local.Ball_X, master->local.Ball_Y);//sujung
    //    Point globalRobot(master->local.Robot_X, master->local.Robot_Y);//sujung

    Point goalPoint = opponent_goal;
    Point p = calcShootPoint(goalPoint, globalBall);

    if(moveToTarget(globalRobot, master->imu.yaw, p, OPPONENT, 0, true))
    {
        cout << "arrive" << endl;
        if(caliToBall())
        {

            //d（왼발오른발
            cout << "caliOK" << endl;
            int kick_mode;
            //            if(master->vision.Ball_2d_X > 0) {
            if(orderedInfo.ball_y>orderedInfo.robot_y_order){
                kick_mode = FRONT_LEFT;
            }
            else
            {
                kick_mode = FRONT_RIGHT;
            }
            playKickMotion(kick_mode);//kick motion
            kickOK = true;
        }
    }

    master->master2local.target_x = p.x();
    master->master2local.target_y = p.y();
}
bool TECHNICAL_CL_K::go2target_yun(){

    //calcTargetAngle(calcPoint,robotcool,-90)// 이거 입력 각도 기준으로 좌표로 각도 계산해줌. 주의할점 0도 쪽이랑 180도 쪽
    Point robot_cool(orderedInfo.robot_ik_x_order,orderedInfo.robot_ik_y_order);
    Point target_cool(orderedInfo.robot_x_order,orderedInfo.robot_x_order);

    int targetDIS = 0;
    if(TargetYaw(master->imu.yaw,calcTargetAngle(robot_cool,target_cool,90),6)){//각도 맞췄따면.

        walkStart(15,0,0);

        targetDIS = sqrt( (robot_cool.x() - target_cool.x())*(robot_cool.x() - target_cool.x())
                          + (robot_cool.y()-target_cool.y())*(robot_cool.y()-target_cool.y()));

        if(targetDIS < 35){

            return true;
        }
    }


    return false;
}
bool TECHNICAL_CL_K::caliToBall() //local base
{

    cout<<"cali!!!!!!!!!!!"<<endl;
    const int velX = 10;//무슨값이냐
    const int velY = 5;
    Point localBall;

    if(orderedInfo.robot_ik_x_order < 550)//left
    {
        localBall.setX(orderedInfo.robot_ik_y_order-orderedInfo.ball_y);
        localBall.setY(orderedInfo.robot_ik_x_order-orderedInfo.ball_x);//sujung
        cout<<"left!!!!!!!!"<<endl;

    }
    else
    {
        localBall.setX(orderedInfo.ball_y - orderedInfo.robot_ik_x_order);
        localBall.setY(orderedInfo.ball_x-orderedInfo.robot_ik_x_order);//sujung
        cout<<"right!!!!!!"<<endl;
    }

    cout<<"cali : "<<localBall.x()<<" , "<<localBall.y()<<endl;
    //Point localBall(master->vision.Ball_2d_X, master->vision.Ball_2d_Y);//sujung

    //30~100, 80~120

    if(abs(localBall.x()) > 30 &&
            abs(localBall.x()) < 100 &&
            localBall.y() > 80 &&
            localBall.y() < 120)
    {
        return true;
    }

    int y = 0;
    int x = 0;

    if(localBall.x() > 70)
    {
        y = -velY;
    }
    else if(localBall.x() > 0)
    {
        y = velY;
    }
    else if(localBall.x() < -70)
    {
        y = velY;
    }
    else
    {
        y = -velY;
    }

    if(localBall.y() > 200)
    {
        x = velX;
    }


    cout<<"walkstart : "<<"("<< x <<","<< y <<")"<<endl;
    walkStart(x,y,0);

    return false;
}

}//namespace robocup_master23
