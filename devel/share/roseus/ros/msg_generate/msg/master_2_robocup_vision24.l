;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::master_2_robocup_vision24)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'master_2_robocup_vision24 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MASTER_2_ROBOCUP_VISION24")
  (make-package "MSG_GENERATE::MASTER_2_ROBOCUP_VISION24"))

(in-package "ROS")
;;//! \htmlinclude master_2_robocup_vision24.msg.html


(defclass msg_generate::master_2_robocup_vision24
  :super ros::object
  :slots (_Scan_Mode _PAN _TILT ))

(defmethod msg_generate::master_2_robocup_vision24
  (:init
   (&key
    ((:Scan_Mode __Scan_Mode) 0)
    ((:PAN __PAN) 0.0)
    ((:TILT __TILT) 0.0)
    )
   (send-super :init)
   (setq _Scan_Mode (round __Scan_Mode))
   (setq _PAN (float __PAN))
   (setq _TILT (float __TILT))
   self)
  (:Scan_Mode
   (&optional __Scan_Mode)
   (if __Scan_Mode (setq _Scan_Mode __Scan_Mode)) _Scan_Mode)
  (:PAN
   (&optional __PAN)
   (if __PAN (setq _PAN __PAN)) _PAN)
  (:TILT
   (&optional __TILT)
   (if __TILT (setq _TILT __TILT)) _TILT)
  (:serialization-length
   ()
   (+
    ;; int64 _Scan_Mode
    8
    ;; float64 _PAN
    8
    ;; float64 _TILT
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _Scan_Mode
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Scan_Mode (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Scan_Mode) (= (length (_Scan_Mode . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Scan_Mode . bv) 0) 0) s)
              (write-long (ash (elt (_Scan_Mode . bv) 1) -1) s))
             ((and (class _Scan_Mode) (= (length (_Scan_Mode . bv)) 1)) ;; big1
              (write-long (elt (_Scan_Mode . bv) 0) s)
              (write-long (if (>= _Scan_Mode 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Scan_Mode s)(write-long (if (>= _Scan_Mode 0) 0 #xffffffff) s)))
     ;; float64 _PAN
       (sys::poke _PAN (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _TILT
       (sys::poke _TILT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _Scan_Mode
#+(or :alpha :irix6 :x86_64)
      (setf _Scan_Mode (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Scan_Mode (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _PAN
     (setq _PAN (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _TILT
     (setq _TILT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::master_2_robocup_vision24 :md5sum-) "b5fe0eb4136cf0ddbbf95ffa2d2e7754")
(setf (get msg_generate::master_2_robocup_vision24 :datatype-) "msg_generate/master_2_robocup_vision24")
(setf (get msg_generate::master_2_robocup_vision24 :definition-)
      "int64 Scan_Mode
float64 PAN
float64 TILT

")



(provide :msg_generate/master_2_robocup_vision24 "b5fe0eb4136cf0ddbbf95ffa2d2e7754")


