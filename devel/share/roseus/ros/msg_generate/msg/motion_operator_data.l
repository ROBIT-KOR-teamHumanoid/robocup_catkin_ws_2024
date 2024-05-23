;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::motion_operator_data)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'motion_operator_data (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MOTION_OPERATOR_DATA")
  (make-package "MSG_GENERATE::MOTION_OPERATOR_DATA"))

(in-package "ROS")
;;//! \htmlinclude motion_operator_data.msg.html


(defclass msg_generate::motion_operator_data
  :super ros::object
  :slots (_yaw_data _startmotion ))

(defmethod msg_generate::motion_operator_data
  (:init
   (&key
    ((:yaw_data __yaw_data) 0)
    ((:startmotion __startmotion) 0)
    )
   (send-super :init)
   (setq _yaw_data (round __yaw_data))
   (setq _startmotion (round __startmotion))
   self)
  (:yaw_data
   (&optional __yaw_data)
   (if __yaw_data (setq _yaw_data __yaw_data)) _yaw_data)
  (:startmotion
   (&optional __startmotion)
   (if __startmotion (setq _startmotion __startmotion)) _startmotion)
  (:serialization-length
   ()
   (+
    ;; int32 _yaw_data
    4
    ;; int32 _startmotion
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _yaw_data
       (write-long _yaw_data s)
     ;; int32 _startmotion
       (write-long _startmotion s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _yaw_data
     (setq _yaw_data (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _startmotion
     (setq _startmotion (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::motion_operator_data :md5sum-) "ca7ee85fd473a08527f7d102be53f660")
(setf (get msg_generate::motion_operator_data :datatype-) "msg_generate/motion_operator_data")
(setf (get msg_generate::motion_operator_data :definition-)
      "int32 yaw_data
int32 startmotion


")



(provide :msg_generate/motion_operator_data "ca7ee85fd473a08527f7d102be53f660")


