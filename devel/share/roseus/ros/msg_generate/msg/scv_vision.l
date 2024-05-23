;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::scv_vision)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'scv_vision (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::SCV_VISION")
  (make-package "MSG_GENERATE::SCV_VISION"))

(in-package "ROS")
;;//! \htmlinclude scv_vision.msg.html


(defclass msg_generate::scv_vision
  :super ros::object
  :slots (_ballX _ballY _ballDist _ballTheta _cylinderX _cylinderY _cylinderDist _cylinderTheta _directX _directY _directDist _directTheta _first_start _circlex _circley ))

(defmethod msg_generate::scv_vision
  (:init
   (&key
    ((:ballX __ballX) 0)
    ((:ballY __ballY) 0)
    ((:ballDist __ballDist) 0)
    ((:ballTheta __ballTheta) 0.0)
    ((:cylinderX __cylinderX) 0)
    ((:cylinderY __cylinderY) 0)
    ((:cylinderDist __cylinderDist) 0)
    ((:cylinderTheta __cylinderTheta) 0.0)
    ((:directX __directX) 0)
    ((:directY __directY) 0)
    ((:directDist __directDist) 0)
    ((:directTheta __directTheta) 0.0)
    ((:first_start __first_start) 0)
    ((:circlex __circlex) 0)
    ((:circley __circley) 0)
    )
   (send-super :init)
   (setq _ballX (round __ballX))
   (setq _ballY (round __ballY))
   (setq _ballDist (round __ballDist))
   (setq _ballTheta (float __ballTheta))
   (setq _cylinderX (round __cylinderX))
   (setq _cylinderY (round __cylinderY))
   (setq _cylinderDist (round __cylinderDist))
   (setq _cylinderTheta (float __cylinderTheta))
   (setq _directX (round __directX))
   (setq _directY (round __directY))
   (setq _directDist (round __directDist))
   (setq _directTheta (float __directTheta))
   (setq _first_start (round __first_start))
   (setq _circlex (round __circlex))
   (setq _circley (round __circley))
   self)
  (:ballX
   (&optional __ballX)
   (if __ballX (setq _ballX __ballX)) _ballX)
  (:ballY
   (&optional __ballY)
   (if __ballY (setq _ballY __ballY)) _ballY)
  (:ballDist
   (&optional __ballDist)
   (if __ballDist (setq _ballDist __ballDist)) _ballDist)
  (:ballTheta
   (&optional __ballTheta)
   (if __ballTheta (setq _ballTheta __ballTheta)) _ballTheta)
  (:cylinderX
   (&optional __cylinderX)
   (if __cylinderX (setq _cylinderX __cylinderX)) _cylinderX)
  (:cylinderY
   (&optional __cylinderY)
   (if __cylinderY (setq _cylinderY __cylinderY)) _cylinderY)
  (:cylinderDist
   (&optional __cylinderDist)
   (if __cylinderDist (setq _cylinderDist __cylinderDist)) _cylinderDist)
  (:cylinderTheta
   (&optional __cylinderTheta)
   (if __cylinderTheta (setq _cylinderTheta __cylinderTheta)) _cylinderTheta)
  (:directX
   (&optional __directX)
   (if __directX (setq _directX __directX)) _directX)
  (:directY
   (&optional __directY)
   (if __directY (setq _directY __directY)) _directY)
  (:directDist
   (&optional __directDist)
   (if __directDist (setq _directDist __directDist)) _directDist)
  (:directTheta
   (&optional __directTheta)
   (if __directTheta (setq _directTheta __directTheta)) _directTheta)
  (:first_start
   (&optional __first_start)
   (if __first_start (setq _first_start __first_start)) _first_start)
  (:circlex
   (&optional __circlex)
   (if __circlex (setq _circlex __circlex)) _circlex)
  (:circley
   (&optional __circley)
   (if __circley (setq _circley __circley)) _circley)
  (:serialization-length
   ()
   (+
    ;; int64 _ballX
    8
    ;; int64 _ballY
    8
    ;; int64 _ballDist
    8
    ;; float64 _ballTheta
    8
    ;; int64 _cylinderX
    8
    ;; int64 _cylinderY
    8
    ;; int64 _cylinderDist
    8
    ;; float64 _cylinderTheta
    8
    ;; int64 _directX
    8
    ;; int64 _directY
    8
    ;; int64 _directDist
    8
    ;; float64 _directTheta
    8
    ;; int64 _first_start
    8
    ;; int64 _circlex
    8
    ;; int64 _circley
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _ballX
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballX (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballX) (= (length (_ballX . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballX . bv) 0) 0) s)
              (write-long (ash (elt (_ballX . bv) 1) -1) s))
             ((and (class _ballX) (= (length (_ballX . bv)) 1)) ;; big1
              (write-long (elt (_ballX . bv) 0) s)
              (write-long (if (>= _ballX 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballX s)(write-long (if (>= _ballX 0) 0 #xffffffff) s)))
     ;; int64 _ballY
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballY (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballY) (= (length (_ballY . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballY . bv) 0) 0) s)
              (write-long (ash (elt (_ballY . bv) 1) -1) s))
             ((and (class _ballY) (= (length (_ballY . bv)) 1)) ;; big1
              (write-long (elt (_ballY . bv) 0) s)
              (write-long (if (>= _ballY 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballY s)(write-long (if (>= _ballY 0) 0 #xffffffff) s)))
     ;; int64 _ballDist
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballDist (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballDist) (= (length (_ballDist . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballDist . bv) 0) 0) s)
              (write-long (ash (elt (_ballDist . bv) 1) -1) s))
             ((and (class _ballDist) (= (length (_ballDist . bv)) 1)) ;; big1
              (write-long (elt (_ballDist . bv) 0) s)
              (write-long (if (>= _ballDist 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballDist s)(write-long (if (>= _ballDist 0) 0 #xffffffff) s)))
     ;; float64 _ballTheta
       (sys::poke _ballTheta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _cylinderX
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cylinderX (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cylinderX) (= (length (_cylinderX . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cylinderX . bv) 0) 0) s)
              (write-long (ash (elt (_cylinderX . bv) 1) -1) s))
             ((and (class _cylinderX) (= (length (_cylinderX . bv)) 1)) ;; big1
              (write-long (elt (_cylinderX . bv) 0) s)
              (write-long (if (>= _cylinderX 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cylinderX s)(write-long (if (>= _cylinderX 0) 0 #xffffffff) s)))
     ;; int64 _cylinderY
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cylinderY (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cylinderY) (= (length (_cylinderY . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cylinderY . bv) 0) 0) s)
              (write-long (ash (elt (_cylinderY . bv) 1) -1) s))
             ((and (class _cylinderY) (= (length (_cylinderY . bv)) 1)) ;; big1
              (write-long (elt (_cylinderY . bv) 0) s)
              (write-long (if (>= _cylinderY 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cylinderY s)(write-long (if (>= _cylinderY 0) 0 #xffffffff) s)))
     ;; int64 _cylinderDist
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cylinderDist (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cylinderDist) (= (length (_cylinderDist . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cylinderDist . bv) 0) 0) s)
              (write-long (ash (elt (_cylinderDist . bv) 1) -1) s))
             ((and (class _cylinderDist) (= (length (_cylinderDist . bv)) 1)) ;; big1
              (write-long (elt (_cylinderDist . bv) 0) s)
              (write-long (if (>= _cylinderDist 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cylinderDist s)(write-long (if (>= _cylinderDist 0) 0 #xffffffff) s)))
     ;; float64 _cylinderTheta
       (sys::poke _cylinderTheta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _directX
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _directX (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _directX) (= (length (_directX . bv)) 2)) ;; bignum
              (write-long (ash (elt (_directX . bv) 0) 0) s)
              (write-long (ash (elt (_directX . bv) 1) -1) s))
             ((and (class _directX) (= (length (_directX . bv)) 1)) ;; big1
              (write-long (elt (_directX . bv) 0) s)
              (write-long (if (>= _directX 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _directX s)(write-long (if (>= _directX 0) 0 #xffffffff) s)))
     ;; int64 _directY
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _directY (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _directY) (= (length (_directY . bv)) 2)) ;; bignum
              (write-long (ash (elt (_directY . bv) 0) 0) s)
              (write-long (ash (elt (_directY . bv) 1) -1) s))
             ((and (class _directY) (= (length (_directY . bv)) 1)) ;; big1
              (write-long (elt (_directY . bv) 0) s)
              (write-long (if (>= _directY 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _directY s)(write-long (if (>= _directY 0) 0 #xffffffff) s)))
     ;; int64 _directDist
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _directDist (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _directDist) (= (length (_directDist . bv)) 2)) ;; bignum
              (write-long (ash (elt (_directDist . bv) 0) 0) s)
              (write-long (ash (elt (_directDist . bv) 1) -1) s))
             ((and (class _directDist) (= (length (_directDist . bv)) 1)) ;; big1
              (write-long (elt (_directDist . bv) 0) s)
              (write-long (if (>= _directDist 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _directDist s)(write-long (if (>= _directDist 0) 0 #xffffffff) s)))
     ;; float64 _directTheta
       (sys::poke _directTheta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _first_start
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _first_start (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _first_start) (= (length (_first_start . bv)) 2)) ;; bignum
              (write-long (ash (elt (_first_start . bv) 0) 0) s)
              (write-long (ash (elt (_first_start . bv) 1) -1) s))
             ((and (class _first_start) (= (length (_first_start . bv)) 1)) ;; big1
              (write-long (elt (_first_start . bv) 0) s)
              (write-long (if (>= _first_start 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _first_start s)(write-long (if (>= _first_start 0) 0 #xffffffff) s)))
     ;; int64 _circlex
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _circlex (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _circlex) (= (length (_circlex . bv)) 2)) ;; bignum
              (write-long (ash (elt (_circlex . bv) 0) 0) s)
              (write-long (ash (elt (_circlex . bv) 1) -1) s))
             ((and (class _circlex) (= (length (_circlex . bv)) 1)) ;; big1
              (write-long (elt (_circlex . bv) 0) s)
              (write-long (if (>= _circlex 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _circlex s)(write-long (if (>= _circlex 0) 0 #xffffffff) s)))
     ;; int64 _circley
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _circley (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _circley) (= (length (_circley . bv)) 2)) ;; bignum
              (write-long (ash (elt (_circley . bv) 0) 0) s)
              (write-long (ash (elt (_circley . bv) 1) -1) s))
             ((and (class _circley) (= (length (_circley . bv)) 1)) ;; big1
              (write-long (elt (_circley . bv) 0) s)
              (write-long (if (>= _circley 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _circley s)(write-long (if (>= _circley 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _ballX
#+(or :alpha :irix6 :x86_64)
      (setf _ballX (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballX (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ballY
#+(or :alpha :irix6 :x86_64)
      (setf _ballY (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballY (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ballDist
#+(or :alpha :irix6 :x86_64)
      (setf _ballDist (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballDist (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _ballTheta
     (setq _ballTheta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _cylinderX
#+(or :alpha :irix6 :x86_64)
      (setf _cylinderX (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cylinderX (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _cylinderY
#+(or :alpha :irix6 :x86_64)
      (setf _cylinderY (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cylinderY (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _cylinderDist
#+(or :alpha :irix6 :x86_64)
      (setf _cylinderDist (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cylinderDist (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _cylinderTheta
     (setq _cylinderTheta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _directX
#+(or :alpha :irix6 :x86_64)
      (setf _directX (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _directX (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _directY
#+(or :alpha :irix6 :x86_64)
      (setf _directY (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _directY (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _directDist
#+(or :alpha :irix6 :x86_64)
      (setf _directDist (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _directDist (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _directTheta
     (setq _directTheta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _first_start
#+(or :alpha :irix6 :x86_64)
      (setf _first_start (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _first_start (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _circlex
#+(or :alpha :irix6 :x86_64)
      (setf _circlex (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _circlex (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _circley
#+(or :alpha :irix6 :x86_64)
      (setf _circley (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _circley (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::scv_vision :md5sum-) "65c896941af724ac4f09562adde2b414")
(setf (get msg_generate::scv_vision :datatype-) "msg_generate/scv_vision")
(setf (get msg_generate::scv_vision :definition-)
      "int64 ballX
int64 ballY
int64 ballDist
float64 ballTheta
int64 cylinderX
int64 cylinderY
int64 cylinderDist
float64 cylinderTheta
int64 directX
int64 directY
int64 directDist
float64 directTheta
int64 first_start
int64 circlex
int64 circley

")



(provide :msg_generate/scv_vision "65c896941af724ac4f09562adde2b414")


