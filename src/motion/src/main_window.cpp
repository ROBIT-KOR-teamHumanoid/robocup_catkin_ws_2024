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
#include <fstream>
#include <string>
#include "../include/motion/main_window.hpp"

extern ros::Publisher motor_dxl_Publisher;
extern ros::Subscriber loadcell_sub;
serial_mcu::Motor_msg dxMsg;

int loadcell_zero[8] = {0,};//{8361713,8790146,7627146,8451717,8369872,8088191,8433721,8214542};
int loadcell_data[8] = {0,};
int load_cell_reset = 0;

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace motion {

using namespace Qt;
using namespace std;

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

    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(main()));
    m_Timer->start(12);

    Dynamixel_ID_INIT_Position[0] = 2048;
    Dynamixel_ID_INIT_Position[1] = 2048;
    Dynamixel_ID_INIT_Position[2] = 2048;
    Dynamixel_ID_INIT_Position[3] = 2048;
    Dynamixel_ID_INIT_Position[4] = 2048;
    Dynamixel_ID_INIT_Position[5] = 2048;
    Dynamixel_ID_INIT_Position[6] = 2048;
    Dynamixel_ID_INIT_Position[7] = 2048;
    Dynamixel_ID_INIT_Position[8] = 2048;
    Dynamixel_ID_INIT_Position[9] = 2048;
    Dynamixel_ID_INIT_Position[10] = 2048;
    Dynamixel_ID_INIT_Position[11] = 2048;
    Dynamixel_ID_INIT_Position[12] = 2048;
    Dynamixel_ID_INIT_Position[13] = 2048;
    Dynamixel_ID_INIT_Position[14] = 2048;
    Dynamixel_ID_INIT_Position[15] = 2048;
    Dynamixel_ID_INIT_Position[16] = 2048;
    Dynamixel_ID_INIT_Position[17] = 2048;
    Dynamixel_ID_INIT_Position[18] = 2048;
    Dynamixel_ID_INIT_Position[19] = 2048;
    Dynamixel_ID_INIT_Position[20] = 2048;
    Dynamixel_ID_INIT_Position[21] = 2048;

    ui.pattern_plot->addGraph();
    ui.pattern_plot->graph(0)->setPen(QPen(Qt::red, 2));
    ui.pattern_plot->addGraph();
    ui.pattern_plot->graph(1)->setPen(QPen(Qt::blue, 2));
    ui.pattern_plot->addGraph();
    ui.pattern_plot->graph(2)->setPen(QPen(Qt::green, 2));
    ui.pattern_plot->addGraph();
    ui.pattern_plot->graph(3)->setPen(QPen(Qt::yellow, 2));
    ui.pattern_plot->xAxis->setLabel("Time(sec)");
    ui.pattern_plot->yAxis->setLabel("Scale");
    ui.pattern_plot->xAxis->setRange(0, 10);
    ui.pattern_plot->yAxis->setRange(-20, 60);
    ui.pattern_plot->setBackground(QColor(30, 30, 30));
    ui.pattern_plot->xAxis->setTickLabelColor(Qt::white);
    ui.pattern_plot->xAxis->setBasePen(QPen(Qt::white));
    ui.pattern_plot->xAxis->setLabelColor(Qt::white);
    ui.pattern_plot->xAxis->setTickPen(QPen(Qt::white));
    ui.pattern_plot->xAxis->setSubTickPen(QPen(Qt::white));
    ui.pattern_plot->yAxis->setTickLabelColor(Qt::white);
    ui.pattern_plot->yAxis->setBasePen(QPen(Qt::white));
    ui.pattern_plot->yAxis->setLabelColor(Qt::white);
    ui.pattern_plot->yAxis->setTickPen(QPen(Qt::white));
    ui.pattern_plot->yAxis->setSubTickPen(QPen(Qt::white));

    scene = new QGraphicsScene(this);

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/
void MainWindow::print_loadcell()
{
    if(scene){delete scene;}

    scene = new QGraphicsScene(this);
    ui.screen->setScene(scene);

    QBrush blueBrush(Qt::blue);
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush yellowBrush(Qt::yellow);
    QBrush blackBrush(Qt::black);
    QBrush grayBrush(Qt::gray);
    QPen grayPen(Qt::gray); grayPen.setWidth(1);
    QPen redPen(Qt::red); redPen.setWidth(2);
    QPen redPen3(Qt::red); redPen3.setWidth(3);
    QPen greenPen(Qt::green); greenPen.setWidth(2);
    QPen bluePen(Qt::blue); bluePen.setWidth(2);
    QPen blackPen1(Qt::black); blackPen1.setWidth(1);
    QPen blackPen(Qt::black); blackPen.setWidth(2);
    QPen blackPen3(Qt::black); blackPen3.setWidth(3);
    QPen LocalPen1(Qt::blue); LocalPen1.setWidth(5);
    QPen LocalPen2(Qt::green); LocalPen2.setWidth(5);
    QPen LocalPen3(Qt::yellow); LocalPen3.setWidth(5);
    QPen LocalPen4(Qt::red); LocalPen4.setWidth(5);
    QPen yellowPen(Qt::yellow); yellowPen.setWidth(3);
    QPen targetPen(Qt::red); targetPen.setWidth(3);
    QPen targetlinePen(Qt::gray); targetlinePen.setWidth(2);

    scene->addRect(0, 0, 50, 70, grayPen, grayBrush);
    scene->addRect(100, 0, 50, 70, grayPen, grayBrush);

    int total = loadcell_data[0] + loadcell_data[1] + loadcell_data[2] + loadcell_data[3];
    double avg[4] = {0,};
    for(int i = 0; i < 4; i++)
    {
        avg[i] = (double)loadcell_data[i] / (double)total;
        //cout<<avg[i]<<endl;
    }
    //cout<<"  "<<endl;
    int center_x = 25, center_y = 35;

    center_x += avg[0] * -25 + avg[1] * -25 + avg[2] * 25 + avg[3] * 25;
    center_y += avg[0] * -35 + avg[1] * 35 + avg[2] * -35 + avg[3] * 35;
    if(center_x < -10){center_x = -10;}
    if(center_x > 60){center_x = 60;}
    if(center_y < -10){center_y = -10;}
    if(center_y > 80){center_y = 80;}

    Lfoot_x = center_x - 25;
    Lfoot_y = center_y - 35;
    scene->addEllipse(center_x - 5, center_y - 5, 10, 10, redPen, redBrush);



//    //print obstacle
//    if(obstacle0.x != 0 && obstacle0.y != 0)
//    {
//        scene->addEllipse(cvt_Print_xy(obstacle0.x) - 35, cvt_Print_xy(obstacle0.y) - 35, 70, 70, grayPen, grayBrush);
//    }
//    if(obstacle1.x != 0 && obstacle1.y != 0)
//    {
//        scene->addEllipse(cvt_Print_xy(obstacle1.x) - 35, cvt_Print_xy(obstacle1.y) - 35, 70, 70, grayPen, grayBrush);
//    }
//    if(obstacle2.x != 0 && obstacle2.y != 0)
//    {
//        scene->addEllipse(cvt_Print_xy(obstacle2.x) - 35, cvt_Print_xy(obstacle2.y) - 35, 70, 70, grayPen, grayBrush);
//    }
//    if(obstacle3.x != 0 && obstacle3.y != 0)
//    {
//        scene->addEllipse(cvt_Print_xy(obstacle3.x) - 35, cvt_Print_xy(obstacle3.y) - 35, 70, 70, grayPen, grayBrush);
//    }
}
int MainWindow::main()
{
    setting();
    print_loadcell();
    //cout<<"\n\n"<<endl;



    switch(main_mode)
    {
    case 0:
    {
        //cout<<"INIT MODE"<<endl;
        for(int i = 0; i < 22; i++)
        {
            Dynamixel_ID_INIT_Position[i] = INIT[i];
            TARGET[i] = 0;
        }
        //SEND MOTION
        send_motion_total();
        break;
    }
    case 1:
    {
        //cout<<"OFFSET MODE"<<endl;
        for(int i = 0; i < 22; i++){TARGET[i] = OFFSET[i];}
        //SEND MOTION
        send_motion_total();
        break;
    }
    case 2:
    {
        //cout<<"READY MODE"<<endl;
        if(motion_timer > 99)
        {
            motion_timer = -1;
            ui.progressbar->setValue(10);
            //cout<<"MOTION END!!!!!!!!!!!!!"<<endl;
        }
        else if(motion_timer == -1)
        {
            //cout<<"*** STOP ***"<<endl;
            ui.progressbar->setValue(0);
            for(int i = 0; i < 22; i++){TARGET[i] = OFFSET[i];}
            //SEND MOTION
            send_motion_total();
        }
        else
        {
            //cout<<"***** PLAYNG MOTION *****"<<endl;
            ui.progressbar->setValue((int)(motion_timer / 10));

            if(motion_flag == 1)
            {
                //***********   swing   *************
                if(pattern[3] != 0 && motion_timer == pattern[0] * 10) //swing start
                {
                    TARGET[10] = OFFSET[10] + motion_swing; TARGET[20] = OFFSET[20] + motion_swing;
                    TARGET[11] = OFFSET[11] + motion_swing * 1.5; TARGET[21] = OFFSET[21] + motion_swing * 1.5;
                    //SEND MOTION
                    send_motion_swing(cal_speed(motion_swing, pattern[1] - pattern[0]));
                }
                if(pattern[3] != 0 && motion_timer == (pattern[1] + pattern[2]) * 10) //swing end
                {
                    TARGET[10] = OFFSET[10]; TARGET[20] = OFFSET[20];
                    TARGET[11] = OFFSET[11]; TARGET[21] = OFFSET[21];
                    //SEND MOTION
                    send_motion_swing(cal_speed(motion_swing, pattern[3] - (pattern[1] + pattern[2])));

                    //ARM
                    TARGET[0] = OFFSET[0];
                    TARGET[2] = OFFSET[2];
                    TARGET[4] = OFFSET[4];

                    TARGET[1] = OFFSET[1];
                    TARGET[3] = OFFSET[3];
                    TARGET[5] = OFFSET[5];
                    send_motion_arm(150);
                }
                else if(pattern[3] != 0 && motion_timer > pattern[1] * 10 && motion_timer < (pattern[1] + pattern[2]) * 10) //swing~~~ing
                {
                    int swing_loadcell = motion_swing;
                    swing_loadcell += Lfoot_x / 10;
                    cout<<"swing_loadcell : "<<swing_loadcell<<endl;
                    TARGET[10] = OFFSET[10] + swing_loadcell; TARGET[20] = OFFSET[20] + swing_loadcell;
                    TARGET[11] = OFFSET[11] + swing_loadcell * 1.5; TARGET[21] = OFFSET[21] + swing_loadcell * 1.5;
                    //SEND MOTION
                    send_motion_swing(1024);

                    int pitch_loadcell = Lfoot_y / 15;
                    cout<<"pitch_loadcell : "<<pitch_loadcell<<endl;
//                    if(pitch_loadcell > 0){pitch_loadcell = 1;}
//                    else if(pitch_loadcell < 0){pitch_loadcell = -1;}
                    TARGET[18] = OFFSET[18] - pitch_loadcell;
                    //SEND MOTION
                    send_motion_ankle_L(1024);
                }
                if(pattern[3] != 0 && motion_timer < (pattern[1] + pattern[2]) * 10)
                {
                    //ARM
                    int arm_loadcell = Lfoot_x / 3;
                    if(arm_loadcell > 5){arm_loadcell = 5;}
                    else if(arm_loadcell < -5){arm_loadcell = -5;}

                    TARGET[0] = 35;
                    TARGET[2] = (-1) * arm_loadcell * 10 - 80;
                    TARGET[4] = (-1) * arm_loadcell * 10 + 80;

                    TARGET[1] = -35;
                    TARGET[3] = (-1) * arm_loadcell * 10 + 80;
                    TARGET[5] = (-1) * arm_loadcell * 10 - 80;
                    send_motion_arm(200);
                }


                //***********   rise   *************
                double separate_value = 9;
                int end_param = 10;
                if(pattern[7] != 0 && motion_timer == pattern[4] * 10) //rise start
                {
                    TARGET[15] = OFFSET[15] - motion_rise / 2;
                    TARGET[17] = OFFSET[17] - motion_rise;
                    TARGET[19] = OFFSET[19] - motion_rise;
                    //SEND MOTION
                    send_motion_kick_R(cal_speed(motion_rise, pattern[5] - pattern[4]));
                    send_motion_ankle_R(cal_speed(motion_rise, pattern[5] - pattern[4]));
                }
                else if(pattern[7] != 0 && motion_timer == (pattern[5] + pattern[6]) * 10) //rise end
                {
                    TARGET[15] = OFFSET[15];
                    TARGET[17] = OFFSET[17];
                    TARGET[19] = OFFSET[19];
                    //SEND MOTION
                    send_motion_kick_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                    send_motion_ankle_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                }
//                else if(pattern[7] != 0 && motion_timer == (pattern[5] * 2 + pattern[6] * 2 + pattern[7]) / 3 * 10) //rise end
//                {
//                    TARGET[15] = OFFSET[15];
//                    TARGET[17] = OFFSET[17];
//                    TARGET[19] = OFFSET[19];
//                    //SEND MOTION
//                    send_motion_kick_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
//                    send_motion_ankle_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
//                }

                //***********   step   *************
                if(pattern[11] != 0 && motion_timer >= pattern[8] * 10 && motion_timer < pattern[9] * 10) //step start
                {
                    //cout<<motion_timer<<endl;
                    TARGET[15] = TARGET[15] + motion_power / separate_value;
                    TARGET[17] = TARGET[17] + motion_power / separate_value;
                    if(TARGET[17] > 130){TARGET[17] = 130;}

                    int target_deg = TARGET[19];
                    TARGET[19] = TARGET[15] + TARGET[17];
                    if(TARGET[19] > 100){TARGET[19] = 100;}
                    if(TARGET[19] < -20){TARGET[19] = -20;}
                    target_deg -= TARGET[19];

                    send_motion_kick_R(cal_speed(motion_power, pattern[9] - pattern[8]));
                    send_motion_ankle_R(cal_speed(target_deg, (pattern[9] - pattern[8])/3));
                }
                else if(pattern[11] != 0 && motion_timer == (pattern[9] + pattern[10]) * 10) //step end
                {
                    TARGET[15] = OFFSET[15] + end_param * 1;
                    TARGET[17] = OFFSET[17] - end_param * 2;
                    TARGET[19] = OFFSET[19] - end_param * 1;
                    //SEND MOTION
                    send_motion_kick_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                    send_motion_ankle_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                }
                else if(pattern[11] != 0 && motion_timer == (pattern[9] * 2 + pattern[10] * 2 + pattern[11]) / 3 * 10) //step end
                {
                    TARGET[15] = OFFSET[15];
                    TARGET[17] = OFFSET[17];
                    TARGET[19] = OFFSET[19];
                    //SEND MOTION
                    send_motion_kick_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                    send_motion_ankle_R(cal_speed(motion_power, pattern[11] - (pattern[9] + pattern[10])));
                }

                //***********   turn   *************
                if(pattern[15] != 0 && motion_timer == pattern[12] * 10) //turn start
                {
                    TARGET[12] = OFFSET[12] + motion_direction;
                    TARGET[13] = TARGET[13] - motion_direction;
                    //SEND MOTION
                    send_motion_turn(cal_speed(abs(motion_direction), pattern[13] - pattern[12]));
                }
                if(pattern[15] != 0 && motion_timer == (pattern[13] + pattern[14]) * 10) //turn end
                {
                    TARGET[12] = OFFSET[12];
                    TARGET[13] = OFFSET[13];
                    //SEND MOTION
                    send_motion_turn(cal_speed(abs(motion_direction), pattern[15] - (pattern[13] + pattern[14])));
                }



                //***********   end   *************
                if(motion_timer == 90)
                {
                    for(int i = 0; i < 22; i++){TARGET[i] = OFFSET[i];}
                    //SEND MOTION
                    send_motion_swing(100);
                    send_motion_kick_L(100);
                    send_motion_kick_R(100);
                    send_motion_turn(100);
                    send_motion_arm(100);
                    send_motion_ankle_L(100);
                    send_motion_ankle_R(100);
                }

                //SEND TO SERIAL
                if(dxMsg.id.size() != 0)
                {
                    dxMsg.length = dxMsg.id.size();
                    dxMsg.mode = 3;
                    motor_dxl_Publisher.publish(dxMsg);

                    dxMsg.id.clear();
                    dxMsg.position.clear();
                    dxMsg.speed.clear();
                }
            }
            motion_flag = 0;



            if(motion_speed_timer > 3)
            {
                motion_speed_timer = 0;
                motion_timer += 1;
                motion_flag = 1;
            }

            motion_speed_timer += (double)(ui.motion_speed->value()) / 10;
            //cout<<motion_timer<<endl;
        }


        break;
    }
    }


}

