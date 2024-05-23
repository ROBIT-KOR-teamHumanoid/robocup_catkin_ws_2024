/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/tune_walk/main_window.hpp"
#include "../include/tune_walk/qnode.hpp"
#include <QKeyEvent>
#include <QDebug>
#include <QStatusBar>

/*****************************************************************************
** Namespaces
*****************************************************************************/


namespace tune_walk {

using namespace Qt;
using namespace std;
extern double xlpattern,ylpattern,zlpattern,slpattern,tlpattern,xrpattern,yrpattern,zrpattern,srpattern,trpattern;
extern double pitch;
extern double roll;
extern double yaw;
extern double left_x_zmp;
extern double left_y_zmp;
extern double right_x_zmp;
extern double right_y_zmp;
extern double total_x_zmp;
extern double total_y_zmp;
extern bool Left_Foot, Right_Foot, Both_Feet;

bool IMU_graph_flag = false;
bool Pattern_graph_flag = false;

//// for K_Value /////
extern int index;

struct Set_Data{
    double Swing_Right_Leg_Box=0;
    double Swing_Left_Leg_Box=0;
    double Swing_Right_Shoulder_Box=0;
    double Swing_Left_Shoulder_Box=0;
    double Rise_Right_Leg_Box=0;
    double Rise_Left_Leg_Box=0;
    double Start_Swing_Box=0;
    double Start_Rise_Box=0;
    double End_Swing_Box=0;
    double End_Rise_Box=0;
    double Test_X_Box=0;
    double Test_Side_Box=0;
    double Test_Yaw_Box=0;
    double Tuning_X_Box=0;
    double Tuning_Side_Box=0;
    double Tuning_Yaw_Box=0;
};
Set_Data Tuning_Data[3];

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    QObject::connect(&qnode, SIGNAL(Landing_callback()),this, SLOT(LandingCallback()));
    qnode.init();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(realtimePlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(IMUrealtimeDataSlot()));
    timer->start(10);
    Plot_init();
    makeIMUPlot();
    int index=0;
//    Center2Leg = 44.1;
//    Link2Link = 130.0;
//    Init_Z_Up = 23.0;
    Click_Value = 3;
    Offset_Angle_Limit = 500;
    msg_init_tune2walk.IK_Flag = false;
    msg_init_tune2walk.Entire_Time = 80;
    msg_init_tune2walk.Frequency=1;
    msg_init_tune2walk.Ratio_Check_Flag = false;
    msg_init_tune2walk.Center2Leg = 100;
    msg_init_tune2walk.Link2Link = 150;
    msg_init_tune2walk.Init_Z_Up = 10;
    msg_init_tune2walk.Default_X_Right=0;
    msg_init_tune2walk.Default_X_Left=0;
    msg_init_tune2walk.Default_Y_Right=-msg_init_tune2walk.Center2Leg;
    msg_init_tune2walk.Default_Y_Left=msg_init_tune2walk.Center2Leg;
    msg_init_tune2walk.Default_Z_Right=-(msg_init_tune2walk.Link2Link+msg_init_tune2walk.Link2Link-msg_init_tune2walk.Init_Z_Up);
    msg_init_tune2walk.Default_Z_Left=-(msg_init_tune2walk.Link2Link+msg_init_tune2walk.Link2Link-msg_init_tune2walk.Init_Z_Up);
    msg_init_tune2walk.Offset_10_Motor=0;
    msg_init_tune2walk.Offset_11_Motor=0;
    msg_init_tune2walk.Offset_12_Motor=0;
    msg_init_tune2walk.Offset_13_Motor=0;
    msg_init_tune2walk.Offset_14_Motor=0;
    msg_init_tune2walk.Offset_15_Motor=0;
    msg_init_tune2walk.Offset_16_Motor=0;
    msg_init_tune2walk.Offset_17_Motor=0;
    msg_init_tune2walk.Offset_18_Motor=0;
    msg_init_tune2walk.Offset_19_Motor=0;
    msg_init_tune2walk.Offset_20_Motor=0;
    msg_init_tune2walk.Offset_21_Motor=0;
    offset_past_motor10 = 0;
    offset_past_motor11 = 0;
    offset_past_motor12 = 0;
    offset_past_motor13 = 0;
    offset_past_motor14 = 0;
    offset_past_motor15 = 0;
    offset_past_motor16 = 0;
    offset_past_motor17 = 0;
    offset_past_motor18 = 0;
    offset_past_motor19 = 0;
    offset_past_motor20 = 0;
    offset_past_motor21 = 0;
    Offset_Scroll_Value = 0;
    msg_init_tune2walk.Percentage_of_IK_10_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_11_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_12_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_13_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_14_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_15_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_16_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_17_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_18_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_19_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_20_Motor = 1;
    msg_init_tune2walk.Percentage_of_IK_21_Motor = 1;
    msg_init_tune2walk.Swing_Right_Leg=10;
    msg_init_tune2walk.Swing_Left_Leg=10;
    msg_init_tune2walk.Swing_Right_Shoulder=0;
    msg_init_tune2walk.Swing_Left_Shoulder=0;
    msg_init_tune2walk.Rise_Right_Leg=10;
    msg_init_tune2walk.Rise_Left_Leg=10;
    msg_init_tune2walk.Start_Entire_Time=60;
    msg_init_tune2walk.Start_Swing=5;
    msg_init_tune2walk.Start_Rise=5;
    msg_init_tune2walk.End_Entire_Time=60;
    msg_init_tune2walk.End_Swing=5;
    msg_init_tune2walk.End_Rise=5;
    msg_init_tune2walk.Test_X=0;
    msg_init_tune2walk.Test_Side=0;
    msg_init_tune2walk.Test_Yaw=0;
    msg_init_tune2walk.Tuning_X=0;
    msg_init_tune2walk.Tuning_Side=0;
    msg_init_tune2walk.Tuning_Yaw=0;

    msg_init_tune2walk.Balance_Value_0=0;
    msg_init_tune2walk.Balance_Value_1=0;
    msg_init_tune2walk.Balance_Value_2=0;
    msg_init_tune2walk.Balance_Value_3=0;

    msg_init_tune2walk.Balance_Pitch_GP=0;
    msg_init_tune2walk.Balance_Pitch_GI=0;
    msg_init_tune2walk.Balance_Pitch_GD=0;
    msg_init_tune2walk.Balance_Pitch_ELIMIT=0;
    msg_init_tune2walk.Balance_Pitch_OLIMIT=0;
    msg_init_tune2walk.Balance_Pitch_Neg_Target=0;
    msg_init_tune2walk.Balance_Pitch_Pos_Target=0;

    msg_init_tune2walk.Balance_Angle_Pitch_GP=0;
    msg_init_tune2walk.Balance_Angle_Pitch_GI=0;
    msg_init_tune2walk.Balance_Angle_Pitch_GD=0;
    msg_init_tune2walk.Balance_Angle_Pitch_ELIMIT=0;
    msg_init_tune2walk.Balance_Angle_Pitch_OLIMIT=0;
    msg_init_tune2walk.Balance_Angle_Pitch_Neg_Target=0;
    msg_init_tune2walk.Balance_Angle_Pitch_Pos_Target=0;

    msg_init_tune2walk.Balance_Roll_GP = 0;
    msg_init_tune2walk.Balance_Roll_GI = 0;
    msg_init_tune2walk.Balance_Roll_GD = 0;
    msg_init_tune2walk.Balance_Roll_ELIMIT = 0;
    msg_init_tune2walk.Balance_Roll_OLIMIT = 0;
    msg_init_tune2walk.Balance_Roll_Neg_Target = 0;
    msg_init_tune2walk.Balance_Roll_Pos_Target = 0;

    msg_init_tune2walk.Balance_Pitch_Flag = false;
    msg_init_tune2walk.Balance_Roll_Flag = false;
    msg_init_tune2walk.Balance_Ankle_Pitch_Flag =false;


    //////////////////imu_parameter////////////////////////////////
    msg_init_tune2walk.Balance_Value_4=0;
    msg_init_tune2walk.Balance_Value_5=0;
    msg_init_tune2walk.Balance_Pitch_Flag_imu=false;
    msg_init_tune2walk.Balance_Pitch_GP_imu=0;
    msg_init_tune2walk.Balance_Pitch_GI_imu=0;
    msg_init_tune2walk.Balance_Pitch_GD_imu=0;
    msg_init_tune2walk.Balance_Pitch_ELIMIT_imu=0;
    msg_init_tune2walk.Balance_Pitch_OLIMIT_imu=0;
    msg_init_tune2walk.Balance_Pitch_Neg_Target_imu=0;
    msg_init_tune2walk.Balance_Pitch_Pos_Target_imu=0;


    ui.Balance_Value_0_Box_2->setValue(msg_init_tune2walk.Balance_Value_4);
    ui.Balance_Value_1_Box_2->setValue(msg_init_tune2walk.Balance_Value_5);
    ui.Balance_Pitch_GP_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GP_imu);
    ui.Balance_Pitch_GI_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GI_imu);
    ui.Balance_Pitch_GD_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GD_imu);
    ui.Balance_Pitch_ELIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_ELIMIT_imu);
    ui.Balance_Pitch_OLIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_OLIMIT_imu);
    ui.Balance_Pitch_Neg_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_Neg_Target_imu);
    ui.Balance_Pitch_Pos_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_Pos_Target_imu);

    msg_init_tune2walk.Balance_Roll_Flag_imu=false;
    msg_init_tune2walk.Balance_Roll_GP_imu=0;
    msg_init_tune2walk.Balance_Roll_GI_imu=0;
    msg_init_tune2walk.Balance_Roll_GD_imu=0;
    msg_init_tune2walk.Balance_Roll_ELIMIT_imu=0;
    msg_init_tune2walk.Balance_Roll_OLIMIT_imu=0;
    msg_init_tune2walk.Balance_Roll_Neg_Target_imu=0;
    msg_init_tune2walk.Balance_Roll_Pos_Target_imu=0;

    ui.Balance_Roll_GP_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GP_imu);
    ui.Balance_Roll_GI_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GI_imu);
    ui.Balance_Roll_GD_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GD_imu);
    ui.Balance_Roll_ELIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_ELIMIT_imu);
    ui.Balance_Roll_OLIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_OLIMIT_imu);
    ui.Balance_Roll_Neg_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_Neg_Target_imu);
    ui.Balance_Roll_Pos_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_Pos_Target_imu);

   ///////////////////////K_Value////////////////////////////////
   msg_init_tune2walk.First_Pos_XR=0;
   msg_init_tune2walk.First_Neg_XR=0;
   msg_init_tune2walk.First_Pos_SideR=0;
   msg_init_tune2walk.First_Pos_SideR_SwingMinus=0;
   msg_init_tune2walk.First_Neg_SideR=0;
   msg_init_tune2walk.First_Neg_SideR_SwingMinus=0;
   msg_init_tune2walk.First_Pos_YawR=0;
   msg_init_tune2walk.First_Neg_YawR=0;
   msg_init_tune2walk.First_Pos_XL=0;
   msg_init_tune2walk.First_Neg_XL=0;
   msg_init_tune2walk.First_Pos_SideL=0;
   msg_init_tune2walk.First_Pos_SideL_SwingMinus=0;
   msg_init_tune2walk.First_Neg_SideL=0;
   msg_init_tune2walk.First_Neg_SideL_SwingMinus=0;
   msg_init_tune2walk.First_Pos_YawL=0;
   msg_init_tune2walk.First_Neg_YawL=0;
   msg_init_tune2walk.First_min=0;
   msg_init_tune2walk.First_max=15;

   msg_init_tune2walk.Second_Pos_XR=0;
   msg_init_tune2walk.Second_Neg_XR=0;
   msg_init_tune2walk.Second_Pos_SideR=0;
   msg_init_tune2walk.Second_Pos_SideR_SwingMinus=0;
   msg_init_tune2walk.Second_Neg_SideR=0;
   msg_init_tune2walk.Second_Neg_SideR_SwingMinus=0;
   msg_init_tune2walk.Second_Pos_YawR=0;
   msg_init_tune2walk.Second_Neg_YawR=0;
   msg_init_tune2walk.Second_Pos_XL=0;
   msg_init_tune2walk.Second_Neg_XL=0;
   msg_init_tune2walk.Second_Pos_SideL=0;
   msg_init_tune2walk.Second_Pos_SideL_SwingMinus=0;
   msg_init_tune2walk.Second_Neg_SideL=0;
   msg_init_tune2walk.Second_Neg_SideL_SwingMinus=0;
   msg_init_tune2walk.Second_Pos_YawL=0;
   msg_init_tune2walk.Second_Neg_YawL=0;
   msg_init_tune2walk.Second_min=15;
   msg_init_tune2walk.Second_max=30;

   msg_init_tune2walk.Third_Pos_XR=0;
   msg_init_tune2walk.Third_Neg_XR=0;
   msg_init_tune2walk.Third_Pos_SideR=0;
   msg_init_tune2walk.Third_Pos_SideR_SwingMinus=0;
   msg_init_tune2walk.Third_Neg_SideR=0;
   msg_init_tune2walk.Third_Neg_SideR_SwingMinus=0;
   msg_init_tune2walk.Third_Pos_YawR=0;
   msg_init_tune2walk.Third_Neg_YawR=0;
   msg_init_tune2walk.Third_Pos_XL=0;
   msg_init_tune2walk.Third_Neg_XL=0;
   msg_init_tune2walk.Third_Pos_SideL=0;
   msg_init_tune2walk.Third_Pos_SideL_SwingMinus=0;
   msg_init_tune2walk.Third_Neg_SideL=0;
   msg_init_tune2walk.Third_Neg_SideL_SwingMinus=0;
   msg_init_tune2walk.Third_Pos_YawL=0;
   msg_init_tune2walk.Third_Neg_YawL=0;
   msg_init_tune2walk.Third_min=30;
   msg_init_tune2walk.Third_max=40;

   msg_init_tune2walk.Fourth_Pos_XR=0;
   msg_init_tune2walk.Fourth_Neg_XR=0;
   msg_init_tune2walk.Fourth_Pos_SideR=0;
   msg_init_tune2walk.Fourth_Pos_SideR_SwingMinus=0;
   msg_init_tune2walk.Fourth_Neg_SideR=0;
   msg_init_tune2walk.Fourth_Neg_SideR_SwingMinus=0;
   msg_init_tune2walk.Fourth_Pos_YawR=0;
   msg_init_tune2walk.Fourth_Neg_YawR=0;
   msg_init_tune2walk.Fourth_Pos_XL=0;
   msg_init_tune2walk.Fourth_Neg_XL=0;
   msg_init_tune2walk.Fourth_Pos_SideL=0;
   msg_init_tune2walk.Fourth_Pos_SideL_SwingMinus=0;
   msg_init_tune2walk.Fourth_Neg_SideL=0;
   msg_init_tune2walk.Fourth_Neg_SideL_SwingMinus=0;
   msg_init_tune2walk.Fourth_Pos_YawL=0;
   msg_init_tune2walk.Fourth_Neg_YawL=0;
   msg_init_tune2walk.Fourth_min=40;
   msg_init_tune2walk.Fourth_max=50;

   msg_init_tune2walk.Landing_Time_Control_flag=0;

   msg_init_tune2walk.Control_System_flag=0;

   ui.Pos_XRSpinBox->setValue(msg_init_tune2walk.First_Pos_XR);
   ui.Neg_XRSpinBox->setValue(msg_init_tune2walk.First_Neg_XR);
   ui.Pos_SideRSpinBox->setValue(msg_init_tune2walk.First_Pos_SideR);
   ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Pos_SideR_SwingMinus);
   ui.Neg_SideRSpinBox->setValue(msg_init_tune2walk.First_Neg_SideR);
   ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Neg_SideR_SwingMinus);
   ui.Pos_YawRSpinBox->setValue(msg_init_tune2walk.First_Pos_YawR);
   ui.Neg_YawRSpinBox->setValue(msg_init_tune2walk.First_Neg_YawR);
   ui.Pos_XLSpinBox->setValue(msg_init_tune2walk.First_Pos_XL);
   ui.Neg_XLSpinBox->setValue(msg_init_tune2walk.First_Neg_XL);
   ui.Pos_SideLSpinBox->setValue(msg_init_tune2walk.First_Pos_SideL);
   ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Pos_SideL_SwingMinus);
   ui.Neg_SideLSpinBox->setValue(msg_init_tune2walk.First_Neg_SideL);
   ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Neg_SideL_SwingMinus);
   ui.Pos_YawLSpinBox->setValue(msg_init_tune2walk.First_Pos_YawL);
   ui.Neg_YawLSpinBox->setValue(msg_init_tune2walk.First_Neg_YawL);
   ui.First_min->setValue(msg_init_tune2walk.First_min);
   ui.First_max->setValue(msg_init_tune2walk.First_max);
   ui.Second_min->setValue(msg_init_tune2walk.Second_min);
   ui.Second_max->setValue(msg_init_tune2walk.Second_max);
   ui.Third_min->setValue(msg_init_tune2walk.Third_min);
   ui.Third_max->setValue(msg_init_tune2walk.Third_max);
   ui.Fourth_min->setValue(msg_init_tune2walk.Fourth_min);
   ui.Fourth_max->setValue(msg_init_tune2walk.Fourth_max);
    ///////////////////////////////////////////////////////////////


    ui.Entire_Time_Box->setValue(msg_init_tune2walk.Entire_Time);
    ui.Frequency_Box->setValue(msg_init_tune2walk.Frequency);
    ui.Center2Leg_Box->setValue(msg_init_tune2walk.Center2Leg);
    ui.Link2Link_Box->setValue(msg_init_tune2walk.Link2Link);
    ui.Init_Z_Up_Box->setValue(msg_init_tune2walk.Init_Z_Up);
    ui.Default_X_Right_Box->setValue(msg_init_tune2walk.Default_X_Right);
    ui.Default_X_Left_Box->setValue(msg_init_tune2walk.Default_X_Left);
    ui.Default_Y_Right_Box->setValue(msg_init_tune2walk.Default_Y_Right);
    ui.Default_Y_Left_Box->setValue(msg_init_tune2walk.Default_Y_Left);
    ui.Default_Z_Right_Box->setValue(msg_init_tune2walk.Default_Z_Right);
    ui.Default_Z_Left_Box->setValue(msg_init_tune2walk.Default_Z_Left);
    ui.Motor_10_Minus -> setText(QString::number(msg_tune2walk.Offset_10_Motor));
    ui.Motor_11_Minus -> setText(QString::number(msg_tune2walk.Offset_11_Motor));
    ui.Motor_12_Minus -> setText(QString::number(msg_tune2walk.Offset_12_Motor));
    ui.Motor_13_Minus -> setText(QString::number(msg_tune2walk.Offset_13_Motor));
    ui.Motor_14_Minus -> setText(QString::number(msg_tune2walk.Offset_14_Motor));
    ui.Motor_15_Minus -> setText(QString::number(msg_tune2walk.Offset_15_Motor));
    ui.Motor_16_Minus -> setText(QString::number(msg_tune2walk.Offset_16_Motor));
    ui.Motor_17_Minus -> setText(QString::number(msg_tune2walk.Offset_17_Motor));
    ui.Motor_18_Minus -> setText(QString::number(msg_tune2walk.Offset_18_Motor));
    ui.Motor_19_Minus -> setText(QString::number(msg_tune2walk.Offset_19_Motor));
    ui.Motor_20_Minus -> setText(QString::number(msg_tune2walk.Offset_20_Motor));
    ui.Motor_21_Minus -> setText(QString::number(msg_tune2walk.Offset_21_Motor));
    ui.Percentage_of_10_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_10_Motor);
    ui.Percentage_of_11_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_11_Motor);
    ui.Percentage_of_12_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_12_Motor);
    ui.Percentage_of_13_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_13_Motor);
    ui.Percentage_of_14_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_14_Motor);
    ui.Percentage_of_15_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_15_Motor);
    ui.Percentage_of_16_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_16_Motor);
    ui.Percentage_of_17_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_17_Motor);
    ui.Percentage_of_18_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_18_Motor);
    ui.Percentage_of_19_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_19_Motor);
    ui.Percentage_of_20_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_20_Motor);
    ui.Percentage_of_21_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_21_Motor);
    ui.Swing_Right_Leg_Box->setValue(msg_init_tune2walk.Swing_Right_Leg);
    ui.Swing_Left_Leg_Box->setValue(msg_init_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Shoulder_Box->setValue(msg_init_tune2walk.Swing_Right_Shoulder);
    ui.Swing_Left_Shoulder_Box->setValue(msg_init_tune2walk.Swing_Left_Shoulder);
    ui.Rise_Right_Leg_Box->setValue(msg_init_tune2walk.Rise_Right_Leg);
    ui.Rise_Left_Leg_Box->setValue(msg_init_tune2walk.Rise_Left_Leg);
    ui.Start_Entire_Time_Box->setValue(msg_init_tune2walk.Start_Entire_Time);
    ui.Start_Swing_Box->setValue(msg_init_tune2walk.Start_Swing);
    ui.Start_Rise_Box->setValue(msg_init_tune2walk.Start_Rise);
    ui.End_Entire_Time_Box->setValue(msg_init_tune2walk.End_Entire_Time);
    ui.End_Swing_Box->setValue(msg_init_tune2walk.End_Swing);
    ui.End_Rise_Box->setValue(msg_init_tune2walk.End_Rise);

    ui.Test_X_Box->setValue(msg_init_tune2walk.Test_X);
    ui.Test_Side_Box->setValue(msg_init_tune2walk.Test_Side);
    ui.Test_Yaw_Box->setValue(msg_init_tune2walk.Test_Yaw);
    ui.Tuning_X_Box->setValue(msg_init_tune2walk.Tuning_X);
    ui.Tuning_Side_Box->setValue(msg_init_tune2walk.Tuning_Side);
    ui.Tuning_Yaw_Box->setValue(msg_init_tune2walk.Tuning_Yaw);

    ui.Balance_Value_0_Box->setValue(msg_init_tune2walk.Balance_Value_0);

    ui.Balance_Pitch_GP_Box->setValue(msg_init_tune2walk.Balance_Pitch_GP);
    ui.Balance_Pitch_GI_Box->setValue(msg_init_tune2walk.Balance_Pitch_GI);
    ui.Balance_Pitch_GD_Box->setValue(msg_init_tune2walk.Balance_Pitch_GD);
    ui.Balance_Pitch_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Pitch_ELIMIT);
    ui.Balance_Pitch_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Pitch_OLIMIT);
    ui.Balance_Pitch_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Pitch_Neg_Target);
    ui.Balance_Pitch_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Pitch_Pos_Target);

    ui.Balance_Value_1_Box->setValue(msg_init_tune2walk.Balance_Value_1);

    ui.Balance_Ankle_Pitch_GP_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GP);
    ui.Balance_Ankle_Pitch_GI_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GI);
    ui.Balance_Ankle_Pitch_GD_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GD);
    ui.Balance_Ankle_Pitch_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_ELIMIT);
    ui.Balance_Ankle_Pitch_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_OLIMIT);
    ui.Balance_Ankle_Pitch_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_Neg_Target);
    ui.Balance_Ankle_Pitch_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_Pos_Target);

    ui.Balance_Value_2_Box->setValue(msg_init_tune2walk.Balance_Value_2);
    ui.Balance_Value_3_Box->setValue(msg_init_tune2walk.Balance_Value_3);

    ui.Balance_Roll_GP_Box->setValue(msg_init_tune2walk.Balance_Roll_GP);
    ui.Balance_Roll_GI_Box->setValue(msg_init_tune2walk.Balance_Roll_GI);
    ui.Balance_Roll_GD_Box->setValue(msg_init_tune2walk.Balance_Roll_GD);
    ui.Balance_Roll_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Roll_ELIMIT);
    ui.Balance_Roll_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Roll_OLIMIT);
    ui.Balance_Roll_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Roll_Neg_Target);
    ui.Balance_Roll_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Roll_Pos_Target);

    ui.IMU_graph->setChecked(0);
    ui.Pattern_graph->setChecked(0);
}
MainWindow::~MainWindow() {}
}  // namespace tune_walk



