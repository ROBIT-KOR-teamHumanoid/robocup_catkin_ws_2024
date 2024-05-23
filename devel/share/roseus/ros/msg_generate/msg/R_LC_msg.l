;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::R_LC_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'R_LC_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::R_LC_MSG")
  (make-package "MSG_GENERATE::R_LC_MSG"))

(in-package "ROS")
;;//! \htmlinclude R_LC_msg.msg.html


(defclass msg_generate::R_LC_msg
  :super ros::object
  :slots (_R_LC_Data ))

(defmethod msg_generate::R_LC_msg
  (:init
   (&key
    ((:R_LC_Data __R_LC_Data) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _R_LC_Data __R_LC_Data)
   self)
  (:R_LC_Data
   (&optional __R_LC_Data)
   (if __R_LC_Data (setq _R_LC_Data __R_LC_Data)) _R_LC_Data)
  (:serialization-length
   ()
   (+
    ;; int32[] _R_LC_Data
    (* 4    (length _R_LC_Data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _R_LC_Data
     (write-long (length _R_LC_Data) s)
     (dotimes (i (length _R_LC_Data))
       (write-long (elt _R_LC_Data i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _R_LC_Data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _R_LC_Data (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _R_LC_Data i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get msg_generate::R_LC_msg :md5sum-) "1d93107f948628f0a69348074e2aa35d")
(setf (get msg_generate::R_LC_msg :datatype-) "msg_generate/R_LC_msg")
(setf (get msg_generate::R_LC_msg :definition-)
      "int32[] R_LC_Data

")



(provide :msg_generate/R_LC_msg "1d93107f948628f0a69348074e2aa35d")


