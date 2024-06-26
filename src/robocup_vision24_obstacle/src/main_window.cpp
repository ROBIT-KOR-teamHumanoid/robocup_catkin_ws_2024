/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/robocup_vision24_obstacle/main_window.hpp"
#include <std_msgs/String.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

extern ros::Publisher visionPub;
msg_generate::robocup_vision23 visionMsg;

extern ros::Publisher vision_feature_Pub;
msg_generate::robocup_vision23_feature vision_feature_Msg;

extern ros::Subscriber masterSub;

extern ros::Publisher p2tPub;

extern ros::Publisher hsvPub;
msg_generate::HSV hsvMsg;

extern ros::Publisher obsnaviPub;
msg_generate::obsnavi obsnaviMsg;

namespace robocup_vision24_obstacle {

using namespace Qt;
using namespace cv;
using namespace std;

HSV fieldhsv, linehsv, redhsv, bluehsv;


//For Pan_Tilt
PAN_TILT pan_tilt = PAN_TILT();

int scan_value = 0;

//robot
int robot_absx = 0;
int robot_absy = 0;

//save
int save_img_flag = 0;
int save_img_start = 0;
int save_img_timer = 0;

//error
int ocam_error = 0;



/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    qnode.init();
    qRegisterMetaType<cv::Mat>("cv::Mat");

    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(filter_100ms()));
    m_Timer->start(100);

    scene = new QGraphicsScene(this);


    QObject::connect(&qnode, SIGNAL(recvImg(const cv::Mat&, const cv::Mat&)), this, SLOT(update(const cv::Mat&, const cv::Mat&)));
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    calibration_info();

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 6; i++)
    {
        str_list[i] = 'a' + (rand() % 26);
    }
    string str_name(str_list);
    cout<<str_list<<endl;
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/
void robocup_vision24_obstacle::MainWindow::publish_vision_msg()
{
    //PRE CONDITION : ball_cam_N, final_filter_N, ballPos.dist, pan_tilt, ball_speed_vec_n, ball_speed_level, scan_value
    //POST CONDITION :msg
    //PURPOSE : 비전 데이터를 다른 노드로 PUBLISH & UI에 비전 데이터 출력

    visionMsg.Ball_cam_X = ball_cam_X;
    visionMsg.Ball_cam_Y = ball_cam_Y;
    if(ballPos.dist == 0){visionMsg.Ball_2d_X = 0; visionMsg.Ball_2d_Y = 0;}
    else{visionMsg.Ball_2d_X = final_filter_x; visionMsg.Ball_2d_Y = final_filter_y;}
    visionMsg.Ball_D = ballPos.dist;
    visionMsg.PAN = pan_tilt.ptpos.PAN_POSITION;
    visionMsg.TILT = pan_tilt.ptpos.TILT_POSITION;
    visionMsg.Ball_speed_X = ball_speed_vec_x;
    visionMsg.Ball_speed_Y = ball_speed_vec_y;
    visionMsg.Ball_speed_level = ball_speed_level;
    visionMsg.Scan_mode = scan_value;
    visionPub.publish(visionMsg);

    visionMsg.ROBOT_VEC_X.clear();
    visionMsg.ROBOT_VEC_Y.clear();

    char TEXT[256];
    sprintf(TEXT, "TARGET_X : %d", (int)visionMsg.Ball_cam_X); ui.TARGET_X_value->setText(TEXT);
    sprintf(TEXT, "TARGET_Y : %d", (int)visionMsg.Ball_cam_Y); ui.TARGET_Y_value->setText(TEXT);
    sprintf(TEXT, "TARGET_CX : %lf", visionMsg.Ball_2d_X); ui.TARGET_CX_value->setText(TEXT);
    sprintf(TEXT, "TARGET_CY : %lf", visionMsg.Ball_2d_Y); ui.TARGET_CY_value->setText(TEXT);
    sprintf(TEXT, "TARGET_DIS : %lf", visionMsg.Ball_D); ui.TARGET_DIS_value->setText(TEXT);
    if(scan_value == 0){sprintf(TEXT, "SCANMODE : INIT"); ui.SCANMODE_value->setText(TEXT);}
    else if(scan_value == 1){sprintf(TEXT, "SCANMODE : OPER"); ui.SCANMODE_value->setText(TEXT);}
    else if(scan_value == 2){sprintf(TEXT, "SCANMODE : BALL"); ui.SCANMODE_value->setText(TEXT);}
    else if(scan_value == 3){sprintf(TEXT, "SCANMODE : LINE"); ui.SCANMODE_value->setText(TEXT);}
    else if(scan_value == 4){sprintf(TEXT, "SCANMODE : MASTER"); ui.SCANMODE_value->setText(TEXT);}
    else{sprintf(TEXT, "SCANMODE : NONE"); ui.SCANMODE_value->setText(TEXT);}

    //++++++++++++++++++++++++++++++++++++++p2t
    std_msgs::String msg;
    //char TEXT[256];
    sprintf(TEXT, "%d, %d, %d", (int)(visionMsg.Ball_2d_X / 50), (int)(visionMsg.Ball_2d_Y / 10) - 3, 0);
    msg.data = TEXT;
    p2tPub.publish(msg);
}

void robocup_vision24_obstacle::MainWindow::publish_localization_msg()
{
    //PRE CONDITION : CONFIDENCE, DISTANCE, POINT_VEC_N
    //POST CONDITION :msg
    //PURPOSE : 로컬 노드에 필요한 비전 데이터를 로컬 노드로 PUBLISH

    vision_feature_Pub.publish(vision_feature_Msg);
    vision_feature_Msg.CONFIDENCE.clear();
    vision_feature_Msg.DISTANCE.clear();
    vision_feature_Msg.POINT_VEC_X.clear();
    vision_feature_Msg.POINT_VEC_Y.clear();
    vision_feature_Msg.TYPE.clear();
}

void robocup_vision24_obstacle::MainWindow::publish_hsv_msg()
{
    hsvMsg.red1_dis = red1_pos.dist;
    hsvMsg.red1_the = red1_pos.theta;
    hsvMsg.red2_dis = red2_pos.dist;
    hsvMsg.red2_the = red2_pos.theta;
    hsvMsg.blue1_dis = blue1_pos.dist;
    hsvMsg.blue1_the = blue1_pos.theta;
    hsvMsg.blue2_dis = blue2_pos.dist;
    hsvMsg.blue2_the = blue2_pos.theta;

    hsvPub.publish(hsvMsg);

}

