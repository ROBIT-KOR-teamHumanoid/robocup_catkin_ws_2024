;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::master2localization24)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'master2localization24 (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MASTER2LOCALIZATION24")
  (make-package "MSG_GENERATE::MASTER2LOCALIZATION24"))

(in-package "ROS")
;;//! \htmlinclude master2localization24.msg.html


(defclass msg_generate::master2localization24
  :super ros::object
  :slots (_goal_x _goal_y _target_x _target_y _robot_allowance_error _robot_cali_radius ))

(defmethod msg_generate::master2localization24
  (:init
   (&key
    ((:goal_x __goal_x) 0)
    ((:goal_y __goal_y) 0)
    ((:target_x __target_x) 0)
    ((:target_y __target_y) 0)
    ((:robot_allowance_error __robot_allowance_error) 0)
    ((:robot_cali_radius __robot_cali_radius) 0)
    )
   (send-super :init)
   (setq _goal_x (round __goal_x))
   (setq _goal_y (round __goal_y))
   (setq _target_x (round __target_x))
   (setq _target_y (round __target_y))
   (setq _robot_allowance_error (round __robot_allowance_error))
   (setq _robot_cali_radius (round __robot_cali_radius))
   self)
  (:goal_x
   (&optional __goal_x)
   (if __goal_x (setq _goal_x __goal_x)) _goal_x)
  (:goal_y
   (&optional __goal_y)
   (if __goal_y (setq _goal_y __goal_y)) _goal_y)
  (:target_x
   (&optional __target_x)
   (if __target_x (setq _target_x __target_x)) _target_x)
  (:target_y
   (&optional __target_y)
   (if __target_y (setq _target_y __target_y)) _target_y)
  (:robot_allowance_error
   (&optional __robot_allowance_error)
   (if __robot_allowance_error (setq _robot_allowance_error __robot_allowance_error)) _robot_allowance_error)
  (:robot_cali_radius
   (&optional __robot_cali_radius)
   (if __robot_cali_radius (setq _robot_cali_radius __robot_cali_radius)) _robot_cali_radius)
  (:serialization-length
   ()
   (+
    ;; int64 _goal_x
    8
    ;; int64 _goal_y
    8
    ;; int64 _target_x
    8
    ;; int64 _target_y
    8
    ;; int64 _robot_allowance_error
    8
    ;; int64 _robot_cali_radius
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
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
     ;; int64 _target_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _target_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _target_x) (= (length (_target_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_target_x . bv) 0) 0) s)
              (write-long (ash (elt (_target_x . bv) 1) -1) s))
             ((and (class _target_x) (= (length (_target_x . bv)) 1)) ;; big1
              (write-long (elt (_target_x . bv) 0) s)
              (write-long (if (>= _target_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _target_x s)(write-long (if (>= _target_x 0) 0 #xffffffff) s)))
     ;; int64 _target_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _target_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _target_y) (= (length (_target_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_target_y . bv) 0) 0) s)
              (write-long (ash (elt (_target_y . bv) 1) -1) s))
             ((and (class _target_y) (= (length (_target_y . bv)) 1)) ;; big1
              (write-long (elt (_target_y . bv) 0) s)
              (write-long (if (>= _target_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _target_y s)(write-long (if (>= _target_y 0) 0 #xffffffff) s)))
     ;; int64 _robot_allowance_error
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_allowance_error (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_allowance_error) (= (length (_robot_allowance_error . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_allowance_error . bv) 0) 0) s)
              (write-long (ash (elt (_robot_allowance_error . bv) 1) -1) s))
             ((and (class _robot_allowance_error) (= (length (_robot_allowance_error . bv)) 1)) ;; big1
              (write-long (elt (_robot_allowance_error . bv) 0) s)
              (write-long (if (>= _robot_allowance_error 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_allowance_error s)(write-long (if (>= _robot_allowance_error 0) 0 #xffffffff) s)))
     ;; int64 _robot_cali_radius
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_cali_radius (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_cali_radius) (= (length (_robot_cali_radius . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_cali_radius . bv) 0) 0) s)
              (write-long (ash (elt (_robot_cali_radius . bv) 1) -1) s))
             ((and (class _robot_cali_radius) (= (length (_robot_cali_radius . bv)) 1)) ;; big1
              (write-long (elt (_robot_cali_radius . bv) 0) s)
              (write-long (if (>= _robot_cali_radius 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_cali_radius s)(write-long (if (>= _robot_cali_radius 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
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
   ;; int64 _target_x
#+(or :alpha :irix6 :x86_64)
      (setf _target_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _target_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _target_y
#+(or :alpha :irix6 :x86_64)
      (setf _target_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _target_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_allowance_error
#+(or :alpha :irix6 :x86_64)
      (setf _robot_allowance_error (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_allowance_error (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _robot_cali_radius
#+(or :alpha :irix6 :x86_64)
      (setf _robot_cali_radius (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_cali_radius (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::master2localization24 :md5sum-) "327d5f269dd6e3ee84371d4f5cf9b95e")
(setf (get msg_generate::master2localization24 :datatype-) "msg_generate/master2localization24")
(setf (get msg_generate::master2localization24 :definition-)
      "int64 goal_x
int64 goal_y
int64 target_x
int64 target_y
int64 robot_allowance_error
int64 robot_cali_radius


")



(provide :msg_generate/master2localization24 "327d5f269dd6e3ee84371d4f5cf9b95e")


