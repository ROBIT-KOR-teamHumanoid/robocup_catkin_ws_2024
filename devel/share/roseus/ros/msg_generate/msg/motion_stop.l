;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::motion_stop)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'motion_stop (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MOTION_STOP")
  (make-package "MSG_GENERATE::MOTION_STOP"))

(in-package "ROS")
;;//! \htmlinclude motion_stop.msg.html


(defclass msg_generate::motion_stop
  :super ros::object
  :slots (_motion_stop ))

(defmethod msg_generate::motion_stop
  (:init
   (&key
    ((:motion_stop __motion_stop) nil)
    )
   (send-super :init)
   (setq _motion_stop __motion_stop)
   self)
  (:motion_stop
   (&optional __motion_stop)
   (if __motion_stop (setq _motion_stop __motion_stop)) _motion_stop)
  (:serialization-length
   ()
   (+
    ;; bool _motion_stop
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _motion_stop
       (if _motion_stop (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _motion_stop
     (setq _motion_stop (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::motion_stop :md5sum-) "26a67ab0046f1f409ea3537c40f97362")
(setf (get msg_generate::motion_stop :datatype-) "msg_generate/motion_stop")
(setf (get msg_generate::motion_stop :definition-)
      "bool motion_stop

")



(provide :msg_generate/motion_stop "26a67ab0046f1f409ea3537c40f97362")


