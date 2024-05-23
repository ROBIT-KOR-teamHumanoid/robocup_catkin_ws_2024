;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Running_2020_vision)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Running_2020_vision (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::RUNNING_2020_VISION")
  (make-package "MSG_GENERATE::RUNNING_2020_VISION"))

(in-package "ROS")
;;//! \htmlinclude Running_2020_vision.msg.html


(defclass msg_generate::Running_2020_vision
  :super ros::object
  :slots (_Way _start_x _start_y _goal_x _goal_y _direction _recog_goal_x ))

(defmethod msg_generate::Running_2020_vision
  (:init
   (&key
    ((:Way __Way) 0)
    ((:start_x __start_x) 0)
    ((:start_y __start_y) 0)
    ((:goal_x __goal_x) 0)
    ((:goal_y __goal_y) 0)
    ((:direction __direction) 0)
    ((:recog_goal_x __recog_goal_x) nil)
    )
   (send-super :init)
   (setq _Way (round __Way))
   (setq _start_x (round __start_x))
   (setq _start_y (round __start_y))
   (setq _goal_x (round __goal_x))
   (setq _goal_y (round __goal_y))
   (setq _direction (round __direction))
   (setq _recog_goal_x __recog_goal_x)
   self)
  (:Way
   (&optional __Way)
   (if __Way (setq _Way __Way)) _Way)
  (:start_x
   (&optional __start_x)
   (if __start_x (setq _start_x __start_x)) _start_x)
  (:start_y
   (&optional __start_y)
   (if __start_y (setq _start_y __start_y)) _start_y)
  (:goal_x
   (&optional __goal_x)
   (if __goal_x (setq _goal_x __goal_x)) _goal_x)
  (:goal_y
   (&optional __goal_y)
   (if __goal_y (setq _goal_y __goal_y)) _goal_y)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:recog_goal_x
   (&optional __recog_goal_x)
   (if __recog_goal_x (setq _recog_goal_x __recog_goal_x)) _recog_goal_x)
  (:serialization-length
   ()
   (+
    ;; int64 _Way
    8
    ;; int64 _start_x
    8
    ;; int64 _start_y
    8
    ;; int64 _goal_x
    8
    ;; int64 _goal_y
    8
    ;; int64 _direction
    8
    ;; bool _recog_goal_x
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _Way
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _Way (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _Way) (= (length (_Way . bv)) 2)) ;; bignum
              (write-long (ash (elt (_Way . bv) 0) 0) s)
              (write-long (ash (elt (_Way . bv) 1) -1) s))
             ((and (class _Way) (= (length (_Way . bv)) 1)) ;; big1
              (write-long (elt (_Way . bv) 0) s)
              (write-long (if (>= _Way 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _Way s)(write-long (if (>= _Way 0) 0 #xffffffff) s)))
     ;; int64 _start_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _start_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _start_x) (= (length (_start_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_start_x . bv) 0) 0) s)
              (write-long (ash (elt (_start_x . bv) 1) -1) s))
             ((and (class _start_x) (= (length (_start_x . bv)) 1)) ;; big1
              (write-long (elt (_start_x . bv) 0) s)
              (write-long (if (>= _start_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _start_x s)(write-long (if (>= _start_x 0) 0 #xffffffff) s)))
     ;; int64 _start_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _start_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _start_y) (= (length (_start_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_start_y . bv) 0) 0) s)
              (write-long (ash (elt (_start_y . bv) 1) -1) s))
             ((and (class _start_y) (= (length (_start_y . bv)) 1)) ;; big1
              (write-long (elt (_start_y . bv) 0) s)
              (write-long (if (>= _start_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _start_y s)(write-long (if (>= _start_y 0) 0 #xffffffff) s)))
     ;; int64 _goal_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _goal_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _goal_x) (= (length (_goal_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_goal_x . bv) 0) 0) s)
              (write-long (ash (elt (_goal_x . bv) 1) -1) s))
             ((and (class _goal_x) (= (length (_goal_x . bv)) 1)) ;; big1
              (write-long (elt (_goal_x . bv) 0) s)
              (write-long (if (>= _goal_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _goal_x s)(write-long (if (>= _goal_x 0) 0 #xffffffff) s)))
     ;; int64 _goal_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _goal_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _goal_y) (= (length (_goal_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_goal_y . bv) 0) 0) s)
              (write-long (ash (elt (_goal_y . bv) 1) -1) s))
             ((and (class _goal_y) (= (length (_goal_y . bv)) 1)) ;; big1
              (write-long (elt (_goal_y . bv) 0) s)
              (write-long (if (>= _goal_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _goal_y s)(write-long (if (>= _goal_y 0) 0 #xffffffff) s)))
     ;; int64 _direction
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _direction (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _direction) (= (length (_direction . bv)) 2)) ;; bignum
              (write-long (ash (elt (_direction . bv) 0) 0) s)
              (write-long (ash (elt (_direction . bv) 1) -1) s))
             ((and (class _direction) (= (length (_direction . bv)) 1)) ;; big1
              (write-long (elt (_direction . bv) 0) s)
              (write-long (if (>= _direction 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _direction s)(write-long (if (>= _direction 0) 0 #xffffffff) s)))
     ;; bool _recog_goal_x
       (if _recog_goal_x (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _Way
#+(or :alpha :irix6 :x86_64)
      (setf _Way (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _Way (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _start_x
#+(or :alpha :irix6 :x86_64)
      (setf _start_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _start_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _start_y
#+(or :alpha :irix6 :x86_64)
      (setf _start_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _start_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _goal_x
#+(or :alpha :irix6 :x86_64)
      (setf _goal_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _goal_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _goal_y
#+(or :alpha :irix6 :x86_64)
      (setf _goal_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _goal_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _direction
#+(or :alpha :irix6 :x86_64)
      (setf _direction (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _direction (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; bool _recog_goal_x
     (setq _recog_goal_x (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::Running_2020_vision :md5sum-) "4006f37f440c035b6febc61d2cd4ff1a")
(setf (get msg_generate::Running_2020_vision :datatype-) "msg_generate/Running_2020_vision")
(setf (get msg_generate::Running_2020_vision :definition-)
      "int64 Way
int64 start_x
int64 start_y
int64 goal_x
int64 goal_y
int64 direction
bool recog_goal_x

")



(provide :msg_generate/Running_2020_vision "4006f37f440c035b6febc61d2cd4ff1a")


