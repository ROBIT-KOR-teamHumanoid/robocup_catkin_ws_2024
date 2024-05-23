;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::robocupcontroller)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'robocupcontroller (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ROBOCUPCONTROLLER")
  (make-package "MSG_GENERATE::ROBOCUPCONTROLLER"))

(in-package "ROS")
;;//! \htmlinclude robocupcontroller.msg.html


(defclass msg_generate::robocupcontroller
  :super ros::object
  :slots (_robotNum _state _readyTime _penalty _firstHalf _firstside _kickoffTeam _secondState _secondInfo ))

(defmethod msg_generate::robocupcontroller
  (:init
   (&key
    ((:robotNum __robotNum) 0)
    ((:state __state) 0)
    ((:readyTime __readyTime) 0)
    ((:penalty __penalty) 0)
    ((:firstHalf __firstHalf) 0)
    ((:firstside __firstside) 0)
    ((:kickoffTeam __kickoffTeam) 0)
    ((:secondState __secondState) 0)
    ((:secondInfo __secondInfo) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _robotNum (round __robotNum))
   (setq _state (round __state))
   (setq _readyTime (round __readyTime))
   (setq _penalty (round __penalty))
   (setq _firstHalf (round __firstHalf))
   (setq _firstside (round __firstside))
   (setq _kickoffTeam (round __kickoffTeam))
   (setq _secondState (round __secondState))
   (setq _secondInfo __secondInfo)
   self)
  (:robotNum
   (&optional __robotNum)
   (if __robotNum (setq _robotNum __robotNum)) _robotNum)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:readyTime
   (&optional __readyTime)
   (if __readyTime (setq _readyTime __readyTime)) _readyTime)
  (:penalty
   (&optional __penalty)
   (if __penalty (setq _penalty __penalty)) _penalty)
  (:firstHalf
   (&optional __firstHalf)
   (if __firstHalf (setq _firstHalf __firstHalf)) _firstHalf)
  (:firstside
   (&optional __firstside)
   (if __firstside (setq _firstside __firstside)) _firstside)
  (:kickoffTeam
   (&optional __kickoffTeam)
   (if __kickoffTeam (setq _kickoffTeam __kickoffTeam)) _kickoffTeam)
  (:secondState
   (&optional __secondState)
   (if __secondState (setq _secondState __secondState)) _secondState)
  (:secondInfo
   (&optional __secondInfo)
   (if __secondInfo (setq _secondInfo __secondInfo)) _secondInfo)
  (:serialization-length
   ()
   (+
    ;; int64 _robotNum
    8
    ;; int64 _state
    8
    ;; int64 _readyTime
    8
    ;; int64 _penalty
    8
    ;; int64 _firstHalf
    8
    ;; int64 _firstside
    8
    ;; int64 _kickoffTeam
    8
    ;; int64 _secondState
    8
    ;; int64[] _secondInfo
    (* 8    (length _secondInfo)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _robotNum
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robotNum (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robotNum) (= (length (_robotNum . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robotNum . bv) 0) 0) s)
              (write-long (ash (elt (_robotNum . bv) 1) -1) s))
             ((and (class _robotNum) (= (length (_robotNum . bv)) 1)) ;; big1
              (write-long (elt (_robotNum . bv) 0) s)
              (write-long (if (>= _robotNum 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robotNum s)(write-long (if (>= _robotNum 0) 0 #xffffffff) s)))
     ;; int64 _state
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _state (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _state) (= (length (_state . bv)) 2)) ;; bignum
              (write-long (ash (elt (_state . bv) 0) 0) s)
              (write-long (ash (elt (_state . bv) 1) -1) s))
             ((and (class _state) (= (length (_state . bv)) 1)) ;; big1
              (write-long (elt (_state . bv) 0) s)
              (write-long (if (>= _state 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _state s)(write-long (if (>= _state 0) 0 #xffffffff) s)))
     ;; int64 _readyTime
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _readyTime (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _readyTime) (= (length (_readyTime . bv)) 2)) ;; bignum
              (write-long (ash (elt (_readyTime . bv) 0) 0) s)
              (write-long (ash (elt (_readyTime . bv) 1) -1) s))
             ((and (class _readyTime) (= (length (_readyTime . bv)) 1)) ;; big1
              (write-long (elt (_readyTime . bv) 0) s)
              (write-long (if (>= _readyTime 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _readyTime s)(write-long (if (>= _readyTime 0) 0 #xffffffff) s)))
     ;; int64 _penalty
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _penalty (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _penalty) (= (length (_penalty . bv)) 2)) ;; bignum
              (write-long (ash (elt (_penalty . bv) 0) 0) s)
              (write-long (ash (elt (_penalty . bv) 1) -1) s))
             ((and (class _penalty) (= (length (_penalty . bv)) 1)) ;; big1
              (write-long (elt (_penalty . bv) 0) s)
              (write-long (if (>= _penalty 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _penalty s)(write-long (if (>= _penalty 0) 0 #xffffffff) s)))
     ;; int64 _firstHalf
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _firstHalf (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _firstHalf) (= (length (_firstHalf . bv)) 2)) ;; bignum
              (write-long (ash (elt (_firstHalf . bv) 0) 0) s)
              (write-long (ash (elt (_firstHalf . bv) 1) -1) s))
             ((and (class _firstHalf) (= (length (_firstHalf . bv)) 1)) ;; big1
              (write-long (elt (_firstHalf . bv) 0) s)
              (write-long (if (>= _firstHalf 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _firstHalf s)(write-long (if (>= _firstHalf 0) 0 #xffffffff) s)))
     ;; int64 _firstside
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _firstside (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _firstside) (= (length (_firstside . bv)) 2)) ;; bignum
              (write-long (ash (elt (_firstside . bv) 0) 0) s)
              (write-long (ash (elt (_firstside . bv) 1) -1) s))
             ((and (class _firstside) (= (length (_firstside . bv)) 1)) ;; big1
              (write-long (elt (_firstside . bv) 0) s)
              (write-long (if (>= _firstside 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _firstside s)(write-long (if (>= _firstside 0) 0 #xffffffff) s)))
     ;; int64 _kickoffTeam
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _kickoffTeam (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _kickoffTeam) (= (length (_kickoffTeam . bv)) 2)) ;; bignum
              (write-long (ash (elt (_kickoffTeam . bv) 0) 0) s)
              (write-long (ash (elt (_kickoffTeam . bv) 1) -1) s))
             ((and (class _kickoffTeam) (= (length (_kickoffTeam . bv)) 1)) ;; big1
              (write-long (elt (_kickoffTeam . bv) 0) s)
              (write-long (if (>= _kickoffTeam 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _kickoffTeam s)(write-long (if (>= _kickoffTeam 0) 0 #xffffffff) s)))
     ;; int64 _secondState
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _secondState (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _secondState) (= (length (_secondState . bv)) 2)) ;; bignum
              (write-long (ash (elt (_secondState . bv) 0) 0) s)
              (write-long (ash (elt (_secondState . bv) 1) -1) s))
             ((and (class _secondState) (= (length (_secondState . bv)) 1)) ;; big1
              (write-long (elt (_secondState . bv) 0) s)
              (write-long (if (>= _secondState 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _secondState s)(write-long (if (>= _secondState 0) 0 #xffffffff) s)))
     ;; int64[] _secondInfo
     (write-long (length _secondInfo) s)
     (dotimes (i (length _secondInfo))
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke (elt _secondInfo i) (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class (elt _secondInfo i)) (= (length ((elt _secondInfo i) . bv)) 2)) ;; bignum
              (write-long (ash (elt ((elt _secondInfo i) . bv) 0) 0) s)
              (write-long (ash (elt ((elt _secondInfo i) . bv) 1) -1) s))
             ((and (class (elt _secondInfo i)) (= (length ((elt _secondInfo i) . bv)) 1)) ;; big1
              (write-long (elt ((elt _secondInfo i) . bv) 0) s)
              (write-long (if (>= (elt _secondInfo i) 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long (elt _secondInfo i) s)(write-long (if (>= (elt _secondInfo i) 0) 0 #xffffffff) s)))
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _robotNum
#+(or :alpha :irix6 :x86_64)
      (setf _robotNum (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robotNum (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _state
#+(or :alpha :irix6 :x86_64)
      (setf _state (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _state (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _readyTime
#+(or :alpha :irix6 :x86_64)
      (setf _readyTime (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _readyTime (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _penalty
#+(or :alpha :irix6 :x86_64)
      (setf _penalty (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _penalty (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _firstHalf
#+(or :alpha :irix6 :x86_64)
      (setf _firstHalf (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _firstHalf (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _firstside
#+(or :alpha :irix6 :x86_64)
      (setf _firstside (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _firstside (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _kickoffTeam
#+(or :alpha :irix6 :x86_64)
      (setf _kickoffTeam (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _kickoffTeam (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _secondState
#+(or :alpha :irix6 :x86_64)
      (setf _secondState (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _secondState (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64[] _secondInfo
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _secondInfo (instantiate integer-vector n))
     (dotimes (i n)
#+(or :alpha :irix6 :x86_64)
      (setf (elt _secondInfo i) (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf (elt _secondInfo i) (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
     ))
   ;;
   self)
  )

(setf (get msg_generate::robocupcontroller :md5sum-) "878b95f20caac6a00b10d1f878052102")
(setf (get msg_generate::robocupcontroller :datatype-) "msg_generate/robocupcontroller")
(setf (get msg_generate::robocupcontroller :definition-)
      "int64 robotNum
int64 state
int64 readyTime
int64 penalty
int64 firstHalf
int64 firstside
int64 kickoffTeam
int64 secondState
int64[] secondInfo

")



(provide :msg_generate/robocupcontroller "878b95f20caac6a00b10d1f878052102")


