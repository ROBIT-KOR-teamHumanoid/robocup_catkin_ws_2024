;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::walk_pattern)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'walk_pattern (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::WALK_PATTERN")
  (make-package "MSG_GENERATE::WALK_PATTERN"))

(in-package "ROS")
;;//! \htmlinclude walk_pattern.msg.html


(defclass msg_generate::walk_pattern
  :super ros::object
  :slots (_xlpattern _ylpattern _zlpattern _slpattern _tlpattern _xrpattern _yrpattern _zrpattern _srpattern _trpattern ))

(defmethod msg_generate::walk_pattern
  (:init
   (&key
    ((:xlpattern __xlpattern) 0.0)
    ((:ylpattern __ylpattern) 0.0)
    ((:zlpattern __zlpattern) 0.0)
    ((:slpattern __slpattern) 0.0)
    ((:tlpattern __tlpattern) 0.0)
    ((:xrpattern __xrpattern) 0.0)
    ((:yrpattern __yrpattern) 0.0)
    ((:zrpattern __zrpattern) 0.0)
    ((:srpattern __srpattern) 0.0)
    ((:trpattern __trpattern) 0.0)
    )
   (send-super :init)
   (setq _xlpattern (float __xlpattern))
   (setq _ylpattern (float __ylpattern))
   (setq _zlpattern (float __zlpattern))
   (setq _slpattern (float __slpattern))
   (setq _tlpattern (float __tlpattern))
   (setq _xrpattern (float __xrpattern))
   (setq _yrpattern (float __yrpattern))
   (setq _zrpattern (float __zrpattern))
   (setq _srpattern (float __srpattern))
   (setq _trpattern (float __trpattern))
   self)
  (:xlpattern
   (&optional __xlpattern)
   (if __xlpattern (setq _xlpattern __xlpattern)) _xlpattern)
  (:ylpattern
   (&optional __ylpattern)
   (if __ylpattern (setq _ylpattern __ylpattern)) _ylpattern)
  (:zlpattern
   (&optional __zlpattern)
   (if __zlpattern (setq _zlpattern __zlpattern)) _zlpattern)
  (:slpattern
   (&optional __slpattern)
   (if __slpattern (setq _slpattern __slpattern)) _slpattern)
  (:tlpattern
   (&optional __tlpattern)
   (if __tlpattern (setq _tlpattern __tlpattern)) _tlpattern)
  (:xrpattern
   (&optional __xrpattern)
   (if __xrpattern (setq _xrpattern __xrpattern)) _xrpattern)
  (:yrpattern
   (&optional __yrpattern)
   (if __yrpattern (setq _yrpattern __yrpattern)) _yrpattern)
  (:zrpattern
   (&optional __zrpattern)
   (if __zrpattern (setq _zrpattern __zrpattern)) _zrpattern)
  (:srpattern
   (&optional __srpattern)
   (if __srpattern (setq _srpattern __srpattern)) _srpattern)
  (:trpattern
   (&optional __trpattern)
   (if __trpattern (setq _trpattern __trpattern)) _trpattern)
  (:serialization-length
   ()
   (+
    ;; float64 _xlpattern
    8
    ;; float64 _ylpattern
    8
    ;; float64 _zlpattern
    8
    ;; float64 _slpattern
    8
    ;; float64 _tlpattern
    8
    ;; float64 _xrpattern
    8
    ;; float64 _yrpattern
    8
    ;; float64 _zrpattern
    8
    ;; float64 _srpattern
    8
    ;; float64 _trpattern
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _xlpattern
       (sys::poke _xlpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ylpattern
       (sys::poke _ylpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zlpattern
       (sys::poke _zlpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _slpattern
       (sys::poke _slpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _tlpattern
       (sys::poke _tlpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xrpattern
       (sys::poke _xrpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yrpattern
       (sys::poke _yrpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zrpattern
       (sys::poke _zrpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _srpattern
       (sys::poke _srpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _trpattern
       (sys::poke _trpattern (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _xlpattern
     (setq _xlpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ylpattern
     (setq _ylpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zlpattern
     (setq _zlpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _slpattern
     (setq _slpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _tlpattern
     (setq _tlpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xrpattern
     (setq _xrpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yrpattern
     (setq _yrpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zrpattern
     (setq _zrpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _srpattern
     (setq _srpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _trpattern
     (setq _trpattern (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::walk_pattern :md5sum-) "bb4fe551ab158f80aba28048dfbba352")
(setf (get msg_generate::walk_pattern :datatype-) "msg_generate/walk_pattern")
(setf (get msg_generate::walk_pattern :definition-)
      "float64 xlpattern
float64 ylpattern
float64 zlpattern
float64 slpattern
float64 tlpattern
float64 xrpattern
float64 yrpattern
float64 zrpattern
float64 srpattern
float64 trpattern

")



(provide :msg_generate/walk_pattern "bb4fe551ab158f80aba28048dfbba352")


