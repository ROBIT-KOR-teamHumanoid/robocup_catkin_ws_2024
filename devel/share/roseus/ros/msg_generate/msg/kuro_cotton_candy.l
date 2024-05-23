;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::kuro_cotton_candy)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'kuro_cotton_candy (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::KURO_COTTON_CANDY")
  (make-package "MSG_GENERATE::KURO_COTTON_CANDY"))

(in-package "ROS")
;;//! \htmlinclude kuro_cotton_candy.msg.html


(defclass msg_generate::kuro_cotton_candy
  :super ros::object
  :slots (_ready _start _stop _timer ))

(defmethod msg_generate::kuro_cotton_candy
  (:init
   (&key
    ((:ready __ready) nil)
    ((:start __start) nil)
    ((:stop __stop) nil)
    ((:timer __timer) 0.0)
    )
   (send-super :init)
   (setq _ready __ready)
   (setq _start __start)
   (setq _stop __stop)
   (setq _timer (float __timer))
   self)
  (:ready
   (&optional __ready)
   (if __ready (setq _ready __ready)) _ready)
  (:start
   (&optional __start)
   (if __start (setq _start __start)) _start)
  (:stop
   (&optional __stop)
   (if __stop (setq _stop __stop)) _stop)
  (:timer
   (&optional __timer)
   (if __timer (setq _timer __timer)) _timer)
  (:serialization-length
   ()
   (+
    ;; bool _ready
    1
    ;; bool _start
    1
    ;; bool _stop
    1
    ;; float64 _timer
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ready
       (if _ready (write-byte -1 s) (write-byte 0 s))
     ;; bool _start
       (if _start (write-byte -1 s) (write-byte 0 s))
     ;; bool _stop
       (if _stop (write-byte -1 s) (write-byte 0 s))
     ;; float64 _timer
       (sys::poke _timer (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ready
     (setq _ready (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _start
     (setq _start (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _stop
     (setq _stop (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _timer
     (setq _timer (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get msg_generate::kuro_cotton_candy :md5sum-) "d9f3ac83b00612092e5b577721e3b2ac")
(setf (get msg_generate::kuro_cotton_candy :datatype-) "msg_generate/kuro_cotton_candy")
(setf (get msg_generate::kuro_cotton_candy :definition-)
      "bool ready
bool start
bool stop
float64 timer 

")



(provide :msg_generate/kuro_cotton_candy "d9f3ac83b00612092e5b577721e3b2ac")


