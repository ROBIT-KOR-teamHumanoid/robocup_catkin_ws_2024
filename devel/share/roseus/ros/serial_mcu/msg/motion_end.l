;; Auto-generated. Do not edit!


(when (boundp 'serial_mcu::motion_end)
  (if (not (find-package "SERIAL_MCU"))
    (make-package "SERIAL_MCU"))
  (shadow 'motion_end (find-package "SERIAL_MCU")))
(unless (find-package "SERIAL_MCU::MOTION_END")
  (make-package "SERIAL_MCU::MOTION_END"))

(in-package "ROS")
;;//! \htmlinclude motion_end.msg.html


(defclass serial_mcu::motion_end
  :super ros::object
  :slots (_motion_end ))

(defmethod serial_mcu::motion_end
  (:init
   (&key
    ((:motion_end __motion_end) 0)
    )
   (send-super :init)
   (setq _motion_end (round __motion_end))
   self)
  (:motion_end
   (&optional __motion_end)
   (if __motion_end (setq _motion_end __motion_end)) _motion_end)
  (:serialization-length
   ()
   (+
    ;; int32 _motion_end
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _motion_end
       (write-long _motion_end s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _motion_end
     (setq _motion_end (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get serial_mcu::motion_end :md5sum-) "d3aa7962353285617f39219e4e26c45c")
(setf (get serial_mcu::motion_end :datatype-) "serial_mcu/motion_end")
(setf (get serial_mcu::motion_end :definition-)
      "int32 motion_end

")



(provide :serial_mcu/motion_end "d3aa7962353285617f39219e4e26c45c")


