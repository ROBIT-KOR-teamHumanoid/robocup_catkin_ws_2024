#include "robocup_master23/technical_pk.hpp"
namespace robocup_master23
{

using namespace std;

int now_hight = 0;
bool isInit = true;
bool isMotion = true;
int motion_cnt = 0;
bool motion_end = false;

TECHNICAL_PK::TECHNICAL_PK(MasterRcko *master) :
    Player(master)
{
    cout << endl << "TECHNICAL_PK!!" << endl << endl;
}

void TECHNICAL_PK::statePlay()
{
    cout << "TECHNICAL_PK STATE: PLAY" << endl;

    switch (parkour_mode) {


    case MODE_IDLE:
    {
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_IDLE  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;

        cout << "set hight : ";
        cin >> now_hight;
        parkour_mode = MODE_PARKOUR;//robocup_case = MODE_PARKOUR;

        break;
    }
    case MODE_PARKOUR:
    {
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_PARKOUR  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;

        cout << "MISSION HIGHT: ";
        switch (now_hight) {
        case 15:
        {
            cout << "now_hight : "<< now_hight << endl;
            if(isMotion){
                if(motion_cnt){
                    Player::playMotion(0x22); parkour_mode = MODE_MOTION;//DOWN
                }
                else{
                    Player::playMotion(0x21);//UP
                }
                isMotion = false;
            }
            if(master->motionEnd.motion_end){
                ros::Duration(5).sleep();
                cout << "motion_end" << endl;
                if(motion_cnt) parkour_mode = MODE_STOP;
                else           isMotion = true;
                motion_cnt = 1;
            }           
            break;
        }
        default:
        {
            cout << "ERROR: INVAILED HIGHT" << endl;
            parkour_mode = MODE_IDLE;
            break;
        }
        }

        break;
    }
    case MODE_STOP:
    {
        cout<<endl<<"&&&&&&&&&&&&&&&&&&&  MODE_STOP  &&&&&&&&&&&&&&&&&&&&&"<<endl<<endl;
        break;
    }

    default:
        cout << "ERROR: using UNDEFINED robocup_case" << endl;
        break;

    }
}


}//namespace robocup_master23

