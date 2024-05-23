;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::localization_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'localization_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::LOCALIZATION_MSG")
  (make-package "MSG_GENERATE::LOCALIZATION_MSG"))

(in-package "ROS")
;;//! \htmlinclude localization_msg.msg.html


(defclass msg_generate::localization_msg
  :super ros::object
  :slots (_ballDist _ballTheta _xcrossDist _xcrossTheta _goalpostDist _goalpostTheta _pointDist _pointTheta _penaltyCircleDist _penaltyCircleTheta _oneline ))

(defmethod msg_generate::localization_msg
  (:init
   (&key
    ((:ballDist __ballDist) 0)
    ((:ballTheta __ballTheta) 0)
    ((:xcrossDist __xcrossDist) (make-array 0 :initial-element 0 :element-type :integer))
    ((:xcrossTheta __xcrossTheta) (make-array 0 :initial-element 0 :element-type :integer))
    ((:goalpostDist __goalpostDist) (make-array 0 :initial-element 0 :element-type :integer))
    ((:goalpostTheta __goalpostTheta) (make-array 0 :initial-element 0 :element-type :integer))
    ((:pointDist __pointDist) (make-array 0 :initial-element 0 :element-type :integer))
    ((:pointTheta __pointTheta) (make-array 0 :initial-element 0 :element-type :integer))
    ((:penaltyCircleDist __penaltyCircleDist) (make-array 0 :initial-element 0 :element-type :integer))
    ((:penaltyCircleTheta __penaltyCircleTheta) (make-array 0 :initial-element 0 :element-type :integer))
    ((:oneline __oneline) 0)
    )
   (send-super :init)
   (setq _ballDist (round __ballDist))
   (setq _ballTheta (round __ballTheta))
   (setq _xcrossDist __xcrossDist)
   (setq _xcrossTheta __xcrossTheta)
   (setq _goalpostDist __goalpostDist)
   (setq _goalpostTheta __goalpostTheta)
   (setq _pointDist __pointDist)
   (setq _pointTheta __pointTheta)
   (setq _penaltyCircleDist __penaltyCircleDist)
   (setq _penaltyCircleTheta __penaltyCircleTheta)
   (setq _oneline (round __oneline))
   self)
  (:ballDist
   (&optional __ballDist)
   (if __ballDist (setq _ballDist __ballDist)) _ballDist)
  (:ballTheta
   (&optional __ballTheta)
   (if __ballTheta (setq _ballTheta __ballTheta)) _ballTheta)
  (:xcrossDist
   (&optional __xcrossDist)
   (if __xcrossDist (setq _xcrossDist __xcrossDist)) _xcrossDist)
  (:xcrossTheta
   (&optional __xcrossTheta)
   (if __xcrossTheta (setq _xcrossTheta __xcrossTheta)) _xcrossTheta)
  (:goalpostDist
   (&optional __goalpostDist)
   (if __goalpostDist (setq _goalpostDist __goalpostDist)) _goalpostDist)
  (:goalpostTheta
   (&optional __goalpostTheta)
   (if __goalpostTheta (setq _goalpostTheta __goalpostTheta)) _goalpostTheta)
  (:pointDist
   (&optional __pointDist)
   (if __pointDist (setq _pointDist __pointDist)) _pointDist)
  (:pointTheta
   (&optional __pointTheta)
   (if __pointTheta (setq _pointTheta __pointTheta)) _pointTheta)
  (:penaltyCircleDist
   (&optional __penaltyCircleDist)
   (if __penaltyCircleDist (setq _penaltyCircleDist __penaltyCircleDist)) _penaltyCircleDist)
  (:penaltyCircleTheta
   (&optional __penaltyCircleTheta)
   (if __penaltyCircleTheta (setq _penaltyCircleTheta __penaltyCircleTheta)) _penaltyCircleTheta)
  (:oneline
   (&optional __oneline)
   (if __oneline (setq _oneline __oneline)) _oneline)
  (:serialization-length
   ()
   (+
    ;; int64 _ballDist
    8
    ;; int64 _ballTheta
    8
    ;; int64[] _xcrossDist
    (* 8    (length _xcrossDist)) 4
    ;; int64[] _xcrossTheta
    (* 8    (length _xcrossTheta)) 4
    ;; int64[] _goalpostDist
    (* 8    (length _goalpostDist)) 4
    ;; int64[] _goalpostTheta
    (* 8    (length _goalpostTheta)) 4
    ;; int64[] _pointDist
    (* 8    (length _pointDist)) 4
    ;; int64[] _pointTheta
    (* 8    (length _pointTheta)) 4
    ;; int64[] _penaltyCircleDist
    (* 8    (length _penaltyCircleDist)) 4
    ;; int64[] _penaltyCircleTheta
    (* 8    (length _penaltyCircleTheta)) 4
    ;; int64 _oneline
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
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
     ;; int64 _ballTheta
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballTheta (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballTheta) (= (length (_ballTheta . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballTheta . bv) 0) 0) s)
              (write-long (ash (elt (_ballTheta . bv) 1) -1) s))
             ((and (class _ballTheta) (= (length (_ballTheta . bv)) 1)) ;; big1
              (write-long (elt (_ballTheta . bv) 0) s)
              (write-long (if (>= _ballTheta 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballTheta s)(write-long (if (>= _ballTheta 0) 0 #xffffffff) s)))
     ;; int64[] _xcrossDist
     (write-long (length _xcrossDist) s)
     (dotimes (i (length _xcrossDist))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _xcrossDist i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _xcrossDist i)) (= (length ((elt _xcrossDist i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _xcrossDist i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _xcrossDist i) . bv) 1) -1) s))
             ((and (class (elt _xcrossDist i)) (= (length ((elt _xcrossDist i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _xcrossDist i) . bv) 0) s)
              (write-long (if (>= (elt _xcrossDist i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _xcrossDist i) s)(write-long (if (>= (elt _xcrossDist i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _xcrossTheta
     (write-long (length _xcrossTheta) s)
     (dotimes (i (length _xcrossTheta))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _xcrossTheta i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _xcrossTheta i)) (= (length ((elt _xcrossTheta i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _xcrossTheta i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _xcrossTheta i) . bv) 1) -1) s))
             ((and (class (elt _xcrossTheta i)) (= (length ((elt _xcrossTheta i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _xcrossTheta i) . bv) 0) s)
              (write-long (if (>= (elt _xcrossTheta i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _xcrossTheta i) s)(write-long (if (>= (elt _xcrossTheta i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _goalpostDist
     (write-long (length _goalpostDist) s)
     (dotimes (i (length _goalpostDist))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _goalpostDist i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _goalpostDist i)) (= (length ((elt _goalpostDist i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _goalpostDist i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _goalpostDist i) . bv) 1) -1) s))
             ((and (class (elt _goalpostDist i)) (= (length ((elt _goalpostDist i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _goalpostDist i) . bv) 0) s)
              (write-long (if (>= (elt _goalpostDist i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _goalpostDist i) s)(write-long (if (>= (elt _goalpostDist i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _goalpostTheta
     (write-long (length _goalpostTheta) s)
     (dotimes (i (length _goalpostTheta))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _goalpostTheta i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _goalpostTheta i)) (= (length ((elt _goalpostTheta i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _goalpostTheta i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _goalpostTheta i) . bv) 1) -1) s))
             ((and (class (elt _goalpostTheta i)) (= (length ((elt _goalpostTheta i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _goalpostTheta i) . bv) 0) s)
              (write-long (if (>= (elt _goalpostTheta i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _goalpostTheta i) s)(write-long (if (>= (elt _goalpostTheta i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _pointDist
     (write-long (length _pointDist) s)
     (dotimes (i (length _pointDist))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _pointDist i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _pointDist i)) (= (length ((elt _pointDist i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _pointDist i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _pointDist i) . bv) 1) -1) s))
             ((and (class (elt _pointDist i)) (= (length ((elt _pointDist i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _pointDist i) . bv) 0) s)
              (write-long (if (>= (elt _pointDist i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _pointDist i) s)(write-long (if (>= (elt _pointDist i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _pointTheta
     (write-long (length _pointTheta) s)
     (dotimes (i (length _pointTheta))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _pointTheta i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _pointTheta i)) (= (length ((elt _pointTheta i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _pointTheta i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _pointTheta i) . bv) 1) -1) s))
             ((and (class (elt _pointTheta i)) (= (length ((elt _pointTheta i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _pointTheta i) . bv) 0) s)
              (write-long (if (>= (elt _pointTheta i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _pointTheta i) s)(write-long (if (>= (elt _pointTheta i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _penaltyCircleDist
     (write-long (length _penaltyCircleDist) s)
     (dotimes (i (length _penaltyCircleDist))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _penaltyCircleDist i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _penaltyCircleDist i)) (= (length ((elt _penaltyCircleDist i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _penaltyCircleDist i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _penaltyCircleDist i) . bv) 1) -1) s))
             ((and (class (elt _penaltyCircleDist i)) (= (length ((elt _penaltyCircleDist i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _penaltyCircleDist i) . bv) 0) s)
              (write-long (if (>= (elt _penaltyCircleDist i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _penaltyCircleDist i) s)(write-long (if (>= (elt _penaltyCircleDist i) 0) 0 #xffffffff) s)))
       )
     ;; int64[] _penaltyCircleTheta
     (write-long (length _penaltyCircleTheta) s)
     (dotimes (i (length _penaltyCircleTheta))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _penaltyCircleTheta i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _penaltyCircleTheta i)) (= (length ((elt _penaltyCircleTheta i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _penaltyCircleTheta i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _penaltyCircleTheta i) . bv) 1) -1) s))
             ((and (class (elt _penaltyCircleTheta i)) (= (length ((elt _penaltyCircleTheta i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _penaltyCircleTheta i) . bv) 0) s)
              (write-long (if (>= (elt _penaltyCircleTheta i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _penaltyCircleTheta i) s)(write-long (if (>= (elt _penaltyCircleTheta i) 0) 0 #xffffffff) s)))
       )
     ;; int64 _oneline
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _oneline (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _oneline) (= (length (_oneline . bv)) 2)) ;; bignum
              (write-long (ash (elt (_oneline . bv) 0) 0) s)
              (write-long (ash (elt (_oneline . bv) 1) -1) s))
             ((and (class _oneline) (= (length (_oneline . bv)) 1)) ;; big1
              (write-long (elt (_oneline . bv) 0) s)
              (write-long (if (>= _oneline 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _oneline s)(write-long (if (>= _oneline 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
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
   ;; int64 _ballTheta
#+(or :alpha :irix6 :x86_64)
      (setf _ballTheta (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballTheta (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64[] _xcrossDist
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _xcrossDist (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _xcrossDist i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _xcrossDist i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _xcrossTheta
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _xcrossTheta (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _xcrossTheta i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _xcrossTheta i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _goalpostDist
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _goalpostDist (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _goalpostDist i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _goalpostDist i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _goalpostTheta
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _goalpostTheta (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _goalpostTheta i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _goalpostTheta i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _pointDist
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pointDist (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _pointDist i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _pointDist i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _pointTheta
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _pointTheta (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _pointTheta i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _pointTheta i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _penaltyCircleDist
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _penaltyCircleDist (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _penaltyCircleDist i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _penaltyCircleDist i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64[] _penaltyCircleTheta
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _penaltyCircleTheta (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _penaltyCircleTheta i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _penaltyCircleTheta i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;; int64 _oneline
#+(or :alpha :irix6 :x86_64)
      (setf _oneline (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _oneline (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::localization_msg :md5sum-) "1199688341e3ebe99dc4295b1eed20cc")
(setf (get msg_generate::localization_msg :datatype-) "msg_generate/localization_msg")
(setf (get msg_generate::localization_msg :definition-)
      "int64 ballDist
int64 ballTheta

int64[] xcrossDist
int64[] xcrossTheta

int64[] goalpostDist
int64[] goalpostTheta

int64[] pointDist
int64[] pointTheta

int64[] penaltyCircleDist
int64[] penaltyCircleTheta

int64 oneline

")



(provide :msg_generate/localization_msg "1199688341e3ebe99dc4295b1eed20cc")


