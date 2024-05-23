;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::pid_tuning)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'pid_tuning (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::PID_TUNING")
  (make-package "MSG_GENERATE::PID_TUNING"))

(in-package "ROS")
;;//! \htmlinclude pid_tuning.msg.html


(defclass msg_generate::pid_tuning
  :super ros::object
  :slots (_Kp _Ki _Kd ))

(defmethod msg_generate::pid_tuning
  (:init
   (&key
    ((:Kp __Kp) 0.0)
    ((:Ki __Ki) 0.0)
    ((:Kd __Kd) 0.0)
    )
   (send-super :init)
   (setq _Kp (float __Kp))
   (setq _Ki (float __Ki))
   (setq _Kd (float __Kd))
   self)
  (:Kp
   (&optional __Kp)
   (if __Kp (setq _Kp __Kp)) _Kp)
  (:Ki
   (&optional __Ki)
   (if __Ki (setq _Ki __Ki)) _Ki)
  (:Kd
   (&optional __Kd)
   (if __Kd (setq _Kd __Kd)) _Kd)
  (:serialization-length
   ()
   (+
    ;; float64 _Kp
    8
    ;; float64 _Ki
    8
    ;; float64 _Kd
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Kp
       (sys::poke _Kp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ki
       (sys::poke _Ki (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Kd
       (sys::poke _Kd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Kp
     (setq _Kp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ki
     (setq _Ki (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Kd
     (setq _Kd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::pid_tuning :md5sum-) "aaaa16f23b4716dd0f817d0839cdbee8")
(setf (get msg_generate::pid_tuning :datatype-) "msg_generate/pid_tuning")
(setf (get msg_generate::pid_tuning :definition-)
      "float64 Kp
float64 Ki
float64 Kd

")



(provide :msg_generate/pid_tuning "aaaa16f23b4716dd0f817d0839cdbee8")


