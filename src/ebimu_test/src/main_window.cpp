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
#include "../include/ebimu_test/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ebimu_test {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    qnode.init();

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    mainTimer = new QTimer(this);
    QObject::connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainTimerCallback()));
    mainTimer->start(50);
}

MainWindow::~MainWindow() {
    delete mainTimer;
}

/*****************************************************************************
** Functions
*****************************************************************************/

void MainWindow::mainTimerCallback()
{
    //IMU
    if(ui.checkBox_yawEnable->isChecked())
    {
        double weight = ui.doubleSpinBox_yawWeight->value();

        yaw = ui.horizontalSlider_YAW->value() * 0.001;

        if(qnode.walk_flag){
            yaw += weight * qnode.robot_yaw;
            if(yaw > 180)
            {
                yaw = -180;
            }
            else if(yaw < -180)
            {
                yaw = 180;
            }

            ui.horizontalSlider_YAW->setValue(yaw * 1000);
        }

        ui.label_YAW->setNum(ui.horizontalSlider_YAW->value() * 0.001);

        imu_msg.yaw = yaw;
        qnode.imu_pub.publish(imu_msg);
    }

    //PID
    Kp = ui.doubleSpinBox_Kp->value();
    Ki = ui.doubleSpinBox_Ki->value();
    Kd = ui.doubleSpinBox_Kd->value();

    pid_msg.Kp = Kp;
    pid_msg.Ki = Ki;
    pid_msg.Kd = Kd;

    qnode.pid_pub.publish(pid_msg);
}


}  // namespace ebimu_test

