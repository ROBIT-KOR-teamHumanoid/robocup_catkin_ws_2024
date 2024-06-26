/**
 * @file /include/gamecontroller/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef gamecontroller_QNODE_HPP_
#define gamecontroller_QNODE_HPP_

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

#include <msg_generate/robocupcontroller.h>
#include <msg_generate/game_control_data.h>
#include <msg_generate/game_control_return_data.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace gamecontroller {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
    QNode(int argc, char** argv );
    virtual ~QNode();
    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void run();

    msg_generate::game_control_data gameControlData;
    msg_generate::game_control_return_data gameControlReturnData;
    ros::Subscriber masterSub;
    ros::Publisher  gamecontrollerPub;

Q_SIGNALS:
    void rosShutdown();

private:
    int init_argc;
    char** init_argv;

    void masterCallback(const msg_generate::game_control_return_data::ConstPtr &msg);
};

}  // namespace gamecontroller

#endif /* gamecontroller_QNODE_HPP_ */









