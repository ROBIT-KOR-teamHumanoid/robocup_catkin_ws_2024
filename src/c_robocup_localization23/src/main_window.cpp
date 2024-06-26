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
#include "../include/c_robocup_localization23/main_window.hpp"
#include "/home/robit/catkin_ws/src/robot_config.h"
#define DEG2RAD (M_PI / 180)
#define PARTICLE_NUM 10000

extern ros::Subscriber imuSub;
extern ros::Subscriber visionSub;
extern ros::Subscriber coordinateSub;
extern ros::Subscriber vision_feature_Sub;
extern ros::Subscriber gamecontrolSub;
extern ros::Subscriber udp1Sub;
extern ros::Subscriber udp2Sub;
extern ros::Subscriber udp3Sub;
extern ros::Subscriber masterSub;

extern ros::Publisher localizationPub;
msg_generate::robocup_localization23 localizationMsg;

//For Objects
VISIONMSG visionMSG;
ROBOT robot0 = ROBOT();
ROBOT robot1 = ROBOT();
ROBOT robot2 = ROBOT();
ROBOT robot3 = ROBOT();
ROBOT robot4 = ROBOT();
BALL ball = BALL();
BALL ball1 = BALL();
BALL ball2 = BALL();
BALL ball3 = BALL();
BALL ball4 = BALL();
LINE Likelihood = LINE();
OBSTACLE obstacle = OBSTACLE();

//For gamecontrol
GAMEMSG gameMSG;

//For particle
ROBOT pt[PARTICLE_NUM];
float particle_range = 0.0;
struct MEASUREMENT
{
    int NUM;
    double WEIGHT;
};
MEASUREMENT measurement;
vector<MEASUREMENT> particle_weight;
double sort_return(MEASUREMENT x, MEASUREMENT y)
{
    return x.WEIGHT > y.WEIGHT;
}
int vision_data_cnt = 0;
int vision_data_size = 0;
int ago_point_cnt = 0;

