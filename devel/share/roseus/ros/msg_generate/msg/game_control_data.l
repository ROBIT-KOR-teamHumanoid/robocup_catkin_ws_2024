;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::game_control_data)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'game_control_data (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::GAME_CONTROL_DATA")
  (make-package "MSG_GENERATE::GAME_CONTROL_DATA"))

(in-package "ROS")
;;//! \htmlinclude game_control_data.msg.html


(defclass msg_generate::game_control_data
  :super ros::object
  :slots (_robotNum _position _myTeam _state _mySide _iskickoff _readyTime _penalty _secondState _secondInfo ))

(defmethod msg_generate::game_control_data
  (:init
   (&key
    ((:robotNum __robotNum) 0)
    ((:position __position) 0)
    ((:myTeam __myTeam) 0)
    ((:state __state) 0)
    ((:mySide __mySide) 0)
    ((:iskickoff __iskickoff) 0)
    ((:readyTime __readyTime) 0)
    ((:penalty __penalty) 0)
    ((:secondState __secondState) 0)
    ((:secondInfo __secondInfo) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _robotNum (round __robotNum))
   (setq _position (round __position))
   (setq _myTeam (round __myTeam))
   (setq _state (round __state))
   (setq _mySide (round __mySide))
   (setq _iskickoff (round __iskickoff))
   (setq _readyTime (round __readyTime))
   (setq _penalty (round __penalty))
   (setq _secondState (round __secondState))
   (setq _secondInfo __secondInfo)
   self)
  (:robotNum
   (&optional __robotNum)
   (if __robotNum (setq _robotNum __robotNum)) _robotNum)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:myTeam
   (&optional __myTeam)
   (if __myTeam (setq _myTeam __myTeam)) _myTeam)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:mySide
   (&optional __mySide)
   (if __mySide (setq _mySide __mySide)) _mySide)
  (:iskickoff
   (&optional __iskickoff)
   (if __iskickoff (setq _iskickoff __iskickoff)) _iskickoff)
  (:readyTime
   (&optional __readyTime)
   (if __readyTime (setq _readyTime __readyTime)) _readyTime)
  (:penalty
   (&optional __penalty)
   (if __penalty (setq _penalty __penalty)) _penalty)
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
    ;; int64 _position
    8
    ;; int64 _myTeam
    8
    ;; int64 _state
    8
    ;; int64 _mySide
    8
    ;; int64 _iskickoff
    8
    ;; int64 _readyTime
    8
    ;; int64 _penalty
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
     ;; int64 _position
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _position (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _position) (= (length (_position . bv)) 2)) ;; bignum
              (write-long (ash (elt (_position . bv) 0) 0) s)
              (write-long (ash (elt (_position . bv) 1) -1) s))
             ((and (class _position) (= (length (_position . bv)) 1)) ;; big1
              (write-long (elt (_position . bv) 0) s)
              (write-long (if (>= _position 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _position s)(write-long (if (>= _position 0) 0 #xffffffff) s)))
     ;; int64 _myTeam
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _myTeam (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _myTeam) (= (length (_myTeam . bv)) 2)) ;; bignum
              (write-long (ash (elt (_myTeam . bv) 0) 0) s)
              (write-long (ash (elt (_myTeam . bv) 1) -1) s))
             ((and (class _myTeam) (= (length (_myTeam . bv)) 1)) ;; big1
              (write-long (elt (_myTeam . bv) 0) s)
              (write-long (if (>= _myTeam 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _myTeam s)(write-long (if (>= _myTeam 0) 0 #xffffffff) s)))
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
     ;; int64 _mySide
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _mySide (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _mySide) (= (length (_mySide . bv)) 2)) ;; bignum
              (write-long (ash (elt (_mySide . bv) 0) 0) s)
              (write-long (ash (elt (_mySide . bv) 1) -1) s))
             ((and (class _mySide) (= (length (_mySide . bv)) 1)) ;; big1
              (write-long (elt (_mySide . bv) 0) s)
              (write-long (if (>= _mySide 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _mySide s)(write-long (if (>= _mySide 0) 0 #xffffffff) s)))
     ;; int64 _iskickoff
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _iskickoff (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _iskickoff) (= (length (_iskickoff . bv)) 2)) ;; bignum
              (write-long (ash (elt (_iskickoff . bv) 0) 0) s)
              (write-long (ash (elt (_iskickoff . bv) 1) -1) s))
             ((and (class _iskickoff) (= (length (_iskickoff . bv)) 1)) ;; big1
              (write-long (elt (_iskickoff . bv) 0) s)
              (write-long (if (>= _iskickoff 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _iskickoff s)(write-long (if (>= _iskickoff 0) 0 #xffffffff) s)))
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
   ;; int64 _position
#+(or :alpha :irix6 :x86_64)
      (setf _position (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _position (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _myTeam
#+(or :alpha :irix6 :x86_64)
      (setf _myTeam (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _myTeam (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;; int64 _mySide
#+(or :alpha :irix6 :x86_64)
      (setf _mySide (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _mySide (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _iskickoff
#+(or :alpha :irix6 :x86_64)
      (setf _iskickoff (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _iskickoff (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::game_control_data :md5sum-) "2d9766fbb6334c79351c86b83016bef8")
(setf (get msg_generate::game_control_data :datatype-) "msg_generate/game_control_data")
(setf (get msg_generate::game_control_data :definition-)
      "int64 robotNum
int64 position
int64 myTeam

int64 state
int64 mySide
int64 iskickoff
int64 readyTime
int64 penalty
int64 secondState
int64[] secondInfo

")



(provide :msg_generate/game_control_data "2d9766fbb6334c79351c86b83016bef8")


