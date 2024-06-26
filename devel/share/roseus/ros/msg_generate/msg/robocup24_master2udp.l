;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::robocup24_master2udp)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'robocup24_master2udp (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ROBOCUP24_MASTER2UDP")
  (make-package "MSG_GENERATE::ROBOCUP24_MASTER2UDP"))

(in-package "ROS")
;;//! \htmlinclude robocup24_master2udp.msg.html


(defclass msg_generate::robocup24_master2udp
  :super ros::object
  :slots (_robot_num _robot_state _robot_coor_x _robot_coor_y _roboy_imu_yaw _ball_dist _ball_coor_x _ball_coor_y _myTeam ))

(defmethod msg_generate::robocup24_master2udp
  (:init
   (&key
    ((:robot_num __robot_num) 0)
    ((:robot_state __robot_state) 0)
    ((:robot_coor_x __robot_coor_x) 0)
    ((:robot_coor_y __robot_coor_y) 0)
    ((:roboy_imu_yaw __roboy_imu_yaw) 0)
    ((:ball_dist __ball_dist) 0)
    ((:ball_coor_x __ball_coor_x) 0)
    ((:ball_coor_y __ball_coor_y) 0)
    ((:myTeam __myTeam) 0)
    )
   (send-super :init)
   (setq _robot_num (round __robot_num))
   (setq _robot_state (round __robot_state))
   (setq _robot_coor_x (round __robot_coor_x))
   (setq _robot_coor_y (round __robot_coor_y))
   (setq _roboy_imu_yaw (round __roboy_imu_yaw))
   (setq _ball_dist (round __ball_dist))
   (setq _ball_coor_x (round __ball_coor_x))
   (setq _ball_coor_y (round __ball_coor_y))
   (setq _myTeam (round __myTeam))
   self)
  (:robot_num
   (&optional __robot_num)
   (if __robot_num (setq _robot_num __robot_num)) _robot_num)
  (:robot_state
   (&optional __robot_state)
   (if __robot_state (setq _robot_state __robot_state)) _robot_state)
  (:robot_coor_x
   (&optional __robot_coor_x)
   (if __robot_coor_x (setq _robot_coor_x __robot_coor_x)) _robot_coor_x)
  (:robot_coor_y
   (&optional __robot_coor_y)
   (if __robot_coor_y (setq _robot_coor_y __robot_coor_y)) _robot_coor_y)
  (:roboy_imu_yaw
   (&optional __roboy_imu_yaw)
   (if __roboy_imu_yaw (setq _roboy_imu_yaw __roboy_imu_yaw)) _roboy_imu_yaw)
  (:ball_dist
   (&optional __ball_dist)
   (if __ball_dist (setq _ball_dist __ball_dist)) _ball_dist)
  (:ball_coor_x
   (&optional __ball_coor_x)
   (if __ball_coor_x (setq _ball_coor_x __ball_coor_x)) _ball_coor_x)
  (:ball_coor_y
   (&optional __ball_coor_y)
   (if __ball_coor_y (setq _ball_coor_y __ball_coor_y)) _ball_coor_y)
  (:myTeam
   (&optional __myTeam)
   (if __myTeam (setq _myTeam __myTeam)) _myTeam)
  (:serialization-length
   ()
   (+
    ;; int64 _robot_num
    8
    ;; int64 _robot_state
    8
    ;; int64 _robot_coor_x
    8
    ;; int64 _robot_coor_y
    8
    ;; int64 _roboy_imu_yaw
    8
    ;; int64 _ball_dist
    8
    ;; int64 _ball_coor_x
    8
    ;; int64 _ball_coor_y
    8
    ;; int64 _myTeam
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
     ;; int64 _robot_state
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_state (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_state) (= (length (_robot_state . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_state . bv) 0) 0) s)
              (write-long (ash (elt (_robot_state . bv) 1) -1) s))
             ((and (class _robot_state) (= (length (_robot_state . bv)) 1)) ;; big1
              (write-long (elt (_robot_state . bv) 0) s)
              (write-long (if (>= _robot_state 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_state s)(write-long (if (>= _robot_state 0) 0 #xffffffff) s)))
     ;; int64 _robot_coor_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_coor_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_coor_x) (= (length (_robot_coor_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_coor_x . bv) 0) 0) s)
              (write-long (ash (elt (_robot_coor_x . bv) 1) -1) s))
             ((and (class _robot_coor_x) (= (length (_robot_coor_x . bv)) 1)) ;; big1
              (write-long (elt (_robot_coor_x . bv) 0) s)
              (write-long (if (>= _robot_coor_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_coor_x s)(write-long (if (>= _robot_coor_x 0) 0 #xffffffff) s)))
     ;; int64 _robot_coor_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_coor_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_coor_y) (= (length (_robot_coor_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_coor_y . bv) 0) 0) s)
              (write-long (ash (elt (_robot_coor_y . bv) 1) -1) s))
             ((and (class _robot_coor_y) (= (length (_robot_coor_y . bv)) 1)) ;; big1
              (write-long (elt (_robot_coor_y . bv) 0) s)
              (write-long (if (>= _robot_coor_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_coor_y s)(write-long (if (>= _robot_coor_y 0) 0 #xffffffff) s)))
     ;; int64 _roboy_imu_yaw
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _roboy_imu_yaw (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _roboy_imu_yaw) (= (length (_roboy_imu_yaw . bv)) 2)) ;; bignum
              (write-long (ash (elt (_roboy_imu_yaw . bv) 0) 0) s)
              (write-long (ash (elt (_roboy_imu_yaw . bv) 1) -1) s))
             ((and (class _roboy_imu_yaw) (= (length (_roboy_imu_yaw . bv)) 1)) ;; big1
              (write-long (elt (_roboy_imu_yaw . bv) 0) s)
              (write-long (if (>= _roboy_imu_yaw 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _roboy_imu_yaw s)(write-long (if (>= _roboy_imu_yaw 0) 0 #xffffffff) s)))
     ;; int64 _ball_dist
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_dist (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_dist) (= (length (_ball_dist . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_dist . bv) 0) 0) s)
              (write-long (ash (elt (_ball_dist . bv) 1) -1) s))
             ((and (class _ball_dist) (= (length (_ball_dist . bv)) 1)) ;; big1
              (write-long (elt (_ball_dist . bv) 0) s)
              (write-long (if (>= _ball_dist 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_dist s)(write-long (if (>= _ball_dist 0) 0 #xffffffff) s)))
     ;; int64 _ball_coor_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_coor_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_coor_x) (= (length (_ball_coor_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_coor_x . bv) 0) 0) s)
              (write-long (ash (elt (_ball_coor_x . bv) 1) -1) s))
             ((and (class _ball_coor_x) (= (length (_ball_coor_x . bv)) 1)) ;; big1
              (write-long (elt (_ball_coor_x . bv) 0) s)
              (write-long (if (>= _ball_coor_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_coor_x s)(write-long (if (>= _ball_coor_x 0) 0 #xffffffff) s)))
     ;; int64 _ball_coor_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_coor_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_coor_y) (= (length (_ball_coor_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_coor_y . bv) 0) 0) s)
              (write-long (ash (elt (_ball_coor_y . bv) 1) -1) s))
             ((and (class _ball_coor_y) (= (length (_ball_coor_y . bv)) 1)) ;; big1
              (write-long (elt (_ball_coor_y . bv) 0) s)
              (write-long (if (>= _ball_coor_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_coor_y s)(write-long (if (>= _ball_coor_y 0) 0 #xffffffff) s)))
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
   ;; int64 _robot_state
#+(or :alpha :irix6 :x86_64)
      (setf _robot_state (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_state (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_coor_x
#+(or :alpha :irix6 :x86_64)
      (setf _robot_coor_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_coor_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_coor_y
#+(or :alpha :irix6 :x86_64)
      (setf _robot_coor_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_coor_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _roboy_imu_yaw
#+(or :alpha :irix6 :x86_64)
      (setf _roboy_imu_yaw (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _roboy_imu_yaw (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_dist
#+(or :alpha :irix6 :x86_64)
      (setf _ball_dist (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_dist (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_coor_x
#+(or :alpha :irix6 :x86_64)
      (setf _ball_coor_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_coor_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_coor_y
#+(or :alpha :irix6 :x86_64)
      (setf _ball_coor_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_coor_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;;
   self)
  )

(setf (get msg_generate::robocup24_master2udp :md5sum-) "c362ddeab15e7aaf6c2da6140bdfe915")
(setf (get msg_generate::robocup24_master2udp :datatype-) "msg_generate/robocup24_master2udp")
(setf (get msg_generate::robocup24_master2udp :definition-)
      "int64 robot_num
int64 robot_state
int64 robot_coor_x
int64 robot_coor_y
int64 roboy_imu_yaw
int64 ball_dist
int64 ball_coor_x
int64 ball_coor_y
int64 myTeam

")



(provide :msg_generate/robocup24_master2udp "c362ddeab15e7aaf6c2da6140bdfe915")


