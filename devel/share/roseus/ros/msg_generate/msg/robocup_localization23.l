;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::robocup_localization23)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'robocup_localization23 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ROBOCUP_LOCALIZATION23")
  (make-package "MSG_GENERATE::ROBOCUP_LOCALIZATION23"))

(in-package "ROS")
;;//! \htmlinclude robocup_localization23.msg.html


(defclass msg_generate::robocup_localization23
  :super ros::object
  :slots (_Ball_X _Ball_Y _Ball_speed_X _Ball_speed_Y _Robot_X _Robot_Y _Obstacle_X _Obstacle_Y _Obstacle0_X _Obstacle0_Y _Obstacle1_X _Obstacle1_Y _Obstacle2_X _Obstacle2_Y _Obstacle3_X _Obstacle3_Y ))

(defmethod msg_generate::robocup_localization23
  (:init
   (&key
    ((:Ball_X __Ball_X) 0.0)
    ((:Ball_Y __Ball_Y) 0.0)
    ((:Ball_speed_X __Ball_speed_X) 0.0)
    ((:Ball_speed_Y __Ball_speed_Y) 0.0)
    ((:Robot_X __Robot_X) 0.0)
    ((:Robot_Y __Robot_Y) 0.0)
    ((:Obstacle_X __Obstacle_X) 0.0)
    ((:Obstacle_Y __Obstacle_Y) 0.0)
    ((:Obstacle0_X __Obstacle0_X) 0.0)
    ((:Obstacle0_Y __Obstacle0_Y) 0.0)
    ((:Obstacle1_X __Obstacle1_X) 0.0)
    ((:Obstacle1_Y __Obstacle1_Y) 0.0)
    ((:Obstacle2_X __Obstacle2_X) 0.0)
    ((:Obstacle2_Y __Obstacle2_Y) 0.0)
    ((:Obstacle3_X __Obstacle3_X) 0.0)
    ((:Obstacle3_Y __Obstacle3_Y) 0.0)
    )
   (send-super :init)
   (setq _Ball_X (float __Ball_X))
   (setq _Ball_Y (float __Ball_Y))
   (setq _Ball_speed_X (float __Ball_speed_X))
   (setq _Ball_speed_Y (float __Ball_speed_Y))
   (setq _Robot_X (float __Robot_X))
   (setq _Robot_Y (float __Robot_Y))
   (setq _Obstacle_X (float __Obstacle_X))
   (setq _Obstacle_Y (float __Obstacle_Y))
   (setq _Obstacle0_X (float __Obstacle0_X))
   (setq _Obstacle0_Y (float __Obstacle0_Y))
   (setq _Obstacle1_X (float __Obstacle1_X))
   (setq _Obstacle1_Y (float __Obstacle1_Y))
   (setq _Obstacle2_X (float __Obstacle2_X))
   (setq _Obstacle2_Y (float __Obstacle2_Y))
   (setq _Obstacle3_X (float __Obstacle3_X))
   (setq _Obstacle3_Y (float __Obstacle3_Y))
   self)
  (:Ball_X
   (&optional __Ball_X)
   (if __Ball_X (setq _Ball_X __Ball_X)) _Ball_X)
  (:Ball_Y
   (&optional __Ball_Y)
   (if __Ball_Y (setq _Ball_Y __Ball_Y)) _Ball_Y)
  (:Ball_speed_X
   (&optional __Ball_speed_X)
   (if __Ball_speed_X (setq _Ball_speed_X __Ball_speed_X)) _Ball_speed_X)
  (:Ball_speed_Y
   (&optional __Ball_speed_Y)
   (if __Ball_speed_Y (setq _Ball_speed_Y __Ball_speed_Y)) _Ball_speed_Y)
  (:Robot_X
   (&optional __Robot_X)
   (if __Robot_X (setq _Robot_X __Robot_X)) _Robot_X)
  (:Robot_Y
   (&optional __Robot_Y)
   (if __Robot_Y (setq _Robot_Y __Robot_Y)) _Robot_Y)
  (:Obstacle_X
   (&optional __Obstacle_X)
   (if __Obstacle_X (setq _Obstacle_X __Obstacle_X)) _Obstacle_X)
  (:Obstacle_Y
   (&optional __Obstacle_Y)
   (if __Obstacle_Y (setq _Obstacle_Y __Obstacle_Y)) _Obstacle_Y)
  (:Obstacle0_X
   (&optional __Obstacle0_X)
   (if __Obstacle0_X (setq _Obstacle0_X __Obstacle0_X)) _Obstacle0_X)
  (:Obstacle0_Y
   (&optional __Obstacle0_Y)
   (if __Obstacle0_Y (setq _Obstacle0_Y __Obstacle0_Y)) _Obstacle0_Y)
  (:Obstacle1_X
   (&optional __Obstacle1_X)
   (if __Obstacle1_X (setq _Obstacle1_X __Obstacle1_X)) _Obstacle1_X)
  (:Obstacle1_Y
   (&optional __Obstacle1_Y)
   (if __Obstacle1_Y (setq _Obstacle1_Y __Obstacle1_Y)) _Obstacle1_Y)
  (:Obstacle2_X
   (&optional __Obstacle2_X)
   (if __Obstacle2_X (setq _Obstacle2_X __Obstacle2_X)) _Obstacle2_X)
  (:Obstacle2_Y
   (&optional __Obstacle2_Y)
   (if __Obstacle2_Y (setq _Obstacle2_Y __Obstacle2_Y)) _Obstacle2_Y)
  (:Obstacle3_X
   (&optional __Obstacle3_X)
   (if __Obstacle3_X (setq _Obstacle3_X __Obstacle3_X)) _Obstacle3_X)
  (:Obstacle3_Y
   (&optional __Obstacle3_Y)
   (if __Obstacle3_Y (setq _Obstacle3_Y __Obstacle3_Y)) _Obstacle3_Y)
  (:serialization-length
   ()
   (+
    ;; float64 _Ball_X
    8
    ;; float64 _Ball_Y
    8
    ;; float64 _Ball_speed_X
    8
    ;; float64 _Ball_speed_Y
    8
    ;; float64 _Robot_X
    8
    ;; float64 _Robot_Y
    8
    ;; float64 _Obstacle_X
    8
    ;; float64 _Obstacle_Y
    8
    ;; float64 _Obstacle0_X
    8
    ;; float64 _Obstacle0_Y
    8
    ;; float64 _Obstacle1_X
    8
    ;; float64 _Obstacle1_Y
    8
    ;; float64 _Obstacle2_X
    8
    ;; float64 _Obstacle2_Y
    8
    ;; float64 _Obstacle3_X
    8
    ;; float64 _Obstacle3_Y
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Ball_X
       (sys::poke _Ball_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_Y
       (sys::poke _Ball_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_speed_X
       (sys::poke _Ball_speed_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_speed_Y
       (sys::poke _Ball_speed_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Robot_X
       (sys::poke _Robot_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Robot_Y
       (sys::poke _Robot_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle_X
       (sys::poke _Obstacle_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle_Y
       (sys::poke _Obstacle_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle0_X
       (sys::poke _Obstacle0_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle0_Y
       (sys::poke _Obstacle0_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle1_X
       (sys::poke _Obstacle1_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle1_Y
       (sys::poke _Obstacle1_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle2_X
       (sys::poke _Obstacle2_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle2_Y
       (sys::poke _Obstacle2_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle3_X
       (sys::poke _Obstacle3_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Obstacle3_Y
       (sys::poke _Obstacle3_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Ball_X
     (setq _Ball_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_Y
     (setq _Ball_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_speed_X
     (setq _Ball_speed_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_speed_Y
     (setq _Ball_speed_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Robot_X
     (setq _Robot_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Robot_Y
     (setq _Robot_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle_X
     (setq _Obstacle_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle_Y
     (setq _Obstacle_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle0_X
     (setq _Obstacle0_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle0_Y
     (setq _Obstacle0_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle1_X
     (setq _Obstacle1_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle1_Y
     (setq _Obstacle1_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle2_X
     (setq _Obstacle2_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle2_Y
     (setq _Obstacle2_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle3_X
     (setq _Obstacle3_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Obstacle3_Y
     (setq _Obstacle3_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::robocup_localization23 :md5sum-) "8ee6effd3d721320075c4ac44f4b0bfe")
(setf (get msg_generate::robocup_localization23 :datatype-) "msg_generate/robocup_localization23")
(setf (get msg_generate::robocup_localization23 :definition-)
      "float64 Ball_X
float64 Ball_Y
float64 Ball_speed_X
float64 Ball_speed_Y
float64 Robot_X
float64 Robot_Y
float64 Obstacle_X
float64 Obstacle_Y



float64 Obstacle0_X
float64 Obstacle0_Y
float64 Obstacle1_X
float64 Obstacle1_Y
float64 Obstacle2_X
float64 Obstacle2_Y
float64 Obstacle3_X
float64 Obstacle3_Y

")



(provide :msg_generate/robocup_localization23 "8ee6effd3d721320075c4ac44f4b0bfe")


