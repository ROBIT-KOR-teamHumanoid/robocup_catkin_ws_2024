;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::ik_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'ik_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::IK_MSG")
  (make-package "MSG_GENERATE::IK_MSG"))

(in-package "ROS")
;;//! \htmlinclude ik_msg.msg.html


(defclass msg_generate::ik_msg
  :super ros::object
  :slots (_X_length _Y_length _Yaw _flag _One_X_length _One_Y_length _One_YAW _One_step_flag ))

(defmethod msg_generate::ik_msg
  (:init
   (&key
    ((:X_length __X_length) 0.0)
    ((:Y_length __Y_length) 0.0)
    ((:Yaw __Yaw) 0.0)
    ((:flag __flag) 0.0)
    ((:One_X_length __One_X_length) 0)
    ((:One_Y_length __One_Y_length) 0)
    ((:One_YAW __One_YAW) 0)
    ((:One_step_flag __One_step_flag) 0)
    )
   (send-super :init)
   (setq _X_length (float __X_length))
   (setq _Y_length (float __Y_length))
   (setq _Yaw (float __Yaw))
   (setq _flag (float __flag))
   (setq _One_X_length (round __One_X_length))
   (setq _One_Y_length (round __One_Y_length))
   (setq _One_YAW (round __One_YAW))
   (setq _One_step_flag (round __One_step_flag))
   self)
  (:X_length
   (&optional __X_length)
   (if __X_length (setq _X_length __X_length)) _X_length)
  (:Y_length
   (&optional __Y_length)
   (if __Y_length (setq _Y_length __Y_length)) _Y_length)
  (:Yaw
   (&optional __Yaw)
   (if __Yaw (setq _Yaw __Yaw)) _Yaw)
  (:flag
   (&optional __flag)
   (if __flag (setq _flag __flag)) _flag)
  (:One_X_length
   (&optional __One_X_length)
   (if __One_X_length (setq _One_X_length __One_X_length)) _One_X_length)
  (:One_Y_length
   (&optional __One_Y_length)
   (if __One_Y_length (setq _One_Y_length __One_Y_length)) _One_Y_length)
  (:One_YAW
   (&optional __One_YAW)
   (if __One_YAW (setq _One_YAW __One_YAW)) _One_YAW)
  (:One_step_flag
   (&optional __One_step_flag)
   (if __One_step_flag (setq _One_step_flag __One_step_flag)) _One_step_flag)
  (:serialization-length
   ()
   (+
    ;; float64 _X_length
    8
    ;; float64 _Y_length
    8
    ;; float64 _Yaw
    8
    ;; float64 _flag
    8
    ;; int32 _One_X_length
    4
    ;; int32 _One_Y_length
    4
    ;; int32 _One_YAW
    4
    ;; int32 _One_step_flag
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _X_length
       (sys::poke _X_length (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Y_length
       (sys::poke _Y_length (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Yaw
       (sys::poke _Yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _flag
       (sys::poke _flag (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _One_X_length
       (write-long _One_X_length s)
     ;; int32 _One_Y_length
       (write-long _One_Y_length s)
     ;; int32 _One_YAW
       (write-long _One_YAW s)
     ;; int32 _One_step_flag
       (write-long _One_step_flag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _X_length
     (setq _X_length (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Y_length
     (setq _Y_length (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Yaw
     (setq _Yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _flag
     (setq _flag (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _One_X_length
     (setq _One_X_length (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _One_Y_length
     (setq _One_Y_length (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _One_YAW
     (setq _One_YAW (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _One_step_flag
     (setq _One_step_flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::ik_msg :md5sum-) "1e34403e3b7a9f4022bce7eaacc3d24d")
(setf (get msg_generate::ik_msg :datatype-) "msg_generate/ik_msg")
(setf (get msg_generate::ik_msg :definition-)
      "float64 X_length
float64 Y_length
float64 Yaw
float64 flag

int32 One_X_length
int32 One_Y_length
int32 One_YAW
int32 One_step_flag



")



(provide :msg_generate/ik_msg "1e34403e3b7a9f4022bce7eaacc3d24d")


