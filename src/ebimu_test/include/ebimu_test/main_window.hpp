/**
 * @file /include/ebimu_test/main_window.hpp
 *
 * @brief Qt based gui for ebimu_test.
 *
 * @date November 2010
 **/
#ifndef ebimu_test_MAIN_WINDOW_H
#define ebimu_test_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace ebimu_test {

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

    msg_generate::imu_msg imu_msg;
    msg_generate::pid_tuning pid_msg;

public Q_SLOTS:
    void mainTimerCallback(void);

private:
	Ui::MainWindowDesign ui;
    QNode qnode;

    QTimer *mainTimer;

    double yaw;
    double Kp, Ki, Kd;
};

}  // namespace ebimu_test

#endif // ebimu_test_MAIN_WINDOW_H
