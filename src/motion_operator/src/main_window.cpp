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
#include <fstream>
#include "../include/motion_operator/main_window.hpp" //tw
#include "../include/motion_operator/qnode.hpp" //tw

#include <QKeyEvent> //tw
#include <QDebug> //tw
#include <QStatusBar> //tw

/*****************************************************************************
** Namespaces
*****************************************************************************/

int Motion_Play_Flag =0;

#define STOP_LIM 5

namespace motion_operator {

using namespace Qt;
using namespace std;
using namespace ros;

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

    setInit();

    //    for(int j = 0; j<23; j++){
    //        qnode.Dx_msg_l.position[j] = 512;
    //    }

    for(int i = 0; i < 15; i++)
    {
      m_StepData[i].imu_roll = qnode.imu.roll; //20240501
    }

    for(int i = 0; i<15; i++){
        for(int j = 0; j<23; j++){
            m_StepData[i].Step_pos[j] = Init_Data[j];
        }
    }

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    QObject::connect(&qnode,SIGNAL(Rx_MotionData()),this,SLOT(MotionCallback()));

    QObject::connect(&qnode,SIGNAL(Motion_Sig()),this,SLOT(MotionNumCallback()));
    //    onTimer0();
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Functions
*****************************************************************************/

void MainWindow::setInit(){
    QString real_path = QDir::homePath() + "/catkin_ws/src/motion_operator/Init/init_0507.txt";
    ifstream fin_Init(real_path.toUtf8().constData());

    if(fin_Init.is_open())
    {
        //
        for(int i = 0; i < 23; i++)
        {
            fin_Init >> Init_Data[i];
            late_Data[i] = Init_Data[i];
        }
        cout<<"Fin set Init"<<endl;
        fin_Init.close();
    }

}

void MainWindow::read_WorkFile(int Mt_num){

    /****************************************************************************************************
    *******************************************MOTION_ARRAY**********************************************
    *****************************************************************************************************/

    QString name[30] = {0,};        //name[motion_num] = "motion_name";

        name[1] = "front_abs"; //"nnme_abs_7";//"padak_str";
        name[2] = "back_abs"; //"r_armX59";//"kick_r_abs"//
        name[3] = "back_r_abs"; //"l_armX57"; //
        name[4] = "back_l_abs";
        name[5] = "kick_r"; //"r_armX59";
        name[6] = "kick_l"; //"l_armX57";
        name[7] = "front_abs";
        //technical motion
        name[8] = "dk_fail2";
        name[9] = "dk_ready3";
        name[10] = "dk_kick2";


    /****************************************************************************************************
    *******************************************MOTION_ARRAY**********************************************
    *****************************************************************************************************/

    if(name[Mt_num] == 0){
        Motion_init(15);
    }
    else{
        QString fileName = QDir::homePath() + "/catkin_ws/src/motion_operator/Work/" + name[Mt_num] +".h"; //tw

        cout<<fileName.toStdString()<<endl;
        ifstream fout_Init(fileName.toStdString().c_str());
        if(fout_Init.is_open())
        {
            int cnt=0;
            int value_mode;
            cout<<"AAAAAAAAA"<<fout_Init.eof()<<endl;
            while(!fout_Init.eof()) //파일의 끝까지 한줄씩 읽어옴
            {
                string tmp;
                getline(fout_Init,tmp);
                int step = 0;
                int num =0;
                cout<<"cnt                 "<<cnt<<endl;
                if(++cnt == 7)
                {
                    string relative_str = "robit_format_v500";
                    string absolute_str = "robit_format_v550";

                    if((tmp[15] == relative_str[15]))
                    {
                        value_mode = Relative;

                    }
                    else if((tmp[15] == absolute_str[15]))
                    {
                        value_mode = Absolute;

                    }
                }
                else if(cnt == 15) // 15번째 줄 읽어오기
                {
                    cout<<"value_mode"<<value_mode<<endl;

                    char *str_buff = new char[10000];
                    strcpy(str_buff, tmp.c_str());
                    cout<<str_buff<<endl;
                    char *tok = strtok(str_buff, ",");
                    static int cnt_comma = 0;
                    while (tok != NULL)
                    {

                        cnt_comma++;

                        if(cnt_comma == 1) // max step detect
                        {
                            static int i=0;
                            while(1)
                            {
                                cout<<"-"<<tok[i]<<"|";

                                if(tok[i] == NULL)
                                {

                                    m_MotionData.Max_step =(int)tok[i-1] - '0';

                                    if(tok[i-2] <= '9' && tok[i-2] >= '0')
                                        m_MotionData.Max_step +=((int)tok[i-2] - '0')*10;

                                    break;
                                }
                                i++;
                            }
                            i = 0;

                        }
                        else if(cnt_comma == 3){
                            m_MotionData.Acceleration = stoi(tok);
                        }
                        else if(cnt_comma == 6){
                            m_MotionData.Repeat = stoi(tok);
                        }
                        else if(tok!=NULL && cnt_comma>=10) // time, delay and motor data
                        {
                            if(num < 2)
                            {

                                if(num == 0)
                                {
                                    m_StepData[step].Time = stoi(tok);
                                }

                                else if(num == 1)
                                {
                                    m_StepData[step].Delay = stoi(tok);
                                }

                            }
                            else
                            {

                                if(value_mode == Relative)
                                    m_StepData[step].Step_pos[num-2] = Init_Data[num-2] + stoi(tok);
                                else if(value_mode == Absolute)
                                    m_StepData[step].Step_pos[num-2] = stoi(tok);
                            }
                            num++;
                            //                            cout<<num<<"\t";
                            if(num == 25)
                            {
                                cout<<endl<<step<<":  TcIME>>"<<(int)m_StepData[step].Time<<"      DELAY>>"<<(int)m_StepData[step].Delay<<endl;
                                step++;
                                num = 0;
                            }
                        }
                        if(step == m_MotionData.Max_step)   break;
                        tok = strtok(NULL, ",");
                    }
                    cnt_comma = 0;
                    delete str_buff;
                    break;
                }
            }

            fout_Init.close();
        }

        cout<<endl<<"m_MotionData.Max_step"<<(int)m_MotionData.Max_step<<endl;

        for(int i = 0; i< m_MotionData.Max_step; i++){
            for(int j = 0; j<23; j++)
                cout<<"sTEp "<<i<<"   motor "<<j<<"  "<<(int)m_StepData[i].Step_pos[j]<<"   SPPEED  "<<(int)m_StepData[i].Time<<endl;
            cout<<endl<<endl;
        }
        for(int i = 0; i<5; i++){
            for(int DXL_ID = 0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
                speed[i].RXS[DXL_ID].Speed = 0;
        }
        //        onTimer0();
    }
}

void MainWindow::Motion_init(int time){

    cout<<"INITITITITITNTITNTITNIT"<<endl;
    m_MotionData.Max_step = 1;
    m_MotionData.Acceleration = 0;
    m_MotionData.Repeat = 1;

    cout<<"m_MotionData.Max_step"<<m_MotionData.Max_step<<endl;

    m_StepData[0].Delay = 0;
    m_StepData[0].Time  = time;

    for(int j = 0; j<23; j++){
    //for(int j = 0; j<19; j++){
        m_StepData[0].Step_pos[j] = Init_Data[j];
    }

    for(int j = 0; j<23; j++)
    //for(int j = 0; j<19; j++)
        cout<<"INITINTIT    MOTOR"<<j<<"     "<<(int)m_StepData[0].Step_pos[j]<<" SPPEED  "<<(int)m_StepData[0].Time<<endl;

    cout<<endl<<endl;

    for(int i = 0; i<5; i++){
        for(int DXL_ID = 0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
            speed[i].RXS[DXL_ID].Speed = 0;
    }
    //    onTimer0();
}

void MainWindow::MotionNumCallback(){
    if(MT_Flag == false){
        read_WorkFile(qnode.motionNum);
        cout<<"EEEEE"<<endl;
        onTimer0();
    }
}

void MainWindow::on_pushButton_StartMt_clicked(){
    if(MT_Flag == false){
        int Motion_num = ui.lineEdit_MtNum->text().toInt();
        cout<<"Motion_num "<<Motion_num<<endl;
        read_WorkFile(Motion_num);
        onTimer0();
    }
}


void MainWindow::on_pushButton_STOP_clicked()
{
    cout<<m_Timer<<endl;
    if(MT_Flag == true)
        MT_STOP = true;
    else if(MT_Flag == false){
        cout<<"OFFFFFF:<"<<endl;
        Motion_init(80);
        cout<<(int)m_MotionData.Max_step<<endl<<(int)m_MotionData.Repeat<<endl;
        cout<<(int)m_StepData[0].Time<<endl<<(int)m_StepData[0].Delay<<endl;
        if(MT_Flag == false){
            onTimer0();
        }
        MT_STOP = false;
    }
}

uint16_t MainWindow::AccTime_Calc(uint8_t AccStep_Number)
{
    uint16_t AccTime = 0;
    if (m_StepData[AccStep_Number].Time < m_MotionData.Acceleration * 2)
        AccTime = m_StepData[AccStep_Number].Time >> 1 ;
    else
        AccTime = m_MotionData.Acceleration;
    if (AccTime == 0)       AccTime = 1;
    return AccTime;
}

DATA MainWindow::Speed_Calc(uint8_t Step_Number, uint8_t DXL_ID, unsigned int *DXL_half_flag, unsigned int *DXL_Acclink, unsigned int *Acting_Time_Acc)
{
#define RPMgain 60  //속도에 따른 초당 움직이는 거리 Gain
    DATA Temp_Position;
    uint8_t min_flag= 0;
    uint8_t DXL_Vector;
    uint8_t i = 0;
    uint16_t TSP,TEP;
    uint16_t DXL_S[5];
    uint16_t DXL_V[5];
    double ALU_num[8]  = {0};
    float roll = qnode.imu.roll; //20240429
    // 가속 시간 계산
    Acting_Time_Acc[0] = AccTime_Calc(Step_Number);
    // 변위량 계산 및 이동 방향 플레이 셋
    if(Step_Number == 0|| Step_Number == 7 || Step_Number == 11){
    //if(Step_Number == 1|| Step_Number == 8 || Step_Number == 12){
        //        if(qnode.Dx_msg_l.id.size()>0)
        //            TSP     = qnode.Dx_msg_l.position[DXL_ID] >> 2;
        //        else
        TSP     = late_Data[DXL_ID];
        //        TSP     = m_StepData[0].Step_pos[DXL_ID];
    }
    else
    TSP     = m_StepData[Step_Number-1].Step_pos[DXL_ID];     //TSP     = Motion.Step[Step_Number-1].RXP[DXL_ID].Position;
    TEP   = m_StepData[Step_Number].Step_pos[DXL_ID];            //          Motion.Step[Step_Number].RXP[DXL_ID].Position;
    cout<<"TSP::"<<TSP<<"  TEP::"<<TEP;
    if(TEP > TSP)
    {
        DXL_S[0] = TEP - TSP;
        DXL_Vector = 0x01;
    }
    else if(TEP < TSP)
    {
        DXL_S[0] = TSP - TEP;
        DXL_Vector = 0x10;
    }
    else
    {
        DXL_Vector = 0;
    }

    // 시간축 7.8ms 기준, RPM 스펙에 따른 변위 조절
    DXL_S[0] = DXL_S[0] * RPMgain;
    // 변위에 따른 등속 속도 자료 추출
    DXL_S[0] = DXL_S[0] / m_StepData[Step_Number].Time;
    // 가속 부분 추가 속도 계산
    ALU_num[0] = (DXL_S[0] * Acting_Time_Acc[0])
            / ((m_StepData[Step_Number].Time -  Acting_Time_Acc[0]) * 2);
    DXL_V[0] = DXL_S[0] + ALU_num[0];
    // 무한 가감속 루프
    while(1)
    {
        i++;
        //        i-=1;
        if(i >= 4){
            cout<<endl;
            break;
        }
        // 가감속의 방향이 일치 검사
        if( Step_Number+i < m_MotionData.Max_step)
        {
            if(TSP == 0){
                cout<<endl;
                break;
            }
            TSP   = m_StepData[Step_Number+i-1].Step_pos[DXL_ID];
            TEP   = m_StepData[Step_Number+i].Step_pos[DXL_ID];
            // cout<<Step_Number<<"  Step_Num+i:"<<Step_Number+i<< "  TSP: "<<TSP<<" TEP: "<<TEP<<endl; //tw
            if(Motion_Play_Flag != 1 ) break;
            else if(m_StepData[Step_Number+i-1].Delay != 0) break;
            else if((TEP > TSP) && (DXL_Vector & 0x01))     DXL_S[i] = TEP - TSP;
            else if((TEP < TSP) && (DXL_Vector & 0x10)) DXL_S[i] = TSP - TEP;
            else break;
        }
        else{
            cout<<endl;
            break;
        }
        Acting_Time_Acc[i] = AccTime_Calc(Step_Number+i);
        DXL_S[i] = DXL_S[i] * RPMgain;
        DXL_S[i] = DXL_S[i] / m_StepData[Step_Number+i].Time;
        // 가감속 링크의 서로 속도차 계산
        if(DXL_S[i-1] < DXL_S[i]) ALU_num[1] = DXL_S[i] - DXL_S[i-1];
        else ALU_num[1] = DXL_S[i-1] - DXL_S[i];
        // 가감속 속도 중간점 변경 플래그 검사
        if(min_flag)
        {
            cout<<"\nmin_flag::"<<min_flag<<endl; //tw
            ALU_num[2] = ((DXL_S[i-1]) * Acting_Time_Acc[i-1])
                    / (2*( m_StepData[Step_Number+i-1].Time - Acting_Time_Acc[i-1]));
            ALU_num[3] = (((DXL_S[i] - (DXL_S[i-1] * 2)) * Acting_Time_Acc[i]) / (4 * ( m_StepData[Step_Number+i].Time
                                                                                  -  Acting_Time_Acc[i])));
            DXL_half_flag[DXL_ID] |= ( 0x10 << (i-1) );
            min_flag = 0;
        }
        else
        {
            cout<<"min_flag::"<<min_flag<<endl; //tw
            ALU_num[2] = ( ALU_num[1] * Acting_Time_Acc[i-1]) / (4 * ( m_StepData[Step_Number+i-1].Time
                                                                 -  Acting_Time_Acc[i-1]));
            ALU_num[3] = ( ALU_num[1] * Acting_Time_Acc[i]) / (4 * ( m_StepData[Step_Number+i].Time
                                                               -  Acting_Time_Acc[i]));
        }
        if(DXL_S[i-1] < DXL_S[i])
        {
            cout<<"ACCELERATION"<<endl; //tw
            DXL_V[i-1] -= ALU_num[2];
            DXL_V[i] = DXL_S[i] + ALU_num[3];
        }
        else
        {
            cout<<"DECELERATION"<<endl; //tw
            DXL_V[i-1] += ALU_num[2];
            DXL_V[i] = DXL_S[i] - ALU_num[3];
        }
        // 중간점 미이동 오차 발생 검사 부분?
        if(DXL_V[i-1] & 0x8000)
        {
            if(Step_Number+i-1 == 1)
            {
                cout<<"First Step Error"<<endl; //tw
                DXL_V[i-1] = DXL_S[i-1];
            }
            else
            {
                cout<<"Another Error"<<endl; //tw
                ALU_num[2] = (((DXL_S[i-2] - (DXL_S[i-1] * 2)) * Acting_Time_Acc[i-2]))
                        / (2 * ( m_StepData[Step_Number+i-2].Time -  Acting_Time_Acc[i-2]));
                DXL_V[i-2] = DXL_V[i-2] + ALU_num[3] - ALU_num[6];
                ALU_num[3] = ((DXL_S[i-1]) * Acting_Time_Acc[i-1])
                        / (2*( m_StepData[Step_Number+i-1].Time - Acting_Time_Acc[i-1]));
                DXL_V[i-1] = DXL_S[i-1] - ALU_num[3];
                DXL_half_flag[DXL_ID] |= ( 0x01 << (i-2) );
            }
            ALU_num[3] = (((DXL_S[i] - (DXL_S[i-1] * 2)) * Acting_Time_Acc[i]))
                    / (2 * ( m_StepData[Step_Number+i].Time - Acting_Time_Acc[i]));
            DXL_V[i] = DXL_S[i] + ALU_num[3];
            DXL_half_flag[DXL_ID] |= ( 0x10 << (i-1) );
            min_flag = 2;
        }
        else if(DXL_V[i] & 0x8000)
        {
            cout<<"Current Step Error"<<endl; //tw
            DXL_V[i] = DXL_S[i];
            ALU_num[2] = ((DXL_S[i-1] - (DXL_S[i] * 2)) * Acting_Time_Acc[i-1])
                    / (2 * (m_StepData[Step_Number+i-1].Time - Acting_Time_Acc[i-1]));
            DXL_V[i-1] = DXL_S[i-1] + ALU_num[0] + ALU_num[2];
            DXL_half_flag[DXL_ID] |= ( 0x01 << (i-1) );
            min_flag = 1;
        }

        // 링크 횟수 체크
        DXL_Acclink[DXL_ID] = i | 0x80;
        cout<<DXL_ID<<"AAAAAAAAAAAAAAAAAA "<<DXL_Acclink[DXL_ID]; //?

        ALU_num[5] = ALU_num[1];
        ALU_num[6] = ALU_num[2];
        ALU_num[7] = ALU_num[3];
    }
    i--;
    if(!(min_flag == 1))
    {
        cout<<"\nmin_flag::false"<<min_flag<<endl;
        ALU_num[4] = (DXL_S[i] * Acting_Time_Acc[i])
                / ((m_StepData[Step_Number+i].Time - Acting_Time_Acc[i]) * 2);
        DXL_V[i] += ALU_num[4];
    }
    // 포지션 스피트 적용 부분?
    //    cout<<Step_Number<<"STEP "<<Step_Number+i<<endl;
    Temp_Position.Word = m_StepData[Step_Number+i].Step_pos[DXL_ID];
    do
    {
        // if(Motor[DXL_ID] == 2) speed[i].RXS[DXL_ID].Speed = DXL_V[i] * 1.1;
        //else if(Motor[DXL_ID] == 3) speed[i].RXS[DXL_ID].Speed = DXL_V[i] * 2.2;
        speed[i].RXS[DXL_ID].Speed = DXL_V[i] * 1.1;
//        cout<<"DXL_V[i] "<<DXL_V[i];
//        cout<<"   SpeedDXL_V[i] * 1.1:: "<<DXL_V[i] * 1.1<<"\n";
    }
    while(i--);
    return Temp_Position;
}

void MainWindow::TimerCallback()
{
    #define limit_roll_L       -4.5 //20240501
    #define limit_roll_R       9 //8.5 //20240502
    #define limit_pitch_front  10
    #define limit_pitch_rear   -12

    uint8_t DXL_ID                          = 0;
    static uint8_t ParaCount                       = 0;
    static DATA Temp_Position;
    static DATA RXS;
    static unsigned int Acting_Time_Acc[5];
    static unsigned int DXL_half_flag[24] = { 0 };
    static unsigned int DXL_Acclink[24] = { 0 };
    static unsigned int mt_Num; //20240430
    static uint16_t limit_10; //20240430
    static uint16_t limit_11; //20240430
    static uint16_t limit_20; //20240430
    static uint16_t limit_21; //20240430
    static uint16_t limit_14; //20240430
    static uint16_t limit_15; //20240430
    static uint16_t limit_16; //20240502
    static uint16_t limit_17; //20240502
    static uint16_t limit_18; //20240430
    static uint16_t limit_19; //20240430
    static uint8_t Step_Number;
    static uint8_t State_Number = 0;
    static uint8_t Max_Step = 0;
    static uint8_t Max_Count = m_MotionData.Repeat;
    static uint8_t Calc_Num[23] = { 0 };
    static uint16_t AccelCount = 1;

    //20240409
    float yaw = qnode.imu.yaw;
    float pitch = qnode.imu.pitch;
    float roll = qnode.imu.roll;

    limit_10 = m_StepData[1].Step_pos[10];
    limit_11 = m_StepData[1].Step_pos[11];
    limit_20 = m_StepData[1].Step_pos[20];
    limit_21 = m_StepData[1].Step_pos[21];
    limit_14 = m_StepData[1].Step_pos[14];
    limit_15 = m_StepData[1].Step_pos[15];
    limit_16 = m_StepData[1].Step_pos[16];
    limit_17 = m_StepData[1].Step_pos[17];
    limit_18 = m_StepData[1].Step_pos[18];
    limit_19 = m_StepData[1].Step_pos[19];

    static int m_delayTime = 0;
    static bool isDelay = false;
    static int accCnt=0;

    mt_Num = ui.lineEdit_MtNum->text().toInt(); //20240430
    State_Number = 0;
    Max_Count = m_MotionData.Repeat;
    Max_Step = m_MotionData.Max_step;
    Motion_Play_Flag = 1;
    //    cout<<"MAX_STEP"<<Max_Step<<endl;

    if(NowRepeat >= Max_Count || (MT_STOP == true&&NowStep<STOP_LIM)){
        NowRepeat = 0;
        NowState = 0;
        NowStep = 0;
        late_Data[DXL_ID] = Temp_Position.Word/4;
        for(int i = 0; i< 5; i++)
            Acting_Time_Acc[i] = 0;
        for(int i = 0; i<24; i++){
            DXL_half_flag[i] = 0;
            DXL_Acclink[i] = 0;

        }
        offTimer0();
    }
    else{
        if(NowStep >= Max_Step){
            NowStep = 0;
            NowRepeat += 1;
        }
        else{
            Step_Number = NowStep;

            switch (NowState) {
            case 0:{             //Set Pos

                cout<<"----MOTION---- "<<NowRepeat<<" || "<<(int)Step_Number<<"-----"<<endl;
                cout << "roll:: "<< roll << endl;
                cout << "pitch:: "<< pitch << endl;
                //            Parameter[0] = P_GOAL_POSITION_L;  	//Address of P_GOAL_POSITION_L
                //            Parameter[1] = 2;   				//쓰고자하는 DATA의 길이
                Dx_msg.mode = 3;
                Dx_msg.id.clear();
                Dx_msg.position.clear();
                for(int i = 0; i< 5; i++)
                    Acting_Time_Acc[i] = 0;
                for(int i = 0; i<24; i++){
                    DXL_half_flag[i] = 0;
                    DXL_Acclink[i] = 0;
                }

                for(DXL_ID=0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
                {
                    if(!DXL_Acclink[DXL_ID])
                    {
                        cout<<DXL_Acclink[DXL_ID]<<"  ";
                        Temp_Position =
                                Speed_Calc(Step_Number, DXL_ID,DXL_half_flag,DXL_Acclink,Acting_Time_Acc);
                        Calc_Num[DXL_ID] = 0;
                    }
                    else
                    {
                        cout<<DXL_ID<<"  "<<DXL_Acclink[DXL_ID]<<"  "<<endl;
                        Temp_Position.Word =
                                m_StepData[Step_Number+DXL_Acclink[DXL_ID]].Step_pos[DXL_ID];
                        Calc_Num[DXL_ID]++;
                    }
                    //                    m_StepData[0].Step_pos[DXL_ID] = Temp_Position.Word;

                    //                    cout<<Temp_Position.Word<<"  | "<<DXL_ID<<" |   ";
                    Temp_Position.Word *= 4;
                    //                    cout<<Temp_Position.Word<<endl;


                    ////MOTION CONTROL////
                    if(mt_Num == 1 || mt_Num == 2 || qnode.motionNum == 2) //20240430
                    {

                      if(roll < limit_roll_L)
                      {
                        cout << ">>>>>>>>FALL DOWN LEFT<<<<<<<<" << endl;
                        cout << "roll | " << roll << " || limit_roll_L | " << limit_roll_L << endl;
                        for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240501
                        {
                          m_StepData[i].Step_pos[3]++;
                          m_StepData[i].Step_pos[10] = limit_10 + 1;
                          m_StepData[i].Step_pos[20] = limit_20 + 1;
                          if(roll > limit_roll_L)
                            break;
                        }
                      }
                    }

                    else if(mt_Num == 1 || mt_Num ==3 || qnode.motionNum == 3)
                    {
                      if(roll > limit_roll_R) //20240502
                      {
                        cout << ">>>>>>>>FALL DOWN RIGHT<<<<<<<<" << endl;
                        cout << "roll | " << roll << " || limit_roll_R | " << limit_roll_R << endl;
                        for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240502
                        {
                          m_StepData[i].Step_pos[2]--;
                          m_StepData[i].Step_pos[11] = limit_11 -1;
                          m_StepData[i].Step_pos[21] = limit_21 - 1;
                          if(roll < limit_roll_R)
                            break;
                        }
                      }
                    }

                    Dx_msg.id.push_back(DXL_ID);
                    Dx_msg.position.push_back(Temp_Position.Word);
                    late_Data[DXL_ID] = Temp_Position.Word/4;
                    Dx_msg.length = Dx_msg.id.size();
                }
                Dx_msg.speed.clear();
                NowState = 1;
                AccelCount = 1;

                break;
            }

            case 1:{             //Acc
                if(AccelCount < Acting_Time_Acc[0]){
                    for(DXL_ID=0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
                    {

                        if((DXL_Acclink[DXL_ID]) && !(DXL_Acclink[DXL_ID] & 0x80))
                        {
                            if(DXL_half_flag[DXL_ID] & 0x10)
                            {

                                RXS.Word = speed[Calc_Num[DXL_ID]-1].RXS[DXL_ID].Speed * 2
                                        + (((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]-1].RXS[DXL_ID].Speed * 2)
                                           / (float)Acting_Time_Acc[0] ) * AccelCount));
                                                                cout<<RXS.Word<<" a ";
                            }
                            else if(DXL_half_flag[DXL_ID] & 0x01)
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed * 2
                                        - ((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                            / (float)Acting_Time_Acc[0] ) * AccelCount));
                                                                cout<<RXS.Word<<" b ";
                            }
                            else if(speed[Calc_Num[DXL_ID]-1].RXS[DXL_ID].Speed < speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed)
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        - (((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]-1].RXS[DXL_ID].Speed )
                                           / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)) / 2);
                                                                cout<<RXS.Word<<" c  ";
                            }
                            else
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        + (((( speed[Calc_Num[DXL_ID]-1].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed )
                                           / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)) / 2);
                                                                cout<<RXS.Word<<" d ";
                            }
                        }
                        else {
                            RXS.Word = (speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed / (float)Acting_Time_Acc[0]) * AccelCount;//main
                        }


                        if (RXS.Word > 1023)
                        {
                            RXS.Word = 1023;
                            cout<<"RXS.Word::"<<RXS.Word<<"\n";
                        }
                        else if (RXS.Word == 0)
                        {
                            RXS.Word = 1;
                            cout<<"RXS.Word::"<<RXS.Word<<"\n";
                        }

                        Dx_msg.speed.push_back(RXS.Word);

                    }

