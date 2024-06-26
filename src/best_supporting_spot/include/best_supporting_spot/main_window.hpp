/**
 * @file /include/best_supporting_spot/main_window.hpp
 *
 * @brief Qt based gui for best_supporting_spot.
 *
 * @date November 2010
 **/
#ifndef best_supporting_spot_MAIN_WINDOW_H
#define best_supporting_spot_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include <QGraphicsScene>
#include <QPolygon>
#include "best_supporting_spot/bestsupportspotmaker.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace best_supporting_spot {

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


  QPixmap buf;
  QGraphicsScene *scene;



  struct ROBOT
  {
    int     x;
    int     y;
    double  z;

  };

   void printMap();


  void datacopy();

  int cvt_Print_xy(float target);
  QPolygonF create_Print_robot(ROBOT robot);

public Q_SLOTS:

  void main();
  void mouseReleaseEvent(QMouseEvent * e);
  void mouseMoveEvent(QMouseEvent * e);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
  ROBOT robot;
  ROBOT ball;
  QTimer* m_Timer;


};

}  // namespace best_supporting_spot

#endif // best_supporting_spot_MAIN_WINDOW_H
