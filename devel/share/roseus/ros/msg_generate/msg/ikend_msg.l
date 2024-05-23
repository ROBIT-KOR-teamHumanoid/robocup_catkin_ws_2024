;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::ikend_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'ikend_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::IKEND_MSG")
  (make-package "MSG_GENERATE::IKEND_MSG"))

(in-package "ROS")
;;//! \htmlinclude ikend_msg.msg.html


(defclass msg_generate::ikend_msg
  :super ros::object
  :slots (_ikend _onestep_end ))

(defmethod msg_generate::ikend_msg
  (:init
   (&key
    ((:ikend __ikend) 0)
    ((:onestep_end __onestep_end) 0)
    )
   (send-super :init)
   (setq _ikend (round __ikend))
   (setq _onestep_end (round __onestep_end))
   self)
  (:ikend
   (&optional __ikend)
   (if __ikend (setq _ikend __ikend)) _ikend)
  (:onestep_end
   (&optional __onestep_end)
   (if __onestep_end (setq _onestep_end __onestep_end)) _onestep_end)
  (:serialization-length
   ()
   (+
    ;; int32 _ikend
    4
    ;; int32 _onestep_end
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _ikend
       (write-long _ikend s)
     ;; int32 _onestep_end
       (write-long _onestep_end s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _ikend
     (setq _ikend (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _onestep_end
     (setq _onestep_end (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::ikend_msg :md5sum-) "927f1106013c7f12a325ab4e0c8eb54f")
(setf (get msg_generate::ikend_msg :datatype-) "msg_generate/ikend_msg")
(setf (get msg_generate::ikend_msg :definition-)
      "int32 ikend
int32 onestep_end

")



(provide :msg_generate/ikend_msg "927f1106013c7f12a325ab4e0c8eb54f")


