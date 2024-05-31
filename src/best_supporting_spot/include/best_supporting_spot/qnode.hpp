/**
 * @file /include/best_supporting_spot/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef best_supporting_spot_QNODE_HPP_
#define best_supporting_spot_QNODE_HPP_

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

//ebimu_v5
#include <msg_generate/imu_msg.h>

//vision
#include <msg_generate/robocup_vision23.h>

//localization_v2
#include <msg_generate/robocup_localization23.h>
#include <msg_generate/master2localization23.h>

//ikwalk
#include <msg_generate/ik_msg.h>
#include <msg_generate/ikend_msg.h>

//udp_com
#include <msg_generate/robocup23_master2udp.h>
#include <msg_generate/localv2_msg.h>

//gamecontroller
#include <msg_generate/game_control_data.h>



/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace best_supporting_spot {

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

        ros::Subscriber imuSub;
        ros::Subscriber localSub;
        ros::Subscriber visionSub;
        ros::Subscriber ikSub;
        ros::Subscriber udpR1Sub;
        ros::Subscriber udpR2Sub;
        ros::Subscriber udpR3Sub;
        ros::Subscriber gamecontrolSub;


        msg_generate::imu_msg imu;
      //    msg_generate::localv2_msg local;
        msg_generate::robocup_localization23 local;
        msg_generate::robocup_vision23 vision;
        msg_generate::ik_msg ik;
        msg_generate::ikend_msg ikEnd;
        msg_generate::localv2_msg udp[4];
        msg_generate::game_control_data gameControlData;
        void imuCallback(const msg_generate::imu_msg::ConstPtr &msg);
        void localCallback(const msg_generate::robocup_localization23::ConstPtr &msg);
        void visionCallback(const msg_generate::robocup_vision23::ConstPtr &msg);
        void ikCallback(const msg_generate::ikend_msg::ConstPtr &msg);
        void udpCallback(const msg_generate::localv2_msg::ConstPtr &msg);
        void gameCallback(const msg_generate::game_control_data::ConstPtr &msg);


Q_SIGNALS:
    void rosShutdown();




private:
	int init_argc;
	char** init_argv;


};

}  // namespace best_supporting_spot

#endif /* best_supporting_spot_QNODE_HPP_ */