                    ////MOTION CONTROL////
                    if(mt_Num == 1 || mt_Num == 2 || qnode.motionNum == 2)
                    {
                      if(roll < limit_roll_L)
                      {
                        for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240501
                        {
                          m_StepData[i].Step_pos[3]++;
                          m_StepData[i].Step_pos[10] = limit_10 + 1;
                          if(roll > limit_roll_L)
                            break;
                        }
                      }
                    }

                    else if(mt_Num == 1 || mt_Num ==3 || qnode.motionNum == 3)
                    {
                      if(roll > limit_roll_R) //20240502
                      {
                        cout << ">>>>>>>>FALL DOWN RIGHT<<<<<<<<" << endl;
                        cout << "roll | " << roll << " || limit_roll_R | " << limit_roll_R << endl;
                        for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240502
                        {
                          m_StepData[i].Step_pos[2]--;
                          m_StepData[i].Step_pos[11] = limit_11 -1;
                          m_StepData[i].Step_pos[21] = limit_21 - 1;
                          if(roll < limit_roll_R)
                            break;
                        }
                      }
                    }

                    // qnode.Motion_Pub.publish(Motion_msg); // 20240402tw
                    qnode.Motor_Pub.publish(Dx_msg);
                    Dx_msg.speed.clear();
                    accCnt++;
                    AccelCount++;
                }
                else{

                    for(DXL_ID=0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
                    {
                        if(DXL_Acclink[DXL_ID])
                        {
                            if(DXL_Acclink[DXL_ID] & 0x80)  DXL_Acclink[DXL_ID] &= ~0x80;
                            else
                            {
                                if(DXL_half_flag[DXL_ID] & 0x01) DXL_half_flag[DXL_ID] &= ~0x01;
                                if(DXL_half_flag[DXL_ID] & 0x10) DXL_half_flag[DXL_ID] &= ~0x10;
                                DXL_half_flag[DXL_ID] >>= 1;
                                DXL_Acclink[DXL_ID]--;
                            }
                        }
                        RXS.Word =  speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed;
                        if (RXS.Word > 1023)        RXS.Word = 1023;
                        else if (RXS.Word == 0) RXS.Word = 1;
                        //                    if(DXL_ID<10)
                        //                        cout<<RXS.Word<<"   ";

                        Dx_msg.speed.push_back(RXS.Word);

                    }
                    qnode.Motor_Pub.publish(Dx_msg);
                    cout<<"accCnt"<<accCnt<<endl;
                    AccelCount = 1;
                    NowState = 2;
                }


                break;
            }
            case 2:{             //Const
                uint16_t Main_Delay = m_StepData[Step_Number].Time - (Acting_Time_Acc[0] * 2) + m_StepData[Step_Number].Delay + 16;

                static uint16_t T_delay = 0;

                if(T_delay <= Main_Delay){
                    accCnt++;
                    T_delay++;
                    cout<<"T_delay"<<T_delay<<"\n"; //tw
                    cout<<"Main_Delay"<<Main_Delay<<"\n"; //tw
                }
                else{
                    //cout<<"constCnt"<<accCnt<<endl; //time-20
                    T_delay = 0;
                    NowState = 3;
                    AccelCount = Acting_Time_Acc[0];
                    cout<<"T_delay"<<T_delay<<"\n"; //tw
                    cout<<"Main_Delay"<<Main_Delay<<"\n"; //tw
                }

                break;
            }
            case 3: {            //Dec

                if(AccelCount > 1){
                    for(DXL_ID=0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
                    {
                        if(DXL_Acclink[DXL_ID])
                        {
                            if(DXL_half_flag[DXL_ID] & 0x10)
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        + ((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                            / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)));
                            }
                            else if(DXL_half_flag[DXL_ID] & 0x01)
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        - (((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]+1].RXS[DXL_ID].Speed * 2 )
                                           / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)));
                            }
                            else if(speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed < speed[Calc_Num[DXL_ID]+1].RXS[DXL_ID].Speed)
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        + (((( speed[Calc_Num[DXL_ID]+1].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed )
                                           / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)) / 2);
                            }
                            else
                            {
                                RXS.Word = speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                        - (((( speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed
                                             - speed[Calc_Num[DXL_ID]+1].RXS[DXL_ID].Speed )
                                           / (float)Acting_Time_Acc[0] ) * (Acting_Time_Acc[0] - AccelCount)) / 2);
                            }
                        }
                        else    RXS.Word =  (speed[Calc_Num[DXL_ID]].RXS[DXL_ID].Speed / (float)Acting_Time_Acc[0]) * AccelCount;
                        if (RXS.Word > 1023)        RXS.Word = 1023;
                        else if (RXS.Word == 0) RXS.Word = 1;

                        ////MOTION CONTROL////
                        if(mt_Num == 1 || mt_Num == 2 || qnode.motionNum == 2)
                        {
                          if(roll < limit_roll_L)
                          {
                            for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240501
                            {
                              m_StepData[i].Step_pos[3]++;
                              m_StepData[i].Step_pos[10] = limit_10 + 1;
                              if(roll > limit_roll_L)
                                break;
                            }
                          }
                        }

                        else if(mt_Num == 1 || mt_Num ==3 || qnode.motionNum == 3)
                        {
                          if(roll > limit_roll_R) //20240502
                          {
                            cout << ">>>>>>>>FALL DOWN RIGHT<<<<<<<<" << endl;
                            cout << "roll | " << roll << " || limit_roll_R | " << limit_roll_R << endl;
                            for(int i = 0; i < m_MotionData.Max_step - 1; i++) //20240502
                            {
                              m_StepData[i].Step_pos[2]--;
                              m_StepData[i].Step_pos[11] = limit_11 -1;
                              m_StepData[i].Step_pos[21] = limit_21 - 1;
                              if(roll < limit_roll_R)
                                break;
                            }
                          }
                        }

                        Dx_msg.speed.push_back(RXS.Word);

                    }
                    qnode.Motor_Pub.publish(Dx_msg);
                    Dx_msg.speed.clear();
                    AccelCount--;
                    accCnt++;
                }
                else{
                    //cout<<"decCnt"<<accCnt<<endl; // time-1
                    //                    offTimer0();
                    NowState = 0;
                    accCnt = 0;
                    AccelCount = 1;
                    NowStep++;
                }


                break;
            }
            default:
                break;
            }
        }


    }


}

