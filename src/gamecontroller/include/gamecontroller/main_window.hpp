/**
 * @file /include/gamecontroller/main_window.hpp
 *
 * @brief Qt based gui for gamecontroller.
 *
 * @date November 2010
 **/
#ifndef gamecontroller_MAIN_WINDOW_H
#define gamecontroller_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "QKeyEvent"
#include "RoboCupGameControlData.h"

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTimer>

#include <iostream>

#define TEAM_ROBIT          4
#define TEAM_ROBIT_RED      22
#define TEAM_ROBIT_BLUE     23

#define LEFT                0
#define RIGHT               1

#define POSITION            0
#define POSITION_GK         1
#define POSITION_FW         2
#define POSITION_TECHNICAL  3

#define STATE_TECHNICAL     0
#define STATE_TCCL_RK       1
#define STATE_TCCL_RH       2
#define STATE_TCDK          3
#define STATE_TCHK          4
#define STATE_TCPK          5

using namespace std;
/*****************************************************************************
** Namespace
*****************************************************************************/

namespace gamecontroller {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  QTimer        *mTimer;
  MainWindow(int argc, char** argv, QWidget *parent = 0);
  ~MainWindow();

  void showNoMasterMessage();

  bool initAddrAndPort();
  void initSocket();
  void closeSocket();

  //kjh edit
  void uiUpdate();
  void sendData();
  void ChangeSendAddress(QHostAddress Address);
  void ChangeTechnicalMode();

  QList<QHostAddress> ipAddressesList;
  //edit end
public Q_SLOTS:


private:
  Ui::RobocupController ui;
  QNode qnode;

  QTimer *g_timer;

  QHostAddress senderAddress;
  quint16 senderPort;

  QUdpSocket     *m_pReadSocket=NULL;
  QUdpSocket     *m_pSendSocket=NULL;

  QHostAddress   m_qSrcAddress;
  QHostAddress   m_qDestAddress;

  quint16        m_iPort;
  QString        m_qstrIp;

  bool           m_bIsServerOpen;

  int            position = 0;
  int            playerNum = 0;
  int            initSide = 0;
  int            mySide = 0;
  int            myTeam = TEAM_ROBIT;


private Q_SLOTS:    
  void on_comboBox_position_currentIndexChanged(int index);
  void on_Server_Open_clicked();
  void udpSend_callback();
  void readData();

  void on_comboBox_state_currentIndexChanged(int index);

private:

  struct RoboCupGameControlData robocupData;
  struct RoboCupGameControlReturnData robocupreturnData;
  struct RobotInfo robotInfo;
  struct TeamInfo teamInfo;
};

}  // namespace gamecontroller

#endif // gamecontroller_MAIN_WINDOW_H