void robocup_vision24_obstacle::MainWindow::filter_100ms()
{
    //PRE CONDITION : filter_cnt, fst_filter_cnt, fst_filter_N, ballPos.dist
    //POST CONDITION : ball_speed_vec_N, ball_speed_level
    //PURPOSE : 이동평균 필터를 적용하여 캠의 오차 값을 보정하고 이동중인 물체를 포착

    if(ocam_error){scan_value = 99; cam_nice_point = pan_tilt.mode(scan_value);}
    else if(scan_value == 99){scan_value = 0;}
    if(scan_value != 2 && scan_value != 3)
    {
        ball_speed_vec_x = 0;
        ball_speed_vec_y = 0;
        ball_speed_level = 0;
    }
    if(filter_cnt >= 9)
    {
        //해당 함수는 100ms마다 실행되고 총 10번 실행시 fps계산

        //fps계산
        char TEXT[256]; sprintf(TEXT, "FPS : %d", fps_cnt); ui.FPS_value->setText(TEXT);
        cout<<"fps_cnt : "<<fps_cnt<<"    nice_cnt : "<<nice_cnt<<endl;
        if(fps_cnt == 0){ocam_error = 1;}
        else{ocam_error = 0;}
        fps_cnt = 0; filter_cnt = 0; nice_cnt = 0;

        //hsv 값 1초마다 오토세이브
        save_hsv();
    }
    if(fst_filter_cnt != 0)
    {
        sec_filter_x += fst_filter_x / fst_filter_cnt;
        sec_filter_y += fst_filter_y / fst_filter_cnt;
        sec_filter_cnt += 1;
        fst_filter_x = 0; fst_filter_y = 0; fst_filter_cnt = 0;
    }

    if(filter_cnt == 0 || filter_cnt == 3 || filter_cnt == 6)
    {
        if(sec_filter_cnt != 0)
        {
            ball_speed_vec_x = final_filter_x;
            ball_speed_vec_y = final_filter_y;

            final_filter_x = sec_filter_x / sec_filter_cnt;
            final_filter_y = sec_filter_y / sec_filter_cnt;
            sec_filter_x = 0; sec_filter_y = 0; sec_filter_cnt = 0;

            ball_speed_vec_x = ball_speed_vec_x - final_filter_x;
            ball_speed_vec_y = ball_speed_vec_y - final_filter_y;
            double dis = sqrt(pow(ball_speed_vec_x, 2) + pow(ball_speed_vec_y, 2));
            if(dis != 0){ball_speed_vec_x /= dis; ball_speed_vec_y /= dis;}
            else{ball_speed_vec_x = 0; ball_speed_vec_y = 0;}
            if(ballPos.dist == 0){ball_speed_level = 0;}
            else
            {
                double tempdist = ballPos.dist;
                if(tempdist > 1500){tempdist = 1500;}
                ball_speed_level = (int)(dis / 5) * abs(1500 - tempdist) / 500;
            }
        }
    }

    filter_cnt += 1;
}
void robocup_vision24_obstacle::MainWindow::update(const cv::Mat& img, const cv::Mat& info)
{
    //PRE CONDITION : img&info(캠에서 받아오는 데이터), result_image(Image_processing 함수에서 리턴되는 Mat형 데이터)
    //POST CONDITION : 비전 데이터
    //PURPOSE : 캠에서 영상 이미지를 받아 올 때마다 실행되어 이미지 프로세싱을 실행하고 이미지 속 데이터를 처리 한 후 publish를 실행, 노드의 main역할

    //cal_Homography();

    //INIT
    load_hsv();
    caminfo_open(info); //캘리 정보 받아오기

    setting(); //UI 정보 받아오기
    cam_nice_point = pan_tilt.mode(scan_value); //팬틸트 모드 변경
    //출력은 타임스태프 찍어서보내기

    //Image processing
    Mat result_image = Image_processing(img); //Image_processing을 통해 반환되는 이미지는 img그대로 반환됨, result_image = img



    //    Mat undistorted_mat;
    //    undistort(img, undistorted_mat, K_M, D_M, NEW_K_M);

    //PRINT
    Print_Screen(img, result_image);

    //MSG
    publish_vision_msg();
    publish_hsv_msg();


    //END
    fps_cnt += 1;
    qnode.isRecv = false;
    return;
}

