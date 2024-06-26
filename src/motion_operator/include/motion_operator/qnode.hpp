/**
 * @file /include/motion_operator/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef motion_operator_QNODE_HPP_
#define motion_operator_QNODE_HPP_

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

#include <std_msgs/Int32.h>
#include <msg_generate/Motion_msg.h>
#include <msg_generate/Motor_msg.h>
#include <msg_generate/Step_msg.h>
#include <msg_generate/motion_end.h>
#include <msg_generate/imu_msg.h> //tw
#include <msg_generate/motionNum_msg.h> //20240408


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace motion_operator {

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

    //void MotionNumCallback(const std_msgs::Int32::ConstPtr &msg);
    void MotionNumCallback(const msg_generate::motionNum_msg::ConstPtr &msg);
    void MotorCallback(const msg_generate::Motor_msg::ConstPtr &msg);
    void MotionCallback(const msg_generate::Motion_msg::ConstPtr &msg);
    void imuCallback(const msg_generate::imu_msg::ConstPtr &msg); //tw

    msg_generate::Motor_msg Dx_msg_l;
    msg_generate::Motion_msg Motion_msg;
    msg_generate::imu_msg imu; //tw
    int motionNum;
    int motionMode; //20240403
    ros::Publisher motion_operate;
    ros::Subscriber imu_Sub; //tw
    ros::Publisher Motor_Pub;
    ros::Subscriber Motor_Sub;
    // ros::Publisher Motion_Pub; // 20240402 tw
    ros::Subscriber Motion_Sub;
    ros::Subscriber MotionN_sub;
    ros::Publisher Serial_pub;


Q_SIGNALS:
    void rosShutdown();
    void Rx_MotionData();
    void Motion_Sig();
    void Rx_MotorData();


private:
    int init_argc;
    char** init_argv;


};

}  // namespace motion_operator

#endif /* motion_operator_QNODE_HPP_ */
