;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::ikcoordinate_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'ikcoordinate_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::IKCOORDINATE_MSG")
  (make-package "MSG_GENERATE::IKCOORDINATE_MSG"))

(in-package "ROS")
;;//! \htmlinclude ikcoordinate_msg.msg.html


(defclass msg_generate::ikcoordinate_msg
  :super ros::object
  :slots (_X _Y ))

(defmethod msg_generate::ikcoordinate_msg
  (:init
   (&key
    ((:X __X) 0)
    ((:Y __Y) 0)
    )
   (send-super :init)
   (setq _X (round __X))
   (setq _Y (round __Y))
   self)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:Y
   (&optional __Y)
   (if __Y (setq _Y __Y)) _Y)
  (:serialization-length
   ()
   (+
    ;; int32 _X
    4
    ;; int32 _Y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _X
       (write-long _X s)
     ;; int32 _Y
       (write-long _Y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _X
     (setq _X (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Y
     (setq _Y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::ikcoordinate_msg :md5sum-) "4d09a2d26153835cde0795d12585c794")
(setf (get msg_generate::ikcoordinate_msg :datatype-) "msg_generate/ikcoordinate_msg")
(setf (get msg_generate::ikcoordinate_msg :definition-)
      "int32 X
int32 Y

")



(provide :msg_generate/ikcoordinate_msg "4d09a2d26153835cde0795d12585c794")


