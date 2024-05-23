;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::pan_tilt_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'pan_tilt_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::PAN_TILT_MSG")
  (make-package "MSG_GENERATE::PAN_TILT_MSG"))

(in-package "ROS")
;;//! \htmlinclude pan_tilt_msg.msg.html


(defclass msg_generate::pan_tilt_msg
  :super ros::object
  :slots (_waist_flag _Angle_Yaw _Angle_Pitch ))

(defmethod msg_generate::pan_tilt_msg
  (:init
   (&key
    ((:waist_flag __waist_flag) 0)
    ((:Angle_Yaw __Angle_Yaw) 0.0)
    ((:Angle_Pitch __Angle_Pitch) 0.0)
    )
   (send-super :init)
   (setq _waist_flag (round __waist_flag))
   (setq _Angle_Yaw (float __Angle_Yaw))
   (setq _Angle_Pitch (float __Angle_Pitch))
   self)
  (:waist_flag
   (&optional __waist_flag)
   (if __waist_flag (setq _waist_flag __waist_flag)) _waist_flag)
  (:Angle_Yaw
   (&optional __Angle_Yaw)
   (if __Angle_Yaw (setq _Angle_Yaw __Angle_Yaw)) _Angle_Yaw)
  (:Angle_Pitch
   (&optional __Angle_Pitch)
   (if __Angle_Pitch (setq _Angle_Pitch __Angle_Pitch)) _Angle_Pitch)
  (:serialization-length
   ()
   (+
    ;; int32 _waist_flag
    4
    ;; float64 _Angle_Yaw
    8
    ;; float64 _Angle_Pitch
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _waist_flag
       (write-long _waist_flag s)
     ;; float64 _Angle_Yaw
       (sys::poke _Angle_Yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Angle_Pitch
       (sys::poke _Angle_Pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _waist_flag
     (setq _waist_flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _Angle_Yaw
     (setq _Angle_Yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Angle_Pitch
     (setq _Angle_Pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::pan_tilt_msg :md5sum-) "611b91cd650b11bf3bb556113e5f1029")
(setf (get msg_generate::pan_tilt_msg :datatype-) "msg_generate/pan_tilt_msg")
(setf (get msg_generate::pan_tilt_msg :definition-)
      "int32 waist_flag

float64 Angle_Yaw
float64 Angle_Pitch

")



(provide :msg_generate/pan_tilt_msg "611b91cd650b11bf3bb556113e5f1029")


