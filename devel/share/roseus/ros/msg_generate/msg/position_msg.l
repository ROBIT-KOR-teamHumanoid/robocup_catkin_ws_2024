;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::position_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'position_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::POSITION_MSG")
  (make-package "MSG_GENERATE::POSITION_MSG"))

(in-package "ROS")
;;//! \htmlinclude position_msg.msg.html


(defclass msg_generate::position_msg
  :super ros::object
  :slots (_robot_area _ball_area _yaw ))

(defmethod msg_generate::position_msg
  (:init
   (&key
    ((:robot_area __robot_area) 0)
    ((:ball_area __ball_area) 0)
    ((:yaw __yaw) 0)
    )
   (send-super :init)
   (setq _robot_area (round __robot_area))
   (setq _ball_area (round __ball_area))
   (setq _yaw (round __yaw))
   self)
  (:robot_area
   (&optional __robot_area)
   (if __robot_area (setq _robot_area __robot_area)) _robot_area)
  (:ball_area
   (&optional __ball_area)
   (if __ball_area (setq _ball_area __ball_area)) _ball_area)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; int64 _robot_area
    8
    ;; int64 _ball_area
    8
    ;; int64 _yaw
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _robot_area
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _robot_area (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _robot_area) (= (length (_robot_area . bv)) 2)) ;; bignum
              (write-long (ash (elt (_robot_area . bv) 0) 0) s)
              (write-long (ash (elt (_robot_area . bv) 1) -1) s))
             ((and (class _robot_area) (= (length (_robot_area . bv)) 1)) ;; big1
              (write-long (elt (_robot_area . bv) 0) s)
              (write-long (if (>= _robot_area 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _robot_area s)(write-long (if (>= _robot_area 0) 0 #xffffffff) s)))
     ;; int64 _ball_area
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ball_area (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ball_area) (= (length (_ball_area . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ball_area . bv) 0) 0) s)
              (write-long (ash (elt (_ball_area . bv) 1) -1) s))
             ((and (class _ball_area) (= (length (_ball_area . bv)) 1)) ;; big1
              (write-long (elt (_ball_area . bv) 0) s)
              (write-long (if (>= _ball_area 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ball_area s)(write-long (if (>= _ball_area 0) 0 #xffffffff) s)))
     ;; int64 _yaw
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _yaw (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _yaw) (= (length (_yaw . bv)) 2)) ;; bignum
              (write-long (ash (elt (_yaw . bv) 0) 0) s)
              (write-long (ash (elt (_yaw . bv) 1) -1) s))
             ((and (class _yaw) (= (length (_yaw . bv)) 1)) ;; big1
              (write-long (elt (_yaw . bv) 0) s)
              (write-long (if (>= _yaw 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _yaw s)(write-long (if (>= _yaw 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _robot_area
#+(or :alpha :irix6 :x86_64)
      (setf _robot_area (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _robot_area (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ball_area
#+(or :alpha :irix6 :x86_64)
      (setf _ball_area (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ball_area (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _yaw
#+(or :alpha :irix6 :x86_64)
      (setf _yaw (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _yaw (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::position_msg :md5sum-) "592ace443c869809edf4b9d783f51103")
(setf (get msg_generate::position_msg :datatype-) "msg_generate/position_msg")
(setf (get msg_generate::position_msg :definition-)
      "int64 robot_area
int64 ball_area
int64 yaw


")



(provide :msg_generate/position_msg "592ace443c869809edf4b9d783f51103")


