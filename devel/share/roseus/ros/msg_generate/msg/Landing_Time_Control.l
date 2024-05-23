;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Landing_Time_Control)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Landing_Time_Control (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::LANDING_TIME_CONTROL")
  (make-package "MSG_GENERATE::LANDING_TIME_CONTROL"))

(in-package "ROS")
;;//! \htmlinclude Landing_Time_Control.msg.html


(defclass msg_generate::Landing_Time_Control
  :super ros::object
  :slots (_Entire_Time _Swing_Gain_L _Swing_Gain_R _Warning _Safe _Landing_Time_L _Landing_Time_R _Landing_Error_L _Landing_Error_R ))

(defmethod msg_generate::Landing_Time_Control
  (:init
   (&key
    ((:Entire_Time __Entire_Time) 0.0)
    ((:Swing_Gain_L __Swing_Gain_L) 0.0)
    ((:Swing_Gain_R __Swing_Gain_R) 0.0)
    ((:Warning __Warning) 0)
    ((:Safe __Safe) 0)
    ((:Landing_Time_L __Landing_Time_L) 0.0)
    ((:Landing_Time_R __Landing_Time_R) 0.0)
    ((:Landing_Error_L __Landing_Error_L) 0.0)
    ((:Landing_Error_R __Landing_Error_R) 0.0)
    )
   (send-super :init)
   (setq _Entire_Time (float __Entire_Time))
   (setq _Swing_Gain_L (float __Swing_Gain_L))
   (setq _Swing_Gain_R (float __Swing_Gain_R))
   (setq _Warning (round __Warning))
   (setq _Safe (round __Safe))
   (setq _Landing_Time_L (float __Landing_Time_L))
   (setq _Landing_Time_R (float __Landing_Time_R))
   (setq _Landing_Error_L (float __Landing_Error_L))
   (setq _Landing_Error_R (float __Landing_Error_R))
   self)
  (:Entire_Time
   (&optional __Entire_Time)
   (if __Entire_Time (setq _Entire_Time __Entire_Time)) _Entire_Time)
  (:Swing_Gain_L
   (&optional __Swing_Gain_L)
   (if __Swing_Gain_L (setq _Swing_Gain_L __Swing_Gain_L)) _Swing_Gain_L)
  (:Swing_Gain_R
   (&optional __Swing_Gain_R)
   (if __Swing_Gain_R (setq _Swing_Gain_R __Swing_Gain_R)) _Swing_Gain_R)
  (:Warning
   (&optional __Warning)
   (if __Warning (setq _Warning __Warning)) _Warning)
  (:Safe
   (&optional __Safe)
   (if __Safe (setq _Safe __Safe)) _Safe)
  (:Landing_Time_L
   (&optional __Landing_Time_L)
   (if __Landing_Time_L (setq _Landing_Time_L __Landing_Time_L)) _Landing_Time_L)
  (:Landing_Time_R
   (&optional __Landing_Time_R)
   (if __Landing_Time_R (setq _Landing_Time_R __Landing_Time_R)) _Landing_Time_R)
  (:Landing_Error_L
   (&optional __Landing_Error_L)
   (if __Landing_Error_L (setq _Landing_Error_L __Landing_Error_L)) _Landing_Error_L)
  (:Landing_Error_R
   (&optional __Landing_Error_R)
   (if __Landing_Error_R (setq _Landing_Error_R __Landing_Error_R)) _Landing_Error_R)
  (:serialization-length
   ()
   (+
    ;; float64 _Entire_Time
    8
    ;; float64 _Swing_Gain_L
    8
    ;; float64 _Swing_Gain_R
    8
    ;; int64 _Warning
    8
    ;; int64 _Safe
    8
    ;; float64 _Landing_Time_L
    8
    ;; float64 _Landing_Time_R
    8
    ;; float64 _Landing_Error_L
    8
    ;; float64 _Landing_Error_R
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Entire_Time
       (sys::poke _Entire_Time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Gain_L
       (sys::poke _Swing_Gain_L (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Swing_Gain_R
       (sys::poke _Swing_Gain_R (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Warning
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Warning (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Warning) (= (length (_Warning . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Warning . bv) 0) 0) s)
              (write-long (ash (elt (_Warning . bv) 1) -1) s))
             ((and (class _Warning) (= (length (_Warning . bv)) 1)) ;; big1
              (write-long (elt (_Warning . bv) 0) s)
              (write-long (if (>= _Warning 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Warning s)(write-long (if (>= _Warning 0) 0 #xffffffff) s)))
     ;; int64 _Safe
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Safe (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Safe) (= (length (_Safe . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Safe . bv) 0) 0) s)
              (write-long (ash (elt (_Safe . bv) 1) -1) s))
             ((and (class _Safe) (= (length (_Safe . bv)) 1)) ;; big1
              (write-long (elt (_Safe . bv) 0) s)
              (write-long (if (>= _Safe 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Safe s)(write-long (if (>= _Safe 0) 0 #xffffffff) s)))
     ;; float64 _Landing_Time_L
       (sys::poke _Landing_Time_L (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Landing_Time_R
       (sys::poke _Landing_Time_R (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Landing_Error_L
       (sys::poke _Landing_Error_L (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Landing_Error_R
       (sys::poke _Landing_Error_R (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Entire_Time
     (setq _Entire_Time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Gain_L
     (setq _Swing_Gain_L (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Swing_Gain_R
     (setq _Swing_Gain_R (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Warning
#+(or :alpha :irix6 :x86_64)
      (setf _Warning (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Warning (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Safe
#+(or :alpha :irix6 :x86_64)
      (setf _Safe (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Safe (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Landing_Time_L
     (setq _Landing_Time_L (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Landing_Time_R
     (setq _Landing_Time_R (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Landing_Error_L
     (setq _Landing_Error_L (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Landing_Error_R
     (setq _Landing_Error_R (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::Landing_Time_Control :md5sum-) "0231e6c7c4e3ed975ff22fc97b613ccc")
(setf (get msg_generate::Landing_Time_Control :datatype-) "msg_generate/Landing_Time_Control")
(setf (get msg_generate::Landing_Time_Control :definition-)
      "float64 Entire_Time
float64 Swing_Gain_L
float64 Swing_Gain_R
int64 Warning
int64 Safe

float64 Landing_Time_L
float64 Landing_Time_R

float64 Landing_Error_L
float64 Landing_Error_R


")



(provide :msg_generate/Landing_Time_Control "0231e6c7c4e3ed975ff22fc97b613ccc")


