;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::running_vision23)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'running_vision23 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::RUNNING_VISION23")
  (make-package "MSG_GENERATE::RUNNING_VISION23"))

(in-package "ROS")
;;//! \htmlinclude running_vision23.msg.html


(defclass msg_generate::running_vision23
  :super ros::object
  :slots (_line_cam_X _line_cam_Y _line_2d_X _line_2d_Y _line_D _line_theta _cross_cam_X _cross_cam_Y _cross_2d_X _cross_2d_Y _cross_D _hurdle_cam_X _hurdle_cam_Y _hurdle_2d_X _hurdle_2d_Y _hurdle_D _hurdle_theta _PAN _TILT _Scan_mode ))

(defmethod msg_generate::running_vision23
  (:init
   (&key
    ((:line_cam_X __line_cam_X) (make-array 0 :initial-element 0 :element-type :integer))
    ((:line_cam_Y __line_cam_Y) (make-array 0 :initial-element 0 :element-type :integer))
    ((:line_2d_X __line_2d_X) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:line_2d_Y __line_2d_Y) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:line_D __line_D) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:line_theta __line_theta) 0.0)
    ((:cross_cam_X __cross_cam_X) 0)
    ((:cross_cam_Y __cross_cam_Y) 0)
    ((:cross_2d_X __cross_2d_X) 0.0)
    ((:cross_2d_Y __cross_2d_Y) 0.0)
    ((:cross_D __cross_D) 0.0)
    ((:hurdle_cam_X __hurdle_cam_X) 0)
    ((:hurdle_cam_Y __hurdle_cam_Y) 0)
    ((:hurdle_2d_X __hurdle_2d_X) 0.0)
    ((:hurdle_2d_Y __hurdle_2d_Y) 0.0)
    ((:hurdle_D __hurdle_D) 0.0)
    ((:hurdle_theta __hurdle_theta) 0.0)
    ((:PAN __PAN) 0.0)
    ((:TILT __TILT) 0.0)
    ((:Scan_mode __Scan_mode) 0)
    )
   (send-super :init)
   (setq _line_cam_X __line_cam_X)
   (setq _line_cam_Y __line_cam_Y)
   (setq _line_2d_X __line_2d_X)
   (setq _line_2d_Y __line_2d_Y)
   (setq _line_D __line_D)
   (setq _line_theta (float __line_theta))
   (setq _cross_cam_X (round __cross_cam_X))
   (setq _cross_cam_Y (round __cross_cam_Y))
   (setq _cross_2d_X (float __cross_2d_X))
   (setq _cross_2d_Y (float __cross_2d_Y))
   (setq _cross_D (float __cross_D))
   (setq _hurdle_cam_X (round __hurdle_cam_X))
   (setq _hurdle_cam_Y (round __hurdle_cam_Y))
   (setq _hurdle_2d_X (float __hurdle_2d_X))
   (setq _hurdle_2d_Y (float __hurdle_2d_Y))
   (setq _hurdle_D (float __hurdle_D))
   (setq _hurdle_theta (float __hurdle_theta))
   (setq _PAN (float __PAN))
   (setq _TILT (float __TILT))
   (setq _Scan_mode (round __Scan_mode))
   self)
  (:line_cam_X
   (&optional __line_cam_X)
   (if __line_cam_X (setq _line_cam_X __line_cam_X)) _line_cam_X)
  (:line_cam_Y
   (&optional __line_cam_Y)
   (if __line_cam_Y (setq _line_cam_Y __line_cam_Y)) _line_cam_Y)
  (:line_2d_X
   (&optional __line_2d_X)
   (if __line_2d_X (setq _line_2d_X __line_2d_X)) _line_2d_X)
  (:line_2d_Y
   (&optional __line_2d_Y)
   (if __line_2d_Y (setq _line_2d_Y __line_2d_Y)) _line_2d_Y)
  (:line_D
   (&optional __line_D)
   (if __line_D (setq _line_D __line_D)) _line_D)
  (:line_theta
   (&optional __line_theta)
   (if __line_theta (setq _line_theta __line_theta)) _line_theta)
  (:cross_cam_X
   (&optional __cross_cam_X)
   (if __cross_cam_X (setq _cross_cam_X __cross_cam_X)) _cross_cam_X)
  (:cross_cam_Y
   (&optional __cross_cam_Y)
   (if __cross_cam_Y (setq _cross_cam_Y __cross_cam_Y)) _cross_cam_Y)
  (:cross_2d_X
   (&optional __cross_2d_X)
   (if __cross_2d_X (setq _cross_2d_X __cross_2d_X)) _cross_2d_X)
  (:cross_2d_Y
   (&optional __cross_2d_Y)
   (if __cross_2d_Y (setq _cross_2d_Y __cross_2d_Y)) _cross_2d_Y)
  (:cross_D
   (&optional __cross_D)
   (if __cross_D (setq _cross_D __cross_D)) _cross_D)
  (:hurdle_cam_X
   (&optional __hurdle_cam_X)
   (if __hurdle_cam_X (setq _hurdle_cam_X __hurdle_cam_X)) _hurdle_cam_X)
  (:hurdle_cam_Y
   (&optional __hurdle_cam_Y)
   (if __hurdle_cam_Y (setq _hurdle_cam_Y __hurdle_cam_Y)) _hurdle_cam_Y)
  (:hurdle_2d_X
   (&optional __hurdle_2d_X)
   (if __hurdle_2d_X (setq _hurdle_2d_X __hurdle_2d_X)) _hurdle_2d_X)
  (:hurdle_2d_Y
   (&optional __hurdle_2d_Y)
   (if __hurdle_2d_Y (setq _hurdle_2d_Y __hurdle_2d_Y)) _hurdle_2d_Y)
  (:hurdle_D
   (&optional __hurdle_D)
   (if __hurdle_D (setq _hurdle_D __hurdle_D)) _hurdle_D)
  (:hurdle_theta
   (&optional __hurdle_theta)
   (if __hurdle_theta (setq _hurdle_theta __hurdle_theta)) _hurdle_theta)
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
    ;; int64[] _line_cam_X
    (* 8    (length _line_cam_X)) 4
    ;; int64[] _line_cam_Y
    (* 8    (length _line_cam_Y)) 4
    ;; float64[] _line_2d_X
    (* 8    (length _line_2d_X)) 4
    ;; float64[] _line_2d_Y
    (* 8    (length _line_2d_Y)) 4
    ;; float64[] _line_D
    (* 8    (length _line_D)) 4
    ;; float64 _line_theta
    8
    ;; int64 _cross_cam_X
    8
    ;; int64 _cross_cam_Y
    8
    ;; float64 _cross_2d_X
    8
    ;; float64 _cross_2d_Y
    8
    ;; float64 _cross_D
    8
    ;; int64 _hurdle_cam_X
    8
    ;; int64 _hurdle_cam_Y
    8
    ;; float64 _hurdle_2d_X
    8
    ;; float64 _hurdle_2d_Y
    8
    ;; float64 _hurdle_D
    8
    ;; float64 _hurdle_theta
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
     ;; int64[] _line_cam_X
     (write-long (length _line_cam_X) s)
     (dotimes (i (length _line_cam_X))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _line_cam_X i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _line_cam_X i)) (= (length ((elt _line_cam_X i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _line_cam_X i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _line_cam_X i) . bv) 1) -1) s))
             ((and (class (elt _line_cam_X i)) (= (length ((elt _line_cam_X i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _line_cam_X i) . bv) 0) s)
              (write-long (if (>= (elt _line_cam_X i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _line_cam_X i) s)(write-long (if (>= (elt _line_cam_X i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _line_cam_Y
     (write-long (length _line_cam_Y) s)
     (dotimes (i (length _line_cam_Y))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _line_cam_Y i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _line_cam_Y i)) (= (length ((elt _line_cam_Y i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _line_cam_Y i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _line_cam_Y i) . bv) 1) -1) s))
             ((and (class (elt _line_cam_Y i)) (= (length ((elt _line_cam_Y i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _line_cam_Y i) . bv) 0) s)
              (write-long (if (>= (elt _line_cam_Y i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _line_cam_Y i) s)(write-long (if (>= (elt _line_cam_Y i) 0) 0 #xffffffff) s)))
       )
     ;; float64[] _line_2d_X
     (write-long (length _line_2d_X) s)
     (dotimes (i (length _line_2d_X))
       (sys::poke (elt _line_2d_X i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _line_2d_Y
     (write-long (length _line_2d_Y) s)
     (dotimes (i (length _line_2d_Y))
       (sys::poke (elt _line_2d_Y i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _line_D
     (write-long (length _line_D) s)
     (dotimes (i (length _line_D))
       (sys::poke (elt _line_D i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64 _line_theta
       (sys::poke _line_theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _cross_cam_X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cross_cam_X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cross_cam_X) (= (length (_cross_cam_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cross_cam_X . bv) 0) 0) s)
              (write-long (ash (elt (_cross_cam_X . bv) 1) -1) s))
             ((and (class _cross_cam_X) (= (length (_cross_cam_X . bv)) 1)) ;; big1
              (write-long (elt (_cross_cam_X . bv) 0) s)
              (write-long (if (>= _cross_cam_X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cross_cam_X s)(write-long (if (>= _cross_cam_X 0) 0 #xffffffff) s)))
     ;; int64 _cross_cam_Y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cross_cam_Y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cross_cam_Y) (= (length (_cross_cam_Y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cross_cam_Y . bv) 0) 0) s)
              (write-long (ash (elt (_cross_cam_Y . bv) 1) -1) s))
             ((and (class _cross_cam_Y) (= (length (_cross_cam_Y . bv)) 1)) ;; big1
              (write-long (elt (_cross_cam_Y . bv) 0) s)
              (write-long (if (>= _cross_cam_Y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cross_cam_Y s)(write-long (if (>= _cross_cam_Y 0) 0 #xffffffff) s)))
     ;; float64 _cross_2d_X
       (sys::poke _cross_2d_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _cross_2d_Y
       (sys::poke _cross_2d_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _cross_D
       (sys::poke _cross_D (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _hurdle_cam_X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hurdle_cam_X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hurdle_cam_X) (= (length (_hurdle_cam_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hurdle_cam_X . bv) 0) 0) s)
              (write-long (ash (elt (_hurdle_cam_X . bv) 1) -1) s))
             ((and (class _hurdle_cam_X) (= (length (_hurdle_cam_X . bv)) 1)) ;; big1
              (write-long (elt (_hurdle_cam_X . bv) 0) s)
              (write-long (if (>= _hurdle_cam_X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hurdle_cam_X s)(write-long (if (>= _hurdle_cam_X 0) 0 #xffffffff) s)))
     ;; int64 _hurdle_cam_Y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _hurdle_cam_Y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _hurdle_cam_Y) (= (length (_hurdle_cam_Y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_hurdle_cam_Y . bv) 0) 0) s)
              (write-long (ash (elt (_hurdle_cam_Y . bv) 1) -1) s))
             ((and (class _hurdle_cam_Y) (= (length (_hurdle_cam_Y . bv)) 1)) ;; big1
              (write-long (elt (_hurdle_cam_Y . bv) 0) s)
              (write-long (if (>= _hurdle_cam_Y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _hurdle_cam_Y s)(write-long (if (>= _hurdle_cam_Y 0) 0 #xffffffff) s)))
     ;; float64 _hurdle_2d_X
       (sys::poke _hurdle_2d_X (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _hurdle_2d_Y
       (sys::poke _hurdle_2d_Y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _hurdle_D
       (sys::poke _hurdle_D (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _hurdle_theta
       (sys::poke _hurdle_theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; int64[] _line_cam_X
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _line_cam_X (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _line_cam_X i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _line_cam_X i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _line_cam_Y
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _line_cam_Y (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _line_cam_Y i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _line_cam_Y i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; float64[] _line_2d_X
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _line_2d_X (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _line_2d_X i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _line_2d_Y
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _line_2d_Y (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _line_2d_Y i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _line_D
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _line_D (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _line_D i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64 _line_theta
     (setq _line_theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _cross_cam_X
#+(or :alpha :irix6 :x86_64)
      (setf _cross_cam_X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cross_cam_X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _cross_cam_Y
#+(or :alpha :irix6 :x86_64)
      (setf _cross_cam_Y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cross_cam_Y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _cross_2d_X
     (setq _cross_2d_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cross_2d_Y
     (setq _cross_2d_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cross_D
     (setq _cross_D (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _hurdle_cam_X
#+(or :alpha :irix6 :x86_64)
      (setf _hurdle_cam_X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hurdle_cam_X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _hurdle_cam_Y
#+(or :alpha :irix6 :x86_64)
      (setf _hurdle_cam_Y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _hurdle_cam_Y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _hurdle_2d_X
     (setq _hurdle_2d_X (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _hurdle_2d_Y
     (setq _hurdle_2d_Y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _hurdle_D
     (setq _hurdle_D (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _hurdle_theta
     (setq _hurdle_theta (sys::peek buf ptr- :double)) (incf ptr- 8)
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

(setf (get msg_generate::running_vision23 :md5sum-) "84bbd3957c09a95986b5eb7beba9cf54")
(setf (get msg_generate::running_vision23 :datatype-) "msg_generate/running_vision23")
(setf (get msg_generate::running_vision23 :definition-)
      "int64[] line_cam_X
int64[] line_cam_Y
float64[] line_2d_X
float64[] line_2d_Y
float64[] line_D
float64 line_theta

int64 cross_cam_X
int64 cross_cam_Y
float64 cross_2d_X
float64 cross_2d_Y
float64 cross_D

int64 hurdle_cam_X
int64 hurdle_cam_Y
float64 hurdle_2d_X
float64 hurdle_2d_Y
float64 hurdle_D
float64 hurdle_theta

float64 PAN
float64 TILT
int64 Scan_mode



")



(provide :msg_generate/running_vision23 "84bbd3957c09a95986b5eb7beba9cf54")


