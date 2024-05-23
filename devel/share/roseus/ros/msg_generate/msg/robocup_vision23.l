;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::robocup_vision23)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'robocup_vision23 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ROBOCUP_VISION23")
  (make-package "MSG_GENERATE::ROBOCUP_VISION23"))

(in-package "ROS")
;;//! \htmlinclude robocup_vision23.msg.html


(defclass msg_generate::robocup_vision23
  :super ros::object
  :slots (_Ball_cam_X _Ball_cam_Y _Ball_2d_X _Ball_2d_Y _Ball_D _PAN _TILT _Ball_speed_X _Ball_speed_Y _ROBOT_VEC_X _ROBOT_VEC_Y _Ball_speed_level _Scan_mode ))

(defmethod msg_generate::robocup_vision23
  (:init
   (&key
    ((:Ball_cam_X __Ball_cam_X) 0)
    ((:Ball_cam_Y __Ball_cam_Y) 0)
    ((:Ball_2d_X __Ball_2d_X) 0.0)
    ((:Ball_2d_Y __Ball_2d_Y) 0.0)
    ((:Ball_D __Ball_D) 0.0)
    ((:PAN __PAN) 0.0)
    ((:TILT __TILT) 0.0)
    ((:Ball_speed_X __Ball_speed_X) 0.0)
    ((:Ball_speed_Y __Ball_speed_Y) 0.0)
    ((:ROBOT_VEC_X __ROBOT_VEC_X) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:ROBOT_VEC_Y __ROBOT_VEC_Y) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:Ball_speed_level __Ball_speed_level) 0)
    ((:Scan_mode __Scan_mode) 0)
    )
   (send-super :init)
   (setq _Ball_cam_X (round __Ball_cam_X))
   (setq _Ball_cam_Y (round __Ball_cam_Y))
   (setq _Ball_2d_X (float __Ball_2d_X))
   (setq _Ball_2d_Y (float __Ball_2d_Y))
   (setq _Ball_D (float __Ball_D))
   (setq _PAN (float __PAN))
   (setq _TILT (float __TILT))
   (setq _Ball_speed_X (float __Ball_speed_X))
   (setq _Ball_speed_Y (float __Ball_speed_Y))
   (setq _ROBOT_VEC_X __ROBOT_VEC_X)
   (setq _ROBOT_VEC_Y __ROBOT_VEC_Y)
   (setq _Ball_speed_level (round __Ball_speed_level))
   (setq _Scan_mode (round __Scan_mode))
   self)
  (:Ball_cam_X
   (&optional __Ball_cam_X)
   (if __Ball_cam_X (setq _Ball_cam_X __Ball_cam_X)) _Ball_cam_X)
  (:Ball_cam_Y
   (&optional __Ball_cam_Y)
   (if __Ball_cam_Y (setq _Ball_cam_Y __Ball_cam_Y)) _Ball_cam_Y)
  (:Ball_2d_X
   (&optional __Ball_2d_X)
   (if __Ball_2d_X (setq _Ball_2d_X __Ball_2d_X)) _Ball_2d_X)
  (:Ball_2d_Y
   (&optional __Ball_2d_Y)
   (if __Ball_2d_Y (setq _Ball_2d_Y __Ball_2d_Y)) _Ball_2d_Y)
  (:Ball_D
   (&optional __Ball_D)
   (if __Ball_D (setq _Ball_D __Ball_D)) _Ball_D)
  (:PAN
   (&optional __PAN)
   (if __PAN (setq _PAN __PAN)) _PAN)
  (:TILT
   (&optional __TILT)
   (if __TILT (setq _TILT __TILT)) _TILT)
  (:Ball_speed_X
   (&optional __Ball_speed_X)
   (if __Ball_speed_X (setq _Ball_speed_X __Ball_speed_X)) _Ball_speed_X)
  (:Ball_speed_Y
   (&optional __Ball_speed_Y)
   (if __Ball_speed_Y (setq _Ball_speed_Y __Ball_speed_Y)) _Ball_speed_Y)
  (:ROBOT_VEC_X
   (&optional __ROBOT_VEC_X)
   (if __ROBOT_VEC_X (setq _ROBOT_VEC_X __ROBOT_VEC_X)) _ROBOT_VEC_X)
  (:ROBOT_VEC_Y
   (&optional __ROBOT_VEC_Y)
   (if __ROBOT_VEC_Y (setq _ROBOT_VEC_Y __ROBOT_VEC_Y)) _ROBOT_VEC_Y)
  (:Ball_speed_level
   (&optional __Ball_speed_level)
   (if __Ball_speed_level (setq _Ball_speed_level __Ball_speed_level)) _Ball_speed_level)
  (:Scan_mode
   (&optional __Scan_mode)
   (if __Scan_mode (setq _Scan_mode __Scan_mode)) _Scan_mode)
  (:serialization-length
   ()
   (+
    ;; int64 _Ball_cam_X
    8
    ;; int64 _Ball_cam_Y
    8
    ;; float64 _Ball_2d_X
    8
    ;; float64 _Ball_2d_Y
    8
    ;; float64 _Ball_D
    8
    ;; float64 _PAN
    8
    ;; float64 _TILT
    8
    ;; float64 _Ball_speed_X
    8
    ;; float64 _Ball_speed_Y
    8
    ;; float64[] _ROBOT_VEC_X
    (* 8    (length _ROBOT_VEC_X)) 4
    ;; float64[] _ROBOT_VEC_Y
    (* 8    (length _ROBOT_VEC_Y)) 4
    ;; int64 _Ball_speed_level
    8
    ;; int64 _Scan_mode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _Ball_cam_X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Ball_cam_X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Ball_cam_X) (= (length (_Ball_cam_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Ball_cam_X . bv) 0) 0) s)
              (write-long (ash (elt (_Ball_cam_X . bv) 1) -1) s))
             ((and (class _Ball_cam_X) (= (length (_Ball_cam_X . bv)) 1)) ;; big1
              (write-long (elt (_Ball_cam_X . bv) 0) s)
              (write-long (if (>= _Ball_cam_X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Ball_cam_X s)(write-long (if (>= _Ball_cam_X 0) 0 #xffffffff) s)))
     ;; int64 _Ball_cam_Y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Ball_cam_Y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Ball_cam_Y) (= (length (_Ball_cam_Y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Ball_cam_Y . bv) 0) 0) s)
              (write-long (ash (elt (_Ball_cam_Y . bv) 1) -1) s))
             ((and (class _Ball_cam_Y) (= (length (_Ball_cam_Y . bv)) 1)) ;; big1
              (write-long (elt (_Ball_cam_Y . bv) 0) s)
              (write-long (if (>= _Ball_cam_Y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Ball_cam_Y s)(write-long (if (>= _Ball_cam_Y 0) 0 #xffffffff) s)))
     ;; float64 _Ball_2d_X
       (sys::poke _Ball_2d_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_2d_Y
       (sys::poke _Ball_2d_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_D
       (sys::poke _Ball_D (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _PAN
       (sys::poke _PAN (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _TILT
       (sys::poke _TILT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_speed_X
       (sys::poke _Ball_speed_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ball_speed_Y
       (sys::poke _Ball_speed_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64[] _ROBOT_VEC_X
     (write-long (length _ROBOT_VEC_X) s)
     (dotimes (i (length _ROBOT_VEC_X))
       (sys::poke (elt _ROBOT_VEC_X i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _ROBOT_VEC_Y
     (write-long (length _ROBOT_VEC_Y) s)
     (dotimes (i (length _ROBOT_VEC_Y))
       (sys::poke (elt _ROBOT_VEC_Y i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; int64 _Ball_speed_level
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Ball_speed_level (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Ball_speed_level) (= (length (_Ball_speed_level . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Ball_speed_level . bv) 0) 0) s)
              (write-long (ash (elt (_Ball_speed_level . bv) 1) -1) s))
             ((and (class _Ball_speed_level) (= (length (_Ball_speed_level . bv)) 1)) ;; big1
              (write-long (elt (_Ball_speed_level . bv) 0) s)
              (write-long (if (>= _Ball_speed_level 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Ball_speed_level s)(write-long (if (>= _Ball_speed_level 0) 0 #xffffffff) s)))
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
   ;; int64 _Ball_cam_X
#+(or :alpha :irix6 :x86_64)
      (setf _Ball_cam_X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Ball_cam_X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _Ball_cam_Y
#+(or :alpha :irix6 :x86_64)
      (setf _Ball_cam_Y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Ball_cam_Y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _Ball_2d_X
     (setq _Ball_2d_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_2d_Y
     (setq _Ball_2d_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_D
     (setq _Ball_D (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _PAN
     (setq _PAN (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _TILT
     (setq _TILT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_speed_X
     (setq _Ball_speed_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ball_speed_Y
     (setq _Ball_speed_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64[] _ROBOT_VEC_X
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ROBOT_VEC_X (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ROBOT_VEC_X i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _ROBOT_VEC_Y
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ROBOT_VEC_Y (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ROBOT_VEC_Y i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; int64 _Ball_speed_level
#+(or :alpha :irix6 :x86_64)
      (setf _Ball_speed_level (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Ball_speed_level (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
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

(setf (get msg_generate::robocup_vision23 :md5sum-) "e7c23af0ec42fde2be9393d1f1e88db0")
(setf (get msg_generate::robocup_vision23 :datatype-) "msg_generate/robocup_vision23")
(setf (get msg_generate::robocup_vision23 :definition-)
      "int64 Ball_cam_X
int64 Ball_cam_Y
float64 Ball_2d_X
float64 Ball_2d_Y
float64 Ball_D
float64 PAN
float64 TILT
float64 Ball_speed_X
float64 Ball_speed_Y
float64[] ROBOT_VEC_X
float64[] ROBOT_VEC_Y
int64 Ball_speed_level
int64 Scan_mode

")



(provide :msg_generate/robocup_vision23 "e7c23af0ec42fde2be9393d1f1e88db0")