Mat robocup_vision24_obstacle::MainWindow::Image_processing(const cv::Mat& img)
{
    // !!!!!!!제일 중요한 부분!!!!!!!
    //PRE CONDITION : img, cam_nice_point,
    //POST CONDITION : ball_filter_N, ball_cam_N, fst_filter_N, vision_feature_Msg, visionMsg
    //PURPOSE : 캠이 현재 볼 트래킹 상태 일 때, 욜로 데이터를 통해 객체를 검출하고 해당 객체가 공, 라인, 로봇인지 판별 한 후 객체 데이터를 저장 및 다른 노드로 전송

    data.clear();//데이터 초기화



    //HSV
    Mat result_mat = img.clone();
    Mat result_mat1 = img.clone();
    Mat HSV_mat = img.clone();
    Mat red_mat_C;
    Mat blue_mat_C;
    cv::cvtColor(HSV_mat,HSV_mat,CV_BGR2HSV);
    GaussianBlur(HSV_mat, HSV_mat, Size(15, 15), 3);

    fieldhsv.hmin = 60;
    fieldhsv.hmax = 88;
    fieldhsv.smin = 54;
    fieldhsv.smax = 99;
    fieldhsv.vmin = 18;
    fieldhsv.vmax = 255;



    //inRange
    Mat field_mat, line_mat, red_mat, blue_mat, map_mat;
    inRange(HSV_mat,cv::Scalar(fieldhsv.hmin,fieldhsv.smin,fieldhsv.vmin),cv::Scalar(fieldhsv.hmax,fieldhsv.smax,fieldhsv.vmax),field_mat);
    erode(field_mat,field_mat,Mat(),Point(-1,-1),fieldhsv.erode); dilate(field_mat,field_mat,Mat(),Point(-1,-1),fieldhsv.dilate);
    inRange(HSV_mat,cv::Scalar(linehsv.hmin,linehsv.smin,linehsv.vmin),cv::Scalar(linehsv.hmax,linehsv.smax,linehsv.vmax),line_mat);
    dilate(line_mat,line_mat,Mat(),Point(-1,-1),linehsv.dilate); erode(line_mat,line_mat,Mat(),Point(-1,-1),linehsv.erode);

    inRange(HSV_mat,cv::Scalar(fieldhsv.hmin,fieldhsv.smin,fieldhsv.vmin),cv::Scalar(fieldhsv.hmax,fieldhsv.smax,fieldhsv.vmax),map_mat);
    erode(map_mat,map_mat,Mat(),Point(-1,-1),fieldhsv.erode); dilate(map_mat,map_mat,Mat(),Point(-1,-1),fieldhsv.dilate);

    inRange(HSV_mat,cv::Scalar(redhsv.hmin, redhsv.smin, redhsv.vmin), cv::Scalar(redhsv.hmax, redhsv.smax, redhsv.vmax), red_mat);
    inRange(HSV_mat,cv::Scalar(bluehsv.hmin, bluehsv.smin, bluehsv.vmin), cv::Scalar(bluehsv.hmax, bluehsv.smax, bluehsv.vmax), blue_mat);
    erode(red_mat, red_mat, Mat(), Point(-1, -1), redhsv.erode); dilate(red_mat, red_mat, Mat(), Point(-1, -1), redhsv.dilate);
    erode(blue_mat, blue_mat, Mat(), Point(-1, -1), bluehsv.erode); dilate(blue_mat, blue_mat, Mat(), Point(-1, -1), bluehsv.dilate);



    //Erase Out Field
//    RobitLabeling labelField(field_mat,5000,4);
//    labelField.doLabeling();
//    if(labelField.mergeArea(result_mat))
//    {
//        labelField.eraseOutField(field_mat,result_mat,50,result_mat);
//        labelField.eraseOutField(line_mat,result_mat,50,result_mat);
//    }

//    RobitLabeling labelField1(field_mat,5000,4);
//    labelField1.doLabeling();
//    if(labelField1.mergeArea(result_mat1))
//    {
//        labelField1.eraseOutField(field_mat,result_mat1,50,result_mat1);
//        labelField1.eraseOutField(line_mat,result_mat1,50,result_mat1);
//    }

    if(HSV_flag != 0)
    {


        //draw coutour
        vector<vector<Point>> contours_red;
        vector<vector<Point>> contours_blue;

        vector<Vec4i> hierarchy_red;
        vector<Vec4i> hierarchy_blue;

        cv::findContours(red_mat, contours_red, hierarchy_red, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        cv::findContours(blue_mat, contours_blue, hierarchy_red, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        vector<vector<Point>> conPoly_red(contours_red.size());
        vector<vector<Point>> conPoly_blue(contours_blue.size());

        drawContours(result_mat1, contours_red, -1, Scalar(0, 0, 255), 3);
        drawContours(result_mat1, contours_blue, -1, Scalar(255, 0, 0), 3);

        //labeling color

        RobitLabeling red(red_mat, 1000, 4);


        RobitLabeling blue(blue_mat, 1000, 4);


        if(red_topfilter_flag)
        {
            red.eraseTopBlob(red_mat, red_mat);
            red_mat_C = red_mat.clone();
            red.m_Image = red_mat;
        }

        red.doLabeling();
        red.sortingRecBlobs();

        if(blue_topfilter_flag)
        {
            blue.eraseTopBlob(blue_mat, blue_mat);
            blue_mat_C = blue_mat.clone();
            blue.m_Image = blue_mat;
        }

        blue.doLabeling();
        blue.sortingRecBlobs();

        Point red_p1(-1, -1), red_p2(-1, -1), blue_p1(-1, -1), blue_p2(-1, -1);

        if(red.m_nBlobs != 0)
        {
            Point p1_xy(red.m_recBlobs.at(0).x, red.m_recBlobs.at(0).y);
            Point p1_wh(red.m_recBlobs.at(0).width, red.m_recBlobs.at(0).height);

            red_p1.x = p1_xy.x + (p1_wh.x / 2); red_p1.y = p1_xy.y + p1_wh.y;
            rectangle(result_mat1, p1_xy, Point(p1_xy.x + p1_wh.x, p1_xy.y + p1_wh.y), Scalar(0, 0, 255), 2 ,8);
            circle(result_mat1, red_p1, 5, Scalar(0, 0, 255));
            if(red.m_nBlobs > 1)
            {
                Point p2_xy(red.m_recBlobs.at(1).x, red.m_recBlobs.at(1).y);
                Point p2_wh(red.m_recBlobs.at(1).width, red.m_recBlobs.at(1).height);

                red_p2.x = p2_xy.x + (p2_wh.x / 2); red_p2.y = p2_xy.y + p2_wh.y;
                rectangle(result_mat1, p2_xy, Point(p2_xy.x + p2_wh.x, p2_xy.y + p2_wh.y), Scalar(0, 0, 255), 2 ,8);
                circle(result_mat1, red_p2, 5, Scalar(0, 0, 255));
            }

        }

        if(blue.m_nBlobs != 0)
        {
            Point p1_xy(blue.m_recBlobs.at(0).x, blue.m_recBlobs.at(0).y);
            Point p1_wh(blue.m_recBlobs.at(0).width, blue.m_recBlobs.at(0).height);

            blue_p1.x = p1_xy.x + (p1_wh.x / 2); blue_p1.y = p1_xy.y + p1_wh.y;
            rectangle(result_mat1, p1_xy, Point(p1_xy.x + p1_wh.x, p1_xy.y + p1_wh.y), Scalar(255, 0, 0), 2 ,8);
            circle(result_mat1, blue_p1, 5, Scalar(255, 0, 0));
            if(blue.m_nBlobs > 1)
            {
                Point p2_xy(blue.m_recBlobs.at(1).x, blue.m_recBlobs.at(1).y);
                Point p2_wh(blue.m_recBlobs.at(1).width, blue.m_recBlobs.at(1).height);

                blue_p2.x = p2_xy.x + (p2_wh.x / 2); blue_p2.y = p2_xy.y + p2_wh.y;
                rectangle(result_mat1, p2_xy, Point(p2_xy.x + p2_wh.x, p2_xy.y + p2_wh.y), Scalar(255, 0, 0), 2 ,8);
                circle(result_mat1, blue_p2, 5, Scalar(255, 0, 0));
            }

        }

        red1_pos.dist = -999; red1_pos.theta = -999; red2_pos.dist = -999; red2_pos.theta = -999; blue1_pos.dist = -999; blue1_pos.theta = -999; blue2_pos.dist = -999; blue2_pos.theta = -999;
        double red1_absx = 0, red1_absy = 0, red2_absx = 0, red2_absy = 0, blue1_absx = 0, blue1_absy = 0, blue2_absx = 0, blue2_absy = 0;

        if(red_p1.x != -1)
        {
            red1_pos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, red_p1);
            double obs_x = red1_pos.dist * sin(red1_pos.theta * M_PI / 180);
            double obs_y = red1_pos.dist * cos(red1_pos.theta * M_PI / 180);
            red1_absx = obs_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - obs_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
            red1_absy = obs_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + obs_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);

//            cout << "red1_abs_x :   " << red1_absx << endl;
//            cout << "red1_abs_y :   " << red1_absy << endl;
        }
        if(red_p2.x != -1)
        {
            red2_pos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, red_p2);
            double obs_x = red2_pos.dist * sin(red2_pos.theta * M_PI / 180);
            double obs_y = red2_pos.dist * cos(red2_pos.theta * M_PI / 180);
            red2_absx = obs_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - obs_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
            red2_absy = obs_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + obs_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
//            cout << "red2_abs_x :   " << red2_absx << endl;
//            cout << "red2_abs_y :   " << red2_absy << endl;
        }
        if(blue_p1.x != -1)
        {
            blue1_pos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, blue_p1);
            double obs_x = blue1_pos.dist * sin(blue1_pos.theta * M_PI / 180);
            double obs_y = blue1_pos.dist * cos(blue1_pos.theta * M_PI / 180);
            blue1_absx = obs_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - obs_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
            blue1_absy = obs_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + obs_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
//            cout << "blue1_abs_x :   " << blue1_absx << endl;
//            cout << "blue1_abs_y :   " << blue1_absy << endl;
        }
        if(blue_p2.x != -1)
        {
            blue2_pos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, blue_p2);
            double obs_x = blue2_pos.dist * sin(blue2_pos.theta * M_PI / 180);
            double obs_y = blue2_pos.dist * cos(blue2_pos.theta * M_PI / 180);
            blue2_absx = obs_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - obs_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
            blue2_absy = obs_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + obs_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
