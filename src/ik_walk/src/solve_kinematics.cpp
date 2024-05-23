#include "../include/ik_walk/solve_kinematics.hpp"
#include "../include/ik_walk/ik_walk.hpp"


double IK_Solve::ang2pos(double angle)
{
    return (double)((angle * 4096.0) / 360.0);
}

void IK_Solve::init_save()
{
    double top_angle[10]={592,432,512,522,102,922,512,512,512,512};//다리 제외 모터값 작성(다리부 512로 고정)

    for(int DXL_ID = 0; DXL_ID <= 22; DXL_ID++)
    {
        if(DXL_ID <= 9){
            g_DXL_ID_position[DXL_ID] = top_angle[DXL_ID]*4;
            g_DXL_ID_Save_position[DXL_ID] = top_angle[DXL_ID]*4;
        }
        else{
            g_DXL_ID_position[DXL_ID] = 512*4;
            g_DXL_ID_Save_position[DXL_ID] = 512*4;
        }
        cout<<"g_DXL_ID_Save_position["<<DXL_ID<<"] = "<<(g_DXL_ID_Save_position[DXL_ID]/4)<<endl;
    }
}

void IK_Solve::Balance_Control_Body_Upright(double Input_Data, double Robot_Z, double Time  ,double Rise_Condition , double Input_Data2 , double Balance_Value_Msg ,double Balance_Value_Msg2 ,double Zmp_Pitch_Limit_Left ,double Zmp_Pitch_Limit_Right ,double Input_Data3 ,double Balance_Value_Msg3,double Balance_Value_Msg4, double L_1, double Zmp_Roll_Limit_Left, double Zmp_Roll_Limit_Right, int Support_Condition)
{
    Now_Balance_Theta.Theta1 = 0;
    Now_Balance_Theta.Theta2 = 0;
    Now_Balance_Theta.Theta3 = -Input_Data * Balance_Value_Msg;
    Compensate_Angle_Data.Vertical_Angle = -Input_Data3 * Balance_Value_Msg3;


    if(Support_Condition == 1)
    {
        Now_Balance_Theta.Right_Theta1 = Now_Balance_Theta.Theta1;
        Now_Balance_Theta.Right_Theta2 = Now_Balance_Theta.Theta2;
        Now_Balance_Theta.Right_Theta3 = Now_Balance_Theta.Theta3;
        Now_Balance_Theta.Left_Theta1 = 0;
        Now_Balance_Theta.Left_Theta2 = 0;
        Now_Balance_Theta.Left_Theta3 = 0;

        //        if(Input_Data3 <= 0.0)
        //        {
        //            Compensate_Angle_Data.Vertical_Angle = Compensate_Angle_Data.Vertical_Angle;
        //        }
        //        else if(Input_Data3 > 0.0)
        //        {
        //            Compensate_Angle_Data.Vertical_Angle = 0;
        //        }
        Compensate_Angle_Data.R_Vertical_Angle = -Compensate_Angle_Data.Vertical_Angle;
        Compensate_Angle_Data.L_Vertical_Angle = 0;
        //        Compensate_Angle_Data.Compensate_Angle_Left_14 = 0;
        //        Compensate_Angle_Data.Compensate_Angle_Right_15 = (Imu_Balance.Pitch_ADD_Angle*1)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;

    }
    else if(Support_Condition == -1)
    {
        Now_Balance_Theta.Left_Theta1 = Now_Balance_Theta.Theta1;
        Now_Balance_Theta.Left_Theta2 = Now_Balance_Theta.Theta2;
        Now_Balance_Theta.Left_Theta3 = Now_Balance_Theta.Theta3;
        Now_Balance_Theta.Right_Theta1 = 0;
        Now_Balance_Theta.Right_Theta2 = 0;
        Now_Balance_Theta.Right_Theta3 = 0;

        //        if(Input_Data3 <= 0.0)
        //        {
        //            Compensate_Angle_Data.Vertical_Angle = 0;
        //        }
        //        else if(Input_Data3 > 0.0)
        //        {
        //            Compensate_Angle_Data.Vertical_Angle = -Compensate_Angle_Data.Vertical_Angle;
        //        }
        Compensate_Angle_Data.R_Vertical_Angle = 0;
        Compensate_Angle_Data.L_Vertical_Angle = Compensate_Angle_Data.Vertical_Angle;
        //        Compensate_Angle_Data.Compensate_Angle_Left_14 = (Imu_Balance.Pitch_ADD_Angle*1);
        //        Compensate_Angle_Data.Compensate_Angle_Right_15 = 0/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;

    }
    else if(Support_Condition == 0)
    {
        Now_Balance_Theta.Right_Theta1 = Now_Balance_Theta.Theta1;
        Now_Balance_Theta.Right_Theta2 = Now_Balance_Theta.Theta2;
        Now_Balance_Theta.Right_Theta3 = Now_Balance_Theta.Theta3;

        Now_Balance_Theta.Left_Theta1 = Now_Balance_Theta.Theta1;
        Now_Balance_Theta.Left_Theta2 = Now_Balance_Theta.Theta2;
        Now_Balance_Theta.Left_Theta3 = Now_Balance_Theta.Theta3;

        if(Input_Data3 <= 0.0)
        {
            Compensate_Angle_Data.Vertical_Angle = Compensate_Angle_Data.Vertical_Angle;
        }
        else if(Input_Data3 > 0.0)
        {
            Compensate_Angle_Data.Vertical_Angle = -Compensate_Angle_Data.Vertical_Angle;
        }

        Compensate_Angle_Data.Vertical_Angle = 0;
        Compensate_Angle_Data.R_Vertical_Angle = Compensate_Angle_Data.Vertical_Angle*0.41;
        Compensate_Angle_Data.L_Vertical_Angle = Compensate_Angle_Data.Vertical_Angle*0.41;
        //        Compensate_Angle_Data.Compensate_Angle_Left_14 = (Imu_Balance.Pitch_ADD_Angle*1)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        //        Compensate_Angle_Data.Compensate_Angle_Right_15 = (Imu_Balance.Pitch_ADD_Angle*1)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
    }
    else if(Support_Condition == 99)
    {
        Now_Balance_Theta.Right_Theta1 = 0;
        Now_Balance_Theta.Right_Theta2 = 0;
        Now_Balance_Theta.Right_Theta3 = 0;

        Now_Balance_Theta.Left_Theta1 = 0;
        Now_Balance_Theta.Left_Theta2 = 0;
        Now_Balance_Theta.Left_Theta3 = 0;

        Compensate_Angle_Data.Vertical_Angle = 0;
        Compensate_Angle_Data.R_Vertical_Angle = Compensate_Angle_Data.Vertical_Angle;
        Compensate_Angle_Data.L_Vertical_Angle = Compensate_Angle_Data.Vertical_Angle;
        //        Compensate_Angle_Data.Compensate_Angle_Left_14 = (Imu_Balance.Pitch_ADD_Angle*1)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        //        Compensate_Angle_Data.Compensate_Angle_Right_15 = (Imu_Balance.Pitch_ADD_Angle*1)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
    }


}

