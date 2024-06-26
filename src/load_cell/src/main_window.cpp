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
#include "../include/load_cell/main_window.hpp"
#include <sstream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QApplication>
#include <QTimer>
#include <QString>
#include <QtCore>
#include <QPen>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

/*****************************************************************************
** Namespaces
*****************************************************************************/
namespace load_cell {

using namespace Qt;
using namespace std;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/
int serial_cnt = 0;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon("/home/robit/catkin_ws/src/load_cell/resources/images/zmp_icon.png"));

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    QObject::connect(&qnode, SIGNAL(LC_callback()),this, SLOT(LoadCell_Callback())); //works whenever 'load_cell value' comes in through serial
    qnode.init();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(makePlot()));
    MainWindow::makePlot();
    Plot_init();

    for(int i = 0; i < LC_NUM; i++)
    {
        add2unit[i] = 1;
        LC_Zero_Gain[i] = 1;
    }
}

void MainWindow::LoadCell_Callback()
{
    if(!(timer->isActive()))
            timer->start(10);

    serial_cnt++;
    for(int i = 0; i < LC_NUM/2; i++) //Right, Left 나눠서 LoadCell값 저장
    {
        L_LC_Data[i] = qnode.LC_info.L_LC_Data[i];
        R_LC_Data[i] = qnode.LC_info.R_LC_Data[i];

//                R_LC_Data[i] = Low_pass_filter(qnode.LC_info.R_LC_Data[i]);
//              L_LC_Data[i] = Low_pass_filter(qnode.LC_info.L_LC_Data[i]);
    }

    ui.LC_Data_00->setText(QString::number(L_LC_Data[0]));
    ui.LC_Data_01->setText(QString::number(L_LC_Data[1]));
    ui.LC_Data_02->setText(QString::number(L_LC_Data[2]));
    ui.LC_Data_03->setText(QString::number(L_LC_Data[3]));

    ui.LC_Data_04->setText(QString::number(R_LC_Data[0]));
    ui.LC_Data_05->setText(QString::number(R_LC_Data[1]));
    ui.LC_Data_06->setText(QString::number(R_LC_Data[2]));
    ui.LC_Data_07->setText(QString::number(R_LC_Data[3]));

    LC_Zero_Value[0] = +add2zero[0] - L_LC_Data[0];
    LC_Zero_Value[1] = +L_LC_Data[1] - add2zero[1];
    LC_Zero_Value[2] = +L_LC_Data[2] - add2zero[2];
    LC_Zero_Value[3] = add2zero[3] - L_LC_Data[3];

    LC_Zero_Value[4] = +add2zero[4] - R_LC_Data[0];
    LC_Zero_Value[5] = +R_LC_Data[1] - add2zero[5];
    LC_Zero_Value[6] = R_LC_Data[2] - add2zero[6];
    LC_Zero_Value[7] = add2zero[7] - R_LC_Data[3];

#ifdef ROBIT_HUMANOID_ROBOT_NUMBER_1
    LC_Zero_Value[0] = -add2zero[0] + L_LC_Data[0];
    LC_Zero_Value[1] = -L_LC_Data[1] + add2zero[1];
    LC_Zero_Value[2] = -L_LC_Data[2] + add2zero[2];
    LC_Zero_Value[3] = add2zero[3] - L_LC_Data[3];

    LC_Zero_Value[4] = add2zero[4] - R_LC_Data[0];
    LC_Zero_Value[5] = R_LC_Data[1] - add2zero[5];
    LC_Zero_Value[6] = R_LC_Data[2] - add2zero[6];
    LC_Zero_Value[7] = add2zero[7] - R_LC_Data[3];
#endif

    for(int i = 0; i < LC_NUM; i++) //단위 변환한 LoadCell값
    {
        if(i < 4)
        {

            if(LC_Zero_Value[i] > 10000) LC_Unit_Value[i] = 1;
            else LC_Unit_Value[i] = 0;
        }
        if(i >= 4)
        {
            if(LC_Zero_Value[i] > 10000) LC_Unit_Value[i] = 1;
            else LC_Unit_Value[i] = 0;
        }
    }


    if((LC_Unit_Value[0] || LC_Unit_Value[1] || LC_Unit_Value[2] || LC_Unit_Value[3]) && !(LC_Unit_Value[4] || LC_Unit_Value[5] || LC_Unit_Value[6] || LC_Unit_Value[7]))//((LC_Unit_Value[0] || LC_Unit_Value[2]) && !(LC_Unit_Value[5] || LC_Unit_Value[7]))
    {
      Right_Foot = false;
      Left_Foot = true;
      Both_Feet = false;
      LTC_Value = -1;
      cout<<"Left_Foot<"<<endl;
    }
    else if((LC_Unit_Value[4] || LC_Unit_Value[5] || LC_Unit_Value[6] || LC_Unit_Value[7]) && !(LC_Unit_Value[0] || LC_Unit_Value[1] || LC_Unit_Value[2] || LC_Unit_Value[3]))//((LC_Unit_Value[5] || LC_Unit_Value[7]) && !(LC_Unit_Value[0] || LC_Unit_Value[2]))
    {
      Left_Foot = false;
      Right_Foot = true;
      Both_Feet = false;
      LTC_Value = 1;
      cout<<"Right_Foot<"<<endl;
    }
    else if((LC_Unit_Value[0] || LC_Unit_Value[1] || LC_Unit_Value[2] || LC_Unit_Value[3]) && (LC_Unit_Value[4] || LC_Unit_Value[5] || LC_Unit_Value[6] || LC_Unit_Value[7]))
    {
        Both_Feet = true;
        Left_Foot = false;
        Right_Foot = false;
        LTC_Value = 0;
        cout<<"Both_Feet<"<<endl;
    }
    else if(LC_Zero_Value[0] < 0 && LC_Zero_Value[1] < 0 && LC_Zero_Value[2] < 0 && LC_Zero_Value[3] < 0 && LC_Zero_Value[4] < 0 && !LC_Zero_Value[5] && LC_Zero_Value[6] < 0 && LC_Zero_Value[7] < 0 )
    {
        Both_Feet = false;
        Left_Foot = false;
        Right_Foot = false;
        LTC_Value = 0;
        cout<<"None<"<<endl;
    }
    else
    {
        Both_Feet = true;
        Left_Foot = false;
        Right_Foot = false;
        LTC_Value = 0;
        cout<<"Both_Feet_v2<"<<endl;
    }
    /////////////////////real_robot_zmp_point///////////////////_foot x,y
    ///
    zmp.Right_Foot = Right_Foot;//support_leg
    zmp.Left_Foot = Left_Foot;//support_leg
    zmp.Both_Feet = Both_Feet;//support_leg

\
    ui.LC_Zero_Value_00->setText(QString::number(LC_Zero_Value[0]));
    ui.LC_Zero_Value_01->setText(QString::number(LC_Zero_Value[1]));
    ui.LC_Zero_Value_02->setText(QString::number(LC_Zero_Value[2]));
    ui.LC_Zero_Value_03->setText(QString::number(LC_Zero_Value[3]));

    ui.LC_Zero_Value_04->setText(QString::number(LC_Zero_Value[4]));
    ui.LC_Zero_Value_05->setText(QString::number(LC_Zero_Value[5]));
    ui.LC_Zero_Value_06->setText(QString::number(LC_Zero_Value[6]));
    ui.LC_Zero_Value_07->setText(QString::number(LC_Zero_Value[7]));

    ui.LC_Unit_Value_00->setText(QString::number(LC_Unit_Value[0]));
    ui.LC_Unit_Value_01->setText(QString::number(LC_Unit_Value[1]));
    ui.LC_Unit_Value_02->setText(QString::number(LC_Unit_Value[2]));
    ui.LC_Unit_Value_03->setText(QString::number(LC_Unit_Value[3]));

    ui.LC_Unit_Value_04->setText(QString::number(LC_Unit_Value[4]));
    ui.LC_Unit_Value_05->setText(QString::number(LC_Unit_Value[5]));
    ui.LC_Unit_Value_06->setText(QString::number(LC_Unit_Value[6]));
    ui.LC_Unit_Value_07->setText(QString::number(LC_Unit_Value[7]));

    qnode.Zmp_Pub.publish(zmp);
}

