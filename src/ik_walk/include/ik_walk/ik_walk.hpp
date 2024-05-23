#ifndef IK_WALK_HPP_
#define IK_WALK_HPP_

#include "ros/ros.h"
#include <iostream>
#include "cmath"
#include <fstream>
#include <algorithm>

//INCLUDE//
#include "walk_pattern.hpp"
#include "imu_position_control.hpp"
#include "pid_control_float.h"
#include "solve_kinematics.hpp"
#include "zmp_position_control.hpp"

//MSG_HEADER//
#include <msg_generate/imu_msg.h>
#include <msg_generate/tune2walk.h>
#include <msg_generate/ikend_msg.h>
#include <msg_generate/ikcoordinate_msg.h>
#include <msg_generate/Motor_msg.h>
#include <msg_generate/ik_msg.h>
#include <msg_generate/zmp_msg.h>
#include <msg_generate/walk_pattern.h>
#include <msg_generate/com_msg.h>
#include <msg_generate/ik_angle_sim.h>
#include <msg_generate/Landing_Time_Control.h>

#define X_LIMIT     50
#define Y_LIMIT     50
#define YAW_LIMIT   50
#define Init_Position_Time -1
#define Init_Position_Pitch 0
#define Init_Position_Balance_Msg 0
#define Init_IK_End 1
#define Init_Rise_Condition 0
#define FILTERDATA   10
#define EXP 2.7182818284590452354

//PUBLISH_MSG
ros::Publisher Ikend_Pub;
ros::Publisher Com_Pub;
ros::Publisher Ikcoordinate_Pub;
ros::Publisher walk_pattern_Pub;
ros::Publisher Landing_Pub;
//SUBSCRIBE_MSG
ros::Subscriber Imu_Sub;
ros::Subscriber Tune2walk_Sub;
ros::Subscriber Master2ik_Sub;
ros::Subscriber Zmp_Sub;

//MSG_STRUCTURE_INFO
msg_generate::imu_msg Imu_Info;
msg_generate::ikend_msg Ikend_Info;
msg_generate::ik_msg Master2ik_Info;
msg_generate::ikcoordinate_msg Ikcoordinate_Info;
msg_generate::tune2walk Tune2walk_Info;
msg_generate::zmp_msg Zmp_Info;
msg_generate::walk_pattern walk_pattern_Info;
msg_generate::com_msg COM_Info;
msg_generate::Landing_Time_Control Landing_Info;

//FUNCTION
void get_parameters();
void timer_callback(const ros::TimerEvent&);
void imu_callback(const msg_generate::imu_msg::ConstPtr&);
void tune2walk_callback(const msg_generate::tune2walk::ConstPtr&);
void master2ik_callback(const msg_generate::ik_msg::ConstPtr& msg);
void zmp_callback(const msg_generate::zmp_msg::ConstPtr& msg);

double negative_position(double x);
double positive_position(double x);
double step_acc_func(double basic, double acc, int num, int & cnt);
//double step_acc_func(double basic, double pos_acc, double neg_acc, int pos_num, int neg_num, int & pos_cnt, int & neg_cnt);

//variable
double Timer_Time = 0.0;
double Timer_Time_Start = 0.0;
double Timer_Time_End =0.0;
double find_time =10.0;
double gather_imu_pitch[5]={0,};

///ZMP Landing Time Control///
double Landing_Time_R = 0.0;
double Landing_Time_L = 0.0;
double Landing_Error_R = 0.0;
double Landing_Error_L = 0.0;
bool Landing_flag_R = false;
bool Landing_flag_L = false;
double Swing_Control_L = 1.0;
double Swing_Control_R = 1.0;
double Swing_Control_add_L = 1.0;
double Swing_Control_add_R = 1.0;
double Swing_Moment_Gain_L = 0.3;
double Swing_Moment_Gain_R = 0.3;
int Swing_Control_Warning_cnt = 0;
int Swing_Control_Safe_cnt = 0;
int Landing_Time_Control_flag = false;

///For RUN_MODE///
bool Run_Flag = false;
double Run_Add = 0.0;

///For ANKLE_MODE///
bool Ankle_Flag = true;

///for Compansate Yaw ///
bool Compansate_Yaw_flag = false;
double desire_yaw = 0;
double Compansate_Yaw = 0;
int Compansate_Yaw_cnt = 0;

///for imu pitch > walk stop ///
int imu_safe_cnt = 0;

int i=0;//counter for fitered

IK_Solve IK;
IK_pos_control Imu_Balance;
IK_zmp_pos_control Zmp_Balance;

int flag=0;
bool Start_Flag = false;
bool Normal_first_Flag = false;
bool End_Flag = false;
bool Compansate_Flag_L = false;
bool Compansate_Flag_R = false;
bool Compansate_Flag_1 = false;
bool Compansate_Flag_2 = false;

