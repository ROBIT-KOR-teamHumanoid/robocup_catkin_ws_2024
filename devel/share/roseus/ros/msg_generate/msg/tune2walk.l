;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::tune2walk)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'tune2walk (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::TUNE2WALK")
  (make-package "MSG_GENERATE::TUNE2WALK"))

(in-package "ROS")
;;//! \htmlinclude tune2walk.msg.html


(defclass msg_generate::tune2walk
  :super ros::object
  :slots (_IK_Flag _Entire_Time _Frequency _Default_X_Right _Default_X_Left _Default_Y_Right _Default_Y_Left _Default_Z_Right _Default_Z_Left _Offset_10_Motor _Offset_11_Motor _Offset_12_Motor _Offset_13_Motor _Offset_14_Motor _Offset_15_Motor _Offset_16_Motor _Offset_17_Motor _Offset_18_Motor _Offset_19_Motor _Offset_20_Motor _Offset_21_Motor _Swing_Right_Leg _Swing_Left_Leg _Swing_Right_Shoulder _Swing_Left_Shoulder _Rise_Right_Leg _Rise_Left_Leg _Start_Entire_Time _Start_Swing _Start_Rise _End_Entire_Time _End_Swing _End_Rise _Test_X _Test_Side _Test_Yaw _Tuning_X _Tuning_Side _Tuning_Yaw _Balance_Value_0 _Balance_Value_1 _Balance_Value_2 _Balance_Value_3 _Balance_Pitch_GP _Balance_Pitch_GI _Balance_Pitch_GD _Balance_Pitch_ELIMIT _Balance_Pitch_OLIMIT _Balance_Pitch_Neg_Target _Balance_Pitch_Pos_Target _Balance_Roll_GP _Balance_Roll_GI _Balance_Roll_GD _Balance_Roll_ELIMIT _Balance_Roll_OLIMIT _Balance_Roll_Neg_Target _Balance_Roll_Pos_Target _Balance_Angle_Pitch_GP _Balance_Angle_Pitch_GI _Balance_Angle_Pitch_GD _Balance_Angle_Pitch_ELIMIT _Balance_Angle_Pitch_OLIMIT _Balance_Angle_Pitch_Neg_Target _Balance_Angle_Pitch_Pos_Target _Balance_Value_4 _Balance_Value_5 _Balance_Pitch_Flag_imu _Balance_Pitch_GP_imu _Balance_Pitch_GI_imu _Balance_Pitch_GD_imu _Balance_Pitch_Neg_Target_imu _Balance_Pitch_Pos_Target_imu _Balance_Pitch_ELIMIT_imu _Balance_Pitch_OLIMIT_imu _Balance_Roll_Flag_imu _Balance_Roll_GP_imu _Balance_Roll_GI_imu _Balance_Roll_GD_imu _Balance_Roll_Neg_Target_imu _Balance_Roll_Pos_Target_imu _Balance_Roll_ELIMIT_imu _Balance_Roll_OLIMIT_imu _Balance_Pitch_Flag _Balance_Ankle_Pitch_Flag _Balance_Roll_Flag _Ratio_Check_Flag _Center2Leg _Link2Link _Init_Z_Up _Percentage_of_IK_10_Motor _Percentage_of_IK_11_Motor _Percentage_of_IK_12_Motor _Percentage_of_IK_13_Motor _Percentage_of_IK_14_Motor _Percentage_of_IK_15_Motor _Percentage_of_IK_16_Motor _Percentage_of_IK_17_Motor _Percentage_of_IK_18_Motor _Percentage_of_IK_19_Motor _Percentage_of_IK_20_Motor _Percentage_of_IK_21_Motor _First_Pos_XR _First_Neg_XR _First_Pos_SideR _First_Neg_SideR _First_Pos_YawR _First_Neg_YawR _First_Pos_XL _First_Neg_XL _First_Pos_SideL _First_Neg_SideL _First_Pos_YawL _First_Neg_YawL _First_Pos_SideR_SwingMinus _First_Neg_SideR_SwingMinus _First_Pos_SideL_SwingMinus _First_Neg_SideL_SwingMinus _First_min _First_max _Second_Pos_XR _Second_Neg_XR _Second_Pos_SideR _Second_Neg_SideR _Second_Pos_YawR _Second_Neg_YawR _Second_Pos_XL _Second_Neg_XL _Second_Pos_SideL _Second_Neg_SideL _Second_Pos_YawL _Second_Neg_YawL _Second_Pos_SideR_SwingMinus _Second_Neg_SideR_SwingMinus _Second_Pos_SideL_SwingMinus _Second_Neg_SideL_SwingMinus _Second_min _Second_max _Third_Pos_XR _Third_Neg_XR _Third_Pos_SideR _Third_Neg_SideR _Third_Pos_YawR _Third_Neg_YawR _Third_Pos_XL _Third_Neg_XL _Third_Pos_SideL _Third_Neg_SideL _Third_Pos_YawL _Third_Neg_YawL _Third_Pos_SideR_SwingMinus _Third_Neg_SideR_SwingMinus _Third_Pos_SideL_SwingMinus _Third_Neg_SideL_SwingMinus _Third_min _Third_max _Fourth_Pos_XR _Fourth_Neg_XR _Fourth_Pos_SideR _Fourth_Neg_SideR _Fourth_Pos_YawR _Fourth_Neg_YawR _Fourth_Pos_XL _Fourth_Neg_XL _Fourth_Pos_SideL _Fourth_Neg_SideL _Fourth_Pos_YawL _Fourth_Neg_YawL _Fourth_Pos_SideR_SwingMinus _Fourth_Neg_SideR_SwingMinus _Fourth_Pos_SideL_SwingMinus _Fourth_Neg_SideL_SwingMinus _Fourth_min _Fourth_max _Landing_Time_Control_flag _Control_System_flag ))

