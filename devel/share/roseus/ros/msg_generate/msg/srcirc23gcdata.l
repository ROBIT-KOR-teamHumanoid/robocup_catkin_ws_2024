;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::srcirc23gcdata)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'srcirc23gcdata (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::SRCIRC23GCDATA")
  (make-package "MSG_GENERATE::SRCIRC23GCDATA"))

(in-package "ROS")
;;//! \htmlinclude srcirc23gcdata.msg.html


(defclass msg_generate::srcirc23gcdata
  :super ros::object
  :slots (_playnode _state _mode ))

(defmethod msg_generate::srcirc23gcdata
  (:init
   (&key
    ((:playnode __playnode) 0)
    ((:state __state) 0)
    ((:mode __mode) 0)
    )
   (send-super :init)
   (setq _playnode (round __playnode))
   (setq _state (round __state))
   (setq _mode (round __mode))
   self)
  (:playnode
   (&optional __playnode)
   (if __playnode (setq _playnode __playnode)) _playnode)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:serialization-length
   ()
   (+
    ;; int64 _playnode
    8
    ;; int64 _state
    8
    ;; int64 _mode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _playnode
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _playnode (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _playnode) (= (length (_playnode . bv)) 2)) ;; bignum
              (write-long (ash (elt (_playnode . bv) 0) 0) s)
              (write-long (ash (elt (_playnode . bv) 1) -1) s))
             ((and (class _playnode) (= (length (_playnode . bv)) 1)) ;; big1
              (write-long (elt (_playnode . bv) 0) s)
              (write-long (if (>= _playnode 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _playnode s)(write-long (if (>= _playnode 0) 0 #xffffffff) s)))
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
     ;; int64 _mode
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _mode (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _mode) (= (length (_mode . bv)) 2)) ;; bignum
              (write-long (ash (elt (_mode . bv) 0) 0) s)
              (write-long (ash (elt (_mode . bv) 1) -1) s))
             ((and (class _mode) (= (length (_mode . bv)) 1)) ;; big1
              (write-long (elt (_mode . bv) 0) s)
              (write-long (if (>= _mode 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _mode s)(write-long (if (>= _mode 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _playnode
#+(or :alpha :irix6 :x86_64)
      (setf _playnode (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _playnode (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;; int64 _mode
#+(or :alpha :irix6 :x86_64)
      (setf _mode (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _mode (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(setf (get msg_generate::srcirc23gcdata :md5sum-) "0086fc665a08f2de855db2ee3ec847f7")
(setf (get msg_generate::srcirc23gcdata :datatype-) "msg_generate/srcirc23gcdata")
(setf (get msg_generate::srcirc23gcdata :definition-)
      "int64 playnode
int64 state
int64 mode

")



(provide :msg_generate/srcirc23gcdata "0086fc665a08f2de855db2ee3ec847f7")


