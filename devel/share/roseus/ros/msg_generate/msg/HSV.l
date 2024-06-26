;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::HSV)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'HSV (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::HSV")
  (make-package "MSG_GENERATE::HSV"))

(in-package "ROS")
;;//! \htmlinclude HSV.msg.html


(defclass msg_generate::HSV
  :super ros::object
  :slots (_red1_dis _red1_the _red2_dis _red2_the _blue1_dis _blue1_the _blue2_dis _blue2_the ))

(defmethod msg_generate::HSV
  (:init
   (&key
    ((:red1_dis __red1_dis) 0.0)
    ((:red1_the __red1_the) 0.0)
    ((:red2_dis __red2_dis) 0.0)
    ((:red2_the __red2_the) 0.0)
    ((:blue1_dis __blue1_dis) 0.0)
    ((:blue1_the __blue1_the) 0.0)
    ((:blue2_dis __blue2_dis) 0.0)
    ((:blue2_the __blue2_the) 0.0)
    )
   (send-super :init)
   (setq _red1_dis (float __red1_dis))
   (setq _red1_the (float __red1_the))
   (setq _red2_dis (float __red2_dis))
   (setq _red2_the (float __red2_the))
   (setq _blue1_dis (float __blue1_dis))
   (setq _blue1_the (float __blue1_the))
   (setq _blue2_dis (float __blue2_dis))
   (setq _blue2_the (float __blue2_the))
   self)
  (:red1_dis
   (&optional __red1_dis)
   (if __red1_dis (setq _red1_dis __red1_dis)) _red1_dis)
  (:red1_the
   (&optional __red1_the)
   (if __red1_the (setq _red1_the __red1_the)) _red1_the)
  (:red2_dis
   (&optional __red2_dis)
   (if __red2_dis (setq _red2_dis __red2_dis)) _red2_dis)
  (:red2_the
   (&optional __red2_the)
   (if __red2_the (setq _red2_the __red2_the)) _red2_the)
  (:blue1_dis
   (&optional __blue1_dis)
   (if __blue1_dis (setq _blue1_dis __blue1_dis)) _blue1_dis)
  (:blue1_the
   (&optional __blue1_the)
   (if __blue1_the (setq _blue1_the __blue1_the)) _blue1_the)
  (:blue2_dis
   (&optional __blue2_dis)
   (if __blue2_dis (setq _blue2_dis __blue2_dis)) _blue2_dis)
  (:blue2_the
   (&optional __blue2_the)
   (if __blue2_the (setq _blue2_the __blue2_the)) _blue2_the)
  (:serialization-length
   ()
   (+
    ;; float64 _red1_dis
    8
    ;; float64 _red1_the
    8
    ;; float64 _red2_dis
    8
    ;; float64 _red2_the
    8
    ;; float64 _blue1_dis
    8
    ;; float64 _blue1_the
    8
    ;; float64 _blue2_dis
    8
    ;; float64 _blue2_the
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _red1_dis
       (sys::poke _red1_dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _red1_the
       (sys::poke _red1_the (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _red2_dis
       (sys::poke _red2_dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _red2_the
       (sys::poke _red2_the (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _blue1_dis
       (sys::poke _blue1_dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _blue1_the
       (sys::poke _blue1_the (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _blue2_dis
       (sys::poke _blue2_dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _blue2_the
       (sys::poke _blue2_the (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _red1_dis
     (setq _red1_dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _red1_the
     (setq _red1_the (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _red2_dis
     (setq _red2_dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _red2_the
     (setq _red2_the (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _blue1_dis
     (setq _blue1_dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _blue1_the
     (setq _blue1_the (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _blue2_dis
     (setq _blue2_dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _blue2_the
     (setq _blue2_the (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::HSV :md5sum-) "5e59624369bde37201fa1c7dfe803e91")
(setf (get msg_generate::HSV :datatype-) "msg_generate/HSV")
(setf (get msg_generate::HSV :definition-)
      "float64 red1_dis
float64 red1_the
float64 red2_dis
float64 red2_the
float64 blue1_dis
float64 blue1_the
float64 blue2_dis
float64 blue2_the


")



(provide :msg_generate/HSV "5e59624369bde37201fa1c7dfe803e91")


