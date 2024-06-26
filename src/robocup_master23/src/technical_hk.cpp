#include "robocup_master23/technical_hk.hpp"
namespace robocup_master23
{

using namespace std;

TECHNICAL_HK::TECHNICAL_HK(MasterRcko *master) :
    Player(master)
{
    cout << endl << "TECHNICAL_HK!!" << endl << endl;
}

bool TECHNICAL_HK::moveToTarget(Point current_coordinates, double current_yaw, Point target_coordinates, int angle_mode, double target_angle, bool dontStop)
{
    //visionPublish(VISION_SCAN_MODE_BALL);
    cout << "moveToTarget" << endl;

    static double ref_angle;

    if(isArrive(current_coordinates, target_coordinates)){
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
                return true;
            }
        }
    } else {
        ref_angle = current_yaw;
        double target_angle = 0;
        calcTargetAngle(target_coordinates, current_coordinates, current_yaw, target_angle);
        cout<<"target_angle : "<<target_angle<<"   current_angle"<<master->imu.yaw<<endl;
        if(alignRobot(current_yaw, target_angle, 5)){
            //            double yaw_correction_value = (yaw_factor / pow(align_threshold, 3)) * pow(target_angle, 3);
            //cout << "target angle: " << target_angle << endl;
            double yaw_correction_value = /*yaw_factor*/3 * fabs(target_angle) / target_angle;
            cout<<"walkstart : "<<endl;
            walkStart(15, 0 , static_cast<int>(yaw_correction_value));//sujung
        }
    }
    return false;

}

