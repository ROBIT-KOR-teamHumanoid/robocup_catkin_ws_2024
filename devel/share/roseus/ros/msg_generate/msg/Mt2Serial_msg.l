;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Mt2Serial_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Mt2Serial_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MT2SERIAL_MSG")
  (make-package "MSG_GENERATE::MT2SERIAL_MSG"))

(in-package "ROS")
;;//! \htmlinclude Mt2Serial_msg.msg.html


(defclass msg_generate::Mt2Serial_msg
  :super ros::object
  :slots (_Motion_Mode _Motion_Num ))

(defmethod msg_generate::Mt2Serial_msg
  (:init
   (&key
    ((:Motion_Mode __Motion_Mode) 0)
    ((:Motion_Num __Motion_Num) 0)
    )
   (send-super :init)
   (setq _Motion_Mode (round __Motion_Mode))
   (setq _Motion_Num (round __Motion_Num))
   self)
  (:Motion_Mode
   (&optional __Motion_Mode)
   (if __Motion_Mode (setq _Motion_Mode __Motion_Mode)) _Motion_Mode)
  (:Motion_Num
   (&optional __Motion_Num)
   (if __Motion_Num (setq _Motion_Num __Motion_Num)) _Motion_Num)
  (:serialization-length
   ()
   (+
    ;; int32 _Motion_Mode
    4
    ;; int32 _Motion_Num
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _Motion_Mode
       (write-long _Motion_Mode s)
     ;; int32 _Motion_Num
       (write-long _Motion_Num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _Motion_Mode
     (setq _Motion_Mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Motion_Num
     (setq _Motion_Num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::Mt2Serial_msg :md5sum-) "e3f9ec431b0fdc81956c12a8b317c691")
(setf (get msg_generate::Mt2Serial_msg :datatype-) "msg_generate/Mt2Serial_msg")
(setf (get msg_generate::Mt2Serial_msg :definition-)
      "int32 Motion_Mode
int32 Motion_Num

")



(provide :msg_generate/Mt2Serial_msg "e3f9ec431b0fdc81956c12a8b317c691")


