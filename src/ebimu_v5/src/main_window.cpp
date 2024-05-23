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
#include "../include/ebimu_v5/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ebimu_v5 {

using namespace Qt;
using namespace std;

QByteArray Rx_data;
QByteArray Tx_data;
unsigned char TxBuffer[10] = {0, };


/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    qnode.init();
    if(!open_serial())
        exit(0);

    uiUpdate();
    init_mw_ahrsv1();
    past_yaw = 0;

    ui.dial->setRange(-180 +30, 180 -30);



    QObject::connect(serial, SIGNAL(readyRead()), this, SLOT(mw_ahrsv1CallBack()));
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

bool MainWindow::open_serial()
{
    serial = new QSerialPort(this);
    serial -> setPortName("ttyUSB-EBIMU");
    serial -> setBaudRate(QSerialPort::Baud115200);
    serial -> setDataBits(QSerialPort::Data8);
    serial -> setParity(QSerialPort::NoParity);
    serial -> setStopBits(QSerialPort::OneStop);
    serial -> setFlowControl(QSerialPort::NoFlowControl);
    if(!serial -> open(QIODevice::ReadWrite))
    {
        cout<<"**********Serial port open fail!!**********"<<endl;
        return false;
    }
    else
        return true;
}


void MainWindow::init_mw_ahrsv1()
{
    TxBuffer[0] = A;     // a
    TxBuffer[1] = N;     // n
    TxBuffer[2] = G;     // g
    TxBuffer[3] = CR;    // CR
    TxBuffer[4] = LF;    // LF
    //    TxBuffer[5] = G;
    //    TxBuffer[6] = Y;
    //    TxBuffer[7] = R;
    //    TxBuffer[8] = CR;
    //    TxBuffer[9] = LF;


    for(int i = 0; i < 5; i++)
    {
        Tx_data.push_back(TxBuffer[i]);
    }

    serial -> write(Tx_data,5);
}

void MainWindow::uiUpdate()
{
    ui.dial->setValue(static_cast<int>(-euler.yaw));
    ui.verticalSlider->setValue(static_cast<int>(euler.pitch));
    ui.horizontalSlider->setValue(static_cast<int>(euler.roll));
}

void MainWindow::mw_ahrsv1CallBack()
{

    if(!serial->isOpen())
    {
        open_serial();
    }

    if(serial->isReadable())
    {
        Rx_data = serial->readAll();
        char *Rx_Buf = Rx_data.data();

        char *ptr;

        ptr = strtok(Rx_Buf,",");
        if(strcmp(ptr,"*")){
            int i = 0;
            while(ptr != NULL)
            {

                if(i == 0){
                    euler.pitch = atof(ptr+1);
                }
                else if(i == 1){
                    euler.roll = atof(ptr);
                }
                else if(i == 2){
                    euler.yaw = -atof(ptr);
                }
                //                else if(i == 5)
                //                    euler.roll_acc = atof(ptr);
                //                else if(i == 6)
                //                    euler.pitch_acc = atof(ptr);
                //                else if(i == 7)
                //                    euler.yaw_acc = atof(ptr);
                ptr = strtok(NULL, ",");
                i++;
            }
            if(past_yaw > 180) past_yaw -= 360;
            else if(past_yaw <= -180)  past_yaw += 360;
            euler.yaw -= past_yaw;



            if(euler.yaw > 180) euler.yaw -= 360;
            else if(euler.yaw <= -180)  euler.yaw += 360;


            imu_msg.roll = euler.roll;
            imu_msg.pitch = euler.pitch;
            imu_msg.yaw = euler.yaw;

            cout.precision(4);
            cout << endl;
            cout<<" YAW  | "<<imu_msg.yaw<<endl;
            cout<<" ROLL | "<<imu_msg.roll<<endl;
            cout<<" PITCH| "<<imu_msg.pitch<<endl;
            cout << endl;

            qnode.Imu_pub.publish(imu_msg);
            Rx_data.clear();
        }
        else {
            qnode.Imu_pub.publish(imu_msg);
            Rx_data.clear();
        }
        uiUpdate();
    }
}

void MainWindow::on_pushButton_set_clicked()
{
    cout<<"set"<<endl;
    past_yaw += euler.yaw;
}

void MainWindow::on_pushButton_set_p90_clicked()
{
    cout<<"set +90"<<endl;
    past_yaw += euler.yaw + 90;
}

void MainWindow::on_pushButton_set_n90_clicked()
{
    cout<<"set -90"<<endl;
    past_yaw += euler.yaw - 90;
}

void MainWindow::on_pushButton_set_180_clicked()
{
    cout<<"set 180"<<endl;
    past_yaw += euler.yaw + 180;
}

MainWindow::~MainWindow() {
    serial->close();
}

}  // namespace mw_ahrsv1



