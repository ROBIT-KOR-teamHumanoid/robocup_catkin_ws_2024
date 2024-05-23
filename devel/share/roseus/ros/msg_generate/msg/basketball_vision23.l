;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::basketball_vision23)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'basketball_vision23 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::BASKETBALL_VISION23")
  (make-package "MSG_GENERATE::BASKETBALL_VISION23"))

(in-package "ROS")
;;//! \htmlinclude basketball_vision23.msg.html


(defclass msg_generate::basketball_vision23
  :super ros::object
  :slots (_goal_cam_X _goal_cam_Y _goal_2d_X _goal_2d_Y _goal_local_X _goal_local_Y _goal_D _robot_local_X _robot_local_Y _PAN _TILT _Scan_mode ))

(defmethod msg_generate::basketball_vision23
  (:init
   (&key
    ((:goal_cam_X __goal_cam_X) 0)
    ((:goal_cam_Y __goal_cam_Y) 0)
    ((:goal_2d_X __goal_2d_X) 0.0)
    ((:goal_2d_Y __goal_2d_Y) 0.0)
    ((:goal_local_X __goal_local_X) 0.0)
    ((:goal_local_Y __goal_local_Y) 0.0)
    ((:goal_D __goal_D) 0.0)
    ((:robot_local_X __robot_local_X) 0.0)
    ((:robot_local_Y __robot_local_Y) 0.0)
    ((:PAN __PAN) 0.0)
    ((:TILT __TILT) 0.0)
    ((:Scan_mode __Scan_mode) 0)
    )
   (send-super :init)
   (setq _goal_cam_X (round __goal_cam_X))
   (setq _goal_cam_Y (round __goal_cam_Y))
   (setq _goal_2d_X (float __goal_2d_X))
   (setq _goal_2d_Y (float __goal_2d_Y))
   (setq _goal_local_X (float __goal_local_X))
   (setq _goal_local_Y (float __goal_local_Y))
   (setq _goal_D (float __goal_D))
   (setq _robot_local_X (float __robot_local_X))
   (setq _robot_local_Y (float __robot_local_Y))
   (setq _PAN (float __PAN))
   (setq _TILT (float __TILT))
   (setq _Scan_mode (round __Scan_mode))
   self)
  (:goal_cam_X
   (&optional __goal_cam_X)
   (if __goal_cam_X (setq _goal_cam_X __goal_cam_X)) _goal_cam_X)
  (:goal_cam_Y
   (&optional __goal_cam_Y)
   (if __goal_cam_Y (setq _goal_cam_Y __goal_cam_Y)) _goal_cam_Y)
  (:goal_2d_X
   (&optional __goal_2d_X)
   (if __goal_2d_X (setq _goal_2d_X __goal_2d_X)) _goal_2d_X)
  (:goal_2d_Y
   (&optional __goal_2d_Y)
   (if __goal_2d_Y (setq _goal_2d_Y __goal_2d_Y)) _goal_2d_Y)
  (:goal_local_X
   (&optional __goal_local_X)
   (if __goal_local_X (setq _goal_local_X __goal_local_X)) _goal_local_X)
  (:goal_local_Y
   (&optional __goal_local_Y)
   (if __goal_local_Y (setq _goal_local_Y __goal_local_Y)) _goal_local_Y)
  (:goal_D
   (&optional __goal_D)
   (if __goal_D (setq _goal_D __goal_D)) _goal_D)
  (:robot_local_X
   (&optional __robot_local_X)
   (if __robot_local_X (setq _robot_local_X __robot_local_X)) _robot_local_X)
  (:robot_local_Y
   (&optional __robot_local_Y)
   (if __robot_local_Y (setq _robot_local_Y __robot_local_Y)) _robot_local_Y)
  (:PAN
   (&optional __PAN)
   (if __PAN (setq _PAN __PAN)) _PAN)
  (:TILT
   (&optional __TILT)
   (if __TILT (setq _TILT __TILT)) _TILT)
  (:Scan_mode
   (&optional __Scan_mode)
   (if __Scan_mode (setq _Scan_mode __Scan_mode)) _Scan_mode)
  (:serialization-length
   ()
   (+
    ;; int64 _goal_cam_X
    8
    ;; int64 _goal_cam_Y
    8
    ;; float64 _goal_2d_X
    8
    ;; float64 _goal_2d_Y
    8
    ;; float64 _goal_local_X
    8
    ;; float64 _goal_local_Y
    8
    ;; float64 _goal_D
    8
    ;; float64 _robot_local_X
    8
    ;; float64 _robot_local_Y
    8
    ;; float64 _PAN
    8
    ;; float64 _TILT
    8
    ;; int64 _Scan_mode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _goal_cam_X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _goal_cam_X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _goal_cam_X) (= (length (_goal_cam_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_goal_cam_X . bv) 0) 0) s)
              (write-long (ash (elt (_goal_cam_X . bv) 1) -1) s))
             ((and (class _goal_cam_X) (= (length (_goal_cam_X . bv)) 1)) ;; big1
              (write-long (elt (_goal_cam_X . bv) 0) s)
              (write-long (if (>= _goal_cam_X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _goal_cam_X s)(write-long (if (>= _goal_cam_X 0) 0 #xffffffff) s)))
     ;; int64 _goal_cam_Y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _goal_cam_Y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _goal_cam_Y) (= (length (_goal_cam_Y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_goal_cam_Y . bv) 0) 0) s)
              (write-long (ash (elt (_goal_cam_Y . bv) 1) -1) s))
             ((and (class _goal_cam_Y) (= (length (_goal_cam_Y . bv)) 1)) ;; big1
              (write-long (elt (_goal_cam_Y . bv) 0) s)
              (write-long (if (>= _goal_cam_Y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _goal_cam_Y s)(write-long (if (>= _goal_cam_Y 0) 0 #xffffffff) s)))
     ;; float64 _goal_2d_X
       (sys::poke _goal_2d_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _goal_2d_Y
       (sys::poke _goal_2d_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _goal_local_X
       (sys::poke _goal_local_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _goal_local_Y
       (sys::poke _goal_local_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _goal_D
       (sys::poke _goal_D (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _robot_local_X
       (sys::poke _robot_local_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _robot_local_Y
       (sys::poke _robot_local_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _PAN
       (sys::poke _PAN (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _TILT
       (sys::poke _TILT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _Scan_mode
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Scan_mode (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Scan_mode) (= (length (_Scan_mode . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Scan_mode . bv) 0) 0) s)
              (write-long (ash (elt (_Scan_mode . bv) 1) -1) s))
             ((and (class _Scan_mode) (= (length (_Scan_mode . bv)) 1)) ;; big1
              (write-long (elt (_Scan_mode . bv) 0) s)
              (write-long (if (>= _Scan_mode 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Scan_mode s)(write-long (if (>= _Scan_mode 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _goal_cam_X
#+(or :alpha :irix6 :x86_64)
      (setf _goal_cam_X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _goal_cam_X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _goal_cam_Y
#+(or :alpha :irix6 :x86_64)
      (setf _goal_cam_Y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _goal_cam_Y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _goal_2d_X
     (setq _goal_2d_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _goal_2d_Y
     (setq _goal_2d_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _goal_local_X
     (setq _goal_local_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _goal_local_Y
     (setq _goal_local_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _goal_D
     (setq _goal_D (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _robot_local_X
     (setq _robot_local_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _robot_local_Y
     (setq _robot_local_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _PAN
     (setq _PAN (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _TILT
     (setq _TILT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _Scan_mode
#+(or :alpha :irix6 :x86_64)
      (setf _Scan_mode (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Scan_mode (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get msg_generate::basketball_vision23 :md5sum-) "e6ef028504654d91012c2d8d50a3e391")
(setf (get msg_generate::basketball_vision23 :datatype-) "msg_generate/basketball_vision23")
(setf (get msg_generate::basketball_vision23 :definition-)
      "int64 goal_cam_X
int64 goal_cam_Y
float64 goal_2d_X
float64 goal_2d_Y
float64 goal_local_X
float64 goal_local_Y
float64 goal_D
float64 robot_local_X
float64 robot_local_Y
float64 PAN
float64 TILT
int64 Scan_mode

")



(provide :msg_generate/basketball_vision23 "e6ef028504654d91012c2d8d50a3e391")