struct K_Value{
    double Pos_XR=0;
    double Neg_XR=0;
    double Pos_SideR=0;
    double Neg_SideR=0;
    double Pos_YawR=0;
    double Neg_YawR=0;

    double Pos_XL=0;
    double Neg_XL=0;
    double Pos_SideL=0;
    double Neg_SideL=0;
    double Pos_YawL=0;
    double Neg_YawL=0;

    double Pos_SideR_SwingMinus=0;
    double Neg_SideR_SwingMinus=0;
    double Pos_SideL_SwingMinus=0;
    double Neg_SideL_SwingMinus=0;

    int min = 0;
    int max = 0;
};

struct Robit_Humanoid
{
    double Center2Leg = 0;
    double Link2Link = 0;
    double Init_Z_Up = 0;
};
Robit_Humanoid Model_Data;

class Walk_Parameters
{
public:
    bool IK_Flag = false;

    double Entire_Time = 80.0;
    double Frequency = 1.0;

    double Start_Entire_Time = 0.0;
    double End_Entire_Time = 0.0;

    double Sink_Entire_Time = 0.0;

    struct X_Value
    {
        double X = 0.0;
        double Tuning_X = 0.0;
        double Default_X_Right = 0.0;
        double Default_X_Left = 0.0;
    };
    struct Y_Value
    {
        double Side = 0.0;
        double Tuning_Side = 0.0;

        double Swing_Side_Right = 0.0;
        double Swing_Side_Left = 0.0;

        double Default_Y_Right = -(Model_Data.Center2Leg);
        double Default_Y_Left = Model_Data.Center2Leg;

        double Swing_Right_Leg= 0.0;
        double Swing_Left_Leg = 0.0;
        double Start_Swing = 0.0;
        double End_Swing = 0.0;

    };
    struct Z_Value
    {
        double Default_Z_Right = -(2*Model_Data.Link2Link - Model_Data.Init_Z_Up);
        double Default_Z_Left = -(2*Model_Data.Link2Link - Model_Data.Init_Z_Up);

        double Rise_Right_Leg = 0.0;
        double Rise_Left_Leg = 0.0;

        double Start_Rise = 0.0;
        double End_Rise = 0.0;
        double Z_com = 0.0;

        double R_Rise_Condition = 0.0;
        double L_Rise_Condition = 0.0;
    };
    struct Yaw_Value
    {
        double Yaw = 0.0;
        double Tuning_Yaw = 0.0;
    };
    struct Shoulder_Value
    {
        double Swing_Right_Shoulder = 0.0;
        double Swing_Left_Shoulder = 0.0;
    };

    struct Ratio_Flag
    {
        int Ratio_Flag;
    };

    X_Value X;
    Y_Value Y;
    Z_Value Z;
    Yaw_Value Yaw_R;
    Yaw_Value Yaw_L;
    Shoulder_Value Shoulder;
    Ratio_Flag Check_ratio;
};
K_Value K_value[4];
Walk_Parameters Now_Param;
Walk_Parameters Past_Param;
int accel_pos_x_cnt=-1;
int accel_neg_x_cnt=-1;
double check_old_x=0;
double accel_pos_x=0;
double accel_neg_x=0;
double basic_x = 0;

int accel_pos_y_cnt=-1;
int accel_neg_y_cnt=-1;
double check_old_y=0;
double accel_pos_y=0;
double accel_neg_y=0;
double basic_y = 0;

int accel_pos_z_cnt=-1;
int accel_neg_z_cnt=-1;
double check_old_z=0;
double accel_pos_z=0;
double accel_neg_z=0;
double basic_z = 0;

int accel_pos_x_num = 8;
int accel_neg_x_num = 8;
int accel_pos_y_num = 6;
int accel_neg_y_num = 6;
int accel_pos_z_num = 4;
int accel_neg_z_num = 4;


class Robit_Humanoid_Walk
{
public:

    void Walk_Start_End(Walk_Parameters & Now_Param);
    void Generate_Pattern(Walk_Parameters & Now_Param);
    void Result_Pattern(Walk_Parameters & Now_Param);

    double Time_Right_Leg = 0.0;
    double Time_Left_Leg = 0.0;
    double Time_Right_Leg_End = 0.0;
    double Time_Left_Leg_End = 0.0;
    double Time_Right_Leg_Start = 0.0;
    double Time_Left_Leg_Start = 0.0;

    double Time_X = 0.0;
    double Time_Side = 0.0;
    double Time_Yaw_R = 0.0;
    double Time_Yaw_L = 0.0;

