;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::master2hanoi_vision2019msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'master2hanoi_vision2019msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::MASTER2HANOI_VISION2019MSG")
  (make-package "MSG_GENERATE::MASTER2HANOI_VISION2019MSG"))

(in-package "ROS")
;;//! \htmlinclude master2hanoi_vision2019msg.msg.html


(defclass msg_generate::master2hanoi_vision2019msg
  :super ros::object
  :slots (_color_what _alpha_check ))

(defmethod msg_generate::master2hanoi_vision2019msg
  (:init
   (&key
    ((:color_what __color_what) 0)
    ((:alpha_check __alpha_check) nil)
    )
   (send-super :init)
   (setq _color_what (round __color_what))
   (setq _alpha_check __alpha_check)
   self)
  (:color_what
   (&optional __color_what)
   (if __color_what (setq _color_what __color_what)) _color_what)
  (:alpha_check
   (&optional __alpha_check)
   (if __alpha_check (setq _alpha_check __alpha_check)) _alpha_check)
  (:serialization-length
   ()
   (+
    ;; int32 _color_what
    4
    ;; bool _alpha_check
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _color_what
       (write-long _color_what s)
     ;; bool _alpha_check
       (if _alpha_check (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _color_what
     (setq _color_what (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _alpha_check
     (setq _alpha_check (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get msg_generate::master2hanoi_vision2019msg :md5sum-) "0da4621181e0545911e6b295c023e0d4")
(setf (get msg_generate::master2hanoi_vision2019msg :datatype-) "msg_generate/master2hanoi_vision2019msg")
(setf (get msg_generate::master2hanoi_vision2019msg :definition-)
      "int32 color_what
bool alpha_check

")



(provide :msg_generate/master2hanoi_vision2019msg "0da4621181e0545911e6b295c023e0d4")


