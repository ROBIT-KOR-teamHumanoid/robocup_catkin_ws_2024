/**
 * @file /include/motion/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef motion_QNODE_HPP_
#define motion_QNODE_HPP_

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


#include "Motor_msg.h"
#include <msg_generate/Serial2LC_msg.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace motion {

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

    void LoadCell_Callback(const msg_generate::Serial2LC_msg::ConstPtr &msg);


Q_SIGNALS:
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;

};

}  // namespace motion

#endif /* motion_QNODE_HPP_ */
