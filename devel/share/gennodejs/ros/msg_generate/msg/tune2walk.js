// Auto-generated. Do not edit!

// (in-package msg_generate.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class tune2walk {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.IK_Flag = null;
      this.Entire_Time = null;
      this.Frequency = null;
      this.Default_X_Right = null;
      this.Default_X_Left = null;
      this.Default_Y_Right = null;
      this.Default_Y_Left = null;
      this.Default_Z_Right = null;
      this.Default_Z_Left = null;
      this.Offset_10_Motor = null;
      this.Offset_11_Motor = null;
      this.Offset_12_Motor = null;
      this.Offset_13_Motor = null;
      this.Offset_14_Motor = null;
      this.Offset_15_Motor = null;
      this.Offset_16_Motor = null;
      this.Offset_17_Motor = null;
      this.Offset_18_Motor = null;
      this.Offset_19_Motor = null;
      this.Offset_20_Motor = null;
      this.Offset_21_Motor = null;
      this.Swing_Right_Leg = null;
      this.Swing_Left_Leg = null;
      this.Swing_Right_Shoulder = null;
      this.Swing_Left_Shoulder = null;
      this.Rise_Right_Leg = null;
      this.Rise_Left_Leg = null;
      this.Start_Entire_Time = null;
      this.Start_Swing = null;
      this.Start_Rise = null;
      this.End_Entire_Time = null;
      this.End_Swing = null;
      this.End_Rise = null;
      this.Test_X = null;
      this.Test_Side = null;
      this.Test_Yaw = null;
      this.Tuning_X = null;
      this.Tuning_Side = null;
      this.Tuning_Yaw = null;
      this.Balance_Value_0 = null;
      this.Balance_Value_1 = null;
      this.Balance_Value_2 = null;
      this.Balance_Value_3 = null;
      this.Balance_Pitch_GP = null;
      this.Balance_Pitch_GI = null;
      this.Balance_Pitch_GD = null;
      this.Balance_Pitch_ELIMIT = null;
      this.Balance_Pitch_OLIMIT = null;
      this.Balance_Pitch_Neg_Target = null;
      this.Balance_Pitch_Pos_Target = null;
      this.Balance_Roll_GP = null;
      this.Balance_Roll_GI = null;
      this.Balance_Roll_GD = null;
      this.Balance_Roll_ELIMIT = null;
      this.Balance_Roll_OLIMIT = null;
      this.Balance_Roll_Neg_Target = null;
      this.Balance_Roll_Pos_Target = null;
      this.Balance_Angle_Pitch_GP = null;
      this.Balance_Angle_Pitch_GI = null;
      this.Balance_Angle_Pitch_GD = null;
      this.Balance_Angle_Pitch_ELIMIT = null;
      this.Balance_Angle_Pitch_OLIMIT = null;
      this.Balance_Angle_Pitch_Neg_Target = null;
      this.Balance_Angle_Pitch_Pos_Target = null;
      this.Balance_Value_4 = null;
      this.Balance_Value_5 = null;
      this.Balance_Pitch_Flag_imu = null;
      this.Balance_Pitch_GP_imu = null;
      this.Balance_Pitch_GI_imu = null;
      this.Balance_Pitch_GD_imu = null;
      this.Balance_Pitch_Neg_Target_imu = null;
      this.Balance_Pitch_Pos_Target_imu = null;
      this.Balance_Pitch_ELIMIT_imu = null;
      this.Balance_Pitch_OLIMIT_imu = null;
      this.Balance_Roll_Flag_imu = null;
      this.Balance_Roll_GP_imu = null;
      this.Balance_Roll_GI_imu = null;
      this.Balance_Roll_GD_imu = null;
      this.Balance_Roll_Neg_Target_imu = null;
      this.Balance_Roll_Pos_Target_imu = null;
      this.Balance_Roll_ELIMIT_imu = null;
      this.Balance_Roll_OLIMIT_imu = null;
      this.Balance_Pitch_Flag = null;
      this.Balance_Ankle_Pitch_Flag = null;
      this.Balance_Roll_Flag = null;
      this.Ratio_Check_Flag = null;
      this.Center2Leg = null;
      this.Link2Link = null;
      this.Init_Z_Up = null;
      this.Percentage_of_IK_10_Motor = null;
      this.Percentage_of_IK_11_Motor = null;
      this.Percentage_of_IK_12_Motor = null;
      this.Percentage_of_IK_13_Motor = null;
      this.Percentage_of_IK_14_Motor = null;
      this.Percentage_of_IK_15_Motor = null;
      this.Percentage_of_IK_16_Motor = null;
      this.Percentage_of_IK_17_Motor = null;
      this.Percentage_of_IK_18_Motor = null;
      this.Percentage_of_IK_19_Motor = null;
      this.Percentage_of_IK_20_Motor = null;
      this.Percentage_of_IK_21_Motor = null;
      this.First_Pos_XR = null;
      this.First_Neg_XR = null;
      this.First_Pos_SideR = null;
      this.First_Neg_SideR = null;
      this.First_Pos_YawR = null;
      this.First_Neg_YawR = null;
      this.First_Pos_XL = null;
      this.First_Neg_XL = null;
      this.First_Pos_SideL = null;
      this.First_Neg_SideL = null;
      this.First_Pos_YawL = null;
      this.First_Neg_YawL = null;
      this.First_Pos_SideR_SwingMinus = null;
      this.First_Neg_SideR_SwingMinus = null;
      this.First_Pos_SideL_SwingMinus = null;
      this.First_Neg_SideL_SwingMinus = null;
      this.First_min = null;
      this.First_max = null;
      this.Second_Pos_XR = null;
      this.Second_Neg_XR = null;
      this.Second_Pos_SideR = null;
      this.Second_Neg_SideR = null;
      this.Second_Pos_YawR = null;
      this.Second_Neg_YawR = null;
      this.Second_Pos_XL = null;
      this.Second_Neg_XL = null;
      this.Second_Pos_SideL = null;
      this.Second_Neg_SideL = null;
      this.Second_Pos_YawL = null;
      this.Second_Neg_YawL = null;
      this.Second_Pos_SideR_SwingMinus = null;
      this.Second_Neg_SideR_SwingMinus = null;
      this.Second_Pos_SideL_SwingMinus = null;
      this.Second_Neg_SideL_SwingMinus = null;
      this.Second_min = null;
      this.Second_max = null;
      this.Third_Pos_XR = null;
      this.Third_Neg_XR = null;
      this.Third_Pos_SideR = null;
      this.Third_Neg_SideR = null;
      this.Third_Pos_YawR = null;
      this.Third_Neg_YawR = null;
      this.Third_Pos_XL = null;
      this.Third_Neg_XL = null;
      this.Third_Pos_SideL = null;
      this.Third_Neg_SideL = null;
      this.Third_Pos_YawL = null;
      this.Third_Neg_YawL = null;
      this.Third_Pos_SideR_SwingMinus = null;
      this.Third_Neg_SideR_SwingMinus = null;
      this.Third_Pos_SideL_SwingMinus = null;
      this.Third_Neg_SideL_SwingMinus = null;
      this.Third_min = null;
      this.Third_max = null;
      this.Fourth_Pos_XR = null;
      this.Fourth_Neg_XR = null;
      this.Fourth_Pos_SideR = null;
      this.Fourth_Neg_SideR = null;
      this.Fourth_Pos_YawR = null;
      this.Fourth_Neg_YawR = null;
      this.Fourth_Pos_XL = null;
      this.Fourth_Neg_XL = null;
      this.Fourth_Pos_SideL = null;
      this.Fourth_Neg_SideL = null;
      this.Fourth_Pos_YawL = null;
      this.Fourth_Neg_YawL = null;
      this.Fourth_Pos_SideR_SwingMinus = null;
      this.Fourth_Neg_SideR_SwingMinus = null;
      this.Fourth_Pos_SideL_SwingMinus = null;
      this.Fourth_Neg_SideL_SwingMinus = null;
      this.Fourth_min = null;
      this.Fourth_max = null;
      this.Landing_Time_Control_flag = null;
      this.Control_System_flag = null;
    }
    else {
      if (initObj.hasOwnProperty('IK_Flag')) {
        this.IK_Flag = initObj.IK_Flag
      }
      else {
        this.IK_Flag = false;
      }
      if (initObj.hasOwnProperty('Entire_Time')) {
        this.Entire_Time = initObj.Entire_Time
      }
      else {
        this.Entire_Time = 0.0;
      }
      if (initObj.hasOwnProperty('Frequency')) {
        this.Frequency = initObj.Frequency
      }
      else {
        this.Frequency = 0.0;
      }
      if (initObj.hasOwnProperty('Default_X_Right')) {
        this.Default_X_Right = initObj.Default_X_Right
      }
      else {
        this.Default_X_Right = 0.0;
      }
      if (initObj.hasOwnProperty('Default_X_Left')) {
        this.Default_X_Left = initObj.Default_X_Left
      }
      else {
        this.Default_X_Left = 0.0;
      }
      if (initObj.hasOwnProperty('Default_Y_Right')) {
        this.Default_Y_Right = initObj.Default_Y_Right
      }
      else {
        this.Default_Y_Right = 0.0;
      }
      if (initObj.hasOwnProperty('Default_Y_Left')) {
        this.Default_Y_Left = initObj.Default_Y_Left
      }
      else {
        this.Default_Y_Left = 0.0;
      }
      if (initObj.hasOwnProperty('Default_Z_Right')) {
        this.Default_Z_Right = initObj.Default_Z_Right
      }
      else {
        this.Default_Z_Right = 0.0;
      }
      if (initObj.hasOwnProperty('Default_Z_Left')) {
        this.Default_Z_Left = initObj.Default_Z_Left
      }
      else {
        this.Default_Z_Left = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_10_Motor')) {
        this.Offset_10_Motor = initObj.Offset_10_Motor
      }
      else {
        this.Offset_10_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_11_Motor')) {
        this.Offset_11_Motor = initObj.Offset_11_Motor
      }
      else {
        this.Offset_11_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_12_Motor')) {
        this.Offset_12_Motor = initObj.Offset_12_Motor
      }
      else {
        this.Offset_12_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_13_Motor')) {
        this.Offset_13_Motor = initObj.Offset_13_Motor
      }
      else {
        this.Offset_13_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_14_Motor')) {
        this.Offset_14_Motor = initObj.Offset_14_Motor
      }
      else {
        this.Offset_14_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_15_Motor')) {
        this.Offset_15_Motor = initObj.Offset_15_Motor
      }
      else {
        this.Offset_15_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_16_Motor')) {
        this.Offset_16_Motor = initObj.Offset_16_Motor
      }
      else {
        this.Offset_16_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_17_Motor')) {
        this.Offset_17_Motor = initObj.Offset_17_Motor
      }
      else {
        this.Offset_17_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_18_Motor')) {
        this.Offset_18_Motor = initObj.Offset_18_Motor
      }
      else {
        this.Offset_18_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_19_Motor')) {
        this.Offset_19_Motor = initObj.Offset_19_Motor
      }
      else {
        this.Offset_19_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_20_Motor')) {
        this.Offset_20_Motor = initObj.Offset_20_Motor
      }
      else {
        this.Offset_20_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Offset_21_Motor')) {
        this.Offset_21_Motor = initObj.Offset_21_Motor
      }
      else {
        this.Offset_21_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Right_Leg')) {
        this.Swing_Right_Leg = initObj.Swing_Right_Leg
      }
      else {
        this.Swing_Right_Leg = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Left_Leg')) {
        this.Swing_Left_Leg = initObj.Swing_Left_Leg
      }
      else {
        this.Swing_Left_Leg = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Right_Shoulder')) {
        this.Swing_Right_Shoulder = initObj.Swing_Right_Shoulder
      }
      else {
        this.Swing_Right_Shoulder = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Left_Shoulder')) {
        this.Swing_Left_Shoulder = initObj.Swing_Left_Shoulder
      }
      else {
        this.Swing_Left_Shoulder = 0.0;
      }
      if (initObj.hasOwnProperty('Rise_Right_Leg')) {
        this.Rise_Right_Leg = initObj.Rise_Right_Leg
      }
      else {
        this.Rise_Right_Leg = 0.0;
      }
      if (initObj.hasOwnProperty('Rise_Left_Leg')) {
        this.Rise_Left_Leg = initObj.Rise_Left_Leg
      }
      else {
        this.Rise_Left_Leg = 0.0;
      }
      if (initObj.hasOwnProperty('Start_Entire_Time')) {
        this.Start_Entire_Time = initObj.Start_Entire_Time
      }
      else {
        this.Start_Entire_Time = 0.0;
      }
      if (initObj.hasOwnProperty('Start_Swing')) {
        this.Start_Swing = initObj.Start_Swing
      }
      else {
        this.Start_Swing = 0.0;
      }
      if (initObj.hasOwnProperty('Start_Rise')) {
        this.Start_Rise = initObj.Start_Rise
      }
      else {
        this.Start_Rise = 0.0;
      }
      if (initObj.hasOwnProperty('End_Entire_Time')) {
        this.End_Entire_Time = initObj.End_Entire_Time
      }
      else {
        this.End_Entire_Time = 0.0;
      }
      if (initObj.hasOwnProperty('End_Swing')) {
        this.End_Swing = initObj.End_Swing
      }
      else {
        this.End_Swing = 0.0;
      }
      if (initObj.hasOwnProperty('End_Rise')) {
        this.End_Rise = initObj.End_Rise
      }
      else {
        this.End_Rise = 0.0;
      }
      if (initObj.hasOwnProperty('Test_X')) {
        this.Test_X = initObj.Test_X
      }
      else {
        this.Test_X = 0.0;
      }
      if (initObj.hasOwnProperty('Test_Side')) {
        this.Test_Side = initObj.Test_Side
      }
      else {
        this.Test_Side = 0.0;
      }
      if (initObj.hasOwnProperty('Test_Yaw')) {
        this.Test_Yaw = initObj.Test_Yaw
      }
      else {
        this.Test_Yaw = 0.0;
      }
      if (initObj.hasOwnProperty('Tuning_X')) {
        this.Tuning_X = initObj.Tuning_X
      }
      else {
        this.Tuning_X = 0.0;
      }
      if (initObj.hasOwnProperty('Tuning_Side')) {
        this.Tuning_Side = initObj.Tuning_Side
      }
      else {
        this.Tuning_Side = 0.0;
      }
      if (initObj.hasOwnProperty('Tuning_Yaw')) {
        this.Tuning_Yaw = initObj.Tuning_Yaw
      }
      else {
        this.Tuning_Yaw = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_0')) {
        this.Balance_Value_0 = initObj.Balance_Value_0
      }
      else {
        this.Balance_Value_0 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_1')) {
        this.Balance_Value_1 = initObj.Balance_Value_1
      }
      else {
        this.Balance_Value_1 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_2')) {
        this.Balance_Value_2 = initObj.Balance_Value_2
      }
      else {
        this.Balance_Value_2 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_3')) {
        this.Balance_Value_3 = initObj.Balance_Value_3
      }
      else {
        this.Balance_Value_3 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GP')) {
        this.Balance_Pitch_GP = initObj.Balance_Pitch_GP
      }
      else {
        this.Balance_Pitch_GP = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GI')) {
        this.Balance_Pitch_GI = initObj.Balance_Pitch_GI
      }
      else {
        this.Balance_Pitch_GI = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GD')) {
        this.Balance_Pitch_GD = initObj.Balance_Pitch_GD
      }
      else {
        this.Balance_Pitch_GD = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_ELIMIT')) {
        this.Balance_Pitch_ELIMIT = initObj.Balance_Pitch_ELIMIT
      }
      else {
        this.Balance_Pitch_ELIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_OLIMIT')) {
        this.Balance_Pitch_OLIMIT = initObj.Balance_Pitch_OLIMIT
      }
      else {
        this.Balance_Pitch_OLIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Neg_Target')) {
        this.Balance_Pitch_Neg_Target = initObj.Balance_Pitch_Neg_Target
      }
      else {
        this.Balance_Pitch_Neg_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Pos_Target')) {
        this.Balance_Pitch_Pos_Target = initObj.Balance_Pitch_Pos_Target
      }
      else {
        this.Balance_Pitch_Pos_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GP')) {
        this.Balance_Roll_GP = initObj.Balance_Roll_GP
      }
      else {
        this.Balance_Roll_GP = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GI')) {
        this.Balance_Roll_GI = initObj.Balance_Roll_GI
      }
      else {
        this.Balance_Roll_GI = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GD')) {
        this.Balance_Roll_GD = initObj.Balance_Roll_GD
      }
      else {
        this.Balance_Roll_GD = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_ELIMIT')) {
        this.Balance_Roll_ELIMIT = initObj.Balance_Roll_ELIMIT
      }
      else {
        this.Balance_Roll_ELIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_OLIMIT')) {
        this.Balance_Roll_OLIMIT = initObj.Balance_Roll_OLIMIT
      }
      else {
        this.Balance_Roll_OLIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Neg_Target')) {
        this.Balance_Roll_Neg_Target = initObj.Balance_Roll_Neg_Target
      }
      else {
        this.Balance_Roll_Neg_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Pos_Target')) {
        this.Balance_Roll_Pos_Target = initObj.Balance_Roll_Pos_Target
      }
      else {
        this.Balance_Roll_Pos_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_GP')) {
        this.Balance_Angle_Pitch_GP = initObj.Balance_Angle_Pitch_GP
      }
      else {
        this.Balance_Angle_Pitch_GP = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_GI')) {
        this.Balance_Angle_Pitch_GI = initObj.Balance_Angle_Pitch_GI
      }
      else {
        this.Balance_Angle_Pitch_GI = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_GD')) {
        this.Balance_Angle_Pitch_GD = initObj.Balance_Angle_Pitch_GD
      }
      else {
        this.Balance_Angle_Pitch_GD = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_ELIMIT')) {
        this.Balance_Angle_Pitch_ELIMIT = initObj.Balance_Angle_Pitch_ELIMIT
      }
      else {
        this.Balance_Angle_Pitch_ELIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_OLIMIT')) {
        this.Balance_Angle_Pitch_OLIMIT = initObj.Balance_Angle_Pitch_OLIMIT
      }
      else {
        this.Balance_Angle_Pitch_OLIMIT = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_Neg_Target')) {
        this.Balance_Angle_Pitch_Neg_Target = initObj.Balance_Angle_Pitch_Neg_Target
      }
      else {
        this.Balance_Angle_Pitch_Neg_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_Pos_Target')) {
        this.Balance_Angle_Pitch_Pos_Target = initObj.Balance_Angle_Pitch_Pos_Target
      }
      else {
        this.Balance_Angle_Pitch_Pos_Target = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_4')) {
        this.Balance_Value_4 = initObj.Balance_Value_4
      }
      else {
        this.Balance_Value_4 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Value_5')) {
        this.Balance_Value_5 = initObj.Balance_Value_5
      }
      else {
        this.Balance_Value_5 = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Flag_imu')) {
        this.Balance_Pitch_Flag_imu = initObj.Balance_Pitch_Flag_imu
      }
      else {
        this.Balance_Pitch_Flag_imu = 0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GP_imu')) {
        this.Balance_Pitch_GP_imu = initObj.Balance_Pitch_GP_imu
      }
      else {
        this.Balance_Pitch_GP_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GI_imu')) {
        this.Balance_Pitch_GI_imu = initObj.Balance_Pitch_GI_imu
      }
      else {
        this.Balance_Pitch_GI_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_GD_imu')) {
        this.Balance_Pitch_GD_imu = initObj.Balance_Pitch_GD_imu
      }
      else {
        this.Balance_Pitch_GD_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Neg_Target_imu')) {
        this.Balance_Pitch_Neg_Target_imu = initObj.Balance_Pitch_Neg_Target_imu
      }
      else {
        this.Balance_Pitch_Neg_Target_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Pos_Target_imu')) {
        this.Balance_Pitch_Pos_Target_imu = initObj.Balance_Pitch_Pos_Target_imu
      }
      else {
        this.Balance_Pitch_Pos_Target_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_ELIMIT_imu')) {
        this.Balance_Pitch_ELIMIT_imu = initObj.Balance_Pitch_ELIMIT_imu
      }
      else {
        this.Balance_Pitch_ELIMIT_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_OLIMIT_imu')) {
        this.Balance_Pitch_OLIMIT_imu = initObj.Balance_Pitch_OLIMIT_imu
      }
      else {
        this.Balance_Pitch_OLIMIT_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Flag_imu')) {
        this.Balance_Roll_Flag_imu = initObj.Balance_Roll_Flag_imu
      }
      else {
        this.Balance_Roll_Flag_imu = 0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GP_imu')) {
        this.Balance_Roll_GP_imu = initObj.Balance_Roll_GP_imu
      }
      else {
        this.Balance_Roll_GP_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GI_imu')) {
        this.Balance_Roll_GI_imu = initObj.Balance_Roll_GI_imu
      }
      else {
        this.Balance_Roll_GI_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_GD_imu')) {
        this.Balance_Roll_GD_imu = initObj.Balance_Roll_GD_imu
      }
      else {
        this.Balance_Roll_GD_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Neg_Target_imu')) {
        this.Balance_Roll_Neg_Target_imu = initObj.Balance_Roll_Neg_Target_imu
      }
      else {
        this.Balance_Roll_Neg_Target_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Pos_Target_imu')) {
        this.Balance_Roll_Pos_Target_imu = initObj.Balance_Roll_Pos_Target_imu
      }
      else {
        this.Balance_Roll_Pos_Target_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_ELIMIT_imu')) {
        this.Balance_Roll_ELIMIT_imu = initObj.Balance_Roll_ELIMIT_imu
      }
      else {
        this.Balance_Roll_ELIMIT_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_OLIMIT_imu')) {
        this.Balance_Roll_OLIMIT_imu = initObj.Balance_Roll_OLIMIT_imu
      }
      else {
        this.Balance_Roll_OLIMIT_imu = 0.0;
      }
      if (initObj.hasOwnProperty('Balance_Pitch_Flag')) {
        this.Balance_Pitch_Flag = initObj.Balance_Pitch_Flag
      }
      else {
        this.Balance_Pitch_Flag = 0;
      }
      if (initObj.hasOwnProperty('Balance_Ankle_Pitch_Flag')) {
        this.Balance_Ankle_Pitch_Flag = initObj.Balance_Ankle_Pitch_Flag
      }
      else {
        this.Balance_Ankle_Pitch_Flag = 0;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Flag')) {
        this.Balance_Roll_Flag = initObj.Balance_Roll_Flag
      }
      else {
        this.Balance_Roll_Flag = 0;
      }
      if (initObj.hasOwnProperty('Ratio_Check_Flag')) {
        this.Ratio_Check_Flag = initObj.Ratio_Check_Flag
      }
      else {
        this.Ratio_Check_Flag = 0;
      }
      if (initObj.hasOwnProperty('Center2Leg')) {
        this.Center2Leg = initObj.Center2Leg
      }
      else {
        this.Center2Leg = 0.0;
      }
      if (initObj.hasOwnProperty('Link2Link')) {
        this.Link2Link = initObj.Link2Link
      }
      else {
        this.Link2Link = 0.0;
      }
      if (initObj.hasOwnProperty('Init_Z_Up')) {
        this.Init_Z_Up = initObj.Init_Z_Up
      }
      else {
        this.Init_Z_Up = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_10_Motor')) {
        this.Percentage_of_IK_10_Motor = initObj.Percentage_of_IK_10_Motor
      }
      else {
        this.Percentage_of_IK_10_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_11_Motor')) {
        this.Percentage_of_IK_11_Motor = initObj.Percentage_of_IK_11_Motor
      }
      else {
        this.Percentage_of_IK_11_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_12_Motor')) {
        this.Percentage_of_IK_12_Motor = initObj.Percentage_of_IK_12_Motor
      }
      else {
        this.Percentage_of_IK_12_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_13_Motor')) {
        this.Percentage_of_IK_13_Motor = initObj.Percentage_of_IK_13_Motor
      }
      else {
        this.Percentage_of_IK_13_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_14_Motor')) {
        this.Percentage_of_IK_14_Motor = initObj.Percentage_of_IK_14_Motor
      }
      else {
        this.Percentage_of_IK_14_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_15_Motor')) {
        this.Percentage_of_IK_15_Motor = initObj.Percentage_of_IK_15_Motor
      }
      else {
        this.Percentage_of_IK_15_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_16_Motor')) {
        this.Percentage_of_IK_16_Motor = initObj.Percentage_of_IK_16_Motor
      }
      else {
        this.Percentage_of_IK_16_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_17_Motor')) {
        this.Percentage_of_IK_17_Motor = initObj.Percentage_of_IK_17_Motor
      }
      else {
        this.Percentage_of_IK_17_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_18_Motor')) {
        this.Percentage_of_IK_18_Motor = initObj.Percentage_of_IK_18_Motor
      }
      else {
        this.Percentage_of_IK_18_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_19_Motor')) {
        this.Percentage_of_IK_19_Motor = initObj.Percentage_of_IK_19_Motor
      }
      else {
        this.Percentage_of_IK_19_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_20_Motor')) {
        this.Percentage_of_IK_20_Motor = initObj.Percentage_of_IK_20_Motor
      }
      else {
        this.Percentage_of_IK_20_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('Percentage_of_IK_21_Motor')) {
        this.Percentage_of_IK_21_Motor = initObj.Percentage_of_IK_21_Motor
      }
      else {
        this.Percentage_of_IK_21_Motor = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_XR')) {
        this.First_Pos_XR = initObj.First_Pos_XR
      }
      else {
        this.First_Pos_XR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_XR')) {
        this.First_Neg_XR = initObj.First_Neg_XR
      }
      else {
        this.First_Neg_XR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_SideR')) {
        this.First_Pos_SideR = initObj.First_Pos_SideR
      }
      else {
        this.First_Pos_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_SideR')) {
        this.First_Neg_SideR = initObj.First_Neg_SideR
      }
      else {
        this.First_Neg_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_YawR')) {
        this.First_Pos_YawR = initObj.First_Pos_YawR
      }
      else {
        this.First_Pos_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_YawR')) {
        this.First_Neg_YawR = initObj.First_Neg_YawR
      }
      else {
        this.First_Neg_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_XL')) {
        this.First_Pos_XL = initObj.First_Pos_XL
      }
      else {
        this.First_Pos_XL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_XL')) {
        this.First_Neg_XL = initObj.First_Neg_XL
      }
      else {
        this.First_Neg_XL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_SideL')) {
        this.First_Pos_SideL = initObj.First_Pos_SideL
      }
      else {
        this.First_Pos_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_SideL')) {
        this.First_Neg_SideL = initObj.First_Neg_SideL
      }
      else {
        this.First_Neg_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_YawL')) {
        this.First_Pos_YawL = initObj.First_Pos_YawL
      }
      else {
        this.First_Pos_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_YawL')) {
        this.First_Neg_YawL = initObj.First_Neg_YawL
      }
      else {
        this.First_Neg_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_SideR_SwingMinus')) {
        this.First_Pos_SideR_SwingMinus = initObj.First_Pos_SideR_SwingMinus
      }
      else {
        this.First_Pos_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_SideR_SwingMinus')) {
        this.First_Neg_SideR_SwingMinus = initObj.First_Neg_SideR_SwingMinus
      }
      else {
        this.First_Neg_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('First_Pos_SideL_SwingMinus')) {
        this.First_Pos_SideL_SwingMinus = initObj.First_Pos_SideL_SwingMinus
      }
      else {
        this.First_Pos_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('First_Neg_SideL_SwingMinus')) {
        this.First_Neg_SideL_SwingMinus = initObj.First_Neg_SideL_SwingMinus
      }
      else {
        this.First_Neg_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('First_min')) {
        this.First_min = initObj.First_min
      }
      else {
        this.First_min = 0;
      }
      if (initObj.hasOwnProperty('First_max')) {
        this.First_max = initObj.First_max
      }
      else {
        this.First_max = 0;
      }
      if (initObj.hasOwnProperty('Second_Pos_XR')) {
        this.Second_Pos_XR = initObj.Second_Pos_XR
      }
      else {
        this.Second_Pos_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_XR')) {
        this.Second_Neg_XR = initObj.Second_Neg_XR
      }
      else {
        this.Second_Neg_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_SideR')) {
        this.Second_Pos_SideR = initObj.Second_Pos_SideR
      }
      else {
        this.Second_Pos_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_SideR')) {
        this.Second_Neg_SideR = initObj.Second_Neg_SideR
      }
      else {
        this.Second_Neg_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_YawR')) {
        this.Second_Pos_YawR = initObj.Second_Pos_YawR
      }
      else {
        this.Second_Pos_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_YawR')) {
        this.Second_Neg_YawR = initObj.Second_Neg_YawR
      }
      else {
        this.Second_Neg_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_XL')) {
        this.Second_Pos_XL = initObj.Second_Pos_XL
      }
      else {
        this.Second_Pos_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_XL')) {
        this.Second_Neg_XL = initObj.Second_Neg_XL
      }
      else {
        this.Second_Neg_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_SideL')) {
        this.Second_Pos_SideL = initObj.Second_Pos_SideL
      }
      else {
        this.Second_Pos_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_SideL')) {
        this.Second_Neg_SideL = initObj.Second_Neg_SideL
      }
      else {
        this.Second_Neg_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_YawL')) {
        this.Second_Pos_YawL = initObj.Second_Pos_YawL
      }
      else {
        this.Second_Pos_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_YawL')) {
        this.Second_Neg_YawL = initObj.Second_Neg_YawL
      }
      else {
        this.Second_Neg_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_SideR_SwingMinus')) {
        this.Second_Pos_SideR_SwingMinus = initObj.Second_Pos_SideR_SwingMinus
      }
      else {
        this.Second_Pos_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_SideR_SwingMinus')) {
        this.Second_Neg_SideR_SwingMinus = initObj.Second_Neg_SideR_SwingMinus
      }
      else {
        this.Second_Neg_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Pos_SideL_SwingMinus')) {
        this.Second_Pos_SideL_SwingMinus = initObj.Second_Pos_SideL_SwingMinus
      }
      else {
        this.Second_Pos_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Second_Neg_SideL_SwingMinus')) {
        this.Second_Neg_SideL_SwingMinus = initObj.Second_Neg_SideL_SwingMinus
      }
      else {
        this.Second_Neg_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Second_min')) {
        this.Second_min = initObj.Second_min
      }
      else {
        this.Second_min = 0;
      }
      if (initObj.hasOwnProperty('Second_max')) {
        this.Second_max = initObj.Second_max
      }
      else {
        this.Second_max = 0;
      }
      if (initObj.hasOwnProperty('Third_Pos_XR')) {
        this.Third_Pos_XR = initObj.Third_Pos_XR
      }
      else {
        this.Third_Pos_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_XR')) {
        this.Third_Neg_XR = initObj.Third_Neg_XR
      }
      else {
        this.Third_Neg_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_SideR')) {
        this.Third_Pos_SideR = initObj.Third_Pos_SideR
      }
      else {
        this.Third_Pos_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_SideR')) {
        this.Third_Neg_SideR = initObj.Third_Neg_SideR
      }
      else {
        this.Third_Neg_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_YawR')) {
        this.Third_Pos_YawR = initObj.Third_Pos_YawR
      }
      else {
        this.Third_Pos_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_YawR')) {
        this.Third_Neg_YawR = initObj.Third_Neg_YawR
      }
      else {
        this.Third_Neg_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_XL')) {
        this.Third_Pos_XL = initObj.Third_Pos_XL
      }
      else {
        this.Third_Pos_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_XL')) {
        this.Third_Neg_XL = initObj.Third_Neg_XL
      }
      else {
        this.Third_Neg_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_SideL')) {
        this.Third_Pos_SideL = initObj.Third_Pos_SideL
      }
      else {
        this.Third_Pos_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_SideL')) {
        this.Third_Neg_SideL = initObj.Third_Neg_SideL
      }
      else {
        this.Third_Neg_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_YawL')) {
        this.Third_Pos_YawL = initObj.Third_Pos_YawL
      }
      else {
        this.Third_Pos_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_YawL')) {
        this.Third_Neg_YawL = initObj.Third_Neg_YawL
      }
      else {
        this.Third_Neg_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_SideR_SwingMinus')) {
        this.Third_Pos_SideR_SwingMinus = initObj.Third_Pos_SideR_SwingMinus
      }
      else {
        this.Third_Pos_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_SideR_SwingMinus')) {
        this.Third_Neg_SideR_SwingMinus = initObj.Third_Neg_SideR_SwingMinus
      }
      else {
        this.Third_Neg_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Pos_SideL_SwingMinus')) {
        this.Third_Pos_SideL_SwingMinus = initObj.Third_Pos_SideL_SwingMinus
      }
      else {
        this.Third_Pos_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Third_Neg_SideL_SwingMinus')) {
        this.Third_Neg_SideL_SwingMinus = initObj.Third_Neg_SideL_SwingMinus
      }
      else {
        this.Third_Neg_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Third_min')) {
        this.Third_min = initObj.Third_min
      }
      else {
        this.Third_min = 0;
      }
      if (initObj.hasOwnProperty('Third_max')) {
        this.Third_max = initObj.Third_max
      }
      else {
        this.Third_max = 0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_XR')) {
        this.Fourth_Pos_XR = initObj.Fourth_Pos_XR
      }
      else {
        this.Fourth_Pos_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_XR')) {
        this.Fourth_Neg_XR = initObj.Fourth_Neg_XR
      }
      else {
        this.Fourth_Neg_XR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_SideR')) {
        this.Fourth_Pos_SideR = initObj.Fourth_Pos_SideR
      }
      else {
        this.Fourth_Pos_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_SideR')) {
        this.Fourth_Neg_SideR = initObj.Fourth_Neg_SideR
      }
      else {
        this.Fourth_Neg_SideR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_YawR')) {
        this.Fourth_Pos_YawR = initObj.Fourth_Pos_YawR
      }
      else {
        this.Fourth_Pos_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_YawR')) {
        this.Fourth_Neg_YawR = initObj.Fourth_Neg_YawR
      }
      else {
        this.Fourth_Neg_YawR = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_XL')) {
        this.Fourth_Pos_XL = initObj.Fourth_Pos_XL
      }
      else {
        this.Fourth_Pos_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_XL')) {
        this.Fourth_Neg_XL = initObj.Fourth_Neg_XL
      }
      else {
        this.Fourth_Neg_XL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_SideL')) {
        this.Fourth_Pos_SideL = initObj.Fourth_Pos_SideL
      }
      else {
        this.Fourth_Pos_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_SideL')) {
        this.Fourth_Neg_SideL = initObj.Fourth_Neg_SideL
      }
      else {
        this.Fourth_Neg_SideL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_YawL')) {
        this.Fourth_Pos_YawL = initObj.Fourth_Pos_YawL
      }
      else {
        this.Fourth_Pos_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_YawL')) {
        this.Fourth_Neg_YawL = initObj.Fourth_Neg_YawL
      }
      else {
        this.Fourth_Neg_YawL = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_SideR_SwingMinus')) {
        this.Fourth_Pos_SideR_SwingMinus = initObj.Fourth_Pos_SideR_SwingMinus
      }
      else {
        this.Fourth_Pos_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_SideR_SwingMinus')) {
        this.Fourth_Neg_SideR_SwingMinus = initObj.Fourth_Neg_SideR_SwingMinus
      }
      else {
        this.Fourth_Neg_SideR_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Pos_SideL_SwingMinus')) {
        this.Fourth_Pos_SideL_SwingMinus = initObj.Fourth_Pos_SideL_SwingMinus
      }
      else {
        this.Fourth_Pos_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_Neg_SideL_SwingMinus')) {
        this.Fourth_Neg_SideL_SwingMinus = initObj.Fourth_Neg_SideL_SwingMinus
      }
      else {
        this.Fourth_Neg_SideL_SwingMinus = 0.0;
      }
      if (initObj.hasOwnProperty('Fourth_min')) {
        this.Fourth_min = initObj.Fourth_min
      }
      else {
        this.Fourth_min = 0;
      }
      if (initObj.hasOwnProperty('Fourth_max')) {
        this.Fourth_max = initObj.Fourth_max
      }
      else {
        this.Fourth_max = 0;
      }
      if (initObj.hasOwnProperty('Landing_Time_Control_flag')) {
        this.Landing_Time_Control_flag = initObj.Landing_Time_Control_flag
      }
      else {
        this.Landing_Time_Control_flag = 0;
      }
      if (initObj.hasOwnProperty('Control_System_flag')) {
        this.Control_System_flag = initObj.Control_System_flag
      }
      else {
        this.Control_System_flag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type tune2walk
    // Serialize message field [IK_Flag]
    bufferOffset = _serializer.bool(obj.IK_Flag, buffer, bufferOffset);
    // Serialize message field [Entire_Time]
    bufferOffset = _serializer.float64(obj.Entire_Time, buffer, bufferOffset);
    // Serialize message field [Frequency]
    bufferOffset = _serializer.float64(obj.Frequency, buffer, bufferOffset);
    // Serialize message field [Default_X_Right]
    bufferOffset = _serializer.float64(obj.Default_X_Right, buffer, bufferOffset);
    // Serialize message field [Default_X_Left]
    bufferOffset = _serializer.float64(obj.Default_X_Left, buffer, bufferOffset);
    // Serialize message field [Default_Y_Right]
    bufferOffset = _serializer.float64(obj.Default_Y_Right, buffer, bufferOffset);
    // Serialize message field [Default_Y_Left]
    bufferOffset = _serializer.float64(obj.Default_Y_Left, buffer, bufferOffset);
    // Serialize message field [Default_Z_Right]
    bufferOffset = _serializer.float64(obj.Default_Z_Right, buffer, bufferOffset);
    // Serialize message field [Default_Z_Left]
    bufferOffset = _serializer.float64(obj.Default_Z_Left, buffer, bufferOffset);
    // Serialize message field [Offset_10_Motor]
    bufferOffset = _serializer.float64(obj.Offset_10_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_11_Motor]
    bufferOffset = _serializer.float64(obj.Offset_11_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_12_Motor]
    bufferOffset = _serializer.float64(obj.Offset_12_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_13_Motor]
    bufferOffset = _serializer.float64(obj.Offset_13_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_14_Motor]
    bufferOffset = _serializer.float64(obj.Offset_14_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_15_Motor]
    bufferOffset = _serializer.float64(obj.Offset_15_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_16_Motor]
    bufferOffset = _serializer.float64(obj.Offset_16_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_17_Motor]
    bufferOffset = _serializer.float64(obj.Offset_17_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_18_Motor]
    bufferOffset = _serializer.float64(obj.Offset_18_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_19_Motor]
    bufferOffset = _serializer.float64(obj.Offset_19_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_20_Motor]
    bufferOffset = _serializer.float64(obj.Offset_20_Motor, buffer, bufferOffset);
    // Serialize message field [Offset_21_Motor]
    bufferOffset = _serializer.float64(obj.Offset_21_Motor, buffer, bufferOffset);
    // Serialize message field [Swing_Right_Leg]
    bufferOffset = _serializer.float64(obj.Swing_Right_Leg, buffer, bufferOffset);
    // Serialize message field [Swing_Left_Leg]
    bufferOffset = _serializer.float64(obj.Swing_Left_Leg, buffer, bufferOffset);
    // Serialize message field [Swing_Right_Shoulder]
    bufferOffset = _serializer.float64(obj.Swing_Right_Shoulder, buffer, bufferOffset);
    // Serialize message field [Swing_Left_Shoulder]
    bufferOffset = _serializer.float64(obj.Swing_Left_Shoulder, buffer, bufferOffset);
    // Serialize message field [Rise_Right_Leg]
    bufferOffset = _serializer.float64(obj.Rise_Right_Leg, buffer, bufferOffset);
    // Serialize message field [Rise_Left_Leg]
    bufferOffset = _serializer.float64(obj.Rise_Left_Leg, buffer, bufferOffset);
    // Serialize message field [Start_Entire_Time]
    bufferOffset = _serializer.float64(obj.Start_Entire_Time, buffer, bufferOffset);
    // Serialize message field [Start_Swing]
    bufferOffset = _serializer.float64(obj.Start_Swing, buffer, bufferOffset);
    // Serialize message field [Start_Rise]
    bufferOffset = _serializer.float64(obj.Start_Rise, buffer, bufferOffset);
    // Serialize message field [End_Entire_Time]
    bufferOffset = _serializer.float64(obj.End_Entire_Time, buffer, bufferOffset);
    // Serialize message field [End_Swing]
    bufferOffset = _serializer.float64(obj.End_Swing, buffer, bufferOffset);
    // Serialize message field [End_Rise]
    bufferOffset = _serializer.float64(obj.End_Rise, buffer, bufferOffset);
    // Serialize message field [Test_X]
    bufferOffset = _serializer.float64(obj.Test_X, buffer, bufferOffset);
    // Serialize message field [Test_Side]
    bufferOffset = _serializer.float64(obj.Test_Side, buffer, bufferOffset);
    // Serialize message field [Test_Yaw]
    bufferOffset = _serializer.float64(obj.Test_Yaw, buffer, bufferOffset);
    // Serialize message field [Tuning_X]
    bufferOffset = _serializer.float64(obj.Tuning_X, buffer, bufferOffset);
    // Serialize message field [Tuning_Side]
    bufferOffset = _serializer.float64(obj.Tuning_Side, buffer, bufferOffset);
    // Serialize message field [Tuning_Yaw]
    bufferOffset = _serializer.float64(obj.Tuning_Yaw, buffer, bufferOffset);
    // Serialize message field [Balance_Value_0]
    bufferOffset = _serializer.float64(obj.Balance_Value_0, buffer, bufferOffset);
    // Serialize message field [Balance_Value_1]
    bufferOffset = _serializer.float64(obj.Balance_Value_1, buffer, bufferOffset);
    // Serialize message field [Balance_Value_2]
    bufferOffset = _serializer.float64(obj.Balance_Value_2, buffer, bufferOffset);
    // Serialize message field [Balance_Value_3]
    bufferOffset = _serializer.float64(obj.Balance_Value_3, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GP]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GP, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GI]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GI, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GD]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GD, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_ELIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_ELIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_OLIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_OLIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Neg_Target]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_Neg_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Pos_Target]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_Pos_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GP]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GP, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GI]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GI, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GD]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GD, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_ELIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Roll_ELIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_OLIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Roll_OLIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Neg_Target]
    bufferOffset = _serializer.float64(obj.Balance_Roll_Neg_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Pos_Target]
    bufferOffset = _serializer.float64(obj.Balance_Roll_Pos_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_GP]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_GP, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_GI]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_GI, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_GD]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_GD, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_ELIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_ELIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_OLIMIT]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_OLIMIT, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_Neg_Target]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_Neg_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_Pos_Target]
    bufferOffset = _serializer.float64(obj.Balance_Angle_Pitch_Pos_Target, buffer, bufferOffset);
    // Serialize message field [Balance_Value_4]
    bufferOffset = _serializer.float64(obj.Balance_Value_4, buffer, bufferOffset);
    // Serialize message field [Balance_Value_5]
    bufferOffset = _serializer.float64(obj.Balance_Value_5, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Flag_imu]
    bufferOffset = _serializer.int64(obj.Balance_Pitch_Flag_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GP_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GP_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GI_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GI_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_GD_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_GD_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Neg_Target_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_Neg_Target_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Pos_Target_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_Pos_Target_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_ELIMIT_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_ELIMIT_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_OLIMIT_imu]
    bufferOffset = _serializer.float64(obj.Balance_Pitch_OLIMIT_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Flag_imu]
    bufferOffset = _serializer.int64(obj.Balance_Roll_Flag_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GP_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GP_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GI_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GI_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_GD_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_GD_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Neg_Target_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_Neg_Target_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Pos_Target_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_Pos_Target_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_ELIMIT_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_ELIMIT_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_OLIMIT_imu]
    bufferOffset = _serializer.float64(obj.Balance_Roll_OLIMIT_imu, buffer, bufferOffset);
    // Serialize message field [Balance_Pitch_Flag]
    bufferOffset = _serializer.int64(obj.Balance_Pitch_Flag, buffer, bufferOffset);
    // Serialize message field [Balance_Ankle_Pitch_Flag]
    bufferOffset = _serializer.int64(obj.Balance_Ankle_Pitch_Flag, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Flag]
    bufferOffset = _serializer.int64(obj.Balance_Roll_Flag, buffer, bufferOffset);
    // Serialize message field [Ratio_Check_Flag]
    bufferOffset = _serializer.int64(obj.Ratio_Check_Flag, buffer, bufferOffset);
    // Serialize message field [Center2Leg]
    bufferOffset = _serializer.float64(obj.Center2Leg, buffer, bufferOffset);
    // Serialize message field [Link2Link]
    bufferOffset = _serializer.float64(obj.Link2Link, buffer, bufferOffset);
    // Serialize message field [Init_Z_Up]
    bufferOffset = _serializer.float64(obj.Init_Z_Up, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_10_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_10_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_11_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_11_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_12_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_12_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_13_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_13_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_14_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_14_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_15_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_15_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_16_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_16_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_17_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_17_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_18_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_18_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_19_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_19_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_20_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_20_Motor, buffer, bufferOffset);
    // Serialize message field [Percentage_of_IK_21_Motor]
    bufferOffset = _serializer.float64(obj.Percentage_of_IK_21_Motor, buffer, bufferOffset);
    // Serialize message field [First_Pos_XR]
    bufferOffset = _serializer.float64(obj.First_Pos_XR, buffer, bufferOffset);
    // Serialize message field [First_Neg_XR]
    bufferOffset = _serializer.float64(obj.First_Neg_XR, buffer, bufferOffset);
    // Serialize message field [First_Pos_SideR]
    bufferOffset = _serializer.float64(obj.First_Pos_SideR, buffer, bufferOffset);
    // Serialize message field [First_Neg_SideR]
    bufferOffset = _serializer.float64(obj.First_Neg_SideR, buffer, bufferOffset);
    // Serialize message field [First_Pos_YawR]
    bufferOffset = _serializer.float64(obj.First_Pos_YawR, buffer, bufferOffset);
    // Serialize message field [First_Neg_YawR]
    bufferOffset = _serializer.float64(obj.First_Neg_YawR, buffer, bufferOffset);
    // Serialize message field [First_Pos_XL]
    bufferOffset = _serializer.float64(obj.First_Pos_XL, buffer, bufferOffset);
    // Serialize message field [First_Neg_XL]
    bufferOffset = _serializer.float64(obj.First_Neg_XL, buffer, bufferOffset);
    // Serialize message field [First_Pos_SideL]
    bufferOffset = _serializer.float64(obj.First_Pos_SideL, buffer, bufferOffset);
    // Serialize message field [First_Neg_SideL]
    bufferOffset = _serializer.float64(obj.First_Neg_SideL, buffer, bufferOffset);
    // Serialize message field [First_Pos_YawL]
    bufferOffset = _serializer.float64(obj.First_Pos_YawL, buffer, bufferOffset);
    // Serialize message field [First_Neg_YawL]
    bufferOffset = _serializer.float64(obj.First_Neg_YawL, buffer, bufferOffset);
    // Serialize message field [First_Pos_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.First_Pos_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [First_Neg_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.First_Neg_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [First_Pos_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.First_Pos_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [First_Neg_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.First_Neg_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [First_min]
    bufferOffset = _serializer.int64(obj.First_min, buffer, bufferOffset);
    // Serialize message field [First_max]
    bufferOffset = _serializer.int64(obj.First_max, buffer, bufferOffset);
    // Serialize message field [Second_Pos_XR]
    bufferOffset = _serializer.float64(obj.Second_Pos_XR, buffer, bufferOffset);
    // Serialize message field [Second_Neg_XR]
    bufferOffset = _serializer.float64(obj.Second_Neg_XR, buffer, bufferOffset);
    // Serialize message field [Second_Pos_SideR]
    bufferOffset = _serializer.float64(obj.Second_Pos_SideR, buffer, bufferOffset);
    // Serialize message field [Second_Neg_SideR]
    bufferOffset = _serializer.float64(obj.Second_Neg_SideR, buffer, bufferOffset);
    // Serialize message field [Second_Pos_YawR]
    bufferOffset = _serializer.float64(obj.Second_Pos_YawR, buffer, bufferOffset);
    // Serialize message field [Second_Neg_YawR]
    bufferOffset = _serializer.float64(obj.Second_Neg_YawR, buffer, bufferOffset);
    // Serialize message field [Second_Pos_XL]
    bufferOffset = _serializer.float64(obj.Second_Pos_XL, buffer, bufferOffset);
    // Serialize message field [Second_Neg_XL]
    bufferOffset = _serializer.float64(obj.Second_Neg_XL, buffer, bufferOffset);
    // Serialize message field [Second_Pos_SideL]
    bufferOffset = _serializer.float64(obj.Second_Pos_SideL, buffer, bufferOffset);
    // Serialize message field [Second_Neg_SideL]
    bufferOffset = _serializer.float64(obj.Second_Neg_SideL, buffer, bufferOffset);
    // Serialize message field [Second_Pos_YawL]
    bufferOffset = _serializer.float64(obj.Second_Pos_YawL, buffer, bufferOffset);
    // Serialize message field [Second_Neg_YawL]
    bufferOffset = _serializer.float64(obj.Second_Neg_YawL, buffer, bufferOffset);
    // Serialize message field [Second_Pos_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Second_Pos_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Second_Neg_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Second_Neg_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Second_Pos_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Second_Pos_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Second_Neg_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Second_Neg_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Second_min]
    bufferOffset = _serializer.int64(obj.Second_min, buffer, bufferOffset);
    // Serialize message field [Second_max]
    bufferOffset = _serializer.int64(obj.Second_max, buffer, bufferOffset);
    // Serialize message field [Third_Pos_XR]
    bufferOffset = _serializer.float64(obj.Third_Pos_XR, buffer, bufferOffset);
    // Serialize message field [Third_Neg_XR]
    bufferOffset = _serializer.float64(obj.Third_Neg_XR, buffer, bufferOffset);
    // Serialize message field [Third_Pos_SideR]
    bufferOffset = _serializer.float64(obj.Third_Pos_SideR, buffer, bufferOffset);
    // Serialize message field [Third_Neg_SideR]
    bufferOffset = _serializer.float64(obj.Third_Neg_SideR, buffer, bufferOffset);
    // Serialize message field [Third_Pos_YawR]
    bufferOffset = _serializer.float64(obj.Third_Pos_YawR, buffer, bufferOffset);
    // Serialize message field [Third_Neg_YawR]
    bufferOffset = _serializer.float64(obj.Third_Neg_YawR, buffer, bufferOffset);
    // Serialize message field [Third_Pos_XL]
    bufferOffset = _serializer.float64(obj.Third_Pos_XL, buffer, bufferOffset);
    // Serialize message field [Third_Neg_XL]
    bufferOffset = _serializer.float64(obj.Third_Neg_XL, buffer, bufferOffset);
    // Serialize message field [Third_Pos_SideL]
    bufferOffset = _serializer.float64(obj.Third_Pos_SideL, buffer, bufferOffset);
    // Serialize message field [Third_Neg_SideL]
    bufferOffset = _serializer.float64(obj.Third_Neg_SideL, buffer, bufferOffset);
    // Serialize message field [Third_Pos_YawL]
    bufferOffset = _serializer.float64(obj.Third_Pos_YawL, buffer, bufferOffset);
    // Serialize message field [Third_Neg_YawL]
    bufferOffset = _serializer.float64(obj.Third_Neg_YawL, buffer, bufferOffset);
    // Serialize message field [Third_Pos_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Third_Pos_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Third_Neg_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Third_Neg_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Third_Pos_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Third_Pos_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Third_Neg_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Third_Neg_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Third_min]
    bufferOffset = _serializer.int64(obj.Third_min, buffer, bufferOffset);
    // Serialize message field [Third_max]
    bufferOffset = _serializer.int64(obj.Third_max, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_XR]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_XR, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_XR]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_XR, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_SideR]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_SideR, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_SideR]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_SideR, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_YawR]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_YawR, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_YawR]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_YawR, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_XL]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_XL, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_XL]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_XL, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_SideL]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_SideL, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_SideL]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_SideL, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_YawL]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_YawL, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_YawL]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_YawL, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_SideR_SwingMinus]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_SideR_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Fourth_Pos_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Fourth_Pos_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Fourth_Neg_SideL_SwingMinus]
    bufferOffset = _serializer.float64(obj.Fourth_Neg_SideL_SwingMinus, buffer, bufferOffset);
    // Serialize message field [Fourth_min]
    bufferOffset = _serializer.int64(obj.Fourth_min, buffer, bufferOffset);
    // Serialize message field [Fourth_max]
    bufferOffset = _serializer.int64(obj.Fourth_max, buffer, bufferOffset);
    // Serialize message field [Landing_Time_Control_flag]
    bufferOffset = _serializer.int64(obj.Landing_Time_Control_flag, buffer, bufferOffset);
    // Serialize message field [Control_System_flag]
    bufferOffset = _serializer.int64(obj.Control_System_flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type tune2walk
    let len;
    let data = new tune2walk(null);
    // Deserialize message field [IK_Flag]
    data.IK_Flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Entire_Time]
    data.Entire_Time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Frequency]
    data.Frequency = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_X_Right]
    data.Default_X_Right = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_X_Left]
    data.Default_X_Left = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_Y_Right]
    data.Default_Y_Right = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_Y_Left]
    data.Default_Y_Left = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_Z_Right]
    data.Default_Z_Right = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Default_Z_Left]
    data.Default_Z_Left = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_10_Motor]
    data.Offset_10_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_11_Motor]
    data.Offset_11_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_12_Motor]
    data.Offset_12_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_13_Motor]
    data.Offset_13_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_14_Motor]
    data.Offset_14_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_15_Motor]
    data.Offset_15_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_16_Motor]
    data.Offset_16_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_17_Motor]
    data.Offset_17_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_18_Motor]
    data.Offset_18_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_19_Motor]
    data.Offset_19_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_20_Motor]
    data.Offset_20_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Offset_21_Motor]
    data.Offset_21_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Right_Leg]
    data.Swing_Right_Leg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Left_Leg]
    data.Swing_Left_Leg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Right_Shoulder]
    data.Swing_Right_Shoulder = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Left_Shoulder]
    data.Swing_Left_Shoulder = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Rise_Right_Leg]
    data.Rise_Right_Leg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Rise_Left_Leg]
    data.Rise_Left_Leg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Start_Entire_Time]
    data.Start_Entire_Time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Start_Swing]
    data.Start_Swing = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Start_Rise]
    data.Start_Rise = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [End_Entire_Time]
    data.End_Entire_Time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [End_Swing]
    data.End_Swing = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [End_Rise]
    data.End_Rise = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Test_X]
    data.Test_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Test_Side]
    data.Test_Side = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Test_Yaw]
    data.Test_Yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Tuning_X]
    data.Tuning_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Tuning_Side]
    data.Tuning_Side = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Tuning_Yaw]
    data.Tuning_Yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_0]
    data.Balance_Value_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_1]
    data.Balance_Value_1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_2]
    data.Balance_Value_2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_3]
    data.Balance_Value_3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GP]
    data.Balance_Pitch_GP = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GI]
    data.Balance_Pitch_GI = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GD]
    data.Balance_Pitch_GD = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_ELIMIT]
    data.Balance_Pitch_ELIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_OLIMIT]
    data.Balance_Pitch_OLIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Neg_Target]
    data.Balance_Pitch_Neg_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Pos_Target]
    data.Balance_Pitch_Pos_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GP]
    data.Balance_Roll_GP = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GI]
    data.Balance_Roll_GI = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GD]
    data.Balance_Roll_GD = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_ELIMIT]
    data.Balance_Roll_ELIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_OLIMIT]
    data.Balance_Roll_OLIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Neg_Target]
    data.Balance_Roll_Neg_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Pos_Target]
    data.Balance_Roll_Pos_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_GP]
    data.Balance_Angle_Pitch_GP = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_GI]
    data.Balance_Angle_Pitch_GI = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_GD]
    data.Balance_Angle_Pitch_GD = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_ELIMIT]
    data.Balance_Angle_Pitch_ELIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_OLIMIT]
    data.Balance_Angle_Pitch_OLIMIT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_Neg_Target]
    data.Balance_Angle_Pitch_Neg_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_Pos_Target]
    data.Balance_Angle_Pitch_Pos_Target = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_4]
    data.Balance_Value_4 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Value_5]
    data.Balance_Value_5 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Flag_imu]
    data.Balance_Pitch_Flag_imu = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GP_imu]
    data.Balance_Pitch_GP_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GI_imu]
    data.Balance_Pitch_GI_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_GD_imu]
    data.Balance_Pitch_GD_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Neg_Target_imu]
    data.Balance_Pitch_Neg_Target_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Pos_Target_imu]
    data.Balance_Pitch_Pos_Target_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_ELIMIT_imu]
    data.Balance_Pitch_ELIMIT_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_OLIMIT_imu]
    data.Balance_Pitch_OLIMIT_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Flag_imu]
    data.Balance_Roll_Flag_imu = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GP_imu]
    data.Balance_Roll_GP_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GI_imu]
    data.Balance_Roll_GI_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_GD_imu]
    data.Balance_Roll_GD_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Neg_Target_imu]
    data.Balance_Roll_Neg_Target_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Pos_Target_imu]
    data.Balance_Roll_Pos_Target_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_ELIMIT_imu]
    data.Balance_Roll_ELIMIT_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_OLIMIT_imu]
    data.Balance_Roll_OLIMIT_imu = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Balance_Pitch_Flag]
    data.Balance_Pitch_Flag = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Balance_Ankle_Pitch_Flag]
    data.Balance_Ankle_Pitch_Flag = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Flag]
    data.Balance_Roll_Flag = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Ratio_Check_Flag]
    data.Ratio_Check_Flag = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Center2Leg]
    data.Center2Leg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Link2Link]
    data.Link2Link = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Init_Z_Up]
    data.Init_Z_Up = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_10_Motor]
    data.Percentage_of_IK_10_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_11_Motor]
    data.Percentage_of_IK_11_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_12_Motor]
    data.Percentage_of_IK_12_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_13_Motor]
    data.Percentage_of_IK_13_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_14_Motor]
    data.Percentage_of_IK_14_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_15_Motor]
    data.Percentage_of_IK_15_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_16_Motor]
    data.Percentage_of_IK_16_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_17_Motor]
    data.Percentage_of_IK_17_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_18_Motor]
    data.Percentage_of_IK_18_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_19_Motor]
    data.Percentage_of_IK_19_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_20_Motor]
    data.Percentage_of_IK_20_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Percentage_of_IK_21_Motor]
    data.Percentage_of_IK_21_Motor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_XR]
    data.First_Pos_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_XR]
    data.First_Neg_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_SideR]
    data.First_Pos_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_SideR]
    data.First_Neg_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_YawR]
    data.First_Pos_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_YawR]
    data.First_Neg_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_XL]
    data.First_Pos_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_XL]
    data.First_Neg_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_SideL]
    data.First_Pos_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_SideL]
    data.First_Neg_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_YawL]
    data.First_Pos_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_YawL]
    data.First_Neg_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_SideR_SwingMinus]
    data.First_Pos_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_SideR_SwingMinus]
    data.First_Neg_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Pos_SideL_SwingMinus]
    data.First_Pos_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_Neg_SideL_SwingMinus]
    data.First_Neg_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [First_min]
    data.First_min = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [First_max]
    data.First_max = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_XR]
    data.Second_Pos_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_XR]
    data.Second_Neg_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_SideR]
    data.Second_Pos_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_SideR]
    data.Second_Neg_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_YawR]
    data.Second_Pos_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_YawR]
    data.Second_Neg_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_XL]
    data.Second_Pos_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_XL]
    data.Second_Neg_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_SideL]
    data.Second_Pos_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_SideL]
    data.Second_Neg_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_YawL]
    data.Second_Pos_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_YawL]
    data.Second_Neg_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_SideR_SwingMinus]
    data.Second_Pos_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_SideR_SwingMinus]
    data.Second_Neg_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Pos_SideL_SwingMinus]
    data.Second_Pos_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_Neg_SideL_SwingMinus]
    data.Second_Neg_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Second_min]
    data.Second_min = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Second_max]
    data.Second_max = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_XR]
    data.Third_Pos_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_XR]
    data.Third_Neg_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_SideR]
    data.Third_Pos_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_SideR]
    data.Third_Neg_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_YawR]
    data.Third_Pos_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_YawR]
    data.Third_Neg_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_XL]
    data.Third_Pos_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_XL]
    data.Third_Neg_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_SideL]
    data.Third_Pos_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_SideL]
    data.Third_Neg_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_YawL]
    data.Third_Pos_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_YawL]
    data.Third_Neg_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_SideR_SwingMinus]
    data.Third_Pos_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_SideR_SwingMinus]
    data.Third_Neg_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Pos_SideL_SwingMinus]
    data.Third_Pos_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_Neg_SideL_SwingMinus]
    data.Third_Neg_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Third_min]
    data.Third_min = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Third_max]
    data.Third_max = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_XR]
    data.Fourth_Pos_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_XR]
    data.Fourth_Neg_XR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_SideR]
    data.Fourth_Pos_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_SideR]
    data.Fourth_Neg_SideR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_YawR]
    data.Fourth_Pos_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_YawR]
    data.Fourth_Neg_YawR = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_XL]
    data.Fourth_Pos_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_XL]
    data.Fourth_Neg_XL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_SideL]
    data.Fourth_Pos_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_SideL]
    data.Fourth_Neg_SideL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_YawL]
    data.Fourth_Pos_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_YawL]
    data.Fourth_Neg_YawL = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_SideR_SwingMinus]
    data.Fourth_Pos_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_SideR_SwingMinus]
    data.Fourth_Neg_SideR_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Pos_SideL_SwingMinus]
    data.Fourth_Pos_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_Neg_SideL_SwingMinus]
    data.Fourth_Neg_SideL_SwingMinus = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Fourth_min]
    data.Fourth_min = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Fourth_max]
    data.Fourth_max = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Landing_Time_Control_flag]
    data.Landing_Time_Control_flag = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Control_System_flag]
    data.Control_System_flag = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1393;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/tune2walk';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '75d5cf0d1f6070c84882cf68f96d4a52';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool IK_Flag
    float64 Entire_Time
    float64 Frequency
    float64 Default_X_Right
    float64 Default_X_Left
    float64 Default_Y_Right
    float64 Default_Y_Left
    float64 Default_Z_Right
    float64 Default_Z_Left
    float64 Offset_10_Motor
    float64 Offset_11_Motor
    float64 Offset_12_Motor
    float64 Offset_13_Motor
    float64 Offset_14_Motor
    float64 Offset_15_Motor
    float64 Offset_16_Motor
    float64 Offset_17_Motor
    float64 Offset_18_Motor
    float64 Offset_19_Motor
    float64 Offset_20_Motor
    float64 Offset_21_Motor
    float64 Swing_Right_Leg
    float64 Swing_Left_Leg
    float64 Swing_Right_Shoulder
    float64 Swing_Left_Shoulder
    float64 Rise_Right_Leg
    float64 Rise_Left_Leg
    float64 Start_Entire_Time
    float64 Start_Swing
    float64 Start_Rise
    float64 End_Entire_Time
    float64 End_Swing
    float64 End_Rise
    float64 Test_X
    float64 Test_Side
    float64 Test_Yaw
    float64 Tuning_X
    float64 Tuning_Side
    float64 Tuning_Yaw
    float64 Balance_Value_0
    float64 Balance_Value_1
    float64 Balance_Value_2
    float64 Balance_Value_3
    float64 Balance_Pitch_GP
    float64 Balance_Pitch_GI
    float64 Balance_Pitch_GD
    float64 Balance_Pitch_ELIMIT
    float64 Balance_Pitch_OLIMIT
    float64 Balance_Pitch_Neg_Target
    float64 Balance_Pitch_Pos_Target
    float64 Balance_Roll_GP
    float64 Balance_Roll_GI
    float64 Balance_Roll_GD
    float64 Balance_Roll_ELIMIT
    float64 Balance_Roll_OLIMIT
    float64 Balance_Roll_Neg_Target
    float64 Balance_Roll_Pos_Target
    float64 Balance_Angle_Pitch_GP
    float64 Balance_Angle_Pitch_GI
    float64 Balance_Angle_Pitch_GD
    float64 Balance_Angle_Pitch_ELIMIT
    float64 Balance_Angle_Pitch_OLIMIT
    float64 Balance_Angle_Pitch_Neg_Target
    float64 Balance_Angle_Pitch_Pos_Target
    
    float64 Balance_Value_4
    float64 Balance_Value_5
    int64 Balance_Pitch_Flag_imu #bool
    float64 Balance_Pitch_GP_imu
    float64 Balance_Pitch_GI_imu
    float64 Balance_Pitch_GD_imu
    float64 Balance_Pitch_Neg_Target_imu
    float64 Balance_Pitch_Pos_Target_imu
    float64 Balance_Pitch_ELIMIT_imu
    float64 Balance_Pitch_OLIMIT_imu
    
    int64 Balance_Roll_Flag_imu #bool
    float64 Balance_Roll_GP_imu
    float64 Balance_Roll_GI_imu
    float64 Balance_Roll_GD_imu
    float64 Balance_Roll_Neg_Target_imu
    float64 Balance_Roll_Pos_Target_imu
    float64 Balance_Roll_ELIMIT_imu
    float64 Balance_Roll_OLIMIT_imu
    
    int64 Balance_Pitch_Flag #bool
    int64 Balance_Ankle_Pitch_Flag #bool
    int64 Balance_Roll_Flag #bool
    int64 Ratio_Check_Flag
    
    float64 Center2Leg
    float64 Link2Link
    float64 Init_Z_Up
    
    float64 Percentage_of_IK_10_Motor
    float64 Percentage_of_IK_11_Motor
    float64 Percentage_of_IK_12_Motor
    float64 Percentage_of_IK_13_Motor
    float64 Percentage_of_IK_14_Motor
    float64 Percentage_of_IK_15_Motor
    float64 Percentage_of_IK_16_Motor
    float64 Percentage_of_IK_17_Motor
    float64 Percentage_of_IK_18_Motor
    float64 Percentage_of_IK_19_Motor
    float64 Percentage_of_IK_20_Motor
    float64 Percentage_of_IK_21_Motor
    
    float64 First_Pos_XR
    float64 First_Neg_XR
    float64 First_Pos_SideR
    float64 First_Neg_SideR
    float64 First_Pos_YawR
    float64 First_Neg_YawR
    float64 First_Pos_XL
    float64 First_Neg_XL
    float64 First_Pos_SideL
    float64 First_Neg_SideL
    float64 First_Pos_YawL
    float64 First_Neg_YawL
    float64 First_Pos_SideR_SwingMinus
    float64 First_Neg_SideR_SwingMinus
    float64 First_Pos_SideL_SwingMinus
    float64 First_Neg_SideL_SwingMinus
    int64 First_min
    int64 First_max
    
    float64 Second_Pos_XR
    float64 Second_Neg_XR
    float64 Second_Pos_SideR
    float64 Second_Neg_SideR
    float64 Second_Pos_YawR
    float64 Second_Neg_YawR
    float64 Second_Pos_XL
    float64 Second_Neg_XL
    float64 Second_Pos_SideL
    float64 Second_Neg_SideL
    float64 Second_Pos_YawL
    float64 Second_Neg_YawL
    float64 Second_Pos_SideR_SwingMinus
    float64 Second_Neg_SideR_SwingMinus
    float64 Second_Pos_SideL_SwingMinus
    float64 Second_Neg_SideL_SwingMinus
    int64 Second_min
    int64 Second_max
    
    float64 Third_Pos_XR
    float64 Third_Neg_XR
    float64 Third_Pos_SideR
    float64 Third_Neg_SideR
    float64 Third_Pos_YawR
    float64 Third_Neg_YawR
    float64 Third_Pos_XL
    float64 Third_Neg_XL
    float64 Third_Pos_SideL
    float64 Third_Neg_SideL
    float64 Third_Pos_YawL
    float64 Third_Neg_YawL
    float64 Third_Pos_SideR_SwingMinus
    float64 Third_Neg_SideR_SwingMinus
    float64 Third_Pos_SideL_SwingMinus
    float64 Third_Neg_SideL_SwingMinus
    int64 Third_min
    int64 Third_max
    
    float64 Fourth_Pos_XR
    float64 Fourth_Neg_XR
    float64 Fourth_Pos_SideR
    float64 Fourth_Neg_SideR
    float64 Fourth_Pos_YawR
    float64 Fourth_Neg_YawR
    float64 Fourth_Pos_XL
    float64 Fourth_Neg_XL
    float64 Fourth_Pos_SideL
    float64 Fourth_Neg_SideL
    float64 Fourth_Pos_YawL
    float64 Fourth_Neg_YawL
    float64 Fourth_Pos_SideR_SwingMinus
    float64 Fourth_Neg_SideR_SwingMinus
    float64 Fourth_Pos_SideL_SwingMinus
    float64 Fourth_Neg_SideL_SwingMinus
    int64 Fourth_min
    int64 Fourth_max
    
    int64 Landing_Time_Control_flag
    
    int64 Control_System_flag
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new tune2walk(null);
    if (msg.IK_Flag !== undefined) {
      resolved.IK_Flag = msg.IK_Flag;
    }
    else {
      resolved.IK_Flag = false
    }

    if (msg.Entire_Time !== undefined) {
      resolved.Entire_Time = msg.Entire_Time;
    }
    else {
      resolved.Entire_Time = 0.0
    }

    if (msg.Frequency !== undefined) {
      resolved.Frequency = msg.Frequency;
    }
    else {
      resolved.Frequency = 0.0
    }

    if (msg.Default_X_Right !== undefined) {
      resolved.Default_X_Right = msg.Default_X_Right;
    }
    else {
      resolved.Default_X_Right = 0.0
    }

    if (msg.Default_X_Left !== undefined) {
      resolved.Default_X_Left = msg.Default_X_Left;
    }
    else {
      resolved.Default_X_Left = 0.0
    }

    if (msg.Default_Y_Right !== undefined) {
      resolved.Default_Y_Right = msg.Default_Y_Right;
    }
    else {
      resolved.Default_Y_Right = 0.0
    }

    if (msg.Default_Y_Left !== undefined) {
      resolved.Default_Y_Left = msg.Default_Y_Left;
    }
    else {
      resolved.Default_Y_Left = 0.0
    }

    if (msg.Default_Z_Right !== undefined) {
      resolved.Default_Z_Right = msg.Default_Z_Right;
    }
    else {
      resolved.Default_Z_Right = 0.0
    }

    if (msg.Default_Z_Left !== undefined) {
      resolved.Default_Z_Left = msg.Default_Z_Left;
    }
    else {
      resolved.Default_Z_Left = 0.0
    }

    if (msg.Offset_10_Motor !== undefined) {
      resolved.Offset_10_Motor = msg.Offset_10_Motor;
    }
    else {
      resolved.Offset_10_Motor = 0.0
    }

    if (msg.Offset_11_Motor !== undefined) {
      resolved.Offset_11_Motor = msg.Offset_11_Motor;
    }
    else {
      resolved.Offset_11_Motor = 0.0
    }

    if (msg.Offset_12_Motor !== undefined) {
      resolved.Offset_12_Motor = msg.Offset_12_Motor;
    }
    else {
      resolved.Offset_12_Motor = 0.0
    }

    if (msg.Offset_13_Motor !== undefined) {
      resolved.Offset_13_Motor = msg.Offset_13_Motor;
    }
    else {
      resolved.Offset_13_Motor = 0.0
    }

    if (msg.Offset_14_Motor !== undefined) {
      resolved.Offset_14_Motor = msg.Offset_14_Motor;
    }
    else {
      resolved.Offset_14_Motor = 0.0
    }

    if (msg.Offset_15_Motor !== undefined) {
      resolved.Offset_15_Motor = msg.Offset_15_Motor;
    }
    else {
      resolved.Offset_15_Motor = 0.0
    }

    if (msg.Offset_16_Motor !== undefined) {
      resolved.Offset_16_Motor = msg.Offset_16_Motor;
    }
    else {
      resolved.Offset_16_Motor = 0.0
    }

    if (msg.Offset_17_Motor !== undefined) {
      resolved.Offset_17_Motor = msg.Offset_17_Motor;
    }
    else {
      resolved.Offset_17_Motor = 0.0
    }

    if (msg.Offset_18_Motor !== undefined) {
      resolved.Offset_18_Motor = msg.Offset_18_Motor;
    }
    else {
      resolved.Offset_18_Motor = 0.0
    }

    if (msg.Offset_19_Motor !== undefined) {
      resolved.Offset_19_Motor = msg.Offset_19_Motor;
    }
    else {
      resolved.Offset_19_Motor = 0.0
    }

    if (msg.Offset_20_Motor !== undefined) {
      resolved.Offset_20_Motor = msg.Offset_20_Motor;
    }
    else {
      resolved.Offset_20_Motor = 0.0
    }

    if (msg.Offset_21_Motor !== undefined) {
      resolved.Offset_21_Motor = msg.Offset_21_Motor;
    }
    else {
      resolved.Offset_21_Motor = 0.0
    }

    if (msg.Swing_Right_Leg !== undefined) {
      resolved.Swing_Right_Leg = msg.Swing_Right_Leg;
    }
    else {
      resolved.Swing_Right_Leg = 0.0
    }

    if (msg.Swing_Left_Leg !== undefined) {
      resolved.Swing_Left_Leg = msg.Swing_Left_Leg;
    }
    else {
      resolved.Swing_Left_Leg = 0.0
    }

    if (msg.Swing_Right_Shoulder !== undefined) {
      resolved.Swing_Right_Shoulder = msg.Swing_Right_Shoulder;
    }
    else {
      resolved.Swing_Right_Shoulder = 0.0
    }

    if (msg.Swing_Left_Shoulder !== undefined) {
      resolved.Swing_Left_Shoulder = msg.Swing_Left_Shoulder;
    }
    else {
      resolved.Swing_Left_Shoulder = 0.0
    }

    if (msg.Rise_Right_Leg !== undefined) {
      resolved.Rise_Right_Leg = msg.Rise_Right_Leg;
    }
    else {
      resolved.Rise_Right_Leg = 0.0
    }

    if (msg.Rise_Left_Leg !== undefined) {
      resolved.Rise_Left_Leg = msg.Rise_Left_Leg;
    }
    else {
      resolved.Rise_Left_Leg = 0.0
    }

    if (msg.Start_Entire_Time !== undefined) {
      resolved.Start_Entire_Time = msg.Start_Entire_Time;
    }
    else {
      resolved.Start_Entire_Time = 0.0
    }

    if (msg.Start_Swing !== undefined) {
      resolved.Start_Swing = msg.Start_Swing;
    }
    else {
      resolved.Start_Swing = 0.0
    }

    if (msg.Start_Rise !== undefined) {
      resolved.Start_Rise = msg.Start_Rise;
    }
    else {
      resolved.Start_Rise = 0.0
    }

    if (msg.End_Entire_Time !== undefined) {
      resolved.End_Entire_Time = msg.End_Entire_Time;
    }
    else {
      resolved.End_Entire_Time = 0.0
    }

    if (msg.End_Swing !== undefined) {
      resolved.End_Swing = msg.End_Swing;
    }
    else {
      resolved.End_Swing = 0.0
    }

    if (msg.End_Rise !== undefined) {
      resolved.End_Rise = msg.End_Rise;
    }
    else {
      resolved.End_Rise = 0.0
    }

    if (msg.Test_X !== undefined) {
      resolved.Test_X = msg.Test_X;
    }
    else {
      resolved.Test_X = 0.0
    }

    if (msg.Test_Side !== undefined) {
      resolved.Test_Side = msg.Test_Side;
    }
    else {
      resolved.Test_Side = 0.0
    }

    if (msg.Test_Yaw !== undefined) {
      resolved.Test_Yaw = msg.Test_Yaw;
    }
    else {
      resolved.Test_Yaw = 0.0
    }

    if (msg.Tuning_X !== undefined) {
      resolved.Tuning_X = msg.Tuning_X;
    }
    else {
      resolved.Tuning_X = 0.0
    }

    if (msg.Tuning_Side !== undefined) {
      resolved.Tuning_Side = msg.Tuning_Side;
    }
    else {
      resolved.Tuning_Side = 0.0
    }

    if (msg.Tuning_Yaw !== undefined) {
      resolved.Tuning_Yaw = msg.Tuning_Yaw;
    }
    else {
      resolved.Tuning_Yaw = 0.0
    }

    if (msg.Balance_Value_0 !== undefined) {
      resolved.Balance_Value_0 = msg.Balance_Value_0;
    }
    else {
      resolved.Balance_Value_0 = 0.0
    }

    if (msg.Balance_Value_1 !== undefined) {
      resolved.Balance_Value_1 = msg.Balance_Value_1;
    }
    else {
      resolved.Balance_Value_1 = 0.0
    }

    if (msg.Balance_Value_2 !== undefined) {
      resolved.Balance_Value_2 = msg.Balance_Value_2;
    }
    else {
      resolved.Balance_Value_2 = 0.0
    }

    if (msg.Balance_Value_3 !== undefined) {
      resolved.Balance_Value_3 = msg.Balance_Value_3;
    }
    else {
      resolved.Balance_Value_3 = 0.0
    }

    if (msg.Balance_Pitch_GP !== undefined) {
      resolved.Balance_Pitch_GP = msg.Balance_Pitch_GP;
    }
    else {
      resolved.Balance_Pitch_GP = 0.0
    }

    if (msg.Balance_Pitch_GI !== undefined) {
      resolved.Balance_Pitch_GI = msg.Balance_Pitch_GI;
    }
    else {
      resolved.Balance_Pitch_GI = 0.0
    }

    if (msg.Balance_Pitch_GD !== undefined) {
      resolved.Balance_Pitch_GD = msg.Balance_Pitch_GD;
    }
    else {
      resolved.Balance_Pitch_GD = 0.0
    }

    if (msg.Balance_Pitch_ELIMIT !== undefined) {
      resolved.Balance_Pitch_ELIMIT = msg.Balance_Pitch_ELIMIT;
    }
    else {
      resolved.Balance_Pitch_ELIMIT = 0.0
    }

    if (msg.Balance_Pitch_OLIMIT !== undefined) {
      resolved.Balance_Pitch_OLIMIT = msg.Balance_Pitch_OLIMIT;
    }
    else {
      resolved.Balance_Pitch_OLIMIT = 0.0
    }

    if (msg.Balance_Pitch_Neg_Target !== undefined) {
      resolved.Balance_Pitch_Neg_Target = msg.Balance_Pitch_Neg_Target;
    }
    else {
      resolved.Balance_Pitch_Neg_Target = 0.0
    }

    if (msg.Balance_Pitch_Pos_Target !== undefined) {
      resolved.Balance_Pitch_Pos_Target = msg.Balance_Pitch_Pos_Target;
    }
    else {
      resolved.Balance_Pitch_Pos_Target = 0.0
    }

    if (msg.Balance_Roll_GP !== undefined) {
      resolved.Balance_Roll_GP = msg.Balance_Roll_GP;
    }
    else {
      resolved.Balance_Roll_GP = 0.0
    }

    if (msg.Balance_Roll_GI !== undefined) {
      resolved.Balance_Roll_GI = msg.Balance_Roll_GI;
    }
    else {
      resolved.Balance_Roll_GI = 0.0
    }

    if (msg.Balance_Roll_GD !== undefined) {
      resolved.Balance_Roll_GD = msg.Balance_Roll_GD;
    }
    else {
      resolved.Balance_Roll_GD = 0.0
    }

    if (msg.Balance_Roll_ELIMIT !== undefined) {
      resolved.Balance_Roll_ELIMIT = msg.Balance_Roll_ELIMIT;
    }
    else {
      resolved.Balance_Roll_ELIMIT = 0.0
    }

    if (msg.Balance_Roll_OLIMIT !== undefined) {
      resolved.Balance_Roll_OLIMIT = msg.Balance_Roll_OLIMIT;
    }
    else {
      resolved.Balance_Roll_OLIMIT = 0.0
    }

    if (msg.Balance_Roll_Neg_Target !== undefined) {
      resolved.Balance_Roll_Neg_Target = msg.Balance_Roll_Neg_Target;
    }
    else {
      resolved.Balance_Roll_Neg_Target = 0.0
    }

    if (msg.Balance_Roll_Pos_Target !== undefined) {
      resolved.Balance_Roll_Pos_Target = msg.Balance_Roll_Pos_Target;
    }
    else {
      resolved.Balance_Roll_Pos_Target = 0.0
    }

    if (msg.Balance_Angle_Pitch_GP !== undefined) {
      resolved.Balance_Angle_Pitch_GP = msg.Balance_Angle_Pitch_GP;
    }
    else {
      resolved.Balance_Angle_Pitch_GP = 0.0
    }

    if (msg.Balance_Angle_Pitch_GI !== undefined) {
      resolved.Balance_Angle_Pitch_GI = msg.Balance_Angle_Pitch_GI;
    }
    else {
      resolved.Balance_Angle_Pitch_GI = 0.0
    }

    if (msg.Balance_Angle_Pitch_GD !== undefined) {
      resolved.Balance_Angle_Pitch_GD = msg.Balance_Angle_Pitch_GD;
    }
    else {
      resolved.Balance_Angle_Pitch_GD = 0.0
    }

    if (msg.Balance_Angle_Pitch_ELIMIT !== undefined) {
      resolved.Balance_Angle_Pitch_ELIMIT = msg.Balance_Angle_Pitch_ELIMIT;
    }
    else {
      resolved.Balance_Angle_Pitch_ELIMIT = 0.0
    }

    if (msg.Balance_Angle_Pitch_OLIMIT !== undefined) {
      resolved.Balance_Angle_Pitch_OLIMIT = msg.Balance_Angle_Pitch_OLIMIT;
    }
    else {
      resolved.Balance_Angle_Pitch_OLIMIT = 0.0
    }

    if (msg.Balance_Angle_Pitch_Neg_Target !== undefined) {
      resolved.Balance_Angle_Pitch_Neg_Target = msg.Balance_Angle_Pitch_Neg_Target;
    }
    else {
      resolved.Balance_Angle_Pitch_Neg_Target = 0.0
    }

    if (msg.Balance_Angle_Pitch_Pos_Target !== undefined) {
      resolved.Balance_Angle_Pitch_Pos_Target = msg.Balance_Angle_Pitch_Pos_Target;
    }
    else {
      resolved.Balance_Angle_Pitch_Pos_Target = 0.0
    }

    if (msg.Balance_Value_4 !== undefined) {
      resolved.Balance_Value_4 = msg.Balance_Value_4;
    }
    else {
      resolved.Balance_Value_4 = 0.0
    }

    if (msg.Balance_Value_5 !== undefined) {
      resolved.Balance_Value_5 = msg.Balance_Value_5;
    }
    else {
      resolved.Balance_Value_5 = 0.0
    }

    if (msg.Balance_Pitch_Flag_imu !== undefined) {
      resolved.Balance_Pitch_Flag_imu = msg.Balance_Pitch_Flag_imu;
    }
    else {
      resolved.Balance_Pitch_Flag_imu = 0
    }

    if (msg.Balance_Pitch_GP_imu !== undefined) {
      resolved.Balance_Pitch_GP_imu = msg.Balance_Pitch_GP_imu;
    }
    else {
      resolved.Balance_Pitch_GP_imu = 0.0
    }

    if (msg.Balance_Pitch_GI_imu !== undefined) {
      resolved.Balance_Pitch_GI_imu = msg.Balance_Pitch_GI_imu;
    }
    else {
      resolved.Balance_Pitch_GI_imu = 0.0
    }

    if (msg.Balance_Pitch_GD_imu !== undefined) {
      resolved.Balance_Pitch_GD_imu = msg.Balance_Pitch_GD_imu;
    }
    else {
      resolved.Balance_Pitch_GD_imu = 0.0
    }

    if (msg.Balance_Pitch_Neg_Target_imu !== undefined) {
      resolved.Balance_Pitch_Neg_Target_imu = msg.Balance_Pitch_Neg_Target_imu;
    }
    else {
      resolved.Balance_Pitch_Neg_Target_imu = 0.0
    }

    if (msg.Balance_Pitch_Pos_Target_imu !== undefined) {
      resolved.Balance_Pitch_Pos_Target_imu = msg.Balance_Pitch_Pos_Target_imu;
    }
    else {
      resolved.Balance_Pitch_Pos_Target_imu = 0.0
    }

    if (msg.Balance_Pitch_ELIMIT_imu !== undefined) {
      resolved.Balance_Pitch_ELIMIT_imu = msg.Balance_Pitch_ELIMIT_imu;
    }
    else {
      resolved.Balance_Pitch_ELIMIT_imu = 0.0
    }

    if (msg.Balance_Pitch_OLIMIT_imu !== undefined) {
      resolved.Balance_Pitch_OLIMIT_imu = msg.Balance_Pitch_OLIMIT_imu;
    }
    else {
      resolved.Balance_Pitch_OLIMIT_imu = 0.0
    }

    if (msg.Balance_Roll_Flag_imu !== undefined) {
      resolved.Balance_Roll_Flag_imu = msg.Balance_Roll_Flag_imu;
    }
    else {
      resolved.Balance_Roll_Flag_imu = 0
    }

    if (msg.Balance_Roll_GP_imu !== undefined) {
      resolved.Balance_Roll_GP_imu = msg.Balance_Roll_GP_imu;
    }
    else {
      resolved.Balance_Roll_GP_imu = 0.0
    }

    if (msg.Balance_Roll_GI_imu !== undefined) {
      resolved.Balance_Roll_GI_imu = msg.Balance_Roll_GI_imu;
    }
    else {
      resolved.Balance_Roll_GI_imu = 0.0
    }

    if (msg.Balance_Roll_GD_imu !== undefined) {
      resolved.Balance_Roll_GD_imu = msg.Balance_Roll_GD_imu;
    }
    else {
      resolved.Balance_Roll_GD_imu = 0.0
    }

    if (msg.Balance_Roll_Neg_Target_imu !== undefined) {
      resolved.Balance_Roll_Neg_Target_imu = msg.Balance_Roll_Neg_Target_imu;
    }
    else {
      resolved.Balance_Roll_Neg_Target_imu = 0.0
    }

    if (msg.Balance_Roll_Pos_Target_imu !== undefined) {
      resolved.Balance_Roll_Pos_Target_imu = msg.Balance_Roll_Pos_Target_imu;
    }
    else {
      resolved.Balance_Roll_Pos_Target_imu = 0.0
    }

    if (msg.Balance_Roll_ELIMIT_imu !== undefined) {
      resolved.Balance_Roll_ELIMIT_imu = msg.Balance_Roll_ELIMIT_imu;
    }
    else {
      resolved.Balance_Roll_ELIMIT_imu = 0.0
    }

    if (msg.Balance_Roll_OLIMIT_imu !== undefined) {
      resolved.Balance_Roll_OLIMIT_imu = msg.Balance_Roll_OLIMIT_imu;
    }
    else {
      resolved.Balance_Roll_OLIMIT_imu = 0.0
    }

    if (msg.Balance_Pitch_Flag !== undefined) {
      resolved.Balance_Pitch_Flag = msg.Balance_Pitch_Flag;
    }
    else {
      resolved.Balance_Pitch_Flag = 0
    }

    if (msg.Balance_Ankle_Pitch_Flag !== undefined) {
      resolved.Balance_Ankle_Pitch_Flag = msg.Balance_Ankle_Pitch_Flag;
    }
    else {
      resolved.Balance_Ankle_Pitch_Flag = 0
    }

    if (msg.Balance_Roll_Flag !== undefined) {
      resolved.Balance_Roll_Flag = msg.Balance_Roll_Flag;
    }
    else {
      resolved.Balance_Roll_Flag = 0
    }

    if (msg.Ratio_Check_Flag !== undefined) {
      resolved.Ratio_Check_Flag = msg.Ratio_Check_Flag;
    }
    else {
      resolved.Ratio_Check_Flag = 0
    }

    if (msg.Center2Leg !== undefined) {
      resolved.Center2Leg = msg.Center2Leg;
    }
    else {
      resolved.Center2Leg = 0.0
    }

    if (msg.Link2Link !== undefined) {
      resolved.Link2Link = msg.Link2Link;
    }
    else {
      resolved.Link2Link = 0.0
    }

    if (msg.Init_Z_Up !== undefined) {
      resolved.Init_Z_Up = msg.Init_Z_Up;
    }
    else {
      resolved.Init_Z_Up = 0.0
    }

    if (msg.Percentage_of_IK_10_Motor !== undefined) {
      resolved.Percentage_of_IK_10_Motor = msg.Percentage_of_IK_10_Motor;
    }
    else {
      resolved.Percentage_of_IK_10_Motor = 0.0
    }

    if (msg.Percentage_of_IK_11_Motor !== undefined) {
      resolved.Percentage_of_IK_11_Motor = msg.Percentage_of_IK_11_Motor;
    }
    else {
      resolved.Percentage_of_IK_11_Motor = 0.0
    }

    if (msg.Percentage_of_IK_12_Motor !== undefined) {
      resolved.Percentage_of_IK_12_Motor = msg.Percentage_of_IK_12_Motor;
    }
    else {
      resolved.Percentage_of_IK_12_Motor = 0.0
    }

    if (msg.Percentage_of_IK_13_Motor !== undefined) {
      resolved.Percentage_of_IK_13_Motor = msg.Percentage_of_IK_13_Motor;
    }
    else {
      resolved.Percentage_of_IK_13_Motor = 0.0
    }

    if (msg.Percentage_of_IK_14_Motor !== undefined) {
      resolved.Percentage_of_IK_14_Motor = msg.Percentage_of_IK_14_Motor;
    }
    else {
      resolved.Percentage_of_IK_14_Motor = 0.0
    }

    if (msg.Percentage_of_IK_15_Motor !== undefined) {
      resolved.Percentage_of_IK_15_Motor = msg.Percentage_of_IK_15_Motor;
    }
    else {
      resolved.Percentage_of_IK_15_Motor = 0.0
    }

    if (msg.Percentage_of_IK_16_Motor !== undefined) {
      resolved.Percentage_of_IK_16_Motor = msg.Percentage_of_IK_16_Motor;
    }
    else {
      resolved.Percentage_of_IK_16_Motor = 0.0
    }

    if (msg.Percentage_of_IK_17_Motor !== undefined) {
      resolved.Percentage_of_IK_17_Motor = msg.Percentage_of_IK_17_Motor;
    }
    else {
      resolved.Percentage_of_IK_17_Motor = 0.0
    }

    if (msg.Percentage_of_IK_18_Motor !== undefined) {
      resolved.Percentage_of_IK_18_Motor = msg.Percentage_of_IK_18_Motor;
    }
    else {
      resolved.Percentage_of_IK_18_Motor = 0.0
    }

    if (msg.Percentage_of_IK_19_Motor !== undefined) {
      resolved.Percentage_of_IK_19_Motor = msg.Percentage_of_IK_19_Motor;
    }
    else {
      resolved.Percentage_of_IK_19_Motor = 0.0
    }

    if (msg.Percentage_of_IK_20_Motor !== undefined) {
      resolved.Percentage_of_IK_20_Motor = msg.Percentage_of_IK_20_Motor;
    }
    else {
      resolved.Percentage_of_IK_20_Motor = 0.0
    }

    if (msg.Percentage_of_IK_21_Motor !== undefined) {
      resolved.Percentage_of_IK_21_Motor = msg.Percentage_of_IK_21_Motor;
    }
    else {
      resolved.Percentage_of_IK_21_Motor = 0.0
    }

    if (msg.First_Pos_XR !== undefined) {
      resolved.First_Pos_XR = msg.First_Pos_XR;
    }
    else {
      resolved.First_Pos_XR = 0.0
    }

    if (msg.First_Neg_XR !== undefined) {
      resolved.First_Neg_XR = msg.First_Neg_XR;
    }
    else {
      resolved.First_Neg_XR = 0.0
    }

    if (msg.First_Pos_SideR !== undefined) {
      resolved.First_Pos_SideR = msg.First_Pos_SideR;
    }
    else {
      resolved.First_Pos_SideR = 0.0
    }

    if (msg.First_Neg_SideR !== undefined) {
      resolved.First_Neg_SideR = msg.First_Neg_SideR;
    }
    else {
      resolved.First_Neg_SideR = 0.0
    }

    if (msg.First_Pos_YawR !== undefined) {
      resolved.First_Pos_YawR = msg.First_Pos_YawR;
    }
    else {
      resolved.First_Pos_YawR = 0.0
    }

    if (msg.First_Neg_YawR !== undefined) {
      resolved.First_Neg_YawR = msg.First_Neg_YawR;
    }
    else {
      resolved.First_Neg_YawR = 0.0
    }

    if (msg.First_Pos_XL !== undefined) {
      resolved.First_Pos_XL = msg.First_Pos_XL;
    }
    else {
      resolved.First_Pos_XL = 0.0
    }

    if (msg.First_Neg_XL !== undefined) {
      resolved.First_Neg_XL = msg.First_Neg_XL;
    }
    else {
      resolved.First_Neg_XL = 0.0
    }

    if (msg.First_Pos_SideL !== undefined) {
      resolved.First_Pos_SideL = msg.First_Pos_SideL;
    }
    else {
      resolved.First_Pos_SideL = 0.0
    }

    if (msg.First_Neg_SideL !== undefined) {
      resolved.First_Neg_SideL = msg.First_Neg_SideL;
    }
    else {
      resolved.First_Neg_SideL = 0.0
    }

    if (msg.First_Pos_YawL !== undefined) {
      resolved.First_Pos_YawL = msg.First_Pos_YawL;
    }
    else {
      resolved.First_Pos_YawL = 0.0
    }

    if (msg.First_Neg_YawL !== undefined) {
      resolved.First_Neg_YawL = msg.First_Neg_YawL;
    }
    else {
      resolved.First_Neg_YawL = 0.0
    }

    if (msg.First_Pos_SideR_SwingMinus !== undefined) {
      resolved.First_Pos_SideR_SwingMinus = msg.First_Pos_SideR_SwingMinus;
    }
    else {
      resolved.First_Pos_SideR_SwingMinus = 0.0
    }

    if (msg.First_Neg_SideR_SwingMinus !== undefined) {
      resolved.First_Neg_SideR_SwingMinus = msg.First_Neg_SideR_SwingMinus;
    }
    else {
      resolved.First_Neg_SideR_SwingMinus = 0.0
    }

    if (msg.First_Pos_SideL_SwingMinus !== undefined) {
      resolved.First_Pos_SideL_SwingMinus = msg.First_Pos_SideL_SwingMinus;
    }
    else {
      resolved.First_Pos_SideL_SwingMinus = 0.0
    }

    if (msg.First_Neg_SideL_SwingMinus !== undefined) {
      resolved.First_Neg_SideL_SwingMinus = msg.First_Neg_SideL_SwingMinus;
    }
    else {
      resolved.First_Neg_SideL_SwingMinus = 0.0
    }

    if (msg.First_min !== undefined) {
      resolved.First_min = msg.First_min;
    }
    else {
      resolved.First_min = 0
    }

    if (msg.First_max !== undefined) {
      resolved.First_max = msg.First_max;
    }
    else {
      resolved.First_max = 0
    }

    if (msg.Second_Pos_XR !== undefined) {
      resolved.Second_Pos_XR = msg.Second_Pos_XR;
    }
    else {
      resolved.Second_Pos_XR = 0.0
    }

    if (msg.Second_Neg_XR !== undefined) {
      resolved.Second_Neg_XR = msg.Second_Neg_XR;
    }
    else {
      resolved.Second_Neg_XR = 0.0
    }

    if (msg.Second_Pos_SideR !== undefined) {
      resolved.Second_Pos_SideR = msg.Second_Pos_SideR;
    }
    else {
      resolved.Second_Pos_SideR = 0.0
    }

    if (msg.Second_Neg_SideR !== undefined) {
      resolved.Second_Neg_SideR = msg.Second_Neg_SideR;
    }
    else {
      resolved.Second_Neg_SideR = 0.0
    }

    if (msg.Second_Pos_YawR !== undefined) {
      resolved.Second_Pos_YawR = msg.Second_Pos_YawR;
    }
    else {
      resolved.Second_Pos_YawR = 0.0
    }

    if (msg.Second_Neg_YawR !== undefined) {
      resolved.Second_Neg_YawR = msg.Second_Neg_YawR;
    }
    else {
      resolved.Second_Neg_YawR = 0.0
    }

    if (msg.Second_Pos_XL !== undefined) {
      resolved.Second_Pos_XL = msg.Second_Pos_XL;
    }
    else {
      resolved.Second_Pos_XL = 0.0
    }

    if (msg.Second_Neg_XL !== undefined) {
      resolved.Second_Neg_XL = msg.Second_Neg_XL;
    }
    else {
      resolved.Second_Neg_XL = 0.0
    }

    if (msg.Second_Pos_SideL !== undefined) {
      resolved.Second_Pos_SideL = msg.Second_Pos_SideL;
    }
    else {
      resolved.Second_Pos_SideL = 0.0
    }

    if (msg.Second_Neg_SideL !== undefined) {
      resolved.Second_Neg_SideL = msg.Second_Neg_SideL;
    }
    else {
      resolved.Second_Neg_SideL = 0.0
    }

    if (msg.Second_Pos_YawL !== undefined) {
      resolved.Second_Pos_YawL = msg.Second_Pos_YawL;
    }
    else {
      resolved.Second_Pos_YawL = 0.0
    }

    if (msg.Second_Neg_YawL !== undefined) {
      resolved.Second_Neg_YawL = msg.Second_Neg_YawL;
    }
    else {
      resolved.Second_Neg_YawL = 0.0
    }

    if (msg.Second_Pos_SideR_SwingMinus !== undefined) {
      resolved.Second_Pos_SideR_SwingMinus = msg.Second_Pos_SideR_SwingMinus;
    }
    else {
      resolved.Second_Pos_SideR_SwingMinus = 0.0
    }

    if (msg.Second_Neg_SideR_SwingMinus !== undefined) {
      resolved.Second_Neg_SideR_SwingMinus = msg.Second_Neg_SideR_SwingMinus;
    }
    else {
      resolved.Second_Neg_SideR_SwingMinus = 0.0
    }

    if (msg.Second_Pos_SideL_SwingMinus !== undefined) {
      resolved.Second_Pos_SideL_SwingMinus = msg.Second_Pos_SideL_SwingMinus;
    }
    else {
      resolved.Second_Pos_SideL_SwingMinus = 0.0
    }

    if (msg.Second_Neg_SideL_SwingMinus !== undefined) {
      resolved.Second_Neg_SideL_SwingMinus = msg.Second_Neg_SideL_SwingMinus;
    }
    else {
      resolved.Second_Neg_SideL_SwingMinus = 0.0
    }

    if (msg.Second_min !== undefined) {
      resolved.Second_min = msg.Second_min;
    }
    else {
      resolved.Second_min = 0
    }

    if (msg.Second_max !== undefined) {
      resolved.Second_max = msg.Second_max;
    }
    else {
      resolved.Second_max = 0
    }

    if (msg.Third_Pos_XR !== undefined) {
      resolved.Third_Pos_XR = msg.Third_Pos_XR;
    }
    else {
      resolved.Third_Pos_XR = 0.0
    }

    if (msg.Third_Neg_XR !== undefined) {
      resolved.Third_Neg_XR = msg.Third_Neg_XR;
    }
    else {
      resolved.Third_Neg_XR = 0.0
    }

    if (msg.Third_Pos_SideR !== undefined) {
      resolved.Third_Pos_SideR = msg.Third_Pos_SideR;
    }
    else {
      resolved.Third_Pos_SideR = 0.0
    }

    if (msg.Third_Neg_SideR !== undefined) {
      resolved.Third_Neg_SideR = msg.Third_Neg_SideR;
    }
    else {
      resolved.Third_Neg_SideR = 0.0
    }

    if (msg.Third_Pos_YawR !== undefined) {
      resolved.Third_Pos_YawR = msg.Third_Pos_YawR;
    }
    else {
      resolved.Third_Pos_YawR = 0.0
    }

    if (msg.Third_Neg_YawR !== undefined) {
      resolved.Third_Neg_YawR = msg.Third_Neg_YawR;
    }
    else {
      resolved.Third_Neg_YawR = 0.0
    }

    if (msg.Third_Pos_XL !== undefined) {
      resolved.Third_Pos_XL = msg.Third_Pos_XL;
    }
    else {
      resolved.Third_Pos_XL = 0.0
    }

    if (msg.Third_Neg_XL !== undefined) {
      resolved.Third_Neg_XL = msg.Third_Neg_XL;
    }
    else {
      resolved.Third_Neg_XL = 0.0
    }

    if (msg.Third_Pos_SideL !== undefined) {
      resolved.Third_Pos_SideL = msg.Third_Pos_SideL;
    }
    else {
      resolved.Third_Pos_SideL = 0.0
    }

    if (msg.Third_Neg_SideL !== undefined) {
      resolved.Third_Neg_SideL = msg.Third_Neg_SideL;
    }
    else {
      resolved.Third_Neg_SideL = 0.0
    }

    if (msg.Third_Pos_YawL !== undefined) {
      resolved.Third_Pos_YawL = msg.Third_Pos_YawL;
    }
    else {
      resolved.Third_Pos_YawL = 0.0
    }

    if (msg.Third_Neg_YawL !== undefined) {
      resolved.Third_Neg_YawL = msg.Third_Neg_YawL;
    }
    else {
      resolved.Third_Neg_YawL = 0.0
    }

    if (msg.Third_Pos_SideR_SwingMinus !== undefined) {
      resolved.Third_Pos_SideR_SwingMinus = msg.Third_Pos_SideR_SwingMinus;
    }
    else {
      resolved.Third_Pos_SideR_SwingMinus = 0.0
    }

    if (msg.Third_Neg_SideR_SwingMinus !== undefined) {
      resolved.Third_Neg_SideR_SwingMinus = msg.Third_Neg_SideR_SwingMinus;
    }
    else {
      resolved.Third_Neg_SideR_SwingMinus = 0.0
    }

    if (msg.Third_Pos_SideL_SwingMinus !== undefined) {
      resolved.Third_Pos_SideL_SwingMinus = msg.Third_Pos_SideL_SwingMinus;
    }
    else {
      resolved.Third_Pos_SideL_SwingMinus = 0.0
    }

    if (msg.Third_Neg_SideL_SwingMinus !== undefined) {
      resolved.Third_Neg_SideL_SwingMinus = msg.Third_Neg_SideL_SwingMinus;
    }
    else {
      resolved.Third_Neg_SideL_SwingMinus = 0.0
    }

    if (msg.Third_min !== undefined) {
      resolved.Third_min = msg.Third_min;
    }
    else {
      resolved.Third_min = 0
    }

    if (msg.Third_max !== undefined) {
      resolved.Third_max = msg.Third_max;
    }
    else {
      resolved.Third_max = 0
    }

    if (msg.Fourth_Pos_XR !== undefined) {
      resolved.Fourth_Pos_XR = msg.Fourth_Pos_XR;
    }
    else {
      resolved.Fourth_Pos_XR = 0.0
    }

    if (msg.Fourth_Neg_XR !== undefined) {
      resolved.Fourth_Neg_XR = msg.Fourth_Neg_XR;
    }
    else {
      resolved.Fourth_Neg_XR = 0.0
    }

    if (msg.Fourth_Pos_SideR !== undefined) {
      resolved.Fourth_Pos_SideR = msg.Fourth_Pos_SideR;
    }
    else {
      resolved.Fourth_Pos_SideR = 0.0
    }

    if (msg.Fourth_Neg_SideR !== undefined) {
      resolved.Fourth_Neg_SideR = msg.Fourth_Neg_SideR;
    }
    else {
      resolved.Fourth_Neg_SideR = 0.0
    }

    if (msg.Fourth_Pos_YawR !== undefined) {
      resolved.Fourth_Pos_YawR = msg.Fourth_Pos_YawR;
    }
    else {
      resolved.Fourth_Pos_YawR = 0.0
    }

    if (msg.Fourth_Neg_YawR !== undefined) {
      resolved.Fourth_Neg_YawR = msg.Fourth_Neg_YawR;
    }
    else {
      resolved.Fourth_Neg_YawR = 0.0
    }

    if (msg.Fourth_Pos_XL !== undefined) {
      resolved.Fourth_Pos_XL = msg.Fourth_Pos_XL;
    }
    else {
      resolved.Fourth_Pos_XL = 0.0
    }

    if (msg.Fourth_Neg_XL !== undefined) {
      resolved.Fourth_Neg_XL = msg.Fourth_Neg_XL;
    }
    else {
      resolved.Fourth_Neg_XL = 0.0
    }

    if (msg.Fourth_Pos_SideL !== undefined) {
      resolved.Fourth_Pos_SideL = msg.Fourth_Pos_SideL;
    }
    else {
      resolved.Fourth_Pos_SideL = 0.0
    }

    if (msg.Fourth_Neg_SideL !== undefined) {
      resolved.Fourth_Neg_SideL = msg.Fourth_Neg_SideL;
    }
    else {
      resolved.Fourth_Neg_SideL = 0.0
    }

    if (msg.Fourth_Pos_YawL !== undefined) {
      resolved.Fourth_Pos_YawL = msg.Fourth_Pos_YawL;
    }
    else {
      resolved.Fourth_Pos_YawL = 0.0
    }

    if (msg.Fourth_Neg_YawL !== undefined) {
      resolved.Fourth_Neg_YawL = msg.Fourth_Neg_YawL;
    }
    else {
      resolved.Fourth_Neg_YawL = 0.0
    }

    if (msg.Fourth_Pos_SideR_SwingMinus !== undefined) {
      resolved.Fourth_Pos_SideR_SwingMinus = msg.Fourth_Pos_SideR_SwingMinus;
    }
    else {
      resolved.Fourth_Pos_SideR_SwingMinus = 0.0
    }

    if (msg.Fourth_Neg_SideR_SwingMinus !== undefined) {
      resolved.Fourth_Neg_SideR_SwingMinus = msg.Fourth_Neg_SideR_SwingMinus;
    }
    else {
      resolved.Fourth_Neg_SideR_SwingMinus = 0.0
    }

    if (msg.Fourth_Pos_SideL_SwingMinus !== undefined) {
      resolved.Fourth_Pos_SideL_SwingMinus = msg.Fourth_Pos_SideL_SwingMinus;
    }
    else {
      resolved.Fourth_Pos_SideL_SwingMinus = 0.0
    }

    if (msg.Fourth_Neg_SideL_SwingMinus !== undefined) {
      resolved.Fourth_Neg_SideL_SwingMinus = msg.Fourth_Neg_SideL_SwingMinus;
    }
    else {
      resolved.Fourth_Neg_SideL_SwingMinus = 0.0
    }

    if (msg.Fourth_min !== undefined) {
      resolved.Fourth_min = msg.Fourth_min;
    }
    else {
      resolved.Fourth_min = 0
    }

    if (msg.Fourth_max !== undefined) {
      resolved.Fourth_max = msg.Fourth_max;
    }
    else {
      resolved.Fourth_max = 0
    }

    if (msg.Landing_Time_Control_flag !== undefined) {
      resolved.Landing_Time_Control_flag = msg.Landing_Time_Control_flag;
    }
    else {
      resolved.Landing_Time_Control_flag = 0
    }

    if (msg.Control_System_flag !== undefined) {
      resolved.Control_System_flag = msg.Control_System_flag;
    }
    else {
      resolved.Control_System_flag = 0
    }

    return resolved;
    }
};

module.exports = tune2walk;
