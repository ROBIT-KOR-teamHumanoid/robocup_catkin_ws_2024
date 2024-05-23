;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Local_Info)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Local_Info (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::LOCAL_INFO")
  (make-package "MSG_GENERATE::LOCAL_INFO"))

(in-package "ROS")
;;//! \htmlinclude Local_Info.msg.html


(defclass msg_generate::Local_Info
  :super ros::object
  :slots (_featureData ))

(defmethod msg_generate::Local_Info
  (:init
   (&key
    ((:featureData __featureData) (let (r) (dotimes (i 0) (push (instance msg_generate::Local_msg :init) r)) r))
    )
   (send-super :init)
   (setq _featureData __featureData)
   self)
  (:featureData
   (&rest __featureData)
   (if (keywordp (car __featureData))
       (send* _featureData __featureData)
     (progn
       (if __featureData (setq _featureData (car __featureData)))
       _featureData)))
  (:serialization-length
   ()
   (+
    ;; msg_generate/Local_msg[] _featureData
    (apply #'+ (send-all _featureData :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; msg_generate/Local_msg[] _featureData
     (write-long (length _featureData) s)
     (dolist (elem _featureData)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; msg_generate/Local_msg[] _featureData
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _featureData (let (r) (dotimes (i n) (push (instance msg_generate::Local_msg :init) r)) r))
     (dolist (elem- _featureData)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get msg_generate::Local_Info :md5sum-) "db10bb32b399e072a5d60b68deb7697e")
(setf (get msg_generate::Local_Info :datatype-) "msg_generate/Local_Info")
(setf (get msg_generate::Local_Info :definition-)
      "Local_msg[] featureData

================================================================================
MSG: msg_generate/Local_msg
float64 Id
float64 dist
float64 theta


")



(provide :msg_generate/Local_Info "db10bb32b399e072a5d60b68deb7697e")