void motion::QNode::LoadCell_Callback(const msg_generate::Serial2LC_msg::ConstPtr &msg)
{
    if(load_cell_reset == 1)
    {
        loadcell_zero[0] = msg->R_LC_Data[0];
        loadcell_zero[1] = msg->R_LC_Data[1];
        loadcell_zero[2] = msg->R_LC_Data[2];
        loadcell_zero[3] = msg->R_LC_Data[3];
        loadcell_zero[4] = msg->L_LC_Data[0];
        loadcell_zero[5] = msg->L_LC_Data[1];
        loadcell_zero[6] = msg->L_LC_Data[2];
        loadcell_zero[7] = msg->L_LC_Data[3];
        load_cell_reset = 0;
    }
    loadcell_data[0] = msg->R_LC_Data[0] - loadcell_zero[0];
    loadcell_data[1] = msg->R_LC_Data[1] - loadcell_zero[1];
    loadcell_data[2] = msg->R_LC_Data[2] - loadcell_zero[2];
    loadcell_data[3] = msg->R_LC_Data[3] - loadcell_zero[3];

    loadcell_data[4] = msg->L_LC_Data[0] - loadcell_zero[4];
    loadcell_data[5] = msg->L_LC_Data[1] - loadcell_zero[5];
    loadcell_data[6] = msg->L_LC_Data[2] - loadcell_zero[6];
    loadcell_data[7] = msg->L_LC_Data[3] - loadcell_zero[7];
}