void MainWindow::MotionCallback()
{

    m_MotionData.Max_step = qnode.Motion_msg.max_step;
    m_MotionData.Acceleration = qnode.Motion_msg.acc;
    m_MotionData.Repeat = qnode.Motion_msg.repeat;

    cout<<"m_MotionData.Max_step"<<m_MotionData.Max_step<<endl;

    for(int i = 0; i < m_MotionData.Max_step; i++){

        m_StepData[i].Delay = qnode.Motion_msg.motion_data[i].delay;
        m_StepData[i].Time  = qnode.Motion_msg.motion_data[i].time;

        for(int j = 0; j<qnode.Motion_msg.motion_data[i].position.size(); j++){
            m_StepData[i].Step_pos[j] = qnode.Motion_msg.motion_data[i].position[j]/4;
        }
    }

    for(int i = 0; i< m_MotionData.Max_step; i++){
        for(int j = 0; j<23; j++)
            cout<<"sTEp "<<i<<"  motor  "<<j<<"    "<<(int)m_StepData[i].Step_pos[j]<<" SPPEED  "<<(int)m_StepData[i].Time<<endl;

        cout<<endl<<endl;
    }
    for(int i = 0; i<5; i++){
        for(int DXL_ID = 0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
            speed[i].RXS[DXL_ID].Speed = 0;
    }
    if(MT_Flag == false)
        onTimer0();
}

void MainWindow::onTimer0()
{
    cout<<"on TIMERTIMER"<<endl;
    for(int i = 0; i<5; i++){
        for(int DXL_ID = 0; DXL_ID <= MAX_DXL_NUM; DXL_ID++)
            speed[i].RXS[DXL_ID].Speed = 0;
    }
    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()),this, SLOT(TimerCallback()));
    m_Timer->start(7.8); //7.8ms
    MT_Flag = true;
}

void MainWindow::offTimer0()
{
    cout<<"ENDMOTION"<<endl;
    NowRepeat = 0;
    NowState = 0;
    NowStep = 0;
    disconnect(m_Timer, SIGNAL(timeout()),this, SLOT(TimerCallback()));
    m_Timer->stop();
    delete m_Timer;
    MT_Flag = false;
    msg_generate::motion_end MT_end;
    MT_end.motion_end = 1;
    //Motion_init(80); //20240429
    qnode.Serial_pub.publish(MT_end);


    if(MT_STOP == true){
        cout<<"OFFFFFF:<"<<endl;
        Motion_init(150);
        cout<<(int)m_MotionData.Max_step<<endl<<(int)m_MotionData.Repeat<<endl;
        cout<<(int)m_StepData[0].Time<<endl<<(int)m_StepData[0].Delay<<endl;
        //        int i = 0;
        //        while(i>50){
        //            i++;
        //        };
        if(MT_Flag == false){
            onTimer0();
        }
        MT_STOP = false;
    }

}

}  // namespace motion_operator