//For print
int robot_sight_flag = 0;
int master_target_x = 0;
int master_target_y = 0;

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace c_robocup_localization23 {

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
    m_Timer->start(100);

    QString img_path = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/Map/2022_RoboCup_Field.png";
    QImage img(img_path);
    buf = QPixmap::fromImage(img);
    buf = buf.scaled(825, 600);

    scene = new QGraphicsScene(this);
    robot0.x = 550; robot0.y = 400;

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/
void c_robocup_localization23::MainWindow::main()
{
    //INIT
    setting();
    sel_ball();
    Print_Screen();
    publish_msg();
}
void c_robocup_localization23::MainWindow::sel_ball()
{
    if(visionMSG.Robot_2d_X != 0 || visionMSG.Robot_2d_Y != 0)
    {
        obstacle.x = robot0.x + (-1)*(visionMSG.Robot_2d_X / 10 * cos((robot0.z) * M_PI / 180) + visionMSG.Robot_2d_Y / 10 * sin((robot0.z) * M_PI / 180));
        obstacle.y = robot0.y + (visionMSG.Robot_2d_X / 10 * sin((robot0.z) * M_PI / 180) - visionMSG.Robot_2d_Y / 10 * cos((robot0.z) * M_PI / 180)) /*- 20*/;//sujong
    }
    else
    {
        obstacle.x = 0;
        obstacle.y = 0;
    }
    if(visionMSG.Ball_2d_X != 0 || visionMSG.Ball_2d_Y != 0)
    {
        ball.noballcnt = 0;
        ball.x = robot0.x + (-1)*(visionMSG.Ball_2d_X / 10 * cos((robot0.z) * M_PI / 180) + visionMSG.Ball_2d_Y / 10 * sin((robot0.z) * M_PI / 180));
        ball.y = robot0.y + (visionMSG.Ball_2d_X / 10 * sin((robot0.z) * M_PI / 180) - visionMSG.Ball_2d_Y / 10 * cos((robot0.z) * M_PI / 180));
        ball.speed_x = (visionMSG.Ball_speed_X) * cos((-1) * robot0.z * DEG2RAD) - (visionMSG.Ball_speed_Y) * sin((-1) * robot0.z * DEG2RAD);
        ball.speed_y = (visionMSG.Ball_speed_X) * sin((-1) * robot0.z * DEG2RAD) + (visionMSG.Ball_speed_Y) * cos((-1) * robot0.z * DEG2RAD);

    }
    else
    {
        ball.noballcnt += 1;
//        if(ball.noballcnt >= 100) *************************************************************************************change
//        {
//            ball.x = 0;
//            ball.y = 0;
//            ball.noballcnt = 500;
//        }
    }


    double min_d = visionMSG.Ball_D / 10;
    if(min_d == 0){min_d = 999999;}
    int min_i = 0;
    if(min_d > ball1.d){min_d = ball1.d; min_i = 1;}
    if(min_d > ball2.d){min_d = ball2.d; min_i = 2;}
    if(min_d > ball3.d){min_d = ball3.d; min_i = 3;}
    if(min_d > ball4.d){min_d = ball4.d; min_i = 4;}

    if(min_i != 0 && (ball.noballcnt == 0 || ball.noballcnt == 500))
    {
        if(min_i == 1)
        {
            ball.x = ball1.x;
            ball.y = ball1.y;
        }
        if(min_i == 2)
        {
            ball.x = ball2.x;
            ball.y = ball2.y;
        }
        if(min_i == 3)
        {
            ball.x = ball3.x;
            ball.y = ball3.y;
        }
        if(min_i == 4)
        {
            ball.x = ball4.x;
            ball.y = ball4.y;
        }
        ball.noballcnt = 50;
    }
}


//
void c_robocup_localization23::MainWindow::setting()
{
    if(setting_flag == 0)
    {
        String param = "";
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_1
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM1.txt";
        #endif
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_2
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM2.txt";
        #endif
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_3
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM3.txt";
        #endif
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_4
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM4.txt";
        #endif
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_5
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM5.txt";
        #endif
        #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_6
            param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM6.txt";
        #endif
        ifstream Last_Index_Num_IN(param);
        if (Last_Index_Num_IN.is_open()){
            Last_Index_Num_IN >> particle_range;
            Last_Index_Num_IN >> robot0.odom_fx;
            Last_Index_Num_IN >> robot0.odom_bx;
            Last_Index_Num_IN >> robot0.odom_ly;
            Last_Index_Num_IN >> robot0.odom_ry;
        }
        Last_Index_Num_IN.close();
        ui.particle_range_value->setValue(particle_range);
        ui.odom_fx_value->setValue(robot0.odom_fx);
        ui.odom_bx_value->setValue(robot0.odom_bx);
        ui.odom_ly_value->setValue(robot0.odom_ly);
        ui.odom_ry_value->setValue(robot0.odom_ry);
        setting_flag = 1;
    }

    particle_range = ui.particle_range_value->value();
    robot0.odom_fx = ui.odom_fx_value->value();
    robot0.odom_bx = ui.odom_bx_value->value();
    robot0.odom_ly = ui.odom_ly_value->value();
    robot0.odom_ry = ui.odom_ry_value->value();
}

void c_robocup_localization23::MainWindow::publish_msg()
{
    localizationMsg.Ball_X = ball.x;
    localizationMsg.Ball_Y = ball.y;
    localizationMsg.Ball_speed_X = ball.x + ball.speed_x * visionMSG.Ball_speed_level;
    localizationMsg.Ball_speed_Y = ball.y + ball.speed_y * visionMSG.Ball_speed_level;
    localizationMsg.Robot_X = robot0.x;
    localizationMsg.Robot_Y = robot0.y;
    localizationMsg.Obstacle_X = obstacle.x;
    localizationMsg.Obstacle_Y = obstacle.y;
    localizationPub.publish(localizationMsg);

    char TEXT[256];
    sprintf(TEXT, "BALL_X : %d", (int)localizationMsg.Ball_X); ui.BALL_X_value->setText(TEXT);
    sprintf(TEXT, "BALL_Y : %d", (int)localizationMsg.Ball_Y); ui.BALL_Y_value->setText(TEXT);
    sprintf(TEXT, "ROBOT_X : %d", (int)localizationMsg.Robot_X); ui.ROBOT_X_value->setText(TEXT);
    sprintf(TEXT, "ROBOT_Y : %d", (int)localizationMsg.Robot_Y); ui.ROBOT_Y_value->setText(TEXT);
}
void c_robocup_localization23::MainWindow::Print_Screen()
{
    //INIT
    if(scene){delete scene;}

    char TEXT[256];
    sprintf(TEXT, "IK_X : %d", (int)robot0.now_ik_param_x); ui.IK_X_value->setText(TEXT);
    sprintf(TEXT, "IK_Y : %d", (int)robot0.now_ik_param_y); ui.IK_Y_value->setText(TEXT);

    scene = new QGraphicsScene(this);
    ui.screen->setScene(scene);
    scene->addPixmap(buf);

    QBrush blueBrush(Qt::blue);
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QBrush yellowBrush(Qt::yellow);
    QBrush blackBrush(Qt::black);
    QPen grayPen(Qt::gray); grayPen.setWidth(2);
    QPen redPen(Qt::red); redPen.setWidth(2);
    QPen redPen3(Qt::red); redPen3.setWidth(3);
    QPen greenPen(Qt::green); greenPen.setWidth(2);
    QPen bluePen(Qt::blue); bluePen.setWidth(2);
    QPen blackPen(Qt::black); blackPen.setWidth(2);
    QPen blackPen3(Qt::black); blackPen3.setWidth(3);
    QPen LocalPen1(Qt::blue); LocalPen1.setWidth(5);
    QPen LocalPen2(Qt::green); LocalPen2.setWidth(5);
    QPen LocalPen3(Qt::yellow); LocalPen3.setWidth(5);
    QPen LocalPen4(Qt::red); LocalPen4.setWidth(5);
    QPen yellowPen(Qt::yellow); yellowPen.setWidth(3);
    QPen targetPen(Qt::red); targetPen.setWidth(3);
    QPen targetlinePen(Qt::gray); targetlinePen.setWidth(2);



    //PRINT PARTICLE
    if(false)
    {
        for(int i = 0; i < PARTICLE_NUM; i++)
        {
            scene->addLine(cvt_Print_xy(pt[i].x), cvt_Print_xy(pt[i].y), cvt_Print_xy(pt[i].x), cvt_Print_xy(pt[i].y), grayPen);
        }
    }

    //PRINT TIMESTAMP
    if(robot0.TIME_STAMP.size() > 0)
    {
        scene->addLine(cvt_Print_xy(robot0.x), cvt_Print_xy(robot0.y), cvt_Print_xy(robot0.TIME_STAMP[robot0.TIME_STAMP.size() - 1].X), cvt_Print_xy(robot0.TIME_STAMP[robot0.TIME_STAMP.size() - 1].Y), blackPen3);
        for(int i = 1; i < robot0.TIME_STAMP.size(); i++)
        {
            scene->addLine(cvt_Print_xy(robot0.TIME_STAMP[i - 1].X), cvt_Print_xy(robot0.TIME_STAMP[i - 1].Y), cvt_Print_xy(robot0.TIME_STAMP[i].X), cvt_Print_xy(robot0.TIME_STAMP[i].Y), blackPen3);
        }
    }


    //PRINT SIGHT
    //if(visionMSG.Scan_mode != 3){robot_sight_flag = 0; Likelihood.vision_point_vect.clear();}
    for(int i = 0; i < 27; i++)
    {
        if(Likelihood.Local_point_on_off[i] == 1)
        {
            scene->addEllipse(cvt_Print_xy(Likelihood.Local_point_x[i]) - 4, cvt_Print_xy(Likelihood.Local_point_y[i]) - 4, 8, 8, blackPen);
        }
    }
    //cout<<Likelihood.vision_point_vect.size()<<endl;
    for(int i = 0; i < Likelihood.vision_point_vect.size(); i++)
    {
        if(Likelihood.vision_point_vect[i].CONFIDENCE > 0.9)
        {
            scene->addLine(cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), LocalPen1);
        }
        else if(Likelihood.vision_point_vect[i].CONFIDENCE > 0.7)
        {
            scene->addLine(cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), LocalPen2);
        }
        else if(Likelihood.vision_point_vect[i].CONFIDENCE > 0.5)
        {
            scene->addLine(cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), LocalPen3);
        }
        else
        {
            scene->addLine(cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_X + Likelihood.vision_point_vect[i].POINT_VEC_X), cvt_Print_xy(Likelihood.vision_point_vect[i].STD_Y + Likelihood.vision_point_vect[i].POINT_VEC_Y), LocalPen4);
        }

    }
    if(Likelihood.vision_point_vect.size() != 0)
    {
        //cout<<Likelihood.CIRCLE_R<<endl;
        scene->addEllipse(cvt_Print_xy(Likelihood.CIRCLE_CENTER.x - Likelihood.CIRCLE_R), cvt_Print_xy(Likelihood.CIRCLE_CENTER.y - Likelihood.CIRCLE_R), cvt_Print_xy(Likelihood.CIRCLE_R * 2), cvt_Print_xy(Likelihood.CIRCLE_R * 2), blackPen);
        //scene->addLine(cvt_Print_xy(Likelihood.CIRCLE_CENTER.x), cvt_Print_xy(Likelihood.CIRCLE_CENTER.y), cvt_Print_xy(Likelihood.CIRCLE_CENTER.x), cvt_Print_xy(Likelihood.CIRCLE_CENTER.y), targetPen);
    }

    //PRINT MASTER TARGET
    if(master_target_x != 0 || master_target_y != 0)
    {
        scene->addLine(cvt_Print_xy(master_target_x) + 4, cvt_Print_xy(master_target_y), cvt_Print_xy(master_target_x) - 4, cvt_Print_xy(master_target_y), targetPen);
        scene->addLine(cvt_Print_xy(master_target_x), cvt_Print_xy(master_target_y) + 4, cvt_Print_xy(master_target_x), cvt_Print_xy(master_target_y) - 4, targetPen);
        scene->addLine(cvt_Print_xy(master_target_x) + 2, cvt_Print_xy(master_target_y) + 2, cvt_Print_xy(robot0.x), cvt_Print_xy(robot0.y), targetlinePen);
    }

    //PRINT ROBOT
    QPolygonF robot0_poly = create_Print_robot(robot0);
    if(robot1.state != 3 && robot2.state != 3 && robot3.state != 3 && robot4.state != 3 && (ball.x != 0 || ball.y != 0)){scene->addPolygon(robot0_poly, redPen3, blueBrush);}
    else {scene->addPolygon(robot0_poly, blackPen, blueBrush);}
    scene->addLine(cvt_Print_xy(robot0.x), cvt_Print_xy(robot0.y), cvt_Print_xy(robot0.x) + sin((-1)*robot0.z * DEG2RAD) * 10, cvt_Print_xy(robot0.y) - cos(robot0.z * DEG2RAD) * 10, blackPen3);

    //scene->addLine(cvt_Print_xy(robot0.x),cvt_Print_xy(robot0.y),cvt_Print_xy(robot0.x),cvt_Print_xy(robot0.y),yellowPen);

    if(robot1.x != 0 || robot1.y != 0)
    {
        QPolygonF robot1_poly = create_Print_robot(robot1);

        if(robot1.state == 3){scene->addPolygon(robot1_poly, redPen3, redBrush);}
        else {scene->addPolygon(robot1_poly, blackPen, redBrush);}
        scene->addLine(cvt_Print_xy(robot1.x), cvt_Print_xy(robot1.y), cvt_Print_xy(robot1.x) + sin((-1)*robot1.z * DEG2RAD) * 10, cvt_Print_xy(robot1.y) - cos(robot1.z * DEG2RAD) * 10, blackPen3);
    }
    if(robot2.x != 0 || robot2.y != 0)
    {
        QPolygonF robot2_poly = create_Print_robot(robot2);
        if(robot2.state == 3){scene->addPolygon(robot2_poly, redPen3, greenBrush);}
        else {scene->addPolygon(robot2_poly, blackPen, greenBrush);}
        scene->addLine(cvt_Print_xy(robot2.x), cvt_Print_xy(robot2.y), cvt_Print_xy(robot2.x) + sin((-1)*robot2.z * DEG2RAD) * 10, cvt_Print_xy(robot2.y) - cos(robot2.z * DEG2RAD) * 10, blackPen3);
    }
    if(robot3.x != 0 || robot3.y != 0)
    {
        QPolygonF robot3_poly = create_Print_robot(robot3);
        if(robot3.state == 3){scene->addPolygon(robot3_poly, redPen3, yellowBrush);}
        else {scene->addPolygon(robot3_poly, blackPen, yellowBrush);}
        scene->addLine(cvt_Print_xy(robot3.x), cvt_Print_xy(robot3.y), cvt_Print_xy(robot3.x) + sin((-1)*robot3.z * DEG2RAD) * 10, cvt_Print_xy(robot3.y) - cos(robot3.z * DEG2RAD) * 10, blackPen3);
    }
    if(robot4.x != 0 || robot4.y != 0)
    {
        QPolygonF robot4_poly = create_Print_robot(robot4);
        if(robot4.state == 3){scene->addPolygon(robot4_poly, redPen3, blackBrush);}
        else {scene->addPolygon(robot4_poly, blackPen, blackBrush);}
        scene->addLine(cvt_Print_xy(robot4.x), cvt_Print_xy(robot4.y), cvt_Print_xy(robot4.x) + sin((-1)*robot4.z * DEG2RAD) * 10, cvt_Print_xy(robot4.y) - cos(robot4.z * DEG2RAD) * 10, blackPen3);
    }

    //print obstacle
    if(obstacle.x != 0 && obstacle.y != 0)
    {
        scene->addEllipse(cvt_Print_xy(obstacle.x) - 5, cvt_Print_xy(obstacle.y) - 5, 11, 11, blackPen, blackBrush);
    }

    //PRINT BALL
    if(visionMSG.Ball_2d_X != 0 || visionMSG.Ball_2d_Y != 0)
    {
        scene->addEllipse(cvt_Print_xy(ball.x) - 3, cvt_Print_xy(ball.y) - 3, 7, 7, blackPen, redBrush);
        scene->addLine(cvt_Print_xy(ball.x), cvt_Print_xy(ball.y), cvt_Print_xy(ball.x + ball.speed_x * visionMSG.Ball_speed_level), cvt_Print_xy(ball.y + ball.speed_y * visionMSG.Ball_speed_level), blackPen);
    }
    else
    {
        if(ball.x != 0 || ball.y != 0)
        {
            scene->addEllipse(cvt_Print_xy(ball.x) - 3, cvt_Print_xy(ball.y) - 3, 7, 7, blackPen, yellowBrush);
        }
    }




}
void c_robocup_localization23::MainWindow::mouseReleaseEvent(QMouseEvent * e)
{
    QPointF point = mapToParent(e->pos());
    QPoint position = mapToGlobal(QPoint(21, 60));
    if(set_robot_flag)
    {
        robot0.x = (point.x() - position.x()) * 100 / 75;
        robot0.y = (point.y() - position.y()) * 100 / 75;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
        set_robot_flag = 0;
        robot0.TIME_STAMP.clear();
        master_target_x = 0; master_target_y = 0;
    }
    if(set_ball_flag)
    {
        ball.x = (point.x() - position.x()) * 100 / 75;
        ball.y = (point.y() - position.y()) * 100 / 75;
        ball.noballcnt = 0;
        set_ball_flag = 0;
    }
}