//Key_Board_Controller
void tune_walk::MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W)
        {
            msg_tune2walk.Test_X +=1;
        }
    else if(e->key() == Qt::Key_A)
        {
            msg_tune2walk.Test_Side +=1;
        }
    else if(e->key() == Qt::Key_S)
        {
            msg_tune2walk.Test_X -=1;
        }
    else if(e->key() == Qt::Key_D)
        {
            msg_tune2walk.Test_Side -=1;
        }
    else if(e->key() == Qt::Key_Comma)
        {
            msg_tune2walk.Test_Yaw +=1;
        }
    else if(e->key() == Qt::Key_Period)
        {
            msg_tune2walk.Test_Yaw -=1;
        }
    else if(e->key() == Qt::Key_1)
        {
            tune_walk::MainWindow::on_Save_Data1_Button_clicked();
        }
    else if(e->key() == Qt::Key_2)
        {
             tune_walk::MainWindow::on_Save_Data2_Button_clicked();
        }
    else if(e->key() == Qt::Key_3)
        {
             tune_walk::MainWindow::on_Save_Data3_Button_clicked();
        }
    else if(e->key() == Qt::Key_4)
        {
            tune_walk::MainWindow::on_Set_Data1_Button_clicked();
        }
    else if(e->key() == Qt::Key_5)
        {
             tune_walk::MainWindow::on_Set_Data2_Button_clicked();
        }
    else if(e->key() == Qt::Key_6)
        {
             tune_walk::MainWindow::on_Set_Data3_Button_clicked();
        }
    else if(e->key() == Qt::Key_0)
        {
             tune_walk::MainWindow::on_Set_Zero_Button_clicked();
        }
    else if(e->key() == Qt::Key_P)
        {
            static bool Control_Flag = true;
            if(Control_Flag)
            {
              msg_tune2walk.IK_Flag = 1;
              ui.IK_Flag_Button->setText("STOP");
              Control_Flag = false;
              cout<<"STOP"<<endl;
            }
            else if(!Control_Flag)
            {
                ui.IK_Flag_Button->setText("WALK");
              msg_tune2walk.IK_Flag = 0;
              Control_Flag = true;
              cout<<"WALK"<<endl;
            }
        }
