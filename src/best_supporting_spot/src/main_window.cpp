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
#include "../include/best_supporting_spot/main_window.hpp"
#include "bestsupportspotmaker.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/


BestSupportSpotMaker maker = BestSupportSpotMaker();




namespace best_supporting_spot {

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

    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(main()));
    m_Timer->start(100);


    QString img_path = "/home/robit/catkin_ws/src/best_supporting_spot/resources/Map/Field.png";
    QImage img(img_path); //QString 변수를 이용한 QImage 변수
    buf = QPixmap::fromImage(img);//QPixmap을 저장하는 버퍼
    buf = buf.scaled(825, 600);//버퍼 리스케일링

    scene = new QGraphicsScene(this);

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/


void best_supporting_spot::MainWindow::main()
{
  printMap();

}


void best_supporting_spot::MainWindow::printMap()
{

  cout<<"print!!"<<endl;
  scene = new QGraphicsScene(this);
  ui.screen->setScene(scene);
  scene->addPixmap(buf);



}
void best_supporting_spot::MainWindow::mouseReleaseEvent(QMouseEvent * e)
{
    //PRE CONDITION : mouseEvent, set_robot_flag, set_ball_flag
    //POST CONDITION : robot0.n, ball.n master_target_n,
    //purpose : set_object_flag가 활성화 되있고, 마우스 클릭 이벤트가 적용 시 해당 object를 마우스 위치로 이동 & 이동한 위치에 파티클 생성

    QPointF point = mapToParent(e->pos());
    QPoint position = mapToGlobal(QPoint(21, 60));

        ball.x = (point.x() - position.x()) * 100 / 75;
        ball.y = (point.y() - position.y()) * 100 / 75;



}

void best_supporting_spot::MainWindow::mouseMoveEvent(QMouseEvent * e)
{
    //PRE CONDITION : mouseEvent, set_robot_flag, set_ball_flag
    //POST CONDITION : robot0.n, ball.n master_target_n,
    //purpose : set_object_flag가 활성화 되있고, 마우스 이동 이벤트가 적용 시 해당 object를 마우스 위치로 이동 & 이동한 위치에 파티클 생성
  QPointF point = mapToParent(e->pos());
  QPoint position = mapToGlobal(QPoint(21, 60));

      ball.x = (point.x() - position.x()) * 100 / 75;
      ball.y = (point.y() - position.y()) * 100 / 75;


}

QPolygonF best_supporting_spot::MainWindow::create_Print_robot(ROBOT robot)
{
    //PRE CONDITION : robot.n, zoom(0.75)
    //POST CONDITION : Robot_model_poly
    //purpose : 로봇의 x, y, z좌표에 zoom값을 곱한 후 해당 값에 의한 폴리곤 생성

    float zoom = 0.75;
    float Robot_model_x = robot.x * zoom;
    float Robot_model_y = robot.y * zoom;
    float Robot_model_z = robot.z + 90;

    float robot_shape_1_x = -12 * zoom, robot_shape_1_y = 9 * zoom, robot_shape_2_x = 12 * zoom, robot_shape_2_y = 9 * zoom, robot_shape_3_x = -12 * zoom, robot_shape_3_y = -9 * zoom, robot_shape_4_x = 12 * zoom, robot_shape_4_y = -9 * zoom;

    QPolygonF Robot_model_poly;
    Robot_model_poly << QPointF((robot_shape_1_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_1_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_1_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_1_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y)
         << QPointF((robot_shape_2_x)*sin(Robot_model_z*M_PI/180)   -   (robot_shape_2_y)*cos(Robot_model_z*M_PI/180)   +   Robot_model_x                   ,                   (robot_shape_2_x)*cos(Robot_model_z*M_PI/180)   +   (robot_shape_2_y)*sin(Robot_model_z*M_PI/180)   +   Robot_model_y)
         << QPointF((robot_shape_4_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_4_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_4_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_4_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y)
         << QPointF((robot_shape_3_x)*sin(Robot_model_z*M_PI/180)-(robot_shape_3_y)*cos(Robot_model_z*M_PI/180)+Robot_model_x, (robot_shape_3_x)*cos(Robot_model_z*M_PI/180)+(robot_shape_3_y)*sin(Robot_model_z*M_PI/180)+Robot_model_y);

    return Robot_model_poly;
}

int best_supporting_spot::MainWindow::cvt_Print_xy(float target)
{
    //PRE CONDITION : target
    //POST CONDITION : tartet * 0.75
    //purpose : target에 0.75를 곱한 값을 리턴

    float zoom = 0.75;
    target *= zoom;
    return (int)target;
}


void best_supporting_spot::MainWindow::datacopy()
{


//  qnode.local.Ball_X;
//  qnode.local.Ball_Y;
//  qnode.local.Robot_X;
//  qnode.local.Robot_Y;
//  qnode.local.Ball_speed_X;
//  qnode.local.Ball_speed_Y;

//  qnode.local.Obstacle0_X;
//  qnode.local.Obstacle0_Y;
//  qnode.local.Obstacle1_X;
//  qnode.local.Obstacle1_Y;
//  qnode.local.Obstacle2_X;
//  qnode.local.Obstacle2_Y;
//  qnode.local.Obstacle3_X;
//  qnode.local.Obstacle3_Y;



}

}  // namespace best_supporting_spot

