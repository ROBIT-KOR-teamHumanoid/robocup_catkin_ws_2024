;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::support_onestep_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'support_onestep_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::SUPPORT_ONESTEP_MSG")
  (make-package "MSG_GENERATE::SUPPORT_ONESTEP_MSG"))

(in-package "ROS")
;;//! \htmlinclude support_onestep_msg.msg.html


(defclass msg_generate::support_onestep_msg
  :super ros::object
  :slots (_onestep_checker ))

(defmethod msg_generate::support_onestep_msg
  (:init
   (&key
    ((:onestep_checker __onestep_checker) 0)
    )
   (send-super :init)
   (setq _onestep_checker (round __onestep_checker))
   self)
  (:onestep_checker
   (&optional __onestep_checker)
   (if __onestep_checker (setq _onestep_checker __onestep_checker)) _onestep_checker)
  (:serialization-length
   ()
   (+
    ;; int32 _onestep_checker
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _onestep_checker
       (write-long _onestep_checker s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _onestep_checker
     (setq _onestep_checker (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::support_onestep_msg :md5sum-) "260ab72f5eacc5be420032b06460a43f")
(setf (get msg_generate::support_onestep_msg :datatype-) "msg_generate/support_onestep_msg")
(setf (get msg_generate::support_onestep_msg :definition-)
      "int32 onestep_checker

")



(provide :msg_generate/support_onestep_msg "260ab72f5eacc5be420032b06460a43f")


