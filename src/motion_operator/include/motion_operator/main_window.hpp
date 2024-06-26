/**
 * @file /include/motion_operator/main_window.hpp
 *
 * @brief Qt based gui for motion_operator.
 *
 * @date November 2010
 **/
#ifndef motion_operator_MAIN_WINDOW_H
#define motion_operator_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "ros/ros.h" //tw
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "QTimer"
#include "QElapsedTimer"

//tw
#include <QtGui/QAction>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QDir>

#include <QKeyEvent> //tw
#include <QDebug> //tw

#define Relative 1
#define Absolute 2

#define MAX_DXL_NUM 22//22(dance) //모터 개수 설정?


/*****************************************************************************
** Namespace
*****************************************************************************/

namespace motion_operator {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */

enum STEP {STEP1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7, STEP8, STEP9, STEP10, STEP11, STEP12, STEP13, STEP14, STEP15};

typedef struct DxlInfo {
    int id;
    int move_pos;   //상대값
    DxlInfo()
    {
        id = 0;
        move_pos = 0;
    }
}DxlInfo;

typedef struct MotionInfo {
    QString Name;
    uint8_t Max_step;
    uint8_t Acceleration;
    uint8_t Repeat;
    uint8_t Motion_speed;    //always 100

    MotionInfo()
    {
        Name = "noname";
        Max_step = 1;
        Acceleration = 20;
        Repeat = 1;
        Motion_speed = 100;
    }
}MotionInfo;

typedef struct StepInfo {
    uint8_t Time;
    uint8_t Delay;
    uint16_t Step_pos[23] = {0, };   //상대값
    double imu_roll; //20240501

    StepInfo()
    {
        Time = 50;
        Delay = 0;
    }
}StepInfo;

typedef union _DATA
{
    uint16_t Word;
    struct _Byte
    {
        uint8_t L;
        uint8_t H;
    } Byte;
} DATA;


typedef union _DXLS
{
    uint16_t Speed;
    struct _SPEED
    {
        uint8_t L;
        uint8_t H;
    } SpeedByte;
} DXLS;

typedef struct _STEPSPEED
{
    DXLS RXS[MAX_DXL_NUM+1];
}STEPSPEED;

class MainWindow : public QMainWindow {
Q_OBJECT

    void read_WorkFile(int Mt_num);
    void publish_Mt();
    void publish_Init();
    uint16_t Init_Data[23] = {0,};
    uint16_t late_Data[23] = {0,};
//    uint16_t Init_Data[19] = {0,};
//    uint16_t late_Data[19] = {0,};
    void setInit();
    void Motion_init(int time);
    MotionInfo m_MotionData;
    StepInfo m_StepData[15];
//    msg_generate::Step_msg
    uint16_t AccTime_Calc(uint8_t);
    DATA Speed_Calc(uint8_t Step_Number, uint8_t DXL_ID, unsigned int *DXL_half_flag, unsigned int *DXL_Acclink, unsigned int *Acting_Time_Acc);
    double ang2pos(double angle); //20240429
    void Play_Motion();
    void Play_Step(int step);

    msg_generate::Motor_msg Dx_msg;
    // msg_generate::Motion_msg Motion_msg; // 20240402 tw


    STEPSPEED speed[4];

    int timer_ms = 0;

    void onTimer0();
    void offTimer0();

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void on_pushButton_StartMt_clicked();
    void MotionNumCallback();
    void TimerCallback();
    void MotionCallback();
//    void ETimerCallback();
    void on_pushButton_STOP_clicked();

//    struct Motor_Angle
//    {
//        //1 ~ 4096
//        int Motor_Angle_0 = 0;
//        int Motor_Angle_1 = 0;
//        int Motor_Angle_10 = 0;
//        int Motor_Angle_11 = 0;
//        int Motor_Angle_12 = 0;
//        int Motor_Angle_13 = 0;
//        int Motor_Angle_14 = 0;
//        int Motor_Angle_15 = 0;
//        int Motor_Angle_16 = 0;
//        int Motor_Angle_17 = 0;
//        int Motor_Angle_18 = 0;
//        int Motor_Angle_19 = 0;
//        int Motor_Angle_20 = 0;
//        int Motor_Angle_21 = 0;
//    };
//    Motor_Angle Now_Motor_Angle;
//    Motor_Angle Past_Motor_Angle;
//    Motor_Angle Buffer_Motor_Angle;

//    typedef struct Compensate_Angle //tw
//    {
//        double Compensate_Angle_Arm_2 = 0.0;
//        double Compensate_Angle_Arm_3 = 0.0;
//        double Compensate_Angle_Left_10 = 0.0;
//        double Compensate_Angle_Left_12 = 0.0;
//        double Compensate_Angle_Left_14 = 0.0;
//        double Compensate_Angle_Left_16 = 0.0;
//        double Compensate_Angle_Left_18 = 0.0;
//        double Compensate_Angle_Left_20 = 0.0;
//        double Compensate_Angle_Right_11 = 0.0;
//        double Compensate_Angle_Right_13 = 0.0;
//        double Compensate_Angle_Right_15 = 0.0;
//        double Compensate_Angle_Right_17 = 0.0;
//        double Compensate_Angle_Right_19 = 0.0;
//        double Compensate_Angle_Right_21 = 0.0;
//        double Horizontal_Angle = 0.0;
//        double Vertical_Angle = 0.0;
//        double R_Vertical_Angle = 0.0;
//        double L_Vertical_Angle = 0.0;

//    }Compensate_Angle_Data;

private:
	Ui::MainWindowDesign ui;
    bool MT_Flag = false;
    bool MT_STOP = false;
    QTimer* m_Timer;
//    QElapsedTimer *m_eTimer;
	QNode qnode;

    int NowRepeat = 0;
    int NowStep = 0;
    int NowState = 0;

    unsigned int g_DXL_ID_position[30] = {0, }; //output
    unsigned int g_DXL_ID_Save_position[30] = {0, };
    int Motion_Data[400] = {0, };
};

}  // namespace motion_operator

#endif // motion_operator_MAIN_WINDOW_H
