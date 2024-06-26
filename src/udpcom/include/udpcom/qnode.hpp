/**
 * @file /include/udpcom/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef udpcom_QNODE_HPP_
#define udpcom_QNODE_HPP_

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

#include <msg_generate/robocup24_master2udp.h>
#include <msg_generate/localv2_msg.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom {

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

    ros::Subscriber udp_dataSub;

    ros::Publisher udp_RB1_pub;
    ros::Publisher udp_RB2_pub;
    ros::Publisher udp_RB3_pub;
    ros::Publisher udp_RB4_pub;

    int robot_num = 0;
    int robot_case = 0;
    int robot_coor_x = 0;
    int robot_coor_y = 0;
    int robot_imu_yaw = 0;
    int ball_coor_x = 0;
    int ball_coor_y = 0;
    int ball_dist = 0;
    int ball_theta = 0;
    int myTeam = 0;

Q_SIGNALS:
    void rosShutdown();
    void getUdpdata();
    void getrobotNum();


private:
    int init_argc;
    char** init_argv;

    void udpDataCallback(const msg_generate::robocup24_master2udp::ConstPtr& msg);
};

}  // namespace udpcom

#endif /* udpcom_QNODE_HPP_ */
