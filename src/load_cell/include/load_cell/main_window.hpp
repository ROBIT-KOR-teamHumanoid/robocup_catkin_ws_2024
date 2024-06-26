/**
 * @file /include/load_cell/main_window.hpp
 *
 * @brief Qt based gui for load_cell.
 *
 * @date November 2010
 **/
#ifndef load_cell_MAIN_WINDOW_H
#define load_cell_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

//#include "/home/robit/catkin_ws/src/robot_config.h"

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QApplication>
#include <QPainter>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

#include <msg_generate/Serial2LC_msg.h>
#include <msg_generate/R_LC_msg.h>
#include <msg_generate/L_LC_msg.h>
#include <msg_generate/com_msg.h>

#define median_cnt 5
#define PI 3.141592653589793

#define LC_NUM 8
#define LEFT_FOOT     0
#define RIGHT_FOOT    1

/*****************************************************************************
** Namespace
*****************************************************************************/
using namespace std;

namespace load_cell {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

    QSerialPort *serial;
    msg_generate::zmp_msg zmp;

    bool open_serial();
    QByteArray Tx_data;

    msg_generate::Serial2LC_msg LC_info;
    msg_generate::R_LC_msg r_lc_info;
    msg_generate::L_LC_msg l_lc_info;
    msg_generate::com_msg COM_info;

    long int R_LC_Data[LC_NUM] = {0,};
    long int L_LC_Data[LC_NUM] = {0,};

    long int R_LC_Data_Filtering[LC_NUM] = {0,};
    long int L_LC_Data_Filtering[LC_NUM] = {0,};

    long int LC_Zero_Value[LC_NUM] = {0,};
    double LC_Unit_Value[LC_NUM] = {0,};

    double LC_Pos_X_Value[LC_NUM] = {0,};
    double LC_Pos_Y_Value[LC_NUM] = {0,};

    double LC_T_Pos_X_Value[LC_NUM] = {0,};
    double LC_T_Pos_Y_Value[LC_NUM] = {0,};

    long int add2zero[LC_NUM] = {0,};
    long int add2unit[LC_NUM] = {0,};

    bool Zero_flag = false;
    bool Unit_flag = false;

    int load_cell_median_buffer[8][median_cnt] = {{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,}};

    int LC_Zero_Gain[LC_NUM] = {0,};
    int LC_Unit_Gain[LC_NUM] = {0,};

    double R_Pos_X_Coordinate = 0.0;
    double R_Pos_Y_Coordinate = 0.0;
    double L_Pos_X_Coordinate = 0.0;
    double L_Pos_Y_Coordinate = 0.0;
    double T_Pos_X_Coordinate = 0.0;
    double T_Pos_Y_Coordinate = 0.0;

    ////////////Low_pass_filter///////////
    long int Output = 0;
    long int data_old = 0;

    //////////Support_Link////////////
    bool Left_Foot = false;
    bool Right_Foot = false;
    bool Both_Feet = false;

    /////////COM_point/////////////
    double X_com = 0.0;
    double Y_com = 0.0;

    int LTC_Value = 0;

public Q_SLOTS:

    void LoadCell_Callback();
    void makePlot();
    void Plot_init();
    void median(int data_1,int data_2,int data_3,int data_4,int data_5,int data_6,int data_7,int data_8);
    long int Low_pass_filter(long int initial_data);

private Q_SLOTS:
    void on_ZG_Push_00_clicked();
    void on_ZG_Push_01_clicked();
    void on_ZG_Push_02_clicked();
    void on_ZG_Push_03_clicked();
    void on_ZG_Push_04_clicked();
    void on_ZG_Push_05_clicked();
    void on_ZG_Push_06_clicked();
    void on_ZG_Push_07_clicked();
    void on_ZG_Insert_Button_clicked();

    void on_LC_Zero_Gain_00_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_01_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_02_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_03_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_04_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_05_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_06_textChanged(const QString &arg1);
    void on_LC_Zero_Gain_07_textChanged(const QString &arg1);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
    QTimer *timer;
};

}  // namespace load_cell

#endif // load_cell_MAIN_WINDOW_H
