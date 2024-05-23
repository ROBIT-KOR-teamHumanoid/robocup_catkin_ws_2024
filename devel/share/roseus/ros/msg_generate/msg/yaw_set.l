;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::yaw_set)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'yaw_set (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::YAW_SET")
  (make-package "MSG_GENERATE::YAW_SET"))

(in-package "ROS")
;;//! \htmlinclude yaw_set.msg.html


(defclass msg_generate::yaw_set
  :super ros::object
  :slots (_isYawSet ))

(defmethod msg_generate::yaw_set
  (:init
   (&key
    ((:isYawSet __isYawSet) nil)
    )
   (send-super :init)
   (setq _isYawSet __isYawSet)
   self)
  (:isYawSet
   (&optional __isYawSet)
   (if __isYawSet (setq _isYawSet __isYawSet)) _isYawSet)
  (:serialization-length
   ()
   (+
    ;; bool _isYawSet
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isYawSet
       (if _isYawSet (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isYawSet
     (setq _isYawSet (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::yaw_set :md5sum-) "dd1fd0ebc1d42598eb0e74fe046655f8")
(setf (get msg_generate::yaw_set :datatype-) "msg_generate/yaw_set")
(setf (get msg_generate::yaw_set :definition-)
      "bool isYawSet

")



(provide :msg_generate/yaw_set "dd1fd0ebc1d42598eb0e74fe046655f8")