int MainWindow::cal_speed(int deg, int time)
{
    double max_deg = deg * M_PI / 180 * (double)(ui.motion_speed->value()) / 3/* <- temp */;
    double target_rad = max_deg / time;
    double target_rpm = target_rad / 2 / M_PI * 60;
    return target_rpm / 0.110;
}

void MainWindow::on_motion_test_clicked()
{
    motion_timer = 0;
    motion_flag = 1;
}
void MainWindow::on_load_cell_clicked()
{
   load_cell_reset = 1;
}
void MainWindow::setting()
{
    //INIT
    INIT[0] = ui.init0->value();
    INIT[1] = ui.init1->value();
    INIT[2] = ui.init2->value();
    INIT[3] = ui.init3->value();
    INIT[4] = ui.init4->value();
    INIT[5] = ui.init5->value();
//    INIT[6] = ui.init6->value();
//    INIT[7] = ui.init7->value();
//    INIT[8] = ui.init8->value();
//    INIT[9] = ui.init9->value();
    INIT[10] = ui.init10->value();
    INIT[11] = ui.init11->value();
    INIT[12] = ui.init12->value();
    INIT[13] = ui.init13->value();
    INIT[14] = ui.init14->value();
    INIT[15] = ui.init15->value();
    INIT[16] = ui.init16->value();
    INIT[17] = ui.init17->value();
    INIT[18] = ui.init18->value();
    INIT[19] = ui.init19->value();
    INIT[20] = ui.init20->value();
    INIT[21] = ui.init21->value();

    //OFFSET
    OFFSET[0] = ui.offset_0->value();
    OFFSET[1] = ui.offset_1->value();
    OFFSET[2] = ui.offset_2->value();
    OFFSET[3] = ui.offset_3->value();
    OFFSET[4] = ui.offset_4->value();
    OFFSET[5] = ui.offset_5->value();
//    OFFSET[6] = ui.offset_6->value();
//    OFFSET[7] = ui.offset_7->value();
//    OFFSET[8] = ui.offset_8->value();
//    OFFSET[9] = ui.offset_9->value();
    OFFSET[10] = ui.offset_10->value();
    OFFSET[11] = ui.offset_11->value();
    OFFSET[12] = ui.offset_12->value();
    OFFSET[13] = ui.offset_13->value();
    OFFSET[14] = ui.offset_14->value();
    OFFSET[15] = ui.offset_15->value();
    OFFSET[16] = ui.offset_16->value();
    OFFSET[17] = ui.offset_17->value();
    OFFSET[18] = ui.offset_18->value();
    OFFSET[19] = ui.offset_19->value();
    OFFSET[20] = ui.offset_20->value();
    OFFSET[21] = ui.offset_21->value();

    motion_swing = ui.motion_swing->value();
    motion_rise = ui.motion_rise->value();
    motion_power = ui.motion_power->value();
    motion_direction = ui.motion_direction->value();

    pattern[0] = ui.pattern_0->value();
    pattern[1] = ui.pattern_1->value();
    pattern[2] = ui.pattern_2->value();
    pattern[3] = ui.pattern_3->value();
    pattern[4] = ui.pattern_4->value();
    pattern[5] = ui.pattern_5->value();
    pattern[6] = ui.pattern_6->value();
    pattern[7] = ui.pattern_7->value();
    pattern[8] = ui.pattern_8->value();
    pattern[9] = ui.pattern_9->value();
    pattern[10] = ui.pattern_10->value();
    pattern[11] = ui.pattern_11->value();
    pattern[12] = ui.pattern_12->value();
    pattern[13] = ui.pattern_13->value();
    pattern[14] = ui.pattern_14->value();
    pattern[15] = ui.pattern_15->value();

    ui.pattern_plot->graph(0)->data()->clear();
    ui.pattern_plot->graph(1)->data()->clear();
    ui.pattern_plot->graph(2)->data()->clear();
    ui.pattern_plot->graph(3)->data()->clear();

    QVector<double> x(6), y(6);
    x[0] = 0; y[0] = 0;
    x[1] = pattern[0]; y[1] = 0;
    x[2] = pattern[1]; y[2] = motion_swing;
    x[3] = pattern[1] + pattern[2]; y[3] = motion_swing;
    x[4] = pattern[3]; y[4] = 0;
    x[5] = 10; y[5] = 0;
    ui.pattern_plot->graph(0)->addData(x, y);

    x[0] = 0; y[0] = 0;
    x[1] = pattern[4]; y[1] = 0;
    x[2] = pattern[5]; y[2] = motion_rise;
    x[3] = pattern[5] + pattern[6]; y[3] = motion_rise;
    x[4] = pattern[7]; y[4] = 0;
    x[5] = 10; y[5] = 0;
    ui.pattern_plot->graph(1)->addData(x, y);

    x[0] = 0; y[0] = 0;
    x[1] = pattern[8]; y[1] = 0;
    x[2] = pattern[9]; y[2] = motion_power;
    x[3] = pattern[9] + pattern[10]; y[3] = motion_power;
    x[4] = pattern[11]; y[4] = 0;
    x[5] = 10; y[5] = 0;
    ui.pattern_plot->graph(2)->addData(x, y);

    x[0] = 0; y[0] = 0;
    x[1] = pattern[12]; y[1] = 0;
    x[2] = pattern[13]; y[2] = motion_direction;
    x[3] = pattern[13] + pattern[14]; y[3] = motion_direction;
    x[4] = pattern[15]; y[4] = 0;
    x[5] = 10; y[5] = 0;
    ui.pattern_plot->graph(3)->addData(x, y);




    ui.pattern_plot->replot();


}
void MainWindow::send_motion_total()
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    serial_mcu::Motor_msg dxMsg;
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        if(main_mode != 2)
        {
            if(i == 16 || i == 17)
            {
                dxMsg.speed.push_back(200);
            }
            else
            {
                dxMsg.speed.push_back(100);
            }

        }
        else{dxMsg.speed.push_back(1023);}
    }
    dxMsg.length = dxMsg.id.size();
    dxMsg.mode = 3;
    motor_dxl_Publisher.publish(dxMsg);
}
void MainWindow::send_motion_swing(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 10 && i != 11 && i != 20 && i != 21){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }
}