//            cout << "blue2_abs_x :   " << blue2_absx << endl;
//            cout << "blue2_abs_y :   " << blue2_absy << endl;
        }


        if(red_p1.x != -1)
        {
            obsnaviMsg.DISTANCE.push_back(red1_pos.dist);
            obsnaviMsg.POINT_VEC_X.push_back(red1_absx);
            obsnaviMsg.POINT_VEC_Y.push_back(red1_absy);
        }

        if(red_p2.x != -1)
        {
            obsnaviMsg.DISTANCE.push_back(red2_pos.dist);
            obsnaviMsg.POINT_VEC_X.push_back(red2_absx);
            obsnaviMsg.POINT_VEC_Y.push_back(red2_absy);
        }

        if(blue_p1.x != -1)
        {
            obsnaviMsg.DISTANCE.push_back(blue1_pos.dist);
            obsnaviMsg.POINT_VEC_X.push_back(blue1_absx);
            obsnaviMsg.POINT_VEC_Y.push_back(blue1_absy);
        }

        if(blue_p2.x != -1)
        {
            obsnaviMsg.DISTANCE.push_back(blue2_pos.dist);
            obsnaviMsg.POINT_VEC_X.push_back(blue2_absx);
            obsnaviMsg.POINT_VEC_Y.push_back(blue2_absy);
        }

        obsnaviPub.publish(obsnaviMsg);
        obsnaviMsg.DISTANCE.clear();
        obsnaviMsg.POINT_VEC_X.clear();
        obsnaviMsg.POINT_VEC_Y.clear();


        char TEXT[256];
        sprintf(TEXT, "RED1 DIS : %d / THE : %d || RED2 DIS : %d / THE : %d", (int)red1_pos.dist, (int)red1_pos.theta, (int)red2_pos.dist, (int)red2_pos.theta); ui.red_data->setText(TEXT);
        sprintf(TEXT, "BLUE1 DIS : %d / THE : %d || BLUE2 DIS : %d / THE : %d", (int)blue1_pos.dist, (int)blue1_pos.theta, (int)blue2_pos.dist, (int)blue2_pos.theta); ui.blue_data->setText(TEXT);



    }
    else
    {
        char TEXT[256];
        sprintf(TEXT, " "); ui.red_data->setText(TEXT);
        sprintf(TEXT, " "); ui.blue_data->setText(TEXT);
    }

    //PAN_TILT CONTROLL


    if(cam_nice_point == 0) //캠이 볼트래킹 모드가 아닐 경우 INIT 상태로 설정
    {
        //변수 초기화
        ballPos.dist = 0;
        pan_tilt.target_x = 0;
        pan_tilt.target_y = 0;
        pan_tilt.target_absx = 0;
        pan_tilt.target_absy = 0;
        ball_cam_X = 0;
        ball_cam_Y = 0;
    }

    //YOLO RUN

    if(cam_nice_point != 0) //캠이 볼트래킹 모드일 경우 욜로 상태로 설정
    {

        Rect remove_rect = Rect(0,0,0,0);

        //YoloRun 함수를 통해 이미지에 있는 객체를 검출 및 판별하여 객체의 데이터를 vector_yolo 벡터 컨테이너에 저장
        yolov4.vector_yolo = yolov4.YoloRun(img);


        int cnt_ball = 0, cnt_line = 0, cnt_robot = 0, cnt_xcross = 0;
        for(int i = 0; i < yolov4.vector_yolo.size();i++)
        {
            //벡터 컨테이너의 크기(물체를 검출한 횟수)만큼 반복 실행하여 검출된 물체가 공, 라인, 로봇 중 어떤 데이터인지 판별하고 해당 물체의 카운트에 +1을 더함
            if(yolov4.vector_yolo[i].NUM == 0){cnt_ball += 1;}
            else if(yolov4.vector_yolo[i].NUM == 1){cnt_line += 1;}
            else if(yolov4.vector_yolo[i].NUM == 2){cnt_robot += 1;}
            else if(yolov4.vector_yolo[i].NUM == 3){cnt_xcross += 1;}
        }
        if(save_img_start && save_img_timer >= 25)
        {
            //이미지 세이브 카운트 및 플래그, 사용 안됨
            save_img_timer = 0;
            if(cnt_ball != 0){save_img_flag = 1;}
            else if(cnt_line != 0){save_img_flag = 1;}
            else if(cnt_robot != 0){save_img_flag = 1;}
            else if(cnt_xcross != 0){save_img_flag = 1;}
        }
        save_img_timer += 1;


        //이후 코드부터 카운트 된 물체의 수 만큼 해당 물체의 위치를 판별함
        //cal distance
        if(cnt_ball != 0) //공이 카운트 됐을 경우 실행
        {
            Rect result(0,0,0,0);
            double score = 0;
            for(int i = 0; i < yolov4.vector_yolo.size();i++)//검출된 객체 수 만큼 반복 실행
            {
                if((yolov4.vector_yolo[i].NUM == 0) && (yolov4.vector_yolo[i].SCORE > score))
                    // 검출된 객체가 공이고 객체의 신뢰도가 특정 값 이상일 경우 실행
                {
                    //결과 값에 해당 욜로 데이터를 저장
                    result = Rect(yolov4.vector_yolo[i].X, yolov4.vector_yolo[i].Y, yolov4.vector_yolo[i].W, yolov4.vector_yolo[i].H);
                    remove_rect = result; //이후 라인 판독 시 사용될 변수

                    //신뢰도 특정 값 업데이트, 이후 해당 값보다 높은 신뢰도를 가진 객체가 검출되면 해당 객체 데이터로 업데이트됨
                    score = yolov4.vector_yolo[i].SCORE;
                }
            }

            //버퍼에 공의 좌표와 넓이 및 높이 데이터 입력
            char buf[100];
            sprintf(buf, "%d %lf %lf %lf %lf", 0, ((double)result.x + (double)result.width / 2) / 640, ((double)result.y + (double)result.height / 2) / 480, (double)result.width / 640, (double)result.height / 480);
            string value_total(buf);
            data.push_back(value_total);

            nice_cnt += 1; //공이 검출될 경우 nice_cnt 에 +1

            //공의 중앙 계산
            double tilt_param = result.height / 2 * (1 - (double(result.y) / 480));
            double ball_center_X = result.x + result.width / 2;
            double ball_center_Y = result.y + result.height / 2 + tilt_param;


            //UI 에 공 위치 그리기
            int color = score * 255;

            line(result_mat,Point(ball_center_X, ball_center_Y),Point(ball_center_X, ball_center_Y),Scalar(0, 0, 0), 3, 8, 0);
            circle(result_mat, Point(result.x + result.width/2, result.y + result.height/2), (result.width + result.height) / 4, Scalar(color, color, color), 3, 8, 0);
            rectangle(line_mat, result, Scalar(0, 0, 0), -1, 8);

            //공의 좌표 벡터 컨테이너로 저장
            vector<Point2f> ball_pts;
            ball_pts.push_back(Point2f(ball_center_X, ball_center_Y));


            //물체와 로봇의 거리 계산
            undistortPoints(ball_pts, ball_pts, K_M, D_M, Mat(), NEW_K_M);
            for(int i = 0; i < ball_pts.size();i++)
            {
                ballPos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, Point(ball_pts[i].x, ball_pts[i].y));
            }
            ball_pts.clear();

            //공에 이동평균 필터 적용
            pan_tilt.target_x = ballPos.dist * sin(ballPos.theta * M_PI / 180);
            pan_tilt.target_y = ballPos.dist * cos(ballPos.theta * M_PI / 180);
            pan_tilt.target_absx = pan_tilt.target_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - pan_tilt.target_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
            pan_tilt.target_absy = pan_tilt.target_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + pan_tilt.target_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);

            if(ball_filter_cnt < 30){

                ball_filter_x[ball_filter_cnt] = ball_center_X;
                ball_filter_y[ball_filter_cnt] = ball_center_Y;
                ball_cam_X = ball_center_X;
                ball_cam_Y = ball_center_Y;
                ball_filter_cnt++;
            }else{
                if(ball_center_X == 0 && ball_center_Y ==0){
                    ball_cam_X = ball_center_X;
                    ball_cam_Y = ball_center_Y;
                }else{
                    ball_filter_x[ball_filter_idx] = ball_center_X;
                    ball_filter_y[ball_filter_idx] = ball_center_Y;
                    for(int i = 0 ; i < 30 ; i++){
                        ball_cam_X += ball_filter_x[i];
                        ball_cam_Y += ball_filter_y[i];
                    }
                    ball_cam_X /= 30;
                    ball_cam_Y /= 30;
                }

                if(ball_filter_idx > 29){
                    ball_filter_idx = 0;
                }else{
                    ball_filter_idx++;
                }

            }

            //필터 적용 후 최종적으로 나온 데이터 저장
            ball_cam_X = ball_center_X;
            ball_cam_Y = ball_center_Y;


            //캠의 이동평균 필터를 위한 변수 저장
            pan_tilt.tracking_cnt += 1;

            fst_filter_x += pan_tilt.target_absx;
            fst_filter_y += pan_tilt.target_absy;
            fst_filter_cnt += 1;
        }
        else //공이 카운트 되지 않았을 경우 실행
        {
            ballPos.dist = 0;
            pan_tilt.target_x = 0;
            pan_tilt.target_y = 0;
            pan_tilt.target_absx = 0;
            pan_tilt.target_absy = 0;
            ball_cam_X = 0;
            ball_cam_Y = 0;

            pan_tilt.no_ball_cnt += 1;
        }

        if(cnt_line != 0) //라인(특징점)이 카운트 됐을 경우 실행
        {
            for(int i = 0; i < yolov4.vector_yolo.size();i++)//검출된 객체 수 만큼 반복 실행
            {
                if((yolov4.vector_yolo[i].NUM == 1)) //검출된 객체가 특징점일 경우 실행
                {
                    //결과 값에 해당 욜로 데이터를 저장
                    Rect result(yolov4.vector_yolo[i].X, yolov4.vector_yolo[i].Y, yolov4.vector_yolo[i].W, yolov4.vector_yolo[i].H);
                    double line_center_X = result.x + result.width / 2;
                    double line_center_Y = result.y + result.height / 2;



                    if((line_center_X > remove_rect.x + remove_rect.width || line_center_X < remove_rect.x) || (line_center_Y > remove_rect.y + remove_rect.height || line_center_Y < remove_rect.y))
                        //라인의 예외처리?
                    {
                        //버퍼에 라인의 좌표 데이터 입력
                        char buf[100];
                        sprintf(buf, "%d %lf %lf %lf %lf", 1, ((double)result.x + (double)result.width / 2) / 640, ((double)result.y + (double)result.height / 2) / 480, (double)result.width / 640, (double)result.height / 480);
                        string value_total(buf);
                        data.push_back(value_total);

                        //UI 에 특징점 위치 그리기
                        int color = yolov4.vector_yolo[i].SCORE * 255;
                        line(result_mat,Point(line_center_X, line_center_Y),Point(line_center_X, line_center_Y),Scalar(color, color, color), 10, 8, 0);

                        //데이터 벡터 컨테이너에 저장
                        pts.push_back(Point2f(line_center_X, line_center_Y));
                        condis.push_back(Point2f(yolov4.vector_yolo[i].SCORE, 0));
                    }
                }
            }

            //저장된 데이터가 존재 할 경우 undistortPoints 실행?
            if(pts.size() != 0){undistortPoints(pts, pts, K_M, D_M, Mat(), NEW_K_M);}

            for(int i = 0; i < pts.size();i++)//저장된 데이터 수 만큼 반복
            {
                //특징점의 거리 계산
                linePos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, Point(pts[i].x, pts[i].y));
                double line_x = linePos.dist * sin(linePos.theta * M_PI / 180);
                double line_y = linePos.dist * cos(linePos.theta * M_PI / 180);
                double line_absx = line_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - line_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
                double line_absy = line_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + line_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);

                //일정 거리 이상에 존재하는 특징점은 예외처리
                int remove_space_dis = 3000;


                if(linePos.dist < remove_space_dis)
                {
                    //로컬 노드에 특징점의 데이터를 보내기 위해 데이터 PUBLISH
                    vision_feature_Msg.CONFIDENCE.push_back(condis[i].x);
                    vision_feature_Msg.DISTANCE.push_back(linePos.dist);
                    vision_feature_Msg.POINT_VEC_X.push_back(line_absx);
                    vision_feature_Msg.POINT_VEC_Y.push_back(line_absy);
                    vision_feature_Msg.TYPE.push_back(0);
                }
            }
            pts.clear(); condis.clear();
            if(cam_nice_point == 1){publish_localization_msg();}
            else
            {
                vision_feature_Msg.CONFIDENCE.clear();
                vision_feature_Msg.DISTANCE.clear();
                vision_feature_Msg.POINT_VEC_X.clear();
                vision_feature_Msg.POINT_VEC_Y.clear();
                vision_feature_Msg.TYPE.clear();
            }
        }

        if(cnt_robot != 0) //로봇(obstacle)이 카운트 됐을 경우 실행
        {
            vector<Point2f> robot_pts;
            Rect result(0,0,0,0);
            double score = 0;
            for(int i = 0; i < yolov4.vector_yolo.size(); i++)//검출된 객체 수 만큼 반복 실행
            {
                if((yolov4.vector_yolo[i].NUM == 2))//검출된 객체가 로봇일 경우 실행
                {
                    //결과 값에 해당 욜로 데이터를 저장
                    result = Rect(yolov4.vector_yolo[i].X, yolov4.vector_yolo[i].Y, yolov4.vector_yolo[i].W, yolov4.vector_yolo[i].H);

                    //버퍼에 로봇의 좌표와 넓이 및 높이 데이터 입력
                    char buf[100];
                    sprintf(buf, "%d %lf %lf %lf %lf", 2, ((double)result.x + (double)result.width / 2) / 640, ((double)result.y + (double)result.height / 2) / 480, (double)result.width / 640, (double)result.height / 480);
                    string value_total(buf);
                    data.push_back(value_total);

                    //로봇의 중앙 계산
                    double tilt_param = result.height / 2 * (1 - (double(result.y) / 480));
                    double robot_center_X = result.x + result.width / 2;
                    double robot_center_Y = result.y + result.height / 2 + tilt_param;

                    //UI 에 로봇의 위치 그리기
                    int color = yolov4.vector_yolo[i].SCORE * 255;
                    rectangle(result_mat, result, Scalar(color, color, color), 3, 8, 0);
                    line(result_mat,Point(robot_center_X, robot_center_Y),Point(robot_center_X, robot_center_Y),Scalar(0, 0, 0), 3, 8, 0);

                    //로봇의 좌표 벡터 컨테이너로 저장
                    robot_pts.push_back(Point2f(robot_center_X, robot_center_Y));
                }
            }

            //visionMsg의 로봇 벡터 컨테이너 초기화
            visionMsg.ROBOT_VEC_X.clear();
            visionMsg.ROBOT_VEC_Y.clear();

            //물체와 로봇의 거리 계산
            if(robot_pts.size() != 0){undistortPoints(robot_pts, robot_pts, K_M, D_M, Mat(), NEW_K_M);}
            for(int i = 0; i < robot_pts.size();i++)
            {
                robotPos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, Point(robot_pts[i].x, robot_pts[i].y));
                double robot_x = robotPos.dist * sin(robotPos.theta * M_PI / 180);
                double robot_y = robotPos.dist * cos(robotPos.theta * M_PI / 180);

                //로봇(obstacle)의 절대좌표 계산
                robot_absx = robot_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - robot_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
                robot_absy = robot_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + robot_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);

                //visionMsg의 로봇 벡터 컨테이너에 데이터 저장
                visionMsg.ROBOT_VEC_X.push_back(robot_absx);
                visionMsg.ROBOT_VEC_Y.push_back(robot_absy);
            }
            robot_pts.clear();


        }
        else //로봇(obstacle)이 카운트 되지 않았을 경우 실행
        {
            visionMsg.ROBOT_VEC_X.clear();
            visionMsg.ROBOT_VEC_Y.clear();
            robot_absx = 0;
            robot_absy = 0;
        }

        if(cnt_xcross != 0)
        {
            for(int i = 0; i < yolov4.vector_yolo.size();i++)//검출된 객체 수 만큼 반복 실행
            {
                if((yolov4.vector_yolo[i].NUM == 3)) //검출된 객체가 특징점일 경우 실행
                {
                    //결과 값에 해당 욜로 데이터를 저장
                    Rect result(yolov4.vector_yolo[i].X, yolov4.vector_yolo[i].Y, yolov4.vector_yolo[i].W, yolov4.vector_yolo[i].H);
                    double xcross_center_X = result.x + result.width / 2;
                    double xcross_center_Y = result.y + result.height / 2;



                    if((xcross_center_X > remove_rect.x + remove_rect.width || xcross_center_X < remove_rect.x) || (xcross_center_Y > remove_rect.y + remove_rect.height || xcross_center_Y < remove_rect.y))
                        //라인의 예외처리?
                    {
                        //버퍼에 라인의 좌표 데이터 입력
                        char buf[100];
                        sprintf(buf, "%d %lf %lf %lf %lf", 1, ((double)result.x + (double)result.width / 2) / 640, ((double)result.y + (double)result.height / 2) / 480, (double)result.width / 640, (double)result.height / 480);
                        string value_total(buf);
                        data.push_back(value_total);

                        //UI 에 특징점 위치 그리기
                        int color = yolov4.vector_yolo[i].SCORE * 255;
                        line(result_mat,Point(xcross_center_X, xcross_center_Y),Point(xcross_center_X, xcross_center_Y),Scalar(color, 0, 0), 10, 8, 0);

                        //데이터 벡터 컨테이너에 저장
                        pts.push_back(Point2f(xcross_center_X, xcross_center_Y));
                        condis.push_back(Point2f(yolov4.vector_yolo[i].SCORE, 0));
                    }
                }
            }

            //저장된 데이터가 존재 할 경우 undistortPoints 실행?
            if(pts.size() != 0){undistortPoints(pts, pts, K_M, D_M, Mat(), NEW_K_M);}

            for(int i = 0; i < pts.size();i++)//저장된 데이터 수 만큼 반복
            {
                //특징점의 거리 계산
                linePos = RV::calcObjectDistance(pan_tilt.ptpos.TILT_POSITION, ROBOT_HEIGHT + TILT_L * (cos(pan_tilt.ptpos.TILT_POSITION*DEG2RAD) - 1), new_focalLen, new_prncPt, Point(pts[i].x, pts[i].y));
                double xcross_x = linePos.dist * sin(linePos.theta * M_PI / 180);
                double xcross_y = linePos.dist * cos(linePos.theta * M_PI / 180);
                double xcross_absx = xcross_x * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) - xcross_y * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);
                double xcross_absy = xcross_x * sin((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180) + xcross_y * cos((-1) * pan_tilt.ptpos.PAN_POSITION * M_PI / 180);

                //일정 거리 이상에 존재하는 특징점은 예외처리
                int remove_space_dis = 3000;


                if(linePos.dist < remove_space_dis)
                {
                    //로컬 노드에 특징점의 데이터를 보내기 위해 데이터 PUBLISH
                    vision_feature_Msg.CONFIDENCE.push_back(condis[i].x);
                    vision_feature_Msg.DISTANCE.push_back(linePos.dist);
                    vision_feature_Msg.POINT_VEC_X.push_back(xcross_absx);
                    vision_feature_Msg.POINT_VEC_Y.push_back(xcross_absy);
                    vision_feature_Msg.TYPE.push_back(1);
                }
            }
            pts.clear(); condis.clear();
            if(cam_nice_point == 1){publish_localization_msg();}
            else
            {
                vision_feature_Msg.CONFIDENCE.clear();
                vision_feature_Msg.DISTANCE.clear();
                vision_feature_Msg.POINT_VEC_X.clear();
                vision_feature_Msg.POINT_VEC_Y.clear();
                vision_feature_Msg.TYPE.clear();
            }
        }
    }

    //입출력스트림을 통해 이미지를 저장하는 코드, 현재는 사용 안됨
    if(save_img_flag)
    {
        save_img_flag = 0;
        save_img_count += 1;
        char buf[256];
        sprintf(buf, "/home/robit/catkin_ws/src/robocup_vision24_obstacle/img/%s%06d.png", &str_list, save_img_count);
        imwrite(buf, img);
        sprintf(buf, "/home/robit/catkin_ws/src/robocup_vision24_obstacle/img/%s%06d.txt", &str_list, save_img_count);
        ofstream file(buf);
        if(file.is_open())
        {
            for(int j = 0; j < data.size(); j++)
            {
                file << data[j] << endl;
            }
            file.close();
        }
        cout<<"save img!!!"<<endl;
    }





    // hsv_flag값에 따라 반환될 이미지 결정 코드, 사용 안됨?
    if(HSV_flag == 0){return result_mat;}
    else if(HSV_flag == 1)
    {
        //        cv::Mat bgr[3];
        //        cv::split(result_mat, bgr);
        //        bgr[0] = field_mat / 255 * 56;
        //        bgr[1] = field_mat / 255 * 191;
        //        bgr[2] = field_mat / 255 * 94;
        //        cv::merge(bgr, 3, field_mat);
        //        return field_mat;
        return result_mat1;
    }
    else if(HSV_flag == 2)
    {
        cv::Mat bgr1[3];
        cv::split(result_mat, bgr1);
        bgr1[0] = field_mat / 255 * 56;
        bgr1[1] = field_mat / 255 * 191;
        bgr1[2] = field_mat / 255 * 94;
        cv::merge(bgr1, 3, field_mat);

        cv::Mat bgr2[3];
        cv::split(result_mat, bgr2);
        bgr2[0] = line_mat / 255 * 60;
        bgr2[1] = line_mat / 255 * 190;
        bgr2[2] = line_mat / 255 * 229;
        cv::merge(bgr2, 3, line_mat);

        Mat line_field_mat = line_mat + field_mat;

        return line_field_mat;
    }
    else if(HSV_flag == 3)
    {
        if(red_topfilter_flag) {return red_mat_C;}
        else {return red_mat;}

    }
    else if(HSV_flag == 4)
    {
        if(blue_topfilter_flag) {return blue_mat_C;}
        else {return blue_mat;}
    }

    return img;
}
void robocup_vision24_obstacle::MainWindow::setting()
{
    //PRE CONDITION : UI
    //POST CONDITION : pan_tilt.ptpos
    //PURPOSE : UI값에 따라 OPER_PAN_TILT 모드일 경우 팬틸트 제어, 현재 틸트는 제어하지 않고 팬만 제어함

    if(scan_value == 1){pan_tilt.ptpos.PAN_POSITION = (-1) * ui.PAN_Scroll->value();}
    else if(scan_value == 0){pan_tilt.ptpos.PAN_POSITION = 0; ui.PAN_Scroll->setValue(pan_tilt.ptpos.PAN_POSITION);}
    else{ui.PAN_Scroll->setValue(pan_tilt.ptpos.PAN_POSITION);}
    pan_tilt.ptpos.TILT_POSITION = TILT_D;

    char TEXT[256];
    sprintf(TEXT, "%d", (int)pan_tilt.ptpos.PAN_POSITION); ui.PAN_Value->setText(TEXT);

    redhsv.hmax = ui.red_hmax_slider->value();
    ui.red_hmax_value->setNum(redhsv.hmax);
    redhsv.hmin = ui.red_hmin_slider->value();
    ui.red_hmin_value->setNum(redhsv.hmin);
    redhsv.smax = ui.red_smax_slider->value();
    ui.red_smax_value->setNum(redhsv.smax);
    redhsv.smin = ui.red_smin_slider->value();
    ui.red_smin_value->setNum(redhsv.smin);
    redhsv.vmax = ui.red_vmax_slider->value();
    ui.red_vmax_value->setNum(redhsv.vmax);
    redhsv.vmin = ui.red_vmin_slider->value();
    ui.red_vmin_value->setNum(redhsv.vmin);
    redhsv.dilate = ui.red_dilate_slider->value();
    ui.red_dilate_value->setNum(redhsv.dilate);
    redhsv.erode = ui.red_erode_slider->value();
    ui.red_erode_value->setNum(redhsv.erode);

    bluehsv.hmax = ui.blue_hmax_slider->value();
    ui.blue_hmax_value->setNum(bluehsv.hmax);
    bluehsv.hmin = ui.blue_hmin_slider->value();
    ui.blue_hmin_value->setNum(bluehsv.hmin);
    bluehsv.smax = ui.blue_smax_slider->value();
    ui.blue_smax_value->setNum(bluehsv.smax);
    bluehsv.smin = ui.blue_smin_slider->value();
    ui.blue_smin_value->setNum(bluehsv.smin);
    bluehsv.vmax = ui.blue_vmax_slider->value();
    ui.blue_vmax_value->setNum(bluehsv.vmax);
    bluehsv.vmin = ui.blue_vmin_slider->value();
    ui.blue_vmin_value->setNum(bluehsv.vmin);
    bluehsv.dilate = ui.blue_dilate_slider->value();
    ui.blue_dilate_value->setNum(bluehsv.dilate);
    bluehsv.erode = ui.blue_erode_slider->value();
    ui.blue_erode_value->setNum(bluehsv.erode);
}

