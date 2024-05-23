/**
 * @file /include/mw_ahrsv1/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef EBIMU_V5_QNODE_HPP_
#define EBIMU_V5_QNODE_HPP_

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


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ebimu_v5 {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
        ros::Publisher Imu_pub;
	bool init();
	void run();


Q_SIGNALS:
        void rosShutdown();

private:
	int init_argc;
	char** init_argv;

};

}  // namespace EBIMU_V5

#endif /* EBIMU_V5_QNODE_HPP_ */
