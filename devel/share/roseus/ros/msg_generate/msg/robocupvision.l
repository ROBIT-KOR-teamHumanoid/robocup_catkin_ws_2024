;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::robocupvision)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'robocupvision (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::ROBOCUPVISION")
  (make-package "MSG_GENERATE::ROBOCUPVISION"))

(in-package "ROS")
;;//! \htmlinclude robocupvision.msg.html


(defclass msg_generate::robocupvision
  :super ros::object
  :slots (_ballX _ballY _ballDist _ballTheta ))

(defmethod msg_generate::robocupvision
  (:init
   (&key
    ((:ballX __ballX) 0)
    ((:ballY __ballY) 0)
    ((:ballDist __ballDist) 0)
    ((:ballTheta __ballTheta) 0.0)
    )
   (send-super :init)
   (setq _ballX (round __ballX))
   (setq _ballY (round __ballY))
   (setq _ballDist (round __ballDist))
   (setq _ballTheta (float __ballTheta))
   self)
  (:ballX
   (&optional __ballX)
   (if __ballX (setq _ballX __ballX)) _ballX)
  (:ballY
   (&optional __ballY)
   (if __ballY (setq _ballY __ballY)) _ballY)
  (:ballDist
   (&optional __ballDist)
   (if __ballDist (setq _ballDist __ballDist)) _ballDist)
  (:ballTheta
   (&optional __ballTheta)
   (if __ballTheta (setq _ballTheta __ballTheta)) _ballTheta)
  (:serialization-length
   ()
   (+
    ;; int64 _ballX
    8
    ;; int64 _ballY
    8
    ;; int64 _ballDist
    8
    ;; float64 _ballTheta
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _ballX
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballX (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballX) (= (length (_ballX . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballX . bv) 0) 0) s)
              (write-long (ash (elt (_ballX . bv) 1) -1) s))
             ((and (class _ballX) (= (length (_ballX . bv)) 1)) ;; big1
              (write-long (elt (_ballX . bv) 0) s)
              (write-long (if (>= _ballX 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballX s)(write-long (if (>= _ballX 0) 0 #xffffffff) s)))
     ;; int64 _ballY
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ballY (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ballY) (= (length (_ballY . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ballY . bv) 0) 0) s)
              (write-long (ash (elt (_ballY . bv) 1) -1) s))
             ((and (class _ballY) (= (length (_ballY . bv)) 1)) ;; big1
              (write-long (elt (_ballY . bv) 0) s)
              (write-long (if (>= _ballY 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ballY s)(write-long (if (>= _ballY 0) 0 #xffffffff) s)))
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
     ;; float64 _ballTheta
       (sys::poke _ballTheta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _ballX
#+(or :alpha :irix6 :x86_64)
      (setf _ballX (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballX (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _ballY
#+(or :alpha :irix6 :x86_64)
      (setf _ballY (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ballY (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;; float64 _ballTheta
     (setq _ballTheta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::robocupvision :md5sum-) "42c32a1bbbff9d4d2593036e1e947112")
(setf (get msg_generate::robocupvision :datatype-) "msg_generate/robocupvision")
(setf (get msg_generate::robocupvision :definition-)
      "int64 ballX
int64 ballY
int64 ballDist
float64 ballTheta


")



(provide :msg_generate/robocupvision "42c32a1bbbff9d4d2593036e1e947112")


