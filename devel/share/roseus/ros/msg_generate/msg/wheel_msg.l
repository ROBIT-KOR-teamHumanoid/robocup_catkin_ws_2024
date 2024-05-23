;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::wheel_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'wheel_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::WHEEL_MSG")
  (make-package "MSG_GENERATE::WHEEL_MSG"))

(in-package "ROS")
;;//! \htmlinclude wheel_msg.msg.html


(defclass msg_generate::wheel_msg
  :super ros::object
  :slots (_ang_r_0 _ang_r_1 ))

(defmethod msg_generate::wheel_msg
  (:init
   (&key
    ((:ang_r_0 __ang_r_0) 0.0)
    ((:ang_r_1 __ang_r_1) 0.0)
    )
   (send-super :init)
   (setq _ang_r_0 (float __ang_r_0))
   (setq _ang_r_1 (float __ang_r_1))
   self)
  (:ang_r_0
   (&optional __ang_r_0)
   (if __ang_r_0 (setq _ang_r_0 __ang_r_0)) _ang_r_0)
  (:ang_r_1
   (&optional __ang_r_1)
   (if __ang_r_1 (setq _ang_r_1 __ang_r_1)) _ang_r_1)
  (:serialization-length
   ()
   (+
    ;; float64 _ang_r_0
    8
    ;; float64 _ang_r_1
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _ang_r_0
       (sys::poke _ang_r_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_1
       (sys::poke _ang_r_1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _ang_r_0
     (setq _ang_r_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_1
     (setq _ang_r_1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::wheel_msg :md5sum-) "56b78b37c2cdbee448584402f58a25fd")
(setf (get msg_generate::wheel_msg :datatype-) "msg_generate/wheel_msg")
(setf (get msg_generate::wheel_msg :definition-)
      "float64 ang_r_0
float64 ang_r_1



")



(provide :msg_generate/wheel_msg "56b78b37c2cdbee448584402f58a25fd")


