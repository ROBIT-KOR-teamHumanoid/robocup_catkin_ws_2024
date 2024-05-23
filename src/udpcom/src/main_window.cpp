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
#include <QUdpSocket>
#include <cstring>
#include "../include/udpcom/main_window.hpp"

using namespace std;
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    qnode.init();
    MainWindow::ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    m_pSendSocket = new QUdpSocket(this);
    m_pReadSocket1 = new QUdpSocket(this);
    m_pReadSocket2 = new QUdpSocket(this);
    m_pReadSocket3= new QUdpSocket(this);
    m_pReadSocket4= new QUdpSocket(this);

    ipAddressesList = QNetworkInterface::allAddresses();

    ARRIVAL_IP = QHostAddress("239.255.43.21");

    initAddrAndPort();

    QObject::connect(&qnode, SIGNAL(getrobotNum()), this, SLOT(init_Callback()));

    g_timer = new QTimer(this);
    QObject::connect(g_timer,SIGNAL(timeout()),this,SLOT(udpData_callback()));
    g_timer->start(500);
}

void MainWindow::udpData_callback()   //send udp data
{
    if(qnode.robot_num<=4)
    {
        sendData();

    }
}

void MainWindow::init_Callback()
{
    closeSocket();
    initAddrAndPort();
    g_timer->start(500);
}

void MainWindow::ChangeSendAddress(QHostAddress Address)
{
    ARRIVAL_IP = Address;
}

void MainWindow::initAddrAndPort()
{
    m_qstrIp = QHostAddress::LocalHost;
    QHostAddress addr;

    if(!ipAddressesList.isEmpty())
    {
        for(int i = 0 ; i < ipAddressesList.size() ; i ++)
        {
            QStringList ipList = ipAddressesList[i].toString().split(".") ;
            if(ipList[0] == "192" && ipList[1] == "168" && ipList[2] == "4")
            {
//                m_qstrIp = ipAddressesList.at(i).toString();
                addr = ipAddressesList.at(i);
                break;
            }
        }
    }
//    addr.setAddress("172.20.10.10");
    m_qstrIp = addr.toString();

    qnode.myTeam *= 10;
    m_iPort_write = 19000 + qnode.robot_num + qnode.myTeam;

    ui.NUM_Line->setText(QString::number(qnode.robot_num));


    switch (qnode.robot_num) {
    case 1:
        m_iPort_read = 19002;
        m_iPort_read_2 = 19003;
        m_iPort_read_3 = 19004;
        break;

    case 2:
        m_iPort_read = 19001;
        m_iPort_read_2 = 19003;
        m_iPort_read_3 = 19004;
        break;

    case 3:
        m_iPort_read = 19001;
        m_iPort_read_2 = 19002;
        m_iPort_read_3 = 19004;
        break;
    case 4:
        m_iPort_read = 19341;
        m_iPort_read_2 = 19342;
        m_iPort_read_3 = 19343;
        break;

    case 5:
        m_iPort_read = 19001;
        m_iPort_read_2 = 19002;
        m_iPort_read_3 = 19003;
        m_iPort_read_4 = 19004;
        break;
    default:
        m_iPort_read = 19002;
        m_iPort_read_2 = 19003;
        m_iPort_read_3 = 19004;
        break;
    }

    m_iPort_read += qnode.myTeam;
    m_iPort_read_2 += qnode.myTeam;
    m_iPort_read_3 += qnode.myTeam;
    m_iPort_read_4 += qnode.myTeam;

    ui.IP_Line->setText(m_qstrIp);
    ui.PORT_Line->setText(QString::number(m_iPort_write));
    ui.PORT_Line_2->setText(QString::number(m_iPort_read));
    ui.PORT_Line_3->setText(QString::number(m_iPort_read_2));
    ui.PORT_Line_4->setText(QString::number(m_iPort_read_3));
    ui.IP_Line->setEnabled(false);
    ui.PORT_Line->setEnabled(false);
    ui.PORT_Line_2->setEnabled(false);
    ui.PORT_Line_3->setEnabled(false);
    ui.PORT_Line_4->setEnabled(false);
    ui.NUM_Line->setEnabled(false);

    if(m_pReadSocket1->bind(addr, m_iPort_read, QUdpSocket::ShareAddress)){
        connect(m_pReadSocket1, SIGNAL(readyRead()), this, SLOT(readData()));
    }

    if(m_pReadSocket2->bind(addr, m_iPort_read_2, QUdpSocket::ShareAddress)){
        connect(m_pReadSocket2, SIGNAL(readyRead()), this, SLOT(readData_2()));
    }
    if(m_pReadSocket3->bind(addr, m_iPort_read_3, QUdpSocket::ShareAddress)){
        connect(m_pReadSocket3, SIGNAL(readyRead()), this, SLOT(readData_3()));
    }
    if(qnode.robot_num>4)
    {
        if(m_pReadSocket4->bind(addr, m_iPort_read_4, QUdpSocket::ShareAddress)){
            connect(m_pReadSocket4, SIGNAL(readyRead()), this, SLOT(readData_4()));
        }
    }
    else
    {
    }
}

