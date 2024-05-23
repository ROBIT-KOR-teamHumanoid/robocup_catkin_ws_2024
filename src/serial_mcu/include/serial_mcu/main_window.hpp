/**
 * @file /include/serial_mcu/main_window.hpp
 *
 * @brief Qt based gui for serial_mcu.
 *
 * @date November 2010
 **/
#ifndef serial_mcu_MAIN_WINDOW_H
#define serial_mcu_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <vector>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "Motor_msg.h"
#include "Mt2Serial_msg.h"
#include <msg_generate/Serial2LC_msg.h>
#include <msg_generate/R_LC_msg.h>
#include <msg_generate/L_LC_msg.h>
#include <string.h>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace serial_mcu {

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
        msg_generate::motion_end motion_msg;
        msg_generate::Serial2LC_msg loadcell_info;

        msg_generate::R_LC_msg r_lc_info;
        msg_generate::L_LC_msg l_lc_info;
        bool open_serial();
        unsigned char rx_buffer[999];
        int rx_idx = 0;


public Q_SLOTS:
        void DynamixelCallback();
        void MotionCallback();
        void RxCallBack();
        void TxData(unsigned char ID, unsigned char Instruction,
                    unsigned char ParameterLength, unsigned char Motion_Mode, unsigned char MotionNum);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace serial_mcu

#endif // serial_mcu_MAIN_WINDOW_H
