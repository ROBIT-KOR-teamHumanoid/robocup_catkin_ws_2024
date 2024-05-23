;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::udp_order)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'udp_order (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::UDP_ORDER")
  (make-package "MSG_GENERATE::UDP_ORDER"))

(in-package "ROS")
;;//! \htmlinclude udp_order.msg.html


(defclass msg_generate::udp_order
  :super ros::object
  :slots (_order ))

(defmethod msg_generate::udp_order
  (:init
   (&key
    ((:order __order) 0)
    )
   (send-super :init)
   (setq _order (round __order))
   self)
  (:order
   (&optional __order)
   (if __order (setq _order __order)) _order)
  (:serialization-length
   ()
   (+
    ;; int16 _order
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _order
       (write-word _order s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _order
     (setq _order (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get msg_generate::udp_order :md5sum-) "2966e63ad91c66f88bbe7ef4becb02eb")
(setf (get msg_generate::udp_order :datatype-) "msg_generate/udp_order")
(setf (get msg_generate::udp_order :definition-)
      "int16 order
")



(provide :msg_generate/udp_order "2966e63ad91c66f88bbe7ef4becb02eb")


