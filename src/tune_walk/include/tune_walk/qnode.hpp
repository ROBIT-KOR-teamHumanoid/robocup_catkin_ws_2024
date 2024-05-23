/**
 * @file /include/tune_walk/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef tune_walk_QNODE_HPP_
#define tune_walk_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

//Msg
#include <msg_generate/tune2walk.h>
#include <msg_generate/imu_msg.h>
#include <msg_generate/zmp_msg.h>
#include <msg_generate/walk_pattern.h>
#include <msg_generate/Motor_msg.h>
#include <msg_generate/Landing_Time_Control.h>






/*****************************************************************************
** Namespaces
*****************************************************************************/
using namespace std;
namespace tune_walk {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	void run();
    msg_generate::Landing_Time_Control Landing_info;

Q_SIGNALS:

    void rosShutdown();
    void Landing_callback();
    void recvImu();

private:
	int init_argc;
	char** init_argv;

        ros::Subscriber imuSub;
        ros::Subscriber zmpSub;
        ros::Subscriber walkpatternSub;
        void zmpCallback(const msg_generate::zmp_msg::ConstPtr&);
        void imuCallback(const msg_generate::imu_msg::ConstPtr&);
        void tune2walkCallback(const msg_generate::tune2walk::ConstPtr &msg);
        void walkpatternCallback(const msg_generate::walk_pattern::ConstPtr &msg);
        void LandingCallback(const msg_generate::Landing_Time_Control::ConstPtr &msg);
};

}  // namespace tune_walk

#endif /* tune_walk_QNODE_HPP_ */
