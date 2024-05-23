#include "../include/ik_walk/ik_walk.hpp"

using namespace std;
Robit_Humanoid_Walk Walk;
double data[FILTERDATA];
double temp;

int main(int argc, char **argv)
{
    //awdawdawdawdawd
    ros::init(argc, argv, "ik_walk");
    ros::NodeHandle Robit;

    //SUBSCIRBE_MSG
    Imu_Sub = Robit.subscribe("imu",100,imu_callback);
    Tune2walk_Sub = Robit.subscribe("tune2walk",100,tune2walk_callback);
    Master2ik_Sub = Robit.subscribe("master2ik",100,master2ik_callback);
    Zmp_Sub = Robit.subscribe("zmp_msg",100,zmp_callback);

    //PUBLISH_MSG
    Ikend_Pub = Robit.advertise<msg_generate::ikend_msg>("ikend",100);
    IK.Motor_Pub = Robit.advertise<msg_generate::Motor_msg>("Dynamixel", 100);
    Ikcoordinate_Pub = Robit.advertise<msg_generate::ikcoordinate_msg>("ikcoordinate", 100);
    walk_pattern_Pub = Robit.advertise<msg_generate::walk_pattern>("walk_pattern",100);
    Com_Pub = Robit.advertise<msg_generate::com_msg>("COM",100);
    IK.Motor_Position_Pub = Robit.advertise<msg_generate::ik_angle_sim>("sim_position", 100);//simulation
    Landing_Pub = Robit.advertise<msg_generate::Landing_Time_Control>("Landing_Time_Control",100);

    ros::Timer timer = Robit.createTimer(ros::Duration(0.01),timer_callback);
    IK.init_save();
    sleep(1);
    get_parameters();
    Landing_flag_L = true;
    Landing_flag_R = true;
    Walk.Generate_Pattern(Now_Param);
    IK.Balance_Control_Body_Upright(0,Now_Param.Z.Default_Z_Right,Init_Position_Time,Init_Rise_Condition,Init_Position_Pitch,Init_Position_Balance_Msg,Init_Position_Balance_Msg,0,0,0,0,0,Model_Data.Link2Link,0,0,99);

    IK.solve(0.0, Now_Param.Y.Default_Y_Right,Now_Param.Z.Default_Z_Right, 0.0, 0.0,Now_Param.Y.Default_Y_Left,Now_Param.Z.Default_Z_Left, 0.0, All,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    sleep(1);

    while(ros::ok())// cycle
    {
        ros::spinOnce();
    }

    return 0;

}
void Robit_Humanoid_Walk::Walk_Start_End(Walk_Parameters &Now_Param)
{
    if(Past_Param.IK_Flag != Ik_Flag_Past)
    {
        if(Past_Param.IK_Flag)
        {
            Start_Flag = true;
            cout<<"Start_Flag"<<endl;
        }
        else if(!Past_Param.IK_Flag && Timer_Time==0)
        {
            End_Flag = true;
            cout<<"End_Flag"<<endl;
        }
    }
    if(Start_Flag)
    {
        IK.Now_Motor_Angle = IK.Past_Motor_Angle;
        IK.Now_Percentage_of_IK_Motor = IK.Past_Percentage_of_IK_Motor;
        if(Timer_Time_Start ==0.0)
        {
            Now_Param.IK_Flag = true;

            cout<<"%%%%%%%%%%%%%%%%%%"<<  Start_Cnt <<"%%%%%%%%%%%%"<<endl;
            Start_Cnt++;
        }

        if(Start_Cnt >=Repeat_Start_Cycle)
        {
            Timer_Time = Timer_Time_Start;
            if(fabs(Timer_Time_Start-Timer_Time)<3)
            {
                Start_Cnt =1;
                Start_Flag = false;
                Ikend_Info.ikend = 0;
                Ikend_Pub.publish(Ikend_Info);
            }
        }
    }

    else if(End_Flag)
    {
        if(Timer_Time_End ==0)
        {
            End_Cnt--;
        }
        if(End_Cnt<1 && Timer_Time_End==0)
        {
            End_Cnt=Repeat_End_Cycle;
            End_Flag=false;
            Now_Param.IK_Flag = false;
            Ik_Flag_Past = false;
            Timer_Time_End =0.0;

            Swing_Control_L = 1.0;
            Swing_Control_R = 1.0;
            Swing_Control_add_L = 1.0;
            Swing_Control_add_R = 1.0;
            Swing_Control_Safe_cnt = 0;
            Swing_Control_Warning_cnt = 0;
            Landing_Info.Swing_Gain_L = Swing_Control_L;
            Landing_Info.Swing_Gain_R = Swing_Control_R;
            Landing_Info.Landing_Time_L = 0;
            Landing_Info.Landing_Time_R = 0;
            Landing_Info.Landing_Error_L = 0;
            Landing_Info.Landing_Error_R = 0;
            Landing_Pub.publish(Landing_Info);


            IK.Now_Motor_Angle = IK.Past_Motor_Angle;
            IK.Now_Percentage_of_IK_Motor = IK.Past_Percentage_of_IK_Motor;
            IK.solve(0.0, Now_Param.Y.Default_Y_Right,Now_Param.Z.Default_Z_Right, 0.0, 0.0, Now_Param.Y.Default_Y_Left, Now_Param.Z.Default_Z_Left, 0.0, Leg,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
            Ikend_Info.ikend = 1;
            Ikend_Pub.publish(Ikend_Info);
        }
    }

    if(Now_Param.IK_Flag && (Start_Flag || End_Flag))
    {
        Result_Pattern(Now_Param);
        if(Start_Flag) End_Cnt = Repeat_End_Cycle;
        else if(End_Flag) Start_Cnt = 1;

    }
    else if(Now_Param.IK_Flag && (!Start_Flag && !End_Flag))
    {
        cout<<"normal"<<endl<<endl;
        Result_Pattern(Now_Param);
    }
}
void Robit_Humanoid_Walk::Generate_Pattern(Walk_Parameters &Now_Param)
{
    ///////////////////////////Single_OR_Double_Pattern///////////////////////////

        if(Balancing_Param.Balance.Ratio_Check_Flag == 1)
        {

            ///////////////////////////Start_Pattern///////////////////////////

            Start_COM_Pattern.put_point(0.0,  0.0,  7.0,  0.0);
            Start_COM_Pattern.put_point(0.1,  0.7,  0.0,  0.0);
            Start_COM_Pattern.put_point(0.2,  1.0,  0.0,  0.0);
            Start_COM_Pattern.put_point(0.3,  1.0,  0.0,  0.0);
            Start_COM_Pattern.put_point(0.4,  0.7,  -7.0,  0.0);
            Start_COM_Pattern.put_point(0.5,  0.0,  -7.0,  0.0);
            Start_COM_Pattern.put_point(0.6,  -0.7,  -7.0,  0.0);
            Start_COM_Pattern.put_point(0.7,  -1.0,  0.0,  0.0);
            Start_COM_Pattern.put_point(0.8,  -1.0,  0.0,  0.0);
            Start_COM_Pattern.put_point(0.9,  -0.7,  0.0,  0.0);
            Start_COM_Pattern.put_point(1.0,  0.0,  7.0,  0.0);

            Start_Rise_Pattern.put_point(0.0, 0.0, 0.0, 0.0);
            Start_Rise_Pattern.put_point(0.1, 0.0, 0.0, 0.0);
            Start_Rise_Pattern.put_point(0.2, 0.7, 0.0, 0.0);
            Start_Rise_Pattern.put_point(0.3, 1.0, 0.0, 0.0);
            Start_Rise_Pattern.put_point(0.5, 0.0, 0.0, 0.0);
            Start_Rise_Pattern.put_point(1.0, 0.0, 0.0, 0.0);

            ///////////////////////////Normal_Pattern/////////////////////////////
            Side_Pattern.put_point(0.0, 0.0, 0.0,0.0);
            Side_Pattern.put_point(0.1, 0.0, 0.0, 0.0);
            Side_Pattern.put_point(0.2, 1.0, 0.0, 0.0);
            Side_Pattern.put_point(0.3, 1.0, 0.0,0.0);
            Side_Pattern.put_point(0.4, 1.0, 0.0,0.0);
            Side_Pattern.put_point(0.5, 0.0, 0.0,0.0);
            Side_Pattern.put_point(0.7, 0.0, 0.0, 0.0);
            Side_Pattern.put_point(1.0, 0.0, 0.0, 0.0);

            Step_Pattern.put_point(0.0,-0.5, 0.0,0.0);
//            Step_Pattern.put_point(0.1,-0.5, 0.0,0.0);
//            Step_Pattern.put_point(0.4, 0.5, 0.0,0.0);
            Step_Pattern.put_point(0.5, 0.5, 0.0,0.0);
//            Step_Pattern.put_point(0.6, 0.5, 0.0,0.0);
//            Step_Pattern.put_point(0.9,-0.5, 0.0,0.0);
            Step_Pattern.put_point(1.0,-0.5, 0.0,0.0);

//            Step_Pattern.put_point(0.0,-0.5, 0.0,0.0);
//            Step_Pattern.put_point(0.375, 0.5, 0.0,0.0);
//            Step_Pattern.put_point(1.0,-0.5, 0.0,0.0);


            COM_Pattern.put_point(0.0,  -0.5, 0.0,  0.0);
            COM_Pattern.put_point(0.2,  0.5,  0.0,  0.0);
            COM_Pattern.put_point(0.5,  0.5,  0.0,  0.0);
            COM_Pattern.put_point(0.7,  -0.5, 0.0,  0.0);
            COM_Pattern.put_point(1.0,  -0.5, 0.0,  0.0);

            Rise_Pattern.put_point(0.0, 0.0, 0.0, 0.0);
            Rise_Pattern.put_point(0.1, 0.0, 0.0, 0.0);
            Rise_Pattern.put_point(0.2, 0.7, 0.0, 0.0);
            Rise_Pattern.put_point(0.3, 1.0, 0.0, 0.0);
            Rise_Pattern.put_point(0.5, 0.0, 0.0, 0.0);
            Rise_Pattern.put_point(0.6, 0.0, 0.0, 0.0);
            Rise_Pattern.put_point(1.0, 0.0, 0.0, 0.0);

            Turn_Pattern.put_point(0.0,  0.0,  0.0,  0.0);
            Turn_Pattern.put_point(0.1,  0.0,  0.0,  0.0);
            Turn_Pattern.put_point(0.3,  1.0,  0.0,  0.0);
            Turn_Pattern.put_point(0.6,  1.0,  0.0,  0.0);
            Turn_Pattern.put_point(0.7,  0.4,  0.0,  0.0);
            Turn_Pattern.put_point(0.9,  0.0,  0.0,  0.0);
            Turn_Pattern.put_point(1.0,  0.0,  0.0,  0.0);

        }
        else if(Balancing_Param.Balance.Ratio_Check_Flag ==0)
        {
            //if you need more pattern, add pattern.
        }
}



void Robit_Humanoid_Walk::Result_Pattern(Walk_Parameters &Now_Param)
{
    Time_Right_Leg_Start = Timer_Time_Start/Now_Param.Sink_Entire_Time+0.5;

    Time_Left_Leg_Start = Timer_Time_Start/Now_Param.Sink_Entire_Time;

    Now_Param.Entire_Time = Past_Param.Entire_Time;

    Time_Right_Leg = Timer_Time/Now_Param.Entire_Time + 0.5;
    Time_Left_Leg  = Timer_Time/Now_Param.Entire_Time;

    Time_Right_Leg_End = Timer_Time_End/Now_Param.End_Entire_Time+0.5;
    Time_Left_Leg_End = Timer_Time_End/Now_Param.End_Entire_Time;
    if(Time_Right_Leg_Start >= 1.0)  Time_Right_Leg_Start -= 1.0;
    if(Time_Right_Leg >= 1.0)        Time_Right_Leg -= 1.0;
    if(Time_Right_Leg_End >= 1.0)    Time_Right_Leg_End -= 1.0;

    if(Balancing_Param.Balance.Ratio_Check_Flag == 1) Past_Param.Check_ratio.Ratio_Flag = 1;
    else if(Balancing_Param.Balance.Ratio_Check_Flag == 0) Past_Param.Check_ratio.Ratio_Flag = 0;

    if(Now_Param.X.X >= 1) Run_Flag = false; //Run_flag 기준 설정(Run 상태에 진입시 기구식 조건 일부 해제)
    else Run_Flag = false;

    if((Now_Param.X.X <= 0) || (Now_Param.Y.Side != 0)) Ankle_Flag = false; //Ankle_Flag 설정(뒤로 가거나 Side시 발목을 사용하여 걷지 않도록)
    else Ankle_Flag = true;

    if(Time_Right_Leg >= 0 && Time_Right_Leg <= 0.02)
    {
        Now_Param.Check_ratio = Past_Param.Check_ratio;
        Now_Param.Y.Default_Y_Right = Past_Param.Y.Default_Y_Right;
        Now_Param.Y.Default_Y_Left = Past_Param.Y.Default_Y_Left;
        Now_Param.Z.Default_Z_Right = Past_Param.Z.Default_Z_Right;
        Now_Param.Z.Default_Z_Left= Past_Param.Z.Default_Z_Left;
        Now_Param.Shoulder.Swing_Right_Shoulder = Past_Param.Shoulder.Swing_Right_Shoulder;
        Now_Param.Shoulder.Swing_Left_Shoulder = Past_Param.Shoulder.Swing_Left_Shoulder;
        Now_Param.Frequency = Past_Param.Frequency;
        Now_Param.Y.Swing_Right_Leg = Past_Param.Y.Swing_Right_Leg;
        Now_Param.Y.Swing_Left_Leg = Past_Param.Y.Swing_Left_Leg;
        Now_Param.Z.Rise_Right_Leg= Past_Param.Z.Rise_Right_Leg;
        Now_Param.Z.Rise_Left_Leg = Past_Param.Z.Rise_Left_Leg;
        Now_Param.X = Past_Param.X;
        Now_Param.Yaw_R = Past_Param.Yaw_R;
        Now_Param.Yaw_L = Past_Param.Yaw_L;
        Now_Param.Yaw_R.Tuning_Yaw = Past_Param.Yaw_R.Tuning_Yaw;
        Now_Param.Yaw_L.Tuning_Yaw = Past_Param.Yaw_L.Tuning_Yaw;

        if(accel_pos_x_cnt >= 0 && accel_pos_x_cnt <= accel_pos_x_num)  accel_pos_x_cnt++;
        if(accel_neg_x_cnt >= 0 && accel_neg_x_cnt <= accel_neg_x_num)  accel_neg_x_cnt++;
        if(accel_pos_y_cnt >= 0 && accel_pos_y_cnt <= accel_pos_y_num)  accel_pos_y_cnt++;
        if(accel_neg_y_cnt >= 0 && accel_neg_y_cnt <= accel_neg_y_num)  accel_neg_y_cnt++;
        if(accel_pos_z_cnt >= 0 && accel_pos_z_cnt <= accel_pos_z_num)  accel_pos_z_cnt++;
        if(accel_neg_z_cnt >= 0 && accel_neg_z_cnt <= accel_neg_z_num)  accel_neg_z_cnt++;

        Compansate_Flag_L = false;
        Compansate_Flag_R = false;
        Compansate_Flag_2 = false;
    }

    else if(fabs(Time_Right_Leg - 0.5) <= 0.02 || fabs(Time_Right_Leg - 0.25) <= 0.02 || fabs(Time_Right_Leg - 0.75) <= 0.02)
    {
        Now_Param.X = Past_Param.X;
        Now_Param.Y = Past_Param.Y;
        Now_Param.Yaw_R = Past_Param.Yaw_R;
        Now_Param.Yaw_L = Past_Param.Yaw_L;

        if(Now_Param.X.X != Past_Param.X.X)
        {
            Temp_Param_X = Now_Param.X.X;
            X_Change = true;
        }
        else
        {
            X_Change = false;
            Time_X = 0.0;
        }

        if(Now_Param.Y.Side != Past_Param.Y.Side)
        {
            Temp_Param_Side = Now_Param.Y.Side;
            Side_Change = true;
        }
        else
        {
            Side_Change = false;
            Time_Side = 0.0;
        }

        if(Now_Param.Yaw_L.Yaw != Past_Param.Yaw_L.Yaw)
        {
            Temp_Param_Yaw_L = Now_Param.Yaw_L.Yaw;
            Yaw_L_Change = true;
        }
        else
        {
            Yaw_L_Change = false;
            Time_Yaw_L = 0.0;
        }

        if(Now_Param.Yaw_R.Yaw != Past_Param.Yaw_R.Yaw)
        {
            Temp_Param_Yaw_R = Now_Param.Yaw_R.Yaw;
            Yaw_R_Change = true;
        }
        else
        {
            Yaw_R_Change = false;
            Time_Yaw_R=0.0;
        }

    }

    else if((Time_Right_Leg - 1) <= 0 && (Time_Right_Leg - 1) >= -0.02)
    {
        if(End_Cnt > 1 && End_Flag)
        {
            Now_Param.Y.Side=0.0;
            Now_Param.X.X = 0.0;
            Now_Param.Yaw_R.Yaw = 0.0;
            Now_Param.Yaw_L.Yaw = 0.0;
            Side_Change = false;
            X_Change = false;
            Yaw_L_Change = false;
            Yaw_R_Change = false;
        }
    }

    if(Side_Change)
    {
        Time_Side++;

        foot_trajectory Param_Pattern;
        Param_Pattern.put_point(0.0, Temp_Param_Side, 0.0, 0.0);
        Param_Pattern.put_point(Now_Param.Entire_Time, Past_Param.Y.Side, 0.0, 0.0);

        Now_Param.Y.Side = Param_Pattern.result(Time_Side);
        if(Now_Param.Y.Side < 0.1 && Now_Param.Y.Side > -0.1) Now_Param.Y.Side = 0;

        if(Time_Side >= Now_Param.Entire_Time) Time_Side = 0.0;
    }
    if(X_Change)
    {
        Time_X++;

        foot_trajectory Param_Pattern;
        Param_Pattern.put_point(0.0, Temp_Param_X, 0.0, 0.0);
        Param_Pattern.put_point(Now_Param.Entire_Time, Past_Param.X.X, 0.0, 0.0);

        Now_Param.X.X = Param_Pattern.result(Time_X);
        if(Now_Param.X.X < 0.1 && Now_Param.X.X > -0.1) Now_Param.X.X = 0;

        if(Time_X >= Now_Param.Entire_Time) Time_X = 0.0;
    }
    if(Yaw_L_Change)
    {
        Time_Yaw_L++;
        foot_trajectory Param_Pattern;
        Param_Pattern.put_point(0.0, Temp_Param_Yaw_L, 0.0, 0.0);
        Param_Pattern.put_point(Now_Param.Entire_Time, Past_Param.Yaw_L.Yaw, 0.0, 0.0);

        Now_Param.Yaw_L.Yaw = Param_Pattern.result(Time_Yaw_L);
        if(Now_Param.Yaw_L.Yaw < 0.1 && Now_Param.Yaw_L.Yaw > -0.1) Now_Param.Yaw_L.Yaw = 0;

        if(Time_Yaw_L >= Now_Param.Entire_Time) Time_Yaw_L = 0.0;
    }
    if(Yaw_R_Change)
    {
        Time_Yaw_R++;
        foot_trajectory Param_Pattern;
        Param_Pattern.put_point(0.0, Temp_Param_Yaw_R, 0.0, 0.0);
        Param_Pattern.put_point(Now_Param.Entire_Time, Past_Param.Yaw_R.Yaw, 0.0, 0.0);

        Now_Param.Yaw_R.Yaw = Param_Pattern.result(Time_Yaw_R);
        if(Now_Param.Yaw_R.Yaw < 0.1 && Now_Param.Yaw_R.Yaw > -0.1) Now_Param.Yaw_R.Yaw = 0;

        if(Time_Yaw_R >= Now_Param.Entire_Time) Time_Yaw_R = 0.0;
    }

    if(Start_Flag)
    {
        cout<<endl<<"**************Start_Walking*****************"<<endl<<endl;
        Now_Param.X.X = 0.0;
        Now_Param.Y.Side = 0.0;
        Now_Param.Yaw_R.Yaw = 0.0;
        Now_Param.Yaw_L.Yaw = 0.0;
        Accel_Rise_R = ((Now_Param.Z.Rise_Right_Leg-Now_Param.Z.Start_Rise)/Repeat_Start_Cycle)*Start_Cnt;
        Accel_Rise_L = ((Now_Param.Z.Rise_Left_Leg-Now_Param.Z.Start_Rise)/Repeat_Start_Cycle)*Start_Cnt;
        Accel_Swing_R = ((Now_Param.Y.Swing_Right_Leg-Now_Param.Y.Start_Swing)/Repeat_Start_Cycle)*Start_Cnt;
        Accel_Swing_L = ((Now_Param.Y.Swing_Left_Leg-Now_Param.Y.Start_Swing)/Repeat_Start_Cycle)*Start_Cnt;
        Accel_Entire_Time = ((Now_Param.Entire_Time-Now_Param.Start_Entire_Time)/Repeat_Start_Cycle)*Start_Cnt;

        Now_Param.Sink_Entire_Time = Now_Param.Start_Entire_Time+Accel_Entire_Time;

        if(Accel_Rise_R>fabs(Now_Param.Z.Rise_Right_Leg-Now_Param.Z.Start_Rise)) Accel_Rise_R=fabs(Now_Param.Z.Rise_Right_Leg-Now_Param.Z.Start_Rise);
        if(Accel_Rise_L>fabs(Now_Param.Z.Rise_Left_Leg-Now_Param.Z.Start_Rise))  Accel_Rise_L=fabs(Now_Param.Z.Rise_Left_Leg-Now_Param.Z.Start_Rise);
        if(Accel_Swing_R>fabs(Now_Param.Y.Swing_Right_Leg-Now_Param.Y.Start_Swing)) Accel_Swing_R=fabs(Now_Param.Y.Swing_Right_Leg-Now_Param.Y.Start_Swing);
        if(Accel_Swing_L>fabs(Now_Param.Y.Swing_Left_Leg-Now_Param.Y.Start_Swing))  Accel_Swing_L=fabs(Now_Param.Y.Swing_Left_Leg-Now_Param.Y.Start_Swing);
        if(Accel_Entire_Time>fabs(Now_Param.Entire_Time-Now_Param.Start_Entire_Time)) Accel_Entire_Time = fabs(Now_Param.Entire_Time-Now_Param.Start_Entire_Time);

        if(accel_pos_x_cnt!=-1) accel_pos_x_cnt=0;
        if(accel_neg_x_cnt!=-1) accel_neg_x_cnt=0;
        if(accel_pos_y_cnt!=-1) accel_pos_y_cnt=0;
        if(accel_pos_z_cnt!=-1) accel_pos_z_cnt=0;

        //RIGHT--------------------------------------------------------------------------------------
        Kinetic_X_R = Step_Pattern.result(Time_Right_Leg_Start)*(Now_Param.X.Tuning_X) + Now_Param.X.Default_X_Right;
        Kinetic_Y_R = -Start_COM_Pattern.result(Time_Right_Leg_Start)*(Now_Param.Y.Start_Swing+Accel_Swing_R)+Now_Param.Y.Default_Y_Right;
        Kinetic_Z_R = Start_Rise_Pattern.result(Time_Right_Leg_Start)*(Now_Param.Z.Start_Rise+Accel_Rise_R)+Now_Param.Z.Default_Z_Right;
        Kinetic_Yaw_R = Turn_Pattern.result(Time_Right_Leg_Start)*(Now_Param.Yaw_R.Tuning_Yaw);

        //LEFT--------------------------------------------------------------------------------------
        Kinetic_X_L = Step_Pattern.result(Time_Left_Leg_Start)*(Now_Param.X.Tuning_X) + Now_Param.X.Default_X_Left;
        Kinetic_Y_L = Start_COM_Pattern.result(Time_Left_Leg_Start)*(Now_Param.Y.Start_Swing+Accel_Swing_L) + Now_Param.Y.Default_Y_Left;
        Kinetic_Z_L = Start_Rise_Pattern.result(Time_Left_Leg_Start)*(Now_Param.Z.Start_Rise+Accel_Rise_L) + Now_Param.Z.Default_Z_Left;
        Kinetic_Yaw_L = Turn_Pattern.result(Time_Left_Leg_Start)*(Now_Param.Yaw_L.Tuning_Yaw);
    }

    else if(End_Flag)
    {
        cout<<endl<<"**************End_Walking*****************"<<endl<<endl;
        check_old_x=0;
        Now_Param.X.X=0;

        check_old_y=0;
        Now_Param.Y.Side=0;

        check_old_z=0;
        Now_Param.Yaw_R.Yaw = 0.0;
        Now_Param.Yaw_L.Yaw = 0.0;

        accel_pos_x_cnt = -1;
        accel_neg_x_cnt = -1;
        accel_pos_y_cnt = -1;
        accel_pos_z_cnt = -1;

        //RIGHT-------------------------------------------------------------------------------------
        Kinetic_X_R = Now_Param.X.Default_X_Right;
        Kinetic_Y_R = -COM_Pattern.result(Time_Right_Leg_End)*(Now_Param.Y.End_Swing)+Now_Param.Y.Default_Y_Right;
        Kinetic_Z_R = Rise_Pattern.result(Time_Right_Leg_End)*(Now_Param.Z.End_Rise)+Now_Param.Z.Default_Z_Right;
        Kinetic_Yaw_R = 0.0;

        //LEFT--------------------------------------------------------------------------------------
        Kinetic_X_L = Now_Param.X.Default_X_Left;
        Kinetic_Y_L = COM_Pattern.result(Time_Left_Leg_End)*(Now_Param.Y.End_Swing) + Now_Param.Y.Default_Y_Left;
        Kinetic_Z_L = Rise_Pattern.result(Time_Left_Leg_End)*(Now_Param.Z.End_Rise) + Now_Param.Z.Default_Z_Left;
        Kinetic_Yaw_L = 0.0;

        //------------------------------------------------------------------------------------------
        Amount_of_Change_X = Kinetic_X_R - Past_Kinetic_X_R;
        Past_Kinetic_X_R = Kinetic_X_R;
        Amount_of_Change_Y = Kinetic_Y_R - Past_Kinetic_Y_R;
        Past_Kinetic_Y_R = Kinetic_Y_R;

    }
    else
    {
        cout<<endl<<"**************Normal_Walking*****************"<<endl<<endl;

        if((accel_pos_x_cnt >= 0 && accel_pos_x_cnt <= accel_pos_x_num) && (accel_neg_x_cnt == -1))
        {
            Now_Param.X.X = step_acc_func(basic_x, accel_pos_x, accel_pos_x_num, accel_pos_x_cnt);
        }

        if((accel_neg_x_cnt >= 0 && accel_neg_x_cnt <= accel_neg_x_num) && (accel_pos_x_cnt == -1))
        {
            Now_Param.X.X = step_acc_func(basic_x, accel_neg_x, accel_neg_x_num, accel_neg_x_cnt);
        }

        if((accel_pos_y_cnt >=0 && accel_pos_y_cnt <= accel_pos_y_num) && (accel_neg_y_cnt == -1))
        {
            Now_Param.Y.Side = step_acc_func(basic_y, accel_pos_y, accel_pos_y_num, accel_pos_y_cnt);
        }

        if((accel_neg_y_cnt >=0 && accel_neg_y_cnt <= accel_neg_y_num) && (accel_pos_y_cnt == -1))
        {
            Now_Param.Y.Side = step_acc_func(basic_y, accel_neg_y, accel_neg_y_num, accel_neg_y_cnt);
        }

        if((accel_pos_z_cnt >= 0 && accel_pos_z_cnt <= accel_pos_z_num) && (accel_neg_z_cnt == -1))
        {
            Now_Param.Yaw_R.Yaw = step_acc_func(basic_z, accel_pos_z, accel_pos_z_num, accel_pos_z_cnt);
            Now_Param.Yaw_L.Yaw = step_acc_func(basic_z, accel_pos_z, accel_pos_z_num, accel_pos_z_cnt);
        }

        if((accel_neg_z_cnt >= 0 && accel_neg_z_cnt <= accel_neg_z_num) && (accel_pos_z_cnt == -1))
        {
            Now_Param.Yaw_R.Yaw = step_acc_func(basic_z, accel_neg_z, accel_neg_z_num, accel_neg_z_cnt);
            Now_Param.Yaw_L.Yaw = step_acc_func(basic_z, accel_neg_z, accel_neg_z_num, accel_neg_z_cnt);
        }

        if((Now_Param.Y.Side || Now_Param.Y.Tuning_Side) && Compansate_Yaw_flag == false && !Now_Param.Yaw_R.Tuning_Yaw && !Now_Param.Yaw_R.Yaw)
        {
            desire_yaw = Imu_Info.yaw;
            Compansate_Yaw_flag = true;
        }

        //외란에 대한 단계적 회복(감속구간>제어구간>회복구간)
//        if(imu_safe_cnt || (IK.Now_Balance_Theta.Theta3 != 0 || fabs(Imu_Info.pitch-(Balancing_Param.Balance.Balance_Pitch_Pos_Target_imu + Balancing_Param.Balance.Balance_Pitch_Neg_Target_imu)/2)>6))
//        {
//            imu_safe_cnt++;
//            if(imu_safe_cnt <= 150) Now_Param.X.X = Past_Param.X.X*0.9;
//                        else if(imu_safe_cnt <= 200) Now_Param.X.X = Past_Param.X.X*0.6;
//                        else if(imu_safe_cnt < 500) Now_Param.X.X = Past_Param.X.X*((0.4*(imu_safe_cnt-200))/300 + 0.6);

//            if(imu_safe_cnt == 500) imu_safe_cnt = 0;
//        }

        if(Swing_Control_add_L > 1.5) Swing_Control_add_L = 1.5;
        if(Swing_Control_add_R > 1.5) Swing_Control_add_R = 1.5;
        if(Swing_Control_add_L < -0.5) Swing_Control_add_L = -0.5;
        if(Swing_Control_add_R < -0.5) Swing_Control_add_R = -0.5;
        if(abs(Swing_Control_add_L) < 0.05) Swing_Control_add_L = 0;
        if(abs(Swing_Control_add_R) < 0.05) Swing_Control_add_R = 0;

        //adjust swing
        if(Now_Param.X.X >= K_value[3].min && Now_Param.X.X <= K_value[3].max)
        {
            //RIGHT-------------------------------------------------------------------------------------
            Kinetic_Y_R = -COM_Pattern.result(Time_Right_Leg)*Swing_Control_R*(Now_Param.Y.Swing_Right_Leg - (negative_position(Now_Param.Yaw_R.Yaw*K_value[3].Neg_YawR) - positive_position(Now_Param.Yaw_R.Yaw*K_value[3].Pos_YawR)) - (negative_position(Now_Param.X.X*K_value[3].Neg_XR) + positive_position(Now_Param.X.X*K_value[3].Pos_XR))) + Now_Param.Y.Default_Y_Right;

            if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Neg_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Neg_SideR;
            else if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Pos_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Pos_SideR;
            Kinetic_Y_R += ((Now_Param.Y.Tuning_Side+ Now_Param.Y.Side )*Side_Pattern.result(Time_Right_Leg));
            //LEFT--------------------------------------------------------------------------------------
            Kinetic_Y_L = COM_Pattern.result(Time_Left_Leg)*Swing_Control_L*(Now_Param.Y.Swing_Left_Leg -(negative_position(Now_Param.Yaw_L.Yaw*K_value[3].Neg_YawL) - positive_position(Now_Param.Yaw_L.Yaw*K_value[3].Pos_YawL)) - (negative_position(Now_Param.X.X*K_value[3].Neg_XL) + positive_position(Now_Param.X.X*K_value[3].Pos_XL))) + Now_Param.Y.Default_Y_Left;

            if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Pos_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Pos_SideL;
            else if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Neg_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[3].Neg_SideL;

            Kinetic_Y_L += ((Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*Side_Pattern.result(Time_Left_Leg) );
        }
        else if(Now_Param.X.X >= K_value[2].min && Now_Param.X.X < K_value[2].max)
        {
            //RIGHT-------------------------------------------------------------------------------------
            Kinetic_Y_R = -COM_Pattern.result(Time_Right_Leg)*Swing_Control_R*(Now_Param.Y.Swing_Right_Leg - (negative_position(Now_Param.Yaw_R.Yaw*K_value[2].Neg_YawR) - positive_position(Now_Param.Yaw_R.Yaw*K_value[2].Pos_YawR)) - (negative_position(Now_Param.X.X*K_value[2].Neg_XR) + positive_position(Now_Param.X.X*K_value[2].Pos_XR))) + Now_Param.Y.Default_Y_Right;

            if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideR;
            else if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideR;
            Kinetic_Y_R += ((Now_Param.Y.Tuning_Side+ Now_Param.Y.Side )*Side_Pattern.result(Time_Right_Leg));
            //LEFT--------------------------------------------------------------------------------------
            Kinetic_Y_L = COM_Pattern.result(Time_Left_Leg)*Swing_Control_L*(Now_Param.Y.Swing_Left_Leg -(negative_position(Now_Param.Yaw_L.Yaw*K_value[2].Neg_YawL) - positive_position(Now_Param.Yaw_L.Yaw*K_value[2].Pos_YawL)) - (negative_position(Now_Param.X.X*K_value[2].Neg_XL) + positive_position(Now_Param.X.X*K_value[2].Pos_XL))) + Now_Param.Y.Default_Y_Left;

            if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[2].Pos_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[2].Pos_SideL;
            else if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[2].Neg_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[2].Neg_SideL;

            Kinetic_Y_L += ((Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*Side_Pattern.result(Time_Left_Leg) );
        }
        else if(Now_Param.X.X >= K_value[1].min && Now_Param.X.X < K_value[1].max)
        {
            //RIGHT-------------------------------------------------------------------------------------
            Kinetic_Y_R = -COM_Pattern.result(Time_Right_Leg)*Swing_Control_R*(Now_Param.Y.Swing_Right_Leg - (negative_position(Now_Param.Yaw_R.Yaw*K_value[1].Neg_YawR) - positive_position(Now_Param.Yaw_R.Yaw*K_value[1].Pos_YawR)) - (negative_position(Now_Param.X.X*K_value[1].Neg_XR) + positive_position(Now_Param.X.X*K_value[1].Pos_XR))) + Now_Param.Y.Default_Y_Right;

            if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Neg_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Neg_SideR;
            else if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Pos_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Pos_SideR;
            Kinetic_Y_R += ((Now_Param.Y.Tuning_Side+ Now_Param.Y.Side )*Side_Pattern.result(Time_Right_Leg));
            //LEFT--------------------------------------------------------------------------------------
            Kinetic_Y_L = COM_Pattern.result(Time_Left_Leg)*Swing_Control_L*(Now_Param.Y.Swing_Left_Leg -(negative_position(Now_Param.Yaw_L.Yaw*K_value[1].Neg_YawL) - positive_position(Now_Param.Yaw_L.Yaw*K_value[1].Pos_YawL)) - (negative_position(Now_Param.X.X*K_value[1].Neg_XL) + positive_position(Now_Param.X.X*K_value[1].Pos_XL))) + Now_Param.Y.Default_Y_Left;

            if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Pos_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Pos_SideL;
            else if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Neg_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[1].Neg_SideL;

            Kinetic_Y_L += ((Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*Side_Pattern.result(Time_Left_Leg) );
        }
        else if(Now_Param.X.X >= K_value[0].min && Now_Param.X.X < K_value[0].max)
        {
            //RIGHT-------------------------------------------------------------------------------------
            Kinetic_Y_R = -COM_Pattern.result(Time_Right_Leg)*Swing_Control_R*(Now_Param.Y.Swing_Right_Leg - (negative_position(Now_Param.Yaw_R.Yaw*K_value[0].Neg_YawR) - positive_position(Now_Param.Yaw_R.Yaw*K_value[0].Pos_YawR)) - (negative_position(Now_Param.X.X*K_value[0].Neg_XR) + positive_position(Now_Param.X.X*K_value[0].Pos_XR))) + Now_Param.Y.Default_Y_Right;

            if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_R -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideR;
            else if(-COM_Pattern.result(Time_Right_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideR_SwingMinus;
            else if(-COM_Pattern.result(Time_Right_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_R += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideR;
            Kinetic_Y_R += ((Now_Param.Y.Tuning_Side+ Now_Param.Y.Side )*Side_Pattern.result(Time_Right_Leg));
            //LEFT--------------------------------------------------------------------------------------
            Kinetic_Y_L = COM_Pattern.result(Time_Left_Leg)*Swing_Control_L*(Now_Param.Y.Swing_Left_Leg -(negative_position(Now_Param.Yaw_L.Yaw*K_value[0].Neg_YawL) - positive_position(Now_Param.Yaw_L.Yaw*K_value[0].Pos_YawL)) - (negative_position(Now_Param.X.X*K_value[0].Neg_XL) + positive_position(Now_Param.X.X*K_value[0].Pos_XL))) + Now_Param.Y.Default_Y_Left;

            if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)>0) Kinetic_Y_L += (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Pos_SideL;
            else if(COM_Pattern.result(Time_Left_Leg)<=0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideL_SwingMinus;
            else if(COM_Pattern.result(Time_Left_Leg)>0 && (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)<=0) Kinetic_Y_L -= (Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*K_value[0].Neg_SideL;

            Kinetic_Y_L += ((Now_Param.Y.Tuning_Side + Now_Param.Y.Side)*Side_Pattern.result(Time_Left_Leg) );
        }

        //RIGHT-------------------------------------------------------------------------------------
        Kinetic_X_R = Step_Pattern.result(Time_Right_Leg)*(Now_Param.X.Tuning_X + Now_Param.X.X) + Now_Param.X.Default_X_Right;
        Kinetic_Z_R = Rise_Pattern.result(Time_Right_Leg)*(Now_Param.Z.Rise_Right_Leg) + Now_Param.Z.Default_Z_Right;

        //LEFT--------------------------------------------------------------------------------------
        Kinetic_X_L = Step_Pattern.result(Time_Left_Leg)*(Now_Param.X.Tuning_X + Now_Param.X.X) + Now_Param.X.Default_X_Left;
        Kinetic_Z_L = Rise_Pattern.result(Time_Left_Leg)*(Now_Param.Z.Rise_Left_Leg) + Now_Param.Z.Default_Z_Left;

        //Shoulder----------------------------------------------------------------------------------
        Kinetic_Shoulder_X_R = Step_Pattern.result(Time_Right_Leg)*(Now_Param.Shoulder.Swing_Right_Shoulder);
        Kinetic_Shoulder_X_L = Step_Pattern.result(Time_Left_Leg)*(Now_Param.Shoulder.Swing_Left_Shoulder);

        Amount_of_Change_Y = Kinetic_Y_R - Past_Kinetic_Y_R;
        Past_Kinetic_Y_R = Kinetic_Y_R;

        Amount_of_Change_X = Kinetic_X_R - Past_Kinetic_X_R;
        Past_Kinetic_X_R = Kinetic_X_R;

        //only side시에 yaw 보정 기능
        if((Now_Param.Y.Side || Now_Param.Y.Tuning_Side) && !Now_Param.Yaw_R.Tuning_Yaw && !Now_Param.Yaw_R.Yaw)
        {
            if((desire_yaw - Imu_Info.yaw) >= 2)
            {
                Compansate_Yaw = 2;
            }
            else if((desire_yaw - Imu_Info.yaw) <= -2)
            {
                Compansate_Yaw = -2;
            }
            else if((desire_yaw - Imu_Info.yaw) == 0)
            {
                Compansate_Yaw_cnt++;
            }
            else if(Compansate_Yaw_cnt>50)
            {
                Compansate_Yaw_cnt = 0;
                Compansate_Yaw = 0;
            }
        }
        else
        {
            Compansate_Yaw_flag = false;
            Compansate_Yaw = 0;
        }

        //마스터에서 공 보정시에 Side와 Yaw를 동시에 줄 때 공 주위로 돌도록(즉, Yaw가 내회전)
        if((Now_Param.Y.Side != 0 && Now_Param.Yaw_R.Yaw != 0))
        {
            if((Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw)>=0)
            {
                Kinetic_Yaw_R = +Turn_Pattern.result(Time_Right_Leg)*(Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw);
                Kinetic_Yaw_L = -Turn_Pattern.result(Time_Right_Leg)*(Now_Param.Yaw_L.Tuning_Yaw + Now_Param.Yaw_L.Yaw);
            }
            else if((Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw)<0)
            {
                Kinetic_Yaw_R = -Turn_Pattern.result(Time_Left_Leg)*(Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw);
                Kinetic_Yaw_L = +Turn_Pattern.result(Time_Left_Leg)*(Now_Param.Yaw_L.Tuning_Yaw + Now_Param.Yaw_L.Yaw);
            }
        }
        else
        {
            if((Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw)>=0)
            {
                Kinetic_Yaw_R = -Turn_Pattern.result(Time_Left_Leg)*(Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw + Compansate_Yaw);
                Kinetic_Yaw_L = +Turn_Pattern.result(Time_Left_Leg)*(Now_Param.Yaw_L.Tuning_Yaw + Now_Param.Yaw_L.Yaw + Compansate_Yaw);
            }
            else if((Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw)<0)
            {
                Kinetic_Yaw_R = +Turn_Pattern.result(Time_Right_Leg)*(Now_Param.Yaw_R.Tuning_Yaw+ Now_Param.Yaw_R.Yaw + Compansate_Yaw);
                Kinetic_Yaw_L = -Turn_Pattern.result(Time_Right_Leg)*(Now_Param.Yaw_L.Tuning_Yaw + Now_Param.Yaw_L.Yaw + Compansate_Yaw);
            }
        }

        if(Time_Right_Leg <= 0.02 )
        {
            Ikcoordinate_Info.X = (int)Now_Param.X.X;
            Ikcoordinate_Info.Y = (int)Now_Param.Y.Side;
            Ikcoordinate_Pub.publish(Ikcoordinate_Info);
        }
    }
    if(Balancing_Param.Balance.Balance_Pitch_Flag)
    {
        if(Zmp_Info.Right_Foot)
        {
            Zmp_Balance.PID_Zmp_Pitch_Balancing(Zmp_Info.Right_Y_zmp,Balancing_Param.Balance.Balance_Pitch_GP,Balancing_Param.Balance.Balance_Pitch_GI,Balancing_Param.Balance.Balance_Pitch_GD,Balancing_Param.Balance.Balance_Pitch_ELIMIT,Balancing_Param.Balance.Balance_Pitch_OLIMIT,Balancing_Param.Balance.Balance_Pitch_Neg_Target,Balancing_Param.Balance.Balance_Pitch_Pos_Target);
            Balancing_Param.Balance.Support_Con = 1;
        }
        if(Zmp_Info.Left_Foot)
        {
            Zmp_Balance.PID_Zmp_Pitch_Balancing(Zmp_Info.Left_Y_zmp,Balancing_Param.Balance.Balance_Pitch_GP,Balancing_Param.Balance.Balance_Pitch_GI,Balancing_Param.Balance.Balance_Pitch_GD,Balancing_Param.Balance.Balance_Pitch_ELIMIT,Balancing_Param.Balance.Balance_Pitch_OLIMIT,Balancing_Param.Balance.Balance_Pitch_Neg_Target,Balancing_Param.Balance.Balance_Pitch_Pos_Target);
            Balancing_Param.Balance.Support_Con = -1;
        }
        if(Zmp_Info.Both_Feet)
        {
            Zmp_Balance.PID_Zmp_Pitch_Balancing(Zmp_Info.Total_Y_zmp,Balancing_Param.Balance.Balance_Pitch_GP,Balancing_Param.Balance.Balance_Pitch_GI,Balancing_Param.Balance.Balance_Pitch_GD,Balancing_Param.Balance.Balance_Pitch_ELIMIT,Balancing_Param.Balance.Balance_Pitch_OLIMIT,Balancing_Param.Balance.Balance_Pitch_Neg_Target,Balancing_Param.Balance.Balance_Pitch_Pos_Target);
            Balancing_Param.Balance.Support_Con = 0;
        }
    }

    if(Balancing_Param.Balance.Balance_Roll_Flag)
    {
        if(Zmp_Info.Right_Foot)
        {
            Zmp_Balance.PID_Zmp_Roll_Balancing(Zmp_Info.Right_X_zmp,Balancing_Param.Balance.Balance_Roll_GP,Balancing_Param.Balance.Balance_Roll_GI,Balancing_Param.Balance.Balance_Roll_GD,Balancing_Param.Balance.Balance_Roll_ELIMIT,Balancing_Param.Balance.Balance_Roll_OLIMIT,Balancing_Param.Balance.Balance_Roll_Neg_Target,Balancing_Param.Balance.Balance_Roll_Pos_Target);

            Balancing_Param.Balance.Support_Con = 1;
        }
        else if(Zmp_Info.Left_Foot)
        {
            Zmp_Balance.PID_Zmp_Roll_Balancing(-Zmp_Info.Left_X_zmp,Balancing_Param.Balance.Balance_Roll_GP,Balancing_Param.Balance.Balance_Roll_GI,Balancing_Param.Balance.Balance_Roll_GD,Balancing_Param.Balance.Balance_Roll_ELIMIT,Balancing_Param.Balance.Balance_Roll_OLIMIT,Balancing_Param.Balance.Balance_Roll_Neg_Target,Balancing_Param.Balance.Balance_Roll_Pos_Target);

            Balancing_Param.Balance.Support_Con = -1;
        }
        else if(Zmp_Info.Both_Feet)
        {
            Zmp_Balance.PID_Zmp_Roll_Balancing(Zmp_Info.Total_X_zmp,Balancing_Param.Balance.Balance_Roll_GP,Balancing_Param.Balance.Balance_Roll_GI,Balancing_Param.Balance.Balance_Roll_GD,Balancing_Param.Balance.Balance_Roll_ELIMIT,Balancing_Param.Balance.Balance_Roll_OLIMIT,0,0);
            Balancing_Param.Balance.Support_Con = 0;
        }
    }
    if (!Balancing_Param.Balance.Balance_Angle_Pitch_Flag)
    {
        Zmp_Balance.Target_Pitch_Angle = 0;
    }
    if (!Balancing_Param.Balance.Balance_Pitch_Flag)
    {
        Zmp_Balance.Target_X = 0;
    }
    if(!Balancing_Param.Balance.Balance_Roll_Flag)
    {
        Zmp_Balance.Target_Roll_Angle = 0;
    }
    if(End_Flag)
    {
        Zmp_Balance.Target_Pitch_Angle = 0;
        Zmp_Balance.Target_X = 0;
        Zmp_Balance.Target_Roll_Angle = 0;
    }
    if((!Balancing_Param.Balance.Balance_Angle_Pitch_Flag && !Balancing_Param.Balance.Balance_Pitch_Flag && !Balancing_Param.Balance.Balance_Roll_Flag) || (!Zmp_Info.Both_Feet && !Zmp_Info.Right_Foot && !Zmp_Info.Left_Foot))
    {
        Balancing_Param.Balance.Support_Con = 99;
    }
    if(Balancing_Param.Balance.Balance_Pitch_Flag_imu){
        Imu_Balance.PD_Pitch_control(Imu_Info.pitch,Balancing_Param.Balance.Balance_Pitch_GP_imu,Balancing_Param.Balance.Balance_Pitch_GI_imu,Balancing_Param.Balance.Balance_Pitch_GD_imu,Balancing_Param.Balance.Balance_Pitch_ELIMIT_imu,Balancing_Param.Balance.Balance_Pitch_OLIMIT_imu,Balancing_Param.Balance.Balance_Pitch_Neg_Target_imu,Balancing_Param.Balance.Balance_Pitch_Pos_Target_imu);
        if(End_Flag)
        {
            Imu_Balance.Pitch_ADD_Angle=0;
            Imu_Balance.Roll_ADD_Angle=0;
        }
    }
    if(!Balancing_Param.Balance.Balance_Pitch_Flag_imu){
        Imu_Balance.Pitch_ADD_Angle=0;
    }
    if(Balancing_Param.Balance.Balance_Roll_Flag_imu){
        Imu_Balance.PD_Roll_control(Imu_Info.roll,Balancing_Param.Balance.Balance_Roll_GP_imu,Balancing_Param.Balance.Balance_Roll_GI_imu,Balancing_Param.Balance.Balance_Roll_GD_imu,Balancing_Param.Balance.Balance_Roll_ELIMIT_imu,Balancing_Param.Balance.Balance_Roll_OLIMIT_imu,Balancing_Param.Balance.Balance_Roll_Neg_Target_imu,Balancing_Param.Balance.Balance_Roll_Pos_Target_imu);
    }
    if(!Balancing_Param.Balance.Balance_Roll_Flag_imu){
        Imu_Balance.Roll_ADD_Angle=0;
    }

    if(Now_Param.IK_Flag)
    {
        Now_Param.Z.R_Rise_Condition = Rise_Pattern.result(Time_Right_Leg)*(Now_Param.Z.Rise_Right_Leg);
        Now_Param.Z.L_Rise_Condition = Rise_Pattern.result(Time_Left_Leg)*(Now_Param.Z.Rise_Left_Leg);

        IK.Balance_Control_Body_Upright(Zmp_Balance.Target_X,Now_Param.Z.Default_Z_Right,Time_Right_Leg,Now_Param.Z.R_Rise_Condition,Zmp_Balance.Target_Pitch_Angle,Balancing_Param.Balance.Balance_Value_0,Balancing_Param.Balance.Balance_Value_1,Zmp_Info.Left_Y_zmp,Zmp_Info.Right_Y_zmp,Zmp_Balance.Target_Roll_Angle,Balancing_Param.Balance.Balance_Value_2,Balancing_Param.Balance.Balance_Value_3, Model_Data.Link2Link, Zmp_Info.Left_X_zmp, Zmp_Info.Right_X_zmp, Balancing_Param.Balance.Support_Con);

        //////////Landing_Time_Control(LTC)//////////
        if(Landing_Time_Control_flag)
        {
            if(Balancing_Param.Balance.Support_Con == 1 && Landing_flag_R)
            {
                Landing_Time_R = Timer_Time;
                Landing_Error_R = (Now_Param.Entire_Time / 2) - Landing_Time_R;
                Landing_flag_R = false;
                Landing_flag_L = true;
                Swing_Moment_Gain_L = 0.0;
                Swing_Moment_Gain_R = 0.5;
            }
            else if(Balancing_Param.Balance.Support_Con == -1 && Landing_flag_L)
            {
                Landing_Time_L = Timer_Time;
                Landing_Error_L = (Now_Param.Entire_Time - 1) - Landing_Time_L;
                Landing_flag_L = false;
                Landing_flag_R = true;
                Swing_Moment_Gain_L = 0.5;
                Swing_Moment_Gain_R = 0.0;
            }
            else if(Balancing_Param.Balance.Support_Con == 0)
            {
                Swing_Control_L = Swing_Control_add_L;
                Swing_Control_R = Swing_Control_add_R;
            }
            else if(Balancing_Param.Balance.Support_Con == 99)
            {
                Swing_Control_Warning_cnt = 0;
                Swing_Control_Safe_cnt = 0;
            }

            if(Landing_Error_L >= 17 && Landing_Error_L <= (Now_Param.Entire_Time / 2))
            {
                if(Balancing_Param.Balance.Support_Con != 0) Swing_Control_Warning_cnt++;
                Landing_Info.Warning = Swing_Control_Warning_cnt;
                Swing_Control_L = Swing_Control_add_L + Swing_Moment_Gain_L;
                if(Swing_Control_Warning_cnt >= 100)
                {
                    Swing_Control_Warning_cnt = 0;
                    Swing_Control_add_L += 0.05;
                    Swing_Control_add_R += 0.05;
                }
            }
            else if(Landing_Error_R >= 17)
            {
                if(Balancing_Param.Balance.Support_Con != 0) Swing_Control_Warning_cnt++;
                Landing_Info.Warning = Swing_Control_Warning_cnt;
                Swing_Control_R = Swing_Control_add_R + Swing_Moment_Gain_R;
                if(Swing_Control_Warning_cnt >= 100)
                {
                    Swing_Control_Warning_cnt = 0;
                    Swing_Control_add_L += 0.05;
                    Swing_Control_add_R += 0.05;
                }
            }
            else if(Landing_Error_L >= (Now_Param.Entire_Time - 10))
            {
                if(Balancing_Param.Balance.Support_Con != 0) Swing_Control_Safe_cnt++;
                Landing_Info.Safe = Swing_Control_Safe_cnt;
                Swing_Control_L = Swing_Control_add_L - Swing_Moment_Gain_L;
                if(Swing_Control_Safe_cnt >= 100)
                {
                    Swing_Control_Safe_cnt = 0;
                    Swing_Control_add_L -= 0.05;
                    Swing_Control_add_R -= 0.05;
                }
            }
            else if(Landing_Error_R <= -10)
            {
                if(Balancing_Param.Balance.Support_Con != 0) Swing_Control_Safe_cnt++;
                Landing_Info.Safe = Swing_Control_Safe_cnt;
                Swing_Control_R = Swing_Control_add_R - Swing_Moment_Gain_R;
                if(Swing_Control_Safe_cnt >= 100)
                {
                    Swing_Control_Safe_cnt = 0;
                    Swing_Control_add_L -= 0.05;
                    Swing_Control_add_R -= 0.05;
                }
            }
            Landing_Info.Swing_Gain_L = Swing_Control_L;
            Landing_Info.Swing_Gain_R = Swing_Control_R;
            Landing_Info.Entire_Time = Now_Param.Entire_Time;
            Landing_Info.Landing_Time_L = Landing_Time_L;
            Landing_Info.Landing_Time_R = Landing_Time_R;
            Landing_Info.Landing_Error_L = Landing_Error_L;
            Landing_Info.Landing_Error_R = Landing_Error_R;
            Landing_Pub.publish(Landing_Info);
        }
        else
        {
            Swing_Control_L = 1.0;
            Swing_Control_R = 1.0;
            Swing_Control_add_L = 1.0;
            Swing_Control_add_R = 1.0;
            Swing_Control_Safe_cnt = 0;
            Swing_Control_Warning_cnt = 0;
            Landing_Info.Swing_Gain_L = Swing_Control_L;
            Landing_Info.Swing_Gain_R = Swing_Control_R;
            Landing_Info.Landing_Time_L = 0;
            Landing_Info.Landing_Time_R = 0;
            Landing_Info.Landing_Error_L = 0;
            Landing_Info.Landing_Error_R = 0;
            Landing_Pub.publish(Landing_Info);
        }

        walk_pattern_Info.xrpattern = Step_Pattern.result(Time_Right_Leg);
        walk_pattern_Info.yrpattern = -COM_Pattern.result(Time_Right_Leg);
        walk_pattern_Info.zrpattern = Rise_Pattern.result(Time_Right_Leg);
        walk_pattern_Info.trpattern = Turn_Pattern.result(Time_Right_Leg);

        walk_pattern_Info.xlpattern = Step_Pattern.result(Time_Left_Leg);
        walk_pattern_Info.ylpattern = -COM_Pattern.result(Time_Left_Leg);
        walk_pattern_Info.zlpattern = Rise_Pattern.result(Time_Left_Leg);
        walk_pattern_Info.tlpattern = Turn_Pattern.result(Time_Left_Leg);

        walk_pattern_Pub.publish(walk_pattern_Info);

        IK.solve(Kinetic_X_R,Kinetic_Y_R,Kinetic_Z_R,Kinetic_Yaw_R,Kinetic_X_L,Kinetic_Y_L,Kinetic_Z_L,Kinetic_Yaw_L,Leg,Kinetic_Shoulder_X_R,Kinetic_Shoulder_X_L,Kinetic_Shoulder_Y_R,Kinetic_Shoulder_Y_L,IK.Now_Balance_Theta.Theta1,IK.Now_Balance_Theta.Theta2,IK.Now_Balance_Theta.Theta3, Now_Param.Z.R_Rise_Condition, Now_Param.Z.L_Rise_Condition, Now_Param.Z.Rise_Right_Leg, Now_Param.Z.Rise_Left_Leg, Imu_Info.pitch, Balancing_Param.Balance.Balance_Pitch_Pos_Target_imu, Balancing_Param.Balance.Balance_Pitch_Neg_Target_imu, Imu_Info.roll, Now_Param.X.X);


        //        cout << "===============IKflag_true====================" << endl;
        //                cout<< "timer : "<<Time_Right_Leg<<endl;
        //                cout<<" end_timer : "<<Time_Right_Leg_End<<endl;
                        cout << "Kinetic_X_R  >> " << Kinetic_X_R  << endl;
        //                cout << "Kinetic_X_L  >> " << Kinetic_X_L  << endl;
                        cout << "Kinetic_Y_R  >> " << Kinetic_Y_R  << endl;
        //                cout << "Kinetic_Y_L  >> " << Kinetic_Y_L  << endl;
                        cout << "Kinetic_Z_R  >> " << Kinetic_Z_R  << endl;
        //                cout << "Kinetic_Z_L  >> " << Kinetic_Z_L  << endl;
                        cout << "Kinetic_Yaw_R >> "  << Kinetic_Yaw_R << endl;
        //                cout << "Kinetic_Yaw_L >> "  << Kinetic_Yaw_L << endl;

        cout<<"Now_Param.X.X >> "<<Now_Param.X.X<<endl;
        cout<<"Now_Param.Y.Side >> "<<Now_Param.Y.Side<<endl;
        cout<<"Now_Param.Z.YawR >> "<<Now_Param.Yaw_R.Yaw<<endl;
        //                cout<<"Past_Param.X.X >> "<<Past_Param.X.X<<endl;
        //                cout<<"Past_Param.Y.Side >> "<<Past_Param.Y.Side<<endl;
        //                cout<<"Past_Param.Z.YawR >> "<<Past_Param.Yaw_R.Yaw<<endl;
        //                cout<<"imu_safe_cnt >> "<<imu_safe_cnt<<endl;
        //                cout<<"desire_yaw >> "<<desire_yaw <<endl;
        //                cout<<"Now_Param.Y.Swing_Right_Leg  "<<Now_Param.Y.Swing_Right_Leg<<endl;
        //                cout<<"Now_Param.Y.Swing_Left_Leg  "<<Now_Param.Y.Swing_Left_Leg<<endl<<endl;
        //                cout<<"Now_Param.Z.Rise_Right_Leg  "<<Now_Param.Z.Rise_Right_Leg<<endl;
        //                cout<<"Now_Param.Z.Rise_Left_Leg  "<<Now_Param.Z.Rise_Left_Leg<<endl;
        //                cout<<"Now_Param.Start_Entire_Time  "<<Now_Param.Start_Entire_Time<<endl;
        //                cout<<"Now_Param.Y.Start_Swing  "<<Now_Param.Y.Start_Swing<<endl;
        //                cout<<"Now_Param.Z.Start_Rise  "<<Now_Param.Z.Start_Rise<<endl;
        //                cout<<"Now_Param.End_Entire_Time  "<<Now_Param.End_Entire_Time<<endl;
        //                cout<<"Now_Param.Y.End_Swing  "<<Now_Param.Y.End_Swing<<endl;
        //                cout<<"Now_Param.Z.End_Rise  "<<Now_Param.Z.End_Rise<<endl;
        //                cout<<"Now_Param.X.Tuning_X  "<<Now_Param.X.Tuning_X<<endl;
        //                cout<<"Now_Param.Y.Tuning_Side  "<<Now_Param.Y.Tuning_Side<<endl;
        //                cout<<"Now_Param.Yaw_R.Yaw  "<<Now_Param.Yaw_R.Yaw<<endl;

        //                cout << "Support_Con" << Balancing_Param.Balance.Support_Con <<endl;
        //                cout << "Landing_Time_R >> " << Landing_Time_R << endl;
        //                cout << "Landing_Time_L >> " << Landing_Time_L << endl;
        //                cout << "Landing_Error_R >> " << Landing_Error_R << endl;
        //                cout << "Landing_Error_L >> " << Landing_Error_L << endl;
        cout << "Swing_Control_L >> " << Swing_Control_L << endl;
        cout << "Swing_Control_R >> " << Swing_Control_R << endl;
        //                cout << "Swing_Control_Warning_cnt >> " << Swing_Control_Warning_cnt << endl;
        //                cout << "Swing_Control_Safe_cnt >> " << Swing_Control_Safe_cnt << endl;
        //                cout << "Landing_Time_Control_flag >> " << Landing_Time_Control_flag << endl;
    }
    Ik_Flag_Past = Now_Param.IK_Flag;
}



void timer_callback(const ros::TimerEvent&)
{
    static int Milli_Second = 0;
    Milli_Second++;

    if(Milli_Second >= Now_Param.Frequency)
    {
        Milli_Second=0;

        Timer_Time +=Now_Param.Frequency;
        Timer_Time_Start +=Now_Param.Frequency;

        if(End_Flag)Timer_Time_End +=Now_Param.Frequency;

        if(Timer_Time >=Now_Param.Entire_Time)
        {
            Timer_Time = 0;
        }
        if(Timer_Time_Start >=Now_Param.Sink_Entire_Time)
        {
            Timer_Time_Start = 0;
        }
        if(Timer_Time_End >=Now_Param.End_Entire_Time)
        {
            Timer_Time_End = 0;
        }
        Walk.Walk_Start_End(Now_Param);

        if(Now_Param.Check_ratio.Ratio_Flag != Past_Param.Check_ratio.Ratio_Flag)
        {
            Now_Param.Check_ratio.Ratio_Flag = Past_Param.Check_ratio.Ratio_Flag;
            Walk.Generate_Pattern(Now_Param);
        }

        Now_Param.Z.Z_com = 325.0 - Model_Data.Init_Z_Up;// Straight_Robot's Z_com - Model_Data.Init_Z_Up
        COM_Info.X_com = (Now_Param.Z.Z_com/9.81)*((Walk.Amount_of_Change_X)/(Now_Param.Entire_Time*0.01)) + Zmp_Info.Total_Y_zmp;
        COM_Info.Y_com = (Now_Param.Z.Z_com/9.81)*((Walk.Amount_of_Change_Y)/(Now_Param.Entire_Time*0.01)) + Zmp_Info.Total_X_zmp;

        Com_Pub.publish(COM_Info);
    }
}

void get_parameters()
{
    std::string addr;
    addr = "/home/robit/catkin_ws/src/tune_walk/work/cup_C_0513";

    std::ifstream is(addr.c_str());

    if(!(is.is_open())){
        cout<<"---------------Warning-----------"<<endl;
        cout<<"-------Not Defined TUNE_WALK File-----"<<endl;
        cout<<"---------------------------------"<<endl;
        std::exit(0);
    }

    is >> Past_Param.Entire_Time;
    is >> Past_Param.Frequency;
    is >> Balancing_Param.Balance.Ratio_Check_Flag;

    is >> Past_Param.X.Default_X_Right;
    is >> Past_Param.X.Default_X_Left;
    is >> Past_Param.Y.Default_Y_Right;
    is >> Past_Param.Y.Default_Y_Left;
    is >> Past_Param.Z.Default_Z_Right;
    is >> Past_Param.Z.Default_Z_Left;
    is >> IK.Past_Motor_Angle.Motor_Angle_10;
    is >> IK.Past_Motor_Angle.Motor_Angle_11;
    is >> IK.Past_Motor_Angle.Motor_Angle_12;
    is >> IK.Past_Motor_Angle.Motor_Angle_13;
    is >> IK.Past_Motor_Angle.Motor_Angle_14;
    is >> IK.Past_Motor_Angle.Motor_Angle_15;
    is >> IK.Past_Motor_Angle.Motor_Angle_16;
    is >> IK.Past_Motor_Angle.Motor_Angle_17;
    is >> IK.Past_Motor_Angle.Motor_Angle_18;
    is >> IK.Past_Motor_Angle.Motor_Angle_19;
    is >> IK.Past_Motor_Angle.Motor_Angle_20;
    is >> IK.Past_Motor_Angle.Motor_Angle_21;
    is >> Past_Param.Y.Swing_Right_Leg;
    is >> Past_Param.Y.Swing_Left_Leg;
    is >> Past_Param.Shoulder.Swing_Right_Shoulder;
    is >> Past_Param.Shoulder.Swing_Left_Shoulder;
    is >> Past_Param.Z.Rise_Right_Leg;
    is >> Past_Param.Z.Rise_Left_Leg;
    is >> Past_Param.Start_Entire_Time;
    is >> Past_Param.Y.Start_Swing;
    is >> Past_Param.Z.Start_Rise;
    is >> Now_Param.End_Entire_Time;
    is >> Now_Param.Y.End_Swing;
    is >> Now_Param.Z.End_Rise;
    is >> Past_Param.X.Tuning_X;
    is >> Past_Param.Y.Tuning_Side;
    is >> Past_Param.Yaw_R.Tuning_Yaw;

    is >> Balancing_Param.Balance.Balance_Value_0;
    is >> Balancing_Param.Balance.Balance_Pitch_GP;
    is >> Balancing_Param.Balance.Balance_Pitch_GI;
    is >> Balancing_Param.Balance.Balance_Pitch_GD;
    is >> Balancing_Param.Balance.Balance_Pitch_ELIMIT;
    is >> Balancing_Param.Balance.Balance_Pitch_OLIMIT;
    is >> Balancing_Param.Balance.Balance_Pitch_Neg_Target;
    is >> Balancing_Param.Balance.Balance_Pitch_Pos_Target;

    is >> Balancing_Param.Balance.Balance_Value_1;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_GP;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_GI;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_GD;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_ELIMIT;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_OLIMIT;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_Neg_Target;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_Pos_Target;

    is >> Balancing_Param.Balance.Balance_Value_2;
    is >> Balancing_Param.Balance.Balance_Roll_GP;
    is >> Balancing_Param.Balance.Balance_Roll_GI;
    is >> Balancing_Param.Balance.Balance_Roll_GD;
    is >> Balancing_Param.Balance.Balance_Roll_ELIMIT;
    is >> Balancing_Param.Balance.Balance_Roll_OLIMIT;
    is >> Balancing_Param.Balance.Balance_Roll_Neg_Target;
    is >> Balancing_Param.Balance.Balance_Roll_Pos_Target;

    is >> Balancing_Param.Balance.Balance_Value_3;

    is >> Balancing_Param.Balance.Balance_Value_4;
    is >> Balancing_Param.Balance.Balance_Value_5;
    is >> Balancing_Param.Balance.Balance_Pitch_GP_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_GI_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_GD_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_ELIMIT_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_OLIMIT_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_Neg_Target_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_Pos_Target_imu;

    is >> Balancing_Param.Balance.Balance_Roll_GP_imu;
    is >> Balancing_Param.Balance.Balance_Roll_GI_imu;
    is >> Balancing_Param.Balance.Balance_Roll_GD_imu;
    is >> Balancing_Param.Balance.Balance_Roll_ELIMIT_imu;
    is >> Balancing_Param.Balance.Balance_Roll_OLIMIT_imu;
    is >> Balancing_Param.Balance.Balance_Roll_Neg_Target_imu;
    is >> Balancing_Param.Balance.Balance_Roll_Pos_Target_imu;
    is >> Model_Data.Center2Leg;
    is >> Model_Data.Link2Link;
    is >> Model_Data.Init_Z_Up;

    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_10;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_11;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_12;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_13;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_14;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_15;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_16;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_17;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_18;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_19;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_20;
    is >> IK.Past_Percentage_of_IK_Motor.Motor_Multiple_21;

    //K_value//
    is >> K_value[0].Pos_XR;
    is >> K_value[0].Neg_XR;
    is >> K_value[0].Pos_SideR;
    is >> K_value[0].Neg_SideR;
    is >> K_value[0].Pos_YawR;
    is >> K_value[0].Neg_YawR;
    is >> K_value[0].Pos_XL;
    is >> K_value[0].Neg_XL;
    is >> K_value[0].Pos_SideL;
    is >> K_value[0].Neg_SideL;
    is >> K_value[0].Pos_YawL;
    is >> K_value[0].Neg_YawL;
    is >> K_value[0].Pos_SideR_SwingMinus;
    is >> K_value[0].Neg_SideR_SwingMinus;
    is >> K_value[0].Pos_SideL_SwingMinus;
    is >> K_value[0].Neg_SideL_SwingMinus;
    is >> K_value[0].min;
    is >> K_value[0].max;

    is >> K_value[1].Pos_XR;
    is >> K_value[1].Neg_XR;
    is >> K_value[1].Pos_SideR;
    is >> K_value[1].Neg_SideR;
    is >> K_value[1].Pos_YawR;
    is >> K_value[1].Neg_YawR;
    is >> K_value[1].Pos_XL;
    is >> K_value[1].Neg_XL;
    is >> K_value[1].Pos_SideL;
    is >> K_value[1].Neg_SideL;
    is >> K_value[1].Pos_YawL;
    is >> K_value[1].Neg_YawL;
    is >> K_value[1].Pos_SideR_SwingMinus;
    is >> K_value[1].Neg_SideR_SwingMinus;
    is >> K_value[1].Pos_SideL_SwingMinus;
    is >> K_value[1].Neg_SideL_SwingMinus;
    is >> K_value[1].min;
    is >> K_value[1].max;

    is >> K_value[2].Pos_XR;
    is >> K_value[2].Neg_XR;
    is >> K_value[2].Pos_SideR;
    is >> K_value[2].Neg_SideR;
    is >> K_value[2].Pos_YawR;
    is >> K_value[2].Neg_YawR;
    is >> K_value[2].Pos_XL;
    is >> K_value[2].Neg_XL;
    is >> K_value[2].Pos_SideL;
    is >> K_value[2].Neg_SideL;
    is >> K_value[2].Pos_YawL;
    is >> K_value[2].Neg_YawL;
    is >> K_value[2].Pos_SideR_SwingMinus;
    is >> K_value[2].Neg_SideR_SwingMinus;
    is >> K_value[2].Pos_SideL_SwingMinus;
    is >> K_value[2].Neg_SideL_SwingMinus;
    is >> K_value[2].min;
    is >> K_value[2].max;

    is >> K_value[3].Pos_XR;
    is >> K_value[3].Neg_XR;
    is >> K_value[3].Pos_SideR;
    is >> K_value[3].Neg_SideR;
    is >> K_value[3].Pos_YawR;
    is >> K_value[3].Neg_YawR;
    is >> K_value[3].Pos_XL;
    is >> K_value[3].Neg_XL;
    is >> K_value[3].Pos_SideL;
    is >> K_value[3].Neg_SideL;
    is >> K_value[3].Pos_YawL;
    is >> K_value[3].Neg_YawL;
    is >> K_value[3].Pos_SideR_SwingMinus;
    is >> K_value[3].Neg_SideR_SwingMinus;
    is >> K_value[3].Pos_SideL_SwingMinus;
    is >> K_value[3].Neg_SideL_SwingMinus;
    is >> K_value[3].min;
    is >> K_value[3].max;

    is >> Landing_Time_Control_flag;

    is >> Balancing_Param.Balance.Balance_Pitch_Flag_imu;
    is >> Balancing_Param.Balance.Balance_Roll_Flag_imu;
    is >> Balancing_Param.Balance.Balance_Pitch_Flag;
    is >> Balancing_Param.Balance.Balance_Angle_Pitch_Flag;
    is >> Balancing_Param.Balance.Balance_Roll_Flag;

//    //Balance flag on/off
//    Balancing_Param.Balance.Balance_Angle_Pitch_Flag = false;
//    Balancing_Param.Balance.Balance_Pitch_Flag = true;
//    Balancing_Param.Balance.Balance_Roll_Flag = true;
//    Balancing_Param.Balance.Balance_Pitch_Flag_imu = true;
//    Balancing_Param.Balance.Balance_Roll_Flag_imu = false;

    //Default//
    Now_Param.Y.Default_Y_Right = -(Model_Data.Center2Leg);
    Now_Param.Y.Default_Y_Left = Model_Data.Center2Leg;
    Now_Param.Z.Default_Z_Right = -(2*Model_Data.Link2Link - Model_Data.Init_Z_Up);
    Now_Param.Z.Default_Z_Left = -(2*Model_Data.Link2Link - Model_Data.Init_Z_Up);

    //Offset & % of IK init//
    IK.Now_Motor_Angle = IK.Past_Motor_Angle;
    IK.Now_Percentage_of_IK_Motor = IK.Past_Percentage_of_IK_Motor;
}


void master2ik_callback(const msg_generate::ik_msg::ConstPtr& msg)
{
    Past_Param.IK_Flag = msg->flag;
    /////////////X_Accel/////////////
    if(fabs(msg->X_length-check_old_x)>=10)
    {
        check_old_x=msg->X_length;
        basic_x = Now_Param.X.X;
        if(msg->X_length-Now_Param.X.X >= 0)
        {
            accel_pos_x = msg->X_length - Now_Param.X.X;
            accel_pos_x_cnt = 0;
            accel_neg_x_cnt = -1;
        }
        else
        {
            accel_neg_x = msg->X_length - Now_Param.X.X;
            accel_pos_x_cnt = -1;
            accel_neg_x_cnt = 0;
        }
        Past_Param.X.X = msg->X_length;

    }
    else
    {
        check_old_x=msg->X_length;
        Past_Param.X.X=msg->X_length;
    }
    /////////////Y_Accel/////////////
    if(fabs(msg->Y_length-check_old_y)>=5)
    {
        check_old_y=-msg->Y_length;
        basic_y = Now_Param.Y.Side;

        accel_pos_y = msg->Y_length - Now_Param.Y.Side;

        if(msg->Y_length-Now_Param.Y.Side >= 0)
        {
            accel_pos_y = msg->Y_length - Now_Param.Y.Side;
            accel_pos_y_cnt = 0;
            accel_neg_y_cnt = -1;
        }
        else
        {
            accel_neg_y = msg->Y_length - Now_Param.Y.Side;
            accel_pos_y_cnt = -1;
            accel_neg_y_cnt = 0;
        }
        Past_Param.Y.Side = msg->Y_length;

    }
    else
    {
        check_old_y=msg->Y_length;
        Past_Param.Y.Side=msg->Y_length;
    }
    /////////////Z(Yaw)_Accel/////////////
    if(fabs(msg->Yaw-check_old_z)>=3)
    {
        check_old_z=msg->Yaw;
        basic_z = Now_Param.Yaw_R.Yaw;
        accel_pos_z = msg->Yaw - Now_Param.Yaw_R.Yaw;

        if(msg->Yaw-Now_Param.Yaw_R.Yaw >= 0)
        {
            accel_pos_z = msg->Yaw - Now_Param.Yaw_R.Yaw;
            accel_pos_z_cnt = 0;
            accel_neg_z_cnt = -1;
        }
        else
        {
            accel_neg_z = msg->Yaw - Now_Param.Yaw_R.Yaw;
            accel_pos_z_cnt = -1;
            accel_neg_z_cnt = 0;
        }
        Past_Param.Yaw_R.Yaw = msg->Yaw;

        if(msg->Yaw-Now_Param.Yaw_L.Yaw >= 0)
        {
            accel_pos_z = msg->Yaw - Now_Param.Yaw_L.Yaw;
            accel_pos_z_cnt = 0;
            accel_neg_z_cnt = -1;
        }
        else
        {
            accel_neg_z = msg->Yaw - Now_Param.Yaw_L.Yaw;
            accel_pos_z_cnt = -1;
            accel_neg_z_cnt = 0;
        }
        Past_Param.Yaw_L.Yaw = msg->Yaw;

    }
    else
    {
        check_old_z=msg->Yaw;
        Past_Param.Yaw_R.Yaw=msg->Yaw;
        Past_Param.Yaw_L.Yaw=msg->Yaw;
    }

    if(Past_Param.X.X >= X_LIMIT)    Past_Param.X.X = X_LIMIT;
    else if(Past_Param.X.X <= -X_LIMIT)  Past_Param.X.X = -X_LIMIT;

    if(Past_Param.Y.Side >= Y_LIMIT) Past_Param.Y.Side = Y_LIMIT;
    else if(Past_Param.Y.Side <= -Y_LIMIT) Past_Param.Y.Side = -Y_LIMIT;

    if(Past_Param.Yaw_R.Yaw >= YAW_LIMIT)   Past_Param.Yaw_R.Yaw = YAW_LIMIT;
    else if(Past_Param.Yaw_R.Yaw <= -YAW_LIMIT)   Past_Param.Yaw_R.Yaw = -YAW_LIMIT;

    if(Past_Param.Yaw_L.Yaw >= YAW_LIMIT)   Past_Param.Yaw_L.Yaw = YAW_LIMIT;
    else if(Past_Param.Yaw_L.Yaw <= -YAW_LIMIT)   Past_Param.Yaw_L.Yaw = -YAW_LIMIT;
}



double avg (double x)
{
    unsigned char i;
    double sum = 0, average;
    for (i = 0; i < FILTERDATA - 1; i++) data[i] = data[i+1];
    data[FILTERDATA - 1] = x;
    for (i = 0; i < 10; i++) sum += data[i];
    average = sum / FILTERDATA;
    //     sort(data,data+FILTERDATA);//
    return /*data[4];*/ average;
}

void imu_callback(const msg_generate::imu_msg::ConstPtr &msg)
{
    //    Imu_Info.pitch     = msg->pitch;
    Imu_Info.pitch = avg(msg->pitch);
    Imu_Info.roll      = msg->roll;
    Imu_Info.yaw       = msg->yaw;
    Imu_Info.roll_acc  = msg->roll_acc;
    Imu_Info.pitch_acc = msg->pitch_acc;
    Imu_Info.yaw_acc   = msg->yaw_acc;
}


void tune2walk_callback(const msg_generate::tune2walk::ConstPtr& msg)
{
    Past_Param.IK_Flag = msg ->IK_Flag;
    Past_Param.Entire_Time = msg ->Entire_Time;
    Past_Param.Frequency = msg->Frequency;
    Balancing_Param.Balance.Ratio_Check_Flag = msg -> Ratio_Check_Flag;

    /////////////X_Accel/////////////
    if(fabs(msg->Test_X-check_old_x)>=10)
    {
        check_old_x=msg->Test_X;
        basic_x = Now_Param.X.X;
        if(msg->Test_X-Now_Param.X.X >= 0)
        {
            accel_pos_x = msg->Test_X - Now_Param.X.X;
            accel_pos_x_cnt = 0;
            accel_neg_x_cnt = -1;
        }
        else
        {
            accel_neg_x = msg->Test_X - Now_Param.X.X;
            accel_pos_x_cnt = -1;
            accel_neg_x_cnt = 0;
        }
        Past_Param.X.X = msg->Test_X;

    }
    else
    {
        check_old_x=msg->Test_X;
        Past_Param.X.X=msg->Test_X;
    }
    /////////////Y_Accel/////////////
    if(fabs(msg->Test_Side-check_old_y)>=5)
    {
        check_old_y=msg->Test_Side;
        basic_y = Now_Param.Y.Side;
        if(msg->Test_Side-Now_Param.Y.Side >= 0)
        {
            accel_pos_y = msg->Test_Side - Now_Param.Y.Side;
            accel_pos_y_cnt = 0;
            accel_neg_y_cnt = -1;
        }
        else
        {
            accel_neg_y = msg->Test_Side - Now_Param.Y.Side;
            accel_pos_y_cnt = -1;
            accel_neg_y_cnt = 0;
        }
        Past_Param.Y.Side = msg->Test_Side;

    }
    else
    {
        check_old_y=msg->Test_Side;
        Past_Param.Y.Side=msg->Test_Side;
    }
    /////////////Z(Yaw)_Accel/////////////
    if(fabs(msg->Test_Yaw-check_old_z)>=3)
    {
        check_old_z=msg->Test_Yaw;
        basic_z = Now_Param.Yaw_R.Yaw;
        if(msg->Test_Yaw-Now_Param.Yaw_R.Yaw >= 0)
        {
            accel_pos_z = msg->Test_Yaw - Now_Param.Yaw_R.Yaw;
            accel_pos_z_cnt = 0;
            accel_neg_z_cnt = -1;
        }
        else
        {
            accel_neg_z = msg->Test_Yaw - Now_Param.Yaw_R.Yaw;
            accel_pos_z_cnt = -1;
            accel_neg_z_cnt = 0;
        }
        Past_Param.Yaw_R.Yaw = msg->Test_Yaw;

        if(msg->Test_Yaw-Now_Param.Yaw_L.Yaw >= 0)
        {
            accel_pos_z = msg->Test_Yaw - Now_Param.Yaw_L.Yaw;
            accel_pos_z_cnt = 0;
            accel_neg_z_cnt = -1;
        }
        else
        {
            accel_neg_z = msg->Test_Yaw - Now_Param.Yaw_L.Yaw;
            accel_pos_z_cnt = -1;
            accel_neg_z_cnt = 0;
        }
        Past_Param.Yaw_L.Yaw = msg->Test_Yaw;

    }
    else
    {
        check_old_z=msg->Test_Yaw;
        Past_Param.Yaw_R.Yaw=msg->Test_Yaw;
        Past_Param.Yaw_L.Yaw=msg->Test_Yaw;
    }

    Past_Param.X.Tuning_X = msg->Tuning_X;
    Past_Param.X.Default_X_Right = msg->Default_X_Right;
    Past_Param.X.Default_X_Left = msg->Default_X_Left;

    Past_Param.Y.Tuning_Side = msg->Tuning_Side;
    Past_Param.Y.Default_Y_Right = msg->Default_Y_Right;
    Past_Param.Y.Default_Y_Left = msg->Default_Y_Left;
    Past_Param.Y.Swing_Right_Leg = msg->Swing_Right_Leg;
    Past_Param.Y.Swing_Left_Leg = msg->Swing_Left_Leg;

    Past_Param.Z.Default_Z_Right = msg->Default_Z_Right;
    Past_Param.Z.Default_Z_Left = msg->Default_Z_Left;
    Past_Param.Z.Rise_Right_Leg = msg->Rise_Right_Leg;
    Past_Param.Z.Rise_Left_Leg = msg->Rise_Left_Leg;
    Past_Param.Shoulder.Swing_Right_Shoulder = msg->Swing_Right_Shoulder;
    Past_Param.Shoulder.Swing_Left_Shoulder = msg->Swing_Left_Shoulder;

    Past_Param.Yaw_R.Tuning_Yaw = msg->Tuning_Yaw;
    Past_Param.Yaw_L.Tuning_Yaw = msg->Tuning_Yaw;

    IK.Past_Motor_Angle.Motor_Angle_10 = msg-> Offset_10_Motor;
    IK.Past_Motor_Angle.Motor_Angle_11 = msg-> Offset_11_Motor;
    IK.Past_Motor_Angle.Motor_Angle_12 = msg-> Offset_12_Motor;
    IK.Past_Motor_Angle.Motor_Angle_13 = msg-> Offset_13_Motor;
    IK.Past_Motor_Angle.Motor_Angle_14 = msg-> Offset_14_Motor;
    IK.Past_Motor_Angle.Motor_Angle_15 = msg-> Offset_15_Motor;
    IK.Past_Motor_Angle.Motor_Angle_16 = msg-> Offset_16_Motor;
    IK.Past_Motor_Angle.Motor_Angle_17 = msg-> Offset_17_Motor;
    IK.Past_Motor_Angle.Motor_Angle_18 = msg-> Offset_18_Motor;
    IK.Past_Motor_Angle.Motor_Angle_19 = msg-> Offset_19_Motor;
    IK.Past_Motor_Angle.Motor_Angle_20 = msg-> Offset_20_Motor;
    IK.Past_Motor_Angle.Motor_Angle_21 = msg-> Offset_21_Motor;

    IK.Now_Motor_Angle=IK.Past_Motor_Angle;

    Past_Param.Start_Entire_Time = msg ->Start_Entire_Time;

    Past_Param.Y.Start_Swing = msg->Start_Swing;
    Past_Param.Z.Start_Rise = msg->Start_Rise;
    Now_Param.End_Entire_Time = msg->End_Entire_Time;
    Now_Param.Y.End_Swing = msg->End_Swing;
    Now_Param.Z.End_Rise = msg->End_Rise;
    Balancing_Param.Balance.Balance_Value_0 = msg -> Balance_Value_0;
    Balancing_Param.Balance.Balance_Value_1 = msg -> Balance_Value_1;
    Balancing_Param.Balance.Balance_Value_2 = msg -> Balance_Value_2;
    Balancing_Param.Balance.Balance_Value_3 = msg -> Balance_Value_3;
    Balancing_Param.Balance.Balance_Pitch_GP = msg -> Balance_Pitch_GP;
    Balancing_Param.Balance.Balance_Pitch_GI = msg -> Balance_Pitch_GI;
    Balancing_Param.Balance.Balance_Pitch_GD = msg -> Balance_Pitch_GD;
    Balancing_Param.Balance.Balance_Pitch_ELIMIT = msg -> Balance_Pitch_ELIMIT;
    Balancing_Param.Balance.Balance_Pitch_OLIMIT = msg -> Balance_Pitch_OLIMIT;
    Balancing_Param.Balance.Balance_Pitch_Neg_Target = msg -> Balance_Pitch_Neg_Target;
    Balancing_Param.Balance.Balance_Pitch_Pos_Target = msg -> Balance_Pitch_Pos_Target;

    Balancing_Param.Balance.Balance_Angle_Pitch_GP = msg -> Balance_Angle_Pitch_GP;
    Balancing_Param.Balance.Balance_Angle_Pitch_GI = msg -> Balance_Angle_Pitch_GI;
    Balancing_Param.Balance.Balance_Angle_Pitch_GD = msg -> Balance_Angle_Pitch_GD;
    Balancing_Param.Balance.Balance_Angle_Pitch_ELIMIT = msg -> Balance_Angle_Pitch_ELIMIT;
    Balancing_Param.Balance.Balance_Angle_Pitch_OLIMIT = msg -> Balance_Angle_Pitch_OLIMIT;
    Balancing_Param.Balance.Balance_Angle_Pitch_Neg_Target = msg -> Balance_Angle_Pitch_Neg_Target;
    Balancing_Param.Balance.Balance_Angle_Pitch_Pos_Target = msg -> Balance_Angle_Pitch_Pos_Target;
    Balancing_Param.Balance.Balance_Roll_GP = msg -> Balance_Roll_GP;
    Balancing_Param.Balance.Balance_Roll_GI = msg -> Balance_Roll_GI;
    Balancing_Param.Balance.Balance_Roll_GD = msg -> Balance_Roll_GD;
    Balancing_Param.Balance.Balance_Roll_ELIMIT = msg -> Balance_Roll_ELIMIT;
    Balancing_Param.Balance.Balance_Roll_OLIMIT = msg -> Balance_Roll_OLIMIT;
    Balancing_Param.Balance.Balance_Roll_Neg_Target = msg -> Balance_Roll_Neg_Target;
    Balancing_Param.Balance.Balance_Roll_Pos_Target = msg -> Balance_Roll_Pos_Target;

    Balancing_Param.Balance.Balance_Pitch_GP_imu = msg -> Balance_Pitch_GP_imu;
    Balancing_Param.Balance.Balance_Pitch_GI_imu = msg -> Balance_Pitch_GI_imu;
    Balancing_Param.Balance.Balance_Pitch_GD_imu = msg -> Balance_Pitch_GD_imu;
    Balancing_Param.Balance.Balance_Pitch_ELIMIT_imu = msg -> Balance_Pitch_ELIMIT_imu;
    Balancing_Param.Balance.Balance_Pitch_OLIMIT_imu = msg -> Balance_Pitch_OLIMIT_imu;
    Balancing_Param.Balance.Balance_Pitch_Neg_Target_imu = msg -> Balance_Pitch_Neg_Target_imu;
    Balancing_Param.Balance.Balance_Pitch_Pos_Target_imu = msg -> Balance_Pitch_Pos_Target_imu;

    Balancing_Param.Balance.Balance_Roll_GP_imu = msg -> Balance_Roll_GP_imu;
    Balancing_Param.Balance.Balance_Roll_GI_imu = msg -> Balance_Roll_GI_imu;
    Balancing_Param.Balance.Balance_Roll_GD_imu = msg -> Balance_Roll_GD_imu;
    Balancing_Param.Balance.Balance_Roll_ELIMIT_imu = msg -> Balance_Roll_ELIMIT_imu;
    Balancing_Param.Balance.Balance_Roll_OLIMIT_imu = msg -> Balance_Roll_OLIMIT_imu;
    Balancing_Param.Balance.Balance_Roll_Neg_Target_imu = msg -> Balance_Roll_Neg_Target_imu;
    Balancing_Param.Balance.Balance_Roll_Pos_Target_imu = msg -> Balance_Roll_Pos_Target_imu;

    Balancing_Param.Balance.Balance_Pitch_Flag = msg -> Balance_Pitch_Flag;
    Balancing_Param.Balance.Balance_Angle_Pitch_Flag = msg -> Balance_Ankle_Pitch_Flag;
    Balancing_Param.Balance.Balance_Roll_Flag = msg -> Balance_Roll_Flag;
    Balancing_Param.Balance.Balance_Pitch_Flag_imu = msg -> Balance_Pitch_Flag_imu;
    Balancing_Param.Balance.Balance_Roll_Flag_imu = msg -> Balance_Roll_Flag_imu;

    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_10 = msg ->Percentage_of_IK_10_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_11 = msg ->Percentage_of_IK_11_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_12 = msg ->Percentage_of_IK_12_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_13 = msg ->Percentage_of_IK_13_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_14 = msg ->Percentage_of_IK_14_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_15 = msg ->Percentage_of_IK_15_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_16 = msg ->Percentage_of_IK_16_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_17 = msg ->Percentage_of_IK_17_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_18 = msg ->Percentage_of_IK_18_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_19 = msg ->Percentage_of_IK_19_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_20 = msg ->Percentage_of_IK_20_Motor;
    IK.Past_Percentage_of_IK_Motor.Motor_Multiple_21 = msg ->Percentage_of_IK_21_Motor;

    IK.Now_Percentage_of_IK_Motor = IK.Past_Percentage_of_IK_Motor;

    ////////////Kinetic_value/////////////////////
    K_value[0].Pos_XR = msg->First_Pos_XR;
    K_value[0].Neg_XR = msg->First_Neg_XR;
    K_value[0].Pos_SideR = msg->First_Pos_SideR;
    K_value[0].Neg_SideR = msg->First_Neg_SideR;
    K_value[0].Pos_YawR = msg->First_Pos_YawR;
    K_value[0].Neg_YawR = msg->First_Neg_YawR;
    K_value[0].Pos_XL = msg->First_Pos_XL;
    K_value[0].Neg_XL = msg->First_Neg_XL;
    K_value[0].Pos_SideL = msg->First_Pos_SideL;
    K_value[0].Neg_SideL = msg->First_Neg_SideL;
    K_value[0].Pos_YawL = msg->First_Pos_YawL;
    K_value[0].Neg_YawL = msg->First_Neg_YawL;
    K_value[0].Pos_SideR_SwingMinus = msg->First_Pos_SideR_SwingMinus;
    K_value[0].Neg_SideR_SwingMinus = msg->First_Neg_SideR_SwingMinus;
    K_value[0].Pos_SideL_SwingMinus = msg->First_Pos_SideL_SwingMinus;
    K_value[0].Neg_SideL_SwingMinus = msg->First_Neg_SideL_SwingMinus;
    K_value[0].min = msg->First_min;
    K_value[0].max = msg->First_max;

    K_value[1].Pos_XR = msg->Second_Pos_XR;
    K_value[1].Neg_XR = msg->Second_Neg_XR;
    K_value[1].Pos_SideR = msg->Second_Pos_SideR;
    K_value[1].Neg_SideR = msg->Second_Neg_SideR;
    K_value[1].Pos_YawR = msg->Second_Pos_YawR;
    K_value[1].Neg_YawR = msg->Second_Neg_YawR;
    K_value[1].Pos_XL = msg->Second_Pos_XL;
    K_value[1].Neg_XL = msg->Second_Neg_XL;
    K_value[1].Pos_SideL = msg->Second_Pos_SideL;
    K_value[1].Neg_SideL = msg->Second_Neg_SideL;
    K_value[1].Pos_YawL = msg->Second_Pos_YawL;
    K_value[1].Neg_YawL = msg->Second_Neg_YawL;
    K_value[1].Pos_SideR_SwingMinus = msg->Second_Pos_SideR_SwingMinus;
    K_value[1].Neg_SideR_SwingMinus = msg->Second_Neg_SideR_SwingMinus;
    K_value[1].Pos_SideL_SwingMinus = msg->Second_Pos_SideL_SwingMinus;
    K_value[1].Neg_SideL_SwingMinus = msg->Second_Neg_SideL_SwingMinus;
    K_value[1].min = msg->Second_min;
    K_value[1].max = msg->Second_max;

    K_value[2].Pos_XR = msg->Third_Pos_XR;
    K_value[2].Neg_XR = msg->Third_Neg_XR;
    K_value[2].Pos_SideR = msg->Third_Pos_SideR;
    K_value[2].Neg_SideR = msg->Third_Neg_SideR;
    K_value[2].Pos_YawR = msg->Third_Pos_YawR;
    K_value[2].Neg_YawR = msg->Third_Neg_YawR;
    K_value[2].Pos_XL = msg->Third_Pos_XL;
    K_value[2].Neg_XL = msg->Third_Neg_XL;
    K_value[2].Pos_SideL = msg->Third_Pos_SideL;
    K_value[2].Neg_SideL = msg->Third_Neg_SideL;
    K_value[2].Pos_YawL = msg->Third_Pos_YawL;
    K_value[2].Neg_YawL = msg->Third_Neg_YawL;
    K_value[2].Pos_SideR_SwingMinus = msg->Third_Pos_SideR_SwingMinus;
    K_value[2].Neg_SideR_SwingMinus = msg->Third_Neg_SideR_SwingMinus;
    K_value[2].Pos_SideL_SwingMinus = msg->Third_Pos_SideL_SwingMinus;
    K_value[2].Neg_SideL_SwingMinus = msg->Third_Neg_SideL_SwingMinus;
    K_value[2].min = msg->Third_min;
    K_value[2].max = msg->Third_max;

    K_value[3].Pos_XR = msg->Fourth_Pos_XR;
    K_value[3].Neg_XR = msg->Fourth_Neg_XR;
    K_value[3].Pos_SideR = msg->Fourth_Pos_SideR;
    K_value[3].Neg_SideR = msg->Fourth_Neg_SideR;
    K_value[3].Pos_YawR = msg->Fourth_Pos_YawR;
    K_value[3].Neg_YawR = msg->Fourth_Neg_YawR;
    K_value[3].Pos_XL = msg->Fourth_Pos_XL;
    K_value[3].Neg_XL = msg->Fourth_Neg_XL;
    K_value[3].Pos_SideL = msg->Fourth_Pos_SideL;
    K_value[3].Neg_SideL = msg->Fourth_Neg_SideL;
    K_value[3].Pos_YawL = msg->Fourth_Pos_YawL;
    K_value[3].Neg_YawL = msg->Fourth_Neg_YawL;
    K_value[3].Pos_SideR_SwingMinus = msg->Fourth_Pos_SideR_SwingMinus;
    K_value[3].Neg_SideR_SwingMinus = msg->Fourth_Neg_SideR_SwingMinus;
    K_value[3].Pos_SideL_SwingMinus = msg->Fourth_Pos_SideL_SwingMinus;
    K_value[3].Neg_SideL_SwingMinus = msg->Fourth_Neg_SideL_SwingMinus;
    K_value[3].min = msg->Fourth_min;
    K_value[3].max = msg->Fourth_max;

    Landing_Time_Control_flag = msg->Landing_Time_Control_flag;

    Balancing_Param.Balance.Balance_Pitch_Flag_imu = msg->Balance_Pitch_Flag_imu;
    Balancing_Param.Balance.Balance_Roll_Flag_imu = msg->Balance_Roll_Flag_imu;
    Balancing_Param.Balance.Balance_Pitch_Flag = msg->Balance_Pitch_Flag;
    Balancing_Param.Balance.Balance_Angle_Pitch_Flag = msg->Balance_Ankle_Pitch_Flag;
    Balancing_Param.Balance.Balance_Roll_Flag = msg->Balance_Roll_Flag;

}
void zmp_callback(const msg_generate::zmp_msg::ConstPtr& msg)
{
    Zmp_Info.Right_X_zmp = msg->Right_X_zmp;
    Zmp_Info.Right_Y_zmp = msg->Right_Y_zmp;
    Zmp_Info.Left_X_zmp  = msg->Left_X_zmp;
    Zmp_Info.Left_Y_zmp  = msg->Left_Y_zmp;
    Zmp_Info.Total_X_zmp = msg->Total_X_zmp;
    Zmp_Info.Total_Y_zmp = msg->Total_Y_zmp;
    Zmp_Info.Right_Foot = msg->Right_Foot;
    Zmp_Info.Left_Foot = msg->Left_Foot;
    Zmp_Info.Both_Feet = msg->Both_Feet;
}

double negative_position(double x)
{
    if(x<=0.0) return x;
    else return 0;
}

double positive_position(double x)
{
    if(x>=0.0) return x;
    else return 0;
}

double step_acc_func(double basic, double acc, int num, int & cnt)
{
    if(num == cnt)
    {
        cnt = -1;
        return basic + acc;
    }
    else
    {
        return basic + (acc / num) * cnt;
    }
}
