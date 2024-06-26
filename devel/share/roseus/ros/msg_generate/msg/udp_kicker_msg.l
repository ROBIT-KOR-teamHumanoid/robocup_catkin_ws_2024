;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::udp_kicker_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'udp_kicker_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::UDP_KICKER_MSG")
  (make-package "MSG_GENERATE::UDP_KICKER_MSG"))

(in-package "ROS")
;;//! \htmlinclude udp_kicker_msg.msg.html


(defclass msg_generate::udp_kicker_msg
  :super ros::object
  :slots (_robot_num _robot_case _local_x _local_y _local_yaw ))

(defmethod msg_generate::udp_kicker_msg
  (:init
   (&key
    ((:robot_num __robot_num) 0)
    ((:robot_case __robot_case) 0)
    ((:local_x __local_x) 0)
    ((:local_y __local_y) 0)
    ((:local_yaw __local_yaw) 0)
    )
   (send-super :init)
   (setq _robot_num (round __robot_num))
   (setq _robot_case (round __robot_case))
   (setq _local_x (round __local_x))
   (setq _local_y (round __local_y))
   (setq _local_yaw (round __local_yaw))
   self)
  (:robot_num
   (&optional __robot_num)
   (if __robot_num (setq _robot_num __robot_num)) _robot_num)
  (:robot_case
   (&optional __robot_case)
   (if __robot_case (setq _robot_case __robot_case)) _robot_case)
  (:local_x
   (&optional __local_x)
   (if __local_x (setq _local_x __local_x)) _local_x)
  (:local_y
   (&optional __local_y)
   (if __local_y (setq _local_y __local_y)) _local_y)
  (:local_yaw
   (&optional __local_yaw)
   (if __local_yaw (setq _local_yaw __local_yaw)) _local_yaw)
  (:serialization-length
   ()
   (+
    ;; int64 _robot_num
    8
    ;; int64 _robot_case
    8
    ;; int64 _local_x
    8
    ;; int64 _local_y
    8
    ;; int64 _local_yaw
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
     ;; int64 _local_x
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _local_x (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _local_x) (= (length (_local_x . bv)) 2)) ;; bignum
              (write-long (ash (elt (_local_x . bv) 0) 0) s)
              (write-long (ash (elt (_local_x . bv) 1) -1) s))
             ((and (class _local_x) (= (length (_local_x . bv)) 1)) ;; big1
              (write-long (elt (_local_x . bv) 0) s)
              (write-long (if (>= _local_x 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _local_x s)(write-long (if (>= _local_x 0) 0 #xffffffff) s)))
     ;; int64 _local_y
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _local_y (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _local_y) (= (length (_local_y . bv)) 2)) ;; bignum
              (write-long (ash (elt (_local_y . bv) 0) 0) s)
              (write-long (ash (elt (_local_y . bv) 1) -1) s))
             ((and (class _local_y) (= (length (_local_y . bv)) 1)) ;; big1
              (write-long (elt (_local_y . bv) 0) s)
              (write-long (if (>= _local_y 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _local_y s)(write-long (if (>= _local_y 0) 0 #xffffffff) s)))
     ;; int64 _local_yaw
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _local_yaw (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _local_yaw) (= (length (_local_yaw . bv)) 2)) ;; bignum
              (write-long (ash (elt (_local_yaw . bv) 0) 0) s)
              (write-long (ash (elt (_local_yaw . bv) 1) -1) s))
             ((and (class _local_yaw) (= (length (_local_yaw . bv)) 1)) ;; big1
              (write-long (elt (_local_yaw . bv) 0) s)
              (write-long (if (>= _local_yaw 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _local_yaw s)(write-long (if (>= _local_yaw 0) 0 #xffffffff) s)))
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
   ;; int64 _local_x
#+(or :alpha :irix6 :x86_64)
      (setf _local_x (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _local_x (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _local_y
#+(or :alpha :irix6 :x86_64)
      (setf _local_y (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _local_y (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _local_yaw
#+(or :alpha :irix6 :x86_64)
      (setf _local_yaw (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _local_yaw (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::udp_kicker_msg :md5sum-) "4f5ba7b091b51220f871e749e172c551")
(setf (get msg_generate::udp_kicker_msg :datatype-) "msg_generate/udp_kicker_msg")
(setf (get msg_generate::udp_kicker_msg :definition-)
      "int64 robot_num
int64 robot_case

int64 local_x
int64 local_y 
int64 local_yaw

")



(provide :msg_generate/udp_kicker_msg "4f5ba7b091b51220f871e749e172c551")


