;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Local_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Local_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::LOCAL_MSG")
  (make-package "MSG_GENERATE::LOCAL_MSG"))

(in-package "ROS")
;;//! \htmlinclude Local_msg.msg.html


(defclass msg_generate::Local_msg
  :super ros::object
  :slots (_Id _dist _theta ))

(defmethod msg_generate::Local_msg
  (:init
   (&key
    ((:Id __Id) 0.0)
    ((:dist __dist) 0.0)
    ((:theta __theta) 0.0)
    )
   (send-super :init)
   (setq _Id (float __Id))
   (setq _dist (float __dist))
   (setq _theta (float __theta))
   self)
  (:Id
   (&optional __Id)
   (if __Id (setq _Id __Id)) _Id)
  (:dist
   (&optional __dist)
   (if __dist (setq _dist __dist)) _dist)
  (:theta
   (&optional __theta)
   (if __theta (setq _theta __theta)) _theta)
  (:serialization-length
   ()
   (+
    ;; float64 _Id
    8
    ;; float64 _dist
    8
    ;; float64 _theta
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Id
       (sys::poke _Id (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dist
       (sys::poke _dist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _theta
       (sys::poke _theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Id
     (setq _Id (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dist
     (setq _dist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _theta
     (setq _theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::Local_msg :md5sum-) "4de6e3c5b2d79698e32a255421b69933")
(setf (get msg_generate::Local_msg :datatype-) "msg_generate/Local_msg")
(setf (get msg_generate::Local_msg :definition-)
      "float64 Id
float64 dist
float64 theta


")



(provide :msg_generate/Local_msg "4de6e3c5b2d79698e32a255421b69933")