bool TECHNICAL_HK::TargetYaw(float robot_yaw, float target_yaw,int z)
{
    cout << "Set_Yaw" << endl;

    static bool off_course = false;

    float yaw_gap = target_yaw - robot_yaw;

    if(fabs(yaw_gap) > 180){
        yaw_gap = yaw_gap*(-1);
    }

    if(fabs(yaw_gap) < 20 / 2) {
        off_course = false;
    }

    if((fabs(yaw_gap) < 20) && !off_course)
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

bool TECHNICAL_HK::TargetYaw2(float robot_yaw, float target_yaw,int z)
{
    cout << "Set_Yaw" << endl;

    static bool off_course = false;

    float yaw_gap = target_yaw - robot_yaw;

    if(fabs(yaw_gap) > 180){
        yaw_gap = yaw_gap*(-1);
    }

    if(fabs(yaw_gap) < 10 / 2) {
        off_course = false;
    }

    if((fabs(yaw_gap) < 10) && !off_course)
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

void TECHNICAL_HK::statePlay()
{
    cout << "TECHNICAL_HK STATE: PLAY" << endl;
    //    int Tracking_flag_C = Tracking(Tracking_thing_x, Tracking_point_x, Tracking_thing_y, Tracking_point_y);

    //highkick_case=========================================================================================================
    switch (highkick_case)
    {
    case MODE_IDLE: //master->local.Robot_X = local_v2Info.x
    {
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_IDLE  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
        //local intercept
        //move(master->local.Ball_X, master->local.Ball_Y);

        moveToTarget(Point(master->local.Robot_X, master->local.Robot_Y),
                                                 master->imu.yaw,
                                                 Point(master->local.Ball_X, master->local.Ball_Y),
                                                 RELATIVE, 0, true);

        if(master->local.Ball_X - 30 < master->local.Robot_X){//20

            moveOkCnt++;
            if(moveOkCnt > 100){
                //                moveOkCnt = 0;
                //                motion_end = 0;
                highkick_case = MODE_BALL_WALK;
                moveOkCnt = 0;
                //walkStop();
            }
        }

//        if(master->local.Robot_X == 800 && master->local.Robot_Y == 400){
//            cout<<endl<<"&&&&&&&&&&  COORDINATE SET(800,400)  &&&&&&&&&&&&"<<endl<<endl;
//            highkick_case = MODE_KICK;

        break;
    }

    case MODE_BALL_WALK:
    {
        if(mode_fix==1){
            highkick_case = MODE_KICK;
        }
        else {
            cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_BALL_WALK  &&&&&&&&&&&&&&&&&&&&&"<<endl;
            cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_BALL_WALK  &&&&&&&&&&&&&&&&&&&&&"<<endl;
            cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_BALL_WALK  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;

            //  (302,411)   (312,413)   ->  x: 300~315
            //  (299,421)   (308,423)   ->  y: 410~423  (ball), cam(0~640, 0~480)

            if(TargetYaw(master->imu.yaw,-90,3)){//yaw맞추기 90은 보는 로봇의 왼쪽

                int x = 18; int y = 0;

                if(master->vision.Ball_cam_X < 310){//go left
                    cout<<"!!left  ";
                    y = 7;
                }
                else if(master->vision.Ball_cam_X > 330){
                    cout<<"!!right  ";
                    y = -7;
                }
                walkStart(x,y,0);

                cout<<" local ball x  : "<<master->local.Ball_X<<endl;
                cout<<" local robot x : "<<master->local.Robot_X<<endl;
                if(master->local.Ball_X < 915){//920
                    cout<<endl<<" local ball x < 900 checked"<<endl;
                    ball_check = 0;
                }
                else if(master->local.Robot_X > 900 && ball_check == 1){
                    cout<<endl<<" local ball x >= 950 checked"<<endl;
                    cout<<endl<<" local robot x > 900 checked"<<endl;
                    walkStop();
                    highkick_case = MODE_KICK;
                }
                else if(master->local.Ball_X >= 915){//920
                    cout<<endl<<" local ball x >= 900 checked"<<endl;
                    ball_check = 1;
                }

                cout<<" ball_check : "<<ball_check<<endl;
            }
        }
        break;
    }

    case MODE_KICK:
    {
        walkStop();
        switch (slide_check)
        {
            case 0:
            {
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK0  &&&&&&&&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK0  &&&&&&&&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK0  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
            //  (305,423)   (310,425)   ->  x: 305~310
            //  (300,428)   (310,431)   ->  y: 428~432  (ball), cam(0~640, 0~480) slide (280~305, 420~440)
                //298,434 296,432
            if(TargetYaw(master->imu.yaw,-90,3)){//yaw맞추기 90은 보는 로봇의 왼쪽
                int x = 0; int y = 0;
                if(master->local.Robot_X >= 925){//N915
                    slide_check = 1;
                }
                else if((296 <=master->vision.Ball_cam_X && master->vision.Ball_cam_X <= 308) &&
                        (426<=master->vision.Ball_cam_Y && master->vision.Ball_cam_Y <= 438) && (master->local.Robot_X >= 915))
                {
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  SLIDEKICK  &&&&&&&&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  SLIDEKICK  &&&&&&&&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  SLIDEKICK  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
                    playMotion(MOTION_SLIDEKICK);
                    slide_check = 1;
                }
                else{
                    if(436 < master->vision.Ball_cam_Y){
                        cout<<"!!back  "<<endl;
                        x = -7;
                        walkStart(x,0,0);
                    }
                    else if(428 > master->vision.Ball_cam_Y){
                        cout<<"!!front  "<<endl;
                        x = 10;//10
                        walkStart(x,0,1);//z = left cali
                    }

                    if(master->vision.Ball_cam_X < 298){//go left
                        cout<<"!!left  "<<endl;
                        y = 7;//7
                        walkStart(0,y,0);
                    }
                    else if(master->vision.Ball_cam_X > 305){
                        cout<<"!!right  "<<endl;
                        y = -7;//-8
                        walkStart(1,y,0);
                    }
                }
            }
                break;
            }
            case 1:
            {
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK1  &&&&&&&&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK1  &&&&&&&&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_KICK1  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
                //  (298,413)   (307,413)   ->  x: 299~305
                //  (299,419)   (306,418)   ->  y: 410~420  (ball), cam(0~640, 0~480) slide (280~305, 420~440)
            if(TargetYaw2(master->imu.yaw,-90,3)){//yaw맞추기 90은 보는 로봇의 왼쪽
                int x = 0; int y = 0;
                if((296 <=master->vision.Ball_cam_X && master->vision.Ball_cam_X <= 308) &&//N296 308
                        (426 <=master->vision.Ball_cam_Y && master->vision.Ball_cam_Y <= 440)){//N426 438
                    cout<<"!!center  "<<endl;
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
                    playMotion(MOTION_HIGHKICK);
//                    walkStop();
//                    if((300 <=master->vision.Ball_cam_X && master->vision.Ball_cam_X <= 315) &&
//                            (410 <=master->vision.Ball_cam_Y && master->vision.Ball_cam_Y <= 423) &&
//                            slide_check == 1 && master->local.Robot_X >= 950){
//                        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&";
//                        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&";
//                        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  HIGHKICK  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
//                        playMotion(MOTION_HIGHKICK);
//                    }
                }
                else{
                    if(438 < master->vision.Ball_cam_Y){
                        cout<<"!!back  "<<endl;
                        x = -7;
                        walkStart(x,0,0);
                    }
                    else if(428 > master->vision.Ball_cam_Y){
                        cout<<"!!front  "<<endl;
                        x = 7;//8
                        walkStart(x,0,1);//z = left cali
                    }

                    if(master->vision.Ball_cam_X < 298){//go left
                        cout<<"!!left  "<<endl;
                        y = 7;//7
                        walkStart(0,y,0);
                    }
                    else if(master->vision.Ball_cam_X > 305){
                        cout<<"!!right  "<<endl;
                        y = -7;//-8
                        walkStart(1,y,0);
                    }
                }
            }
                break;
            }
        }
        break;
    }

    case MODE_STOP:
    {
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_STOP  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;

        walkStop();
        break;
    }
    }

    publishMsg();
}

}

//     odo is 20 ~ 23