long int MainWindow::Low_pass_filter(long int initial_data)
{
    double Sampling_time = 0.09;//Load_cell data time (s)
    double Hz = 1/Sampling_time;
    double filtering_Hz = 10;//cutoff frequency 5~10Hz
    double lambda = 2*PI*filtering_Hz*Sampling_time;

    Output = (lambda/(1+lambda))*initial_data + (1/(1+lambda))*data_old;

    data_old = Output;
    return Output;
}

void MainWindow::makePlot()
{
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/30.0;
    static double lastPointKey = 0;

    if(key - lastPointKey > 0.0001)
    {
        ui.customPlot_LR->graph(0)->addData(key, LTC_Value);

        lastPointKey = key;
    }
    ui.customPlot_LR->xAxis->setRange(key,100,Qt::AlignRight);
    ui.customPlot_LR->replot();

    serial_cnt = 0;
}

void MainWindow::Plot_init()
{
    ui.customPlot_LR->addGraph();
    ui.customPlot_LR->graph(0)->setPen(QPen(Qt::red));
    ui.customPlot_LR->graph(0)->setAntialiasedFill(false);
    ui.customPlot_LR->setBackground(QColor(255,255,255));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    ui.customPlot_LR->xAxis->setTicker(timeTicker);
    ui.customPlot_LR->axisRect()->setupFullAxesBox();

    ui.customPlot_LR->xAxis->setTickLabelFont(QFont(QFont().family(),10));
    ui.customPlot_LR->yAxis->setTickLabelFont(QFont(QFont().family(),10));
    ui.customPlot_LR->xAxis->setBasePen(QPen(Qt::black));
    ui.customPlot_LR->yAxis->setTickPen(QPen(Qt::black));
    ui.customPlot_LR->xAxis->setTickLabelColor(Qt::black);
    ui.customPlot_LR->xAxis->setLabelColor(Qt::black);
    ui.customPlot_LR->xAxis->setLabel("Time(s)");
    ui.customPlot_LR->yAxis->setTickLabelColor(Qt::black);
    ui.customPlot_LR->yAxis->setLabelColor(Qt::black);
    ui.customPlot_LR->yAxis->setRange(-1.5,1.5);
    ui.customPlot_LR->xAxis2->setVisible(true);
    ui.customPlot_LR->yAxis->setVisible(true);
    ui.customPlot_LR->xAxis2->setTicks(true);
    ui.customPlot_LR->yAxis2->setTicks(true);
    ui.customPlot_LR->xAxis2->setTickLabels(true);
    ui.customPlot_LR->yAxis2->setTickLabels(true);
    timeTicker->setTimeFormat("%s");
}