void c_robocup_localization23::MainWindow::mouseMoveEvent(QMouseEvent * e)
{
  QPointF point = mapToParent(e->pos());
  QPoint position = mapToGlobal(QPoint(21, 60));
  if(set_robot_flag)
  {
      robot0.x = (point.x() - position.x()) * 100 / 75;
      robot0.y = (point.y() - position.y()) * 100 / 75;
      robot0.TIME_STAMP.clear();
      master_target_x = 0; master_target_y = 0;
  }
  if(set_ball_flag)
  {
      ball.x = (point.x() - position.x()) * 100 / 75;
      ball.y = (point.y() - position.y()) * 100 / 75;
      ball.noballcnt = 0;
  }
}

QPolygonF c_robocup_localization23::MainWindow::create_Print_robot(ROBOT robot)
{
    float zoom = 0.75;
    float Robot_model_x = robot.x * zoom;
    float Robot_model_y = robot.y * zoom;
    float Robot_model_z = robot.z + 90;

    float robot_shape_1_x = -12 * zoom, robot_shape_1_y = 9 * zoom, robot_shape_2_x = 12 * zoom, robot_shape_2_y = 9 * zoom, robot_shape_3_x = -12 * zoom, robot_shape_3_y = -9 * zoom, robot_shape_4_x = 12 * zoom, robot_shape_4_y = -9 * zoom;

    QPolygonF Robot_model_poly;
    Robot_model_poly << QPointF((robot_shape_1_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_1_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_1_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_1_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y)
         << QPointF((robot_shape_2_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_2_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_2_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_2_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y)
         << QPointF((robot_shape_4_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_4_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_4_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_4_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y)
         << QPointF((robot_shape_3_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_3_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_3_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_3_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y);

    return Robot_model_poly;
}

int c_robocup_localization23::MainWindow::cvt_Print_xy(float target)
{
    float zoom = 0.75;
    target *= zoom;
    return (int)target;
}
void c_robocup_localization23::QNode::visionfeatureCallback(const msg_generate::robocup_vision23_feature::ConstPtr &msg)
{

    if(Likelihood.vision_point_vect.size() > 100)
    {
//        if(vision_data_size / vision_data_cnt < 2)
//        {
//            for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, 20);}
//            cout<<"SMALL"<<endl;
//        }

        for(int i = 0; i < PARTICLE_NUM; i++)
        {
            Likelihood.set_circle(robot0.z, Likelihood.vision_point_vect);
            measurement.NUM = i;
            measurement.WEIGHT = Likelihood.sence(pt[i].x, pt[i].y, robot0.x, robot0.y, Likelihood.vision_point_vect);
            double dis = sqrt(pow(pt[i].x -robot0.x, 2) + pow(pt[i].y -robot0.y, 2));
            dis /= particle_range;
            if(dis < 1){dis = 1;}
            measurement.WEIGHT /= dis;
            particle_weight.push_back(measurement);
        }
        sort(particle_weight.begin(), particle_weight.end(), sort_return);

        cout<<particle_weight[0].WEIGHT<<endl;

        if(vision_data_size / vision_data_cnt > 1 && particle_weight[0].WEIGHT > 30)
        {
            cout<<"MATCHING!!"<<endl;
            robot0.x = pt[particle_weight[0].NUM].x; //(pt[particle_weight[0].NUM].x + pt[particle_weight[1].NUM].x + pt[particle_weight[2].NUM].x) / 3;
            robot0.y = pt[particle_weight[0].NUM].y; //(pt[particle_weight[0].NUM].y + pt[particle_weight[1].NUM].y + pt[particle_weight[2].NUM].y) / 3;
        }
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}

        Likelihood.check_local_point(50, robot0.z, Likelihood.vision_point_vect);

        //robot_sight_flag = 0;
        particle_weight.clear();
        Likelihood.vision_point_vect.clear();
        vision_data_cnt = 0;
        vision_data_size = 0;

        ago_point_cnt = 0;
        for(int i = 0; i < 27; i++)
        {
            if(Likelihood.Local_point_check[i] == 1)
            {
                Likelihood.vision_point.CONFIDENCE = 0.1;
                Likelihood.vision_point.DISTANCE = 1;
                Likelihood.vision_point.POINT_VEC_X = Likelihood.Local_point_x[i] - robot0.x;
                Likelihood.vision_point.POINT_VEC_Y = Likelihood.Local_point_y[i] - robot0.y;
                Likelihood.vision_point.STD_X = robot0.x;
                Likelihood.vision_point.STD_Y = robot0.y;
                Likelihood.vision_point_vect.push_back(Likelihood.vision_point);
                ago_point_cnt += 1;
            }

        }





    }

    for(int i = 0; i < msg->CONFIDENCE.size(); i++)
    {
        vision_data_cnt += 1;
        vision_data_size += msg->CONFIDENCE.size();
        Likelihood.vision_point.CONFIDENCE = msg->CONFIDENCE[i];
        Likelihood.vision_point.DISTANCE = msg->DISTANCE[i];
        Likelihood.vision_point.POINT_VEC_X = (-1)*(msg->POINT_VEC_X[i] / 10 * cos((robot0.z) * M_PI / 180) + msg->POINT_VEC_Y[i] / 10 * sin((robot0.z) * M_PI / 180));
        Likelihood.vision_point.POINT_VEC_Y = (msg->POINT_VEC_X[i] / 10 * sin((robot0.z) * M_PI / 180) - msg->POINT_VEC_Y[i] / 10 * cos((robot0.z) * M_PI / 180));
        Likelihood.vision_point.STD_X = robot0.x;
        Likelihood.vision_point.STD_Y = robot0.y;
        Likelihood.vision_point_vect.push_back(Likelihood.vision_point);

        Likelihood.set_circle(robot0.z, Likelihood.vision_point_vect);
        Likelihood.on_local_point(robot0.x, robot0.y, robot0.x, robot0.y);
    }



}
void c_robocup_localization23::QNode::imuCallback(const msg_generate::imu_msg::ConstPtr &msg)
{
    robot0.z = msg->yaw;
}
void c_robocup_localization23::QNode::visionCallback(const msg_generate::robocup_vision23::ConstPtr &msg)
{
    visionMSG.Ball_cam_X = msg->Ball_cam_X;
    visionMSG.Ball_cam_Y = msg->Ball_cam_Y;
    visionMSG.Ball_2d_X = msg->Ball_2d_X;
    visionMSG.Ball_2d_Y = msg->Ball_2d_Y;
    visionMSG.Ball_D = msg->Ball_D;
    visionMSG.PAN = msg->PAN;
    visionMSG.TILT = msg->TILT;
    visionMSG.Ball_speed_X = msg->Ball_speed_X;
    visionMSG.Ball_speed_Y = msg->Ball_speed_Y;
    visionMSG.Robot_2d_X = msg->Robot_2d_X;
    visionMSG.Robot_2d_Y = msg->Robot_2d_Y;
    visionMSG.Ball_speed_level = msg->Ball_speed_level;
    visionMSG.Scan_mode = msg->Scan_mode;
    if(visionMSG.Ball_speed_level > 150){visionMSG.Ball_speed_level = 150;}



}

void c_robocup_localization23::QNode::coordinateCallback(const msg_generate::ikcoordinate_msg::ConstPtr &msg)
{
    double Xmoved = msg->X;
    double Ymoved = msg->Y;
    robot0.move(Xmoved, Ymoved);
    for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
}

void c_robocup_localization23::QNode::gamecontrolCallback(const msg_generate::game_control_data::ConstPtr &msg)
{
    gameMSG.mySide = msg->mySide;
    gameMSG.penalty = msg->penalty;
    gameMSG.position = msg->position;
    gameMSG.robotNum = msg->robotNum;
    if(gameMSG.penalty != 0)
    {
        if(gameMSG.mySide)
        {
            if(gameMSG.position == 1){robot0.x = 900; robot0.y = 700;}
            else {robot0.x = 800; robot0.y = 700;}
            for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
        }
        else
        {
            if(gameMSG.position == 1){robot0.x = 200; robot0.y = 700;}
            else {robot0.x = 300; robot0.y = 700;}
            for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
        }
        robot0.TIME_STAMP.clear();
        master_target_x = 0; master_target_y = 0;
    }
}

void c_robocup_localization23::QNode::udpCallback(const msg_generate::localv2_msg::ConstPtr &msg)
{
    if(msg->robot_num == 1)
    {
        robot1.x = msg->local_x;
        robot1.y = msg->local_y;
        robot1.z = msg->local_yaw;
        robot1.state = msg->robot_case;

        ball1.x = msg->ball_x;
        ball1.y = msg->ball_y;
        ball1.d = sqrt(pow(msg->local_x - msg->ball_x, 2) + pow(msg->local_y - msg->ball_y, 2));
    }
    if(msg->robot_num == 2)
    {
        robot2.x = msg->local_x;
        robot2.y = msg->local_y;
        robot2.z = msg->local_yaw;
        robot2.state = msg->robot_case;

        ball2.x = msg->ball_x;
        ball2.y = msg->ball_y;
        ball2.d = sqrt(pow(msg->local_x - msg->ball_x, 2) + pow(msg->local_y - msg->ball_y, 2));
    }
    if(msg->robot_num == 3)
    {
        robot3.x = msg->local_x;
        robot3.y = msg->local_y;
        robot3.z = msg->local_yaw;
        robot3.state = msg->robot_case;

        ball3.x = msg->ball_x;
        ball3.y = msg->ball_y;
        ball3.d = sqrt(pow(msg->local_x - msg->ball_x, 2) + pow(msg->local_y - msg->ball_y, 2));
    }
    if(msg->robot_num == 4)
    {
        robot4.x = msg->local_x;
        robot4.y = msg->local_y;
        robot4.z = msg->local_yaw;
        robot4.state = msg->robot_case;

        ball4.x = msg->ball_x;
        ball4.y = msg->ball_y;
        ball4.d = sqrt(pow(msg->local_x - msg->ball_x, 2) + pow(msg->local_y - msg->ball_y, 2));
    }
}
void c_robocup_localization23::QNode::masterCallback(const msg_generate::master2localization23::ConstPtr &msg)
{
    master_target_x = msg->target_x;
    master_target_y = msg->target_y;

    if(msg->mf_robot_x != 0 || msg->mf_robot_y != 0){
        robot0.x = msg->mf_robot_x;
        robot0.y = msg->mf_robot_y;
    }
    if(msg->mf_ball_x != 0 || msg->mf_ball_y != 0){
        ball.x = msg->mf_ball_x;
        ball.y = msg->mf_ball_y;
    }

    cout<<"robot 0 : "<<robot0.x<<robot0.y<<endl;
    cout<<"ballxy : "<<ball.x<<ball.y<<endl;
}

void c_robocup_localization23::MainWindow::on_btn_free_set_clicked()
{
    set_robot_flag = 1;
}
void c_robocup_localization23::MainWindow::on_btn_objects_save_clicked()
{
    String param = "";
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_1
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM1.txt";
    #endif
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_2
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM2.txt";
    #endif
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_3
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM3.txt";
    #endif
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_4
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM4.txt";
    #endif
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_5
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM5.txt";
    #endif
    #ifdef ROBIT_HUMANOID_ROBOT_NUMBER_6
        param = "/home/robit/catkin_ws/src/c_robocup_localization23/resources/param/PARAM6.txt";
    #endif
    ofstream Last_Index_Num_OUT(param);
    if(Last_Index_Num_OUT.is_open()){
        Last_Index_Num_OUT << particle_range << endl;
        Last_Index_Num_OUT << robot0.odom_fx << endl;
        Last_Index_Num_OUT << robot0.odom_bx << endl;
        Last_Index_Num_OUT << robot0.odom_ly << endl;
        Last_Index_Num_OUT << robot0.odom_ry << endl;
    }
    Last_Index_Num_OUT.close();
}
void c_robocup_localization23::MainWindow::on_btn_set_1_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 630;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 200;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_2_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 800;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 300;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_3_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 900;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 470;
        robot0.y = 100;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_4_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 630;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 200;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_5_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 800;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 300;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_6_clicked()
{
    if(gameMSG.mySide)
    {
        robot0.x = 900;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        robot0.x = 470;
        robot0.y = 700;
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_set_auto_clicked()
{
    if(gameMSG.mySide)
    {
        if(gameMSG.robotNum == 1)
        {
            robot0.x = 630;
            robot0.y = 100;
        }
        if(gameMSG.robotNum == 2)
        {
            robot0.x = 800;
            robot0.y = 100;
        }
        if(gameMSG.robotNum == 3)
        {
            robot0.x = 630;
            robot0.y = 700;
        }
        if(gameMSG.robotNum == 4)
        {
            robot0.x = 900;
            robot0.y = 700;
        }
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    else
    {
        if(gameMSG.robotNum == 1)
        {
            robot0.x = 470;
            robot0.y = 700;
        }
        if(gameMSG.robotNum == 2)
        {
            robot0.x = 300;
            robot0.y = 700;
        }
        if(gameMSG.robotNum == 3)
        {
            robot0.x = 470;
            robot0.y = 100;
        }
        if(gameMSG.robotNum == 4)
        {
            robot0.x = 200;
            robot0.y = 100;
        }
        for(int i = 0; i < PARTICLE_NUM; i++){pt[i].random_point(robot0.x, robot0.y, particle_range);}
    }
    robot0.TIME_STAMP.clear();
    master_target_x = 0; master_target_y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_ball_set_clicked()
{
    set_ball_flag = 1;
}
void c_robocup_localization23::MainWindow::on_btn_ball_del_clicked()
{
    ball.x = 0;
    ball.y = 0;
}
void c_robocup_localization23::MainWindow::on_btn_test_clicked()
{
    robot1.x = 0;
    robot1.y = 0;
    robot1.z = 0;

    ball1.x = 0;
    ball1.y = 0;
    ball1.d = 999999;

    robot2.x = 0;
    robot2.y = 0;
    robot2.z = 0;

    ball2.x = 0;
    ball2.y = 0;
    ball2.d = 999999;

    robot3.x = 0;
    robot3.y = 0;
    robot3.z = 0;

    ball3.x = 0;
    ball3.y = 0;
    ball3.d = 999999;

    robot4.x = 0;
    robot4.y = 0;
    robot4.z = 0;

    ball4.x = 0;
    ball4.y = 0;
    ball4.d = 999999;

    Likelihood.vision_point_vect.clear();
}


}  // namespace c_robocup_localization23