void robocup_vision24_obstacle::MainWindow::load_hsv()
{
    if(HSV_LOAD_flag == 0)
    {
        red1_pos.dist = -999; red1_pos.theta = -999; red2_pos.dist = -999; red2_pos.theta = -999; blue1_pos.dist = -999; blue1_pos.theta = -999; blue2_pos.dist = -999; blue2_pos.theta = -999;
        ifstream Last_HSV_VALUE_IN("/home/robit/catkin_ws/src/robocup_vision24_obstacle/resources/HSV/color_HSV.txt");
        if(Last_HSV_VALUE_IN.is_open())
        {
            Last_HSV_VALUE_IN >> redhsv.hmin;
            Last_HSV_VALUE_IN >> redhsv.smin;
            Last_HSV_VALUE_IN >> redhsv.vmin;
            Last_HSV_VALUE_IN >> redhsv.hmax;
            Last_HSV_VALUE_IN >> redhsv.smax;
            Last_HSV_VALUE_IN >> redhsv.vmax;
            Last_HSV_VALUE_IN >> redhsv.erode;
            Last_HSV_VALUE_IN >> redhsv.dilate;
            Last_HSV_VALUE_IN >> bluehsv.hmin;
            Last_HSV_VALUE_IN >> bluehsv.smin;
            Last_HSV_VALUE_IN >> bluehsv.vmin;
            Last_HSV_VALUE_IN >> bluehsv.hmax;
            Last_HSV_VALUE_IN >> bluehsv.smax;
            Last_HSV_VALUE_IN >> bluehsv.vmax;
            Last_HSV_VALUE_IN >> bluehsv.erode;
            Last_HSV_VALUE_IN >> bluehsv.dilate;

            ui.red_hmax_slider->setValue(redhsv.hmax);
            ui.red_hmin_slider->setValue(redhsv.hmin);
            ui.red_smax_slider->setValue(redhsv.smax);
            ui.red_smin_slider->setValue(redhsv.smin);
            ui.red_vmax_slider->setValue(redhsv.vmax);
            ui.red_vmin_slider->setValue(redhsv.vmin);
            ui.red_dilate_slider->setValue(redhsv.dilate);
            ui.red_erode_slider->setValue(redhsv.erode);

            ui.blue_hmax_slider->setValue(bluehsv.hmax);
            ui.blue_hmin_slider->setValue(bluehsv.hmin);
            ui.blue_smax_slider->setValue(bluehsv.smax);
            ui.blue_smin_slider->setValue(bluehsv.smin);
            ui.blue_vmax_slider->setValue(bluehsv.vmax);
            ui.blue_vmin_slider->setValue(bluehsv.vmin);
            ui.blue_dilate_slider->setValue(bluehsv.dilate);
            ui.blue_erode_slider->setValue(bluehsv.erode);
        }
        else
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!   HSV FILE DONT OPEN   !!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        Last_HSV_VALUE_IN.close();

        ifstream Last_Index_Num_IN("/home/robit/catkin_ws/src/robocup_vision24_obstacle/resources/HSV/HSV.txt");
        if(Last_Index_Num_IN.is_open())
        {
            Last_Index_Num_IN >> fieldhsv.hmin;
            Last_Index_Num_IN >> fieldhsv.hmax;
            Last_Index_Num_IN >> fieldhsv.smin;
            Last_Index_Num_IN >> fieldhsv.smax;
            Last_Index_Num_IN >> fieldhsv.vmin;
            Last_Index_Num_IN >> fieldhsv.vmax;
            Last_Index_Num_IN >> fieldhsv.dilate;
            Last_Index_Num_IN >> fieldhsv.erode;
            Last_Index_Num_IN >> linehsv.hmin;
            Last_Index_Num_IN >> linehsv.hmax;
            Last_Index_Num_IN >> linehsv.smin;
            Last_Index_Num_IN >> linehsv.smax;
            Last_Index_Num_IN >> linehsv.vmin;
            Last_Index_Num_IN >> linehsv.vmax;
            Last_Index_Num_IN >> linehsv.dilate;
            Last_Index_Num_IN >> linehsv.erode;
        }
        else
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!  FIELD FILE DONT OPEN  !!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        Last_Index_Num_IN.close();

        HSV_LOAD_flag = 1;
    }
}