void IK_Solve::solve(double pX_r, double pY_r, double pZ_r, double Yaw_R_deg, double pX_l, double pY_l, double pZ_l, double Yaw_L_deg, int body,double Shoulder_Pattern_X_R, double Shoulder_Pattern_X_L,double Shoulder_Pattern_Y_R, double Shoulder_Pattern_Y_L, double Balance_Theta1,double Balance_Theta2,double Balance_Theta3, double R_Rise_Condition, double L_Rise_Condition, double R_Rise_Max, double L_Rise_Max, double Imu_pitch, double Imu_pos, double Imu_neg, double Imu_roll, double Now_X)
{
    msg_generate::ik_angle_sim Position_Info;
    /////////////////////////////////  Solve Start  //////////////////////////////////

    const double C2p = 45, L_1 = 140, L_2 = 140; // C2p(Center to pelvis) = 중심에서 roll 축까지의 길이, L_1,2 = 링크 위 아래 길이
    double Yaw_L_rad = (double)(Yaw_L_deg * deg2rad), Yaw_R_rad = (double)(Yaw_R_deg * deg2rad);

    //왼다리 역기구학(왼다리 모터의 각도)------------------------------------------------------------------------------------------
    double L_temp[4] = {0,0,0,0};
    double L_Valid = (double)(((pX_l*pX_l) + ((pY_l-C2p)*(pY_l-C2p)) + ((pZ_l)*(pZ_l)) - (L_1*L_1) - (L_2*L_2) ) / (2*L_1*L_2)); // 제 2 cos법칙 이용

    InvLegAngle[0] = Yaw_L_rad;
    InvLegAngle[3] = (double)acos(L_Valid);
    InvLegAngle[1] = (double)(atan2(pZ_l, -pX_l*(double)sin(Yaw_L_rad)+(pY_l-C2p)*(double)cos(Yaw_L_rad)));

    L_temp[0] = (double)(-L_2*sin(InvLegAngle[3]));
    L_temp[1] = (double)(L_1+L_2*cos(InvLegAngle[3]));
    L_temp[2] = (double)(pX_l*cos(Yaw_L_rad)+(pY_l-C2p)*sin(Yaw_L_rad));
    L_temp[3] = (double)(-pX_l*sin(Yaw_L_rad)*cos(InvLegAngle[1])+(pY_l-C2p)*cos(Yaw_L_rad)*cos(InvLegAngle[1])+pZ_l*sin(InvLegAngle[1]));

    L_Valid = (double)((L_temp[0]*L_temp[3]-L_temp[1]*L_temp[2])/(L_temp[0]*L_temp[0]+L_temp[1]*L_temp[1]));

    InvLegAngle[2] = (double)asin(L_Valid);
    InvLegAngle[1] = (double)(InvLegAngle[1] + (PI/2.0));

    InvLegAngle[4] = -(InvLegAngle[3] + InvLegAngle[2]);
    InvLegAngle[5] = (1.0 * InvLegAngle[1]);

    //오른다리 역기구학(오른다리 모터의 각도)--------------------------------------------------------------------------------------
    double R_temp[4] = {0,0,0,0};
    double R_Valid = (double)(((pX_r*pX_r) + ((pY_r+C2p)*(pY_r+C2p)) + ((pZ_r)*(pZ_r)) - (L_1*L_1) - (L_2*L_2) ) / (2*L_1*L_2)); // 제 2 cos법칙 이용

    InvLegAngle[6] = Yaw_R_rad;
    InvLegAngle[9] = (double)acos(R_Valid);
    InvLegAngle[7] = (double)(atan2(pZ_r, -pX_r*(double)sin(Yaw_R_rad)+(C2p+pY_r)*(double)cos(Yaw_R_rad)));

    R_temp[0] = (double)(-L_2*sin(InvLegAngle[9]));
    R_temp[1] = (double)(L_1+L_2*cos(InvLegAngle[9]));
    R_temp[2] = (double)(pX_r*cos(Yaw_R_rad)+(pY_r+C2p)*sin(Yaw_R_rad));
    R_temp[3] = (double)(-pX_r*sin(Yaw_R_rad)*cos(InvLegAngle[7])+(pY_r+C2p)*cos(Yaw_R_rad)*cos(InvLegAngle[7])+pZ_r*sin(InvLegAngle[7]));

    R_Valid = (double)((R_temp[0]*R_temp[3]-R_temp[1]*R_temp[2])/(R_temp[0]*R_temp[0]+R_temp[1]*R_temp[1]));

    InvLegAngle[8] = (double)asin(R_Valid);
    InvLegAngle[7] = (double)(InvLegAngle[7] + (PI/2.0));

    InvLegAngle[10] = -(InvLegAngle[9] + InvLegAngle[8]);
    InvLegAngle[11] = (1.0 * InvLegAngle[7]);

    if(Run_Flag == true)//기구식 조건 해제:발목-지면 수평 조건
    {
        /*if(pX_l >= 0)*/       InvLegAngle[4] += -(pX_l * 0.002);
        /*elseif(pX_r >= 0)*/   InvLegAngle[10] += -(pX_r * 0.002);
    }
    else if(Ankle_Flag == true)//발가락과 뒷꿈치가 먼저 땅에 닿으며 보행하는 조건
    {
//        const double Fh = 49.5, Ff = 75, Fb = 75; //Fh(Foot height) Ft(Foot front), Fh(Foot back) = pitch축에서 발끝까지 길이
//        const double Rf = sqrt((Ff*Ff) + (Fh*Fh)), Rb = sqrt((Fb*Fb) + (Fh*Fh)); //Rf(발목피치축~발끝 거리), Rb(발목피치축~발뒷꿈치 거리)
//        const double AnkF_th = acos(-Fh/Rf), AnkB_th = acos(-Fh/Rb); // 발목피치축과 발끝 기울기

//        if(fabs(pZ_l) < fabs(pZ_r))//왼발이 떠있거나 DSP
//        {
//            double h = fabs(pZ_r) - fabs(pZ_l);// 양 다리간 높이차이
//            if(pX_l <= pX_r)//Foot front
//            {
//                double F_th = acos(-(Fh + h)/Rf);
//                InvLegAngle[4] -= AnkF_th - F_th;
//            }
//            else if(pX_l > pX_r)//Foot back
//            {
//                double B_th = acos(-(Fh + h)/Rb);
//                InvLegAngle[4] += AnkB_th - B_th;
//            }
//        }
//        else if(fabs(pZ_l) > fabs(pZ_r))//오른발이 떠있을경우
//        {
//            double h = fabs(pZ_l) - fabs(pZ_r);// 양 다리간 높이차이
//            if(pX_l >= pX_r)//Foot front
//            {
//                double F_th = acos(-(Fh + h)/Rf);
//                InvLegAngle[10] -= AnkF_th - F_th;
//            }
//            else if(pX_l < pX_r)//Foot back
//            {
//                double B_th = acos(-(Fh + h)/Rb);
//                InvLegAngle[10] += AnkB_th - B_th;
//            }
//        }
    }

    for(int i = 0; i < 23; i++)
    {
        g_DXL_ID_position[i] = g_DXL_ID_Save_position[i];
    }

    Compensate_Angle_Data.Compensate_Angle_Left_10 = /*(Imu_Balance.Roll_ADD_Angle)*/ + Compensate_Angle_Data.L_Vertical_Angle + Compensate_Angle_Data.R_Vertical_Angle/*-Imu_Info.roll_acc*0.01*/;
    if(Imu_pitch <= (Imu_pos + Imu_neg)/2){
        Compensate_Angle_Data.Compensate_Angle_Left_14 = (Imu_Balance.Pitch_ADD_Angle*4.0)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        Compensate_Angle_Data.Compensate_Angle_Left_16 = -(Imu_Balance.Pitch_ADD_Angle*2.0);

    }
    else {
        Compensate_Angle_Data.Compensate_Angle_Left_14 = (Imu_Balance.Pitch_ADD_Angle*2.0)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        Compensate_Angle_Data.Compensate_Angle_Left_16 = -(Imu_Balance.Pitch_ADD_Angle*0.0);
        //Compensate_Angle_Data.Compensate_Angle_Left_18 = -(Imu_Balance.Pitch_ADD_Angle*1.0);
    }

    Compensate_Angle_Data.Compensate_Angle_Left_18 = Now_Balance_Theta.Left_Theta3-(Imu_Balance.Pitch_ADD_Angle*1.0)+(Imu_Balance.Pitch_ADD_Angle*0.0);
    Compensate_Angle_Data.Compensate_Angle_Left_20 = -Compensate_Angle_Data.L_Vertical_Angle + (Imu_Balance.Roll_ADD_Angle*1);


    //////////////////////////////////////////////////////////////
    Compensate_Angle_Data.Compensate_Angle_Right_11 = /*(Imu_Balance.Roll_ADD_Angle)*/ + Compensate_Angle_Data.R_Vertical_Angle + Compensate_Angle_Data.L_Vertical_Angle/*-Imu_Info.roll_acc*0.01*/;
    if(Imu_pitch <= (Imu_pos + Imu_neg)/2){
        Compensate_Angle_Data.Compensate_Angle_Right_15 = (Imu_Balance.Pitch_ADD_Angle*4.0)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        Compensate_Angle_Data.Compensate_Angle_Right_17 = -(Imu_Balance.Pitch_ADD_Angle*2.0);

    }
    else {
        Compensate_Angle_Data.Compensate_Angle_Right_15 = (Imu_Balance.Pitch_ADD_Angle*2.0)/*-Imu_Info.pitch_acc*0.01*//*-(Past_Param.X.X*0.4)*/;
        Compensate_Angle_Data.Compensate_Angle_Right_17 = -(Imu_Balance.Pitch_ADD_Angle*0.0);
        //Compensate_Angle_Data.Compensate_Angle_Right_19 = -(Imu_Balance.Pitch_ADD_Angle*1.0);
    }
    Compensate_Angle_Data.Compensate_Angle_Right_19 = Now_Balance_Theta.Right_Theta3-(Imu_Balance.Pitch_ADD_Angle*1)+(Imu_Balance.Pitch_ADD_Angle*0.0);
    Compensate_Angle_Data.Compensate_Angle_Right_21 = -Compensate_Angle_Data.R_Vertical_Angle + (Imu_Balance.Roll_ADD_Angle*1);

    if(abs(Imu_pitch)<20)
    {
        if(pZ_l > pZ_r)
        {
            Compensate_Angle_Data.Compensate_Angle_Left_14 -= (Imu_Balance.Pitch_ADD_Angle*2.5);
            Compensate_Angle_Data.Compensate_Angle_Right_15 -= (Imu_Balance.Pitch_ADD_Angle*0.0);
        }
        else {
            Compensate_Angle_Data.Compensate_Angle_Left_14 -= (Imu_Balance.Pitch_ADD_Angle*0.0);
            Compensate_Angle_Data.Compensate_Angle_Right_15 -= (Imu_Balance.Pitch_ADD_Angle*2.5);
        }
    }


//        cout<<"Now_Balance_Theta.Theta1*rad2deg: "<<Now_Balance_Theta.Theta1*rad2deg<<endl;
//        cout<<"Now_Balance_Theta.Theta2*rad2deg: "<<Now_Balance_Theta.Theta2*rad2deg<<endl;
//        cout<<"Now_Balance_Theta.Theta3*rad2deg: "<<Now_Balance_Theta.Theta3*rad2deg<<endl;

//        cout<<"Compensate_14: "<<Compensate_Angle_Data.Compensate_Angle_Left_14<<endl;
//        cout<<"Compensate_16: "<<Compensate_Angle_Data.Compensate_Angle_Left_16<<endl;
//        cout<<"Compensate_18: "<<Compensate_Angle_Data.Compensate_Angle_Left_18<<endl;

//        cout<<"Compensate_15: "<<Compensate_Angle_Data.Compensate_Angle_Right_15<<endl;
//        cout<<"Compensate_17: "<<Compensate_Angle_Data.Compensate_Angle_Right_17<<endl;
//        cout<<"Compensate_19: "<<Compensate_Angle_Data.Compensate_Angle_Right_19<<endl;

    if(Now_Param.Y.Side >= 0.0) //옆으로 걸을 때
    {
        if(Shoulder_Pattern_Y_R>=0.0)
        {
            Shoulder_Pattern_Y_R = 0.0;
        }
        if(Shoulder_Pattern_Y_L<=0.0)
        {
            Shoulder_Pattern_Y_L = 0.0;
        }
        g_DXL_ID_position[2] += ang2pos(1.0*Shoulder_Pattern_Y_L + Compensate_Angle_Data.Compensate_Angle_Arm_2);
        g_DXL_ID_position[3] += ang2pos(-1.5*Shoulder_Pattern_Y_R + Compensate_Angle_Data.Compensate_Angle_Arm_3);
    }

    else if(Now_Param.Y.Side < 0.0)
    {
        if(Shoulder_Pattern_Y_R>=0.0)
        {
            Shoulder_Pattern_Y_R = 0.0;
        }
        if(Shoulder_Pattern_Y_L<=0.0)
        {
            Shoulder_Pattern_Y_L = 0.0;
        }
        g_DXL_ID_position[2] += ang2pos(-1.5*Shoulder_Pattern_Y_L + Compensate_Angle_Data.Compensate_Angle_Arm_2);
        g_DXL_ID_position[3] += ang2pos(1.0*Shoulder_Pattern_Y_R + Compensate_Angle_Data.Compensate_Angle_Arm_3);
    }

    //무게중심 이동
    if(Run_Flag == true)
    {
        Run_Add = (Now_X * 0.5);
    }
    else Run_Add = 0;

    g_DXL_ID_position[0] += ang2pos(Shoulder_Pattern_X_L + 1.5*Imu_Balance.Pitch_ADD_Angle/*-Compensate_Angle_Data.Horizontal_Angle*3*/);
    g_DXL_ID_position[1] -= ang2pos(Shoulder_Pattern_X_R + 1.5*Imu_Balance.Pitch_ADD_Angle/*-Compensate_Angle_Data.Horizontal_Angle*3*/);

    g_DXL_ID_position[12] -= ang2pos(InvLegAngle[0]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_12) + Now_Motor_Angle.Motor_Angle_12 + Compensate_Angle_Data.Compensate_Angle_Left_12;       //left_Yaw
    g_DXL_ID_position[14] += ang2pos(InvLegAngle[2]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_14 + Compensate_Angle_Data.Compensate_Angle_Left_14) + Now_Motor_Angle.Motor_Angle_14 + Run_Add;       //left_pitch
    g_DXL_ID_position[16] += ang2pos(InvLegAngle[3]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_16 + Compensate_Angle_Data.Compensate_Angle_Left_16) + Now_Motor_Angle.Motor_Angle_16 - Run_Add;       //left_pitch
    g_DXL_ID_position[18] -= ang2pos(InvLegAngle[4]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_18 + Compensate_Angle_Data.Compensate_Angle_Left_18/*+Compensate_Angle_Data.Horizontal_Angle*/) +Now_Motor_Angle.Motor_Angle_18 ;      //left_pitch

    g_DXL_ID_position[10] += 2*(ang2pos(InvLegAngle[1]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_10 + Compensate_Angle_Data.Compensate_Angle_Left_10) + Now_Motor_Angle.Motor_Angle_10);       //left_roll
    g_DXL_ID_position[20] -= 2*(ang2pos((-InvLegAngle[5]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_20/**2.5*//*+Compensate_Angle_Data.L_Vertical_Angle*/ + Compensate_Angle_Data.Compensate_Angle_Left_20)) + Now_Motor_Angle.Motor_Angle_20);       //left_roll


    g_DXL_ID_position[13] -= ang2pos(InvLegAngle[6]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_13) + Now_Motor_Angle.Motor_Angle_13 + Compensate_Angle_Data.Compensate_Angle_Right_13;       //right_Yaw
    g_DXL_ID_position[15] -= ang2pos(InvLegAngle[8]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_15 + Compensate_Angle_Data.Compensate_Angle_Right_15) + Now_Motor_Angle.Motor_Angle_15 + Run_Add;       //right_pitch
    g_DXL_ID_position[17] -= ang2pos(InvLegAngle[9]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_17 + Compensate_Angle_Data.Compensate_Angle_Right_17) + Now_Motor_Angle.Motor_Angle_17 - Run_Add;       //right_pitch
    g_DXL_ID_position[19] += ang2pos(InvLegAngle[10]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_19 + Compensate_Angle_Data.Compensate_Angle_Right_19/*+Compensate_Angle_Data.Horizontal_Angle*/) + Now_Motor_Angle.Motor_Angle_19;       //right_pitch

    g_DXL_ID_position[11] += 2*(ang2pos(InvLegAngle[7]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_11 + Compensate_Angle_Data.Compensate_Angle_Right_11) + Now_Motor_Angle.Motor_Angle_11);       //right_roll
    g_DXL_ID_position[21] -= 2*(ang2pos((-InvLegAngle[11]*rad2deg * Now_Percentage_of_IK_Motor.Motor_Multiple_21/**5.5*//*+Compensate_Angle_Data.R_Vertical_Angle*/ + Compensate_Angle_Data.Compensate_Angle_Right_21)) + Now_Motor_Angle.Motor_Angle_21);       //right_roll


    //발 겹침 방지
    if(Imu_roll>25)
    {
        g_DXL_ID_position[10] += ang2pos(5);
        g_DXL_ID_position[20] += ang2pos(40);
    }
    else if(Imu_roll<-25)
    {
        g_DXL_ID_position[11] -= ang2pos(5);
        g_DXL_ID_position[21] -= ang2pos(40);
    }

    //손 프레임 변형 방지
//    if(Imu_pitch>30)
//    {
//        g_DXL_ID_position[0] += ang2pos(40);
//        g_DXL_ID_position[1] -= ang2pos(40);
//    }
//    else if(Imu_pitch<-30)
//    {
//        g_DXL_ID_position[0] -= ang2pos(30);
//        g_DXL_ID_position[1] += ang2pos(30);
//    }

    Position_Info.ang_l_0 = g_DXL_ID_position[0];
    Position_Info.ang_l_1 = g_DXL_ID_position[2];
    Position_Info.ang_l_2 = g_DXL_ID_position[10];
    Position_Info.ang_l_3 = g_DXL_ID_position[12];
    Position_Info.ang_l_4 = g_DXL_ID_position[14];
    Position_Info.ang_l_5 = g_DXL_ID_position[16];
    Position_Info.ang_l_6 = g_DXL_ID_position[18];
    Position_Info.ang_l_7 = g_DXL_ID_position[20];
    Position_Info.ang_l_8 = g_DXL_ID_position[4];

    Position_Info.ang_r_0 = g_DXL_ID_position[1];
    Position_Info.ang_r_1 = g_DXL_ID_position[3];
    Position_Info.ang_r_2 = g_DXL_ID_position[11];
    Position_Info.ang_r_3 = g_DXL_ID_position[13];
    Position_Info.ang_r_4 = g_DXL_ID_position[15];
    Position_Info.ang_r_5 = g_DXL_ID_position[17];
    Position_Info.ang_r_6 = g_DXL_ID_position[19];
    Position_Info.ang_r_7 = g_DXL_ID_position[21];
    Position_Info.ang_r_8 = g_DXL_ID_position[5];

    Motor_Position_Pub.publish(Position_Info);
//        cout<<"Run_Flag : "<< Run_Flag <<endl;
//        cout<<"Run_Add : "<< Run_Add <<endl;

    //    cout<<"10 : "<<g_DXL_ID_position[10]<<endl;
    //    cout<<"11 : "<<g_DXL_ID_position[11]<<endl;
    //    cout<<"12 : "<<g_DXL_ID_position[12]<<endl;
    //    cout<<"13 : "<<g_DXL_ID_position[13]<<endl;
    //    cout<<"14 : "<<g_DXL_ID_position[14]<<endl;
    //    cout<<"15 : "<<g_DXL_ID_position[15]<<endl;
    //    cout<<"16 : "<<g_DXL_ID_position[16]<<endl;
    //    cout<<"17 : "<<g_DXL_ID_position[17]<<endl;
    //    cout<<"18 : "<<g_DXL_ID_position[18]<<endl;
    //    cout<<"19 : "<<g_DXL_ID_position[19]<<endl;
    //    cout<<"20 : "<<g_DXL_ID_position[20]<<endl;
    //    cout<<"21 : "<<g_DXL_ID_position[21]<<endl;

    //    cout<<"Now_Motor_Angle.Motor_Angle_10  "<<Now_Motor_Angle.Motor_Angle_10<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_11  "<<Now_Motor_Angle.Motor_Angle_11<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_12  "<<Now_Motor_Angle.Motor_Angle_12<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_13  "<<Now_Motor_Angle.Motor_Angle_13<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_14  "<<Now_Motor_Angle.Motor_Angle_14<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_15  "<<Now_Motor_Angle.Motor_Angle_15<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_16  "<<Now_Motor_Angle.Motor_Angle_16<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_17  "<<Now_Motor_Angle.Motor_Angle_17<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_18  "<<Now_Motor_Angle.Motor_Angle_18<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_19  "<<Now_Motor_Angle.Motor_Angle_19<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_20  "<<Now_Motor_Angle.Motor_Angle_20<<endl<<endl;
    //    cout<<"Now_Motor_Angle.Motor_Angle_21  "<<Now_Motor_Angle.Motor_Angle_21<<endl<<endl;

    if(body == All)
        motor_packet(All, 23);
    else if(body == Leg)
        motor_packet(Leg, 22);



    if(ikinit_flag)
    {
        cout<<endl<<"====  walk init ===="<<endl<<endl;
        for(int DXL_ID = 0; DXL_ID <= 22; DXL_ID++)
        {
            cout<< "g_DXL_ID_position[" << DXL_ID << "] = " << (g_DXL_ID_position[DXL_ID]/4) <<endl;
        }
        ikinit_flag = false;
    }
}

void IK_Solve::motor_packet(int body, int limit)
{
    msg_generate::Motor_msg Motor_Info;
    if(body == Leg)
    {
        for(int i = 0; i < 4; i++)//4 : 변경하지 말 것. 마스터에 심각한 딜레이 발생
        {
            Motor_Info.id.push_back(i);
            int pos = g_DXL_ID_position[i];
            Motor_Info.position.push_back(pos);
            Motor_Info.speed.push_back(0);
        }
    }
    for(int i = body; i < limit; i++)
    {
        Motor_Info.id.push_back(i);
        int pos = g_DXL_ID_position[i];
        Motor_Info.position.push_back(pos);
        Motor_Info.speed.push_back(0);
    }

    Motor_Info.length = Motor_Info.id.size();
    Motor_Info.mode = 3;


    Motor_Pub.publish(Motor_Info);
}
