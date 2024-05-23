#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "robocup_master24.hpp"
#include "define.hpp"
#include <yaml-cpp/yaml.h>

#include "./master_controller_PID/pidcontroll.h"

#define ROBOTNUM 3

namespace robocup_master24 {

class Player
{
public:
    Player(MasterRcko* master) {
        this->master = master;
    }
    virtual ~Player();

    MasterRcko* master;
    int robot_state;
    int robot_panalty_state;

    bool falldownExeption();
    void selectGoalPost();
    void penaltyControl(bool &isPenalty);
    void gameStateControl(bool control_on, int state);
    virtual void selectRobotState(bool isPenalty);
    void publishMsg();

    void move(bool flag);
    void move(int x, int y, int angle_mode = RELATIVE, int target = COORDINATE, int target_yaw = 0);
    void move(Point target_coor, int angle_mode = RELATIVE, int target = COORDINATE, int target_yaw = 0);
    bool playMotion(int motion_num);
    void setVisionTarget(int target);
    void setVisionMode(int mode);

    bool isArrive(Point robot_coor, Point target_coor, double threshold = 20);//


    YAML::Node config = YAML::LoadFile("/home/robit/catkin_ws/src/robocup_master24/src/robots.yaml");
    const YAML::Node& robot3 = config["robots"][ROBOTNUM - 1];

    double Kp = robot3["Kp"].as<double>();
    double Ki = robot3["Ki"].as<double>();
    double Kd = robot3["Kd"].as<double>();


protected:
    virtual void stateInitial() =0;
    virtual void stateReady() =0;
    virtual void stateReady(Point init_coor);
    virtual void stateSet();
    virtual void statePlay() =0;
    virtual void stateFinished();

protected:
    const double PI = 3.14159265;
    const double kick_threshold = 200;

    int before_cnt = 0;

    int status;
    int walk_status;
    int walk_switch = -1;
    int fixyawflag = 0;
    double target_angle;
    double abs_target_angle;
    double remaining_distance;

    size_t dribble_cnt = 0;

    Point opponent_goal_high;
    Point opponent_goal_low;
    Point opponent_goal_middle_high;
    Point opponent_goal_middle_low;
    Point opponent_goal_middle;
    Point opponent_goal;

    int isFalldown(const double pitch_threshold, const double roll_threshold, int &falldownWhere);
    void raisetUp(int falldownWhere);

    void calcBallKickPosCoor(Point goal_coordinates, Point ball_coordinates, Point &OUTPUT_target_coor, double kick_radius = 10);
    int selectKickType(Point ball_coordinates, Point robot_coordinates);
    void calibratePosition(Point robot_coor, Point ball_cam_coor, int &kick_mode, bool &isCalibrate);
    bool playKickMotion(int kick_mode);
    bool moveFixYaw(Point current_coordinates, double current_yaw, Point target_coordinates, bool dontStop);
    bool moveToTarget(Point current_coordinates, double current_yaw, Point target_coordinates, int angle_mode, double target_angle, bool dontStop = false);
    void calcDistance(Point starting_point, Point end_point, double &result);
    double calcDistance(Point starting_point, Point end_point);
    //bool isArrive(Point robot_coor, Point target_coor, double threshold = 20);
    void calcTargetAngle(Point target_coor, Point robot_coor, double robot_yaw, double &target_angle);
    double calcTargetAngle(Point target_coor, Point robot_coor, double robot_yaw);
    bool alignRobot(double robot_yaw, double target_angle = 0, int yaw_factor = 3, int angle_mode = OPPONENT, double align_threshold = 30);
    Point setPoint(int point_number);
    Point calcShootPoint(double cali_radius, Point goal_coor, Point ball_coor);
    void kick3();
    void dribble();
    bool moveRobotAroundBall(double cail_threshold, int refDist, Point localTarget, Point goalPoint);
    bool caliToBall(Point goalPoint);
    bool walkStart(int x, int y, int yaw);
    bool walkStop();
    bool walkPublish();
    bool visionPublish(int scan_mode, int pan = 0, int tilt = 0);
    bool udpPublish();
    bool localPublish();
    std::vector<int> sortArrayByElementSize(const std::vector<double>& arr);
    bool compareIndices(const std::vector<double>& arr, int i, int j);
};

} //namespace Player

#endif //PLAYER_HPP
