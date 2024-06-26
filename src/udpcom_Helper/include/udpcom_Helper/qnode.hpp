/**
 * @file /include/udpcom_Helper/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef udpcom_Helper_QNODE_HPP_
#define udpcom_Helper_QNODE_HPP_

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

#include <msg_generate/udp_msg.h>
#include <msg_generate/udp_order.h>
#include <msg_generate/localv2_msg.h>
#include <msg_generate/robocupvision.h>
#include <msg_generate/udp_msg.h>
#include <msg_generate/robocupcontroller.h>
#include <msg_generate/udp_msg_TC_Helper.h>
#include <msg_generate/udp_msg_TC_Kicker.h>

#include <msg_generate/udp_helper_msg.h>
#include <msg_generate/udp_kicker_msg.h>
#include <msg_generate/game_control_data.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace udpcom_Helper {

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

        ros::Subscriber gamecon_sub;
        ros::Subscriber udp_dataSub;
        ros::Subscriber vision_Sub;
        ros::Subscriber master2udp_sub;

        ros::Publisher udp_RB1_pub;
        ros::Publisher udp_RB2_pub;
        ros::Publisher udp_RB_K_pub;
        ros::Publisher udp_RB_H_pub;

        ros::Subscriber udpRhSub;

        ros::Publisher udp2Hmpub;
        ros::Subscriber Hm2udpsub;

        int robot_X_order = 0;
        int robot_Y_order = 0;
        int robot_X=0;
        int robot_Y=0;
        int robot_Yaw=0;
        int ball_X = 0;
        int ball_Y = 0;
        int ball_D = 0;
        int ball_T = 0;
        int robot_ik_X_order=0;
        int robot_ik_Y_order=0;
        int robot_ik_Yaw_order=0;

        int robot_Num = 1;
        int past_robot_Num = 1;
        int robot_case = 0;
        int robot_Pan = 0;


Q_SIGNALS:
    void rosShutdown();
    void getUdpdata();
    void getrobotNum();

private:
	int init_argc;
	char** init_argv;
        void udpDataCallback(const msg_generate::localv2_msg::ConstPtr& msg);
//        void gameconCallback(const msg_generate::robocupcontroller::ConstPtr& msg);
        void gameconCallback(const msg_generate::game_control_data::ConstPtr& msg);
        void visionCallback(const msg_generate::robocupvision::ConstPtr& msg);
        void master2udpCallback(const msg_generate::udp_msg::ConstPtr& msg);

        //void udpRhCallback(const msg_generate::udp_msg_TC_Helper::ConstPtr &msg);

        void master2HudpCallback(const msg_generate::udp_helper_msg::ConstPtr &msg);

};

}  // namespace udpcom_Helper

#endif /* udpcom_Helper_QNODE_HPP_ */