void MainWindow::send_motion_kick_L(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 14 && i != 16){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }
}
void MainWindow::send_motion_kick_R(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 15 && i != 17){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }
}
void MainWindow::send_motion_ankle_L(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 18){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }
}
void MainWindow::send_motion_ankle_R(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 19){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }

}
void MainWindow::send_motion_turn(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 12 && i != 13){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        dxMsg.speed.push_back(speed);
    }
}
void MainWindow::send_motion_arm(int speed)
{
    for(int i = 0; i < 22; i++){Dynamixel_ID_Position[i + waist_flag] = Dynamixel_ID_INIT_Position[i + waist_flag] + AngleToPosition(TARGET[i]);}
    bool fflag = true;
    for(int i = 0; i < 22; i++)
    {
        if(i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5){continue;}
        unsigned int pos = Dynamixel_ID_Position[i + waist_flag];
        if(pos > 4096) {int posMax = 4095;  pos = posMax;}
        else if(pos < 0) {int posMin =1; pos = posMin;}
        if(waist_flag == 2 && fflag == true) {dxMsg.id.push_back(22); fflag = false;}
        else {dxMsg.id.push_back(i);}
        dxMsg.position.push_back(pos);
        if(i == 4 || i == 5)
        {
            int max_speed = speed * 2;
            if(max_speed > 1024){max_speed = 1024;}
            dxMsg.speed.push_back(max_speed);
        }
        else
        {
            dxMsg.speed.push_back(speed);
        }

    }
}
int MainWindow::AngleToPosition(double angle)
{
    return (int)((angle * 4096) / 360);
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    main_mode = index;
}

