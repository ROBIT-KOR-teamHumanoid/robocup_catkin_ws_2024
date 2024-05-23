;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::zmp_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'zmp_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ZMP_MSG")
  (make-package "MSG_GENERATE::ZMP_MSG"))

(in-package "ROS")
;;//! \htmlinclude zmp_msg.msg.html


(defclass msg_generate::zmp_msg
  :super ros::object
  :slots (_Left_X_zmp _Left_Y_zmp _Right_X_zmp _Right_Y_zmp _Total_X_zmp _Total_Y_zmp _Left_Foot _Right_Foot _Both_Feet ))

(defmethod msg_generate::zmp_msg
  (:init
   (&key
    ((:Left_X_zmp __Left_X_zmp) 0.0)
    ((:Left_Y_zmp __Left_Y_zmp) 0.0)
    ((:Right_X_zmp __Right_X_zmp) 0.0)
    ((:Right_Y_zmp __Right_Y_zmp) 0.0)
    ((:Total_X_zmp __Total_X_zmp) 0.0)
    ((:Total_Y_zmp __Total_Y_zmp) 0.0)
    ((:Left_Foot __Left_Foot) nil)
    ((:Right_Foot __Right_Foot) nil)
    ((:Both_Feet __Both_Feet) nil)
    )
   (send-super :init)
   (setq _Left_X_zmp (float __Left_X_zmp))
   (setq _Left_Y_zmp (float __Left_Y_zmp))
   (setq _Right_X_zmp (float __Right_X_zmp))
   (setq _Right_Y_zmp (float __Right_Y_zmp))
   (setq _Total_X_zmp (float __Total_X_zmp))
   (setq _Total_Y_zmp (float __Total_Y_zmp))
   (setq _Left_Foot __Left_Foot)
   (setq _Right_Foot __Right_Foot)
   (setq _Both_Feet __Both_Feet)
   self)
  (:Left_X_zmp
   (&optional __Left_X_zmp)
   (if __Left_X_zmp (setq _Left_X_zmp __Left_X_zmp)) _Left_X_zmp)
  (:Left_Y_zmp
   (&optional __Left_Y_zmp)
   (if __Left_Y_zmp (setq _Left_Y_zmp __Left_Y_zmp)) _Left_Y_zmp)
  (:Right_X_zmp
   (&optional __Right_X_zmp)
   (if __Right_X_zmp (setq _Right_X_zmp __Right_X_zmp)) _Right_X_zmp)
  (:Right_Y_zmp
   (&optional __Right_Y_zmp)
   (if __Right_Y_zmp (setq _Right_Y_zmp __Right_Y_zmp)) _Right_Y_zmp)
  (:Total_X_zmp
   (&optional __Total_X_zmp)
   (if __Total_X_zmp (setq _Total_X_zmp __Total_X_zmp)) _Total_X_zmp)
  (:Total_Y_zmp
   (&optional __Total_Y_zmp)
   (if __Total_Y_zmp (setq _Total_Y_zmp __Total_Y_zmp)) _Total_Y_zmp)
  (:Left_Foot
   (&optional __Left_Foot)
   (if __Left_Foot (setq _Left_Foot __Left_Foot)) _Left_Foot)
  (:Right_Foot
   (&optional __Right_Foot)
   (if __Right_Foot (setq _Right_Foot __Right_Foot)) _Right_Foot)
  (:Both_Feet
   (&optional __Both_Feet)
   (if __Both_Feet (setq _Both_Feet __Both_Feet)) _Both_Feet)
  (:serialization-length
   ()
   (+
    ;; float64 _Left_X_zmp
    8
    ;; float64 _Left_Y_zmp
    8
    ;; float64 _Right_X_zmp
    8
    ;; float64 _Right_Y_zmp
    8
    ;; float64 _Total_X_zmp
    8
    ;; float64 _Total_Y_zmp
    8
    ;; bool _Left_Foot
    1
    ;; bool _Right_Foot
    1
    ;; bool _Both_Feet
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Left_X_zmp
       (sys::poke _Left_X_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Left_Y_zmp
       (sys::poke _Left_Y_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Right_X_zmp
       (sys::poke _Right_X_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Right_Y_zmp
       (sys::poke _Right_Y_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Total_X_zmp
       (sys::poke _Total_X_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Total_Y_zmp
       (sys::poke _Total_Y_zmp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _Left_Foot
       (if _Left_Foot (write-byte -1 s) (write-byte 0 s))
     ;; bool _Right_Foot
       (if _Right_Foot (write-byte -1 s) (write-byte 0 s))
     ;; bool _Both_Feet
       (if _Both_Feet (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Left_X_zmp
     (setq _Left_X_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Left_Y_zmp
     (setq _Left_Y_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Right_X_zmp
     (setq _Right_X_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Right_Y_zmp
     (setq _Right_Y_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Total_X_zmp
     (setq _Total_X_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Total_Y_zmp
     (setq _Total_Y_zmp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _Left_Foot
     (setq _Left_Foot (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Right_Foot
     (setq _Right_Foot (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Both_Feet
     (setq _Both_Feet (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::zmp_msg :md5sum-) "b6dd8aae25ccfd762514817678c236ea")
(setf (get msg_generate::zmp_msg :datatype-) "msg_generate/zmp_msg")
(setf (get msg_generate::zmp_msg :definition-)
      "float64 Left_X_zmp
float64 Left_Y_zmp
float64 Right_X_zmp
float64 Right_Y_zmp
float64 Total_X_zmp
float64 Total_Y_zmp
bool Left_Foot
bool Right_Foot
bool Both_Feet

")



(provide :msg_generate/zmp_msg "b6dd8aae25ccfd762514817678c236ea")


