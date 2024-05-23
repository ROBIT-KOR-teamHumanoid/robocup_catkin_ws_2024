/**
 * @file /include/motion/main_window.hpp
 *
 * @brief Qt based gui for motion.
 *
 * @date November 2010
 **/
#ifndef motion_MAIN_WINDOW_H
#define motion_MAIN_WINDOW_H


#define YAW 0
#define PITCH 1

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include "Motor_msg.h"
#include <cmath>

#include "/home/robit/catkin_ws/src/motion/include/motion/qcustomplot.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace motion {

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

    //For timer
    QTimer *m_Timer;

    void setting();
    void send_motion_total();

    void send_motion_swing(int speed);
    void send_motion_kick_L(int speed);
    void send_motion_kick_R(int speed);
    void send_motion_turn(int speed);
    void send_motion_arm(int speed);
    void send_motion_ankle_L(int speed);
    void send_motion_ankle_R(int speed);

    void print_loadcell();
    QGraphicsScene *scene;





    int AngleToPosition(double angle);
    int cal_speed(int deg, int time);

    //For mode
    int main_mode = 0;

    int first_read = 0;

    int motion_timer = -1;
    double motion_speed_timer = 0;
    int motion_flag = 1;


    //For ui
    int motion_swing = 0;
    int motion_rise = 0;
    int motion_step_min = 0;
    int motion_step_max = 0;
    int motion_turn_min = 0;
    int motion_turn_max = 0;
    int motion_power = 0;
    int motion_direction = 0;

    int pattern[16] = {0,};





    //For Dynamixel
    unsigned int lowpassfilter[2][2];
    const double ratio = 0.5;
    int waist_flag = 0;
    unsigned int Dynamixel_ID_Position[22] = {0,};
    unsigned int Dynamixel_ID_INIT_Position[22] = {2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048};

    int TARGET[22] = {0,};
    unsigned int INIT[22] = {2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048};
    int OFFSET[22] = {0,};

    int READY0[22] = {0,}; //init
    int READY1[22] = {0,}; //swing
    int READY2[22] = {0,}; //leg up
    int READY3[22] = {0,}; //leg back
    int READY4[22] = {0,}; //kick1
    int READY5[22] = {0,}; //kick2
    int READY6[22] = {0,}; //back
    int READY7[22] = {0,}; //init



    //For loadcell
    int Lfoot_x = 0, Lfoot_y = 0;





public Q_SLOTS:
    int main();
    void on_init_reset_clicked();
    void on_init_save_clicked();
    void on_init_down_clicked();
    void on_init_up_clicked();
    void on_init_read_clicked();
    void on_init_down_side_clicked();
    void on_init_up_side_clicked();
    void on_offset_reset_clicked();
    void on_offset_save_clicked();
    void on_offset_down_clicked();
    void on_offset_up_clicked();
    void on_offset_read_clicked();
    void on_offset_down_side_clicked();
    void on_offset_up_side_clicked();
    void on_toolBox_currentChanged(int index);

    void on_ready_swing_clicked();
    void on_motion_test_clicked();
    void on_load_cell_clicked();


private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace motion

#endif // motion_MAIN_WINDOW_H