\
    if(msg_tune2walk.Test_X >= 150)  msg_tune2walk.Test_X = 150;
    if(msg_tune2walk.Test_X <= -50)  msg_tune2walk.Test_X = -50;
    if(msg_tune2walk.Test_Side >= 50)  msg_tune2walk.Test_Side = 50;
    if(msg_tune2walk.Test_Side <= -50)  msg_tune2walk.Test_Side = -50;
    if(msg_tune2walk.Test_Yaw >= 50)  msg_tune2walk.Test_Yaw = 50;
    if(msg_tune2walk.Test_Yaw <= -50)  msg_tune2walk.Test_Yaw = -50;


    ui.Test_X_Box -> setValue(msg_tune2walk.Test_X);
    ui.Test_Side_Box -> setValue(msg_tune2walk.Test_Side);
    ui.Test_Yaw_Box -> setValue(msg_tune2walk.Test_Yaw);

    tune2walk_Pub.publish(msg_tune2walk);
}
//make Graph
void tune_walk::MainWindow::realtimePlot()
{
    if(value !=6)
    {
        value++;
        Condition_Data[value] = value;
    }
    else
    {
        value=0;
    }
    if(Pattern_graph_flag)
    {
        static QTime time(QTime::currentTime());
        double key = time.elapsed()/1000.0;
        static double lastPointKey = 0;
        if(key - lastPointKey > 0.0001) // 1s display
        {
            if(L_Step_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(0)->addData(key, xlpattern);
            if(L_COM_Pattern_Check_Flag == 1) ui.Pattern_plot->graph (1)->addData(key, ylpattern);
            if(L_Rise_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(2)->addData(key, zlpattern);
            if(L_Side_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(3)->addData(key, slpattern);
            if(L_Turn_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(4)->addData(key, tlpattern);

            if(R_Step_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(0)->addData(key, xrpattern);
            if(R_COM_Pattern_Check_Flag == 1) ui.Pattern_plot->graph (1)->addData(key, yrpattern);
            if(R_Rise_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(2)->addData(key, zrpattern);
            if(R_Side_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(3)->addData(key, srpattern);
            if(R_Turn_Pattern_Check_Flag == 1) ui.Pattern_plot->graph(4)->addData(key, trpattern);

            lastPointKey = key;
        }
        /* make key axis range scroll right with the data at a constant range of 8. */
        ui.Pattern_plot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui.Pattern_plot->replot();
    }
}
void tune_walk::MainWindow::Plot_init()
{
      ui.Pattern_plot->addGraph();
      ui.Pattern_plot->graph(0)->setPen(QPen(Qt::red));
      ui.Pattern_plot->graph(0)->setAntialiasedFill(false);
      ui.Pattern_plot->addGraph();
      ui.Pattern_plot->graph(1)->setPen(QPen(Qt::darkCyan));
      ui.Pattern_plot->graph(1)->setAntialiasedFill(false);
      ui.Pattern_plot->addGraph();
      ui.Pattern_plot->graph(2)->setPen(QPen(Qt::black));
      ui.Pattern_plot->graph(2)->setAntialiasedFill(false);
      ui.Pattern_plot->addGraph();
      ui.Pattern_plot->graph(3)->setPen(QPen(Qt::magenta));
      ui.Pattern_plot->graph(3)->setAntialiasedFill(false);
      ui.Pattern_plot->addGraph();
      ui.Pattern_plot->graph(4)->setPen(QPen(Qt::blue));
      ui.Pattern_plot->graph(4)->setAntialiasedFill(false);
      ui.Pattern_plot->setBackground(QColor(255,255,255));

      QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
      timeTicker->setTimeFormat("%h:%m:%s");
      ui.Pattern_plot->xAxis->setTicker(timeTicker);
      ui.Pattern_plot->axisRect()->setupFullAxesBox();

      ui.Pattern_plot->xAxis->setTickLabelFont(QFont(QFont().family(),10));
      ui.Pattern_plot->yAxis->setTickLabelFont(QFont(QFont().family(),10));
      ui.Pattern_plot->xAxis->setBasePen(QPen(Qt::black));
      ui.Pattern_plot->yAxis->setTickPen(QPen(Qt::black));
      ui.Pattern_plot->xAxis->setTickLabelColor(Qt::black);
      ui.Pattern_plot->xAxis->setLabelColor(Qt::black);
      ui.Pattern_plot->xAxis->setLabel("Time(s)");
      ui.Pattern_plot->yAxis->setTickLabelColor(Qt::black);
      ui.Pattern_plot->yAxis->setLabelColor(Qt::black);
      ui.Pattern_plot->yAxis->setRange(-1.5,1.5);
      ui.Pattern_plot->xAxis2->setVisible(true);
      ui.Pattern_plot->yAxis->setVisible(true);
      ui.Pattern_plot->xAxis2->setTicks(true);
      ui.Pattern_plot->yAxis2->setTicks(true);
      ui.Pattern_plot->xAxis2->setTickLabels(true);
      ui.Pattern_plot->yAxis2->setTickLabels(true);
}

//-------------------------------------------------------------IMU_graph

void tune_walk::MainWindow::makeIMUPlot()
{
    ui.IMU_plot->addGraph(); // blue line
    ui.IMU_plot->graph(0)->setPen(QPen(QColor(40, 110, 255)));//pitch
    ui.IMU_plot->addGraph(); // red line
    ui.IMU_plot->graph(1)->setPen(QPen(QColor(255, 110, 40)));//roll

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui.IMU_plot->xAxis->setTicker(timeTicker);
    ui.IMU_plot->axisRect()->setupFullAxesBox();
    ui.IMU_plot->yAxis->setRange(-20, 20);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui.IMU_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.IMU_plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui.IMU_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.IMU_plot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::IMUrealtimeDataSlot:

//    timer.start(0); // Interval 0 means to refresh as fast as possible

}

void tune_walk::MainWindow::IMUrealtimeDataSlot()
{
    if(IMU_graph_flag)
    {
        static QTime time(QTime::currentTime());
        // calculate two new data points:
        double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
        static double lastPointKey = 0;
        if (key-lastPointKey > 0.0001) // at most add point every 1s
        {
          // add data to lines:
          ui.IMU_plot->graph(0)->addData(key, pitch);
          ui.IMU_plot->graph(1)->addData(key, roll);
          // rescale value (vertical) axis to fit the current data:
          //ui.IMU_plot->graph(0)->rescaleValueAxis();
          //ui.IMU_plot->graph(1)->rescaleValueAxis(true);
          lastPointKey = key;
        }
        // make key axis range scroll with the data (at a constant range size of 8):
        ui.IMU_plot->xAxis->setRange(key, 8, Qt::AlignRight);
        ui.IMU_plot->replot();
    }
}

//---------------------------Parameter--------------------------------------//
//////////////////////////////////////////////////////////////////////////////
//Entire_Time
void tune_walk::MainWindow::on_Entire_Time_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Entire_Time = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Entire_Time_Plus_Button_clicked()
{
    msg_tune2walk.Entire_Time +=10;
    if(msg_tune2walk.Entire_Time>=500)msg_tune2walk.Entire_Time=500;
    ui.Entire_Time_Box -> setValue(msg_tune2walk.Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Entire_Time_Minus_Button_clicked()
{
    msg_tune2walk.Entire_Time -=10;
    if(msg_tune2walk.Entire_Time<=0)msg_tune2walk.Entire_Time=0;
    ui.Entire_Time_Box -> setValue(msg_tune2walk.Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Frequency
void tune_walk::MainWindow::on_Frequency_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Frequency = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Frequency_Plus_Button_clicked()
{
    msg_tune2walk.Frequency +=1;
    if(msg_tune2walk.Frequency>=100)msg_tune2walk.Frequency=100;
    ui.Frequency_Box -> setValue(msg_tune2walk.Frequency);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Frequency_Minus_Button_clicked()
{
    msg_tune2walk.Frequency -=1;
    if(msg_tune2walk.Frequency<=0)msg_tune2walk.Frequency=0;
    ui.Frequency_Box -> setValue(msg_tune2walk.Frequency);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Double


//Default_X_Right
void tune_walk::MainWindow::on_Default_X_Right_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_X_Right = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Default_X_Right_Plus_Button_clicked()
{
    msg_tune2walk.Default_X_Right +=1;
    if(msg_tune2walk.Default_X_Right>=100)msg_tune2walk.Default_X_Right=100;
    ui.Default_X_Right_Box -> setValue(msg_tune2walk.Default_X_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Default_X_Right_Minus_Button_clicked()
{
    msg_tune2walk.Default_X_Right -=1;
    if(msg_tune2walk.Default_X_Right<=-100)msg_tune2walk.Default_X_Right=-100;
    ui.Default_X_Right_Box -> setValue(msg_tune2walk.Default_X_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Default_X_Left
void tune_walk::MainWindow::on_Default_X_Left_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_X_Left = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_X_Left_Plus_Button_clicked()
{
    msg_tune2walk.Default_X_Left +=1;
    if(msg_tune2walk.Default_X_Left>=100)msg_tune2walk.Default_X_Left=100;
    ui.Default_X_Left_Box -> setValue(msg_tune2walk.Default_X_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_X_Left_Minus_Button_clicked()
{
    msg_tune2walk.Default_X_Left -=1;
    if(msg_tune2walk.Default_X_Left<=-100)msg_tune2walk.Default_X_Left=-100;
    ui.Default_X_Left_Box -> setValue(msg_tune2walk.Default_X_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Default_Y_Right
void tune_walk::MainWindow::on_Default_Y_Right_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_Y_Right = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Y_Right_Plus_Button_clicked()
{
    msg_tune2walk.Default_Y_Right +=1;
    if(msg_tune2walk.Default_Y_Right>=100)msg_tune2walk.Default_Y_Right=100;
    ui.Default_Y_Right_Box -> setValue(msg_tune2walk.Default_Y_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Y_Right_Minus_Button_clicked()
{
    msg_tune2walk.Default_Y_Right -=1;
    if(msg_tune2walk.Default_Y_Right<=-100)msg_tune2walk.Default_Y_Right=-100;
    ui.Default_Y_Right_Box -> setValue(msg_tune2walk.Default_Y_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Default_Y_Left
void tune_walk::MainWindow::on_Default_Y_Left_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_Y_Left = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Y_Left_Plus_Button_clicked()
{
    msg_tune2walk.Default_Y_Left +=1;
    if(msg_tune2walk.Default_Y_Left>=100)msg_tune2walk.Default_Y_Left=100;
    ui.Default_Y_Left_Box -> setValue(msg_tune2walk.Default_Y_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Y_Left_Minus_Button_clicked()
{
    msg_tune2walk.Default_Y_Left -=1;
    if(msg_tune2walk.Default_Y_Left<=-100)msg_tune2walk.Default_Y_Left=-100;
    ui.Default_Y_Left_Box -> setValue(msg_tune2walk.Default_Y_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Default_Z_Right
void tune_walk::MainWindow::on_Default_Z_Right_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_Z_Right = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Z_Right_Plus_Button_clicked()
{
    msg_tune2walk.Default_Z_Right +=1;
    if(msg_tune2walk.Default_Z_Right>=100)msg_tune2walk.Default_Z_Right=100;
    ui.Default_Z_Right_Box -> setValue(msg_tune2walk.Default_Z_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Z_Right_Minus_Button_clicked()
{
    msg_tune2walk.Default_Z_Right -=1;
    if(msg_tune2walk.Default_Z_Right<=-(2*msg_tune2walk.Link2Link))msg_tune2walk.Default_Z_Right=-(2*msg_tune2walk.Link2Link);
    ui.Default_Z_Right_Box -> setValue(msg_tune2walk.Default_Z_Right);
    tune2walk_Pub.publish(msg_tune2walk);
}
//Default_Z_Left
void tune_walk::MainWindow::on_Default_Z_Left_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Default_Z_Left = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Z_Left_Plus_Button_clicked()
{
    msg_tune2walk.Default_Z_Left +=1;
    if(msg_tune2walk.Default_Z_Left>=100)msg_tune2walk.Default_Z_Left=100;
    ui.Default_Z_Left_Box -> setValue(msg_tune2walk.Default_Z_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Default_Z_Left_Minus_Button_clicked()
{
    msg_tune2walk.Default_Z_Left -=1;
    if(msg_tune2walk.Default_Z_Left<=-(2*msg_tune2walk.Link2Link))msg_tune2walk.Default_Z_Left=-(2*msg_tune2walk.Link2Link);
    ui.Default_Z_Left_Box -> setValue(msg_tune2walk.Default_Z_Left);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Center2Leg_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Center2Leg = arg1;
    msg_tune2walk.Default_Y_Right=-msg_tune2walk.Center2Leg;
    msg_tune2walk.Default_Y_Left=msg_tune2walk.Center2Leg;
    ui.Default_Y_Right_Box -> setValue(msg_tune2walk.Default_Y_Right);
    ui.Default_Y_Left_Box -> setValue(msg_tune2walk.Default_Y_Left);
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Link2Link_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Link2Link = arg1;
    msg_tune2walk.Default_Z_Right=-(2*msg_tune2walk.Link2Link-msg_tune2walk.Init_Z_Up);
    msg_tune2walk.Default_Z_Left=-(2*msg_tune2walk.Link2Link-msg_tune2walk.Init_Z_Up);
    ui.Default_Z_Right_Box -> setValue(msg_tune2walk.Default_Z_Right);
    ui.Default_Z_Left_Box -> setValue(msg_tune2walk.Default_Z_Left);
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Init_Z_Up_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Init_Z_Up = arg1;
    msg_tune2walk.Default_Z_Right=-(2*msg_tune2walk.Link2Link-msg_tune2walk.Init_Z_Up);
    msg_tune2walk.Default_Z_Left=-(2*msg_tune2walk.Link2Link-msg_tune2walk.Init_Z_Up);
    ui.Default_Z_Right_Box -> setValue(msg_tune2walk.Default_Z_Right);
    ui.Default_Z_Left_Box -> setValue(msg_tune2walk.Default_Z_Left);
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Init_Z_Up_Plus_Button_clicked()
{
    msg_tune2walk.Init_Z_Up +=1;
    if(msg_tune2walk.Init_Z_Up>=75)msg_tune2walk.Init_Z_Up=75;
    ui.Init_Z_Up_Box -> setValue(msg_tune2walk.Init_Z_Up);
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Init_Z_Up_Minus_Button_clicked()
{
    msg_tune2walk.Init_Z_Up -=1;
    if(msg_tune2walk.Init_Z_Up<=1)msg_tune2walk.Init_Z_Up=1;
    ui.Init_Z_Up_Box -> setValue(msg_tune2walk.Init_Z_Up);
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Ratio_Check_Box_clicked()
{
    if(msg_tune2walk.Ratio_Check_Flag == 0)
    {
        msg_tune2walk.Ratio_Check_Flag = 1;
        cout<<"Double"<<endl;
    }
    else if(msg_tune2walk.Ratio_Check_Flag == 1)
    {
        msg_tune2walk.Ratio_Check_Flag = 0;
         cout<<"Single"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}
//------------------------------Offset--------------------------------------//
//////////////////////////////////////////////////////////////////////////////
void tune_walk::MainWindow::on_All_Offset_Zero_Button_clicked()
{
    QMessageBox Reset_Check_Box;
    Reset_Check_Box.setText("Do you really want to reset it?");
    Reset_Check_Box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    Reset_Check_Box.setDefaultButton(QMessageBox::Cancel);

    if(Reset_Check_Box.exec() == QMessageBox::Ok)
    {
    msg_tune2walk.Offset_10_Motor = 0.0;
    msg_tune2walk.Offset_11_Motor = 0.0;
    msg_tune2walk.Offset_12_Motor = 0.0;
    msg_tune2walk.Offset_13_Motor = 0.0;
    msg_tune2walk.Offset_14_Motor = 0.0;
    msg_tune2walk.Offset_15_Motor = 0.0;
    msg_tune2walk.Offset_16_Motor = 0.0;
    msg_tune2walk.Offset_17_Motor = 0.0;
    msg_tune2walk.Offset_18_Motor = 0.0;
    msg_tune2walk.Offset_19_Motor = 0.0;
    msg_tune2walk.Offset_20_Motor = 0.0;
    msg_tune2walk.Offset_21_Motor = 0.0;
    angle_update();
    past_motor_update();
    Offset_scroll_reset(0);

    arr_reset();
    }
}
void tune_walk::MainWindow::past_motor_update()
{
    offset_past_motor10 = msg_tune2walk.Offset_10_Motor;
    offset_past_motor11 = msg_tune2walk.Offset_11_Motor;
    offset_past_motor12 = msg_tune2walk.Offset_12_Motor;
    offset_past_motor13 = msg_tune2walk.Offset_13_Motor;
    offset_past_motor14 = msg_tune2walk.Offset_14_Motor;
    offset_past_motor15 = msg_tune2walk.Offset_15_Motor;
    offset_past_motor16 = msg_tune2walk.Offset_16_Motor;
    offset_past_motor17 = msg_tune2walk.Offset_17_Motor;
    offset_past_motor18 = msg_tune2walk.Offset_18_Motor;
    offset_past_motor19 = msg_tune2walk.Offset_19_Motor;
    offset_past_motor20 = msg_tune2walk.Offset_20_Motor;
    offset_past_motor21 = msg_tune2walk.Offset_21_Motor;
}

void tune_walk::MainWindow::angle_update()
{
    ui.Motor_10_Minus -> setText(QString::number(msg_tune2walk.Offset_10_Motor));
    ui.Motor_11_Minus -> setText(QString::number(msg_tune2walk.Offset_11_Motor));
    ui.Motor_12_Minus -> setText(QString::number(msg_tune2walk.Offset_12_Motor));
    ui.Motor_13_Minus -> setText(QString::number(msg_tune2walk.Offset_13_Motor));
    ui.Motor_14_Minus -> setText(QString::number(msg_tune2walk.Offset_14_Motor));
    ui.Motor_15_Minus -> setText(QString::number(msg_tune2walk.Offset_15_Motor));
    ui.Motor_16_Minus -> setText(QString::number(msg_tune2walk.Offset_16_Motor));
    ui.Motor_17_Minus -> setText(QString::number(msg_tune2walk.Offset_17_Motor));
    ui.Motor_18_Minus -> setText(QString::number(msg_tune2walk.Offset_18_Motor));
    ui.Motor_19_Minus -> setText(QString::number(msg_tune2walk.Offset_19_Motor));
    ui.Motor_20_Minus -> setText(QString::number(msg_tune2walk.Offset_20_Motor));
    ui.Motor_21_Minus -> setText(QString::number(msg_tune2walk.Offset_21_Motor));

    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::arr_update()
{
    if(motor_plus_arr[0] != 0) ui.plus_Button_0 -> setText(QString::number(motor_plus_arr[0]));
    else ui.plus_Button_0 -> setText(" ");
    if(motor_plus_arr[1] != 0) ui.plus_Button_1 -> setText(QString::number(motor_plus_arr[1]));
    else ui.plus_Button_1-> setText(" ");
    if(motor_plus_arr[2] != 0) ui.plus_Button_2 -> setText(QString::number(motor_plus_arr[2]));
    else ui.plus_Button_2 -> setText(" ");
    if(motor_plus_arr[3] != 0) ui.plus_Button_3 -> setText(QString::number(motor_plus_arr[3]));
    else ui.plus_Button_3 -> setText(" ");

    if(motor_minus_arr[0] != 0) ui.minus_Button_0 -> setText(QString::number(motor_minus_arr[0]));
    else ui.minus_Button_0 -> setText(" ");
    if(motor_minus_arr[1] != 0) ui.minus_Button_1 -> setText(QString::number(motor_minus_arr[1]));
    else ui.minus_Button_1 -> setText(" ");
    if(motor_minus_arr[2] != 0) ui.minus_Button_2 -> setText(QString::number(motor_minus_arr[2]));
    else ui.minus_Button_2 -> setText(" ");
    if(motor_minus_arr[3] != 0) ui.minus_Button_3 -> setText(QString::number(motor_minus_arr[3]));
    else ui.minus_Button_3 -> setText(" ");
}

void tune_walk::MainWindow::arr_reset()
{
    for(int i = 0; i < 4; i++)
    {
        motor_plus_arr[i] = 0;
        motor_minus_arr[i] = 0;
    }
    motor_plus_cnt = 0;
    motor_minus_cnt = 0;
    arr_update();
}

int tune_walk::MainWindow::arr_check(int arr[], int motor_num)
{
    for(int i = 3; i >= 0; i--)
    {
        if(arr[i] != motor_num && i == 0) return -1;
        else if(arr[i] == motor_num)
        {
            return i;
            break;
        }
    }
}

int tune_walk::MainWindow::arr_num_cnt(int num, int arr[], int size) {
    int cnt = 0;
    for (int i = 0; i < size; i++) if (arr[i] == num) cnt++;
    return cnt;
}

void tune_walk::MainWindow::Motor_Num_Toss(int Pos_or_Neg, int motor_num)
{
    if(Pos_or_Neg >= 0)
    {
        arr_check_num = arr_check(motor_minus_arr, motor_num);
        if(arr_check_num != -1)
        {
            motor_minus_arr[arr_check_num] = 0;
            for(int i = arr_check_num; i < 3; i++)
            {
                motor_minus_arr[i] = motor_minus_arr[i + 1];
                motor_minus_arr[i + 1] = 0;
            }
            if(motor_minus_cnt > 0) motor_minus_cnt--;
        }
        else if(motor_plus_cnt < 4)
        {
            if(motor_plus_arr[motor_plus_cnt] == 0) motor_plus_arr[motor_plus_cnt] = motor_num;
            if(motor_plus_cnt != 3) motor_plus_cnt++;
        }
    }
    else
    {
        arr_check_num = arr_check(motor_plus_arr, motor_num);
        if(arr_check_num != -1)
        {
            motor_plus_arr[arr_check_num] = 0;
            for(int i = arr_check_num; i < 3; i++)
            {
                motor_plus_arr[i] = motor_plus_arr[i + 1];
                motor_plus_arr[i + 1] = 0;
            }
            if(motor_plus_cnt > 0) motor_plus_cnt--;
        }
        else if(motor_minus_cnt < 4)
        {
            if(motor_minus_arr[motor_minus_cnt] == 0) motor_minus_arr[motor_minus_cnt] = motor_num;
            if(motor_minus_cnt != 3) motor_minus_cnt++;
        }
    }
    arr_update();
}

void tune_walk::MainWindow::Offset_scroll_reset(int button_flag)
{
    if(Offset_Scroll_Value != 0)
    {
        Offset_Scroll_Value = 0;
        ui.Angle_Control_Box -> setValue(Offset_Scroll_Value);
        ui.Angle_horizontalScrollBar -> setValue(Offset_Scroll_Value);
    }
    if(button_flag == 1)
    {
        if(arr_check(motor_plus_arr, 10) == -1) msg_tune2walk.Offset_10_Motor = offset_past_motor10;
        if(arr_check(motor_plus_arr, 11) == -1) msg_tune2walk.Offset_11_Motor = offset_past_motor11;
        if(arr_check(motor_plus_arr, 12) == -1) msg_tune2walk.Offset_12_Motor = offset_past_motor12;
        if(arr_check(motor_plus_arr, 13) == -1) msg_tune2walk.Offset_13_Motor = offset_past_motor13;
        if(arr_check(motor_plus_arr, 14) == -1) msg_tune2walk.Offset_14_Motor = offset_past_motor14;
        if(arr_check(motor_plus_arr, 15) == -1) msg_tune2walk.Offset_15_Motor = offset_past_motor15;
        if(arr_check(motor_plus_arr, 16) == -1) msg_tune2walk.Offset_16_Motor = offset_past_motor16;
        if(arr_check(motor_plus_arr, 17) == -1) msg_tune2walk.Offset_17_Motor = offset_past_motor17;
        if(arr_check(motor_plus_arr, 18) == -1) msg_tune2walk.Offset_18_Motor = offset_past_motor18;
        if(arr_check(motor_plus_arr, 19) == -1) msg_tune2walk.Offset_19_Motor = offset_past_motor19;
        if(arr_check(motor_plus_arr, 20) == -1) msg_tune2walk.Offset_20_Motor = offset_past_motor20;
        if(arr_check(motor_plus_arr, 21) == -1) msg_tune2walk.Offset_21_Motor = offset_past_motor21;

        if(arr_check(motor_minus_arr, 10) == -1) msg_tune2walk.Offset_10_Motor = offset_past_motor10;
        if(arr_check(motor_minus_arr, 11) == -1) msg_tune2walk.Offset_11_Motor = offset_past_motor11;
        if(arr_check(motor_minus_arr, 12) == -1) msg_tune2walk.Offset_12_Motor = offset_past_motor12;
        if(arr_check(motor_minus_arr, 13) == -1) msg_tune2walk.Offset_13_Motor = offset_past_motor13;
        if(arr_check(motor_minus_arr, 14) == -1) msg_tune2walk.Offset_14_Motor = offset_past_motor14;
        if(arr_check(motor_minus_arr, 15) == -1) msg_tune2walk.Offset_15_Motor = offset_past_motor15;
        if(arr_check(motor_minus_arr, 16) == -1) msg_tune2walk.Offset_16_Motor = offset_past_motor16;
        if(arr_check(motor_minus_arr, 17) == -1) msg_tune2walk.Offset_17_Motor = offset_past_motor17;
        if(arr_check(motor_minus_arr, 18) == -1) msg_tune2walk.Offset_18_Motor = offset_past_motor18;
        if(arr_check(motor_minus_arr, 19) == -1) msg_tune2walk.Offset_19_Motor = offset_past_motor19;
        if(arr_check(motor_minus_arr, 20) == -1) msg_tune2walk.Offset_20_Motor = offset_past_motor20;
        if(arr_check(motor_minus_arr, 21) == -1) msg_tune2walk.Offset_21_Motor = offset_past_motor21;
        angle_update();
    }
}

void tune_walk::MainWindow::motor_limit_control()
{
    if(msg_tune2walk.Offset_10_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_10_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_10_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_10_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_11_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_11_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_11_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_11_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_12_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_12_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_12_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_12_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_13_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_13_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_13_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_13_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_14_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_14_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_14_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_14_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_15_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_15_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_15_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_15_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_16_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_16_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_16_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_16_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_17_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_17_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_17_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_17_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_18_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_18_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_18_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_18_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_19_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_19_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_19_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_19_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_20_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_20_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_20_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_20_Motor = -Offset_Angle_Limit;
    if(msg_tune2walk.Offset_21_Motor > Offset_Angle_Limit)       msg_tune2walk.Offset_21_Motor = +Offset_Angle_Limit;
    else if(msg_tune2walk.Offset_21_Motor < -Offset_Angle_Limit) msg_tune2walk.Offset_21_Motor = -Offset_Angle_Limit;
}

void tune_walk::MainWindow::on_Motor_10_Plus_clicked()
{
    Motor_Num_Toss(+1, 10);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_11_Plus_clicked()
{
    Motor_Num_Toss(+1, 11);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_12_Plus_clicked()
{
    Motor_Num_Toss(+1, 12);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_13_Plus_clicked()
{
    Motor_Num_Toss(+1, 13);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_14_Plus_clicked()
{
    Motor_Num_Toss(+1, 14);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_15_Plus_clicked()
{
    Motor_Num_Toss(+1, 15);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_16_Plus_clicked()
{
    Motor_Num_Toss(+1, 16);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_17_Plus_clicked()
{
    Motor_Num_Toss(+1, 17);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_18_Plus_clicked()
{
    Motor_Num_Toss(+1, 18);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_19_Plus_clicked()
{
    Motor_Num_Toss(+1, 19);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_20_Plus_clicked()
{
    Motor_Num_Toss(+1, 20);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_21_Plus_clicked()
{
    Motor_Num_Toss(+1, 21);
    Offset_scroll_reset(1);
}

void tune_walk::MainWindow::on_Motor_10_Minus_clicked()
{
    Motor_Num_Toss(-1, 10);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_11_Minus_clicked()
{
    Motor_Num_Toss(-1, 11);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_12_Minus_clicked()
{
    Motor_Num_Toss(-1, 12);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_13_Minus_clicked()
{
    Motor_Num_Toss(-1, 13);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_14_Minus_clicked()
{
    Motor_Num_Toss(-1, 14);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_15_Minus_clicked()
{
    Motor_Num_Toss(-1, 15);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_16_Minus_clicked()
{
    Motor_Num_Toss(-1, 16);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_17_Minus_clicked()
{
    Motor_Num_Toss(-1, 17);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_18_Minus_clicked()
{
    Motor_Num_Toss(-1, 18);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_19_Minus_clicked()
{
    Motor_Num_Toss(-1, 19);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_20_Minus_clicked()
{
    Motor_Num_Toss(-1, 20);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Motor_21_Minus_clicked()
{
   Motor_Num_Toss(-1, 21);
   Offset_scroll_reset(1);
}

void tune_walk::MainWindow::on_plus_Button_0_clicked()
{
    if(motor_plus_arr[0] != 0)
    {
        for(int i = 0; i < 7; i++)
        {
            motor_plus_arr[i] = motor_plus_arr[i + 1];
            motor_plus_arr[i + 1] = 0;
        }
        if(motor_plus_cnt > 0) motor_plus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_plus_Button_1_clicked()
{
    if(motor_plus_arr[1] != 0)
    {
        for(int i = 1; i < 7; i++)
        {
            motor_plus_arr[i] = motor_plus_arr[i + 1];
            motor_plus_arr[i + 1] = 0;
        }
        motor_plus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_plus_Button_2_clicked()
{
    if(motor_plus_arr[2] != 0)
    {
        for(int i = 2; i < 7; i++)
        {
            motor_plus_arr[i] = motor_plus_arr[i + 1];
            motor_plus_arr[i + 1] = 0;
        }
        motor_plus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_plus_Button_3_clicked()
{
    if(motor_plus_arr[3] != 0)
    {
        for(int i = 3; i < 7; i++)
        {
            motor_plus_arr[i] = motor_plus_arr[i + 1];
            motor_plus_arr[i + 1] = 0;
        }
        motor_plus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}


void tune_walk::MainWindow::on_minus_Button_0_clicked()
{
    if(motor_minus_arr[0] != 0)
    {
        for(int i = 0; i < 7; i++)
        {
            motor_minus_arr[i] = motor_minus_arr[i + 1];
            motor_minus_arr[i + 1] = 0;
        }
        if(motor_minus_cnt > 0) motor_minus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_minus_Button_1_clicked()
{
    if(motor_minus_arr[1] != 0)
    {
        for(int i = 1; i < 7; i++)
        {
            motor_minus_arr[i] = motor_minus_arr[i + 1];
            motor_minus_arr[i + 1] = 0;
        }
        motor_minus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_minus_Button_2_clicked()
{
    if(motor_minus_arr[2] != 0)
    {
        for(int i = 2; i < 7; i++)
        {
            motor_minus_arr[i] = motor_minus_arr[i + 1];
            motor_minus_arr[i + 1] = 0;
        }
        motor_minus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_minus_Button_3_clicked()
{
    if(motor_minus_arr[3] != 0)
    {
        for(int i = 3; i < 7; i++)
        {
            motor_minus_arr[i] = motor_minus_arr[i + 1];
            motor_minus_arr[i + 1] = 0;
        }
        motor_minus_cnt--;
    }
    arr_update();
    Offset_scroll_reset(1);
}


void tune_walk::MainWindow::on_Angle_horizontalScrollBar_valueChanged(int value)
{
    Offset_Scroll_Value = value;
    ui.Angle_Control_Box -> setValue(Offset_Scroll_Value);
}

void tune_walk::MainWindow::on_Angle_Control_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    Offset_Scroll_Value = arg1;
    ui.Angle_horizontalScrollBar -> setValue(Offset_Scroll_Value);

    for(int i = 0; i < 3; i++)
    {
        if(motor_plus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10 + (arr_num_cnt(10, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11 + (arr_num_cnt(11, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12 + (arr_num_cnt(12, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13 + (arr_num_cnt(13, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14 + (arr_num_cnt(14, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15 + (arr_num_cnt(15, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16 + (arr_num_cnt(16, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17 + (arr_num_cnt(17, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18 + (arr_num_cnt(18, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19 + (arr_num_cnt(19, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20 + (arr_num_cnt(20, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21 + (arr_num_cnt(21, motor_plus_arr, 8)*Offset_Scroll_Value);

        if(motor_minus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10 - (arr_num_cnt(10, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11 - (arr_num_cnt(11, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12 - (arr_num_cnt(12, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13 - (arr_num_cnt(13, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14 - (arr_num_cnt(14, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15 - (arr_num_cnt(15, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16 - (arr_num_cnt(16, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17 - (arr_num_cnt(17, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18 - (arr_num_cnt(18, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19 - (arr_num_cnt(19, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20 - (arr_num_cnt(20, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21 - (arr_num_cnt(21, motor_minus_arr, 8)*Offset_Scroll_Value);
    }
    motor_limit_control();
    angle_update();
}

void tune_walk::MainWindow::on_offset_O_Button_clicked()
{
    for(int i = 0; i < 3; i++)
    {
        if(motor_plus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10 + (arr_num_cnt(10, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11 + (arr_num_cnt(11, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12 + (arr_num_cnt(12, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13 + (arr_num_cnt(13, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14 + (arr_num_cnt(14, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15 + (arr_num_cnt(15, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16 + (arr_num_cnt(16, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17 + (arr_num_cnt(17, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18 + (arr_num_cnt(18, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19 + (arr_num_cnt(19, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20 + (arr_num_cnt(20, motor_plus_arr, 8)*Offset_Scroll_Value);
        else if(motor_plus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21 + (arr_num_cnt(21, motor_plus_arr, 8)*Offset_Scroll_Value);

        if(motor_minus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10 - (arr_num_cnt(10, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11 - (arr_num_cnt(11, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12 - (arr_num_cnt(12, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13 - (arr_num_cnt(13, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14 - (arr_num_cnt(14, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15 - (arr_num_cnt(15, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16 - (arr_num_cnt(16, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17 - (arr_num_cnt(17, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18 - (arr_num_cnt(18, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19 - (arr_num_cnt(19, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20 - (arr_num_cnt(20, motor_minus_arr, 8)*Offset_Scroll_Value);
        else if(motor_minus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21 - (arr_num_cnt(21, motor_minus_arr, 8)*Offset_Scroll_Value);
    }
    motor_limit_control();
    angle_update();
    past_motor_update();

    Offset_scroll_reset(0);

    arr_reset();
}
void tune_walk::MainWindow::on_offset_X_Button_clicked()
{
    for(int i = 0; i < 3; i++)
    {
        if(motor_plus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10;
        else if(motor_plus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11;
        else if(motor_plus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12;
        else if(motor_plus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13;
        else if(motor_plus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14;
        else if(motor_plus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15;
        else if(motor_plus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16;
        else if(motor_plus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17;
        else if(motor_plus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18;
        else if(motor_plus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19;
        else if(motor_plus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20;
        else if(motor_plus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21;

        if(motor_minus_arr[i] == 10)      msg_tune2walk.Offset_10_Motor = offset_past_motor10;
        else if(motor_minus_arr[i] == 11) msg_tune2walk.Offset_11_Motor = offset_past_motor11;
        else if(motor_minus_arr[i] == 12) msg_tune2walk.Offset_12_Motor = offset_past_motor12;
        else if(motor_minus_arr[i] == 13) msg_tune2walk.Offset_13_Motor = offset_past_motor13;
        else if(motor_minus_arr[i] == 14) msg_tune2walk.Offset_14_Motor = offset_past_motor14;
        else if(motor_minus_arr[i] == 15) msg_tune2walk.Offset_15_Motor = offset_past_motor15;
        else if(motor_minus_arr[i] == 16) msg_tune2walk.Offset_16_Motor = offset_past_motor16;
        else if(motor_minus_arr[i] == 17) msg_tune2walk.Offset_17_Motor = offset_past_motor17;
        else if(motor_minus_arr[i] == 18) msg_tune2walk.Offset_18_Motor = offset_past_motor18;
        else if(motor_minus_arr[i] == 19) msg_tune2walk.Offset_19_Motor = offset_past_motor19;
        else if(motor_minus_arr[i] == 20) msg_tune2walk.Offset_20_Motor = offset_past_motor20;
        else if(motor_minus_arr[i] == 21) msg_tune2walk.Offset_21_Motor = offset_past_motor21;
    }
    motor_limit_control();
    angle_update();

    Offset_Scroll_Value = 0;
    ui.Angle_Control_Box -> setValue(Offset_Scroll_Value);
    ui.Angle_horizontalScrollBar -> setValue(Offset_Scroll_Value);

    arr_reset();
}


////////////////////////////////////////////////////////////////////Notice : check mecro motor direction////////////////////////////

void tune_walk::MainWindow::on_Stand_Button_clicked()
{
    arr_reset();
    Motor_Num_Toss(+1, 14);
    Motor_Num_Toss(-1, 16);
    Motor_Num_Toss(-1, 16);
    Motor_Num_Toss(+1, 18);

    Motor_Num_Toss(+1, 15);
    Motor_Num_Toss(-1, 17);
    Motor_Num_Toss(-1, 17);
    Motor_Num_Toss(+1, 19);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Stand_Left_Button_clicked()
{
    arr_reset();
    Motor_Num_Toss(+1, 14);
    Motor_Num_Toss(-1, 16);
    Motor_Num_Toss(-1, 16);
    Motor_Num_Toss(+1, 18);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Stand_Right_Button_clicked()
{
    arr_reset();
    Motor_Num_Toss(+1, 15);
    Motor_Num_Toss(-1, 17);
    Motor_Num_Toss(-1, 17);
    Motor_Num_Toss(+1, 19);
    Offset_scroll_reset(1);
}
void tune_walk::MainWindow::on_Stretch_Button_clicked()
{
    arr_reset();
    Motor_Num_Toss(+1, 10);
    Motor_Num_Toss(-1, 11);

    Motor_Num_Toss(-1, 20);
    Motor_Num_Toss(+1, 21);
    Offset_scroll_reset(1);
}
//////////////////////////////////Percentage_of_IK////////////////////////////


void tune_walk::MainWindow::on_Percentage_of_10_Motor_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_10_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Percentage_of_11_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_11_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_12_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_12_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_13_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_13_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_14_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_14_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_15_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_15_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_16_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_16_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_17_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_17_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_18_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_18_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_19_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_19_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_20_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_20_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Percentage_of_21_Motor_Box_valueChanged(double arg1)
{

    if(arg1 < 0.1 && arg1 > 0) arg1 = 0.1;
    if(arg1 == 0.0) arg1 = 1.0;
    msg_tune2walk.Percentage_of_IK_21_Motor = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

//////////////////////////////////////Tuning////////////////////////////////
void tune_walk::MainWindow::on_Swing_Right_Leg_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Swing_Right_Leg = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Right_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Swing_Right_Leg +=1;
    if(msg_tune2walk.Swing_Right_Leg>=100)msg_tune2walk.Swing_Right_Leg=100;
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Right_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Swing_Right_Leg -=1;
    if(msg_tune2walk.Swing_Right_Leg<=-100)msg_tune2walk.Swing_Right_Leg=-100;
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Leg_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Swing_Left_Leg = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg +=1;
    if(msg_tune2walk.Swing_Left_Leg>=100)msg_tune2walk.Swing_Left_Leg=100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg -=1;
    if(msg_tune2walk.Swing_Left_Leg<=-100)msg_tune2walk.Swing_Left_Leg=-100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Both_Leg_Plus5_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg +=5;
    msg_tune2walk.Swing_Right_Leg +=5;
    if(msg_tune2walk.Swing_Left_Leg>=100)msg_tune2walk.Swing_Left_Leg=100;
    if(msg_tune2walk.Swing_Right_Leg>=100)msg_tune2walk.Swing_Right_Leg=100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Both_Leg_Minus5_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg -=5;
    msg_tune2walk.Swing_Right_Leg -=5;
    if(msg_tune2walk.Swing_Left_Leg<=-100)msg_tune2walk.Swing_Left_Leg=-100;
    if(msg_tune2walk.Swing_Right_Leg<=-100)msg_tune2walk.Swing_Right_Leg=-100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Both_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg +=1;
    msg_tune2walk.Swing_Right_Leg +=1;
    if(msg_tune2walk.Swing_Left_Leg>=100)msg_tune2walk.Swing_Left_Leg=100;
    if(msg_tune2walk.Swing_Right_Leg>=100)msg_tune2walk.Swing_Right_Leg=100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Both_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Leg -=1;
    msg_tune2walk.Swing_Right_Leg -=1;
    if(msg_tune2walk.Swing_Left_Leg<=-100)msg_tune2walk.Swing_Left_Leg=-100;
    if(msg_tune2walk.Swing_Right_Leg<=-100)msg_tune2walk.Swing_Right_Leg=-100;
    ui.Swing_Left_Leg_Box -> setValue(msg_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Leg_Box -> setValue(msg_tune2walk.Swing_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Right_Shoulder_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Swing_Right_Shoulder = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Right_Shoulder_Plus_Button_clicked()
{
    msg_tune2walk.Swing_Right_Shoulder +=1;
    if(msg_tune2walk.Swing_Right_Shoulder>=100)msg_tune2walk.Swing_Right_Shoulder=100;
    ui.Swing_Right_Shoulder_Box -> setValue(msg_tune2walk.Swing_Right_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Right_Shoulder_Minus_Button_clicked()
{
    msg_tune2walk.Swing_Right_Shoulder -=1;
    if(msg_tune2walk.Swing_Right_Shoulder<=-100)msg_tune2walk.Swing_Right_Shoulder=-100;
    ui.Swing_Right_Shoulder_Box -> setValue(msg_tune2walk.Swing_Right_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Shoulder_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Swing_Left_Shoulder = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Shoulder_Plus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Shoulder +=1;
    if(msg_tune2walk.Swing_Left_Shoulder>=100)msg_tune2walk.Swing_Left_Shoulder=100;
    ui.Swing_Left_Shoulder_Box -> setValue(msg_tune2walk.Swing_Left_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Left_Shoulder_Minus_Button_clicked()
{
    msg_tune2walk.Swing_Left_Shoulder -=1;
    if(msg_tune2walk.Swing_Left_Shoulder<=-100)msg_tune2walk.Swing_Left_Shoulder=-100;
    ui.Swing_Left_Shoulder_Box -> setValue(msg_tune2walk.Swing_Left_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Swing_Both_Shoulder_Plus5_Button_clicked()
{
    msg_tune2walk.Swing_Left_Shoulder +=5;
    msg_tune2walk.Swing_Right_Shoulder +=5;
    if(msg_tune2walk.Swing_Left_Shoulder>=100)msg_tune2walk.Swing_Left_Shoulder=100;
    if(msg_tune2walk.Swing_Right_Shoulder>=100)msg_tune2walk.Swing_Right_Shoulder=100;
    ui.Swing_Left_Shoulder_Box -> setValue(msg_tune2walk.Swing_Left_Shoulder);
    ui.Swing_Right_Shoulder_Box -> setValue(msg_tune2walk.Swing_Right_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Swing_Both_Shoulder_Minus5_Button_clicked()
{
    msg_tune2walk.Swing_Left_Shoulder -=5;
    msg_tune2walk.Swing_Right_Shoulder -=5;
    if(msg_tune2walk.Swing_Left_Shoulder<=-100)msg_tune2walk.Swing_Left_Shoulder=-100;
    if(msg_tune2walk.Swing_Right_Shoulder<=-100)msg_tune2walk.Swing_Right_Shoulder=-100;
    ui.Swing_Left_Shoulder_Box -> setValue(msg_tune2walk.Swing_Left_Shoulder);
    ui.Swing_Right_Shoulder_Box -> setValue(msg_tune2walk.Swing_Right_Shoulder);
    tune2walk_Pub.publish(msg_tune2walk);
}


void tune_walk::MainWindow::on_Rise_Right_Leg_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Rise_Right_Leg = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_Right_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Rise_Right_Leg +=1;
    if(msg_tune2walk.Rise_Right_Leg>=100)msg_tune2walk.Rise_Right_Leg=100;
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_Right_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Rise_Right_Leg -=1;
    if(msg_tune2walk.Rise_Right_Leg<=-100)msg_tune2walk.Rise_Right_Leg=-100;
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_Left_Leg_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Rise_Left_Leg = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_Left_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg +=1;
    if(msg_tune2walk.Rise_Left_Leg>=100)msg_tune2walk.Rise_Left_Leg=100;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_Left_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg -=1;
    if(msg_tune2walk.Rise_Left_Leg<=-100)msg_tune2walk.Rise_Left_Leg=-100;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Rise_All_Leg_Plus_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg +=1;
    msg_tune2walk.Rise_Right_Leg +=1;
    if(msg_tune2walk.Rise_Left_Leg>=100)msg_tune2walk.Rise_Left_Leg=100;
    if(msg_tune2walk.Rise_Right_Leg>=100)msg_tune2walk.Rise_Right_Leg=100;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_All_Leg_Minus_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg -=1;
    msg_tune2walk.Rise_Right_Leg -=1;
    if(msg_tune2walk.Rise_Left_Leg<=0)msg_tune2walk.Rise_Left_Leg=0;
    if(msg_tune2walk.Rise_Right_Leg<=0)msg_tune2walk.Rise_Right_Leg=0;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_All_Leg_Plus5_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg +=5;
    msg_tune2walk.Rise_Right_Leg +=5;
    if(msg_tune2walk.Rise_Left_Leg>=100)msg_tune2walk.Rise_Left_Leg=100;
    if(msg_tune2walk.Rise_Right_Leg>=100)msg_tune2walk.Rise_Right_Leg=100;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Rise_All_Leg_Minus5_Button_clicked()
{
    msg_tune2walk.Rise_Left_Leg -=5;
    msg_tune2walk.Rise_Right_Leg -=5;
    if(msg_tune2walk.Rise_Left_Leg<=0)msg_tune2walk.Rise_Left_Leg=0;
    if(msg_tune2walk.Rise_Right_Leg<=0)msg_tune2walk.Rise_Right_Leg=0;
    ui.Rise_Left_Leg_Box -> setValue(msg_tune2walk.Rise_Left_Leg);
    ui.Rise_Right_Leg_Box -> setValue(msg_tune2walk.Rise_Right_Leg);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Entire_Time_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Start_Entire_Time = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Entire_Time_Plus_Button_clicked()
{
    msg_tune2walk.Start_Entire_Time +=10;
    if(msg_tune2walk.Start_Entire_Time>=200)msg_tune2walk.Start_Entire_Time=200;
    ui.Start_Entire_Time_Box -> setValue(msg_tune2walk.Start_Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Entire_Time_Minus_Button_clicked()
{
    msg_tune2walk.Start_Entire_Time -=10;
    if(msg_tune2walk.Start_Entire_Time<=0)msg_tune2walk.Start_Entire_Time=0;
    ui.Start_Entire_Time_Box -> setValue(msg_tune2walk.Start_Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Swing_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Start_Swing = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Swing_Plus_Button_clicked()
{
    msg_tune2walk.Start_Swing +=1;
    if(msg_tune2walk.Start_Swing>=100)msg_tune2walk.Start_Swing=100;
    ui.Start_Swing_Box -> setValue(msg_tune2walk.Start_Swing);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Swing_Minus_Button_clicked()
{
    msg_tune2walk.Start_Swing -=1;
    if(msg_tune2walk.Start_Swing<=-100)msg_tune2walk.Start_Swing=-100;
    ui.Start_Swing_Box -> setValue(msg_tune2walk.Start_Swing);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Rise_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Start_Rise = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Rise_Plus_Button_clicked()
{
    msg_tune2walk.Start_Rise +=1;
    if(msg_tune2walk.Start_Rise>=100)msg_tune2walk.Start_Rise=100;
    ui.Start_Rise_Box -> setValue(msg_tune2walk.Start_Rise);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Start_Rise_Minus_Button_clicked()
{
    msg_tune2walk.Start_Rise -=1;
    if(msg_tune2walk.Start_Rise<=0)msg_tune2walk.Start_Rise=0;
    ui.Start_Rise_Box -> setValue(msg_tune2walk.Start_Rise);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Entire_Time_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.End_Entire_Time = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Entire_Time_Plus_Button_clicked()
{
    msg_tune2walk.End_Entire_Time +=10;
    if(msg_tune2walk.End_Entire_Time>=200)msg_tune2walk.End_Entire_Time=200;
    ui.End_Entire_Time_Box -> setValue(msg_tune2walk.End_Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Entire_Time_Minus_Button_clicked()
{
    msg_tune2walk.End_Entire_Time -=10;
    if(msg_tune2walk.End_Entire_Time<=0)msg_tune2walk.End_Entire_Time=0;
    ui.End_Entire_Time_Box -> setValue(msg_tune2walk.End_Entire_Time);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Swing_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.End_Swing = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Swing_Plus_Button_clicked()
{
    msg_tune2walk.End_Swing +=1;
    if(msg_tune2walk.End_Swing>=100)msg_tune2walk.End_Swing=100;
    ui.End_Swing_Box -> setValue(msg_tune2walk.End_Swing);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Swing_Minus_Button_clicked()
{
    msg_tune2walk.End_Swing -=1;
    if(msg_tune2walk.End_Swing<=-100)msg_tune2walk.End_Swing=-100;
    ui.End_Swing_Box -> setValue(msg_tune2walk.End_Swing);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Rise_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.End_Rise = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Rise_Plus_Button_clicked()
{
    msg_tune2walk.End_Rise +=1;
    if(msg_tune2walk.End_Rise>=100)msg_tune2walk.End_Rise=100;
    ui.End_Rise_Box -> setValue(msg_tune2walk.End_Rise);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_End_Rise_Minus_Button_clicked()
{
    msg_tune2walk.End_Rise -=1;
    if(msg_tune2walk.End_Rise<=0)msg_tune2walk.End_Rise=0;
    ui.End_Rise_Box -> setValue(msg_tune2walk.End_Rise);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_IK_Flag_Button_clicked()
{
    static bool Flag = true;
    if(Flag)
    {
      ui.IK_Flag_Button->setText("STOP");
      msg_tune2walk.IK_Flag = 1;
      Flag = false;
      cout<<"WALK"<<endl;
    }
    else if(!Flag)
    {
      ui.IK_Flag_Button->setText("WALK");
      msg_tune2walk.IK_Flag = 0;
      Flag = true;
      cout<<"STOP"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Tuning_X_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Tuning_X = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Tuning_Side_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Tuning_Side = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Tuning_Yaw_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Tuning_Yaw = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Test_X_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Test_X = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Test_Side_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Test_Side = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Test_Yaw_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Test_Yaw = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_0_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Value_0 = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_0_Plus_Button_clicked()
{
    msg_tune2walk.Balance_Value_0 +=1;
    if(msg_tune2walk.Balance_Value_0>=100)msg_tune2walk.Balance_Value_0=100;
    ui.Balance_Value_0_Box -> setValue(msg_tune2walk.Balance_Value_0);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_0_Minus_Button_clicked()
{
    msg_tune2walk.Balance_Value_0 -=1;
    if(msg_tune2walk.Balance_Value_0<=-100)msg_tune2walk.Balance_Value_0=-100;
    ui.Balance_Value_0_Box -> setValue(msg_tune2walk.Balance_Value_0);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Balance_Pitch_GP_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GP= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_GI_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GI= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_GD_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GD= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_Neg_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_Neg_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_Pos_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_Pos_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_ELIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_ELIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_OLIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_OLIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_checkBox_Pitch_ZMP_clicked()
{
    if(msg_tune2walk.Balance_Pitch_Flag==0)
    {
        msg_tune2walk.Balance_Pitch_Flag=1;
        cout<<"PID running"<<endl;
    }
    else
    {
        msg_tune2walk.Balance_Pitch_Flag=0;
         cout<<"PID OFF"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_GP_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_GP= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_GI_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_GI= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_GD_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_GD= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_ELIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_ELIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_OLIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_OLIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Ankle_Pitch_Neg_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_Neg_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Balance_Ankle_Pitch_Pos_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Angle_Pitch_Pos_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_checkBox_Ankle_Pitch_ZMP_clicked()
{
    if(msg_tune2walk.Balance_Ankle_Pitch_Flag==0)
    {
        msg_tune2walk.Balance_Ankle_Pitch_Flag=1;
        cout<<"Ankle_PID running"<<endl;
    }
    else
    {
        msg_tune2walk.Balance_Ankle_Pitch_Flag=0;
         cout<<"Ankle_PID OFF"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_1_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Value_1 = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_1_Plus_Button_clicked()
{
    msg_tune2walk.Balance_Value_1 +=1;
    if(msg_tune2walk.Balance_Value_1>=100)msg_tune2walk.Balance_Value_1=100;
    ui.Balance_Value_1_Box -> setValue(msg_tune2walk.Balance_Value_1);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_1_Minus_Button_clicked()
{
    msg_tune2walk.Balance_Value_1 -=1;
    if(msg_tune2walk.Balance_Value_1<=-100)msg_tune2walk.Balance_Value_1=-100;
    ui.Balance_Value_1_Box -> setValue(msg_tune2walk.Balance_Value_1);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_GP_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GP= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_GI_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GI= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_GD_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GD= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_ELIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_ELIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_OLIMIT_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_OLIMIT= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_Neg_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_Neg_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_Pos_Target_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_Pos_Target= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_checkBox_Ankle_Roll_ZMP_clicked()
{
    if(msg_tune2walk.Balance_Roll_Flag==0)
    {
        msg_tune2walk.Balance_Roll_Flag=1;
        cout<<"Roll_PID running"<<endl;
    }
    else
    {
        msg_tune2walk.Balance_Roll_Flag=0;
         cout<<"Roll_PID OFF"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_2_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Value_2 = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_2_Plus_Button_clicked()
{
    msg_tune2walk.Balance_Value_2 +=1;
    if(msg_tune2walk.Balance_Value_2>=100)msg_tune2walk.Balance_Value_2=100;
    ui.Balance_Value_2_Box -> setValue(msg_tune2walk.Balance_Value_2);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_2_Minus_Button_clicked()
{
    msg_tune2walk.Balance_Value_2 -=1;
    if(msg_tune2walk.Balance_Value_2<=-100)msg_tune2walk.Balance_Value_2=-100;
    ui.Balance_Value_2_Box -> setValue(msg_tune2walk.Balance_Value_2);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_3_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Value_3 = arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_3_Plus_Button_clicked()
{
    msg_tune2walk.Balance_Value_3 +=1;
    if(msg_tune2walk.Balance_Value_3>=100)msg_tune2walk.Balance_Value_3=100;
    ui.Balance_Value_3_Box -> setValue(msg_tune2walk.Balance_Value_3);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Blance_Value_3_Minus_Button_clicked()
{
    msg_tune2walk.Balance_Value_3 -=1;
    if(msg_tune2walk.Balance_Value_3<=-100)msg_tune2walk.Balance_Value_3=-100;
    ui.Balance_Value_3_Box -> setValue(msg_tune2walk.Balance_Value_3);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_L_Step_Pattern_Check_Box_clicked()
{
    if(L_Step_Pattern_Check_Flag == 0)  L_Step_Pattern_Check_Flag = 1;

    else if(L_Step_Pattern_Check_Flag == 1) L_Step_Pattern_Check_Flag = 0;

    cout<<"L_Step_Pattern_Check_Flag = "<<L_Step_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_L_COM_Pattern_Check_Box_clicked()
{
    if(L_COM_Pattern_Check_Flag == 0)  L_COM_Pattern_Check_Flag = 1;

    else if(L_COM_Pattern_Check_Flag == 1) L_COM_Pattern_Check_Flag = 0;

    cout<<"L_COM_Pattern_Check_Flag = "<<L_COM_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_L_Rise_Pattern_Check_Box_clicked()
{
    if(L_Rise_Pattern_Check_Flag == 0)  L_Rise_Pattern_Check_Flag = 1;

    else if(L_Rise_Pattern_Check_Flag == 1) L_Rise_Pattern_Check_Flag = 0;

    cout<<"L_Rise_Pattern_Check_Flag = "<<L_Rise_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_L_Side_Pattern_Check_Box_clicked()
{
    if(L_Side_Pattern_Check_Flag == 0)  L_Side_Pattern_Check_Flag = 1;

    else if(L_Side_Pattern_Check_Flag == 1) L_Side_Pattern_Check_Flag = 0;

    cout<<"L_Side_Pattern_Check_Flag = "<<L_Side_Pattern_Check_Flag<<endl;
}

void tune_walk::MainWindow::on_L_Turn_Pattern_Check_Box_clicked()
{
    if(L_Turn_Pattern_Check_Flag == 0)  L_Turn_Pattern_Check_Flag = 1;

    else if(L_Turn_Pattern_Check_Flag == 1) L_Turn_Pattern_Check_Flag = 0;

    cout<<"L_Turn_Pattern_Check_Flag = "<<L_Turn_Pattern_Check_Flag<<endl;
}

void tune_walk::MainWindow::on_R_Step_Pattern_Check_Box_clicked()
{
    if(R_Step_Pattern_Check_Flag == 0)  R_Step_Pattern_Check_Flag = 1;

    else if(R_Step_Pattern_Check_Flag == 1) R_Step_Pattern_Check_Flag = 0;

    cout<<"R_Step_Pattern_Check_Flag = "<<R_Step_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_R_COM_Pattern_Check_Box_clicked()
{
    if(R_COM_Pattern_Check_Flag == 0)  R_COM_Pattern_Check_Flag = 1;

    else if(R_COM_Pattern_Check_Flag == 1) R_COM_Pattern_Check_Flag = 0;

    cout<<"R_COM_Pattern_Check_Flag = "<<R_COM_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_R_Rise_Pattern_Check_Box_clicked()
{
    if(R_Rise_Pattern_Check_Flag == 0)  R_Rise_Pattern_Check_Flag = 1;

    else if(R_Rise_Pattern_Check_Flag == 1) R_Rise_Pattern_Check_Flag = 0;

    cout<<"R_Rise_Pattern_Check_Flag = "<<R_Rise_Pattern_Check_Flag<<endl;
}
void tune_walk::MainWindow::on_R_Side_Pattern_Check_Box_clicked()
{
    if(R_Side_Pattern_Check_Flag == 0)  R_Side_Pattern_Check_Flag = 1;

    else if(R_Side_Pattern_Check_Flag == 1) R_Side_Pattern_Check_Flag = 0;

    cout<<"R_Side_Pattern_Check_Flag = "<<R_Side_Pattern_Check_Flag<<endl;
}

void tune_walk::MainWindow::on_R_Turn_Pattern_Check_Box_clicked()
{
    if(R_Turn_Pattern_Check_Flag == 0)  R_Turn_Pattern_Check_Flag = 1;

    else if(R_Turn_Pattern_Check_Flag == 1) R_Turn_Pattern_Check_Flag = 0;

    cout<<"R_Turn_Pattern_Check_Flag = "<<R_Turn_Pattern_Check_Flag<<endl;
}

void tune_walk::MainWindow::on_Reset_Button_clicked()
{
    QMessageBox Reset_Check_Box;
    Reset_Check_Box.setText("Do you really want to reset it?");
    Reset_Check_Box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    Reset_Check_Box.setDefaultButton(QMessageBox::Cancel);

    if(Reset_Check_Box.exec() == QMessageBox::Ok)
    {
    ui.Entire_Time_Box->setValue(msg_init_tune2walk.Entire_Time);
    ui.Frequency_Box->setValue(msg_init_tune2walk.Frequency);
    ui.Center2Leg_Box->setValue(msg_init_tune2walk.Center2Leg);
    ui.Link2Link_Box->setValue(msg_init_tune2walk.Link2Link);
    ui.Init_Z_Up_Box->setValue(msg_init_tune2walk.Init_Z_Up);
    ui.Default_X_Right_Box->setValue(msg_init_tune2walk.Default_X_Right);
    ui.Default_X_Left_Box->setValue(msg_init_tune2walk.Default_X_Left);
    ui.Default_Y_Right_Box->setValue(msg_init_tune2walk.Default_Y_Right);
    ui.Default_Y_Left_Box->setValue(msg_init_tune2walk.Default_Y_Left);
    ui.Default_Z_Right_Box->setValue(msg_init_tune2walk.Default_Z_Right);
    ui.Default_Z_Left_Box->setValue(msg_init_tune2walk.Default_Z_Left);
    msg_tune2walk.Offset_10_Motor = 0.0;
    msg_tune2walk.Offset_11_Motor = 0.0;
    msg_tune2walk.Offset_12_Motor = 0.0;
    msg_tune2walk.Offset_13_Motor = 0.0;
    msg_tune2walk.Offset_14_Motor = 0.0;
    msg_tune2walk.Offset_15_Motor = 0.0;
    msg_tune2walk.Offset_16_Motor = 0.0;
    msg_tune2walk.Offset_17_Motor = 0.0;
    msg_tune2walk.Offset_18_Motor = 0.0;
    msg_tune2walk.Offset_19_Motor = 0.0;
    msg_tune2walk.Offset_20_Motor = 0.0;
    msg_tune2walk.Offset_21_Motor = 0.0;
    angle_update();
    past_motor_update();
    arr_reset();
    Offset_scroll_reset(0);
    ui.Percentage_of_10_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_10_Motor);
    ui.Percentage_of_11_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_11_Motor);
    ui.Percentage_of_12_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_12_Motor);
    ui.Percentage_of_13_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_13_Motor);
    ui.Percentage_of_14_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_14_Motor);
    ui.Percentage_of_15_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_15_Motor);
    ui.Percentage_of_16_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_16_Motor);
    ui.Percentage_of_17_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_17_Motor);
    ui.Percentage_of_18_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_18_Motor);
    ui.Percentage_of_19_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_19_Motor);
    ui.Percentage_of_20_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_20_Motor);
    ui.Percentage_of_21_Motor_Box->setValue(msg_init_tune2walk.Percentage_of_IK_21_Motor);
    ui.Swing_Right_Leg_Box->setValue(msg_init_tune2walk.Swing_Right_Leg);
    ui.Swing_Left_Leg_Box->setValue(msg_init_tune2walk.Swing_Left_Leg);
    ui.Swing_Right_Shoulder_Box->setValue(msg_init_tune2walk.Swing_Right_Shoulder);
    ui.Swing_Left_Shoulder_Box->setValue(msg_init_tune2walk.Swing_Left_Shoulder);
    ui.Rise_Right_Leg_Box->setValue(msg_init_tune2walk.Rise_Right_Leg);
    ui.Rise_Left_Leg_Box->setValue(msg_init_tune2walk.Rise_Left_Leg);
    ui.Start_Entire_Time_Box->setValue(msg_init_tune2walk.Start_Entire_Time);
    ui.Start_Swing_Box->setValue(msg_init_tune2walk.Start_Swing);
    ui.Start_Rise_Box->setValue(msg_init_tune2walk.Start_Rise);
    ui.End_Entire_Time_Box->setValue(msg_init_tune2walk.End_Entire_Time);
    ui.End_Swing_Box->setValue(msg_init_tune2walk.End_Swing);
    ui.End_Rise_Box->setValue(msg_init_tune2walk.End_Rise);
    ui.Test_X_Box->setValue(msg_init_tune2walk.Test_X);
    ui.Test_Side_Box->setValue(msg_init_tune2walk.Test_Side);
    ui.Test_Yaw_Box->setValue(msg_init_tune2walk.Test_Yaw);
    ui.Tuning_X_Box->setValue(msg_init_tune2walk.Tuning_X);
    ui.Tuning_Side_Box->setValue(msg_init_tune2walk.Tuning_Side);
    ui.Tuning_Yaw_Box->setValue(msg_init_tune2walk.Tuning_Yaw);

    ui.Balance_Value_0_Box->setValue(msg_init_tune2walk.Balance_Value_0);
    ui.Balance_Pitch_GP_Box->setValue(msg_init_tune2walk.Balance_Pitch_GP);
    ui.Balance_Pitch_GI_Box->setValue(msg_init_tune2walk.Balance_Pitch_GI);
    ui.Balance_Pitch_GD_Box->setValue(msg_init_tune2walk.Balance_Pitch_GD);
    ui.Balance_Pitch_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Pitch_ELIMIT);
    ui.Balance_Pitch_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Pitch_OLIMIT);
    ui.Balance_Pitch_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Pitch_Neg_Target);
    ui.Balance_Pitch_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Pitch_Pos_Target);

    ui.Balance_Value_1_Box->setValue(msg_init_tune2walk.Balance_Value_1);
    ui.Balance_Ankle_Pitch_GP_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GP);
    ui.Balance_Ankle_Pitch_GI_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GI);
    ui.Balance_Ankle_Pitch_GD_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_GD);
    ui.Balance_Ankle_Pitch_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_ELIMIT);
    ui.Balance_Ankle_Pitch_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_OLIMIT);
    ui.Balance_Ankle_Pitch_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_Neg_Target);
    ui.Balance_Ankle_Pitch_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Angle_Pitch_Pos_Target);

    ui.Balance_Value_2_Box->setValue(msg_init_tune2walk.Balance_Value_2);
    ui.Balance_Value_3_Box->setValue(msg_init_tune2walk.Balance_Value_3);
    ui.Balance_Roll_GP_Box->setValue(msg_init_tune2walk.Balance_Roll_GP);
    ui.Balance_Roll_GI_Box->setValue(msg_init_tune2walk.Balance_Roll_GI);
    ui.Balance_Roll_GD_Box->setValue(msg_init_tune2walk.Balance_Roll_GD);
    ui.Balance_Roll_ELIMIT_Box->setValue(msg_init_tune2walk.Balance_Roll_ELIMIT);
    ui.Balance_Roll_OLIMIT_Box->setValue(msg_init_tune2walk.Balance_Roll_OLIMIT);
    ui.Balance_Roll_Neg_Target_Box->setValue(msg_init_tune2walk.Balance_Roll_Neg_Target);
    ui.Balance_Roll_Pos_Target_Box->setValue(msg_init_tune2walk.Balance_Roll_Pos_Target);

    //////////////////imu_parameter////////////////////////////////
    ui.Balance_Value_0_Box_2->setValue(msg_init_tune2walk.Balance_Value_4);
    ui.Balance_Value_1_Box_2->setValue(msg_init_tune2walk.Balance_Value_5);
    ui.Balance_Pitch_GP_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GP_imu);
    ui.Balance_Pitch_GI_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GI_imu);
    ui.Balance_Pitch_GD_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_GD_imu);
    ui.Balance_Pitch_ELIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_ELIMIT_imu);
    ui.Balance_Pitch_OLIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_OLIMIT_imu);
    ui.Balance_Pitch_Neg_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_Neg_Target_imu);
    ui.Balance_Pitch_Pos_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Pitch_Pos_Target_imu);

    ui.Balance_Roll_GP_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GP_imu);
    ui.Balance_Roll_GI_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GI_imu);
    ui.Balance_Roll_GD_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_GD_imu);
    ui.Balance_Roll_ELIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_ELIMIT_imu);
    ui.Balance_Roll_OLIMIT_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_OLIMIT_imu);
    ui.Balance_Roll_Neg_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_Neg_Target_imu);
    ui.Balance_Roll_Pos_Target_IMU_Box->setValue(msg_init_tune2walk.Balance_Roll_Pos_Target_imu);
    //////////////////////////////////K_Value//////////////////////////////////////////////////
    ui.Pos_XRSpinBox->setValue(msg_init_tune2walk.First_Pos_XR);
    ui.Neg_XRSpinBox->setValue(msg_init_tune2walk.First_Neg_XR);
    ui.Pos_SideRSpinBox->setValue(msg_init_tune2walk.First_Pos_SideR);
    ui.Neg_SideRSpinBox->setValue(msg_init_tune2walk.First_Neg_SideR);
    ui.Pos_YawRSpinBox->setValue(msg_init_tune2walk.First_Pos_YawR);
    ui.Neg_YawRSpinBox->setValue(msg_init_tune2walk.First_Neg_YawR);
    ui.Pos_XLSpinBox->setValue(msg_init_tune2walk.First_Pos_XL);
    ui.Neg_XLSpinBox->setValue(msg_init_tune2walk.First_Neg_XL);
    ui.Pos_SideLSpinBox->setValue(msg_init_tune2walk.First_Pos_SideL);
    ui.Neg_SideLSpinBox->setValue(msg_init_tune2walk.First_Neg_SideL);
    ui.Pos_YawLSpinBox->setValue(msg_init_tune2walk.First_Pos_YawL);
    ui.Neg_YawLSpinBox->setValue(msg_init_tune2walk.First_Neg_YawL);
    ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Pos_SideR_SwingMinus);
    ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Neg_SideR_SwingMinus);
    ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Pos_SideL_SwingMinus);
    ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_init_tune2walk.First_Neg_SideL_SwingMinus);

    ui.First_min->setValue(msg_init_tune2walk.First_min);
    ui.First_max->setValue(msg_init_tune2walk.First_max);
    ui.Second_min->setValue(msg_init_tune2walk.Second_min);
    ui.Second_max->setValue(msg_init_tune2walk.Second_max);
    ui.Third_min->setValue(msg_init_tune2walk.Third_min);
    ui.Third_max->setValue(msg_init_tune2walk.Third_max);
    ui.Fourth_min->setValue(msg_init_tune2walk.Fourth_min);
    ui.Fourth_max->setValue(msg_init_tune2walk.Fourth_max);

    ui.Landing_Time_Control_flag->setChecked(msg_init_tune2walk.Landing_Time_Control_flag);



    cout<<"Reset::"<<endl<<endl;
    }

}

void tune_walk::MainWindow::on_Open_Button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "/home/robit/catkin_ws/src/tune_walk/work/");

    if(fileName.isEmpty() == true)
    {
        qDebug() << "Load Cancel";
    }

    else
    {
      for(int i=0;i<2;i++){
        std::ifstream is;
        is.open(fileName.toStdString().c_str());

            is >> msg_tune2walk.Entire_Time;
            is >> msg_tune2walk.Frequency;
            is >> msg_tune2walk.Ratio_Check_Flag;
            is >> msg_tune2walk.Default_X_Right;
            is >> msg_tune2walk.Default_X_Left;
            is >> msg_tune2walk.Default_Y_Right;
            is >> msg_tune2walk.Default_Y_Left;
            is >> msg_tune2walk.Default_Z_Right;
            is >> msg_tune2walk.Default_Z_Left;
            is >> msg_tune2walk.Offset_10_Motor;
            is >> msg_tune2walk.Offset_11_Motor;
            is >> msg_tune2walk.Offset_12_Motor;
            is >> msg_tune2walk.Offset_13_Motor;
            is >> msg_tune2walk.Offset_14_Motor;
            is >> msg_tune2walk.Offset_15_Motor;
            is >> msg_tune2walk.Offset_16_Motor;
            is >> msg_tune2walk.Offset_17_Motor;
            is >> msg_tune2walk.Offset_18_Motor;
            is >> msg_tune2walk.Offset_19_Motor;
            is >> msg_tune2walk.Offset_20_Motor;
            is >> msg_tune2walk.Offset_21_Motor;
            is >> msg_tune2walk.Swing_Right_Leg;
            is >> msg_tune2walk.Swing_Left_Leg;
            is >> msg_tune2walk.Swing_Right_Shoulder;
            is >> msg_tune2walk.Swing_Left_Shoulder;
            is >> msg_tune2walk.Rise_Right_Leg;
            is >> msg_tune2walk.Rise_Left_Leg;
            is >> msg_tune2walk.Start_Entire_Time;
            is >> msg_tune2walk.Start_Swing;
            is >> msg_tune2walk.Start_Rise;
            is >> msg_tune2walk.End_Entire_Time;
            is >> msg_tune2walk.End_Swing;
            is >> msg_tune2walk.End_Rise;
            is >> msg_tune2walk.Tuning_X;
            is >> msg_tune2walk.Tuning_Side;
            is >> msg_tune2walk.Tuning_Yaw;

            is >> msg_tune2walk.Balance_Value_0;
            is >> msg_tune2walk.Balance_Pitch_GP;
            is >> msg_tune2walk.Balance_Pitch_GI;
            is >> msg_tune2walk.Balance_Pitch_GD;
            is >> msg_tune2walk.Balance_Pitch_ELIMIT;
            is >> msg_tune2walk.Balance_Pitch_OLIMIT;
            is >> msg_tune2walk.Balance_Pitch_Neg_Target;
            is >> msg_tune2walk.Balance_Pitch_Pos_Target;

            is >> msg_tune2walk.Balance_Value_1;
            is >> msg_tune2walk.Balance_Angle_Pitch_GP;
            is >> msg_tune2walk.Balance_Angle_Pitch_GI;
            is >> msg_tune2walk.Balance_Angle_Pitch_GD;
            is >> msg_tune2walk.Balance_Angle_Pitch_ELIMIT;
            is >> msg_tune2walk.Balance_Angle_Pitch_OLIMIT;
            is >> msg_tune2walk.Balance_Angle_Pitch_Neg_Target;
            is >> msg_tune2walk.Balance_Angle_Pitch_Pos_Target;

            is >> msg_tune2walk.Balance_Value_2;
            is >> msg_tune2walk.Balance_Roll_GP;
            is >> msg_tune2walk.Balance_Roll_GI;
            is >> msg_tune2walk.Balance_Roll_GD;
            is >> msg_tune2walk.Balance_Roll_ELIMIT;
            is >> msg_tune2walk.Balance_Roll_OLIMIT;
            is >> msg_tune2walk.Balance_Roll_Neg_Target;
            is >> msg_tune2walk.Balance_Roll_Pos_Target;

            is >> msg_tune2walk.Balance_Value_3;


            //////////////////imu_parameter////////////////////////////////

            is >> msg_tune2walk.Balance_Value_4;
            is >> msg_tune2walk.Balance_Value_5;
            is >> msg_tune2walk.Balance_Pitch_GP_imu;
            is >> msg_tune2walk.Balance_Pitch_GI_imu;
            is >> msg_tune2walk.Balance_Pitch_GD_imu;
            is >> msg_tune2walk.Balance_Pitch_ELIMIT_imu;
            is >> msg_tune2walk.Balance_Pitch_OLIMIT_imu;
            is >> msg_tune2walk.Balance_Pitch_Neg_Target_imu;
            is >> msg_tune2walk.Balance_Pitch_Pos_Target_imu;

            is >> msg_tune2walk.Balance_Roll_GP_imu;
            is >> msg_tune2walk.Balance_Roll_GI_imu;
            is >> msg_tune2walk.Balance_Roll_GD_imu;
            is >> msg_tune2walk.Balance_Roll_ELIMIT_imu;
            is >> msg_tune2walk.Balance_Roll_OLIMIT_imu;
            is >> msg_tune2walk.Balance_Roll_Neg_Target_imu;
            is >> msg_tune2walk.Balance_Roll_Pos_Target_imu;
            ///////////////////////////////////////////////////////////////
            is >> msg_tune2walk.Center2Leg;
            is >> msg_tune2walk.Link2Link;
            is >> msg_tune2walk.Init_Z_Up;
            is >> msg_tune2walk.Percentage_of_IK_10_Motor;
            is >> msg_tune2walk.Percentage_of_IK_11_Motor;
            is >> msg_tune2walk.Percentage_of_IK_12_Motor;
            is >> msg_tune2walk.Percentage_of_IK_13_Motor;
            is >> msg_tune2walk.Percentage_of_IK_14_Motor;
            is >> msg_tune2walk.Percentage_of_IK_15_Motor;
            is >> msg_tune2walk.Percentage_of_IK_16_Motor;
            is >> msg_tune2walk.Percentage_of_IK_17_Motor;
            is >> msg_tune2walk.Percentage_of_IK_18_Motor;
            is >> msg_tune2walk.Percentage_of_IK_19_Motor;
            is >> msg_tune2walk.Percentage_of_IK_20_Motor;
            is >> msg_tune2walk.Percentage_of_IK_21_Motor;

////////////////////////////////K_Value///////////////////////////
            is >> msg_tune2walk.First_Pos_XR;
            is >> msg_tune2walk.First_Neg_XR;
            is >> msg_tune2walk.First_Pos_SideR;
            is >> msg_tune2walk.First_Neg_SideR;
            is >> msg_tune2walk.First_Pos_YawR;
            is >> msg_tune2walk.First_Neg_YawR;
            is >> msg_tune2walk.First_Pos_XL;
            is >> msg_tune2walk.First_Neg_XL;
            is >> msg_tune2walk.First_Pos_SideL;
            is >> msg_tune2walk.First_Neg_SideL;
            is >> msg_tune2walk.First_Pos_YawL;
            is >> msg_tune2walk.First_Neg_YawL;
            is >> msg_tune2walk.First_Pos_SideR_SwingMinus;
            is >> msg_tune2walk.First_Neg_SideR_SwingMinus;
            is >> msg_tune2walk.First_Pos_SideL_SwingMinus;
            is >> msg_tune2walk.First_Neg_SideL_SwingMinus;
            is >> msg_tune2walk.First_min;
            is >> msg_tune2walk.First_max;

            is >> msg_tune2walk.Second_Pos_XR;
            is >> msg_tune2walk.Second_Neg_XR;
            is >> msg_tune2walk.Second_Pos_SideR;
            is >> msg_tune2walk.Second_Neg_SideR;
            is >> msg_tune2walk.Second_Pos_YawR;
            is >> msg_tune2walk.Second_Neg_YawR;
            is >> msg_tune2walk.Second_Pos_XL;
            is >> msg_tune2walk.Second_Neg_XL;
            is >> msg_tune2walk.Second_Pos_SideL;
            is >> msg_tune2walk.Second_Neg_SideL;
            is >> msg_tune2walk.Second_Pos_YawL;
            is >> msg_tune2walk.Second_Neg_YawL;
            is >> msg_tune2walk.Second_Pos_SideR_SwingMinus;
            is >> msg_tune2walk.Second_Neg_SideR_SwingMinus;
            is >> msg_tune2walk.Second_Pos_SideL_SwingMinus;
            is >> msg_tune2walk.Second_Neg_SideL_SwingMinus;
            is >> msg_tune2walk.Second_min;
            is >> msg_tune2walk.Second_max;

            is >> msg_tune2walk.Third_Pos_XR;
            is >> msg_tune2walk.Third_Neg_XR;
            is >> msg_tune2walk.Third_Pos_SideR;
            is >> msg_tune2walk.Third_Neg_SideR;
            is >> msg_tune2walk.Third_Pos_YawR;
            is >> msg_tune2walk.Third_Neg_YawR;
            is >> msg_tune2walk.Third_Pos_XL;
            is >> msg_tune2walk.Third_Neg_XL;
            is >> msg_tune2walk.Third_Pos_SideL;
            is >> msg_tune2walk.Third_Neg_SideL;
            is >> msg_tune2walk.Third_Pos_YawL;
            is >> msg_tune2walk.Third_Neg_YawL;
            is >> msg_tune2walk.Third_Pos_SideR_SwingMinus;
            is >> msg_tune2walk.Third_Neg_SideR_SwingMinus;
            is >> msg_tune2walk.Third_Pos_SideL_SwingMinus;
            is >> msg_tune2walk.Third_Neg_SideL_SwingMinus;
            is >> msg_tune2walk.Third_min;
            is >> msg_tune2walk.Third_max;

            is >> msg_tune2walk.Fourth_Pos_XR;
            is >> msg_tune2walk.Fourth_Neg_XR;
            is >> msg_tune2walk.Fourth_Pos_SideR;
            is >> msg_tune2walk.Fourth_Neg_SideR;
            is >> msg_tune2walk.Fourth_Pos_YawR;
            is >> msg_tune2walk.Fourth_Neg_YawR;
            is >> msg_tune2walk.Fourth_Pos_XL;
            is >> msg_tune2walk.Fourth_Neg_XL;
            is >> msg_tune2walk.Fourth_Pos_SideL;
            is >> msg_tune2walk.Fourth_Neg_SideL;
            is >> msg_tune2walk.Fourth_Pos_YawL;
            is >> msg_tune2walk.Fourth_Neg_YawL;
            is >> msg_tune2walk.Fourth_Pos_SideR_SwingMinus;
            is >> msg_tune2walk.Fourth_Neg_SideR_SwingMinus;
            is >> msg_tune2walk.Fourth_Pos_SideL_SwingMinus;
            is >> msg_tune2walk.Fourth_Neg_SideL_SwingMinus;
            is >> msg_tune2walk.Fourth_min;
            is >> msg_tune2walk.Fourth_max;

            is >> msg_tune2walk.Landing_Time_Control_flag;

            is >> msg_tune2walk.Balance_Pitch_Flag_imu;
            is >> msg_tune2walk.Balance_Roll_Flag_imu;
            is >> msg_tune2walk.Balance_Pitch_Flag;
            is >> msg_tune2walk.Balance_Ankle_Pitch_Flag;
            is >> msg_tune2walk.Balance_Roll_Flag;

         is.close();

            ui.Entire_Time_Box->setValue(msg_tune2walk.Entire_Time);
            ui.Frequency_Box->setValue(msg_tune2walk.Frequency);
            ui.Center2Leg_Box->setValue(msg_tune2walk.Center2Leg);
            ui.Link2Link_Box->setValue(msg_tune2walk.Link2Link);
            ui.Init_Z_Up_Box->setValue(msg_tune2walk.Init_Z_Up);
            ui.Default_X_Right_Box->setValue(msg_tune2walk.Default_X_Right);
            ui.Default_X_Left_Box->setValue(msg_tune2walk.Default_X_Left);
            ui.Default_Y_Right_Box->setValue(msg_tune2walk.Default_Y_Right);
            ui.Default_Y_Left_Box->setValue(msg_tune2walk.Default_Y_Left);
            ui.Default_Z_Right_Box->setValue(msg_tune2walk.Default_Z_Right);
            ui.Default_Z_Left_Box->setValue(msg_tune2walk.Default_Z_Left);
            angle_update();
            past_motor_update();
            arr_reset();
            Offset_scroll_reset(0);
            ui.Percentage_of_10_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_10_Motor);
            ui.Percentage_of_11_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_11_Motor);
            ui.Percentage_of_12_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_12_Motor);
            ui.Percentage_of_13_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_13_Motor);
            ui.Percentage_of_14_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_14_Motor);
            ui.Percentage_of_15_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_15_Motor);
            ui.Percentage_of_16_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_16_Motor);
            ui.Percentage_of_17_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_17_Motor);
            ui.Percentage_of_18_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_18_Motor);
            ui.Percentage_of_19_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_19_Motor);
            ui.Percentage_of_20_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_20_Motor);
            ui.Percentage_of_21_Motor_Box->setValue(msg_tune2walk.Percentage_of_IK_21_Motor);

            ui.Swing_Right_Leg_Box->setValue(msg_tune2walk.Swing_Right_Leg);
            ui.Swing_Left_Leg_Box->setValue(msg_tune2walk.Swing_Left_Leg);
            ui.Swing_Right_Shoulder_Box->setValue(msg_tune2walk.Swing_Right_Shoulder);
            ui.Swing_Left_Shoulder_Box->setValue(msg_tune2walk.Swing_Left_Shoulder);
            ui.Rise_Right_Leg_Box->setValue(msg_tune2walk.Rise_Right_Leg);
            ui.Rise_Left_Leg_Box->setValue(msg_tune2walk.Rise_Left_Leg);
            ui.Start_Entire_Time_Box->setValue(msg_tune2walk.Start_Entire_Time);
            ui.Start_Swing_Box->setValue(msg_tune2walk.Start_Swing);
            ui.Start_Rise_Box->setValue(msg_tune2walk.Start_Rise);
            ui.End_Entire_Time_Box->setValue(msg_tune2walk.End_Entire_Time);
            ui.End_Swing_Box->setValue(msg_tune2walk.End_Swing);
            ui.End_Rise_Box->setValue(msg_tune2walk.End_Rise);
            ui.Test_X_Box->setValue(msg_init_tune2walk.Test_X);
            ui.Test_Side_Box->setValue(msg_init_tune2walk.Test_Side);
            ui.Test_Yaw_Box->setValue(msg_init_tune2walk.Test_Yaw);
            ui.Tuning_X_Box->setValue(msg_tune2walk.Tuning_X);
            ui.Tuning_Side_Box->setValue(msg_tune2walk.Tuning_Side);
            ui.Tuning_Yaw_Box->setValue(msg_tune2walk.Tuning_Yaw);

            ui.Balance_Value_0_Box->setValue(msg_tune2walk.Balance_Value_0);
            ui.Balance_Pitch_GP_Box->setValue(msg_tune2walk.Balance_Pitch_GP);
            ui.Balance_Pitch_GI_Box->setValue(msg_tune2walk.Balance_Pitch_GI);
            ui.Balance_Pitch_GD_Box->setValue(msg_tune2walk.Balance_Pitch_GD);
            ui.Balance_Pitch_ELIMIT_Box->setValue(msg_tune2walk.Balance_Pitch_ELIMIT);
            ui.Balance_Pitch_OLIMIT_Box->setValue(msg_tune2walk.Balance_Pitch_OLIMIT);
            ui.Balance_Pitch_Neg_Target_Box->setValue(msg_tune2walk.Balance_Pitch_Neg_Target);
            ui.Balance_Pitch_Pos_Target_Box->setValue(msg_tune2walk.Balance_Pitch_Pos_Target);

            ui.Balance_Value_1_Box->setValue(msg_tune2walk.Balance_Value_1);
            ui.Balance_Ankle_Pitch_GP_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_GP);
            ui.Balance_Ankle_Pitch_GI_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_GI);
            ui.Balance_Ankle_Pitch_GD_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_GD);
            ui.Balance_Ankle_Pitch_ELIMIT_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_ELIMIT);
            ui.Balance_Ankle_Pitch_OLIMIT_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_OLIMIT);
            ui.Balance_Ankle_Pitch_Neg_Target_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_Neg_Target);
            ui.Balance_Ankle_Pitch_Pos_Target_Box->setValue(msg_tune2walk.Balance_Angle_Pitch_Pos_Target);

            ui.Balance_Value_2_Box->setValue(msg_tune2walk.Balance_Value_2);

            ui.Balance_Value_3_Box->setValue(msg_tune2walk.Balance_Value_3);

            ui.Balance_Roll_GP_Box->setValue(msg_tune2walk.Balance_Roll_GP);
            ui.Balance_Roll_GI_Box->setValue(msg_tune2walk.Balance_Roll_GI);
            ui.Balance_Roll_GD_Box->setValue(msg_tune2walk.Balance_Roll_GD);
            ui.Balance_Roll_ELIMIT_Box->setValue(msg_tune2walk.Balance_Roll_ELIMIT);
            ui.Balance_Roll_OLIMIT_Box->setValue(msg_tune2walk.Balance_Roll_OLIMIT);
            ui.Balance_Roll_Neg_Target_Box->setValue(msg_tune2walk.Balance_Roll_Neg_Target);
            ui.Balance_Roll_Pos_Target_Box->setValue(msg_tune2walk.Balance_Roll_Pos_Target);

            ////////////////////////////PID_IMU_PARAMETER/////////////////////////////////////////
            ui.Balance_Value_0_Box_2->setValue(msg_tune2walk.Balance_Value_4);
            ui.Balance_Value_1_Box_2->setValue(msg_tune2walk.Balance_Value_5);
            ui.Balance_Pitch_GP_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_GP_imu);
            ui.Balance_Pitch_GI_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_GI_imu);
            ui.Balance_Pitch_GD_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_GD_imu);
            ui.Balance_Pitch_ELIMIT_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_ELIMIT_imu);
            ui.Balance_Pitch_OLIMIT_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_OLIMIT_imu);
            ui.Balance_Pitch_Neg_Target_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_Neg_Target_imu);
            ui.Balance_Pitch_Pos_Target_IMU_Box->setValue(msg_tune2walk.Balance_Pitch_Pos_Target_imu);

            ui.Balance_Roll_GP_IMU_Box->setValue(msg_tune2walk.Balance_Roll_GP_imu);
            ui.Balance_Roll_GI_IMU_Box->setValue(msg_tune2walk.Balance_Roll_GI_imu);
            ui.Balance_Roll_GD_IMU_Box->setValue(msg_tune2walk.Balance_Roll_GD_imu);
            ui.Balance_Roll_ELIMIT_IMU_Box->setValue(msg_tune2walk.Balance_Roll_ELIMIT_imu);
            ui.Balance_Roll_OLIMIT_IMU_Box->setValue(msg_tune2walk.Balance_Roll_OLIMIT_imu);
            ui.Balance_Roll_Neg_Target_IMU_Box->setValue(msg_tune2walk.Balance_Roll_Neg_Target_imu);
            ui.Balance_Roll_Pos_Target_IMU_Box->setValue(msg_tune2walk.Balance_Roll_Pos_Target_imu);
            //////////////////////////////////K_Value//////////////////////////////////////////////////
            ui.Pos_XRSpinBox->setValue(msg_tune2walk.First_Pos_XR);
            ui.Neg_XRSpinBox->setValue(msg_tune2walk.First_Neg_XR);
            ui.Pos_SideRSpinBox->setValue(msg_tune2walk.First_Pos_SideR);
            ui.Neg_SideRSpinBox->setValue(msg_tune2walk.First_Neg_SideR);
            ui.Pos_YawRSpinBox->setValue(msg_tune2walk.First_Pos_YawR);
            ui.Neg_YawRSpinBox->setValue(msg_tune2walk.First_Neg_YawR);
            ui.Pos_XLSpinBox->setValue(msg_tune2walk.First_Pos_XL);
            ui.Neg_XLSpinBox->setValue(msg_tune2walk.First_Neg_XL);
            ui.Pos_SideLSpinBox->setValue(msg_tune2walk.First_Pos_SideL);
            ui.Neg_SideLSpinBox->setValue(msg_tune2walk.First_Neg_SideL);
            ui.Pos_YawLSpinBox->setValue(msg_tune2walk.First_Pos_YawL);
            ui.Neg_YawLSpinBox->setValue(msg_tune2walk.First_Neg_YawL);
            ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.First_Pos_SideR_SwingMinus);
            ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.First_Neg_SideR_SwingMinus);
            ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.First_Pos_SideL_SwingMinus);
            ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.First_Neg_SideL_SwingMinus);

            ui.First_min->setValue(msg_tune2walk.First_min);
            ui.First_max->setValue(msg_tune2walk.First_max);
            ui.Second_min->setValue(msg_tune2walk.Second_min);
            ui.Second_max->setValue(msg_tune2walk.Second_max);
            ui.Third_min->setValue(msg_tune2walk.Third_min);
            ui.Third_max->setValue(msg_tune2walk.Third_max);
            ui.Fourth_min->setValue(msg_tune2walk.Fourth_min);
            ui.Fourth_max->setValue(msg_tune2walk.Fourth_max);

            msg_tune2walk.Control_System_flag = 1;
            ui.checkBox_Control_System->setChecked(1);
            }

      if(msg_tune2walk.Ratio_Check_Flag  == 1)
      {
          ui.Ratio_Check_Box->setChecked(1);
          cout<<"Double"<<endl;
      }
      else if(msg_tune2walk.Ratio_Check_Flag == 0)
      {
          ui.Ratio_Check_Box->setChecked(0);
          cout<<"Single"<<endl;
      }

      if(msg_tune2walk.Landing_Time_Control_flag  == 1)
      {
          ui.Landing_Time_Control_flag->setChecked(1);
          cout<<"LTC_ON"<<endl;
      }
      else if(msg_tune2walk.Landing_Time_Control_flag == 0)
      {
          ui.Landing_Time_Control_flag->setChecked(0);
          cout<<"LTC_OFF"<<endl;
      }

      if(msg_tune2walk.Balance_Pitch_Flag_imu == 1)
      {
          ui.checkBox_Pitch_IMU->setChecked(1);
          cout<<"IMU_Pitch_PID_ON"<<endl;
      }
      else if(msg_tune2walk.Balance_Pitch_Flag_imu == 0)
      {
          ui.checkBox_Pitch_IMU->setChecked(0);
          cout<<"IMU_Pitch_PID_OFF"<<endl;
      }

      if(msg_tune2walk.Balance_Roll_Flag_imu == 1)
      {
          ui.checkBox_Roll_IMU->setChecked(1);
          cout<<"IMU_Roll_PID_ON"<<endl;
      }
      else if(msg_tune2walk.Balance_Roll_Flag_imu == 0)
      {
          ui.checkBox_Roll_IMU->setChecked(0);
          cout<<"IMU_Roll_PID_OFF"<<endl;
      }

      if(msg_tune2walk.Balance_Pitch_Flag == 1)
      {
          ui.checkBox_Pitch_ZMP->setChecked(1);
          cout<<"ZMP_Pitch_PID_ON"<<endl;
      }
      else if(msg_tune2walk.Balance_Pitch_Flag == 0)
      {
          ui.checkBox_Pitch_ZMP->setChecked(0);
          cout<<"ZMP_Pitch_PID_OFF"<<endl;
      }

      if(msg_tune2walk.Balance_Ankle_Pitch_Flag == 1)
      {
          ui.checkBox_Ankle_Pitch_ZMP->setChecked(1);
          cout<<"ZMP_Ankle_PID_ON"<<endl;
      }
      else if(msg_tune2walk.Balance_Ankle_Pitch_Flag == 0)
      {
          ui.checkBox_Ankle_Pitch_ZMP->setChecked(0);
          cout<<"ZMP_Ankle_PID_OFF"<<endl;
      }

      if(msg_tune2walk.Balance_Roll_Flag == 1)
      {
          ui.checkBox_Ankle_Roll_ZMP->setChecked(1);
          cout<<"ZMP_Roll_PID_ON"<<endl;
      }
      else if(msg_tune2walk.Balance_Roll_Flag == 0)
      {
          ui.checkBox_Ankle_Roll_ZMP->setChecked(0);
          cout<<"ZMP_Roll_PID_OFF"<<endl;
      }
    }
}
void tune_walk::MainWindow::on_Save_Button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), "/home/robit/catkin_ws/src/tune_walk/work/");

    if(fileName.isEmpty() == true)
        qDebug() << "Save Cancel";

    else
    {
        QFile *file = new QFile;
        file->setFileName(fileName);
        file->open(QIODevice::WriteOnly);
        QTextStream out(file);

        out
        << msg_tune2walk.Entire_Time <<endl
        <<msg_tune2walk.Frequency<<endl
        <<msg_tune2walk.Ratio_Check_Flag<<endl
        <<msg_tune2walk.Default_X_Right<<endl
        <<msg_tune2walk.Default_X_Left<<endl
        <<msg_tune2walk.Default_Y_Right<<endl
        <<msg_tune2walk.Default_Y_Left<<endl
        <<msg_tune2walk.Default_Z_Right<<endl
        <<msg_tune2walk.Default_Z_Left<<endl
        <<msg_tune2walk.Offset_10_Motor<<endl
        <<msg_tune2walk.Offset_11_Motor<<endl
        <<msg_tune2walk.Offset_12_Motor<<endl
        <<msg_tune2walk.Offset_13_Motor<<endl
        <<msg_tune2walk.Offset_14_Motor<<endl
        <<msg_tune2walk.Offset_15_Motor<<endl
        <<msg_tune2walk.Offset_16_Motor<<endl
        <<msg_tune2walk.Offset_17_Motor<<endl
        <<msg_tune2walk.Offset_18_Motor<<endl
        <<msg_tune2walk.Offset_19_Motor<<endl
        <<msg_tune2walk.Offset_20_Motor<<endl
        <<msg_tune2walk.Offset_21_Motor<<endl
        <<msg_tune2walk.Swing_Right_Leg<<endl
        <<msg_tune2walk.Swing_Left_Leg<<endl
        <<msg_tune2walk.Swing_Right_Shoulder<<endl
        <<msg_tune2walk.Swing_Left_Shoulder<<endl
        <<msg_tune2walk.Rise_Right_Leg<<endl
        <<msg_tune2walk.Rise_Left_Leg<<endl
        <<msg_tune2walk.Start_Entire_Time<<endl
        <<msg_tune2walk.Start_Swing<<endl
        <<msg_tune2walk.Start_Rise<<endl
        <<msg_tune2walk.End_Entire_Time<<endl
        <<msg_tune2walk.End_Swing<<endl
        <<msg_tune2walk.End_Rise<<endl
        <<msg_tune2walk.Tuning_X<<endl
        <<msg_tune2walk.Tuning_Side<<endl
        <<msg_tune2walk.Tuning_Yaw<<endl

        <<msg_tune2walk.Balance_Value_0<<endl
        <<msg_tune2walk.Balance_Pitch_GP<<endl
        <<msg_tune2walk.Balance_Pitch_GI<<endl
        <<msg_tune2walk.Balance_Pitch_GD<<endl
        <<msg_tune2walk.Balance_Pitch_ELIMIT<<endl
        <<msg_tune2walk.Balance_Pitch_OLIMIT<<endl
        <<msg_tune2walk.Balance_Pitch_Neg_Target<<endl
        <<msg_tune2walk.Balance_Pitch_Pos_Target<<endl

        <<msg_tune2walk.Balance_Value_1<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_GP<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_GI<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_GD<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_ELIMIT<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_OLIMIT<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_Neg_Target<<endl
        <<msg_tune2walk.Balance_Angle_Pitch_Pos_Target<<endl

        <<msg_tune2walk.Balance_Value_2<<endl
        <<msg_tune2walk.Balance_Roll_GP<<endl
        <<msg_tune2walk.Balance_Roll_GI<<endl
        <<msg_tune2walk.Balance_Roll_GD<<endl
        <<msg_tune2walk.Balance_Roll_ELIMIT<<endl
        <<msg_tune2walk.Balance_Roll_OLIMIT<<endl
        <<msg_tune2walk.Balance_Roll_Neg_Target<<endl
        <<msg_tune2walk.Balance_Roll_Pos_Target<<endl

        <<msg_tune2walk.Balance_Value_3<<endl


          ////////////////PID_IMU_PARAMETER/////////////////////
        <<msg_tune2walk.Balance_Value_4<<endl
        <<msg_tune2walk.Balance_Value_5<<endl
        <<msg_tune2walk.Balance_Pitch_GP_imu<<endl
        <<msg_tune2walk.Balance_Pitch_GI_imu<<endl
        <<msg_tune2walk.Balance_Pitch_GD_imu<<endl
        <<msg_tune2walk.Balance_Pitch_ELIMIT_imu<<endl
        <<msg_tune2walk.Balance_Pitch_OLIMIT_imu<<endl
        <<msg_tune2walk.Balance_Pitch_Neg_Target_imu<<endl
        <<msg_tune2walk.Balance_Pitch_Pos_Target_imu<<endl

        <<msg_tune2walk.Balance_Roll_GP_imu<<endl
        <<msg_tune2walk.Balance_Roll_GI_imu<<endl
        <<msg_tune2walk.Balance_Roll_GD_imu<<endl
        <<msg_tune2walk.Balance_Roll_ELIMIT_imu<<endl
        <<msg_tune2walk.Balance_Roll_OLIMIT_imu<<endl
        <<msg_tune2walk.Balance_Roll_Neg_Target_imu<<endl
        <<msg_tune2walk.Balance_Roll_Pos_Target_imu<<endl
        <<msg_tune2walk.Center2Leg<<endl
        <<msg_tune2walk.Link2Link<<endl
        <<msg_tune2walk.Init_Z_Up<<endl
          ///////////////////////////////////////////////////////
        <<msg_tune2walk.Percentage_of_IK_10_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_11_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_12_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_13_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_14_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_15_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_16_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_17_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_18_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_19_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_20_Motor<<endl
        <<msg_tune2walk.Percentage_of_IK_21_Motor<<endl

          /////////////////////K_Value///////////////////////////////
        <<msg_tune2walk.First_Pos_XR<<endl
        <<msg_tune2walk.First_Neg_XR<<endl
        <<msg_tune2walk.First_Pos_SideR<<endl
        <<msg_tune2walk.First_Neg_SideR<<endl
        <<msg_tune2walk.First_Pos_YawR<<endl
        <<msg_tune2walk.First_Neg_YawR<<endl
        <<msg_tune2walk.First_Pos_XL<<endl
        <<msg_tune2walk.First_Neg_XL<<endl
        <<msg_tune2walk.First_Pos_SideL<<endl
        <<msg_tune2walk.First_Neg_SideL<<endl
        <<msg_tune2walk.First_Pos_YawL<<endl
        <<msg_tune2walk.First_Neg_YawL<<endl
        <<msg_tune2walk.First_Pos_SideR_SwingMinus<<endl
        <<msg_tune2walk.First_Neg_SideR_SwingMinus<<endl
        <<msg_tune2walk.First_Pos_SideL_SwingMinus<<endl
        <<msg_tune2walk.First_Neg_SideL_SwingMinus<<endl
        <<msg_tune2walk.First_min<<endl
        <<msg_tune2walk.First_max<<endl

        <<msg_tune2walk.Second_Pos_XR<<endl
        <<msg_tune2walk.Second_Neg_XR<<endl
        <<msg_tune2walk.Second_Pos_SideR<<endl
        <<msg_tune2walk.Second_Neg_SideR<<endl
        <<msg_tune2walk.Second_Pos_YawR<<endl
        <<msg_tune2walk.Second_Neg_YawR<<endl
        <<msg_tune2walk.Second_Pos_XL<<endl
        <<msg_tune2walk.Second_Neg_XL<<endl
        <<msg_tune2walk.Second_Pos_SideL<<endl
        <<msg_tune2walk.Second_Neg_SideL<<endl
        <<msg_tune2walk.Second_Pos_YawL<<endl
        <<msg_tune2walk.Second_Neg_YawL<<endl
        <<msg_tune2walk.Second_Pos_SideR_SwingMinus<<endl
        <<msg_tune2walk.Second_Neg_SideR_SwingMinus<<endl
        <<msg_tune2walk.Second_Pos_SideL_SwingMinus<<endl
        <<msg_tune2walk.Second_Neg_SideL_SwingMinus<<endl
        <<msg_tune2walk.Second_min<<endl
        <<msg_tune2walk.Second_max<<endl

        <<msg_tune2walk.Third_Pos_XR<<endl
        <<msg_tune2walk.Third_Neg_XR<<endl
        <<msg_tune2walk.Third_Pos_SideR<<endl
        <<msg_tune2walk.Third_Neg_SideR<<endl
        <<msg_tune2walk.Third_Pos_YawR<<endl
        <<msg_tune2walk.Third_Neg_YawR<<endl
        <<msg_tune2walk.Third_Pos_XL<<endl
        <<msg_tune2walk.Third_Neg_XL<<endl
        <<msg_tune2walk.Third_Pos_SideL<<endl
        <<msg_tune2walk.Third_Neg_SideL<<endl
        <<msg_tune2walk.Third_Pos_YawL<<endl
        <<msg_tune2walk.Third_Neg_YawL<<endl
        <<msg_tune2walk.Third_Pos_SideR_SwingMinus<<endl
        <<msg_tune2walk.Third_Neg_SideR_SwingMinus<<endl
        <<msg_tune2walk.Third_Pos_SideL_SwingMinus<<endl
        <<msg_tune2walk.Third_Neg_SideL_SwingMinus<<endl
        <<msg_tune2walk.Third_min<<endl
        <<msg_tune2walk.Third_max<<endl

        <<msg_tune2walk.Fourth_Pos_XR<<endl
        <<msg_tune2walk.Fourth_Neg_XR<<endl
        <<msg_tune2walk.Fourth_Pos_SideR<<endl
        <<msg_tune2walk.Fourth_Neg_SideR<<endl
        <<msg_tune2walk.Fourth_Pos_YawR<<endl
        <<msg_tune2walk.Fourth_Neg_YawR<<endl
        <<msg_tune2walk.Fourth_Pos_XL<<endl
        <<msg_tune2walk.Fourth_Neg_XL<<endl
        <<msg_tune2walk.Fourth_Pos_SideL<<endl
        <<msg_tune2walk.Fourth_Neg_SideL<<endl
        <<msg_tune2walk.Fourth_Pos_YawL<<endl
        <<msg_tune2walk.Fourth_Neg_YawL<<endl
        <<msg_tune2walk.Fourth_Pos_SideR_SwingMinus<<endl
        <<msg_tune2walk.Fourth_Neg_SideR_SwingMinus<<endl
        <<msg_tune2walk.Fourth_Pos_SideL_SwingMinus<<endl
        <<msg_tune2walk.Fourth_Neg_SideL_SwingMinus<<endl
        <<msg_tune2walk.Fourth_min<<endl
        <<msg_tune2walk.Fourth_max<<endl

        <<msg_tune2walk.Landing_Time_Control_flag<<endl

        <<msg_tune2walk.Balance_Pitch_Flag_imu<<endl
        <<msg_tune2walk.Balance_Roll_Flag_imu<<endl
        <<msg_tune2walk.Balance_Pitch_Flag<<endl
        <<msg_tune2walk.Balance_Ankle_Pitch_Flag<<endl
        <<msg_tune2walk.Balance_Roll_Flag<<endl
        <<",";
        file->close();

    }
    arr_reset();
    Offset_scroll_reset(0);
}





//////////////////////IMU_PID_ADDON/////////////////////////////

void tune_walk::MainWindow::on_checkBox_Pitch_IMU_clicked()
{
    if(msg_tune2walk.Balance_Pitch_Flag_imu==0)
    {
        msg_tune2walk.Balance_Pitch_Flag_imu=1;
        cout<<"imu_pid_pitch_running"<<endl;
    }
    else
    {
        msg_tune2walk.Balance_Pitch_Flag_imu=0;
         cout<<"imu_pid_pitch_OFF"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_0_Plus_Button_2_clicked()
{
    msg_tune2walk.Balance_Value_4 +=1;
    if(msg_tune2walk.Balance_Value_4>=100)msg_tune2walk.Balance_Value_4=100;
    ui.Balance_Value_0_Box_2 -> setValue(msg_tune2walk.Balance_Value_4);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Balance_Value_0_Minus_Button_2_clicked()
{
    msg_tune2walk.Balance_Value_4 -=1;
    if(msg_tune2walk.Balance_Value_4<=-100)msg_tune2walk.Balance_Value_4=-100;
    ui.Balance_Value_0_Box_2 -> setValue(msg_tune2walk.Balance_Value_4);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_GP_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GP_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_GI_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GI_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_GD_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_GD_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_ELIMIT_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_ELIMIT_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_OLIMIT_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_OLIMIT_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_Neg_Target_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_Neg_Target_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Pitch_Pos_Target_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Pitch_Pos_Target_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_checkBox_Roll_IMU_clicked()
{
    if(msg_tune2walk.Balance_Roll_Flag_imu == 0)
    {
        msg_tune2walk.Balance_Roll_Flag_imu = 1;
        cout<<"imu_pid_roll_running"<<endl;
    }
    else
    {
        msg_tune2walk.Balance_Roll_Flag_imu = 0;
         cout<<"imu_pid_roll_OFF"<<endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Value_1_Plus_Button_2_clicked()
{
    msg_tune2walk.Balance_Value_5 +=1;
    if(msg_tune2walk.Balance_Value_5>=100)msg_tune2walk.Balance_Value_5=100;
    ui.Balance_Value_1_Box_2 -> setValue(msg_tune2walk.Balance_Value_5);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Balance_Value_1_Minus_Button_2_clicked()
{
    msg_tune2walk.Balance_Value_5 -=1;
    if(msg_tune2walk.Balance_Value_5<=-100)msg_tune2walk.Balance_Value_5=-100;
    ui.Balance_Value_1_Box_2 -> setValue(msg_tune2walk.Balance_Value_5);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Balance_Roll_GP_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GP_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_GI_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GI_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_GD_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_GD_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_ELIMIT_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_ELIMIT_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_OLIMIT_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_OLIMIT_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_Neg_Target_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_Neg_Target_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

void tune_walk::MainWindow::on_Balance_Roll_Pos_Target_IMU_Box_valueChanged(double arg1)
{
    if(arg1 < 0.1 && arg1 > -0.1) arg1 = 0.0;
    msg_tune2walk.Balance_Roll_Pos_Target_imu= arg1;
    tune2walk_Pub.publish(msg_tune2walk);

}

//////////////////////K_Value///////////////////////////
void tune_walk::MainWindow::on_Pos_XRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_XR= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_XR= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_XR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_XR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_XRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_XR= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_XR= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_XR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_XR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_SideR= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_SideR= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_SideR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_SideR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_SideR= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_SideR= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_SideR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_SideR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_YawR= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_YawR= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_YawR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_YawR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawRSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_YawR= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_YawR= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_YawR= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_YawR= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_XLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_XL= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_XL= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_XL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_XL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_XLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_XL= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_XL= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_XL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_XL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_SideL= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_SideL= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_SideL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_SideL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_SideL= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_SideL= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_SideL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_SideL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_YawL= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_YawL= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_YawL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Pos_YawL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawLSpinBox_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_YawL= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_YawL= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_YawL= arg1;
  else if(index == 3) msg_tune2walk.Fourth_Neg_YawL= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_XR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_XR +=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.First_Pos_XR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_XR +=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Second_Pos_XR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_XR +=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Third_Pos_XR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_XR +=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_XR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Neg_XR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_XR +=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.First_Neg_XR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_XR +=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Second_Neg_XR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_XR +=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Third_Neg_XR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_XR +=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_XR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideR +=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.First_Pos_SideR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideR +=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Second_Pos_SideR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideR +=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Third_Pos_SideR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideR +=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_SideR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideR +=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.First_Neg_SideR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideR +=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Second_Neg_SideR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideR +=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Third_Neg_SideR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideR +=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_SideR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_YawR +=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.First_Pos_YawR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_YawR +=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Second_Pos_YawR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_YawR +=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Third_Pos_YawR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_YawR +=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_YawR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawR_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_YawR +=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.First_Neg_YawR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_YawR +=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Second_Neg_YawR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_YawR +=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Third_Neg_YawR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_YawR +=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_YawR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_XL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_XL +=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.First_Pos_XL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_XL +=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Second_Pos_XL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_XL +=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Third_Pos_XL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_XL +=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_XL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Neg_XL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_XL +=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.First_Neg_XL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_XL +=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Second_Neg_XL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_XL +=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Third_Neg_XL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_XL +=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_XL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideL +=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.First_Pos_SideL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideL +=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Second_Pos_SideL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideL +=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Third_Pos_SideL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideL +=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_SideL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideL +=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.First_Neg_SideL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideL +=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Second_Neg_SideL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideL +=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Third_Neg_SideL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideL +=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_SideL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_YawL +=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.First_Pos_YawL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_YawL +=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Second_Pos_YawL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_YawL +=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Third_Pos_YawL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_YawL +=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_YawL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawL_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_YawL +=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.First_Neg_YawL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_YawL +=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Second_Neg_YawL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_YawL +=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Third_Neg_YawL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_YawL +=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_YawL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}



void tune_walk::MainWindow::on_Pos_XR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_XR -=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.First_Pos_XR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_XR -=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Second_Pos_XR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_XR -=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Third_Pos_XR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_XR -=0.01;
    ui.Pos_XRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_XR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Neg_XR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_XR -=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.First_Neg_XR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_XR -=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Second_Neg_XR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_XR -=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Third_Neg_XR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_XR -=0.01;
    ui.Neg_XRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_XR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideR -=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.First_Pos_SideR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideR -=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Second_Pos_SideR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideR -=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Third_Pos_SideR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideR -=0.01;
    ui.Pos_SideRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_SideR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideR -=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.First_Neg_SideR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideR -=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Second_Neg_SideR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideR -=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Third_Neg_SideR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideR -=0.01;
    ui.Neg_SideRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_SideR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_YawR -=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.First_Pos_YawR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_YawR -=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Second_Pos_YawR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_YawR -=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Third_Pos_YawR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_YawR -=0.01;
    ui.Pos_YawRSpinBox -> setValue(msg_tune2walk.Fourth_Pos_YawR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawR_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_YawR -=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.First_Neg_YawR);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_YawR -=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Second_Neg_YawR);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_YawR -=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Third_Neg_YawR);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_YawR -=0.01;
    ui.Neg_YawRSpinBox -> setValue(msg_tune2walk.Fourth_Neg_YawR);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_XL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_XL -=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.First_Pos_XL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_XL -=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Second_Pos_XL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_XL -=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Third_Pos_XL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_XL -=0.01;
    ui.Pos_XLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_XL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Neg_XL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_XL -=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.First_Neg_XL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_XL -=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Second_Neg_XL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_XL -=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Third_Neg_XL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_XL -=0.01;
    ui.Neg_XLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_XL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideL -=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.First_Pos_SideL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideL -=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Second_Pos_SideL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideL -=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Third_Pos_SideL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideL -=0.01;
    ui.Pos_SideLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_SideL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideL -=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.First_Neg_SideL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideL -=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Second_Neg_SideL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideL -=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Third_Neg_SideL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideL -=0.01;
    ui.Neg_SideLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_SideL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_YawL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_YawL -=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.First_Pos_YawL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_YawL -=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Second_Pos_YawL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_YawL -=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Third_Pos_YawL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_YawL -=0.01;
    ui.Pos_YawLSpinBox -> setValue(msg_tune2walk.Fourth_Pos_YawL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_YawL_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_YawL -=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.First_Neg_YawL);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_YawL -=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Second_Neg_YawL);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_YawL -=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Third_Neg_YawL);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_YawL -=0.01;
    ui.Neg_YawLSpinBox -> setValue(msg_tune2walk.Fourth_Neg_YawL);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideRSpinBox_SwingMinus_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_SideR_SwingMinus= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_SideR_SwingMinus= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_SideR_SwingMinus= arg1;
  else if(index == 3)msg_tune2walk.Fourth_Pos_SideR_SwingMinus= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideRSpinBox_SwingMinus_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_SideR_SwingMinus= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_SideR_SwingMinus= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_SideR_SwingMinus= arg1;
  else if(index == 3)msg_tune2walk.Fourth_Neg_SideR_SwingMinus= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideLSpinBox_SwingMinus_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Pos_SideL_SwingMinus= arg1;
  else if(index == 1) msg_tune2walk.Second_Pos_SideL_SwingMinus= arg1;
  else if(index == 2) msg_tune2walk.Third_Pos_SideL_SwingMinus= arg1;
  else if(index == 3)msg_tune2walk.Fourth_Pos_SideL_SwingMinus= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideLSpinBox_SwingMinus_valueChanged(double arg1){
  if(index == 0) msg_tune2walk.First_Neg_SideL_SwingMinus= arg1;
  else if(index == 1) msg_tune2walk.Second_Neg_SideL_SwingMinus= arg1;
  else if(index == 2) msg_tune2walk.Third_Neg_SideL_SwingMinus= arg1;
  else if(index == 3)msg_tune2walk.Fourth_Neg_SideL_SwingMinus= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideR_SwingMinus_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideR_SwingMinus +=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Pos_SideR_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideR_SwingMinus +=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Pos_SideR_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideR_SwingMinus +=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Pos_SideR_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideR_SwingMinus +=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Pos_SideR_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideR_SwingMinus_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideR_SwingMinus +=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Neg_SideR_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideR_SwingMinus +=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Neg_SideR_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideR_SwingMinus +=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Neg_SideR_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideR_SwingMinus +=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Neg_SideR_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideL_SwingMinus_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideL_SwingMinus +=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Pos_SideL_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideL_SwingMinus +=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Pos_SideL_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideL_SwingMinus +=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Pos_SideL_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideL_SwingMinus +=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Pos_SideL_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideL_SwingMinus_Plus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideL_SwingMinus +=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Neg_SideL_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideL_SwingMinus +=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Neg_SideL_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideL_SwingMinus +=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Neg_SideL_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideL_SwingMinus +=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Neg_SideL_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideR_SwingMinus_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideR_SwingMinus -=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Pos_SideR_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideR_SwingMinus -=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Pos_SideR_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideR_SwingMinus -=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Pos_SideR_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideR_SwingMinus -=0.1;
    ui.Pos_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Pos_SideR_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideR_SwingMinus_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideR_SwingMinus -=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Neg_SideR_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideR_SwingMinus -=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Neg_SideR_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideR_SwingMinus -=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Neg_SideR_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideR_SwingMinus -=0.1;
    ui.Neg_SideRSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Neg_SideR_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Pos_SideL_SwingMinus_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Pos_SideL_SwingMinus -=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Pos_SideL_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Pos_SideL_SwingMinus -=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Pos_SideL_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Pos_SideL_SwingMinus -=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Pos_SideL_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Pos_SideL_SwingMinus -=0.1;
    ui.Pos_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Pos_SideL_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Neg_SideL_SwingMinus_Minus_clicked(){
  if(index == 0) {
    msg_tune2walk.First_Neg_SideL_SwingMinus -=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.First_Neg_SideL_SwingMinus);
  }
  else if(index == 1) {
    msg_tune2walk.Second_Neg_SideL_SwingMinus -=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Second_Neg_SideL_SwingMinus);
  }
  else if(index == 2) {
    msg_tune2walk.Third_Neg_SideL_SwingMinus -=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Third_Neg_SideL_SwingMinus);
  }
  else if(index == 3){
    msg_tune2walk.Fourth_Neg_SideL_SwingMinus -=0.1;
    ui.Neg_SideLSpinBox_SwingMinus -> setValue(msg_tune2walk.Fourth_Neg_SideL_SwingMinus);
  }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_First_min_valueChanged(int arg1){
    msg_tune2walk.First_min= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_First_max_valueChanged(int arg1){
    msg_tune2walk.First_max= arg1;
    ui.Second_min->setValue(msg_tune2walk.First_max);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Second_min_valueChanged(int arg1){
    msg_tune2walk.Second_min= arg1;
    ui.First_max->setValue(msg_tune2walk.Second_min);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Second_max_valueChanged(int arg1){
    msg_tune2walk.Second_max= arg1;
    ui.Third_min->setValue(msg_tune2walk.Second_max);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Third_min_valueChanged(int arg1){
    msg_tune2walk.Third_min= arg1;
    ui.Second_max->setValue(msg_tune2walk.Third_min);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Third_max_valueChanged(int arg1){
    msg_tune2walk.Third_max= arg1;
    ui.Fourth_min->setValue(msg_tune2walk.Third_max);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Fourth_min_valueChanged(int arg1){
    msg_tune2walk.Fourth_min= arg1;
    ui.Third_max->setValue(msg_tune2walk.Fourth_min);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Fourth_max_valueChanged(int arg1){
    msg_tune2walk.Fourth_max= arg1;
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_First_load_clicked(){
  index = 0;
  ui.Pos_XRSpinBox->setValue(msg_tune2walk.First_Pos_XR);
  ui.Neg_XRSpinBox->setValue(msg_tune2walk.First_Neg_XR);
  ui.Pos_SideRSpinBox->setValue(msg_tune2walk.First_Pos_SideR);
  ui.Neg_SideRSpinBox->setValue(msg_tune2walk.First_Neg_SideR);
  ui.Pos_YawRSpinBox->setValue(msg_tune2walk.First_Pos_YawR);
  ui.Neg_YawRSpinBox->setValue(msg_tune2walk.First_Neg_YawR);
  ui.Pos_XLSpinBox->setValue(msg_tune2walk.First_Pos_XL);
  ui.Neg_XLSpinBox->setValue(msg_tune2walk.First_Neg_XL);
  ui.Pos_SideLSpinBox->setValue(msg_tune2walk.First_Pos_SideL);
  ui.Neg_SideLSpinBox->setValue(msg_tune2walk.First_Neg_SideL);
  ui.Pos_YawLSpinBox->setValue(msg_tune2walk.First_Pos_YawL);
  ui.Neg_YawLSpinBox->setValue(msg_tune2walk.First_Neg_YawL);
  ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.First_Pos_SideR_SwingMinus);
  ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.First_Neg_SideR_SwingMinus);
  ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.First_Pos_SideL_SwingMinus);
  ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.First_Neg_SideL_SwingMinus);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Second_load_clicked(){
  index = 1;
  ui.Pos_XRSpinBox->setValue(msg_tune2walk.Second_Pos_XR);
  ui.Neg_XRSpinBox->setValue(msg_tune2walk.Second_Neg_XR);
  ui.Pos_SideRSpinBox->setValue(msg_tune2walk.Second_Pos_SideR);
  ui.Neg_SideRSpinBox->setValue(msg_tune2walk.Second_Neg_SideR);
  ui.Pos_YawRSpinBox->setValue(msg_tune2walk.Second_Pos_YawR);
  ui.Neg_YawRSpinBox->setValue(msg_tune2walk.Second_Neg_YawR);
  ui.Pos_XLSpinBox->setValue(msg_tune2walk.Second_Pos_XL);
  ui.Neg_XLSpinBox->setValue(msg_tune2walk.Second_Neg_XL);
  ui.Pos_SideLSpinBox->setValue(msg_tune2walk.Second_Pos_SideL);
  ui.Neg_SideLSpinBox->setValue(msg_tune2walk.Second_Neg_SideL);
  ui.Pos_YawLSpinBox->setValue(msg_tune2walk.Second_Pos_YawL);
  ui.Neg_YawLSpinBox->setValue(msg_tune2walk.Second_Neg_YawL);
  ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Second_Pos_SideR_SwingMinus);
  ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Second_Neg_SideR_SwingMinus);
  ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Second_Pos_SideL_SwingMinus);
  ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Second_Neg_SideL_SwingMinus);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Third_load_clicked(){
  index = 2;
  ui.Pos_XRSpinBox->setValue(msg_tune2walk.Third_Pos_XR);
  ui.Neg_XRSpinBox->setValue(msg_tune2walk.Third_Neg_XR);
  ui.Pos_SideRSpinBox->setValue(msg_tune2walk.Third_Pos_SideR);
  ui.Neg_SideRSpinBox->setValue(msg_tune2walk.Third_Neg_SideR);
  ui.Pos_YawRSpinBox->setValue(msg_tune2walk.Third_Pos_YawR);
  ui.Neg_YawRSpinBox->setValue(msg_tune2walk.Third_Neg_YawR);
  ui.Pos_XLSpinBox->setValue(msg_tune2walk.Third_Pos_XL);
  ui.Neg_XLSpinBox->setValue(msg_tune2walk.Third_Neg_XL);
  ui.Pos_SideLSpinBox->setValue(msg_tune2walk.Third_Pos_SideL);
  ui.Neg_SideLSpinBox->setValue(msg_tune2walk.Third_Neg_SideL);
  ui.Pos_YawLSpinBox->setValue(msg_tune2walk.Third_Pos_YawL);
  ui.Neg_YawLSpinBox->setValue(msg_tune2walk.Third_Neg_YawL);
  ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Third_Pos_SideR_SwingMinus);
  ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Third_Neg_SideR_SwingMinus);
  ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Third_Pos_SideL_SwingMinus);
  ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Third_Neg_SideL_SwingMinus);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Fourth_load_clicked(){
  index = 3;
  ui.Pos_XRSpinBox->setValue(msg_tune2walk.Fourth_Pos_XR);
  ui.Neg_XRSpinBox->setValue(msg_tune2walk.Fourth_Neg_XR);
  ui.Pos_SideRSpinBox->setValue(msg_tune2walk.Fourth_Pos_SideR);
  ui.Neg_SideRSpinBox->setValue(msg_tune2walk.Fourth_Neg_SideR);
  ui.Pos_YawRSpinBox->setValue(msg_tune2walk.Fourth_Pos_YawR);
  ui.Neg_YawRSpinBox->setValue(msg_tune2walk.Fourth_Neg_YawR);
  ui.Pos_XLSpinBox->setValue(msg_tune2walk.Fourth_Pos_XL);
  ui.Neg_XLSpinBox->setValue(msg_tune2walk.Fourth_Neg_XL);
  ui.Pos_SideLSpinBox->setValue(msg_tune2walk.Fourth_Pos_SideL);
  ui.Neg_SideLSpinBox->setValue(msg_tune2walk.Fourth_Neg_SideL);
  ui.Pos_YawLSpinBox->setValue(msg_tune2walk.Fourth_Pos_YawL);
  ui.Neg_YawLSpinBox->setValue(msg_tune2walk.Fourth_Neg_YawL);
  ui.Pos_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Fourth_Pos_SideR_SwingMinus);
  ui.Neg_SideRSpinBox_SwingMinus->setValue(msg_tune2walk.Fourth_Neg_SideR_SwingMinus);
  ui.Pos_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Fourth_Pos_SideL_SwingMinus);
  ui.Neg_SideLSpinBox_SwingMinus->setValue(msg_tune2walk.Fourth_Neg_SideL_SwingMinus);
    tune2walk_Pub.publish(msg_tune2walk);
}






//////////////////////Set (0 or Data)///////////////////////////
void tune_walk::MainWindow::on_Set_Zero_Button_clicked(){
    msg_tune2walk.Swing_Right_Leg = 0;
    msg_tune2walk.Swing_Left_Leg = 0;
    msg_tune2walk.Swing_Right_Shoulder = 0;
    msg_tune2walk.Swing_Left_Shoulder = 0;
    msg_tune2walk.Rise_Right_Leg = 0;
    msg_tune2walk.Rise_Left_Leg = 0;
    msg_tune2walk.Start_Rise = 0;
    msg_tune2walk.Start_Swing = 0;
    msg_tune2walk.End_Rise = 0;
    msg_tune2walk.End_Swing = 0;
    msg_tune2walk.Test_X = 0;
    msg_tune2walk.Test_Side = 0;
    msg_tune2walk.Test_Yaw = 0;
    msg_tune2walk.Tuning_X = 0;
    msg_tune2walk.Tuning_Side = 0;
    msg_tune2walk.Tuning_Yaw = 0;

    ui.Swing_Right_Leg_Box->setValue(0);
    ui.Swing_Left_Leg_Box->setValue(0);
    ui.Swing_Right_Shoulder_Box->setValue(0);
    ui.Swing_Left_Shoulder_Box->setValue(0);
    ui.Rise_Right_Leg_Box->setValue(0);
    ui.Rise_Left_Leg_Box->setValue(0);
    ui.Start_Swing_Box->setValue(0);
    ui.Start_Rise_Box->setValue(0);
    ui.End_Swing_Box->setValue(0);
    ui.End_Rise_Box->setValue(0);
    ui.Test_X_Box->setValue(0);
    ui.Test_Side_Box->setValue(0);
    ui.Test_Yaw_Box->setValue(0);
    ui.Tuning_X_Box->setValue(0);
    ui.Tuning_Side_Box->setValue(0);
    ui.Tuning_Yaw_Box->setValue(0);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Set_Data1_Button_clicked(){
    msg_tune2walk.Swing_Right_Leg = Tuning_Data[0].Swing_Right_Leg_Box;
    msg_tune2walk.Swing_Left_Leg = Tuning_Data[0].Swing_Left_Leg_Box;
    msg_tune2walk.Swing_Right_Shoulder = Tuning_Data[0].Swing_Right_Shoulder_Box;
    msg_tune2walk.Swing_Left_Shoulder = Tuning_Data[0].Swing_Left_Shoulder_Box;
    msg_tune2walk.Rise_Right_Leg = Tuning_Data[0].Rise_Right_Leg_Box;
    msg_tune2walk.Rise_Left_Leg = Tuning_Data[0].Rise_Left_Leg_Box;
    msg_tune2walk.Start_Rise = Tuning_Data[0].Start_Rise_Box;
    msg_tune2walk.Start_Swing = Tuning_Data[0].Start_Swing_Box;
    msg_tune2walk.End_Rise = Tuning_Data[0].End_Rise_Box;
    msg_tune2walk.End_Swing = Tuning_Data[0].End_Swing_Box;
    msg_tune2walk.Test_X = Tuning_Data[0].Test_X_Box;
    msg_tune2walk.Test_Side = Tuning_Data[0].Test_Side_Box;
    msg_tune2walk.Test_Yaw = Tuning_Data[0].Test_Yaw_Box;
    msg_tune2walk.Tuning_X = Tuning_Data[0].Tuning_X_Box;
    msg_tune2walk.Tuning_Side = Tuning_Data[0].Tuning_Side_Box;
    msg_tune2walk.Tuning_Yaw = Tuning_Data[0].Tuning_Yaw_Box;

    ui.Swing_Right_Leg_Box->setValue(Tuning_Data[0].Swing_Right_Leg_Box);
    ui.Swing_Left_Leg_Box->setValue(Tuning_Data[0].Swing_Left_Leg_Box);
    ui.Swing_Right_Shoulder_Box->setValue(Tuning_Data[0].Swing_Right_Shoulder_Box);
    ui.Swing_Left_Shoulder_Box->setValue(Tuning_Data[0].Swing_Left_Shoulder_Box);
    ui.Rise_Right_Leg_Box->setValue(Tuning_Data[0].Rise_Right_Leg_Box);
    ui.Rise_Left_Leg_Box->setValue(Tuning_Data[0].Rise_Left_Leg_Box);
    ui.Start_Swing_Box->setValue(Tuning_Data[0].Start_Swing_Box);
    ui.Start_Rise_Box->setValue(Tuning_Data[0].Start_Rise_Box);
    ui.End_Swing_Box->setValue(Tuning_Data[0].End_Swing_Box);
    ui.End_Rise_Box->setValue(Tuning_Data[0].End_Rise_Box);
    ui.Test_X_Box->setValue(Tuning_Data[0].Test_X_Box);
    ui.Test_Side_Box->setValue(Tuning_Data[0].Test_Side_Box);
    ui.Test_Yaw_Box->setValue(Tuning_Data[0].Test_Yaw_Box);
    ui.Tuning_X_Box->setValue(Tuning_Data[0].Tuning_X_Box);
    ui.Tuning_Side_Box->setValue(Tuning_Data[0].Tuning_Side_Box);
    ui.Tuning_Yaw_Box->setValue(Tuning_Data[0].Tuning_Yaw_Box);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Set_Data2_Button_clicked(){
    msg_tune2walk.Swing_Right_Leg = Tuning_Data[1].Swing_Right_Leg_Box;
    msg_tune2walk.Swing_Left_Leg = Tuning_Data[1].Swing_Left_Leg_Box;
    msg_tune2walk.Swing_Right_Shoulder = Tuning_Data[1].Swing_Right_Shoulder_Box;
    msg_tune2walk.Swing_Left_Shoulder = Tuning_Data[1].Swing_Left_Shoulder_Box;
    msg_tune2walk.Rise_Right_Leg = Tuning_Data[1].Rise_Right_Leg_Box;
    msg_tune2walk.Rise_Left_Leg = Tuning_Data[1].Rise_Left_Leg_Box;
    msg_tune2walk.Start_Rise = Tuning_Data[1].Start_Rise_Box;
    msg_tune2walk.Start_Swing = Tuning_Data[1].Start_Swing_Box;
    msg_tune2walk.End_Rise = Tuning_Data[1].End_Rise_Box;
    msg_tune2walk.End_Swing = Tuning_Data[1].End_Swing_Box;
    msg_tune2walk.Test_X = Tuning_Data[1].Test_X_Box;
    msg_tune2walk.Test_Side = Tuning_Data[1].Test_Side_Box;
    msg_tune2walk.Test_Yaw = Tuning_Data[1].Test_Yaw_Box;
    msg_tune2walk.Tuning_X = Tuning_Data[1].Tuning_X_Box;
    msg_tune2walk.Tuning_Side = Tuning_Data[1].Tuning_Side_Box;
    msg_tune2walk.Tuning_Yaw = Tuning_Data[1].Tuning_Yaw_Box;

    ui.Swing_Right_Leg_Box->setValue(Tuning_Data[1].Swing_Right_Leg_Box);
    ui.Swing_Left_Leg_Box->setValue(Tuning_Data[1].Swing_Left_Leg_Box);
    ui.Swing_Right_Shoulder_Box->setValue(Tuning_Data[1].Swing_Right_Shoulder_Box);
    ui.Swing_Left_Shoulder_Box->setValue(Tuning_Data[1].Swing_Left_Shoulder_Box);
    ui.Rise_Right_Leg_Box->setValue(Tuning_Data[1].Rise_Right_Leg_Box);
    ui.Rise_Left_Leg_Box->setValue(Tuning_Data[1].Rise_Left_Leg_Box);
    ui.Start_Swing_Box->setValue(Tuning_Data[1].Start_Swing_Box);
    ui.Start_Rise_Box->setValue(Tuning_Data[1].Start_Rise_Box);
    ui.End_Swing_Box->setValue(Tuning_Data[1].End_Swing_Box);
    ui.End_Rise_Box->setValue(Tuning_Data[1].End_Rise_Box);
    ui.Test_X_Box->setValue(Tuning_Data[1].Test_X_Box);
    ui.Test_Side_Box->setValue(Tuning_Data[1].Test_Side_Box);
    ui.Test_Yaw_Box->setValue(Tuning_Data[1].Test_Yaw_Box);
    ui.Tuning_X_Box->setValue(Tuning_Data[1].Tuning_X_Box);
    ui.Tuning_Side_Box->setValue(Tuning_Data[1].Tuning_Side_Box);
    ui.Tuning_Yaw_Box->setValue(Tuning_Data[1].Tuning_Yaw_Box);
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::on_Set_Data3_Button_clicked(){
    msg_tune2walk.Swing_Right_Leg = Tuning_Data[2].Swing_Right_Leg_Box;
    msg_tune2walk.Swing_Left_Leg = Tuning_Data[2].Swing_Left_Leg_Box;
    msg_tune2walk.Swing_Right_Shoulder = Tuning_Data[2].Swing_Right_Shoulder_Box;
    msg_tune2walk.Swing_Left_Shoulder = Tuning_Data[2].Swing_Left_Shoulder_Box;
    msg_tune2walk.Rise_Right_Leg = Tuning_Data[2].Rise_Right_Leg_Box;
    msg_tune2walk.Rise_Left_Leg = Tuning_Data[2].Rise_Left_Leg_Box;
    msg_tune2walk.Start_Rise = Tuning_Data[2].Start_Rise_Box;
    msg_tune2walk.Start_Swing = Tuning_Data[2].Start_Swing_Box;
    msg_tune2walk.End_Rise = Tuning_Data[2].End_Rise_Box;
    msg_tune2walk.End_Swing = Tuning_Data[2].End_Swing_Box;
    msg_tune2walk.Test_X = Tuning_Data[2].Test_X_Box;
    msg_tune2walk.Test_Side = Tuning_Data[2].Test_Side_Box;
    msg_tune2walk.Test_Yaw = Tuning_Data[2].Test_Yaw_Box;
    msg_tune2walk.Tuning_X = Tuning_Data[2].Tuning_X_Box;
    msg_tune2walk.Tuning_Side = Tuning_Data[2].Tuning_Side_Box;
    msg_tune2walk.Tuning_Yaw = Tuning_Data[2].Tuning_Yaw_Box;

    ui.Swing_Right_Leg_Box->setValue(Tuning_Data[2].Swing_Right_Leg_Box);
    ui.Swing_Left_Leg_Box->setValue(Tuning_Data[2].Swing_Left_Leg_Box);
    ui.Swing_Right_Shoulder_Box->setValue(Tuning_Data[2].Swing_Right_Shoulder_Box);
    ui.Swing_Left_Shoulder_Box->setValue(Tuning_Data[2].Swing_Left_Shoulder_Box);
    ui.Rise_Right_Leg_Box->setValue(Tuning_Data[2].Rise_Right_Leg_Box);
    ui.Rise_Left_Leg_Box->setValue(Tuning_Data[2].Rise_Left_Leg_Box);
    ui.Start_Swing_Box->setValue(Tuning_Data[2].Start_Swing_Box);
    ui.Start_Rise_Box->setValue(Tuning_Data[2].Start_Rise_Box);
    ui.End_Swing_Box->setValue(Tuning_Data[2].End_Swing_Box);
    ui.End_Rise_Box->setValue(Tuning_Data[2].End_Rise_Box);
    ui.Test_X_Box->setValue(Tuning_Data[2].Test_X_Box);
    ui.Test_Side_Box->setValue(Tuning_Data[2].Test_Side_Box);
    ui.Test_Yaw_Box->setValue(Tuning_Data[2].Test_Yaw_Box);
    ui.Tuning_X_Box->setValue(Tuning_Data[2].Tuning_X_Box);
    ui.Tuning_Side_Box->setValue(Tuning_Data[2].Tuning_Side_Box);
    ui.Tuning_Yaw_Box->setValue(Tuning_Data[2].Tuning_Yaw_Box);
    tune2walk_Pub.publish(msg_tune2walk);
}
void tune_walk::MainWindow::on_Save_Data1_Button_clicked(){
    Tuning_Data[0].Swing_Right_Leg_Box = msg_tune2walk.Swing_Right_Leg;
    Tuning_Data[0].Swing_Left_Leg_Box = msg_tune2walk.Swing_Left_Leg;
    Tuning_Data[0].Swing_Right_Shoulder_Box = msg_tune2walk.Swing_Right_Shoulder;
    Tuning_Data[0].Swing_Left_Shoulder_Box = msg_tune2walk.Swing_Left_Shoulder;
    Tuning_Data[0].Rise_Right_Leg_Box = msg_tune2walk.Rise_Right_Leg;
    Tuning_Data[0].Rise_Left_Leg_Box = msg_tune2walk.Rise_Left_Leg;
    Tuning_Data[0].Start_Rise_Box =  msg_tune2walk.Start_Rise;
    Tuning_Data[0].Start_Swing_Box = msg_tune2walk.Start_Swing;
    Tuning_Data[0].End_Rise_Box = msg_tune2walk.End_Rise;
    Tuning_Data[0].End_Swing_Box = msg_tune2walk.End_Swing;
    Tuning_Data[0].Test_X_Box =  msg_tune2walk.Test_X;
    Tuning_Data[0].Test_Side_Box = msg_tune2walk.Test_Side;
    Tuning_Data[0].Test_Yaw_Box = msg_tune2walk.Test_Yaw;
    Tuning_Data[0].Tuning_X_Box = msg_tune2walk.Tuning_X;
    Tuning_Data[0].Tuning_Side_Box = msg_tune2walk.Tuning_Side;
    Tuning_Data[0].Tuning_Yaw_Box = msg_tune2walk.Tuning_Yaw;
}

void tune_walk::MainWindow::on_Save_Data2_Button_clicked(){
    Tuning_Data[1].Swing_Right_Leg_Box = msg_tune2walk.Swing_Right_Leg;
    Tuning_Data[1].Swing_Left_Leg_Box = msg_tune2walk.Swing_Left_Leg;
    Tuning_Data[1].Swing_Right_Shoulder_Box = msg_tune2walk.Swing_Right_Shoulder;
    Tuning_Data[1].Swing_Left_Shoulder_Box = msg_tune2walk.Swing_Left_Shoulder;
    Tuning_Data[1].Rise_Right_Leg_Box = msg_tune2walk.Rise_Right_Leg;
    Tuning_Data[1].Rise_Left_Leg_Box = msg_tune2walk.Rise_Left_Leg;
    Tuning_Data[1].Start_Rise_Box =  msg_tune2walk.Start_Rise;
    Tuning_Data[1].Start_Swing_Box = msg_tune2walk.Start_Swing;
    Tuning_Data[1].End_Rise_Box = msg_tune2walk.End_Rise;
    Tuning_Data[1].End_Swing_Box = msg_tune2walk.End_Swing;
    Tuning_Data[1].Test_X_Box =  msg_tune2walk.Test_X;
    Tuning_Data[1].Test_Side_Box = msg_tune2walk.Test_Side;
    Tuning_Data[1].Test_Yaw_Box = msg_tune2walk.Test_Yaw;
    Tuning_Data[1].Tuning_X_Box = msg_tune2walk.Tuning_X;
    Tuning_Data[1].Tuning_Side_Box = msg_tune2walk.Tuning_Side;
    Tuning_Data[1].Tuning_Yaw_Box = msg_tune2walk.Tuning_Yaw;
}

void tune_walk::MainWindow::on_Save_Data3_Button_clicked(){
    Tuning_Data[2].Swing_Right_Leg_Box = msg_tune2walk.Swing_Right_Leg;
    Tuning_Data[2].Swing_Left_Leg_Box = msg_tune2walk.Swing_Left_Leg;
    Tuning_Data[2].Swing_Right_Shoulder_Box = msg_tune2walk.Swing_Right_Shoulder;
    Tuning_Data[2].Swing_Left_Shoulder_Box = msg_tune2walk.Swing_Left_Shoulder;
    Tuning_Data[2].Rise_Right_Leg_Box = msg_tune2walk.Rise_Right_Leg;
    Tuning_Data[2].Rise_Left_Leg_Box = msg_tune2walk.Rise_Left_Leg;
    Tuning_Data[2].Start_Rise_Box =  msg_tune2walk.Start_Rise;
    Tuning_Data[2].Start_Swing_Box = msg_tune2walk.Start_Swing;
    Tuning_Data[2].End_Rise_Box = msg_tune2walk.End_Rise;
    Tuning_Data[2].End_Swing_Box = msg_tune2walk.End_Swing;
    Tuning_Data[2].Test_X_Box =  msg_tune2walk.Test_X;
    Tuning_Data[2].Test_Side_Box = msg_tune2walk.Test_Side;
    Tuning_Data[2].Test_Yaw_Box = msg_tune2walk.Test_Yaw;
    Tuning_Data[2].Tuning_X_Box = msg_tune2walk.Tuning_X;
    Tuning_Data[2].Tuning_Side_Box = msg_tune2walk.Tuning_Side;
    Tuning_Data[2].Tuning_Yaw_Box = msg_tune2walk.Tuning_Yaw;
}

void tune_walk::MainWindow::on_Landing_Time_Control_flag_clicked()
{
    if(msg_tune2walk.Landing_Time_Control_flag == 0)
    {
        msg_tune2walk.Landing_Time_Control_flag = 1;
        cout << "LTC ON" << endl;
    }
    else if(msg_tune2walk.Landing_Time_Control_flag == 1)
    {
        msg_tune2walk.Landing_Time_Control_flag = 0;
        cout << "LTC OFF" << endl;
    }
    tune2walk_Pub.publish(msg_tune2walk);
}


void tune_walk::MainWindow::on_checkBox_Control_System_clicked()
{
    static int Control_flag[6];
    if(msg_tune2walk.Control_System_flag==1)
    {
        Control_flag[0] = msg_tune2walk.Balance_Pitch_Flag_imu;
        Control_flag[1] = msg_tune2walk.Balance_Roll_Flag_imu;
        Control_flag[2] = msg_tune2walk.Balance_Pitch_Flag;
        Control_flag[3] = msg_tune2walk.Balance_Ankle_Pitch_Flag;
        Control_flag[4] = msg_tune2walk.Balance_Roll_Flag;
        Control_flag[5] = msg_tune2walk.Landing_Time_Control_flag;
        msg_tune2walk.Control_System_flag = 0;
        msg_tune2walk.Balance_Pitch_Flag_imu = 0;
        msg_tune2walk.Balance_Roll_Flag_imu = 0;
        msg_tune2walk.Balance_Pitch_Flag = 0;
        msg_tune2walk.Balance_Ankle_Pitch_Flag = 0;
        msg_tune2walk.Balance_Roll_Flag = 0;
        msg_tune2walk.Landing_Time_Control_flag = 0;
        ui.checkBox_Pitch_IMU->setChecked(0);
        ui.checkBox_Roll_IMU->setChecked(0);
        ui.checkBox_Pitch_ZMP->setChecked(0);
        ui.checkBox_Ankle_Pitch_ZMP->setChecked(0);
        ui.checkBox_Ankle_Roll_ZMP->setChecked(0);
        ui.Landing_Time_Control_flag->setChecked(0);
    }
    else
    {

        msg_tune2walk.Control_System_flag = 1;
        if(Control_flag[0])
        {
            msg_tune2walk.Balance_Pitch_Flag_imu = 1;
            ui.checkBox_Pitch_IMU->setChecked(1);
        }
        if(Control_flag[1])
        {
            msg_tune2walk.Balance_Roll_Flag_imu = 1;
            ui.checkBox_Roll_IMU->setChecked(1);
        }
        if(Control_flag[2])
        {
            msg_tune2walk.Balance_Pitch_Flag = 1;
            ui.checkBox_Pitch_ZMP->setChecked(1);
        }
        if(Control_flag[3])
        {
            msg_tune2walk.Balance_Ankle_Pitch_Flag = 1;
            ui.checkBox_Ankle_Pitch_ZMP->setChecked(1);
        }
        if(Control_flag[4])
        {
            msg_tune2walk.Balance_Roll_Flag = 1;
            ui.checkBox_Ankle_Roll_ZMP->setChecked(1);
        }
        if(Control_flag[5])
        {
            msg_tune2walk.Landing_Time_Control_flag = 1;
            ui.Landing_Time_Control_flag->setChecked(1);
        }
    }
    tune2walk_Pub.publish(msg_tune2walk);
}

void tune_walk::MainWindow::LandingCallback()
{
    ui.Entire_Time->setText(QString::number(qnode.Landing_info.Entire_Time));
    ui.Swing_Gain_L->setText(QString::number(qnode.Landing_info.Swing_Gain_L));
    ui.Swing_Gain_R->setText(QString::number(qnode.Landing_info.Swing_Gain_R));
    ui.Slider_Warning->setValue(qnode.Landing_info.Warning);
    ui.Slider_Safe->setValue(qnode.Landing_info.Safe);

    ui.Landing_Time_L->setText(QString::number(qnode.Landing_info.Landing_Time_L));
    ui.Landing_Time_R->setText(QString::number(qnode.Landing_info.Landing_Time_R));

    ui.Landing_Error_L->setText(QString::number(qnode.Landing_info.Landing_Error_L));
    ui.Landing_Error_R->setText(QString::number(qnode.Landing_info.Landing_Error_R));
}

void tune_walk::MainWindow::on_IMU_graph_clicked(){
    if(IMU_graph_flag == false)
    {
        IMU_graph_flag = true;
    }
    else
    {
        IMU_graph_flag = false;
    }
}

void tune_walk::MainWindow::on_Pattern_graph_clicked(){
    if(Pattern_graph_flag == false)
    {
        Pattern_graph_flag = true;
    }
    else
    {
        Pattern_graph_flag = false;
    }
}