(defmethod msg_generate::tune2walk
  (:init
   (&key
    ((:IK_Flag __IK_Flag) nil)
    ((:Entire_Time __Entire_Time) 0.0)
    ((:Frequency __Frequency) 0.0)
    ((:Default_X_Right __Default_X_Right) 0.0)
    ((:Default_X_Left __Default_X_Left) 0.0)
    ((:Default_Y_Right __Default_Y_Right) 0.0)
    ((:Default_Y_Left __Default_Y_Left) 0.0)
    ((:Default_Z_Right __Default_Z_Right) 0.0)
    ((:Default_Z_Left __Default_Z_Left) 0.0)
    ((:Offset_10_Motor __Offset_10_Motor) 0.0)
    ((:Offset_11_Motor __Offset_11_Motor) 0.0)
    ((:Offset_12_Motor __Offset_12_Motor) 0.0)
    ((:Offset_13_Motor __Offset_13_Motor) 0.0)
    ((:Offset_14_Motor __Offset_14_Motor) 0.0)
    ((:Offset_15_Motor __Offset_15_Motor) 0.0)
    ((:Offset_16_Motor __Offset_16_Motor) 0.0)
    ((:Offset_17_Motor __Offset_17_Motor) 0.0)
    ((:Offset_18_Motor __Offset_18_Motor) 0.0)
    ((:Offset_19_Motor __Offset_19_Motor) 0.0)
    ((:Offset_20_Motor __Offset_20_Motor) 0.0)
    ((:Offset_21_Motor __Offset_21_Motor) 0.0)
    ((:Swing_Right_Leg __Swing_Right_Leg) 0.0)
    ((:Swing_Left_Leg __Swing_Left_Leg) 0.0)
    ((:Swing_Right_Shoulder __Swing_Right_Shoulder) 0.0)
    ((:Swing_Left_Shoulder __Swing_Left_Shoulder) 0.0)
    ((:Rise_Right_Leg __Rise_Right_Leg) 0.0)
    ((:Rise_Left_Leg __Rise_Left_Leg) 0.0)
    ((:Start_Entire_Time __Start_Entire_Time) 0.0)
    ((:Start_Swing __Start_Swing) 0.0)
    ((:Start_Rise __Start_Rise) 0.0)
    ((:End_Entire_Time __End_Entire_Time) 0.0)
    ((:End_Swing __End_Swing) 0.0)
    ((:End_Rise __End_Rise) 0.0)
    ((:Test_X __Test_X) 0.0)
    ((:Test_Side __Test_Side) 0.0)
    ((:Test_Yaw __Test_Yaw) 0.0)
    ((:Tuning_X __Tuning_X) 0.0)
    ((:Tuning_Side __Tuning_Side) 0.0)
    ((:Tuning_Yaw __Tuning_Yaw) 0.0)
    ((:Balance_Value_0 __Balance_Value_0) 0.0)
    ((:Balance_Value_1 __Balance_Value_1) 0.0)
    ((:Balance_Value_2 __Balance_Value_2) 0.0)
    ((:Balance_Value_3 __Balance_Value_3) 0.0)
    ((:Balance_Pitch_GP __Balance_Pitch_GP) 0.0)
    ((:Balance_Pitch_GI __Balance_Pitch_GI) 0.0)
    ((:Balance_Pitch_GD __Balance_Pitch_GD) 0.0)
    ((:Balance_Pitch_ELIMIT __Balance_Pitch_ELIMIT) 0.0)
    ((:Balance_Pitch_OLIMIT __Balance_Pitch_OLIMIT) 0.0)
    ((:Balance_Pitch_Neg_Target __Balance_Pitch_Neg_Target) 0.0)
    ((:Balance_Pitch_Pos_Target __Balance_Pitch_Pos_Target) 0.0)
    ((:Balance_Roll_GP __Balance_Roll_GP) 0.0)
    ((:Balance_Roll_GI __Balance_Roll_GI) 0.0)
    ((:Balance_Roll_GD __Balance_Roll_GD) 0.0)
    ((:Balance_Roll_ELIMIT __Balance_Roll_ELIMIT) 0.0)
    ((:Balance_Roll_OLIMIT __Balance_Roll_OLIMIT) 0.0)
    ((:Balance_Roll_Neg_Target __Balance_Roll_Neg_Target) 0.0)
    ((:Balance_Roll_Pos_Target __Balance_Roll_Pos_Target) 0.0)
    ((:Balance_Angle_Pitch_GP __Balance_Angle_Pitch_GP) 0.0)
    ((:Balance_Angle_Pitch_GI __Balance_Angle_Pitch_GI) 0.0)
    ((:Balance_Angle_Pitch_GD __Balance_Angle_Pitch_GD) 0.0)
    ((:Balance_Angle_Pitch_ELIMIT __Balance_Angle_Pitch_ELIMIT) 0.0)
    ((:Balance_Angle_Pitch_OLIMIT __Balance_Angle_Pitch_OLIMIT) 0.0)
    ((:Balance_Angle_Pitch_Neg_Target __Balance_Angle_Pitch_Neg_Target) 0.0)
    ((:Balance_Angle_Pitch_Pos_Target __Balance_Angle_Pitch_Pos_Target) 0.0)
    ((:Balance_Value_4 __Balance_Value_4) 0.0)
    ((:Balance_Value_5 __Balance_Value_5) 0.0)
    ((:Balance_Pitch_Flag_imu __Balance_Pitch_Flag_imu) 0)
    ((:Balance_Pitch_GP_imu __Balance_Pitch_GP_imu) 0.0)
    ((:Balance_Pitch_GI_imu __Balance_Pitch_GI_imu) 0.0)
    ((:Balance_Pitch_GD_imu __Balance_Pitch_GD_imu) 0.0)
    ((:Balance_Pitch_Neg_Target_imu __Balance_Pitch_Neg_Target_imu) 0.0)
    ((:Balance_Pitch_Pos_Target_imu __Balance_Pitch_Pos_Target_imu) 0.0)
    ((:Balance_Pitch_ELIMIT_imu __Balance_Pitch_ELIMIT_imu) 0.0)
    ((:Balance_Pitch_OLIMIT_imu __Balance_Pitch_OLIMIT_imu) 0.0)
    ((:Balance_Roll_Flag_imu __Balance_Roll_Flag_imu) 0)
    ((:Balance_Roll_GP_imu __Balance_Roll_GP_imu) 0.0)
    ((:Balance_Roll_GI_imu __Balance_Roll_GI_imu) 0.0)
    ((:Balance_Roll_GD_imu __Balance_Roll_GD_imu) 0.0)
    ((:Balance_Roll_Neg_Target_imu __Balance_Roll_Neg_Target_imu) 0.0)
    ((:Balance_Roll_Pos_Target_imu __Balance_Roll_Pos_Target_imu) 0.0)
    ((:Balance_Roll_ELIMIT_imu __Balance_Roll_ELIMIT_imu) 0.0)
    ((:Balance_Roll_OLIMIT_imu __Balance_Roll_OLIMIT_imu) 0.0)
    ((:Balance_Pitch_Flag __Balance_Pitch_Flag) 0)
    ((:Balance_Ankle_Pitch_Flag __Balance_Ankle_Pitch_Flag) 0)
    ((:Balance_Roll_Flag __Balance_Roll_Flag) 0)
    ((:Ratio_Check_Flag __Ratio_Check_Flag) 0)
    ((:Center2Leg __Center2Leg) 0.0)
    ((:Link2Link __Link2Link) 0.0)
    ((:Init_Z_Up __Init_Z_Up) 0.0)
    ((:Percentage_of_IK_10_Motor __Percentage_of_IK_10_Motor) 0.0)
    ((:Percentage_of_IK_11_Motor __Percentage_of_IK_11_Motor) 0.0)
    ((:Percentage_of_IK_12_Motor __Percentage_of_IK_12_Motor) 0.0)
    ((:Percentage_of_IK_13_Motor __Percentage_of_IK_13_Motor) 0.0)
    ((:Percentage_of_IK_14_Motor __Percentage_of_IK_14_Motor) 0.0)
    ((:Percentage_of_IK_15_Motor __Percentage_of_IK_15_Motor) 0.0)
    ((:Percentage_of_IK_16_Motor __Percentage_of_IK_16_Motor) 0.0)
    ((:Percentage_of_IK_17_Motor __Percentage_of_IK_17_Motor) 0.0)
    ((:Percentage_of_IK_18_Motor __Percentage_of_IK_18_Motor) 0.0)
    ((:Percentage_of_IK_19_Motor __Percentage_of_IK_19_Motor) 0.0)
    ((:Percentage_of_IK_20_Motor __Percentage_of_IK_20_Motor) 0.0)
    ((:Percentage_of_IK_21_Motor __Percentage_of_IK_21_Motor) 0.0)
    ((:First_Pos_XR __First_Pos_XR) 0.0)
    ((:First_Neg_XR __First_Neg_XR) 0.0)
    ((:First_Pos_SideR __First_Pos_SideR) 0.0)
    ((:First_Neg_SideR __First_Neg_SideR) 0.0)
    ((:First_Pos_YawR __First_Pos_YawR) 0.0)
    ((:First_Neg_YawR __First_Neg_YawR) 0.0)
    ((:First_Pos_XL __First_Pos_XL) 0.0)
    ((:First_Neg_XL __First_Neg_XL) 0.0)
    ((:First_Pos_SideL __First_Pos_SideL) 0.0)
    ((:First_Neg_SideL __First_Neg_SideL) 0.0)
    ((:First_Pos_YawL __First_Pos_YawL) 0.0)
    ((:First_Neg_YawL __First_Neg_YawL) 0.0)
    ((:First_Pos_SideR_SwingMinus __First_Pos_SideR_SwingMinus) 0.0)
    ((:First_Neg_SideR_SwingMinus __First_Neg_SideR_SwingMinus) 0.0)
    ((:First_Pos_SideL_SwingMinus __First_Pos_SideL_SwingMinus) 0.0)
    ((:First_Neg_SideL_SwingMinus __First_Neg_SideL_SwingMinus) 0.0)
    ((:First_min __First_min) 0)
    ((:First_max __First_max) 0)
    ((:Second_Pos_XR __Second_Pos_XR) 0.0)
    ((:Second_Neg_XR __Second_Neg_XR) 0.0)
    ((:Second_Pos_SideR __Second_Pos_SideR) 0.0)
    ((:Second_Neg_SideR __Second_Neg_SideR) 0.0)
    ((:Second_Pos_YawR __Second_Pos_YawR) 0.0)
    ((:Second_Neg_YawR __Second_Neg_YawR) 0.0)
    ((:Second_Pos_XL __Second_Pos_XL) 0.0)
    ((:Second_Neg_XL __Second_Neg_XL) 0.0)
    ((:Second_Pos_SideL __Second_Pos_SideL) 0.0)
    ((:Second_Neg_SideL __Second_Neg_SideL) 0.0)
    ((:Second_Pos_YawL __Second_Pos_YawL) 0.0)
    ((:Second_Neg_YawL __Second_Neg_YawL) 0.0)
    ((:Second_Pos_SideR_SwingMinus __Second_Pos_SideR_SwingMinus) 0.0)
    ((:Second_Neg_SideR_SwingMinus __Second_Neg_SideR_SwingMinus) 0.0)
    ((:Second_Pos_SideL_SwingMinus __Second_Pos_SideL_SwingMinus) 0.0)
    ((:Second_Neg_SideL_SwingMinus __Second_Neg_SideL_SwingMinus) 0.0)
    ((:Second_min __Second_min) 0)
    ((:Second_max __Second_max) 0)
    ((:Third_Pos_XR __Third_Pos_XR) 0.0)
    ((:Third_Neg_XR __Third_Neg_XR) 0.0)
    ((:Third_Pos_SideR __Third_Pos_SideR) 0.0)
    ((:Third_Neg_SideR __Third_Neg_SideR) 0.0)
    ((:Third_Pos_YawR __Third_Pos_YawR) 0.0)
    ((:Third_Neg_YawR __Third_Neg_YawR) 0.0)
    ((:Third_Pos_XL __Third_Pos_XL) 0.0)
    ((:Third_Neg_XL __Third_Neg_XL) 0.0)
    ((:Third_Pos_SideL __Third_Pos_SideL) 0.0)
    ((:Third_Neg_SideL __Third_Neg_SideL) 0.0)
    ((:Third_Pos_YawL __Third_Pos_YawL) 0.0)
    ((:Third_Neg_YawL __Third_Neg_YawL) 0.0)
    ((:Third_Pos_SideR_SwingMinus __Third_Pos_SideR_SwingMinus) 0.0)
    ((:Third_Neg_SideR_SwingMinus __Third_Neg_SideR_SwingMinus) 0.0)
    ((:Third_Pos_SideL_SwingMinus __Third_Pos_SideL_SwingMinus) 0.0)
    ((:Third_Neg_SideL_SwingMinus __Third_Neg_SideL_SwingMinus) 0.0)
    ((:Third_min __Third_min) 0)
    ((:Third_max __Third_max) 0)
    ((:Fourth_Pos_XR __Fourth_Pos_XR) 0.0)
    ((:Fourth_Neg_XR __Fourth_Neg_XR) 0.0)
    ((:Fourth_Pos_SideR __Fourth_Pos_SideR) 0.0)
    ((:Fourth_Neg_SideR __Fourth_Neg_SideR) 0.0)
    ((:Fourth_Pos_YawR __Fourth_Pos_YawR) 0.0)
    ((:Fourth_Neg_YawR __Fourth_Neg_YawR) 0.0)
    ((:Fourth_Pos_XL __Fourth_Pos_XL) 0.0)
    ((:Fourth_Neg_XL __Fourth_Neg_XL) 0.0)
    ((:Fourth_Pos_SideL __Fourth_Pos_SideL) 0.0)
    ((:Fourth_Neg_SideL __Fourth_Neg_SideL) 0.0)
    ((:Fourth_Pos_YawL __Fourth_Pos_YawL) 0.0)
    ((:Fourth_Neg_YawL __Fourth_Neg_YawL) 0.0)
    ((:Fourth_Pos_SideR_SwingMinus __Fourth_Pos_SideR_SwingMinus) 0.0)
    ((:Fourth_Neg_SideR_SwingMinus __Fourth_Neg_SideR_SwingMinus) 0.0)
    ((:Fourth_Pos_SideL_SwingMinus __Fourth_Pos_SideL_SwingMinus) 0.0)
    ((:Fourth_Neg_SideL_SwingMinus __Fourth_Neg_SideL_SwingMinus) 0.0)
    ((:Fourth_min __Fourth_min) 0)
    ((:Fourth_max __Fourth_max) 0)
    ((:Landing_Time_Control_flag __Landing_Time_Control_flag) 0)
    ((:Control_System_flag __Control_System_flag) 0)
    )
   (send-super :init)
   (setq _IK_Flag __IK_Flag)
   (setq _Entire_Time (float __Entire_Time))
   (setq _Frequency (float __Frequency))
   (setq _Default_X_Right (float __Default_X_Right))
   (setq _Default_X_Left (float __Default_X_Left))
   (setq _Default_Y_Right (float __Default_Y_Right))
   (setq _Default_Y_Left (float __Default_Y_Left))
   (setq _Default_Z_Right (float __Default_Z_Right))
   (setq _Default_Z_Left (float __Default_Z_Left))
   (setq _Offset_10_Motor (float __Offset_10_Motor))
   (setq _Offset_11_Motor (float __Offset_11_Motor))
   (setq _Offset_12_Motor (float __Offset_12_Motor))
   (setq _Offset_13_Motor (float __Offset_13_Motor))
   (setq _Offset_14_Motor (float __Offset_14_Motor))
   (setq _Offset_15_Motor (float __Offset_15_Motor))
   (setq _Offset_16_Motor (float __Offset_16_Motor))
   (setq _Offset_17_Motor (float __Offset_17_Motor))
   (setq _Offset_18_Motor (float __Offset_18_Motor))
   (setq _Offset_19_Motor (float __Offset_19_Motor))
   (setq _Offset_20_Motor (float __Offset_20_Motor))
   (setq _Offset_21_Motor (float __Offset_21_Motor))
   (setq _Swing_Right_Leg (float __Swing_Right_Leg))
   (setq _Swing_Left_Leg (float __Swing_Left_Leg))
   (setq _Swing_Right_Shoulder (float __Swing_Right_Shoulder))
   (setq _Swing_Left_Shoulder (float __Swing_Left_Shoulder))
   (setq _Rise_Right_Leg (float __Rise_Right_Leg))
   (setq _Rise_Left_Leg (float __Rise_Left_Leg))
   (setq _Start_Entire_Time (float __Start_Entire_Time))
   (setq _Start_Swing (float __Start_Swing))
   (setq _Start_Rise (float __Start_Rise))
   (setq _End_Entire_Time (float __End_Entire_Time))
   (setq _End_Swing (float __End_Swing))
   (setq _End_Rise (float __End_Rise))
   (setq _Test_X (float __Test_X))
   (setq _Test_Side (float __Test_Side))
   (setq _Test_Yaw (float __Test_Yaw))
   (setq _Tuning_X (float __Tuning_X))
   (setq _Tuning_Side (float __Tuning_Side))
   (setq _Tuning_Yaw (float __Tuning_Yaw))
   (setq _Balance_Value_0 (float __Balance_Value_0))
   (setq _Balance_Value_1 (float __Balance_Value_1))
   (setq _Balance_Value_2 (float __Balance_Value_2))
   (setq _Balance_Value_3 (float __Balance_Value_3))
   (setq _Balance_Pitch_GP (float __Balance_Pitch_GP))
   (setq _Balance_Pitch_GI (float __Balance_Pitch_GI))
   (setq _Balance_Pitch_GD (float __Balance_Pitch_GD))
   (setq _Balance_Pitch_ELIMIT (float __Balance_Pitch_ELIMIT))
   (setq _Balance_Pitch_OLIMIT (float __Balance_Pitch_OLIMIT))
   (setq _Balance_Pitch_Neg_Target (float __Balance_Pitch_Neg_Target))
   (setq _Balance_Pitch_Pos_Target (float __Balance_Pitch_Pos_Target))
   (setq _Balance_Roll_GP (float __Balance_Roll_GP))
   (setq _Balance_Roll_GI (float __Balance_Roll_GI))
   (setq _Balance_Roll_GD (float __Balance_Roll_GD))
   (setq _Balance_Roll_ELIMIT (float __Balance_Roll_ELIMIT))
   (setq _Balance_Roll_OLIMIT (float __Balance_Roll_OLIMIT))
   (setq _Balance_Roll_Neg_Target (float __Balance_Roll_Neg_Target))
   (setq _Balance_Roll_Pos_Target (float __Balance_Roll_Pos_Target))
   (setq _Balance_Angle_Pitch_GP (float __Balance_Angle_Pitch_GP))
   (setq _Balance_Angle_Pitch_GI (float __Balance_Angle_Pitch_GI))
   (setq _Balance_Angle_Pitch_GD (float __Balance_Angle_Pitch_GD))
   (setq _Balance_Angle_Pitch_ELIMIT (float __Balance_Angle_Pitch_ELIMIT))
   (setq _Balance_Angle_Pitch_OLIMIT (float __Balance_Angle_Pitch_OLIMIT))
   (setq _Balance_Angle_Pitch_Neg_Target (float __Balance_Angle_Pitch_Neg_Target))
   (setq _Balance_Angle_Pitch_Pos_Target (float __Balance_Angle_Pitch_Pos_Target))
   (setq _Balance_Value_4 (float __Balance_Value_4))
   (setq _Balance_Value_5 (float __Balance_Value_5))
   (setq _Balance_Pitch_Flag_imu (round __Balance_Pitch_Flag_imu))
   (setq _Balance_Pitch_GP_imu (float __Balance_Pitch_GP_imu))
   (setq _Balance_Pitch_GI_imu (float __Balance_Pitch_GI_imu))
   (setq _Balance_Pitch_GD_imu (float __Balance_Pitch_GD_imu))
   (setq _Balance_Pitch_Neg_Target_imu (float __Balance_Pitch_Neg_Target_imu))
   (setq _Balance_Pitch_Pos_Target_imu (float __Balance_Pitch_Pos_Target_imu))
   (setq _Balance_Pitch_ELIMIT_imu (float __Balance_Pitch_ELIMIT_imu))
   (setq _Balance_Pitch_OLIMIT_imu (float __Balance_Pitch_OLIMIT_imu))
   (setq _Balance_Roll_Flag_imu (round __Balance_Roll_Flag_imu))
   (setq _Balance_Roll_GP_imu (float __Balance_Roll_GP_imu))
   (setq _Balance_Roll_GI_imu (float __Balance_Roll_GI_imu))
   (setq _Balance_Roll_GD_imu (float __Balance_Roll_GD_imu))
   (setq _Balance_Roll_Neg_Target_imu (float __Balance_Roll_Neg_Target_imu))
   (setq _Balance_Roll_Pos_Target_imu (float __Balance_Roll_Pos_Target_imu))
   (setq _Balance_Roll_ELIMIT_imu (float __Balance_Roll_ELIMIT_imu))
   (setq _Balance_Roll_OLIMIT_imu (float __Balance_Roll_OLIMIT_imu))
   (setq _Balance_Pitch_Flag (round __Balance_Pitch_Flag))
   (setq _Balance_Ankle_Pitch_Flag (round __Balance_Ankle_Pitch_Flag))
   (setq _Balance_Roll_Flag (round __Balance_Roll_Flag))
   (setq _Ratio_Check_Flag (round __Ratio_Check_Flag))
   (setq _Center2Leg (float __Center2Leg))
   (setq _Link2Link (float __Link2Link))
   (setq _Init_Z_Up (float __Init_Z_Up))
   (setq _Percentage_of_IK_10_Motor (float __Percentage_of_IK_10_Motor))
   (setq _Percentage_of_IK_11_Motor (float __Percentage_of_IK_11_Motor))
   (setq _Percentage_of_IK_12_Motor (float __Percentage_of_IK_12_Motor))
   (setq _Percentage_of_IK_13_Motor (float __Percentage_of_IK_13_Motor))
   (setq _Percentage_of_IK_14_Motor (float __Percentage_of_IK_14_Motor))
   (setq _Percentage_of_IK_15_Motor (float __Percentage_of_IK_15_Motor))
   (setq _Percentage_of_IK_16_Motor (float __Percentage_of_IK_16_Motor))
   (setq _Percentage_of_IK_17_Motor (float __Percentage_of_IK_17_Motor))
   (setq _Percentage_of_IK_18_Motor (float __Percentage_of_IK_18_Motor))
   (setq _Percentage_of_IK_19_Motor (float __Percentage_of_IK_19_Motor))
   (setq _Percentage_of_IK_20_Motor (float __Percentage_of_IK_20_Motor))
   (setq _Percentage_of_IK_21_Motor (float __Percentage_of_IK_21_Motor))
   (setq _First_Pos_XR (float __First_Pos_XR))
   (setq _First_Neg_XR (float __First_Neg_XR))
   (setq _First_Pos_SideR (float __First_Pos_SideR))
   (setq _First_Neg_SideR (float __First_Neg_SideR))
   (setq _First_Pos_YawR (float __First_Pos_YawR))
   (setq _First_Neg_YawR (float __First_Neg_YawR))
   (setq _First_Pos_XL (float __First_Pos_XL))
   (setq _First_Neg_XL (float __First_Neg_XL))
   (setq _First_Pos_SideL (float __First_Pos_SideL))
   (setq _First_Neg_SideL (float __First_Neg_SideL))
   (setq _First_Pos_YawL (float __First_Pos_YawL))
   (setq _First_Neg_YawL (float __First_Neg_YawL))
   (setq _First_Pos_SideR_SwingMinus (float __First_Pos_SideR_SwingMinus))
   (setq _First_Neg_SideR_SwingMinus (float __First_Neg_SideR_SwingMinus))
   (setq _First_Pos_SideL_SwingMinus (float __First_Pos_SideL_SwingMinus))
   (setq _First_Neg_SideL_SwingMinus (float __First_Neg_SideL_SwingMinus))
   (setq _First_min (round __First_min))
   (setq _First_max (round __First_max))
   (setq _Second_Pos_XR (float __Second_Pos_XR))
   (setq _Second_Neg_XR (float __Second_Neg_XR))
   (setq _Second_Pos_SideR (float __Second_Pos_SideR))
   (setq _Second_Neg_SideR (float __Second_Neg_SideR))
   (setq _Second_Pos_YawR (float __Second_Pos_YawR))
   (setq _Second_Neg_YawR (float __Second_Neg_YawR))
   (setq _Second_Pos_XL (float __Second_Pos_XL))
   (setq _Second_Neg_XL (float __Second_Neg_XL))
   (setq _Second_Pos_SideL (float __Second_Pos_SideL))
   (setq _Second_Neg_SideL (float __Second_Neg_SideL))
   (setq _Second_Pos_YawL (float __Second_Pos_YawL))
   (setq _Second_Neg_YawL (float __Second_Neg_YawL))
   (setq _Second_Pos_SideR_SwingMinus (float __Second_Pos_SideR_SwingMinus))
   (setq _Second_Neg_SideR_SwingMinus (float __Second_Neg_SideR_SwingMinus))
   (setq _Second_Pos_SideL_SwingMinus (float __Second_Pos_SideL_SwingMinus))
   (setq _Second_Neg_SideL_SwingMinus (float __Second_Neg_SideL_SwingMinus))
   (setq _Second_min (round __Second_min))
   (setq _Second_max (round __Second_max))
   (setq _Third_Pos_XR (float __Third_Pos_XR))
   (setq _Third_Neg_XR (float __Third_Neg_XR))
   (setq _Third_Pos_SideR (float __Third_Pos_SideR))
   (setq _Third_Neg_SideR (float __Third_Neg_SideR))
   (setq _Third_Pos_YawR (float __Third_Pos_YawR))
   (setq _Third_Neg_YawR (float __Third_Neg_YawR))
   (setq _Third_Pos_XL (float __Third_Pos_XL))
   (setq _Third_Neg_XL (float __Third_Neg_XL))
   (setq _Third_Pos_SideL (float __Third_Pos_SideL))
   (setq _Third_Neg_SideL (float __Third_Neg_SideL))
   (setq _Third_Pos_YawL (float __Third_Pos_YawL))
   (setq _Third_Neg_YawL (float __Third_Neg_YawL))
   (setq _Third_Pos_SideR_SwingMinus (float __Third_Pos_SideR_SwingMinus))
   (setq _Third_Neg_SideR_SwingMinus (float __Third_Neg_SideR_SwingMinus))
   (setq _Third_Pos_SideL_SwingMinus (float __Third_Pos_SideL_SwingMinus))
   (setq _Third_Neg_SideL_SwingMinus (float __Third_Neg_SideL_SwingMinus))
   (setq _Third_min (round __Third_min))
   (setq _Third_max (round __Third_max))
   (setq _Fourth_Pos_XR (float __Fourth_Pos_XR))
   (setq _Fourth_Neg_XR (float __Fourth_Neg_XR))
   (setq _Fourth_Pos_SideR (float __Fourth_Pos_SideR))
   (setq _Fourth_Neg_SideR (float __Fourth_Neg_SideR))
   (setq _Fourth_Pos_YawR (float __Fourth_Pos_YawR))
   (setq _Fourth_Neg_YawR (float __Fourth_Neg_YawR))
   (setq _Fourth_Pos_XL (float __Fourth_Pos_XL))
   (setq _Fourth_Neg_XL (float __Fourth_Neg_XL))
   (setq _Fourth_Pos_SideL (float __Fourth_Pos_SideL))
   (setq _Fourth_Neg_SideL (float __Fourth_Neg_SideL))
   (setq _Fourth_Pos_YawL (float __Fourth_Pos_YawL))
   (setq _Fourth_Neg_YawL (float __Fourth_Neg_YawL))
   (setq _Fourth_Pos_SideR_SwingMinus (float __Fourth_Pos_SideR_SwingMinus))
   (setq _Fourth_Neg_SideR_SwingMinus (float __Fourth_Neg_SideR_SwingMinus))
   (setq _Fourth_Pos_SideL_SwingMinus (float __Fourth_Pos_SideL_SwingMinus))
   (setq _Fourth_Neg_SideL_SwingMinus (float __Fourth_Neg_SideL_SwingMinus))
   (setq _Fourth_min (round __Fourth_min))
   (setq _Fourth_max (round __Fourth_max))
   (setq _Landing_Time_Control_flag (round __Landing_Time_Control_flag))
   (setq _Control_System_flag (round __Control_System_flag))
   self)
  (:IK_Flag
   (&optional __IK_Flag)
   (if __IK_Flag (setq _IK_Flag __IK_Flag)) _IK_Flag)
  (:Entire_Time
   (&optional __Entire_Time)
   (if __Entire_Time (setq _Entire_Time __Entire_Time)) _Entire_Time)
  (:Frequency
   (&optional __Frequency)
   (if __Frequency (setq _Frequency __Frequency)) _Frequency)
  (:Default_X_Right
   (&optional __Default_X_Right)
   (if __Default_X_Right (setq _Default_X_Right __Default_X_Right)) _Default_X_Right)
  (:Default_X_Left
   (&optional __Default_X_Left)
   (if __Default_X_Left (setq _Default_X_Left __Default_X_Left)) _Default_X_Left)
  (:Default_Y_Right
   (&optional __Default_Y_Right)
   (if __Default_Y_Right (setq _Default_Y_Right __Default_Y_Right)) _Default_Y_Right)
  (:Default_Y_Left
   (&optional __Default_Y_Left)
   (if __Default_Y_Left (setq _Default_Y_Left __Default_Y_Left)) _Default_Y_Left)
  (:Default_Z_Right
   (&optional __Default_Z_Right)
   (if __Default_Z_Right (setq _Default_Z_Right __Default_Z_Right)) _Default_Z_Right)
  (:Default_Z_Left
   (&optional __Default_Z_Left)
   (if __Default_Z_Left (setq _Default_Z_Left __Default_Z_Left)) _Default_Z_Left)
  (:Offset_10_Motor
   (&optional __Offset_10_Motor)
   (if __Offset_10_Motor (setq _Offset_10_Motor __Offset_10_Motor)) _Offset_10_Motor)
  (:Offset_11_Motor
   (&optional __Offset_11_Motor)
   (if __Offset_11_Motor (setq _Offset_11_Motor __Offset_11_Motor)) _Offset_11_Motor)
  (:Offset_12_Motor
   (&optional __Offset_12_Motor)
   (if __Offset_12_Motor (setq _Offset_12_Motor __Offset_12_Motor)) _Offset_12_Motor)
  (:Offset_13_Motor
   (&optional __Offset_13_Motor)
   (if __Offset_13_Motor (setq _Offset_13_Motor __Offset_13_Motor)) _Offset_13_Motor)
  (:Offset_14_Motor
   (&optional __Offset_14_Motor)
   (if __Offset_14_Motor (setq _Offset_14_Motor __Offset_14_Motor)) _Offset_14_Motor)
  (:Offset_15_Motor
   (&optional __Offset_15_Motor)
   (if __Offset_15_Motor (setq _Offset_15_Motor __Offset_15_Motor)) _Offset_15_Motor)
  (:Offset_16_Motor
   (&optional __Offset_16_Motor)
   (if __Offset_16_Motor (setq _Offset_16_Motor __Offset_16_Motor)) _Offset_16_Motor)
  (:Offset_17_Motor
   (&optional __Offset_17_Motor)
   (if __Offset_17_Motor (setq _Offset_17_Motor __Offset_17_Motor)) _Offset_17_Motor)
  (:Offset_18_Motor
   (&optional __Offset_18_Motor)
   (if __Offset_18_Motor (setq _Offset_18_Motor __Offset_18_Motor)) _Offset_18_Motor)
  (:Offset_19_Motor
   (&optional __Offset_19_Motor)
   (if __Offset_19_Motor (setq _Offset_19_Motor __Offset_19_Motor)) _Offset_19_Motor)
  (:Offset_20_Motor
   (&optional __Offset_20_Motor)
   (if __Offset_20_Motor (setq _Offset_20_Motor __Offset_20_Motor)) _Offset_20_Motor)
  (:Offset_21_Motor
   (&optional __Offset_21_Motor)
   (if __Offset_21_Motor (setq _Offset_21_Motor __Offset_21_Motor)) _Offset_21_Motor)
  (:Swing_Right_Leg
   (&optional __Swing_Right_Leg)
   (if __Swing_Right_Leg (setq _Swing_Right_Leg __Swing_Right_Leg)) _Swing_Right_Leg)
  (:Swing_Left_Leg
   (&optional __Swing_Left_Leg)
   (if __Swing_Left_Leg (setq _Swing_Left_Leg __Swing_Left_Leg)) _Swing_Left_Leg)
  (:Swing_Right_Shoulder
   (&optional __Swing_Right_Shoulder)
   (if __Swing_Right_Shoulder (setq _Swing_Right_Shoulder __Swing_Right_Shoulder)) _Swing_Right_Shoulder)
  (:Swing_Left_Shoulder
   (&optional __Swing_Left_Shoulder)
   (if __Swing_Left_Shoulder (setq _Swing_Left_Shoulder __Swing_Left_Shoulder)) _Swing_Left_Shoulder)
  (:Rise_Right_Leg
   (&optional __Rise_Right_Leg)
   (if __Rise_Right_Leg (setq _Rise_Right_Leg __Rise_Right_Leg)) _Rise_Right_Leg)
  (:Rise_Left_Leg
   (&optional __Rise_Left_Leg)
   (if __Rise_Left_Leg (setq _Rise_Left_Leg __Rise_Left_Leg)) _Rise_Left_Leg)
  (:Start_Entire_Time
   (&optional __Start_Entire_Time)
   (if __Start_Entire_Time (setq _Start_Entire_Time __Start_Entire_Time)) _Start_Entire_Time)
  (:Start_Swing
   (&optional __Start_Swing)
   (if __Start_Swing (setq _Start_Swing __Start_Swing)) _Start_Swing)
  (:Start_Rise
   (&optional __Start_Rise)
   (if __Start_Rise (setq _Start_Rise __Start_Rise)) _Start_Rise)
  (:End_Entire_Time
   (&optional __End_Entire_Time)
   (if __End_Entire_Time (setq _End_Entire_Time __End_Entire_Time)) _End_Entire_Time)
  (:End_Swing
   (&optional __End_Swing)
   (if __End_Swing (setq _End_Swing __End_Swing)) _End_Swing)
  (:End_Rise
   (&optional __End_Rise)
   (if __End_Rise (setq _End_Rise __End_Rise)) _End_Rise)
  (:Test_X
   (&optional __Test_X)
   (if __Test_X (setq _Test_X __Test_X)) _Test_X)
  (:Test_Side
   (&optional __Test_Side)
   (if __Test_Side (setq _Test_Side __Test_Side)) _Test_Side)
  (:Test_Yaw
   (&optional __Test_Yaw)
   (if __Test_Yaw (setq _Test_Yaw __Test_Yaw)) _Test_Yaw)
  (:Tuning_X
   (&optional __Tuning_X)
   (if __Tuning_X (setq _Tuning_X __Tuning_X)) _Tuning_X)
  (:Tuning_Side
   (&optional __Tuning_Side)
   (if __Tuning_Side (setq _Tuning_Side __Tuning_Side)) _Tuning_Side)
  (:Tuning_Yaw
   (&optional __Tuning_Yaw)
   (if __Tuning_Yaw (setq _Tuning_Yaw __Tuning_Yaw)) _Tuning_Yaw)
  (:Balance_Value_0
   (&optional __Balance_Value_0)
   (if __Balance_Value_0 (setq _Balance_Value_0 __Balance_Value_0)) _Balance_Value_0)
  (:Balance_Value_1
   (&optional __Balance_Value_1)
   (if __Balance_Value_1 (setq _Balance_Value_1 __Balance_Value_1)) _Balance_Value_1)
  (:Balance_Value_2
   (&optional __Balance_Value_2)
   (if __Balance_Value_2 (setq _Balance_Value_2 __Balance_Value_2)) _Balance_Value_2)
  (:Balance_Value_3
   (&optional __Balance_Value_3)
   (if __Balance_Value_3 (setq _Balance_Value_3 __Balance_Value_3)) _Balance_Value_3)
  (:Balance_Pitch_GP
   (&optional __Balance_Pitch_GP)
   (if __Balance_Pitch_GP (setq _Balance_Pitch_GP __Balance_Pitch_GP)) _Balance_Pitch_GP)
  (:Balance_Pitch_GI
   (&optional __Balance_Pitch_GI)
   (if __Balance_Pitch_GI (setq _Balance_Pitch_GI __Balance_Pitch_GI)) _Balance_Pitch_GI)
  (:Balance_Pitch_GD
   (&optional __Balance_Pitch_GD)
   (if __Balance_Pitch_GD (setq _Balance_Pitch_GD __Balance_Pitch_GD)) _Balance_Pitch_GD)
  (:Balance_Pitch_ELIMIT
   (&optional __Balance_Pitch_ELIMIT)
   (if __Balance_Pitch_ELIMIT (setq _Balance_Pitch_ELIMIT __Balance_Pitch_ELIMIT)) _Balance_Pitch_ELIMIT)
  (:Balance_Pitch_OLIMIT
   (&optional __Balance_Pitch_OLIMIT)
   (if __Balance_Pitch_OLIMIT (setq _Balance_Pitch_OLIMIT __Balance_Pitch_OLIMIT)) _Balance_Pitch_OLIMIT)
  (:Balance_Pitch_Neg_Target
   (&optional __Balance_Pitch_Neg_Target)
   (if __Balance_Pitch_Neg_Target (setq _Balance_Pitch_Neg_Target __Balance_Pitch_Neg_Target)) _Balance_Pitch_Neg_Target)
  (:Balance_Pitch_Pos_Target
   (&optional __Balance_Pitch_Pos_Target)
   (if __Balance_Pitch_Pos_Target (setq _Balance_Pitch_Pos_Target __Balance_Pitch_Pos_Target)) _Balance_Pitch_Pos_Target)
  (:Balance_Roll_GP
   (&optional __Balance_Roll_GP)
   (if __Balance_Roll_GP (setq _Balance_Roll_GP __Balance_Roll_GP)) _Balance_Roll_GP)
  (:Balance_Roll_GI
   (&optional __Balance_Roll_GI)
   (if __Balance_Roll_GI (setq _Balance_Roll_GI __Balance_Roll_GI)) _Balance_Roll_GI)
  (:Balance_Roll_GD
   (&optional __Balance_Roll_GD)
   (if __Balance_Roll_GD (setq _Balance_Roll_GD __Balance_Roll_GD)) _Balance_Roll_GD)
  (:Balance_Roll_ELIMIT
   (&optional __Balance_Roll_ELIMIT)
   (if __Balance_Roll_ELIMIT (setq _Balance_Roll_ELIMIT __Balance_Roll_ELIMIT)) _Balance_Roll_ELIMIT)
  (:Balance_Roll_OLIMIT
   (&optional __Balance_Roll_OLIMIT)
   (if __Balance_Roll_OLIMIT (setq _Balance_Roll_OLIMIT __Balance_Roll_OLIMIT)) _Balance_Roll_OLIMIT)
  (:Balance_Roll_Neg_Target
   (&optional __Balance_Roll_Neg_Target)
   (if __Balance_Roll_Neg_Target (setq _Balance_Roll_Neg_Target __Balance_Roll_Neg_Target)) _Balance_Roll_Neg_Target)
  (:Balance_Roll_Pos_Target
   (&optional __Balance_Roll_Pos_Target)
   (if __Balance_Roll_Pos_Target (setq _Balance_Roll_Pos_Target __Balance_Roll_Pos_Target)) _Balance_Roll_Pos_Target)
  (:Balance_Angle_Pitch_GP
   (&optional __Balance_Angle_Pitch_GP)
   (if __Balance_Angle_Pitch_GP (setq _Balance_Angle_Pitch_GP __Balance_Angle_Pitch_GP)) _Balance_Angle_Pitch_GP)
  (:Balance_Angle_Pitch_GI
   (&optional __Balance_Angle_Pitch_GI)
   (if __Balance_Angle_Pitch_GI (setq _Balance_Angle_Pitch_GI __Balance_Angle_Pitch_GI)) _Balance_Angle_Pitch_GI)
  (:Balance_Angle_Pitch_GD
   (&optional __Balance_Angle_Pitch_GD)
   (if __Balance_Angle_Pitch_GD (setq _Balance_Angle_Pitch_GD __Balance_Angle_Pitch_GD)) _Balance_Angle_Pitch_GD)
  (:Balance_Angle_Pitch_ELIMIT
   (&optional __Balance_Angle_Pitch_ELIMIT)
   (if __Balance_Angle_Pitch_ELIMIT (setq _Balance_Angle_Pitch_ELIMIT __Balance_Angle_Pitch_ELIMIT)) _Balance_Angle_Pitch_ELIMIT)
  (:Balance_Angle_Pitch_OLIMIT
   (&optional __Balance_Angle_Pitch_OLIMIT)
   (if __Balance_Angle_Pitch_OLIMIT (setq _Balance_Angle_Pitch_OLIMIT __Balance_Angle_Pitch_OLIMIT)) _Balance_Angle_Pitch_OLIMIT)
  (:Balance_Angle_Pitch_Neg_Target
   (&optional __Balance_Angle_Pitch_Neg_Target)
   (if __Balance_Angle_Pitch_Neg_Target (setq _Balance_Angle_Pitch_Neg_Target __Balance_Angle_Pitch_Neg_Target)) _Balance_Angle_Pitch_Neg_Target)
  (:Balance_Angle_Pitch_Pos_Target
   (&optional __Balance_Angle_Pitch_Pos_Target)
   (if __Balance_Angle_Pitch_Pos_Target (setq _Balance_Angle_Pitch_Pos_Target __Balance_Angle_Pitch_Pos_Target)) _Balance_Angle_Pitch_Pos_Target)
  (:Balance_Value_4
   (&optional __Balance_Value_4)
   (if __Balance_Value_4 (setq _Balance_Value_4 __Balance_Value_4)) _Balance_Value_4)
  (:Balance_Value_5
   (&optional __Balance_Value_5)
   (if __Balance_Value_5 (setq _Balance_Value_5 __Balance_Value_5)) _Balance_Value_5)
  (:Balance_Pitch_Flag_imu
   (&optional __Balance_Pitch_Flag_imu)
   (if __Balance_Pitch_Flag_imu (setq _Balance_Pitch_Flag_imu __Balance_Pitch_Flag_imu)) _Balance_Pitch_Flag_imu)
  (:Balance_Pitch_GP_imu
   (&optional __Balance_Pitch_GP_imu)
   (if __Balance_Pitch_GP_imu (setq _Balance_Pitch_GP_imu __Balance_Pitch_GP_imu)) _Balance_Pitch_GP_imu)
  (:Balance_Pitch_GI_imu
   (&optional __Balance_Pitch_GI_imu)
   (if __Balance_Pitch_GI_imu (setq _Balance_Pitch_GI_imu __Balance_Pitch_GI_imu)) _Balance_Pitch_GI_imu)
  (:Balance_Pitch_GD_imu
   (&optional __Balance_Pitch_GD_imu)
   (if __Balance_Pitch_GD_imu (setq _Balance_Pitch_GD_imu __Balance_Pitch_GD_imu)) _Balance_Pitch_GD_imu)
  (:Balance_Pitch_Neg_Target_imu
   (&optional __Balance_Pitch_Neg_Target_imu)
   (if __Balance_Pitch_Neg_Target_imu (setq _Balance_Pitch_Neg_Target_imu __Balance_Pitch_Neg_Target_imu)) _Balance_Pitch_Neg_Target_imu)
  (:Balance_Pitch_Pos_Target_imu
   (&optional __Balance_Pitch_Pos_Target_imu)
   (if __Balance_Pitch_Pos_Target_imu (setq _Balance_Pitch_Pos_Target_imu __Balance_Pitch_Pos_Target_imu)) _Balance_Pitch_Pos_Target_imu)
  (:Balance_Pitch_ELIMIT_imu
   (&optional __Balance_Pitch_ELIMIT_imu)
   (if __Balance_Pitch_ELIMIT_imu (setq _Balance_Pitch_ELIMIT_imu __Balance_Pitch_ELIMIT_imu)) _Balance_Pitch_ELIMIT_imu)
  (:Balance_Pitch_OLIMIT_imu
   (&optional __Balance_Pitch_OLIMIT_imu)
   (if __Balance_Pitch_OLIMIT_imu (setq _Balance_Pitch_OLIMIT_imu __Balance_Pitch_OLIMIT_imu)) _Balance_Pitch_OLIMIT_imu)
  (:Balance_Roll_Flag_imu
   (&optional __Balance_Roll_Flag_imu)
   (if __Balance_Roll_Flag_imu (setq _Balance_Roll_Flag_imu __Balance_Roll_Flag_imu)) _Balance_Roll_Flag_imu)
  (:Balance_Roll_GP_imu
   (&optional __Balance_Roll_GP_imu)
   (if __Balance_Roll_GP_imu (setq _Balance_Roll_GP_imu __Balance_Roll_GP_imu)) _Balance_Roll_GP_imu)
  (:Balance_Roll_GI_imu
   (&optional __Balance_Roll_GI_imu)
   (if __Balance_Roll_GI_imu (setq _Balance_Roll_GI_imu __Balance_Roll_GI_imu)) _Balance_Roll_GI_imu)
  (:Balance_Roll_GD_imu
   (&optional __Balance_Roll_GD_imu)
   (if __Balance_Roll_GD_imu (setq _Balance_Roll_GD_imu __Balance_Roll_GD_imu)) _Balance_Roll_GD_imu)
  (:Balance_Roll_Neg_Target_imu
   (&optional __Balance_Roll_Neg_Target_imu)
   (if __Balance_Roll_Neg_Target_imu (setq _Balance_Roll_Neg_Target_imu __Balance_Roll_Neg_Target_imu)) _Balance_Roll_Neg_Target_imu)
  (:Balance_Roll_Pos_Target_imu
   (&optional __Balance_Roll_Pos_Target_imu)
   (if __Balance_Roll_Pos_Target_imu (setq _Balance_Roll_Pos_Target_imu __Balance_Roll_Pos_Target_imu)) _Balance_Roll_Pos_Target_imu)
  (:Balance_Roll_ELIMIT_imu
   (&optional __Balance_Roll_ELIMIT_imu)
   (if __Balance_Roll_ELIMIT_imu (setq _Balance_Roll_ELIMIT_imu __Balance_Roll_ELIMIT_imu)) _Balance_Roll_ELIMIT_imu)
  (:Balance_Roll_OLIMIT_imu
   (&optional __Balance_Roll_OLIMIT_imu)
   (if __Balance_Roll_OLIMIT_imu (setq _Balance_Roll_OLIMIT_imu __Balance_Roll_OLIMIT_imu)) _Balance_Roll_OLIMIT_imu)
  (:Balance_Pitch_Flag
   (&optional __Balance_Pitch_Flag)
   (if __Balance_Pitch_Flag (setq _Balance_Pitch_Flag __Balance_Pitch_Flag)) _Balance_Pitch_Flag)
  (:Balance_Ankle_Pitch_Flag
   (&optional __Balance_Ankle_Pitch_Flag)
   (if __Balance_Ankle_Pitch_Flag (setq _Balance_Ankle_Pitch_Flag __Balance_Ankle_Pitch_Flag)) _Balance_Ankle_Pitch_Flag)
  (:Balance_Roll_Flag
   (&optional __Balance_Roll_Flag)
   (if __Balance_Roll_Flag (setq _Balance_Roll_Flag __Balance_Roll_Flag)) _Balance_Roll_Flag)
  (:Ratio_Check_Flag
   (&optional __Ratio_Check_Flag)
   (if __Ratio_Check_Flag (setq _Ratio_Check_Flag __Ratio_Check_Flag)) _Ratio_Check_Flag)
  (:Center2Leg
   (&optional __Center2Leg)
   (if __Center2Leg (setq _Center2Leg __Center2Leg)) _Center2Leg)
  (:Link2Link
   (&optional __Link2Link)
   (if __Link2Link (setq _Link2Link __Link2Link)) _Link2Link)
  (:Init_Z_Up
   (&optional __Init_Z_Up)
   (if __Init_Z_Up (setq _Init_Z_Up __Init_Z_Up)) _Init_Z_Up)
  (:Percentage_of_IK_10_Motor
   (&optional __Percentage_of_IK_10_Motor)
   (if __Percentage_of_IK_10_Motor (setq _Percentage_of_IK_10_Motor __Percentage_of_IK_10_Motor)) _Percentage_of_IK_10_Motor)
  (:Percentage_of_IK_11_Motor
   (&optional __Percentage_of_IK_11_Motor)
   (if __Percentage_of_IK_11_Motor (setq _Percentage_of_IK_11_Motor __Percentage_of_IK_11_Motor)) _Percentage_of_IK_11_Motor)
  (:Percentage_of_IK_12_Motor
   (&optional __Percentage_of_IK_12_Motor)
   (if __Percentage_of_IK_12_Motor (setq _Percentage_of_IK_12_Motor __Percentage_of_IK_12_Motor)) _Percentage_of_IK_12_Motor)
  (:Percentage_of_IK_13_Motor
   (&optional __Percentage_of_IK_13_Motor)
   (if __Percentage_of_IK_13_Motor (setq _Percentage_of_IK_13_Motor __Percentage_of_IK_13_Motor)) _Percentage_of_IK_13_Motor)
  (:Percentage_of_IK_14_Motor
   (&optional __Percentage_of_IK_14_Motor)
   (if __Percentage_of_IK_14_Motor (setq _Percentage_of_IK_14_Motor __Percentage_of_IK_14_Motor)) _Percentage_of_IK_14_Motor)
  (:Percentage_of_IK_15_Motor
   (&optional __Percentage_of_IK_15_Motor)
   (if __Percentage_of_IK_15_Motor (setq _Percentage_of_IK_15_Motor __Percentage_of_IK_15_Motor)) _Percentage_of_IK_15_Motor)
  (:Percentage_of_IK_16_Motor
   (&optional __Percentage_of_IK_16_Motor)
   (if __Percentage_of_IK_16_Motor (setq _Percentage_of_IK_16_Motor __Percentage_of_IK_16_Motor)) _Percentage_of_IK_16_Motor)
  (:Percentage_of_IK_17_Motor
   (&optional __Percentage_of_IK_17_Motor)
   (if __Percentage_of_IK_17_Motor (setq _Percentage_of_IK_17_Motor __Percentage_of_IK_17_Motor)) _Percentage_of_IK_17_Motor)
  (:Percentage_of_IK_18_Motor
   (&optional __Percentage_of_IK_18_Motor)
   (if __Percentage_of_IK_18_Motor (setq _Percentage_of_IK_18_Motor __Percentage_of_IK_18_Motor)) _Percentage_of_IK_18_Motor)
  (:Percentage_of_IK_19_Motor
   (&optional __Percentage_of_IK_19_Motor)
   (if __Percentage_of_IK_19_Motor (setq _Percentage_of_IK_19_Motor __Percentage_of_IK_19_Motor)) _Percentage_of_IK_19_Motor)
  (:Percentage_of_IK_20_Motor
   (&optional __Percentage_of_IK_20_Motor)
   (if __Percentage_of_IK_20_Motor (setq _Percentage_of_IK_20_Motor __Percentage_of_IK_20_Motor)) _Percentage_of_IK_20_Motor)
  (:Percentage_of_IK_21_Motor
   (&optional __Percentage_of_IK_21_Motor)
   (if __Percentage_of_IK_21_Motor (setq _Percentage_of_IK_21_Motor __Percentage_of_IK_21_Motor)) _Percentage_of_IK_21_Motor)
  (:First_Pos_XR
   (&optional __First_Pos_XR)
   (if __First_Pos_XR (setq _First_Pos_XR __First_Pos_XR)) _First_Pos_XR)
  (:First_Neg_XR
   (&optional __First_Neg_XR)
   (if __First_Neg_XR (setq _First_Neg_XR __First_Neg_XR)) _First_Neg_XR)
  (:First_Pos_SideR
   (&optional __First_Pos_SideR)
   (if __First_Pos_SideR (setq _First_Pos_SideR __First_Pos_SideR)) _First_Pos_SideR)
  (:First_Neg_SideR
   (&optional __First_Neg_SideR)
   (if __First_Neg_SideR (setq _First_Neg_SideR __First_Neg_SideR)) _First_Neg_SideR)
  (:First_Pos_YawR
   (&optional __First_Pos_YawR)
   (if __First_Pos_YawR (setq _First_Pos_YawR __First_Pos_YawR)) _First_Pos_YawR)
  (:First_Neg_YawR
   (&optional __First_Neg_YawR)
   (if __First_Neg_YawR (setq _First_Neg_YawR __First_Neg_YawR)) _First_Neg_YawR)
  (:First_Pos_XL
   (&optional __First_Pos_XL)
   (if __First_Pos_XL (setq _First_Pos_XL __First_Pos_XL)) _First_Pos_XL)
  (:First_Neg_XL
   (&optional __First_Neg_XL)
   (if __First_Neg_XL (setq _First_Neg_XL __First_Neg_XL)) _First_Neg_XL)
  (:First_Pos_SideL
   (&optional __First_Pos_SideL)
   (if __First_Pos_SideL (setq _First_Pos_SideL __First_Pos_SideL)) _First_Pos_SideL)
  (:First_Neg_SideL
   (&optional __First_Neg_SideL)
   (if __First_Neg_SideL (setq _First_Neg_SideL __First_Neg_SideL)) _First_Neg_SideL)
  (:First_Pos_YawL
   (&optional __First_Pos_YawL)
   (if __First_Pos_YawL (setq _First_Pos_YawL __First_Pos_YawL)) _First_Pos_YawL)
  (:First_Neg_YawL
   (&optional __First_Neg_YawL)
   (if __First_Neg_YawL (setq _First_Neg_YawL __First_Neg_YawL)) _First_Neg_YawL)
  (:First_Pos_SideR_SwingMinus
   (&optional __First_Pos_SideR_SwingMinus)
   (if __First_Pos_SideR_SwingMinus (setq _First_Pos_SideR_SwingMinus __First_Pos_SideR_SwingMinus)) _First_Pos_SideR_SwingMinus)
  (:First_Neg_SideR_SwingMinus
   (&optional __First_Neg_SideR_SwingMinus)
   (if __First_Neg_SideR_SwingMinus (setq _First_Neg_SideR_SwingMinus __First_Neg_SideR_SwingMinus)) _First_Neg_SideR_SwingMinus)
  (:First_Pos_SideL_SwingMinus
   (&optional __First_Pos_SideL_SwingMinus)
   (if __First_Pos_SideL_SwingMinus (setq _First_Pos_SideL_SwingMinus __First_Pos_SideL_SwingMinus)) _First_Pos_SideL_SwingMinus)
  (:First_Neg_SideL_SwingMinus
   (&optional __First_Neg_SideL_SwingMinus)
   (if __First_Neg_SideL_SwingMinus (setq _First_Neg_SideL_SwingMinus __First_Neg_SideL_SwingMinus)) _First_Neg_SideL_SwingMinus)
  (:First_min
   (&optional __First_min)
   (if __First_min (setq _First_min __First_min)) _First_min)
  (:First_max
   (&optional __First_max)
   (if __First_max (setq _First_max __First_max)) _First_max)
  (:Second_Pos_XR
   (&optional __Second_Pos_XR)
   (if __Second_Pos_XR (setq _Second_Pos_XR __Second_Pos_XR)) _Second_Pos_XR)
  (:Second_Neg_XR
   (&optional __Second_Neg_XR)
   (if __Second_Neg_XR (setq _Second_Neg_XR __Second_Neg_XR)) _Second_Neg_XR)
  (:Second_Pos_SideR
   (&optional __Second_Pos_SideR)
   (if __Second_Pos_SideR (setq _Second_Pos_SideR __Second_Pos_SideR)) _Second_Pos_SideR)
  (:Second_Neg_SideR
   (&optional __Second_Neg_SideR)
   (if __Second_Neg_SideR (setq _Second_Neg_SideR __Second_Neg_SideR)) _Second_Neg_SideR)
  (:Second_Pos_YawR
   (&optional __Second_Pos_YawR)
   (if __Second_Pos_YawR (setq _Second_Pos_YawR __Second_Pos_YawR)) _Second_Pos_YawR)
  (:Second_Neg_YawR
   (&optional __Second_Neg_YawR)
   (if __Second_Neg_YawR (setq _Second_Neg_YawR __Second_Neg_YawR)) _Second_Neg_YawR)
  (:Second_Pos_XL
   (&optional __Second_Pos_XL)
   (if __Second_Pos_XL (setq _Second_Pos_XL __Second_Pos_XL)) _Second_Pos_XL)
  (:Second_Neg_XL
   (&optional __Second_Neg_XL)
   (if __Second_Neg_XL (setq _Second_Neg_XL __Second_Neg_XL)) _Second_Neg_XL)
  (:Second_Pos_SideL
   (&optional __Second_Pos_SideL)
   (if __Second_Pos_SideL (setq _Second_Pos_SideL __Second_Pos_SideL)) _Second_Pos_SideL)
  (:Second_Neg_SideL
   (&optional __Second_Neg_SideL)
   (if __Second_Neg_SideL (setq _Second_Neg_SideL __Second_Neg_SideL)) _Second_Neg_SideL)
  (:Second_Pos_YawL
   (&optional __Second_Pos_YawL)
   (if __Second_Pos_YawL (setq _Second_Pos_YawL __Second_Pos_YawL)) _Second_Pos_YawL)
  (:Second_Neg_YawL
   (&optional __Second_Neg_YawL)
   (if __Second_Neg_YawL (setq _Second_Neg_YawL __Second_Neg_YawL)) _Second_Neg_YawL)
  (:Second_Pos_SideR_SwingMinus
   (&optional __Second_Pos_SideR_SwingMinus)
   (if __Second_Pos_SideR_SwingMinus (setq _Second_Pos_SideR_SwingMinus __Second_Pos_SideR_SwingMinus)) _Second_Pos_SideR_SwingMinus)
  (:Second_Neg_SideR_SwingMinus
   (&optional __Second_Neg_SideR_SwingMinus)
   (if __Second_Neg_SideR_SwingMinus (setq _Second_Neg_SideR_SwingMinus __Second_Neg_SideR_SwingMinus)) _Second_Neg_SideR_SwingMinus)
  (:Second_Pos_SideL_SwingMinus
   (&optional __Second_Pos_SideL_SwingMinus)
   (if __Second_Pos_SideL_SwingMinus (setq _Second_Pos_SideL_SwingMinus __Second_Pos_SideL_SwingMinus)) _Second_Pos_SideL_SwingMinus)
  (:Second_Neg_SideL_SwingMinus
   (&optional __Second_Neg_SideL_SwingMinus)
   (if __Second_Neg_SideL_SwingMinus (setq _Second_Neg_SideL_SwingMinus __Second_Neg_SideL_SwingMinus)) _Second_Neg_SideL_SwingMinus)
  (:Second_min
   (&optional __Second_min)
   (if __Second_min (setq _Second_min __Second_min)) _Second_min)
  (:Second_max
   (&optional __Second_max)
   (if __Second_max (setq _Second_max __Second_max)) _Second_max)
  (:Third_Pos_XR
   (&optional __Third_Pos_XR)
   (if __Third_Pos_XR (setq _Third_Pos_XR __Third_Pos_XR)) _Third_Pos_XR)
  (:Third_Neg_XR
   (&optional __Third_Neg_XR)
   (if __Third_Neg_XR (setq _Third_Neg_XR __Third_Neg_XR)) _Third_Neg_XR)
  (:Third_Pos_SideR
   (&optional __Third_Pos_SideR)
   (if __Third_Pos_SideR (setq _Third_Pos_SideR __Third_Pos_SideR)) _Third_Pos_SideR)
  (:Third_Neg_SideR
   (&optional __Third_Neg_SideR)
   (if __Third_Neg_SideR (setq _Third_Neg_SideR __Third_Neg_SideR)) _Third_Neg_SideR)
  (:Third_Pos_YawR
   (&optional __Third_Pos_YawR)
   (if __Third_Pos_YawR (setq _Third_Pos_YawR __Third_Pos_YawR)) _Third_Pos_YawR)
  (:Third_Neg_YawR
   (&optional __Third_Neg_YawR)
   (if __Third_Neg_YawR (setq _Third_Neg_YawR __Third_Neg_YawR)) _Third_Neg_YawR)
  (:Third_Pos_XL
   (&optional __Third_Pos_XL)
   (if __Third_Pos_XL (setq _Third_Pos_XL __Third_Pos_XL)) _Third_Pos_XL)
  (:Third_Neg_XL
   (&optional __Third_Neg_XL)
   (if __Third_Neg_XL (setq _Third_Neg_XL __Third_Neg_XL)) _Third_Neg_XL)
  (:Third_Pos_SideL
   (&optional __Third_Pos_SideL)
   (if __Third_Pos_SideL (setq _Third_Pos_SideL __Third_Pos_SideL)) _Third_Pos_SideL)
  (:Third_Neg_SideL
   (&optional __Third_Neg_SideL)
   (if __Third_Neg_SideL (setq _Third_Neg_SideL __Third_Neg_SideL)) _Third_Neg_SideL)
  (:Third_Pos_YawL
   (&optional __Third_Pos_YawL)
   (if __Third_Pos_YawL (setq _Third_Pos_YawL __Third_Pos_YawL)) _Third_Pos_YawL)
  (:Third_Neg_YawL
   (&optional __Third_Neg_YawL)
   (if __Third_Neg_YawL (setq _Third_Neg_YawL __Third_Neg_YawL)) _Third_Neg_YawL)
  (:Third_Pos_SideR_SwingMinus
   (&optional __Third_Pos_SideR_SwingMinus)
   (if __Third_Pos_SideR_SwingMinus (setq _Third_Pos_SideR_SwingMinus __Third_Pos_SideR_SwingMinus)) _Third_Pos_SideR_SwingMinus)
  (:Third_Neg_SideR_SwingMinus
   (&optional __Third_Neg_SideR_SwingMinus)
   (if __Third_Neg_SideR_SwingMinus (setq _Third_Neg_SideR_SwingMinus __Third_Neg_SideR_SwingMinus)) _Third_Neg_SideR_SwingMinus)
  (:Third_Pos_SideL_SwingMinus
   (&optional __Third_Pos_SideL_SwingMinus)
   (if __Third_Pos_SideL_SwingMinus (setq _Third_Pos_SideL_SwingMinus __Third_Pos_SideL_SwingMinus)) _Third_Pos_SideL_SwingMinus)
  (:Third_Neg_SideL_SwingMinus
   (&optional __Third_Neg_SideL_SwingMinus)
   (if __Third_Neg_SideL_SwingMinus (setq _Third_Neg_SideL_SwingMinus __Third_Neg_SideL_SwingMinus)) _Third_Neg_SideL_SwingMinus)
  (:Third_min
   (&optional __Third_min)
   (if __Third_min (setq _Third_min __Third_min)) _Third_min)
  (:Third_max
   (&optional __Third_max)
   (if __Third_max (setq _Third_max __Third_max)) _Third_max)
  (:Fourth_Pos_XR
   (&optional __Fourth_Pos_XR)
   (if __Fourth_Pos_XR (setq _Fourth_Pos_XR __Fourth_Pos_XR)) _Fourth_Pos_XR)
  (:Fourth_Neg_XR
   (&optional __Fourth_Neg_XR)
   (if __Fourth_Neg_XR (setq _Fourth_Neg_XR __Fourth_Neg_XR)) _Fourth_Neg_XR)
  (:Fourth_Pos_SideR
   (&optional __Fourth_Pos_SideR)
   (if __Fourth_Pos_SideR (setq _Fourth_Pos_SideR __Fourth_Pos_SideR)) _Fourth_Pos_SideR)
  (:Fourth_Neg_SideR
   (&optional __Fourth_Neg_SideR)
   (if __Fourth_Neg_SideR (setq _Fourth_Neg_SideR __Fourth_Neg_SideR)) _Fourth_Neg_SideR)
  (:Fourth_Pos_YawR
   (&optional __Fourth_Pos_YawR)
   (if __Fourth_Pos_YawR (setq _Fourth_Pos_YawR __Fourth_Pos_YawR)) _Fourth_Pos_YawR)
  (:Fourth_Neg_YawR
   (&optional __Fourth_Neg_YawR)
   (if __Fourth_Neg_YawR (setq _Fourth_Neg_YawR __Fourth_Neg_YawR)) _Fourth_Neg_YawR)
  (:Fourth_Pos_XL
   (&optional __Fourth_Pos_XL)
   (if __Fourth_Pos_XL (setq _Fourth_Pos_XL __Fourth_Pos_XL)) _Fourth_Pos_XL)
  (:Fourth_Neg_XL
   (&optional __Fourth_Neg_XL)
   (if __Fourth_Neg_XL (setq _Fourth_Neg_XL __Fourth_Neg_XL)) _Fourth_Neg_XL)
  (:Fourth_Pos_SideL
   (&optional __Fourth_Pos_SideL)
   (if __Fourth_Pos_SideL (setq _Fourth_Pos_SideL __Fourth_Pos_SideL)) _Fourth_Pos_SideL)
  (:Fourth_Neg_SideL
   (&optional __Fourth_Neg_SideL)
   (if __Fourth_Neg_SideL (setq _Fourth_Neg_SideL __Fourth_Neg_SideL)) _Fourth_Neg_SideL)
  (:Fourth_Pos_YawL
   (&optional __Fourth_Pos_YawL)
   (if __Fourth_Pos_YawL (setq _Fourth_Pos_YawL __Fourth_Pos_YawL)) _Fourth_Pos_YawL)
  (:Fourth_Neg_YawL
   (&optional __Fourth_Neg_YawL)
   (if __Fourth_Neg_YawL (setq _Fourth_Neg_YawL __Fourth_Neg_YawL)) _Fourth_Neg_YawL)
  (:Fourth_Pos_SideR_SwingMinus
   (&optional __Fourth_Pos_SideR_SwingMinus)
   (if __Fourth_Pos_SideR_SwingMinus (setq _Fourth_Pos_SideR_SwingMinus __Fourth_Pos_SideR_SwingMinus)) _Fourth_Pos_SideR_SwingMinus)
  (:Fourth_Neg_SideR_SwingMinus
   (&optional __Fourth_Neg_SideR_SwingMinus)
   (if __Fourth_Neg_SideR_SwingMinus (setq _Fourth_Neg_SideR_SwingMinus __Fourth_Neg_SideR_SwingMinus)) _Fourth_Neg_SideR_SwingMinus)
  (:Fourth_Pos_SideL_SwingMinus
   (&optional __Fourth_Pos_SideL_SwingMinus)
   (if __Fourth_Pos_SideL_SwingMinus (setq _Fourth_Pos_SideL_SwingMinus __Fourth_Pos_SideL_SwingMinus)) _Fourth_Pos_SideL_SwingMinus)
  (:Fourth_Neg_SideL_SwingMinus
   (&optional __Fourth_Neg_SideL_SwingMinus)
   (if __Fourth_Neg_SideL_SwingMinus (setq _Fourth_Neg_SideL_SwingMinus __Fourth_Neg_SideL_SwingMinus)) _Fourth_Neg_SideL_SwingMinus)
  (:Fourth_min
   (&optional __Fourth_min)
   (if __Fourth_min (setq _Fourth_min __Fourth_min)) _Fourth_min)
  (:Fourth_max
   (&optional __Fourth_max)
   (if __Fourth_max (setq _Fourth_max __Fourth_max)) _Fourth_max)
  (:Landing_Time_Control_flag
   (&optional __Landing_Time_Control_flag)
   (if __Landing_Time_Control_flag (setq _Landing_Time_Control_flag __Landing_Time_Control_flag)) _Landing_Time_Control_flag)
  (:Control_System_flag
   (&optional __Control_System_flag)
   (if __Control_System_flag (setq _Control_System_flag __Control_System_flag)) _Control_System_flag)
  (:serialization-length
   ()
   (+
    ;; bool _IK_Flag
    1
    ;; float64 _Entire_Time
    8
    ;; float64 _Frequency
    8
    ;; float64 _Default_X_Right
    8
    ;; float64 _Default_X_Left
    8
    ;; float64 _Default_Y_Right
    8
    ;; float64 _Default_Y_Left
    8
    ;; float64 _Default_Z_Right
    8
    ;; float64 _Default_Z_Left
    8
    ;; float64 _Offset_10_Motor
    8
    ;; float64 _Offset_11_Motor
    8
    ;; float64 _Offset_12_Motor
    8
    ;; float64 _Offset_13_Motor
    8
    ;; float64 _Offset_14_Motor
    8
    ;; float64 _Offset_15_Motor
    8
    ;; float64 _Offset_16_Motor
    8
    ;; float64 _Offset_17_Motor
    8
    ;; float64 _Offset_18_Motor
    8
    ;; float64 _Offset_19_Motor
    8
    ;; float64 _Offset_20_Motor
    8
    ;; float64 _Offset_21_Motor
    8
    ;; float64 _Swing_Right_Leg
    8
    ;; float64 _Swing_Left_Leg
    8
    ;; float64 _Swing_Right_Shoulder
    8
    ;; float64 _Swing_Left_Shoulder
    8
    ;; float64 _Rise_Right_Leg
    8
    ;; float64 _Rise_Left_Leg
    8
    ;; float64 _Start_Entire_Time
    8
    ;; float64 _Start_Swing
    8
    ;; float64 _Start_Rise
    8
    ;; float64 _End_Entire_Time
    8
    ;; float64 _End_Swing
    8
    ;; float64 _End_Rise
    8
    ;; float64 _Test_X
    8
    ;; float64 _Test_Side
    8
    ;; float64 _Test_Yaw
    8
    ;; float64 _Tuning_X
    8
    ;; float64 _Tuning_Side
    8
    ;; float64 _Tuning_Yaw
    8
    ;; float64 _Balance_Value_0
    8
    ;; float64 _Balance_Value_1
    8
    ;; float64 _Balance_Value_2
    8
    ;; float64 _Balance_Value_3
    8
    ;; float64 _Balance_Pitch_GP
    8
    ;; float64 _Balance_Pitch_GI
    8
    ;; float64 _Balance_Pitch_GD
    8
    ;; float64 _Balance_Pitch_ELIMIT
    8
    ;; float64 _Balance_Pitch_OLIMIT
    8
    ;; float64 _Balance_Pitch_Neg_Target
    8
    ;; float64 _Balance_Pitch_Pos_Target
    8
    ;; float64 _Balance_Roll_GP
    8
    ;; float64 _Balance_Roll_GI
    8
    ;; float64 _Balance_Roll_GD
    8
    ;; float64 _Balance_Roll_ELIMIT
    8
    ;; float64 _Balance_Roll_OLIMIT
    8
    ;; float64 _Balance_Roll_Neg_Target
    8
    ;; float64 _Balance_Roll_Pos_Target
    8
    ;; float64 _Balance_Angle_Pitch_GP
    8
    ;; float64 _Balance_Angle_Pitch_GI
    8
    ;; float64 _Balance_Angle_Pitch_GD
    8
    ;; float64 _Balance_Angle_Pitch_ELIMIT
    8
    ;; float64 _Balance_Angle_Pitch_OLIMIT
    8
    ;; float64 _Balance_Angle_Pitch_Neg_Target
    8
    ;; float64 _Balance_Angle_Pitch_Pos_Target
    8
    ;; float64 _Balance_Value_4
    8
    ;; float64 _Balance_Value_5
    8
    ;; int64 _Balance_Pitch_Flag_imu
    8
    ;; float64 _Balance_Pitch_GP_imu
    8
    ;; float64 _Balance_Pitch_GI_imu
    8
    ;; float64 _Balance_Pitch_GD_imu
    8
    ;; float64 _Balance_Pitch_Neg_Target_imu
    8
    ;; float64 _Balance_Pitch_Pos_Target_imu
    8
    ;; float64 _Balance_Pitch_ELIMIT_imu
    8
    ;; float64 _Balance_Pitch_OLIMIT_imu
    8
    ;; int64 _Balance_Roll_Flag_imu
    8
    ;; float64 _Balance_Roll_GP_imu
    8
    ;; float64 _Balance_Roll_GI_imu
    8
    ;; float64 _Balance_Roll_GD_imu
    8
    ;; float64 _Balance_Roll_Neg_Target_imu
    8
    ;; float64 _Balance_Roll_Pos_Target_imu
    8
    ;; float64 _Balance_Roll_ELIMIT_imu
    8
    ;; float64 _Balance_Roll_OLIMIT_imu
    8
    ;; int64 _Balance_Pitch_Flag
    8
    ;; int64 _Balance_Ankle_Pitch_Flag
    8
    ;; int64 _Balance_Roll_Flag
    8
    ;; int64 _Ratio_Check_Flag
    8
    ;; float64 _Center2Leg
    8
    ;; float64 _Link2Link
    8
    ;; float64 _Init_Z_Up
    8
    ;; float64 _Percentage_of_IK_10_Motor
    8
    ;; float64 _Percentage_of_IK_11_Motor
    8
    ;; float64 _Percentage_of_IK_12_Motor
    8
    ;; float64 _Percentage_of_IK_13_Motor
    8
    ;; float64 _Percentage_of_IK_14_Motor
    8
    ;; float64 _Percentage_of_IK_15_Motor
    8
    ;; float64 _Percentage_of_IK_16_Motor
    8
    ;; float64 _Percentage_of_IK_17_Motor
    8
    ;; float64 _Percentage_of_IK_18_Motor
    8
    ;; float64 _Percentage_of_IK_19_Motor
    8
    ;; float64 _Percentage_of_IK_20_Motor
    8
    ;; float64 _Percentage_of_IK_21_Motor
    8
    ;; float64 _First_Pos_XR
    8
    ;; float64 _First_Neg_XR
    8
    ;; float64 _First_Pos_SideR
    8
    ;; float64 _First_Neg_SideR
    8
    ;; float64 _First_Pos_YawR
    8
    ;; float64 _First_Neg_YawR
    8
    ;; float64 _First_Pos_XL
    8
    ;; float64 _First_Neg_XL
    8
    ;; float64 _First_Pos_SideL
    8
    ;; float64 _First_Neg_SideL
    8
    ;; float64 _First_Pos_YawL
    8
    ;; float64 _First_Neg_YawL
    8
    ;; float64 _First_Pos_SideR_SwingMinus
    8
    ;; float64 _First_Neg_SideR_SwingMinus
    8
    ;; float64 _First_Pos_SideL_SwingMinus
    8
    ;; float64 _First_Neg_SideL_SwingMinus
    8
    ;; int64 _First_min
    8
    ;; int64 _First_max
    8
    ;; float64 _Second_Pos_XR
    8
    ;; float64 _Second_Neg_XR
    8
    ;; float64 _Second_Pos_SideR
    8
    ;; float64 _Second_Neg_SideR
    8
    ;; float64 _Second_Pos_YawR
    8
    ;; float64 _Second_Neg_YawR
    8
    ;; float64 _Second_Pos_XL
    8
    ;; float64 _Second_Neg_XL
    8
    ;; float64 _Second_Pos_SideL
    8
    ;; float64 _Second_Neg_SideL
    8
    ;; float64 _Second_Pos_YawL
    8
    ;; float64 _Second_Neg_YawL
    8
    ;; float64 _Second_Pos_SideR_SwingMinus
    8
    ;; float64 _Second_Neg_SideR_SwingMinus
    8
    ;; float64 _Second_Pos_SideL_SwingMinus
    8
    ;; float64 _Second_Neg_SideL_SwingMinus
    8
    ;; int64 _Second_min
    8
    ;; int64 _Second_max
    8
    ;; float64 _Third_Pos_XR
    8
    ;; float64 _Third_Neg_XR
    8
    ;; float64 _Third_Pos_SideR
    8
    ;; float64 _Third_Neg_SideR
    8
    ;; float64 _Third_Pos_YawR
    8
    ;; float64 _Third_Neg_YawR
    8
    ;; float64 _Third_Pos_XL
    8
    ;; float64 _Third_Neg_XL
    8
    ;; float64 _Third_Pos_SideL
    8
    ;; float64 _Third_Neg_SideL
    8
    ;; float64 _Third_Pos_YawL
    8
    ;; float64 _Third_Neg_YawL
    8
    ;; float64 _Third_Pos_SideR_SwingMinus
    8
    ;; float64 _Third_Neg_SideR_SwingMinus
    8
    ;; float64 _Third_Pos_SideL_SwingMinus
    8
    ;; float64 _Third_Neg_SideL_SwingMinus
    8
    ;; int64 _Third_min
    8
    ;; int64 _Third_max
    8
    ;; float64 _Fourth_Pos_XR
    8
    ;; float64 _Fourth_Neg_XR
    8
    ;; float64 _Fourth_Pos_SideR
    8
    ;; float64 _Fourth_Neg_SideR
    8
    ;; float64 _Fourth_Pos_YawR
    8
    ;; float64 _Fourth_Neg_YawR
    8
    ;; float64 _Fourth_Pos_XL
    8
    ;; float64 _Fourth_Neg_XL
    8
    ;; float64 _Fourth_Pos_SideL
    8
    ;; float64 _Fourth_Neg_SideL
    8
    ;; float64 _Fourth_Pos_YawL
    8
    ;; float64 _Fourth_Neg_YawL
    8
    ;; float64 _Fourth_Pos_SideR_SwingMinus
    8
    ;; float64 _Fourth_Neg_SideR_SwingMinus
    8
    ;; float64 _Fourth_Pos_SideL_SwingMinus
    8
    ;; float64 _Fourth_Neg_SideL_SwingMinus
    8
    ;; int64 _Fourth_min
    8
    ;; int64 _Fourth_max
    8
    ;; int64 _Landing_Time_Control_flag
    8
    ;; int64 _Control_System_flag
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _IK_Flag
       (if _IK_Flag (write-byte -1 s) (write-byte 0 s))
     ;; float64 _Entire_Time
       (sys::poke _Entire_Time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Frequency
       (sys::poke _Frequency (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_X_Right
       (sys::poke _Default_X_Right (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_X_Left
       (sys::poke _Default_X_Left (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_Y_Right
       (sys::poke _Default_Y_Right (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_Y_Left
       (sys::poke _Default_Y_Left (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_Z_Right
       (sys::poke _Default_Z_Right (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Default_Z_Left
       (sys::poke _Default_Z_Left (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_10_Motor
       (sys::poke _Offset_10_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_11_Motor
       (sys::poke _Offset_11_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_12_Motor
       (sys::poke _Offset_12_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_13_Motor
       (sys::poke _Offset_13_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_14_Motor
       (sys::poke _Offset_14_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_15_Motor
       (sys::poke _Offset_15_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_16_Motor
       (sys::poke _Offset_16_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_17_Motor
       (sys::poke _Offset_17_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_18_Motor
       (sys::poke _Offset_18_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_19_Motor
       (sys::poke _Offset_19_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_20_Motor
       (sys::poke _Offset_20_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Offset_21_Motor
       (sys::poke _Offset_21_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Right_Leg
       (sys::poke _Swing_Right_Leg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Left_Leg
       (sys::poke _Swing_Left_Leg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Right_Shoulder
       (sys::poke _Swing_Right_Shoulder (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Left_Shoulder
       (sys::poke _Swing_Left_Shoulder (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Rise_Right_Leg
       (sys::poke _Rise_Right_Leg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Rise_Left_Leg
       (sys::poke _Rise_Left_Leg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Start_Entire_Time
       (sys::poke _Start_Entire_Time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Start_Swing
       (sys::poke _Start_Swing (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Start_Rise
       (sys::poke _Start_Rise (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _End_Entire_Time
       (sys::poke _End_Entire_Time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _End_Swing
       (sys::poke _End_Swing (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _End_Rise
       (sys::poke _End_Rise (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Test_X
       (sys::poke _Test_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Test_Side
       (sys::poke _Test_Side (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Test_Yaw
       (sys::poke _Test_Yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Tuning_X
       (sys::poke _Tuning_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Tuning_Side
       (sys::poke _Tuning_Side (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Tuning_Yaw
       (sys::poke _Tuning_Yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_0
       (sys::poke _Balance_Value_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_1
       (sys::poke _Balance_Value_1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_2
       (sys::poke _Balance_Value_2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_3
       (sys::poke _Balance_Value_3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_GP
       (sys::poke _Balance_Pitch_GP (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_GI
       (sys::poke _Balance_Pitch_GI (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_GD
       (sys::poke _Balance_Pitch_GD (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_ELIMIT
       (sys::poke _Balance_Pitch_ELIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_OLIMIT
       (sys::poke _Balance_Pitch_OLIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_Neg_Target
       (sys::poke _Balance_Pitch_Neg_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_Pos_Target
       (sys::poke _Balance_Pitch_Pos_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_GP
       (sys::poke _Balance_Roll_GP (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_GI
       (sys::poke _Balance_Roll_GI (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_GD
       (sys::poke _Balance_Roll_GD (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_ELIMIT
       (sys::poke _Balance_Roll_ELIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_OLIMIT
       (sys::poke _Balance_Roll_OLIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_Neg_Target
       (sys::poke _Balance_Roll_Neg_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_Pos_Target
       (sys::poke _Balance_Roll_Pos_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_GP
       (sys::poke _Balance_Angle_Pitch_GP (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_GI
       (sys::poke _Balance_Angle_Pitch_GI (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_GD
       (sys::poke _Balance_Angle_Pitch_GD (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_ELIMIT
       (sys::poke _Balance_Angle_Pitch_ELIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_OLIMIT
       (sys::poke _Balance_Angle_Pitch_OLIMIT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_Neg_Target
       (sys::poke _Balance_Angle_Pitch_Neg_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Angle_Pitch_Pos_Target
       (sys::poke _Balance_Angle_Pitch_Pos_Target (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_4
       (sys::poke _Balance_Value_4 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Value_5
       (sys::poke _Balance_Value_5 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Balance_Pitch_Flag_imu
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Balance_Pitch_Flag_imu (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Balance_Pitch_Flag_imu) (= (length (_Balance_Pitch_Flag_imu . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Balance_Pitch_Flag_imu . bv) 0) 0) s)
              (write-long (ash (elt (_Balance_Pitch_Flag_imu . bv) 1) -1) s))
             ((and (class _Balance_Pitch_Flag_imu) (= (length (_Balance_Pitch_Flag_imu . bv)) 1)) ;; big1
              (write-long (elt (_Balance_Pitch_Flag_imu . bv) 0) s)
              (write-long (if (>= _Balance_Pitch_Flag_imu 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Balance_Pitch_Flag_imu s)(write-long (if (>= _Balance_Pitch_Flag_imu 0) 0 #xffffffff) s)))
     ;; float64 _Balance_Pitch_GP_imu
       (sys::poke _Balance_Pitch_GP_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_GI_imu
       (sys::poke _Balance_Pitch_GI_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_GD_imu
       (sys::poke _Balance_Pitch_GD_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_Neg_Target_imu
       (sys::poke _Balance_Pitch_Neg_Target_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_Pos_Target_imu
       (sys::poke _Balance_Pitch_Pos_Target_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_ELIMIT_imu
       (sys::poke _Balance_Pitch_ELIMIT_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Pitch_OLIMIT_imu
       (sys::poke _Balance_Pitch_OLIMIT_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Balance_Roll_Flag_imu
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Balance_Roll_Flag_imu (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Balance_Roll_Flag_imu) (= (length (_Balance_Roll_Flag_imu . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Balance_Roll_Flag_imu . bv) 0) 0) s)
              (write-long (ash (elt (_Balance_Roll_Flag_imu . bv) 1) -1) s))
             ((and (class _Balance_Roll_Flag_imu) (= (length (_Balance_Roll_Flag_imu . bv)) 1)) ;; big1
              (write-long (elt (_Balance_Roll_Flag_imu . bv) 0) s)
              (write-long (if (>= _Balance_Roll_Flag_imu 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Balance_Roll_Flag_imu s)(write-long (if (>= _Balance_Roll_Flag_imu 0) 0 #xffffffff) s)))
     ;; float64 _Balance_Roll_GP_imu
       (sys::poke _Balance_Roll_GP_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_GI_imu
       (sys::poke _Balance_Roll_GI_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_GD_imu
       (sys::poke _Balance_Roll_GD_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_Neg_Target_imu
       (sys::poke _Balance_Roll_Neg_Target_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_Pos_Target_imu
       (sys::poke _Balance_Roll_Pos_Target_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_ELIMIT_imu
       (sys::poke _Balance_Roll_ELIMIT_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Balance_Roll_OLIMIT_imu
       (sys::poke _Balance_Roll_OLIMIT_imu (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Balance_Pitch_Flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Balance_Pitch_Flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Balance_Pitch_Flag) (= (length (_Balance_Pitch_Flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Balance_Pitch_Flag . bv) 0) 0) s)
              (write-long (ash (elt (_Balance_Pitch_Flag . bv) 1) -1) s))
             ((and (class _Balance_Pitch_Flag) (= (length (_Balance_Pitch_Flag . bv)) 1)) ;; big1
              (write-long (elt (_Balance_Pitch_Flag . bv) 0) s)
              (write-long (if (>= _Balance_Pitch_Flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Balance_Pitch_Flag s)(write-long (if (>= _Balance_Pitch_Flag 0) 0 #xffffffff) s)))
     ;; int64 _Balance_Ankle_Pitch_Flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Balance_Ankle_Pitch_Flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Balance_Ankle_Pitch_Flag) (= (length (_Balance_Ankle_Pitch_Flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Balance_Ankle_Pitch_Flag . bv) 0) 0) s)
              (write-long (ash (elt (_Balance_Ankle_Pitch_Flag . bv) 1) -1) s))
             ((and (class _Balance_Ankle_Pitch_Flag) (= (length (_Balance_Ankle_Pitch_Flag . bv)) 1)) ;; big1
              (write-long (elt (_Balance_Ankle_Pitch_Flag . bv) 0) s)
              (write-long (if (>= _Balance_Ankle_Pitch_Flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Balance_Ankle_Pitch_Flag s)(write-long (if (>= _Balance_Ankle_Pitch_Flag 0) 0 #xffffffff) s)))
     ;; int64 _Balance_Roll_Flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Balance_Roll_Flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Balance_Roll_Flag) (= (length (_Balance_Roll_Flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Balance_Roll_Flag . bv) 0) 0) s)
              (write-long (ash (elt (_Balance_Roll_Flag . bv) 1) -1) s))
             ((and (class _Balance_Roll_Flag) (= (length (_Balance_Roll_Flag . bv)) 1)) ;; big1
              (write-long (elt (_Balance_Roll_Flag . bv) 0) s)
              (write-long (if (>= _Balance_Roll_Flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Balance_Roll_Flag s)(write-long (if (>= _Balance_Roll_Flag 0) 0 #xffffffff) s)))
     ;; int64 _Ratio_Check_Flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Ratio_Check_Flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Ratio_Check_Flag) (= (length (_Ratio_Check_Flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Ratio_Check_Flag . bv) 0) 0) s)
              (write-long (ash (elt (_Ratio_Check_Flag . bv) 1) -1) s))
             ((and (class _Ratio_Check_Flag) (= (length (_Ratio_Check_Flag . bv)) 1)) ;; big1
              (write-long (elt (_Ratio_Check_Flag . bv) 0) s)
              (write-long (if (>= _Ratio_Check_Flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Ratio_Check_Flag s)(write-long (if (>= _Ratio_Check_Flag 0) 0 #xffffffff) s)))
     ;; float64 _Center2Leg
       (sys::poke _Center2Leg (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Link2Link
       (sys::poke _Link2Link (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Init_Z_Up
       (sys::poke _Init_Z_Up (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_10_Motor
       (sys::poke _Percentage_of_IK_10_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_11_Motor
       (sys::poke _Percentage_of_IK_11_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_12_Motor
       (sys::poke _Percentage_of_IK_12_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_13_Motor
       (sys::poke _Percentage_of_IK_13_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_14_Motor
       (sys::poke _Percentage_of_IK_14_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_15_Motor
       (sys::poke _Percentage_of_IK_15_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_16_Motor
       (sys::poke _Percentage_of_IK_16_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_17_Motor
       (sys::poke _Percentage_of_IK_17_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_18_Motor
       (sys::poke _Percentage_of_IK_18_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_19_Motor
       (sys::poke _Percentage_of_IK_19_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_20_Motor
       (sys::poke _Percentage_of_IK_20_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Percentage_of_IK_21_Motor
       (sys::poke _Percentage_of_IK_21_Motor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_XR
       (sys::poke _First_Pos_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_XR
       (sys::poke _First_Neg_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_SideR
       (sys::poke _First_Pos_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_SideR
       (sys::poke _First_Neg_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_YawR
       (sys::poke _First_Pos_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_YawR
       (sys::poke _First_Neg_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_XL
       (sys::poke _First_Pos_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_XL
       (sys::poke _First_Neg_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_SideL
       (sys::poke _First_Pos_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_SideL
       (sys::poke _First_Neg_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_YawL
       (sys::poke _First_Pos_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_YawL
       (sys::poke _First_Neg_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_SideR_SwingMinus
       (sys::poke _First_Pos_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_SideR_SwingMinus
       (sys::poke _First_Neg_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Pos_SideL_SwingMinus
       (sys::poke _First_Pos_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _First_Neg_SideL_SwingMinus
       (sys::poke _First_Neg_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _First_min
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _First_min (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _First_min) (= (length (_First_min . bv)) 2)) ;; bignum
              (write-long (ash (elt (_First_min . bv) 0) 0) s)
              (write-long (ash (elt (_First_min . bv) 1) -1) s))
             ((and (class _First_min) (= (length (_First_min . bv)) 1)) ;; big1
              (write-long (elt (_First_min . bv) 0) s)
              (write-long (if (>= _First_min 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _First_min s)(write-long (if (>= _First_min 0) 0 #xffffffff) s)))
     ;; int64 _First_max
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _First_max (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _First_max) (= (length (_First_max . bv)) 2)) ;; bignum
              (write-long (ash (elt (_First_max . bv) 0) 0) s)
              (write-long (ash (elt (_First_max . bv) 1) -1) s))
             ((and (class _First_max) (= (length (_First_max . bv)) 1)) ;; big1
              (write-long (elt (_First_max . bv) 0) s)
              (write-long (if (>= _First_max 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _First_max s)(write-long (if (>= _First_max 0) 0 #xffffffff) s)))
     ;; float64 _Second_Pos_XR
       (sys::poke _Second_Pos_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_XR
       (sys::poke _Second_Neg_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_SideR
       (sys::poke _Second_Pos_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_SideR
       (sys::poke _Second_Neg_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_YawR
       (sys::poke _Second_Pos_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_YawR
       (sys::poke _Second_Neg_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_XL
       (sys::poke _Second_Pos_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_XL
       (sys::poke _Second_Neg_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_SideL
       (sys::poke _Second_Pos_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_SideL
       (sys::poke _Second_Neg_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_YawL
       (sys::poke _Second_Pos_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_YawL
       (sys::poke _Second_Neg_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_SideR_SwingMinus
       (sys::poke _Second_Pos_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_SideR_SwingMinus
       (sys::poke _Second_Neg_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Pos_SideL_SwingMinus
       (sys::poke _Second_Pos_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Second_Neg_SideL_SwingMinus
       (sys::poke _Second_Neg_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Second_min
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Second_min (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Second_min) (= (length (_Second_min . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Second_min . bv) 0) 0) s)
              (write-long (ash (elt (_Second_min . bv) 1) -1) s))
             ((and (class _Second_min) (= (length (_Second_min . bv)) 1)) ;; big1
              (write-long (elt (_Second_min . bv) 0) s)
              (write-long (if (>= _Second_min 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Second_min s)(write-long (if (>= _Second_min 0) 0 #xffffffff) s)))
     ;; int64 _Second_max
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Second_max (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Second_max) (= (length (_Second_max . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Second_max . bv) 0) 0) s)
              (write-long (ash (elt (_Second_max . bv) 1) -1) s))
             ((and (class _Second_max) (= (length (_Second_max . bv)) 1)) ;; big1
              (write-long (elt (_Second_max . bv) 0) s)
              (write-long (if (>= _Second_max 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Second_max s)(write-long (if (>= _Second_max 0) 0 #xffffffff) s)))
     ;; float64 _Third_Pos_XR
       (sys::poke _Third_Pos_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_XR
       (sys::poke _Third_Neg_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_SideR
       (sys::poke _Third_Pos_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_SideR
       (sys::poke _Third_Neg_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_YawR
       (sys::poke _Third_Pos_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_YawR
       (sys::poke _Third_Neg_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_XL
       (sys::poke _Third_Pos_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_XL
       (sys::poke _Third_Neg_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_SideL
       (sys::poke _Third_Pos_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_SideL
       (sys::poke _Third_Neg_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_YawL
       (sys::poke _Third_Pos_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_YawL
       (sys::poke _Third_Neg_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_SideR_SwingMinus
       (sys::poke _Third_Pos_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_SideR_SwingMinus
       (sys::poke _Third_Neg_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Pos_SideL_SwingMinus
       (sys::poke _Third_Pos_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Third_Neg_SideL_SwingMinus
       (sys::poke _Third_Neg_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Third_min
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Third_min (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Third_min) (= (length (_Third_min . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Third_min . bv) 0) 0) s)
              (write-long (ash (elt (_Third_min . bv) 1) -1) s))
             ((and (class _Third_min) (= (length (_Third_min . bv)) 1)) ;; big1
              (write-long (elt (_Third_min . bv) 0) s)
              (write-long (if (>= _Third_min 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Third_min s)(write-long (if (>= _Third_min 0) 0 #xffffffff) s)))
     ;; int64 _Third_max
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Third_max (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Third_max) (= (length (_Third_max . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Third_max . bv) 0) 0) s)
              (write-long (ash (elt (_Third_max . bv) 1) -1) s))
             ((and (class _Third_max) (= (length (_Third_max . bv)) 1)) ;; big1
              (write-long (elt (_Third_max . bv) 0) s)
              (write-long (if (>= _Third_max 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Third_max s)(write-long (if (>= _Third_max 0) 0 #xffffffff) s)))
     ;; float64 _Fourth_Pos_XR
       (sys::poke _Fourth_Pos_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_XR
       (sys::poke _Fourth_Neg_XR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_SideR
       (sys::poke _Fourth_Pos_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_SideR
       (sys::poke _Fourth_Neg_SideR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_YawR
       (sys::poke _Fourth_Pos_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_YawR
       (sys::poke _Fourth_Neg_YawR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_XL
       (sys::poke _Fourth_Pos_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_XL
       (sys::poke _Fourth_Neg_XL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_SideL
       (sys::poke _Fourth_Pos_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_SideL
       (sys::poke _Fourth_Neg_SideL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_YawL
       (sys::poke _Fourth_Pos_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_YawL
       (sys::poke _Fourth_Neg_YawL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_SideR_SwingMinus
       (sys::poke _Fourth_Pos_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_SideR_SwingMinus
       (sys::poke _Fourth_Neg_SideR_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Pos_SideL_SwingMinus
       (sys::poke _Fourth_Pos_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Fourth_Neg_SideL_SwingMinus
       (sys::poke _Fourth_Neg_SideL_SwingMinus (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Fourth_min
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Fourth_min (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Fourth_min) (= (length (_Fourth_min . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Fourth_min . bv) 0) 0) s)
              (write-long (ash (elt (_Fourth_min . bv) 1) -1) s))
             ((and (class _Fourth_min) (= (length (_Fourth_min . bv)) 1)) ;; big1
              (write-long (elt (_Fourth_min . bv) 0) s)
              (write-long (if (>= _Fourth_min 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Fourth_min s)(write-long (if (>= _Fourth_min 0) 0 #xffffffff) s)))
     ;; int64 _Fourth_max
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Fourth_max (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Fourth_max) (= (length (_Fourth_max . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Fourth_max . bv) 0) 0) s)
              (write-long (ash (elt (_Fourth_max . bv) 1) -1) s))
             ((and (class _Fourth_max) (= (length (_Fourth_max . bv)) 1)) ;; big1
              (write-long (elt (_Fourth_max . bv) 0) s)
              (write-long (if (>= _Fourth_max 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Fourth_max s)(write-long (if (>= _Fourth_max 0) 0 #xffffffff) s)))
     ;; int64 _Landing_Time_Control_flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Landing_Time_Control_flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Landing_Time_Control_flag) (= (length (_Landing_Time_Control_flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Landing_Time_Control_flag . bv) 0) 0) s)
              (write-long (ash (elt (_Landing_Time_Control_flag . bv) 1) -1) s))
             ((and (class _Landing_Time_Control_flag) (= (length (_Landing_Time_Control_flag . bv)) 1)) ;; big1
              (write-long (elt (_Landing_Time_Control_flag . bv) 0) s)
              (write-long (if (>= _Landing_Time_Control_flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Landing_Time_Control_flag s)(write-long (if (>= _Landing_Time_Control_flag 0) 0 #xffffffff) s)))
     ;; int64 _Control_System_flag
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Control_System_flag (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Control_System_flag) (= (length (_Control_System_flag . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Control_System_flag . bv) 0) 0) s)
              (write-long (ash (elt (_Control_System_flag . bv) 1) -1) s))
             ((and (class _Control_System_flag) (= (length (_Control_System_flag . bv)) 1)) ;; big1
              (write-long (elt (_Control_System_flag . bv) 0) s)
              (write-long (if (>= _Control_System_flag 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Control_System_flag s)(write-long (if (>= _Control_System_flag 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _IK_Flag
     (setq _IK_Flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _Entire_Time
     (setq _Entire_Time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Frequency
     (setq _Frequency (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_X_Right
     (setq _Default_X_Right (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_X_Left
     (setq _Default_X_Left (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_Y_Right
     (setq _Default_Y_Right (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_Y_Left
     (setq _Default_Y_Left (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_Z_Right
     (setq _Default_Z_Right (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Default_Z_Left
     (setq _Default_Z_Left (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_10_Motor
     (setq _Offset_10_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_11_Motor
     (setq _Offset_11_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_12_Motor
     (setq _Offset_12_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_13_Motor
     (setq _Offset_13_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_14_Motor
     (setq _Offset_14_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_15_Motor
     (setq _Offset_15_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_16_Motor
     (setq _Offset_16_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_17_Motor
     (setq _Offset_17_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_18_Motor
     (setq _Offset_18_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_19_Motor
     (setq _Offset_19_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_20_Motor
     (setq _Offset_20_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Offset_21_Motor
     (setq _Offset_21_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Right_Leg
     (setq _Swing_Right_Leg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Left_Leg
     (setq _Swing_Left_Leg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Right_Shoulder
     (setq _Swing_Right_Shoulder (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Left_Shoulder
     (setq _Swing_Left_Shoulder (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Rise_Right_Leg
     (setq _Rise_Right_Leg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Rise_Left_Leg
     (setq _Rise_Left_Leg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Start_Entire_Time
     (setq _Start_Entire_Time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Start_Swing
     (setq _Start_Swing (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Start_Rise
     (setq _Start_Rise (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _End_Entire_Time
     (setq _End_Entire_Time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _End_Swing
     (setq _End_Swing (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _End_Rise
     (setq _End_Rise (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Test_X
     (setq _Test_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Test_Side
     (setq _Test_Side (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Test_Yaw
     (setq _Test_Yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Tuning_X
     (setq _Tuning_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Tuning_Side
     (setq _Tuning_Side (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Tuning_Yaw
     (setq _Tuning_Yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_0
     (setq _Balance_Value_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_1
     (setq _Balance_Value_1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_2
     (setq _Balance_Value_2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_3
     (setq _Balance_Value_3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_GP
     (setq _Balance_Pitch_GP (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_GI
     (setq _Balance_Pitch_GI (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_GD
     (setq _Balance_Pitch_GD (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_ELIMIT
     (setq _Balance_Pitch_ELIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_OLIMIT
     (setq _Balance_Pitch_OLIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_Neg_Target
     (setq _Balance_Pitch_Neg_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_Pos_Target
     (setq _Balance_Pitch_Pos_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_GP
     (setq _Balance_Roll_GP (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_GI
     (setq _Balance_Roll_GI (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_GD
     (setq _Balance_Roll_GD (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_ELIMIT
     (setq _Balance_Roll_ELIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_OLIMIT
     (setq _Balance_Roll_OLIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_Neg_Target
     (setq _Balance_Roll_Neg_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_Pos_Target
     (setq _Balance_Roll_Pos_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_GP
     (setq _Balance_Angle_Pitch_GP (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_GI
     (setq _Balance_Angle_Pitch_GI (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_GD
     (setq _Balance_Angle_Pitch_GD (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_ELIMIT
     (setq _Balance_Angle_Pitch_ELIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_OLIMIT
     (setq _Balance_Angle_Pitch_OLIMIT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_Neg_Target
     (setq _Balance_Angle_Pitch_Neg_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Angle_Pitch_Pos_Target
     (setq _Balance_Angle_Pitch_Pos_Target (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_4
     (setq _Balance_Value_4 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Value_5
     (setq _Balance_Value_5 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Balance_Pitch_Flag_imu
#+(or :alpha :irix6 :x86_64)
      (setf _Balance_Pitch_Flag_imu (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Balance_Pitch_Flag_imu (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Balance_Pitch_GP_imu
     (setq _Balance_Pitch_GP_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_GI_imu
     (setq _Balance_Pitch_GI_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_GD_imu
     (setq _Balance_Pitch_GD_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_Neg_Target_imu
     (setq _Balance_Pitch_Neg_Target_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_Pos_Target_imu
     (setq _Balance_Pitch_Pos_Target_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_ELIMIT_imu
     (setq _Balance_Pitch_ELIMIT_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Pitch_OLIMIT_imu
     (setq _Balance_Pitch_OLIMIT_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Balance_Roll_Flag_imu
#+(or :alpha :irix6 :x86_64)
      (setf _Balance_Roll_Flag_imu (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Balance_Roll_Flag_imu (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Balance_Roll_GP_imu
     (setq _Balance_Roll_GP_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_GI_imu
     (setq _Balance_Roll_GI_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_GD_imu
     (setq _Balance_Roll_GD_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_Neg_Target_imu
     (setq _Balance_Roll_Neg_Target_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_Pos_Target_imu
     (setq _Balance_Roll_Pos_Target_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_ELIMIT_imu
     (setq _Balance_Roll_ELIMIT_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Balance_Roll_OLIMIT_imu
     (setq _Balance_Roll_OLIMIT_imu (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Balance_Pitch_Flag
#+(or :alpha :irix6 :x86_64)
      (setf _Balance_Pitch_Flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Balance_Pitch_Flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Balance_Ankle_Pitch_Flag
#+(or :alpha :irix6 :x86_64)
      (setf _Balance_Ankle_Pitch_Flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Balance_Ankle_Pitch_Flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Balance_Roll_Flag
#+(or :alpha :irix6 :x86_64)
      (setf _Balance_Roll_Flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Balance_Roll_Flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Ratio_Check_Flag
#+(or :alpha :irix6 :x86_64)
      (setf _Ratio_Check_Flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Ratio_Check_Flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Center2Leg
     (setq _Center2Leg (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Link2Link
     (setq _Link2Link (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Init_Z_Up
     (setq _Init_Z_Up (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_10_Motor
     (setq _Percentage_of_IK_10_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_11_Motor
     (setq _Percentage_of_IK_11_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_12_Motor
     (setq _Percentage_of_IK_12_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_13_Motor
     (setq _Percentage_of_IK_13_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_14_Motor
     (setq _Percentage_of_IK_14_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_15_Motor
     (setq _Percentage_of_IK_15_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_16_Motor
     (setq _Percentage_of_IK_16_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_17_Motor
     (setq _Percentage_of_IK_17_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_18_Motor
     (setq _Percentage_of_IK_18_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_19_Motor
     (setq _Percentage_of_IK_19_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_20_Motor
     (setq _Percentage_of_IK_20_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Percentage_of_IK_21_Motor
     (setq _Percentage_of_IK_21_Motor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_XR
     (setq _First_Pos_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_XR
     (setq _First_Neg_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_SideR
     (setq _First_Pos_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_SideR
     (setq _First_Neg_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_YawR
     (setq _First_Pos_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_YawR
     (setq _First_Neg_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_XL
     (setq _First_Pos_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_XL
     (setq _First_Neg_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_SideL
     (setq _First_Pos_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_SideL
     (setq _First_Neg_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_YawL
     (setq _First_Pos_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_YawL
     (setq _First_Neg_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_SideR_SwingMinus
     (setq _First_Pos_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_SideR_SwingMinus
     (setq _First_Neg_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Pos_SideL_SwingMinus
     (setq _First_Pos_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _First_Neg_SideL_SwingMinus
     (setq _First_Neg_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _First_min
#+(or :alpha :irix6 :x86_64)
      (setf _First_min (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _First_min (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _First_max
#+(or :alpha :irix6 :x86_64)
      (setf _First_max (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _First_max (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Second_Pos_XR
     (setq _Second_Pos_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_XR
     (setq _Second_Neg_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_SideR
     (setq _Second_Pos_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_SideR
     (setq _Second_Neg_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_YawR
     (setq _Second_Pos_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_YawR
     (setq _Second_Neg_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_XL
     (setq _Second_Pos_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_XL
     (setq _Second_Neg_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_SideL
     (setq _Second_Pos_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_SideL
     (setq _Second_Neg_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_YawL
     (setq _Second_Pos_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_YawL
     (setq _Second_Neg_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_SideR_SwingMinus
     (setq _Second_Pos_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_SideR_SwingMinus
     (setq _Second_Neg_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Pos_SideL_SwingMinus
     (setq _Second_Pos_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Second_Neg_SideL_SwingMinus
     (setq _Second_Neg_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Second_min
#+(or :alpha :irix6 :x86_64)
      (setf _Second_min (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Second_min (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Second_max
#+(or :alpha :irix6 :x86_64)
      (setf _Second_max (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Second_max (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Third_Pos_XR
     (setq _Third_Pos_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_XR
     (setq _Third_Neg_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_SideR
     (setq _Third_Pos_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_SideR
     (setq _Third_Neg_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_YawR
     (setq _Third_Pos_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_YawR
     (setq _Third_Neg_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_XL
     (setq _Third_Pos_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_XL
     (setq _Third_Neg_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_SideL
     (setq _Third_Pos_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_SideL
     (setq _Third_Neg_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_YawL
     (setq _Third_Pos_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_YawL
     (setq _Third_Neg_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_SideR_SwingMinus
     (setq _Third_Pos_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_SideR_SwingMinus
     (setq _Third_Neg_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Pos_SideL_SwingMinus
     (setq _Third_Pos_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Third_Neg_SideL_SwingMinus
     (setq _Third_Neg_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Third_min
#+(or :alpha :irix6 :x86_64)
      (setf _Third_min (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Third_min (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Third_max
#+(or :alpha :irix6 :x86_64)
      (setf _Third_max (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Third_max (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Fourth_Pos_XR
     (setq _Fourth_Pos_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_XR
     (setq _Fourth_Neg_XR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_SideR
     (setq _Fourth_Pos_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_SideR
     (setq _Fourth_Neg_SideR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_YawR
     (setq _Fourth_Pos_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_YawR
     (setq _Fourth_Neg_YawR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_XL
     (setq _Fourth_Pos_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_XL
     (setq _Fourth_Neg_XL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_SideL
     (setq _Fourth_Pos_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_SideL
     (setq _Fourth_Neg_SideL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_YawL
     (setq _Fourth_Pos_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_YawL
     (setq _Fourth_Neg_YawL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_SideR_SwingMinus
     (setq _Fourth_Pos_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_SideR_SwingMinus
     (setq _Fourth_Neg_SideR_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Pos_SideL_SwingMinus
     (setq _Fourth_Pos_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Fourth_Neg_SideL_SwingMinus
     (setq _Fourth_Neg_SideL_SwingMinus (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Fourth_min
#+(or :alpha :irix6 :x86_64)
      (setf _Fourth_min (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Fourth_min (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Fourth_max
#+(or :alpha :irix6 :x86_64)
      (setf _Fourth_max (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Fourth_max (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Landing_Time_Control_flag
#+(or :alpha :irix6 :x86_64)
      (setf _Landing_Time_Control_flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Landing_Time_Control_flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Control_System_flag
#+(or :alpha :irix6 :x86_64)
      (setf _Control_System_flag (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Control_System_flag (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get msg_generate::tune2walk :md5sum-) "75d5cf0d1f6070c84882cf68f96d4a52")
(setf (get msg_generate::tune2walk :datatype-) "msg_generate/tune2walk")
(setf (get msg_generate::tune2walk :definition-)
      "bool IK_Flag
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


")



(provide :msg_generate/tune2walk "75d5cf0d1f6070c84882cf68f96d4a52")


