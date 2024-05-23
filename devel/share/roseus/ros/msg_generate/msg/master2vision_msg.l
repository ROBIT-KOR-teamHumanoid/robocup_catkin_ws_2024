;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::master2vision_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'master2vision_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MASTER2VISION_MSG")
  (make-package "MSG_GENERATE::MASTER2VISION_MSG"))

(in-package "ROS")
;;//! \htmlinclude master2vision_msg.msg.html


(defclass msg_generate::master2vision_msg
  :super ros::object
  :slots (_TILT _PAN ))

(defmethod msg_generate::master2vision_msg
  (:init
   (&key
    ((:TILT __TILT) 0.0)
    ((:PAN __PAN) 0.0)
    )
   (send-super :init)
   (setq _TILT (float __TILT))
   (setq _PAN (float __PAN))
   self)
  (:TILT
   (&optional __TILT)
   (if __TILT (setq _TILT __TILT)) _TILT)
  (:PAN
   (&optional __PAN)
   (if __PAN (setq _PAN __PAN)) _PAN)
  (:serialization-length
   ()
   (+
    ;; float64 _TILT
    8
    ;; float64 _PAN
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _TILT
       (sys::poke _TILT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _PAN
       (sys::poke _PAN (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _TILT
     (setq _TILT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _PAN
     (setq _PAN (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::master2vision_msg :md5sum-) "8e3fffe76719ba65b10a2f461e54333b")
(setf (get msg_generate::master2vision_msg :datatype-) "msg_generate/master2vision_msg")
(setf (get msg_generate::master2vision_msg :definition-)
      "float64 TILT
float64 PAN

")



(provide :msg_generate/master2vision_msg "8e3fffe76719ba65b10a2f461e54333b")


