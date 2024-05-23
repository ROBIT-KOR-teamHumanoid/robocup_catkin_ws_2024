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

class eom_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.IK_Flag = null;
      this.Entire_Time = null;
      this.Frequency = null;
      this.Double_Ratio = null;
      this.Single_Ratio = null;
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
      this.Balance_Pitch_Flag = null;
      this.Balance_Angle_Pitch_Flag = null;
      this.Balance_Roll_Flag = null;
      this.Balance_Time_Flag = null;
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
      if (initObj.hasOwnProperty('Double_Ratio')) {
        this.Double_Ratio = initObj.Double_Ratio
      }
      else {
        this.Double_Ratio = 0.0;
      }
      if (initObj.hasOwnProperty('Single_Ratio')) {
        this.Single_Ratio = initObj.Single_Ratio
      }
      else {
        this.Single_Ratio = 0.0;
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
      if (initObj.hasOwnProperty('Balance_Pitch_Flag')) {
        this.Balance_Pitch_Flag = initObj.Balance_Pitch_Flag
      }
      else {
        this.Balance_Pitch_Flag = false;
      }
      if (initObj.hasOwnProperty('Balance_Angle_Pitch_Flag')) {
        this.Balance_Angle_Pitch_Flag = initObj.Balance_Angle_Pitch_Flag
      }
      else {
        this.Balance_Angle_Pitch_Flag = false;
      }
      if (initObj.hasOwnProperty('Balance_Roll_Flag')) {
        this.Balance_Roll_Flag = initObj.Balance_Roll_Flag
      }
      else {
        this.Balance_Roll_Flag = false;
      }
      if (initObj.hasOwnProperty('Balance_Time_Flag')) {
        this.Balance_Time_Flag = initObj.Balance_Time_Flag
      }
      else {
        this.Balance_Time_Flag = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type eom_msg
    // Serialize message field [IK_Flag]
    bufferOffset = _serializer.bool(obj.IK_Flag, buffer, bufferOffset);
    // Serialize message field [Entire_Time]
    bufferOffset = _serializer.float64(obj.Entire_Time, buffer, bufferOffset);
    // Serialize message field [Frequency]
    bufferOffset = _serializer.float64(obj.Frequency, buffer, bufferOffset);
    // Serialize message field [Double_Ratio]
    bufferOffset = _serializer.float64(obj.Double_Ratio, buffer, bufferOffset);
    // Serialize message field [Single_Ratio]
    bufferOffset = _serializer.float64(obj.Single_Ratio, buffer, bufferOffset);
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
    // Serialize message field [Balance_Pitch_Flag]
    bufferOffset = _serializer.bool(obj.Balance_Pitch_Flag, buffer, bufferOffset);
    // Serialize message field [Balance_Angle_Pitch_Flag]
    bufferOffset = _serializer.bool(obj.Balance_Angle_Pitch_Flag, buffer, bufferOffset);
    // Serialize message field [Balance_Roll_Flag]
    bufferOffset = _serializer.bool(obj.Balance_Roll_Flag, buffer, bufferOffset);
    // Serialize message field [Balance_Time_Flag]
    bufferOffset = _serializer.float64(obj.Balance_Time_Flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type eom_msg
    let len;
    let data = new eom_msg(null);
    // Deserialize message field [IK_Flag]
    data.IK_Flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Entire_Time]
    data.Entire_Time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Frequency]
    data.Frequency = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Double_Ratio]
    data.Double_Ratio = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Single_Ratio]
    data.Single_Ratio = _deserializer.float64(buffer, bufferOffset);
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
    // Deserialize message field [Balance_Pitch_Flag]
    data.Balance_Pitch_Flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Balance_Angle_Pitch_Flag]
    data.Balance_Angle_Pitch_Flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Balance_Roll_Flag]
    data.Balance_Roll_Flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Balance_Time_Flag]
    data.Balance_Time_Flag = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 532;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/eom_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2bab63df50bb1f7ece05fa6985761519';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool IK_Flag
    float64 Entire_Time
    float64 Frequency
    float64 Double_Ratio
    float64 Single_Ratio
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
    bool Balance_Pitch_Flag
    bool Balance_Angle_Pitch_Flag
    bool Balance_Roll_Flag
    float64 Balance_Time_Flag
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new eom_msg(null);
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

    if (msg.Double_Ratio !== undefined) {
      resolved.Double_Ratio = msg.Double_Ratio;
    }
    else {
      resolved.Double_Ratio = 0.0
    }

    if (msg.Single_Ratio !== undefined) {
      resolved.Single_Ratio = msg.Single_Ratio;
    }
    else {
      resolved.Single_Ratio = 0.0
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

    if (msg.Balance_Pitch_Flag !== undefined) {
      resolved.Balance_Pitch_Flag = msg.Balance_Pitch_Flag;
    }
    else {
      resolved.Balance_Pitch_Flag = false
    }

    if (msg.Balance_Angle_Pitch_Flag !== undefined) {
      resolved.Balance_Angle_Pitch_Flag = msg.Balance_Angle_Pitch_Flag;
    }
    else {
      resolved.Balance_Angle_Pitch_Flag = false
    }

    if (msg.Balance_Roll_Flag !== undefined) {
      resolved.Balance_Roll_Flag = msg.Balance_Roll_Flag;
    }
    else {
      resolved.Balance_Roll_Flag = false
    }

    if (msg.Balance_Time_Flag !== undefined) {
      resolved.Balance_Time_Flag = msg.Balance_Time_Flag;
    }
    else {
      resolved.Balance_Time_Flag = 0.0
    }

    return resolved;
    }
};

module.exports = eom_msg;
