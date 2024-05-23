;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::angle2)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'angle2 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ANGLE2")
  (make-package "MSG_GENERATE::ANGLE2"))

(in-package "ROS")
;;//! \htmlinclude angle2.msg.html


(defclass msg_generate::angle2
  :super ros::object
  :slots (_ang_r_0 _ang_r_1 _ang_r_2 _ang_r_3 _ang_r_4 _ang_r_5 _ang_l_0 _ang_l_1 _ang_l_2 _ang_l_3 _ang_l_4 _ang_l_5 ))

(defmethod msg_generate::angle2
  (:init
   (&key
    ((:ang_r_0 __ang_r_0) 0.0)
    ((:ang_r_1 __ang_r_1) 0.0)
    ((:ang_r_2 __ang_r_2) 0.0)
    ((:ang_r_3 __ang_r_3) 0.0)
    ((:ang_r_4 __ang_r_4) 0.0)
    ((:ang_r_5 __ang_r_5) 0.0)
    ((:ang_l_0 __ang_l_0) 0.0)
    ((:ang_l_1 __ang_l_1) 0.0)
    ((:ang_l_2 __ang_l_2) 0.0)
    ((:ang_l_3 __ang_l_3) 0.0)
    ((:ang_l_4 __ang_l_4) 0.0)
    ((:ang_l_5 __ang_l_5) 0.0)
    )
   (send-super :init)
   (setq _ang_r_0 (float __ang_r_0))
   (setq _ang_r_1 (float __ang_r_1))
   (setq _ang_r_2 (float __ang_r_2))
   (setq _ang_r_3 (float __ang_r_3))
   (setq _ang_r_4 (float __ang_r_4))
   (setq _ang_r_5 (float __ang_r_5))
   (setq _ang_l_0 (float __ang_l_0))
   (setq _ang_l_1 (float __ang_l_1))
   (setq _ang_l_2 (float __ang_l_2))
   (setq _ang_l_3 (float __ang_l_3))
   (setq _ang_l_4 (float __ang_l_4))
   (setq _ang_l_5 (float __ang_l_5))
   self)
  (:ang_r_0
   (&optional __ang_r_0)
   (if __ang_r_0 (setq _ang_r_0 __ang_r_0)) _ang_r_0)
  (:ang_r_1
   (&optional __ang_r_1)
   (if __ang_r_1 (setq _ang_r_1 __ang_r_1)) _ang_r_1)
  (:ang_r_2
   (&optional __ang_r_2)
   (if __ang_r_2 (setq _ang_r_2 __ang_r_2)) _ang_r_2)
  (:ang_r_3
   (&optional __ang_r_3)
   (if __ang_r_3 (setq _ang_r_3 __ang_r_3)) _ang_r_3)
  (:ang_r_4
   (&optional __ang_r_4)
   (if __ang_r_4 (setq _ang_r_4 __ang_r_4)) _ang_r_4)
  (:ang_r_5
   (&optional __ang_r_5)
   (if __ang_r_5 (setq _ang_r_5 __ang_r_5)) _ang_r_5)
  (:ang_l_0
   (&optional __ang_l_0)
   (if __ang_l_0 (setq _ang_l_0 __ang_l_0)) _ang_l_0)
  (:ang_l_1
   (&optional __ang_l_1)
   (if __ang_l_1 (setq _ang_l_1 __ang_l_1)) _ang_l_1)
  (:ang_l_2
   (&optional __ang_l_2)
   (if __ang_l_2 (setq _ang_l_2 __ang_l_2)) _ang_l_2)
  (:ang_l_3
   (&optional __ang_l_3)
   (if __ang_l_3 (setq _ang_l_3 __ang_l_3)) _ang_l_3)
  (:ang_l_4
   (&optional __ang_l_4)
   (if __ang_l_4 (setq _ang_l_4 __ang_l_4)) _ang_l_4)
  (:ang_l_5
   (&optional __ang_l_5)
   (if __ang_l_5 (setq _ang_l_5 __ang_l_5)) _ang_l_5)
  (:serialization-length
   ()
   (+
    ;; float64 _ang_r_0
    8
    ;; float64 _ang_r_1
    8
    ;; float64 _ang_r_2
    8
    ;; float64 _ang_r_3
    8
    ;; float64 _ang_r_4
    8
    ;; float64 _ang_r_5
    8
    ;; float64 _ang_l_0
    8
    ;; float64 _ang_l_1
    8
    ;; float64 _ang_l_2
    8
    ;; float64 _ang_l_3
    8
    ;; float64 _ang_l_4
    8
    ;; float64 _ang_l_5
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _ang_r_0
       (sys::poke _ang_r_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_1
       (sys::poke _ang_r_1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_2
       (sys::poke _ang_r_2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_3
       (sys::poke _ang_r_3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_4
       (sys::poke _ang_r_4 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_r_5
       (sys::poke _ang_r_5 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_0
       (sys::poke _ang_l_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_1
       (sys::poke _ang_l_1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_2
       (sys::poke _ang_l_2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_3
       (sys::poke _ang_l_3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_4
       (sys::poke _ang_l_4 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ang_l_5
       (sys::poke _ang_l_5 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _ang_r_0
     (setq _ang_r_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_1
     (setq _ang_r_1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_2
     (setq _ang_r_2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_3
     (setq _ang_r_3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_4
     (setq _ang_r_4 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_r_5
     (setq _ang_r_5 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_0
     (setq _ang_l_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_1
     (setq _ang_l_1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_2
     (setq _ang_l_2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_3
     (setq _ang_l_3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_4
     (setq _ang_l_4 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ang_l_5
     (setq _ang_l_5 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::angle2 :md5sum-) "fb3bce9c774e8adb8b04618b1b2cb9fc")
(setf (get msg_generate::angle2 :datatype-) "msg_generate/angle2")
(setf (get msg_generate::angle2 :definition-)
      "float64 ang_r_0
float64 ang_r_1
float64 ang_r_2
float64 ang_r_3
float64 ang_r_4
float64 ang_r_5
float64 ang_l_0
float64 ang_l_1
float64 ang_l_2
float64 ang_l_3
float64 ang_l_4
float64 ang_l_5

")



(provide :msg_generate/angle2 "fb3bce9c774e8adb8b04618b1b2cb9fc")