void MainWindow::on_init_reset_clicked()
{
    ui.init0->setValue(2048);
    ui.init1->setValue(2048);
    ui.init2->setValue(2048);
    ui.init3->setValue(2048);
    ui.init4->setValue(2048);
    ui.init5->setValue(2048);
//    ui.init6->setValue(2048);
//    ui.init7->setValue(2048);
//    ui.init8->setValue(2048);
//    ui.init9->setValue(2048);
    ui.init10->setValue(2048);
    ui.init11->setValue(2048);
    ui.init12->setValue(2048);
    ui.init13->setValue(2048);
    ui.init14->setValue(2048);
    ui.init15->setValue(2048);
    ui.init16->setValue(2048);
    ui.init17->setValue(2048);
    ui.init18->setValue(2048);
    ui.init19->setValue(2048);
    ui.init20->setValue(2048);
    ui.init21->setValue(2048);
}

void MainWindow::on_init_save_clicked()
{
    string init_dir = "/home/robit/catkin_ws/src/motion/resources/backup/init.txt";
    ofstream Last_Index_Num_OUT(init_dir);
    if(Last_Index_Num_OUT.is_open()){for(int i = 0; i < 22; i++){Last_Index_Num_OUT << INIT[i] << endl;}}
    Last_Index_Num_OUT.close();
}

