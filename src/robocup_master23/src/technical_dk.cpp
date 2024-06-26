#include "robocup_master23/technical_dk.hpp"
namespace robocup_master23
{

using namespace std;

TECHNICAL_DK_K::TECHNICAL_DK_K(MasterRcko *master) :
    Player(master)
{
    cout << endl << "TECHNICAL_DK_K!!" << endl << endl;
}

double TECHNICAL_DK_K::BallSpeed()
{
  double Ball_V = 0;
  Ball_V = sqrt(pow(master->local.Ball_speed_X - master->vision.Ball_2d_X, 2) + pow(master->local.Ball_speed_Y - master->vision.Ball_2d_Y, 2));
  return Ball_V;
}

void TECHNICAL_DK_K::PRINTDKINFO()
{
  cout<<"BALL DISTANCE : "<< master->vision.Ball_D <<endl;
  cout<<"BALL SPEED : "<< BallSpeed() <<endl;
  cout<<"PAN POSITION : "<< master->vision.PAN <<endl;
  cout<<"BALL CAM X : "<<master->vision.Ball_cam_X<<endl;
  cout<<"BALL CAM Y : "<<master->vision.Ball_cam_Y<<endl;
  cout<<"kick_time : "<<temp_time_dk<<endl;
}

void TECHNICAL_DK_K::PRINTFAILINFO(int i)
{
    cout<<"FAIL INFO: ";

    switch(i)
    {
    case 0:
    {
        cout<<"non"<<endl;
        cout<<"non"<<endl;
        cout<<"non"<<endl;
        cout<<"non"<<endl;
        cout<<"non"<<endl;
        break;
    }
    case 1:
    {
        cout<<"OUT OF 1st LINE RANGE"<<endl;
        cout<<"OUT OF 1st LINE RANGE"<<endl;
        cout<<"OUT OF 1st LINE RANGE"<<endl;
        cout<<"OUT OF 1st LINE RANGE"<<endl;
        cout<<"OUT OF 1st LINE RANGE"<<endl;
        break;
    }
    case 2:
    {
        cout<<"1st LINE PASS, BUT 2nd LINE NOT PASS"<<endl;
        cout<<"1st LINE PASS, BUT 2nd LINE NOT PASS"<<endl;
        cout<<"1st LINE PASS, BUT 2nd LINE NOT PASS"<<endl;
        cout<<"1st LINE PASS, BUT 2nd LINE NOT PASS"<<endl;
        cout<<"1st LINE PASS, BUT 2nd LINE NOT PASS"<<endl;
        break;
    }
    case 3:
    {
        cout<<"2nd LINE NOT PASS"<<endl;
        cout<<"2nd LINE NOT PASS"<<endl;
        cout<<"2nd LINE NOT PASS"<<endl;
        cout<<"2nd LINE NOT PASS"<<endl;
        cout<<"2nd LINE NOT PASS"<<endl;
        break;
    }
    case 4:
    {
        cout<<"OUT OF 2nd LINE RANGE"<<endl;
        cout<<"OUT OF 2nd LINE RANGE"<<endl;
        cout<<"OUT OF 2nd LINE RANGE"<<endl;
        cout<<"OUT OF 2nd LINE RANGE"<<endl;
        cout<<"OUT OF 2nd LINE RANGE"<<endl;
        break;
    }
    case 5:
    {
        cout<<"BALL IS TO SLOW"<<endl;
        cout<<"BALL IS TO SLOW"<<endl;
        cout<<"BALL IS TO SLOW"<<endl;
        cout<<"BALL IS TO SLOW"<<endl;
        cout<<"BALL IS TO SLOW"<<endl;
        break;
    }
    case 6:
    {
        cout<<"BALL IS TO FAST"<<endl;
        cout<<"BALL IS TO FAST"<<endl;
        cout<<"BALL IS TO FAST"<<endl;
        cout<<"BALL IS TO FAST"<<endl;
        cout<<"BALL IS TO FAST"<<endl;
        break;
    }
    default:
    {
        cout<<"ERROR ERROR ERROR"<<endl;
        cout<<"ERROR ERROR ERROR"<<endl;
        cout<<"ERROR ERROR ERROR"<<endl;
        cout<<"ERROR ERROR ERROR"<<endl;
        cout<<"ERROR ERROR ERROR"<<endl;
        break;
    }
    }

}

void TECHNICAL_DK_K::statePlay()
{

    //visionPublish(VISION_SCAN_MODE_BALL);

    cout << "TECHNICAL_DK_K STATE: PLAY" << endl;

    pan = paninit;

    temp_time_dk++;

    switch (Kicker_case)
    {
      PRINTDKINFO();
    case MODE_TEST:
    {
        cout<<endl<<"&&&&&&&&&&&&&&&  MODE_TEST &&&&&&&&&&&&&&&"<<endl<<endl;
        PRINTDKINFO();
        stop_cnt++;
        if(ready_mode == 0)
        {
            cout<<endl<<"&&&&&&&&&&&&&&&  READY &&&&&&&&&&&&&&&"<<endl<<endl;
            playMotion(MOTION_READY);
            ready_mode = 1;
        }
        if(stop_cnt > 1500) {
            Kicker_case = MODE_WAIT;
            stop_cnt = 0;
        }
        break;

    }
    case MODE_WAIT: //BALL STATE 1
    {
//        PRINTDKINFO();
        cout<<endl<<"&&&&&&&&&&&&&&&  MODE_WAIT  &&&&&&&&&&&&&&&"<<endl<<endl;

//        if(master->vision.Ball_D != 0 && ball_state == 0) { //공의 유무
        if(master->vision.Ball_cam_Y != 0 && ball_state == 0) {
        //if(master->local.Ball_Y != 0 && ball_state == 0) {
            if(first_cam_Y <= master->vision.Ball_cam_Y && master->vision.Ball_cam_Y < second_cam_Y) { //첫 번째 공 지점(mid line)
            //if(master->local.Ball_Y >= first_loc_Y) {
                if(first_cam_min_X < master->vision.Ball_cam_X && master->vision.Ball_cam_X < first_cam_max_X) {//재시도 처리
                //if(first_loc_min_X < master->local.Ball_X && master->local.Ball_X < first_loc_max_X) {
                    ball_state = 1;
                    p1balltime = temp_time_dk;

                    p1x = master->vision.Ball_cam_X;
                    p1y = master->vision.Ball_cam_Y;
//                    p1x = master->local.Ball_X;
//                    p1y = master->local.Ball_Y;
                    Kicker_case = MODE_FAR_BALL;
                }
                else {
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 1st LINE RANGE  &&&&&&&&&&&&&&&"<<endl<<endl;
                    kickyn = 0;
                    fail_mode = 1;
                    playMotion(MOTION_FAIL);
                    Kicker_case = MODE_END;
                }
            }
        }
        break;
    }
    case MODE_FAR_BALL: //BALL STATE 2
    {
        cout<<endl<<"&&&&&&&&&&&&&&&  MODE_FAR_BALL  &&&&&&&&&&&&&&&"<<endl<<endl;
        cout<<ball_state<<endl;
        PRINTDKINFO();

        if(master->vision.Ball_cam_Y >= second_cam_Y) { //두 번째 공 지점(front line)
        //if(master->local.Ball_Y >= second_loc_Y) {
            if(second_cam_min_X < master->vision.Ball_cam_X && master->vision.Ball_cam_X < second_cam_max_X) { //재시도 처리
            //if(second_loc_min_X < master->local.Ball_X && master->local.Ball_X < second_loc_max_X) {
                ball_state = 2;
                p2balltime = temp_time_dk;

                p2x = master->vision.Ball_cam_X;
                p2y = master->vision.Ball_cam_Y;
//                p2x = master->local.Ball_X;
//                p2y = master->local.Ball_Y;

                cout << "&&&&&&&&&&&  ( p1x, p1y )  : ( " << p1x << ", " << p1y << "  )&&&&&&&&&&&" << endl;
                cout << "&&&&&&&&&&&  ( p1x, p1y )  : ( " << p1x << ", " << p1y << "  )&&&&&&&&&&&" << endl;
                cout << "&&&&&&&&&&&  ( p2x, p2y )  : ( " << p2x << ", " << p2y << "  )&&&&&&&&&&&" << endl;
                cout << "&&&&&&&&&&&  ( p2x, p2y )  : ( " << p2x << ", " << p2y << "  )&&&&&&&&&&&" << endl;

                temp_bv = 5 * 500 / (p2balltime - p1balltime);//
                kick_time = 1000 / temp_bv; //500->1000

                cout << endl << "&&&&&&&&&&&  p1balltime  " << p1balltime << " &&&&&&&&&&&";
                cout << endl << "&&&&&&&&&&&  p1balltime  " << p1balltime << " &&&&&&&&&&&" << endl;

                cout << endl << "&&&&&&&&&&&  p2balltime  " << p2balltime << " &&&&&&&&&&&";
                cout << endl << "&&&&&&&&&&&  p2balltime  " << p2balltime << " &&&&&&&&&&&";

                cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&";
                cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&" << endl;

                cout << endl <<"&&&&&&&&&&&  kick_time  " << kick_time << "  &&&&&&&&&&&";
                cout << endl <<"&&&&&&&&&&&  kick_time  " << kick_time << "  &&&&&&&&&&&" << endl;

                if(kick_time != 0)
                {
                    Kicker_case = MODE_KICK;
                }
                else
                {
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&";
                    cout<<endl<<"&&&&&&&&&&&&&&&  2nd LINE NOT PASS  &&&&&&&&&&&&&&&"<<endl<<endl;
                    kickyn = 0;
                    fail_mode = 3;
                    playMotion(MOTION_FAIL);
                    Kicker_case = MODE_END;
                }
            }
            else{
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&";
                cout<<endl<<"&&&&&&&&&&&&&&&  OUT OF 2nd LINE RANGE  &&&&&&&&&&&&&&&"<<endl<<endl;
                kickyn = 0;
                fail_mode = 4;
                playMotion(MOTION_FAIL);
                Kicker_case = MODE_END;
            }
        }
        break;
      }
      case MODE_KICK:
           {
               cout<<endl<<"&&&&&&&&&&&&&&&  MODE_KICK  &&&&&&&&&&&&&&&"<<endl<<endl;

               kick_cnt++;

               if(temp_bv <= 0){
                   playMotion(MOTION_FAIL);
                   Kicker_case = MODE_END;
                   cout << endl <<"&&&&&&&&&&&  kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" ;
                   cout << endl <<"&&&&&&&&&&&  kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" ;
                   cout << endl <<"&&&&&&&&&&&  kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;

                   kick_cnt = 0;
                   kickyn = 0;
                   fail_mode = 5; // BALL IS TO SLOW
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&";
                   cout<<endl<<"&&&&&&&&&&&&&&&  BALL IS TO SLOW  &&&&&&&&&&&&&&&"<<endl<<endl;
               }
               else if(1 <= temp_bv && temp_bv < 5){
                   if(kick_cnt > 19){ //0->1->7->14->17 //0 is too fast maybe 3~5?){
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(5 <= temp_bv && temp_bv < 9){
                   if(kick_cnt > 22){ //18 -> 19->20
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(9 <= temp_bv && temp_bv < 12){
                   if(kick_cnt > 10){ //0->1->7->10->12->11->12
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(12 <= temp_bv && temp_bv < 15){
                   if(kick_cnt > 11){ //0->1->7->10->12->11->12
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(15 <= temp_bv && temp_bv < 20){ //8~19-> 8~18
                   if(kick_cnt > 14){ //2->4->5->7->11
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(20 <= temp_bv && temp_bv < 30){
                   if(kick_cnt > 4){ //5->4
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else if(temp_bv >= 30){
                   if(kick_cnt > 0){
                       playMotion(MOTION_KICK);
                       Kicker_case = MODE_END;
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                       cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
                       kick_cnt = 0;
                       kickyn = 1;
                   }
               }
               else {
                   playMotion(MOTION_FAIL);
                   Kicker_case = MODE_END;
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "   kick_cnt  " << kick_cnt << "  &&&&&&&&&&&" << endl;
               }

               break;
           }
           case MODE_END:
           {
               mode_stop_cnt += 1;
               if(kickyn) {
                   cout<<endl<<"OOOOOOOOOOOOOO  MODE_SUCCESS  OOOOOOOOOOOOOO"<<endl;
                   cout<<"OOOOOOOOOOOOOO  MODE_SUCCESS  OOOOOOOOOOOOOO"<<endl;
                   cout<<"OOOOOOOOOOOOOO  MODE_SUCCESS  OOOOOOOOOOOOOO"<<endl;
                   cout<<"OOOOOOOOOOOOOO  MODE_SUCCESS  OOOOOOOOOOOOOO"<<endl;
                   cout<<"OOOOOOOOOOOOOO  MODE_SUCCESS  OOOOOOOOOOOOOO"<<endl<<endl;

                   cout<<"BALL MODE : "<<ball_state<<endl;
                   cout<<"BALL POINT DELAY : "<<p2balltime-p1balltime<<endl;
                   cout<<"BALL SPEED : "<<temp_bv<<endl;
                   cout<<"KICK DELAY : "<<kick_delay<<endl;

                   cout << endl << "&&&&&&&&&&&  p1balltime  " << p1balltime << " &&&&&&&&&&&";
                   cout << endl << "&&&&&&&&&&&  p1balltime  " << p1balltime << " &&&&&&&&&&&" << endl;

                   cout << endl << "&&&&&&&&&&&  p2balltime  " << p2balltime << " &&&&&&&&&&&";
                   cout << endl << "&&&&&&&&&&&  p2balltime  " << p2balltime << " &&&&&&&&&&&" << endl;

                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  temp_bv  " << temp_bv << "  &&&&&&&&&&&" << endl;

                   cout << endl <<"&&&&&&&&&&&  kick_time  " << kick_time << "  &&&&&&&&&&&";
                   cout << endl <<"&&&&&&&&&&&  kick_time  " << kick_time << "  &&&&&&&&&&&" << endl;

                   if(mode_stop_cnt > 100)
                   {
                       Kicker_case = MODE_TEST;//exit(100);

                       stop_cnt = 0;
                       kick_cnt = 0;
                       kick_delay = 0;
                       kick_time = 0;
                       kickyn = 1;
                       kick_mode = 0;
                       ball_state = 0;
                       p1balltime = 0;
                       p2balltime = 0;
                       temp_time_dk = 0;
                       p1p2d = 0;
                       temp_bv = 0;
                       temp_rp = 0;
                       p1x=0;
                       p1y=0;
                       p2x=0;
                       p2y=0;
                       mode_stop_cnt = 0;
                   }
               }
               else {
                   cout<<endl<<"XXXXXXXXXXXXXXX  MODE_FAIL  XXXXXXXXXXXXXXX"<<endl<<endl;
                   cout<<endl<<"XXXXXXXXXXXXXXX  MODE_FAIL  XXXXXXXXXXXXXXX"<<endl<<endl;
                   cout<<endl<<"XXXXXXXXXXXXXXX  MODE_FAIL  XXXXXXXXXXXXXXX"<<endl<<endl;
                   cout<<endl<<"XXXXXXXXXXXXXXX  MODE_FAIL  XXXXXXXXXXXXXXX"<<endl<<endl;
                   cout<<endl<<"XXXXXXXXXXXXXXX  MODE_FAIL  XXXXXXXXXXXXXXX"<<endl<<endl;
                   cout<<"BALL MODE : "<<ball_state<<endl;
                   cout<<"BALL POINT DELAY : "<<p2balltime-p1balltime<<endl;
                   cout<<"BALL SPEED : "<<temp_bv<<endl;
                   PRINTFAILINFO(fail_mode);

                   if(mode_stop_cnt > 100)
                   {
                       Kicker_case = MODE_TEST;

                       stop_cnt = 0;
                       kick_cnt = 0;
                       kick_delay = 0;
                       kick_time = 0;
                       kickyn = 1;
                       kick_mode = 0;
                       ball_state = 0;
                       p1balltime = 0;
                       p2balltime = 0;
                       temp_time_dk = 0;
                       p1p2d = 0;
                       temp_bv = 0;
                       temp_rp = 0;
                       p1x=0;
                       p1y=0;
                       p2x=0;
                       p2y=0;
                       mode_stop_cnt = 0;
                   }
               }

               cout<<"p1("<<p1x<<", "<<p1y<<")"<<endl;
               cout<<"p2("<<p2x<<", "<<p2y<<")"<<endl;
               break;
           }
         }
     }

     //    temp_case = robocup_case;
     }
