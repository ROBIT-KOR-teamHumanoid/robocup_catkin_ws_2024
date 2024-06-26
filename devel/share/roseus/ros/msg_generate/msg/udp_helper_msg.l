;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::udp_helper_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'udp_helper_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::UDP_HELPER_MSG")
  (make-package "MSG_GENERATE::UDP_HELPER_MSG"))

(in-package "ROS")
;;//! \htmlinclude udp_helper_msg.msg.html


(defclass msg_generate::udp_helper_msg
  :super ros::object
  :slots (_robot_num _robot_case _robot_x_order _robot_y_order _robot_ik_x_order _robot_ik_y_order _robot_ik_yaw_order _ball_x _ball_y _ballDist _ballTheta ))

(defmethod msg_generate::udp_helper_msg
  (:init
   (&key
    ((:robot_num __robot_num) 0)
    ((:robot_case __robot_case) 0)
    ((:robot_x_order __robot_x_order) 0)
    ((:robot_y_order __robot_y_order) 0)
    ((:robot_ik_x_order __robot_ik_x_order) 0)
    ((:robot_ik_y_order __robot_ik_y_order) 0)
    ((:robot_ik_yaw_order __robot_ik_yaw_order) 0)
    ((:ball_x __ball_x) 0)
    ((:ball_y __ball_y) 0)
    ((:ballDist __ballDist) 0)
    ((:ballTheta __ballTheta) 0)
    )
   (send-super :init)
   (setq _robot_num (round __robot_num))
   (setq _robot_case (round __robot_case))
   (setq _robot_x_order (round __robot_x_order))
   (setq _robot_y_order (round __robot_y_order))
   (setq _robot_ik_x_order (round __robot_ik_x_order))
   (setq _robot_ik_y_order (round __robot_ik_y_order))
   (setq _robot_ik_yaw_order (round __robot_ik_yaw_order))
   (setq _ball_x (round __ball_x))
   (setq _ball_y (round __ball_y))
   (setq _ballDist (round __ballDist))
   (setq _ballTheta (round __ballTheta))
   self)
  (:robot_num
   (&optional __robot_num)
   (if __robot_num (setq _robot_num __robot_num)) _robot_num)
  (:robot_case
   (&optional __robot_case)
   (if __robot_case (setq _robot_case __robot_case)) _robot_case)
  (:robot_x_order
   (&optional __robot_x_order)
   (if __robot_x_order (setq _robot_x_order __robot_x_order)) _robot_x_order)
  (:robot_y_order
   (&optional __robot_y_order)
   (if __robot_y_order (setq _robot_y_order __robot_y_order)) _robot_y_order)
  (:robot_ik_x_order
   (&optional __robot_ik_x_order)
   (if __robot_ik_x_order (setq _robot_ik_x_order __robot_ik_x_order)) _robot_ik_x_order)
  (:robot_ik_y_order
   (&optional __robot_ik_y_order)
   (if __robot_ik_y_order (setq _robot_ik_y_order __robot_ik_y_order)) _robot_ik_y_order)
  (:robot_ik_yaw_order
   (&optional __robot_ik_yaw_order)
   (if __robot_ik_yaw_order (setq _robot_ik_yaw_order __robot_ik_yaw_order)) _robot_ik_yaw_order)
  (:ball_x
   (&optional __ball_x)
   (if __ball_x (setq _ball_x __ball_x)) _ball_x)
  (:ball_y
   (&optional __ball_y)
   (if __ball_y (setq _ball_y __ball_y)) _ball_y)
  (:ballDist
   (&optional __ballDist)
   (if __ballDist (setq _ballDist __ballDist)) _ballDist)
  (:ballTheta
   (&optional __ballTheta)
   (if __ballTheta (setq _ballTheta __ballTheta)) _ballTheta)
  (:serialization-length
   ()
   (+
    ;; int64 _robot_num
    8
    ;; int64 _robot_case
    8
    ;; int64 _robot_x_order
    8
    ;; int64 _robot_y_order
    8
    ;; int64 _robot_ik_x_order
    8
    ;; int64 _robot_ik_y_order
    8
    ;; int64 _robot_ik_yaw_order
    8
    ;; int64 _ball_x
    8
    ;; int64 _ball_y
    8
    ;; int64 _ballDist
    8
    ;; int64 _ballTheta
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _robot_num
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_num (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_num) (= (length (_robot_num . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_num . bv) 0) 0) s)
              (write-long (ash (elt (_robot_num . bv) 1) -1) s))
             ((and (class _robot_num) (= (length (_robot_num . bv)) 1)) ;; big1
              (write-long (elt (_robot_num . bv) 0) s)
              (write-long (if (>= _robot_num 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_num s)(write-long (if (>= _robot_num 0) 0 #xffffffff) s)))
     ;; int64 _robot_case
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_case (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_case) (= (length (_robot_case . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_case . bv) 0) 0) s)
              (write-long (ash (elt (_robot_case . bv) 1) -1) s))
             ((and (class _robot_case) (= (length (_robot_case . bv)) 1)) ;; big1
              (write-long (elt (_robot_case . bv) 0) s)
              (write-long (if (>= _robot_case 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_case s)(write-long (if (>= _robot_case 0) 0 #xffffffff) s)))
     ;; int64 _robot_x_order
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_x_order (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_x_order) (= (length (_robot_x_order . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_x_order . bv) 0) 0) s)
              (write-long (ash (elt (_robot_x_order . bv) 1) -1) s))
             ((and (class _robot_x_order) (= (length (_robot_x_order . bv)) 1)) ;; big1
              (write-long (elt (_robot_x_order . bv) 0) s)
              (write-long (if (>= _robot_x_order 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_x_order s)(write-long (if (>= _robot_x_order 0) 0 #xffffffff) s)))
     ;; int64 _robot_y_order
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_y_order (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_y_order) (= (length (_robot_y_order . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_y_order . bv) 0) 0) s)
              (write-long (ash (elt (_robot_y_order . bv) 1) -1) s))
             ((and (class _robot_y_order) (= (length (_robot_y_order . bv)) 1)) ;; big1
              (write-long (elt (_robot_y_order . bv) 0) s)
              (write-long (if (>= _robot_y_order 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_y_order s)(write-long (if (>= _robot_y_order 0) 0 #xffffffff) s)))
     ;; int64 _robot_ik_x_order
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_ik_x_order (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_ik_x_order) (= (length (_robot_ik_x_order . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_ik_x_order . bv) 0) 0) s)
              (write-long (ash (elt (_robot_ik_x_order . bv) 1) -1) s))
             ((and (class _robot_ik_x_order) (= (length (_robot_ik_x_order . bv)) 1)) ;; big1
              (write-long (elt (_robot_ik_x_order . bv) 0) s)
              (write-long (if (>= _robot_ik_x_order 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_ik_x_order s)(write-long (if (>= _robot_ik_x_order 0) 0 #xffffffff) s)))
     ;; int64 _robot_ik_y_order
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_ik_y_order (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_ik_y_order) (= (length (_robot_ik_y_order . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_ik_y_order . bv) 0) 0) s)
              (write-long (ash (elt (_robot_ik_y_order . bv) 1) -1) s))
             ((and (class _robot_ik_y_order) (= (length (_robot_ik_y_order . bv)) 1)) ;; big1
              (write-long (elt (_robot_ik_y_order . bv) 0) s)
              (write-long (if (>= _robot_ik_y_order 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_ik_y_order s)(write-long (if (>= _robot_ik_y_order 0) 0 #xffffffff) s)))
     ;; int64 _robot_ik_yaw_order
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_ik_yaw_order (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_ik_yaw_order) (= (length (_robot_ik_yaw_order . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_ik_yaw_order . bv) 0) 0) s)
              (write-long (ash (elt (_robot_ik_yaw_order . bv) 1) -1) s))
             ((and (class _robot_ik_yaw_order) (= (length (_robot_ik_yaw_order . bv)) 1)) ;; big1
              (write-long (elt (_robot_ik_yaw_order . bv) 0) s)
              (write-long (if (>= _robot_ik_yaw_order 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_ik_yaw_order s)(write-long (if (>= _robot_ik_yaw_order 0) 0 #xffffffff) s)))
     ;; int64 _ball_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_x) (= (length (_ball_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_x . bv) 0) 0) s)
              (write-long (ash (elt (_ball_x . bv) 1) -1) s))
             ((and (class _ball_x) (= (length (_ball_x . bv)) 1)) ;; big1
              (write-long (elt (_ball_x . bv) 0) s)
              (write-long (if (>= _ball_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_x s)(write-long (if (>= _ball_x 0) 0 #xffffffff) s)))
     ;; int64 _ball_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_y) (= (length (_ball_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_y . bv) 0) 0) s)
              (write-long (ash (elt (_ball_y . bv) 1) -1) s))
             ((and (class _ball_y) (= (length (_ball_y . bv)) 1)) ;; big1
              (write-long (elt (_ball_y . bv) 0) s)
              (write-long (if (>= _ball_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_y s)(write-long (if (>= _ball_y 0) 0 #xffffffff) s)))
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
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _robot_num
#+(or :alpha :irix6 :x86_64)
      (setf _robot_num (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_num (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_case
#+(or :alpha :irix6 :x86_64)
      (setf _robot_case (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_case (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_x_order
#+(or :alpha :irix6 :x86_64)
      (setf _robot_x_order (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_x_order (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_y_order
#+(or :alpha :irix6 :x86_64)
      (setf _robot_y_order (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_y_order (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_ik_x_order
#+(or :alpha :irix6 :x86_64)
      (setf _robot_ik_x_order (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_ik_x_order (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_ik_y_order
#+(or :alpha :irix6 :x86_64)
      (setf _robot_ik_y_order (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_ik_y_order (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_ik_yaw_order
#+(or :alpha :irix6 :x86_64)
      (setf _robot_ik_yaw_order (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_ik_yaw_order (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_x
#+(or :alpha :irix6 :x86_64)
      (setf _ball_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_y
#+(or :alpha :irix6 :x86_64)
      (setf _ball_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;;
   self)
  )

(setf (get msg_generate::udp_helper_msg :md5sum-) "6961c7de19af71cbd4139ee3940f46a0")
(setf (get msg_generate::udp_helper_msg :datatype-) "msg_generate/udp_helper_msg")
(setf (get msg_generate::udp_helper_msg :definition-)
      "int64 robot_num
int64 robot_case

int64 robot_x_order
int64 robot_y_order 

int64 robot_ik_x_order
int64 robot_ik_y_order
int64 robot_ik_yaw_order

int64 ball_x
int64 ball_y
int64 ballDist
int64 ballTheta

")



(provide :msg_generate/udp_helper_msg "6961c7de19af71cbd4139ee3940f46a0")