void MainWindow::on_init_read_clicked()
{
    string init_dir = "/home/robit/catkin_ws/src/motion/resources/backup/init.txt";
    int temp = 0;
    ifstream Last_Index_Num_IN(init_dir);
    if (Last_Index_Num_IN.is_open()){
        Last_Index_Num_IN >> temp; ui.init0->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init1->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init2->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init3->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init4->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init5->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.init6->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.init7->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.init8->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.init9->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init10->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init11->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init12->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init13->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init14->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init15->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init16->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init17->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init18->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init19->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init20->setValue(temp);
        Last_Index_Num_IN >> temp; ui.init21->setValue(temp);
    }
    Last_Index_Num_IN.close();
}



void MainWindow::on_init_down_side_clicked()
{
    ui.init10->setValue(ui.init10->value() + 10);
    ui.init20->setValue(ui.init20->value() + 10);
    ui.init11->setValue(ui.init11->value() - 10);
    ui.init21->setValue(ui.init21->value() - 10);
}
void MainWindow::on_init_up_side_clicked()
{
    ui.init10->setValue(ui.init10->value() - 10);
    ui.init20->setValue(ui.init20->value() - 10);
    ui.init11->setValue(ui.init11->value() + 10);
    ui.init21->setValue(ui.init21->value() + 10);
}
void MainWindow::on_init_down_clicked()
{
    ui.init14->setValue(ui.init14->value() - 10);
    ui.init15->setValue(ui.init15->value() + 10);//
    ui.init16->setValue(ui.init16->value() + 20);
    ui.init17->setValue(ui.init17->value() - 20);//
    ui.init18->setValue(ui.init18->value() + 10);
    ui.init19->setValue(ui.init19->value() - 10);//
}
void MainWindow::on_init_up_clicked()
{
    ui.init14->setValue(ui.init14->value() + 10);
    ui.init15->setValue(ui.init15->value() - 10);//
    ui.init16->setValue(ui.init16->value() - 20);
    ui.init17->setValue(ui.init17->value() + 20);//
    ui.init18->setValue(ui.init18->value() - 10);
    ui.init19->setValue(ui.init19->value() + 10);//
}


