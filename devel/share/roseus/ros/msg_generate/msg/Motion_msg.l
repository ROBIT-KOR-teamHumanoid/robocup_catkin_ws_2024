;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Motion_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Motion_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MOTION_MSG")
  (make-package "MSG_GENERATE::MOTION_MSG"))

(in-package "ROS")
;;//! \htmlinclude Motion_msg.msg.html


(defclass msg_generate::Motion_msg
  :super ros::object
  :slots (_max_step _repeat _acc _motion_data ))

(defmethod msg_generate::Motion_msg
  (:init
   (&key
    ((:max_step __max_step) 0)
    ((:repeat __repeat) 0)
    ((:acc __acc) 0)
    ((:motion_data __motion_data) (let (r) (dotimes (i 0) (push (instance msg_generate::Step_msg :init) r)) r))
    )
   (send-super :init)
   (setq _max_step (round __max_step))
   (setq _repeat (round __repeat))
   (setq _acc (round __acc))
   (setq _motion_data __motion_data)
   self)
  (:max_step
   (&optional __max_step)
   (if __max_step (setq _max_step __max_step)) _max_step)
  (:repeat
   (&optional __repeat)
   (if __repeat (setq _repeat __repeat)) _repeat)
  (:acc
   (&optional __acc)
   (if __acc (setq _acc __acc)) _acc)
  (:motion_data
   (&rest __motion_data)
   (if (keywordp (car __motion_data))
       (send* _motion_data __motion_data)
     (progn
       (if __motion_data (setq _motion_data (car __motion_data)))
       _motion_data)))
  (:serialization-length
   ()
   (+
    ;; uint32 _max_step
    4
    ;; uint32 _repeat
    4
    ;; uint32 _acc
    4
    ;; msg_generate/Step_msg[] _motion_data
    (apply #'+ (send-all _motion_data :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _max_step
       (write-long _max_step s)
     ;; uint32 _repeat
       (write-long _repeat s)
     ;; uint32 _acc
       (write-long _acc s)
     ;; msg_generate/Step_msg[] _motion_data
     (write-long (length _motion_data) s)
     (dolist (elem _motion_data)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _max_step
     (setq _max_step (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _repeat
     (setq _repeat (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _acc
     (setq _acc (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; msg_generate/Step_msg[] _motion_data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motion_data (let (r) (dotimes (i n) (push (instance msg_generate::Step_msg :init) r)) r))
     (dolist (elem- _motion_data)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get msg_generate::Motion_msg :md5sum-) "fbcb902fe8f910d4d1cd05b17d5ee522")
(setf (get msg_generate::Motion_msg :datatype-) "msg_generate/Motion_msg")
(setf (get msg_generate::Motion_msg :definition-)
      "uint32 max_step
uint32 repeat
uint32 acc
Step_msg[] motion_data

================================================================================
MSG: msg_generate/Step_msg
int32 delay
int32 time
int32[] id
int32[] position



")



(provide :msg_generate/Motion_msg "fbcb902fe8f910d4d1cd05b17d5ee522")


