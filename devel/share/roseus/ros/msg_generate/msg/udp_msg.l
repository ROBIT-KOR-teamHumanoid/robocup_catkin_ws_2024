;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::udp_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'udp_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::UDP_MSG")
  (make-package "MSG_GENERATE::UDP_MSG"))

(in-package "ROS")
;;//! \htmlinclude udp_msg.msg.html


(defclass msg_generate::udp_msg
  :super ros::object
  :slots (_field_area _ball_area _robocup_case _ballDist ))

(defmethod msg_generate::udp_msg
  (:init
   (&key
    ((:field_area __field_area) 0)
    ((:ball_area __ball_area) 0)
    ((:robocup_case __robocup_case) 0)
    ((:ballDist __ballDist) 0.0)
    )
   (send-super :init)
   (setq _field_area (round __field_area))
   (setq _ball_area (round __ball_area))
   (setq _robocup_case (round __robocup_case))
   (setq _ballDist (float __ballDist))
   self)
  (:field_area
   (&optional __field_area)
   (if __field_area (setq _field_area __field_area)) _field_area)
  (:ball_area
   (&optional __ball_area)
   (if __ball_area (setq _ball_area __ball_area)) _ball_area)
  (:robocup_case
   (&optional __robocup_case)
   (if __robocup_case (setq _robocup_case __robocup_case)) _robocup_case)
  (:ballDist
   (&optional __ballDist)
   (if __ballDist (setq _ballDist __ballDist)) _ballDist)
  (:serialization-length
   ()
   (+
    ;; int32 _field_area
    4
    ;; int32 _ball_area
    4
    ;; int32 _robocup_case
    4
    ;; float64 _ballDist
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _field_area
       (write-long _field_area s)
     ;; int32 _ball_area
       (write-long _ball_area s)
     ;; int32 _robocup_case
       (write-long _robocup_case s)
     ;; float64 _ballDist
       (sys::poke _ballDist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _field_area
     (setq _field_area (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _ball_area
     (setq _ball_area (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _robocup_case
     (setq _robocup_case (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _ballDist
     (setq _ballDist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::udp_msg :md5sum-) "705379b613a1dfa415f111dd5f542624")
(setf (get msg_generate::udp_msg :datatype-) "msg_generate/udp_msg")
(setf (get msg_generate::udp_msg :definition-)
      "int32 field_area
int32 ball_area
int32 robocup_case
float64 ballDist

")



(provide :msg_generate/udp_msg "705379b613a1dfa415f111dd5f542624")