int compare(const void *a, const void *b)
{
    const int* x = (int*)a;
    const int* y = (int*)b;

    if(*x > *y)
    {
        return 1;
    }
    else if(*x < *y)
    {
        return -1;
    }

    return 0;
}

void MainWindow::median(int data_1,int data_2,int data_3,int data_4,int data_5,int data_6,int data_7,int data_8)
{
    int median[8] = {0,};
    int median_array = median_cnt/2;

    int load_cell_median_buf[8][median_cnt] = {{0,},{0,},{0,},{0,},{0,},{0,},{0,}};
    int data_array[8] = {data_1,data_2,data_3,data_4,data_5,data_6,data_7,data_8};

    for(int i = 0; i < LC_NUM; i++)
    {
        for(int j = 0; j < median_cnt-1; j++)
        {
            load_cell_median_buffer[i][j] = load_cell_median_buffer[i][j+1];
        }

        load_cell_median_buffer[i][median_cnt-1] = data_array[i];
    }

    for(int i = 0; i < LC_NUM; i++)
    {
        for(int j = 0; j < median_cnt; j++)
        {
            load_cell_median_buf[i][j] = load_cell_median_buffer[i][j];
        }
    }

    for(int i = 0; i < LC_NUM; i ++)
    {
        qsort(load_cell_median_buf[i],median_cnt,sizeof(int),compare);
        median[i] = load_cell_median_buf[i][median_array];
    }

    for(int i = 0; i < LC_NUM; i++)
    {
        //        load_cell_Value__[i] = median[i];
    }
}

//MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/

////Gain : Zero_Gain_push___________________________________
void load_cell::MainWindow::on_ZG_Push_00_clicked()
{
    ui.LC_Zero_Gain_00->setText(ui.LC_Data_00->text());
    add2zero[0] = ui.LC_Zero_Gain_00->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_01_clicked()
{
    ui.LC_Zero_Gain_01->setText(ui.LC_Data_01->text());
    add2zero[1] = ui.LC_Zero_Gain_01->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_02_clicked()
{
    ui.LC_Zero_Gain_02->setText(ui.LC_Data_02->text());
    add2zero[2] = ui.LC_Zero_Gain_02->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_03_clicked()
{
    ui.LC_Zero_Gain_03->setText(ui.LC_Data_03->text());
    add2zero[3] = ui.LC_Zero_Gain_03->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_04_clicked()
{
    ui.LC_Zero_Gain_04->setText(ui.LC_Data_04->text());
    add2zero[4] = ui.LC_Zero_Gain_04->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_05_clicked()
{
    ui.LC_Zero_Gain_05->setText(ui.LC_Data_05->text());
    add2zero[5] = ui.LC_Zero_Gain_05->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_06_clicked()
{
    ui.LC_Zero_Gain_06->setText(ui.LC_Data_06->text());
    add2zero[6] = ui.LC_Zero_Gain_06->text().toLong();
}

void load_cell::MainWindow::on_ZG_Push_07_clicked()
{
    ui.LC_Zero_Gain_07->setText(ui.LC_Data_07->text());
    add2zero[7] = ui.LC_Zero_Gain_07->text().toLong();
}

void load_cell::MainWindow::on_ZG_Insert_Button_clicked()
{
    ui.LC_Zero_Gain_00->setText(ui.LC_Data_00->text());
    add2zero[0] = ui.LC_Zero_Gain_00->text().toLong();

    ui.LC_Zero_Gain_01->setText(ui.LC_Data_01->text());
    add2zero[1] = ui.LC_Zero_Gain_01->text().toLong();

    ui.LC_Zero_Gain_02->setText(ui.LC_Data_02->text());
    add2zero[2] = ui.LC_Zero_Gain_02->text().toLong();

    ui.LC_Zero_Gain_03->setText(ui.LC_Data_03->text());
    add2zero[3] = ui.LC_Zero_Gain_03->text().toLong();

    ui.LC_Zero_Gain_04->setText(ui.LC_Data_04->text());
    add2zero[4] = ui.LC_Zero_Gain_04->text().toLong();

    ui.LC_Zero_Gain_05->setText(ui.LC_Data_05->text());
    add2zero[5] = ui.LC_Zero_Gain_05->text().toLong();

    ui.LC_Zero_Gain_06->setText(ui.LC_Data_06->text());
    add2zero[6] = ui.LC_Zero_Gain_06->text().toLong();

    ui.LC_Zero_Gain_07->setText(ui.LC_Data_07->text());
    add2zero[7] = ui.LC_Zero_Gain_07->text().toLong();
}

//Gain : Zero_Gain
void load_cell::MainWindow::on_LC_Zero_Gain_00_textChanged(const QString &arg1)
{
    add2zero[0] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_01_textChanged(const QString &arg1)
{
    add2zero[1] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_02_textChanged(const QString &arg1)
{
    add2zero[2] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_03_textChanged(const QString &arg1)
{
    add2zero[3] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_04_textChanged(const QString &arg1)
{
    add2zero[4] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_05_textChanged(const QString &arg1)
{
    add2zero[5] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_06_textChanged(const QString &arg1)
{
    add2zero[6] = arg1.toLong();
}
void load_cell::MainWindow::on_LC_Zero_Gain_07_textChanged(const QString &arg1)
{
    add2zero[7] = arg1.toLong();
}
MainWindow::~MainWindow() {
    serial->close();
}

} // namespace load_cell