    bool  flag = false;
    double Amount_of_Change_X = 0.0;
    double Amount_of_Change_Y = 0.0;

private:
    int Ik_Flag_Past = 0;
    int Start_Cnt = 1;
    int End_Cnt = 5;

    int Repeat_Start_Cycle = 9;//Run : 9 , hanoi : 3
    int Repeat_End_Cycle = 2;//3

    bool Side_Change = false;
    bool X_Change = false;
    bool Yaw_L_Change = false;
    bool Yaw_R_Change = false;
    bool Ang_Change = false;

    double Temp_Param_Yaw_R = 0.0;
    double Temp_Param_Yaw_L = 0.0;
    double Temp_Param_Side = 0.0;
    double Temp_Param_X = 0.0;

    double Kinetic_X_R;
    double Kinetic_Y_R;
    double Kinetic_Z_R;
    double Kinetic_Yaw_R;

    double Past_Kinetic_X_R;
    double Past_Kinetic_Y_R;

    double Kinetic_X_L;
    double Kinetic_Y_L;
    double Kinetic_Z_L;
    double Kinetic_Yaw_L;

    double Kinetic_Shoulder_X_R;
    double Kinetic_Shoulder_X_L;
    double Kinetic_Shoulder_Y_R;
    double Kinetic_Shoulder_Y_L;

    double Accel_Rise_R=0.0;
    double Accel_Rise_L=0.0;
    double Accel_Entire_Time = 0.0;
    double Accel_Swing_R = 0.0;
    double Accel_Swing_L = 0.0;

    foot_trajectory Start_COM_Pattern;
    foot_trajectory Start_Rise_Pattern;
    foot_trajectory COM_Pattern;
    foot_trajectory Step_Pattern;
    foot_trajectory Side_Pattern;
    foot_trajectory Rise_Pattern;
    foot_trajectory Turn_Pattern;
};


class Robit_Humanoid_Balancing
{
public :
    double Target_Time = 0.0;

    struct Balance
    {
        double Balance_Value_0 = 0.0;
        double Balance_Value_1 = 0.0;
        double Balance_Value_2 = 0.0;
        double Balance_Value_3 = 0.0;
        double Balance_Value_4 = 0.0;
        double Balance_Value_5 = 0.0;
        double Balance_Pitch_GP = 0.0;
        double Balance_Pitch_GI = 0.0;
        double Balance_Pitch_GD = 0.0;
        double Balance_Pitch_ELIMIT = 0.0;
        double Balance_Pitch_OLIMIT = 0.0;
        double Balance_Pitch_Neg_Target = 0.0;
        double Balance_Pitch_Pos_Target = 0.0;
        double Balance_Angle_Pitch_GP = 0.0;
        double Balance_Angle_Pitch_GI = 0.0;
        double Balance_Angle_Pitch_GD = 0.0;
        double Balance_Angle_Pitch_ELIMIT = 0.0;
        double Balance_Angle_Pitch_OLIMIT = 0.0;
        double Balance_Angle_Pitch_Neg_Target = 0.0;
        double Balance_Angle_Pitch_Pos_Target = 0.0;
        double Balance_Roll_GP = 0.0;
        double Balance_Roll_GI = 0.0;
        double Balance_Roll_GD = 0.0;
        double Balance_Roll_ELIMIT = 0.0;
        double Balance_Roll_OLIMIT = 0.0;
        double Balance_Roll_Neg_Target = 0.0;
        double Balance_Roll_Pos_Target = 0.0;
        double Balance_Pitch_GP_imu = 0.0;
        double Balance_Pitch_GI_imu = 0.0;
        double Balance_Pitch_GD_imu = 0.0;
        double Balance_Pitch_Neg_Target_imu = 0.0;
        double Balance_Pitch_Pos_Target_imu = 0.0;
        double Balance_Pitch_ELIMIT_imu = 0.0;
        double Balance_Pitch_OLIMIT_imu = 0.0;
        double Balance_Roll_GP_imu = 0.0;
        double Balance_Roll_GI_imu = 0.0;
        double Balance_Roll_GD_imu = 0.0;
        double Balance_Roll_Neg_Target_imu = 0.0;
        double Balance_Roll_Pos_Target_imu = 0.0;
        double Balance_Roll_ELIMIT_imu = 0.0;
        double Balance_Roll_OLIMIT_imu = 0.0;
        bool Balance_Pitch_Flag_imu = false;
        bool Balance_Roll_Flag_imu = false;
        bool Balance_Pitch_Flag = false;
        bool Balance_Angle_Pitch_Flag = false;
        bool Balance_Roll_Flag = false;



        int Ratio_Check_Flag = 0;
        int Support_Con = 99;
    };
    Balance Balance;
};
Robit_Humanoid_Balancing Balancing_Param;

#endif