void MainWindow::on_offset_reset_clicked()
{
    ui.offset_0->setValue(0);
    ui.offset_1->setValue(0);
    ui.offset_2->setValue(0);
    ui.offset_3->setValue(0);
    ui.offset_4->setValue(0);
    ui.offset_5->setValue(0);
//    ui.offset_6->setValue(0);
//    ui.offset_7->setValue(0);
//    ui.offset_8->setValue(0);
//    ui.offset_9->setValue(0);
    ui.offset_10->setValue(0);
    ui.offset_11->setValue(0);
    ui.offset_12->setValue(0);
    ui.offset_13->setValue(0);
    ui.offset_14->setValue(0);
    ui.offset_15->setValue(0);
    ui.offset_16->setValue(0);
    ui.offset_17->setValue(0);
    ui.offset_18->setValue(0);
    ui.offset_19->setValue(0);
    ui.offset_20->setValue(0);
    ui.offset_21->setValue(0);
}
void MainWindow::on_offset_save_clicked()
{
    string offset_dir = "/home/robit/catkin_ws/src/motion/resources/backup/offset.txt";
    ofstream Last_Index_Num_OUT(offset_dir);
    if(Last_Index_Num_OUT.is_open()){for(int i = 0; i < 22; i++){Last_Index_Num_OUT << OFFSET[i] << endl;}}
    Last_Index_Num_OUT.close();
}
void MainWindow::on_offset_read_clicked()
{
    string offset_dir = "/home/robit/catkin_ws/src/motion/resources/backup/offset.txt";
    int temp = 0;
    ifstream Last_Index_Num_IN(offset_dir);
    if (Last_Index_Num_IN.is_open()){
        Last_Index_Num_IN >> temp; ui.offset_0->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_1->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_2->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_3->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_4->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_5->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.offset_6->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.offset_7->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.offset_8->setValue(temp);
        Last_Index_Num_IN >> temp; //ui.offset_9->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_10->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_11->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_12->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_13->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_14->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_15->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_16->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_17->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_18->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_19->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_20->setValue(temp);
        Last_Index_Num_IN >> temp; ui.offset_21->setValue(temp);
    }
    Last_Index_Num_IN.close();
}