void robocup_vision24_obstacle::MainWindow::save_hsv()
{
    //PRE CONDITION : HSV데이터
    //POST CONDITION : FILESTREAM
    //PURPOSE : HSV 데이터 저장, 사용되지 않음
    if(setting_flag != -1)
    {
        ofstream Last_HSV_VALUE_OUT("/home/robit/catkin_ws/src/robocup_vision24_obstacle/resources/HSV/color_HSV.txt");
        if(Last_HSV_VALUE_OUT.is_open())
        {
            Last_HSV_VALUE_OUT << redhsv.hmin << endl;
            Last_HSV_VALUE_OUT << redhsv.smin << endl;
            Last_HSV_VALUE_OUT << redhsv.vmin << endl;
            Last_HSV_VALUE_OUT << redhsv.hmax << endl;
            Last_HSV_VALUE_OUT << redhsv.smax << endl;
            Last_HSV_VALUE_OUT << redhsv.vmax << endl;
            Last_HSV_VALUE_OUT << redhsv.erode << endl;
            Last_HSV_VALUE_OUT << redhsv.dilate << endl;
            Last_HSV_VALUE_OUT << bluehsv.hmin << endl;
            Last_HSV_VALUE_OUT << bluehsv.smin << endl;
            Last_HSV_VALUE_OUT << bluehsv.vmin << endl;
            Last_HSV_VALUE_OUT << bluehsv.hmax << endl;
            Last_HSV_VALUE_OUT << bluehsv.smax << endl;
            Last_HSV_VALUE_OUT << bluehsv.vmax << endl;
            Last_HSV_VALUE_OUT << bluehsv.erode << endl;
            Last_HSV_VALUE_OUT << bluehsv.dilate << endl;
        }
        else
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!   HSV FILE DONT OPEN   !!!!!!!!!!!!" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        Last_HSV_VALUE_OUT.close();

        ofstream Last_Index_Num_OUT("/home/robit/catkin_ws/src/robocup_vision24_obstacle/resources/HSV/HSV.txt");
        if(Last_Index_Num_OUT.is_open()){
            Last_Index_Num_OUT << fieldhsv.hmin << endl;
            Last_Index_Num_OUT << fieldhsv.hmax << endl;
            Last_Index_Num_OUT << fieldhsv.smin << endl;
            Last_Index_Num_OUT << fieldhsv.smax << endl;
            Last_Index_Num_OUT << fieldhsv.vmin << endl;
            Last_Index_Num_OUT << fieldhsv.vmax << endl;
            Last_Index_Num_OUT << fieldhsv.dilate << endl;
            Last_Index_Num_OUT << fieldhsv.erode << endl;
            Last_Index_Num_OUT << linehsv.hmin << endl;
            Last_Index_Num_OUT << linehsv.hmax << endl;
            Last_Index_Num_OUT << linehsv.smin << endl;
            Last_Index_Num_OUT << linehsv.smax << endl;
            Last_Index_Num_OUT << linehsv.vmin << endl;
            Last_Index_Num_OUT << linehsv.vmax << endl;
            Last_Index_Num_OUT << linehsv.dilate << endl;
            Last_Index_Num_OUT << linehsv.erode << endl;
        }
        Last_Index_Num_OUT.close();
    }
}

