;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::com_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'com_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::COM_MSG")
  (make-package "MSG_GENERATE::COM_MSG"))

(in-package "ROS")
;;//! \htmlinclude com_msg.msg.html


(defclass msg_generate::com_msg
  :super ros::object
  :slots (_X_com _Y_com ))

(defmethod msg_generate::com_msg
  (:init
   (&key
    ((:X_com __X_com) 0.0)
    ((:Y_com __Y_com) 0.0)
    )
   (send-super :init)
   (setq _X_com (float __X_com))
   (setq _Y_com (float __Y_com))
   self)
  (:X_com
   (&optional __X_com)
   (if __X_com (setq _X_com __X_com)) _X_com)
  (:Y_com
   (&optional __Y_com)
   (if __Y_com (setq _Y_com __Y_com)) _Y_com)
  (:serialization-length
   ()
   (+
    ;; float64 _X_com
    8
    ;; float64 _Y_com
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _X_com
       (sys::poke _X_com (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Y_com
       (sys::poke _Y_com (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _X_com
     (setq _X_com (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Y_com
     (setq _Y_com (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::com_msg :md5sum-) "47867f34a56c5603eede6e151741abd1")
(setf (get msg_generate::com_msg :datatype-) "msg_generate/com_msg")
(setf (get msg_generate::com_msg :definition-)
      "float64 X_com
float64 Y_com

")



(provide :msg_generate/com_msg "47867f34a56c5603eede6e151741abd1")


