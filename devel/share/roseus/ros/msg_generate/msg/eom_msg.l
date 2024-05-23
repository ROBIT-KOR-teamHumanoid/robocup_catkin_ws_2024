;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::eom_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'eom_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::EOM_MSG")
  (make-package "MSG_GENERATE::EOM_MSG"))

(in-package "ROS")
;;//! \htmlinclude eom_msg.msg.html


(defclass msg_generate::eom_msg
  :super ros::object
  :slots (_IK_Flag _Entire_Time _Frequency _Double_Ratio _Single_Ratio _Default_X_Right _Default_X_Left _Default_Y_Right _Default_Y_Left _Default_Z_Right _Default_Z_Left _Offset_10_Motor _Offset_11_Motor _Offset_12_Motor _Offset_13_Motor _Offset_14_Motor _Offset_15_Motor _Offset_16_Motor _Offset_17_Motor _Offset_18_Motor _Offset_19_Motor _Offset_20_Motor _Offset_21_Motor _Swing_Right_Leg _Swing_Left_Leg _Swing_Right_Shoulder _Swing_Left_Shoulder _Rise_Right_Leg _Rise_Left_Leg _Start_Entire_Time _Start_Swing _Start_Rise _End_Entire_Time _End_Swing _End_Rise _Test_X _Test_Side _Test_Yaw _Tuning_X _Tuning_Side _Tuning_Yaw _Balance_Value_0 _Balance_Value_1 _Balance_Value_2 _Balance_Value_3 _Balance_Pitch_GP _Balance_Pitch_GI _Balance_Pitch_GD _Balance_Pitch_ELIMIT _Balance_Pitch_OLIMIT _Balance_Pitch_Neg_Target _Balance_Pitch_Pos_Target _Balance_Roll_GP _Balance_Roll_GI _Balance_Roll_GD _Balance_Roll_ELIMIT _Balance_Roll_OLIMIT _Balance_Roll_Neg_Target _Balance_Roll_Pos_Target _Balance_Angle_Pitch_GP _Balance_Angle_Pitch_GI _Balance_Angle_Pitch_GD _Balance_Angle_Pitch_ELIMIT _Balance_Angle_Pitch_OLIMIT _Balance_Angle_Pitch_Neg_Target _Balance_Angle_Pitch_Pos_Target _Balance_Pitch_Flag _Balance_Angle_Pitch_Flag _Balance_Roll_Flag _Balance_Time_Flag ))

(defmethod msg_generate::eom_msg
  (:init
   (&key
    ((:IK_Flag __IK_Flag) nil)
    ((:Entire_Time __Entire_Time) 0.0)
    ((:Frequency __Frequency) 0.0)
    ((:Double_Ratio __Double_Ratio) 0.0)
    ((:Single_Ratio __Single_Ratio) 0.0)
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
    ((:Balance_Pitch_Flag __Balance_Pitch_Flag) nil)
    ((:Balance_Angle_Pitch_Flag __Balance_Angle_Pitch_Flag) nil)
    ((:Balance_Roll_Flag __Balance_Roll_Flag) nil)
    ((:Balance_Time_Flag __Balance_Time_Flag) 0.0)
    )
   (send-super :init)
   (setq _IK_Flag __IK_Flag)
   (setq _Entire_Time (float __Entire_Time))
   (setq _Frequency (float __Frequency))
   (setq _Double_Ratio (float __Double_Ratio))
   (setq _Single_Ratio (float __Single_Ratio))
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
   (setq _Balance_Pitch_Flag __Balance_Pitch_Flag)
   (setq _Balance_Angle_Pitch_Flag __Balance_Angle_Pitch_Flag)
   (setq _Balance_Roll_Flag __Balance_Roll_Flag)
   (setq _Balance_Time_Flag (float __Balance_Time_Flag))
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
  (:Double_Ratio
   (&optional __Double_Ratio)
   (if __Double_Ratio (setq _Double_Ratio __Double_Ratio)) _Double_Ratio)
  (:Single_Ratio
   (&optional __Single_Ratio)
   (if __Single_Ratio (setq _Single_Ratio __Single_Ratio)) _Single_Ratio)
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
  (:Balance_Pitch_Flag
   (&optional __Balance_Pitch_Flag)
   (if __Balance_Pitch_Flag (setq _Balance_Pitch_Flag __Balance_Pitch_Flag)) _Balance_Pitch_Flag)
  (:Balance_Angle_Pitch_Flag
   (&optional __Balance_Angle_Pitch_Flag)
   (if __Balance_Angle_Pitch_Flag (setq _Balance_Angle_Pitch_Flag __Balance_Angle_Pitch_Flag)) _Balance_Angle_Pitch_Flag)
  (:Balance_Roll_Flag
   (&optional __Balance_Roll_Flag)
   (if __Balance_Roll_Flag (setq _Balance_Roll_Flag __Balance_Roll_Flag)) _Balance_Roll_Flag)
  (:Balance_Time_Flag
   (&optional __Balance_Time_Flag)
   (if __Balance_Time_Flag (setq _Balance_Time_Flag __Balance_Time_Flag)) _Balance_Time_Flag)
  (:serialization-length
   ()
   (+
    ;; bool _IK_Flag
    1
    ;; float64 _Entire_Time
    8
    ;; float64 _Frequency
    8
    ;; float64 _Double_Ratio
    8
    ;; float64 _Single_Ratio
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
    ;; bool _Balance_Pitch_Flag
    1
    ;; bool _Balance_Angle_Pitch_Flag
    1
    ;; bool _Balance_Roll_Flag
    1
    ;; float64 _Balance_Time_Flag
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
     ;; float64 _Double_Ratio
       (sys::poke _Double_Ratio (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Single_Ratio
       (sys::poke _Single_Ratio (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
     ;; bool _Balance_Pitch_Flag
       (if _Balance_Pitch_Flag (write-byte -1 s) (write-byte 0 s))
     ;; bool _Balance_Angle_Pitch_Flag
       (if _Balance_Angle_Pitch_Flag (write-byte -1 s) (write-byte 0 s))
     ;; bool _Balance_Roll_Flag
       (if _Balance_Roll_Flag (write-byte -1 s) (write-byte 0 s))
     ;; float64 _Balance_Time_Flag
       (sys::poke _Balance_Time_Flag (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64 _Double_Ratio
     (setq _Double_Ratio (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Single_Ratio
     (setq _Single_Ratio (sys::peek buf ptr- :double)) (incf ptr- 8)
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
   ;; bool _Balance_Pitch_Flag
     (setq _Balance_Pitch_Flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Balance_Angle_Pitch_Flag
     (setq _Balance_Angle_Pitch_Flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Balance_Roll_Flag
     (setq _Balance_Roll_Flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _Balance_Time_Flag
     (setq _Balance_Time_Flag (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::eom_msg :md5sum-) "2bab63df50bb1f7ece05fa6985761519")
(setf (get msg_generate::eom_msg :datatype-) "msg_generate/eom_msg")
(setf (get msg_generate::eom_msg :definition-)
      "bool IK_Flag
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


")



(provide :msg_generate/eom_msg "2bab63df50bb1f7ece05fa6985761519")