void robocup_vision24_obstacle::MainWindow::Print_Screen(const cv::Mat& img, const cv::Mat& result_img)
{
    //PRE CONDITION : img, result_img
    //POST CONDITION : Pixmap
    //PURPOSE : 화면과 객체 데이터를 화면에 표시

    //INIT
    if(scene){delete scene;}
    Mat image_mat;
    if(/*HSV_flag == 0*/false){image_mat = img.clone();}
    else{image_mat = result_img.clone();}

    /*if(HSV_flag == 0 || HSV_flag == 1)  */cvtColor(image_mat, image_mat, COLOR_BGR2RGB);


    QImage image = QImage(image_mat.data, image_mat.cols, image_mat.rows, QImage::Format_RGB888);
    buf = QPixmap::fromImage(image);
    buf = buf.scaled(640, 480);

    scene = new QGraphicsScene(this);
    ui.screen->setScene(scene);
    scene->addPixmap(buf);
}

void robocup_vision24_obstacle::QNode::masterCallback(const msg_generate::master_2_robocup_vision23::ConstPtr &msg)
{
    //PRE CONDITION :  msg
    //POST CONDITION : Scan_Mode
    //PURPOSE : 마스터에서 받아온 Scan_Mode값으로 팬 데이터 수신

    if(ocam_error){scan_value = 99;}
    else{scan_value = msg->Scan_Mode;}

    if(scan_value == 4)
    {
        pan_tilt.ptpos.PAN_POSITION = msg->PAN;
        pan_tilt.ptpos.TILT_POSITION = TILT_D;
    }
}
void robocup_vision24_obstacle::MainWindow::on_btn_mode_0_clicked()
{
    scan_value = 0;
}
void robocup_vision24_obstacle::MainWindow::on_btn_mode_1_clicked()
{
    scan_value = 2;
}
void robocup_vision24_obstacle::MainWindow::on_btn_mode_2_clicked()
{
    scan_value = 3;
}
void robocup_vision24_obstacle::MainWindow::on_btn_mode_3_clicked()
{
    if(save_img_start){save_img_start = 0; ui.btn_mode_3->setText("SAVE");}
    else{save_img_start = 1; ui.btn_mode_3->setText("STOP");}
}
void robocup_vision24_obstacle::MainWindow::on_radioori_clicked(bool checked)
{
    HSV_flag = 1;
    setting_flag = 0;
}
void robocup_vision24_obstacle::MainWindow::on_radionone_clicked(bool checked)
{
    HSV_flag = 0;
    setting_flag = 0;
}
void robocup_vision24_obstacle::MainWindow::on_radiomap_clicked(bool checked)
{
    HSV_flag = 2;
    setting_flag = 0;
}
void robocup_vision24_obstacle::MainWindow::on_radiored_clicked(bool checked)
{
    HSV_flag = 3;
    setting_flag = 0;
}
void robocup_vision24_obstacle::MainWindow::on_radioblue_clicked(bool checked)
{
    HSV_flag = 4;
    setting_flag = 0;
}

void robocup_vision24_obstacle::MainWindow::on_topfilterred_clicked(bool checked)
{
    if(red_topfilter_flag){red_topfilter_flag = false;}
    else{red_topfilter_flag = true;}
}

void robocup_vision24_obstacle::MainWindow::on_topfilterblue_clicked(bool checked)
{
    if(blue_topfilter_flag){blue_topfilter_flag = false;}
    else{blue_topfilter_flag = true;}
}

void robocup_vision24_obstacle::MainWindow::on_btn_oper_pan_tilt_clicked(bool checked)
{
    if(checked){scan_value = 1;}
    else{scan_value = 0;}
}

}  // namespace robocup_vision24_obstacle



