;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::master2localization23_technical_obstacle)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'master2localization23_technical_obstacle (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MASTER2LOCALIZATION23_TECHNICAL_OBSTACLE")
  (make-package "MSG_GENERATE::MASTER2LOCALIZATION23_TECHNICAL_OBSTACLE"))

(in-package "ROS")
;;//! \htmlinclude master2localization23_technical_obstacle.msg.html


(defclass msg_generate::master2localization23_technical_obstacle
  :super ros::object
  :slots (_sector _obs_1 _obs_2 ))

(defmethod msg_generate::master2localization23_technical_obstacle
  (:init
   (&key
    ((:sector __sector) 0)
    ((:obs_1 __obs_1) 0)
    ((:obs_2 __obs_2) 0)
    )
   (send-super :init)
   (setq _sector (round __sector))
   (setq _obs_1 (round __obs_1))
   (setq _obs_2 (round __obs_2))
   self)
  (:sector
   (&optional __sector)
   (if __sector (setq _sector __sector)) _sector)
  (:obs_1
   (&optional __obs_1)
   (if __obs_1 (setq _obs_1 __obs_1)) _obs_1)
  (:obs_2
   (&optional __obs_2)
   (if __obs_2 (setq _obs_2 __obs_2)) _obs_2)
  (:serialization-length
   ()
   (+
    ;; int64 _sector
    8
    ;; int64 _obs_1
    8
    ;; int64 _obs_2
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _sector
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _sector (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _sector) (= (length (_sector . bv)) 2)) ;; bignum
              (write-long (ash (elt (_sector . bv) 0) 0) s)
              (write-long (ash (elt (_sector . bv) 1) -1) s))
             ((and (class _sector) (= (length (_sector . bv)) 1)) ;; big1
              (write-long (elt (_sector . bv) 0) s)
              (write-long (if (>= _sector 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _sector s)(write-long (if (>= _sector 0) 0 #xffffffff) s)))
     ;; int64 _obs_1
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _obs_1 (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _obs_1) (= (length (_obs_1 . bv)) 2)) ;; bignum
              (write-long (ash (elt (_obs_1 . bv) 0) 0) s)
              (write-long (ash (elt (_obs_1 . bv) 1) -1) s))
             ((and (class _obs_1) (= (length (_obs_1 . bv)) 1)) ;; big1
              (write-long (elt (_obs_1 . bv) 0) s)
              (write-long (if (>= _obs_1 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _obs_1 s)(write-long (if (>= _obs_1 0) 0 #xffffffff) s)))
     ;; int64 _obs_2
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _obs_2 (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _obs_2) (= (length (_obs_2 . bv)) 2)) ;; bignum
              (write-long (ash (elt (_obs_2 . bv) 0) 0) s)
              (write-long (ash (elt (_obs_2 . bv) 1) -1) s))
             ((and (class _obs_2) (= (length (_obs_2 . bv)) 1)) ;; big1
              (write-long (elt (_obs_2 . bv) 0) s)
              (write-long (if (>= _obs_2 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _obs_2 s)(write-long (if (>= _obs_2 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _sector
#+(or :alpha :irix6 :x86_64)
      (setf _sector (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _sector (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _obs_1
#+(or :alpha :irix6 :x86_64)
      (setf _obs_1 (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _obs_1 (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _obs_2
#+(or :alpha :irix6 :x86_64)
      (setf _obs_2 (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _obs_2 (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::master2localization23_technical_obstacle :md5sum-) "84cbbda57e228d1e1a9085de32393705")
(setf (get msg_generate::master2localization23_technical_obstacle :datatype-) "msg_generate/master2localization23_technical_obstacle")
(setf (get msg_generate::master2localization23_technical_obstacle :definition-)
      "int64 sector
int64 obs_1
int64 obs_2


")



(provide :msg_generate/master2localization23_technical_obstacle "84cbbda57e228d1e1a9085de32393705")


