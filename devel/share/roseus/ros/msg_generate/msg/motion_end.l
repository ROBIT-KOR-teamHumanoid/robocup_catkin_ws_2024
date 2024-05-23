;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::motion_end)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'motion_end (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MOTION_END")
  (make-package "MSG_GENERATE::MOTION_END"))

(in-package "ROS")
;;//! \htmlinclude motion_end.msg.html


(defclass msg_generate::motion_end
  :super ros::object
  :slots (_motion_end _motion_ing _motion_start_ing _motion_end_ing _motion_num ))

(defmethod msg_generate::motion_end
  (:init
   (&key
    ((:motion_end __motion_end) 0)
    ((:motion_ing __motion_ing) 0)
    ((:motion_start_ing __motion_start_ing) 0)
    ((:motion_end_ing __motion_end_ing) 0)
    ((:motion_num __motion_num) 0)
    )
   (send-super :init)
   (setq _motion_end (round __motion_end))
   (setq _motion_ing (round __motion_ing))
   (setq _motion_start_ing (round __motion_start_ing))
   (setq _motion_end_ing (round __motion_end_ing))
   (setq _motion_num (round __motion_num))
   self)
  (:motion_end
   (&optional __motion_end)
   (if __motion_end (setq _motion_end __motion_end)) _motion_end)
  (:motion_ing
   (&optional __motion_ing)
   (if __motion_ing (setq _motion_ing __motion_ing)) _motion_ing)
  (:motion_start_ing
   (&optional __motion_start_ing)
   (if __motion_start_ing (setq _motion_start_ing __motion_start_ing)) _motion_start_ing)
  (:motion_end_ing
   (&optional __motion_end_ing)
   (if __motion_end_ing (setq _motion_end_ing __motion_end_ing)) _motion_end_ing)
  (:motion_num
   (&optional __motion_num)
   (if __motion_num (setq _motion_num __motion_num)) _motion_num)
  (:serialization-length
   ()
   (+
    ;; int32 _motion_end
    4
    ;; int32 _motion_ing
    4
    ;; int32 _motion_start_ing
    4
    ;; int32 _motion_end_ing
    4
    ;; int32 _motion_num
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _motion_end
       (write-long _motion_end s)
     ;; int32 _motion_ing
       (write-long _motion_ing s)
     ;; int32 _motion_start_ing
       (write-long _motion_start_ing s)
     ;; int32 _motion_end_ing
       (write-long _motion_end_ing s)
     ;; int32 _motion_num
       (write-long _motion_num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _motion_end
     (setq _motion_end (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _motion_ing
     (setq _motion_ing (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _motion_start_ing
     (setq _motion_start_ing (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _motion_end_ing
     (setq _motion_end_ing (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _motion_num
     (setq _motion_num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_generate::motion_end :md5sum-) "25f699e9aaf9930abdbe2aaa9b5b0063")
(setf (get msg_generate::motion_end :datatype-) "msg_generate/motion_end")
(setf (get msg_generate::motion_end :definition-)
      "int32 motion_end
int32 motion_ing
int32 motion_start_ing
int32 motion_end_ing

int32 motion_num


")



(provide :msg_generate/motion_end "25f699e9aaf9930abdbe2aaa9b5b0063")


