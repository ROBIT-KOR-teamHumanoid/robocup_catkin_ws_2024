;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::motion_balance)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'motion_balance (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MOTION_BALANCE")
  (make-package "MSG_GENERATE::MOTION_BALANCE"))

(in-package "ROS")
;;//! \htmlinclude motion_balance.msg.html


(defclass msg_generate::motion_balance
  :super ros::object
  :slots (_Left_10 _Right_11 _Left_14 _Right_15 _Left_16 _Right_17 _Left_18 _Right_19 _Left_20 _Right_21 _support_L _support_R _support_B ))

(defmethod msg_generate::motion_balance
  (:init
   (&key
    ((:Left_10 __Left_10) 0.0)
    ((:Right_11 __Right_11) 0.0)
    ((:Left_14 __Left_14) 0.0)
    ((:Right_15 __Right_15) 0.0)
    ((:Left_16 __Left_16) 0.0)
    ((:Right_17 __Right_17) 0.0)
    ((:Left_18 __Left_18) 0.0)
    ((:Right_19 __Right_19) 0.0)
    ((:Left_20 __Left_20) 0.0)
    ((:Right_21 __Right_21) 0.0)
    ((:support_L __support_L) nil)
    ((:support_R __support_R) nil)
    ((:support_B __support_B) nil)
    )
   (send-super :init)
   (setq _Left_10 (float __Left_10))
   (setq _Right_11 (float __Right_11))
   (setq _Left_14 (float __Left_14))
   (setq _Right_15 (float __Right_15))
   (setq _Left_16 (float __Left_16))
   (setq _Right_17 (float __Right_17))
   (setq _Left_18 (float __Left_18))
   (setq _Right_19 (float __Right_19))
   (setq _Left_20 (float __Left_20))
   (setq _Right_21 (float __Right_21))
   (setq _support_L __support_L)
   (setq _support_R __support_R)
   (setq _support_B __support_B)
   self)
  (:Left_10
   (&optional __Left_10)
   (if __Left_10 (setq _Left_10 __Left_10)) _Left_10)
  (:Right_11
   (&optional __Right_11)
   (if __Right_11 (setq _Right_11 __Right_11)) _Right_11)
  (:Left_14
   (&optional __Left_14)
   (if __Left_14 (setq _Left_14 __Left_14)) _Left_14)
  (:Right_15
   (&optional __Right_15)
   (if __Right_15 (setq _Right_15 __Right_15)) _Right_15)
  (:Left_16
   (&optional __Left_16)
   (if __Left_16 (setq _Left_16 __Left_16)) _Left_16)
  (:Right_17
   (&optional __Right_17)
   (if __Right_17 (setq _Right_17 __Right_17)) _Right_17)
  (:Left_18
   (&optional __Left_18)
   (if __Left_18 (setq _Left_18 __Left_18)) _Left_18)
  (:Right_19
   (&optional __Right_19)
   (if __Right_19 (setq _Right_19 __Right_19)) _Right_19)
  (:Left_20
   (&optional __Left_20)
   (if __Left_20 (setq _Left_20 __Left_20)) _Left_20)
  (:Right_21
   (&optional __Right_21)
   (if __Right_21 (setq _Right_21 __Right_21)) _Right_21)
  (:support_L
   (&optional __support_L)
   (if __support_L (setq _support_L __support_L)) _support_L)
  (:support_R
   (&optional __support_R)
   (if __support_R (setq _support_R __support_R)) _support_R)
  (:support_B
   (&optional __support_B)
   (if __support_B (setq _support_B __support_B)) _support_B)
  (:serialization-length
   ()
   (+
    ;; float32 _Left_10
    4
    ;; float32 _Right_11
    4
    ;; float32 _Left_14
    4
    ;; float32 _Right_15
    4
    ;; float32 _Left_16
    4
    ;; float32 _Right_17
    4
    ;; float32 _Left_18
    4
    ;; float32 _Right_19
    4
    ;; float32 _Left_20
    4
    ;; float32 _Right_21
    4
    ;; bool _support_L
    1
    ;; bool _support_R
    1
    ;; bool _support_B
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _Left_10
       (sys::poke _Left_10 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Right_11
       (sys::poke _Right_11 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Left_14
       (sys::poke _Left_14 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Right_15
       (sys::poke _Right_15 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Left_16
       (sys::poke _Left_16 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Right_17
       (sys::poke _Right_17 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Left_18
       (sys::poke _Left_18 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Right_19
       (sys::poke _Right_19 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Left_20
       (sys::poke _Left_20 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Right_21
       (sys::poke _Right_21 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _support_L
       (if _support_L (write-byte -1 s) (write-byte 0 s))
     ;; bool _support_R
       (if _support_R (write-byte -1 s) (write-byte 0 s))
     ;; bool _support_B
       (if _support_B (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _Left_10
     (setq _Left_10 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Right_11
     (setq _Right_11 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Left_14
     (setq _Left_14 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Right_15
     (setq _Right_15 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Left_16
     (setq _Left_16 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Right_17
     (setq _Right_17 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Left_18
     (setq _Left_18 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Right_19
     (setq _Right_19 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Left_20
     (setq _Left_20 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Right_21
     (setq _Right_21 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _support_L
     (setq _support_L (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _support_R
     (setq _support_R (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _support_B
     (setq _support_B (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::motion_balance :md5sum-) "03d17ac032478d225abd4895f2c60b7c")
(setf (get msg_generate::motion_balance :datatype-) "msg_generate/motion_balance")
(setf (get msg_generate::motion_balance :definition-)
      "float32 Left_10
float32 Right_11
float32 Left_14
float32 Right_15
float32 Left_16
float32 Right_17
float32 Left_18
float32 Right_19
float32 Left_20
float32 Right_21

bool support_L
bool support_R
bool support_B

")



(provide :msg_generate/motion_balance "03d17ac032478d225abd4895f2c60b7c")


