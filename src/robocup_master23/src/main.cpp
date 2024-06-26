#include "../include/robocup_master23/goalkeeper.hpp"
#include "../include/robocup_master23/forward.hpp"

#include "../include/robocup_master23/technical_cl.hpp"
#include "../include/robocup_master23/technical_dk.hpp"
#include "../include/robocup_master23/technical_pk.hpp"
#include "../include/robocup_master23/technical_hk.hpp"
#include "../include/robocup_master23/technical_ob.hpp"


using namespace std;
using namespace robocup_master23;

bool isPenalty;
bool testFlag = false;

int position    = POSITION_GK;
int state       = STATE_PLAYING;

int main(int argc, char**argv){
    MasterRcko* master = new MasterRcko(argc, argv);
    master->init();

    Player* robot = nullptr;

    ros::Rate loop_rate(500);
    while ( ros::ok() ) {

        if(!testFlag) {
            position = master->gameControlData.position;
            state = master->gameControlData.state;
        }

        if(!robot) {
            switch (position) {
            case POSITION_GK:
                cout << endl << "POSITION_GK" << endl;
                robot = new Goalkeeper(master);
                break;
            case POSITION_FW:
                cout << endl << "POSITION_FW" << endl;
                robot = new Forward(master);
                break;
            case TECHNICAL:
                cout<<endl<<"TECHNICAL_MODE : ";
                cout<<state<<endl;
                switch (state) {


                case STATE_CL_K:
                    cout << endl << "TECHNICAL_CL_K" << endl;
                    robot = new TECHNICAL_CL_K(master);
                    break;
                case STATE_CL_H:
                    cout << endl << "TECHNICAL_CL_H" << endl;
                    robot = new TECHNICAL_CL_H(master);
                    break;
                case STATE_DK:
                    cout << endl << "TECHNICAL_DK" << endl;
                    robot = new TECHNICAL_DK_K(master);
                    break;
                case STATE_PK:
                    cout << endl << "TECHNICAL_PK" << endl;
                    robot = new TECHNICAL_PK(master);
                    break;
                case STATE_HK:
                    cout << endl << "TECHNICAL_HK" << endl;
                    robot = new TECHNICAL_HK(master);
                    break;
                case STATE_OB:
                    cout << endl << "TECHINACL_OB" << endl;
                    robot = new TECHNICAL_OB(master);
                    break;
                default:
                    cout<<"!!error!!"<<endl;
                }
                break;
            default:
                cout << "WAITIONG GAME CONTROLLER: SET POSITION" << endl;
                break;
            }
        }

        if(robot){
            if(!robot->falldownExeption())
            {
                robot->selectGoalPost();
                robot->selectRobotState();
                robot->penaltyControl(isPenalty);
                robot->gameStateControl(!isPenalty,state,position);
            }
            robot->publishMsg();
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    if(robot != nullptr) {
        delete robot;
    }


    cout << "ros shutdown" << endl;
}
