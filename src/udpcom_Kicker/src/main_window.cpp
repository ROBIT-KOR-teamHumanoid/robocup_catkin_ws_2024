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
#include "../include/udpcom_Kicker/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom_Kicker {


using namespace Qt;
using namespace std;

QHostAddress ARRIVAL_IP = QHostAddress("239.255.43.21");
/*****************************************************************************
** Implementation [MainWindow]
****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/udp.png"));

    m_pSendSocket   = new QUdpSocket(this);
    m_pReadSocket1  = new QUdpSocket(this);
    ipAddressesList = QNetworkInterface::allAddresses();

    initAddrAndPort();

    qnode.init();

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    g_timer = new QTimer(this);
    QObject::connect(g_timer,SIGNAL(timeout()),this,SLOT(udpData_callback()));
    g_timer->start(500);
    //g_timer->start(314);

}

/*****************************************************************************
** Functions
*****************************************************************************/
void MainWindow::udpData_callback()   //send udp data
{
    sendData();
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

    if(!ipAddressesList.isEmpty())
    {
        for(int i = 0 ; i < ipAddressesList.size() ; i ++)
        {
            QStringList ipList = ipAddressesList[i].toString().split(".") ;
            if(ipList[0] == "192" && ipList[1] == "168")
            {
                m_qstrIp = ipAddressesList.at(i).toString();
                break;
            }
        }
    }


    m_iPort_write = 19340+qnode.robot_Num;

    ui.label_RNum->setNum(qnode.robot_Num);


    switch (qnode.robot_Num) {
    case 5:
        m_iPort_read = 19346;
        break;

    case 6:
        m_iPort_read = 19345;
        break;

    default:
        m_iPort_read = 19341;
        break;
    }
    //    m_iPort_read = 19341;


    ui.IP_Line->setText(m_qstrIp);                         ui.IP_Line->setEnabled(false);
    ui.PORT_Line->setText(QString::number(m_iPort_write)); ui.PORT_Line->setEnabled(false);
    ui.PORT_Line_2->setText(QString::number(m_iPort_read));ui.PORT_Line_2->setEnabled(false);

    if(m_pReadSocket1->bind(m_iPort_read , QUdpSocket::ShareAddress)){
        connect(m_pReadSocket1, SIGNAL(readyRead()), this, SLOT(readData()));
    }
}

void MainWindow::readData()
{
    QHostAddress senderAddress;
    quint16 senderPort;

    QByteArray Buffer;
    Buffer.resize(m_pReadSocket1->pendingDatagramSize());

    m_pReadSocket1->readDatagram(Buffer.data(),Buffer.size(),&senderAddress,&senderPort);
//    qDebug() << "From : "<<senderAddress.toString();
//    qDebug() << "Port : "<<senderPort;
//    qDebug() << "Message : "<<Buffer;


    //=====Change here (order to master)
    const std::size_t count = Buffer.size();
    unsigned char* RxData = new unsigned char[count];
    std::memcpy(RxData,Buffer.constData(),count);
    //char* RxData = Buffer.data();

    rb_h.robot_num          = RxData[0];
    rb_h.robot_case         = RxData[1];
    rb_h.robot_x_order      = RxData[3]<<8;
    rb_h.robot_x_order     += RxData[2];
    rb_h.robot_y_order      = RxData[5]<<8;
    rb_h.robot_y_order     += RxData[4];
    rb_h.robot_ik_x_order   = RxData[7]<<8;
    rb_h.robot_ik_x_order  += RxData[6];
    rb_h.robot_ik_y_order   = RxData[9]<<8;
    rb_h.robot_ik_y_order  += RxData[8];
    rb_h.robot_ik_yaw_order = RxData[11]<<8;
    rb_h.robot_ik_yaw_order+= RxData[10];


    ui.label_CaseNum    ->setNum(int(rb_h.robot_case));
    ui.textEdit_READ    ->append(QString::number(rb_h.robot_x_order));
    ui.textEdit_READ_2  ->append(QString::number(rb_h.robot_y_order));
    ui.textEdit_READ_3  ->append(QString::number(rb_h.robot_ik_x_order));
    ui.textEdit_READ_4  ->append(QString::number(rb_h.robot_ik_y_order));
    ui.textEdit_READ_5  ->append(QString::number(rb_h.robot_ik_yaw_order));

//    qnode.udp_RB_H_pub.publish(rb_h);
    qnode.udp2hoderpub.publish(rb_h);
    Buffer.clear();
}

void MainWindow::sendData()
{
    QByteArray Data;

    if(balldt >= 65000) balldt = 65000;

    //kicker robot data send
    Data.push_back(qnode.robot_Num);
    Data.push_back(qnode.robot_case);
    Data.push_back((qnode.robot_X) & 0x00FF);
    Data.push_back((qnode.robot_X) >> 8);
    Data.push_back((qnode.robot_Y) & 0x00FF);
    Data.push_back((qnode.robot_Y) >> 8);
    Data.push_back((qnode.robot_Yaw) & 0x00FF);
    Data.push_back((qnode.robot_Yaw) >> 8);

    //std::cout << qnode.robot_Yaw<< std::endl;

    //    std::cout<<"balldt & 0x00ff ==" <<(balldt & 0x00ff)<<std::endl;
    //    std::cout<<"balldt >> 8 ==" <<(balldt >> 8)<<std::endl;


    //m_pSendSocket->writeDatagram(Data.data(),Data.size(),QHostAddress::Broadcast, m_iPort_write);
    //ui.textEdit_SEND->append(QString::number(balldt));
    //qDebug() << "Send : "<<ARRIVAL_IP;

    QHostAddress addr;
    addr.setAddress("192.168.0.81");
    m_pSendSocket->writeDatagram(Data.data(),Data.size(), addr, m_iPort_write);

    cout<<"udp kicker send state : "<<qnode.robot_case<<endl;

    ui.textEdit_SEND->append(QString::number(qnode.robot_X));
    ui.textEdit_SEND_2->append(QString::number(qnode.robot_Y));
    ui.textEdit_SEND_3->append(QString::number(qnode.robot_Yaw));


}

void MainWindow::closeSocket()
{
    ui.IP_Line->setEnabled(true);
    ui.PORT_Line->setEnabled(true);

    disconnect(m_pReadSocket1,SIGNAL(readyRead()),this,SLOT(readData()));
    g_timer->stop();
    //    ui.textEdit_READ->clear();
    //    ui.textEdit_SEND->clear();
    m_pReadSocket1->close();
    m_bIsServerOpen = false;

}

MainWindow::~MainWindow()
{
    closeSocket();
    delete &ui;
    delete m_pSendSocket;
    delete m_pReadSocket1;
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

}  // namespace udpcom_Kicker