void MainWindow::on_offset_down_side_clicked()
{
    ui.offset_10->setValue(ui.offset_10->value() + 1);
    ui.offset_20->setValue(ui.offset_20->value() + 1);
    ui.offset_11->setValue(ui.offset_11->value() - 1);
    ui.offset_21->setValue(ui.offset_21->value() - 1);
}
void MainWindow::on_offset_up_side_clicked()
{
    ui.offset_10->setValue(ui.offset_10->value() - 1);
    ui.offset_20->setValue(ui.offset_20->value() - 1);
    ui.offset_11->setValue(ui.offset_11->value() + 1);
    ui.offset_21->setValue(ui.offset_21->value() + 1);
}
void MainWindow::on_offset_down_clicked()
{
    ui.offset_14->setValue(ui.offset_14->value() - 1);
    ui.offset_15->setValue(ui.offset_15->value() + 1);//
    ui.offset_16->setValue(ui.offset_16->value() + 2);
    ui.offset_17->setValue(ui.offset_17->value() - 2);//
    ui.offset_18->setValue(ui.offset_18->value() + 1);
    ui.offset_19->setValue(ui.offset_19->value() - 1);//
}
void MainWindow::on_offset_up_clicked()
{
    ui.offset_14->setValue(ui.offset_14->value() + 1);
    ui.offset_15->setValue(ui.offset_15->value() - 1);//
    ui.offset_16->setValue(ui.offset_16->value() - 2);
    ui.offset_17->setValue(ui.offset_17->value() + 2);//
    ui.offset_18->setValue(ui.offset_18->value() - 1);
    ui.offset_19->setValue(ui.offset_19->value() + 1);//
}
void MainWindow::on_ready_swing_clicked()
{
    ui.offset_10->setValue(ui.offset_10->value() + 2);
    ui.offset_20->setValue(ui.offset_20->value() + 2);
    ui.offset_11->setValue(ui.offset_11->value() + 1);
    ui.offset_21->setValue(ui.offset_21->value() + 1);
}


}  // namespace motion