void MainWindow::readData()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pReadSocket1->pendingDatagramSize());

    m_pReadSocket1->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);

    //=====Change here (order to master)
    const std::size_t count = Buffer.size();
    unsigned char* RxData = new unsigned char[count];
    std::memcpy(RxData,Buffer.constData(),count);

    rb_1.robot_num = RxData[0];
    rb_1.robot_case = RxData[1];
    rb_1.local_x    = RxData[3]<<8;
    rb_1.local_x    += RxData[2];
    rb_1.local_y    = RxData[5]<<8;
    rb_1.local_y    += RxData[4];
    rb_1.local_yaw  = RxData[7]<<8;
    rb_1.local_yaw  += RxData[6];
    rb_1.local_yaw  -= 180;
    rb_1.ball_x    = RxData[9]<<8;
    rb_1.ball_x    += RxData[8];
    rb_1.ball_y    = RxData[11]<<8;
    rb_1.ball_y    += RxData[10];
    rb_1.ballDist   = RxData[13]<<8;
    rb_1.ballDist   +=  RxData[12];
    rb_1.ballTheta  = RxData[15]<<8;
    rb_1.ballTheta  += RxData[14];
    rb_1.ballTheta  -= 180;

    ui.radioButton_read1->setChecked(true);

    qnode.udp_RB1_pub.publish(rb_1);
    Buffer.clear();
}

void MainWindow::readData_2()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pReadSocket2->pendingDatagramSize());

    m_pReadSocket2->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);

    //=====Change here (order to master)
    const std::size_t count = Buffer.size();
    unsigned char* RxData = new unsigned char[count];
    std::memcpy(RxData,Buffer.constData(),count);

    rb_2.robot_num = RxData[0];
    rb_2.robot_case = RxData[1];
    rb_2.local_x    = RxData[3]<<8;
    rb_2.local_x    += RxData[2];
    rb_2.local_y    = RxData[5]<<8;
    rb_2.local_y    += RxData[4];
    rb_2.local_yaw  = RxData[7]<<8;
    rb_2.local_yaw  += RxData[6];
    rb_2.local_yaw  -= 180;
    rb_2.ball_x    = RxData[9]<<8;
    rb_2.ball_x    += RxData[8];
    rb_2.ball_y    = RxData[11]<<8;
    rb_2.ball_y    += RxData[10];
    rb_2.ballDist   = RxData[13]<<8;
    rb_2.ballDist   +=  RxData[12];
    rb_2.ballTheta  = RxData[15]<<8;
    rb_2.ballTheta  += RxData[14];
    rb_2.ballTheta  -= 180;

    ui.radioButton_read2->setChecked(true);

    cout << "22222222222222222222222222222222222" << endl;

    qnode.udp_RB2_pub.publish(rb_2);
    Buffer.clear();
}

void MainWindow::readData_3()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pReadSocket3->pendingDatagramSize());

    m_pReadSocket3->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);

    //=====Change here (order to master)
    const std::size_t count = Buffer.size();
    unsigned char* RxData = new unsigned char[count];
    std::memcpy(RxData,Buffer.constData(),count);

    rb_3.robot_num = RxData[0];
    rb_3.robot_case = RxData[1];
    rb_3.local_x    = RxData[3]<<8;
    rb_3.local_x    += RxData[2];
    rb_3.local_y    = RxData[5]<<8;
    rb_3.local_y    += RxData[4];
    rb_3.local_yaw  = RxData[7]<<8;
    rb_3.local_yaw  += RxData[6];
    rb_3.local_yaw  -= 180;
    rb_3.ball_x    = RxData[9]<<8;
    rb_3.ball_x    += RxData[8];
    rb_3.ball_y    = RxData[11]<<8;
    rb_3.ball_y    += RxData[10];
    rb_3.ballDist   = RxData[13]<<8;
    rb_3.ballDist   +=  RxData[12];
    rb_3.ballTheta  = RxData[15]<<8;
    rb_3.ballTheta  += RxData[14];
    rb_3.ballTheta  -= 180;

    ui.radioButton_read3->setChecked(true);

    qnode.udp_RB3_pub.publish(rb_3);
    Buffer.clear();
}

