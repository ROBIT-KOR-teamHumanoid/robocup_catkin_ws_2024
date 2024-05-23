;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::game_control_return_data)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'game_control_return_data (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::GAME_CONTROL_RETURN_DATA")
  (make-package "MSG_GENERATE::GAME_CONTROL_RETURN_DATA"))

(in-package "ROS")
;;//! \htmlinclude game_control_return_data.msg.html


(defclass msg_generate::game_control_return_data
  :super ros::object
  :slots (_message ))

(defmethod msg_generate::game_control_return_data
  (:init
   (&key
    ((:message __message) 0)
    )
   (send-super :init)
   (setq _message (round __message))
   self)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; int64 _message
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _message
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _message (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _message) (= (length (_message . bv)) 2)) ;; bignum
              (write-long (ash (elt (_message . bv) 0) 0) s)
              (write-long (ash (elt (_message . bv) 1) -1) s))
             ((and (class _message) (= (length (_message . bv)) 1)) ;; big1
              (write-long (elt (_message . bv) 0) s)
              (write-long (if (>= _message 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _message s)(write-long (if (>= _message 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _message
#+(or :alpha :irix6 :x86_64)
      (setf _message (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _message (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::game_control_return_data :md5sum-) "9b8769cd592bd7dbe979986bd8cd4f43")
(setf (get msg_generate::game_control_return_data :datatype-) "msg_generate/game_control_return_data")
(setf (get msg_generate::game_control_return_data :definition-)
      "int64 message

")



(provide :msg_generate/game_control_return_data "9b8769cd592bd7dbe979986bd8cd4f43")


