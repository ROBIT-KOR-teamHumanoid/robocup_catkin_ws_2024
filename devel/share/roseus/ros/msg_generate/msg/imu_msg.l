;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::imu_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'imu_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::IMU_MSG")
  (make-package "MSG_GENERATE::IMU_MSG"))

(in-package "ROS")
;;//! \htmlinclude imu_msg.msg.html


(defclass msg_generate::imu_msg
  :super ros::object
  :slots (_roll _pitch _yaw _roll_acc _pitch_acc _yaw_acc ))

(defmethod msg_generate::imu_msg
  (:init
   (&key
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    ((:yaw __yaw) 0.0)
    ((:roll_acc __roll_acc) 0.0)
    ((:pitch_acc __pitch_acc) 0.0)
    ((:yaw_acc __yaw_acc) 0.0)
    )
   (send-super :init)
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   (setq _yaw (float __yaw))
   (setq _roll_acc (float __roll_acc))
   (setq _pitch_acc (float __pitch_acc))
   (setq _yaw_acc (float __yaw_acc))
   self)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:roll_acc
   (&optional __roll_acc)
   (if __roll_acc (setq _roll_acc __roll_acc)) _roll_acc)
  (:pitch_acc
   (&optional __pitch_acc)
   (if __pitch_acc (setq _pitch_acc __pitch_acc)) _pitch_acc)
  (:yaw_acc
   (&optional __yaw_acc)
   (if __yaw_acc (setq _yaw_acc __yaw_acc)) _yaw_acc)
  (:serialization-length
   ()
   (+
    ;; float32 _roll
    4
    ;; float32 _pitch
    4
    ;; float32 _yaw
    4
    ;; float32 _roll_acc
    4
    ;; float32 _pitch_acc
    4
    ;; float32 _yaw_acc
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _roll_acc
       (sys::poke _roll_acc (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch_acc
       (sys::poke _pitch_acc (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw_acc
       (sys::poke _yaw_acc (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _roll
     (setq _roll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch
     (setq _pitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _roll_acc
     (setq _roll_acc (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch_acc
     (setq _pitch_acc (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw_acc
     (setq _yaw_acc (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::imu_msg :md5sum-) "7a5074fa2c7055370ef50e1051a0c7bf")
(setf (get msg_generate::imu_msg :datatype-) "msg_generate/imu_msg")
(setf (get msg_generate::imu_msg :definition-)
      "float32 roll
float32 pitch
float32 yaw
float32 roll_acc
float32 pitch_acc
float32 yaw_acc

")



(provide :msg_generate/imu_msg "7a5074fa2c7055370ef50e1051a0c7bf")


