/**
 * @file /include/ebimu_test/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef ebimu_test_QNODE_HPP_
#define ebimu_test_QNODE_HPP_

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
#include <msg_generate/imu_msg.h>
#include <msg_generate/ik_msg.h>
#include <msg_generate/pid_tuning.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ebimu_test {

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

    ros::Subscriber ik_sub;
    ros::Publisher imu_pub;
    ros::Publisher pid_pub;

    int walk_flag;
    int robot_yaw;

Q_SIGNALS:
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;

    void ikCallback(const msg_generate::ik_msg::ConstPtr &msg);
};

}  // namespace ebimu_test

#endif /* ebimu_test_QNODE_HPP_ */
