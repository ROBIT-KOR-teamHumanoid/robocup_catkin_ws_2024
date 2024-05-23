;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::L_LC_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'L_LC_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::L_LC_MSG")
  (make-package "MSG_GENERATE::L_LC_MSG"))

(in-package "ROS")
;;//! \htmlinclude L_LC_msg.msg.html


(defclass msg_generate::L_LC_msg
  :super ros::object
  :slots (_L_LC_Data ))

(defmethod msg_generate::L_LC_msg
  (:init
   (&key
    ((:L_LC_Data __L_LC_Data) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _L_LC_Data __L_LC_Data)
   self)
  (:L_LC_Data
   (&optional __L_LC_Data)
   (if __L_LC_Data (setq _L_LC_Data __L_LC_Data)) _L_LC_Data)
  (:serialization-length
   ()
   (+
    ;; int32[] _L_LC_Data
    (* 4    (length _L_LC_Data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _L_LC_Data
     (write-long (length _L_LC_Data) s)
     (dotimes (i (length _L_LC_Data))
       (write-long (elt _L_LC_Data i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _L_LC_Data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _L_LC_Data (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _L_LC_Data i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get msg_generate::L_LC_msg :md5sum-) "4073ba7351186b3518f6130a0a0b94b2")
(setf (get msg_generate::L_LC_msg :datatype-) "msg_generate/L_LC_msg")
(setf (get msg_generate::L_LC_msg :definition-)
      "int32[] L_LC_Data

")



(provide :msg_generate/L_LC_msg "4073ba7351186b3518f6130a0a0b94b2")


