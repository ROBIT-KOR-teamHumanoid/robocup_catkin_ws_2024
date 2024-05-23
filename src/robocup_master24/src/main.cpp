#include "../include/robocup_master24/goalkeeper.hpp"
#include "../include/robocup_master24/forward.hpp"

using namespace std;
using namespace robocup_master24;

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
            default:
                cout << "WAITIONG GAME CONTROLLER: SET POSITION" << endl;
                break;
            }
        }

        if(robot){
            if(!robot->falldownExeption())
            {
                robot->selectGoalPost();
                robot->penaltyControl(isPenalty);
                robot->selectRobotState(isPenalty);
                robot->gameStateControl(!isPenalty, state);
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