void MainWindow::readData_4()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pReadSocket4->pendingDatagramSize());

    m_pReadSocket4->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);

    //=====Change here (order to master)
    const std::size_t count = Buffer.size();
    unsigned char* RxData = new unsigned char[count];
    std::memcpy(RxData,Buffer.constData(),count);

    rb_4.robot_num = RxData[0];
    rb_4.robot_case = RxData[1];
    rb_4.local_x    = RxData[3]<<8;
    rb_4.local_x    += RxData[2];
    rb_4.local_y    = RxData[5]<<8;
    rb_4.local_y    += RxData[4];
    rb_4.local_yaw  = RxData[7]<<8;
    rb_4.local_yaw  += RxData[6];
    rb_4.local_yaw  -= 180;
    rb_4.ball_x    = RxData[9]<<8;
    rb_4.ball_x    += RxData[8];
    rb_4.ball_y    = RxData[11]<<8;
    rb_4.ball_y    += RxData[10];
    rb_4.ballDist   = RxData[13]<<8;
    rb_4.ballDist   +=  RxData[12];
    rb_4.ballTheta  = RxData[15]<<8;
    rb_4.ballTheta  += RxData[14];
    rb_4.ballTheta  -= 180;

    qnode.udp_RB4_pub.publish(rb_4);
    Buffer.clear();
}

void MainWindow::sendData()
{
//    rb_2.robot_num = 2;
//    rb_2.robot_case = 1;
//    rb_2.local_x    = 806;
//    rb_2.local_y    = 571;
//    qnode.udp_RB2_pub.publish(rb_2);

//    rb_3.robot_num = 3;
//    rb_3.robot_case = 1;
//    rb_3.local_x    = 779;
//    rb_3.local_y    = 251;
//    qnode.udp_RB3_pub.publish(rb_3);

    QByteArray Data;

    if(balldt >= 65000) balldt = 65000;

    Data.push_back(qnode.robot_num);
    Data.push_back(qnode.robot_case);
    Data.push_back((qnode.robot_coor_x) & 0x00FF);
    Data.push_back((qnode.robot_coor_x) >> 8);
    Data.push_back((qnode.robot_coor_y) & 0x00FF);
    Data.push_back((qnode.robot_coor_y) >> 8);
    Data.push_back((qnode.robot_imu_yaw) & 0x00FF);
    Data.push_back((qnode.robot_imu_yaw) >> 8);
    Data.push_back((qnode.ball_coor_x) & 0x00FF);
    Data.push_back((qnode.ball_coor_x) >> 8);
    Data.push_back((qnode.ball_coor_y) & 0x00FF);
    Data.push_back((qnode.ball_coor_y) >> 8);
    Data.push_back((qnode.ball_dist) & 0x00FF);
    Data.push_back((qnode.ball_dist) >> 8);
    Data.push_back((qnode.ball_theta) & 0x00FF);
    Data.push_back((qnode.ball_theta) >> 8);

    QHostAddress addr1, addr2, addr3, addr4;
    addr1.setAddress("192.168.4.1");
    addr2.setAddress("192.168.4.2");
    addr3.setAddress("192.168.4.3");
    addr4.setAddress("192.168.4.4");
//    addr.setAddress("172.20.10.5");
    m_pSendSocket->writeDatagram(Data.data(),Data.size(), addr1, m_iPort_write);
    m_pSendSocket->writeDatagram(Data.data(),Data.size(), addr2, m_iPort_write);
    m_pSendSocket->writeDatagram(Data.data(),Data.size(), addr3, m_iPort_write);
    m_pSendSocket->writeDatagram(Data.data(),Data.size(), addr4, m_iPort_write);


    ui.radioButton_read1->setChecked(false);
    ui.radioButton_read2->setChecked(false);
    ui.radioButton_read3->setChecked(false);
}

void MainWindow::closeSocket()
{
    ui.IP_Line->setEnabled(true);
    ui.PORT_Line->setEnabled(true);

    disconnect(m_pReadSocket1,SIGNAL(readyRead()),this,SLOT(readData()));
    disconnect(m_pReadSocket2,SIGNAL(readyRead()),this,SLOT(readData_2()));
    disconnect(m_pReadSocket3,SIGNAL(readyRead()),this,SLOT(readData_3()));

    if(qnode.robot_num>4)
    {
        disconnect(m_pReadSocket4,SIGNAL(readyRead()),this,SLOT(readData_4()));
        m_pReadSocket4->close();

    }
    g_timer->stop();

    m_pReadSocket1->close();
    m_pReadSocket2->close();
    m_pReadSocket3->close();
    m_bIsServerOpen = false;
}

MainWindow::~MainWindow()
{
    closeSocket();
    delete &ui;
    delete m_pSendSocket;
    delete m_pReadSocket1;
    delete m_pReadSocket2;
    delete m_pReadSocket3;

    delete m_pReadSocket4;
}


/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::on_pushButton_clicked()
{
    closeSocket();

    initAddrAndPort();

    g_timer->start(500);
}

}  // namespace udpcom
