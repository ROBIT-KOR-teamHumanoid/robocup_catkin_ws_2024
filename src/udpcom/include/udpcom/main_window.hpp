/**
 * @file /include/udpcom/main_window.hpp
 *
 * @brief Qt based gui for udpcom.
 *
 * @date November 2010
 **/
#ifndef udpcom_MAIN_WINDOW_H
#define udpcom_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

#include <iostream>



/*****************************************************************************
** Namespace
*****************************************************************************/

namespace udpcom {

typedef struct robotData
{
    int robot_X = 0;
    int robot_Y = 0;
    int robot_Yaw = 0;
    int ball_D = 0;
    int ball_T = 0;

    int robot_Num = 1;
    int robot_Pan = 0;
}robotData;
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

    void initAddrAndPort();
    void closeSocket();
    void sendData();

    void ChangeSendAddress(QHostAddress Address);

    QList<QHostAddress> ipAddressesList;


public Q_SLOTS:
    void udpData_callback();
    void init_Callback();
    void readData();
    void readData_2();
    void readData_3();
    void readData_4();
//    void timer_callback();
    void on_pushButton_clicked();

private:
    Ui::MainWindowDesign ui;
    QNode qnode;
    QTimer *g_timer;
    QUdpSocket     *m_pSendSocket;
    QUdpSocket     *m_pReadSocket1;
    QUdpSocket     *m_pReadSocket2;
    QUdpSocket     *m_pReadSocket3;
    QUdpSocket     *m_pReadSocket4;
    QHostAddress   m_qSrcAddress;
    QHostAddress   m_qDestAddress;
    QHostAddress   ARRIVAL_IP;

    quint16        m_iPort_write = 19341;
    quint16        m_iPort_read = 19342;     //1220
    quint16        m_iPort_read_2 = 19343;
    quint16        m_iPort_read_3 = 19344;
    quint16        m_iPort_read_4 = 19344;
    msg_generate::localv2_msg rb_1;
    msg_generate::localv2_msg rb_2;
    msg_generate::localv2_msg rb_3;
    msg_generate::localv2_msg rb_4;
//    robotData      rb_1;
//    robotData      rb_2;
    QString        m_qstrIp;

    bool           m_bIsServerOpen;

    int balldt = 0;
    int field_area = 0;
    int ball_area = 0;
    int robocup_case = 0;
    double order = 0.0;



};

}  // namespace udpcom

#endif // udpcom_MAIN_WINDOW_H