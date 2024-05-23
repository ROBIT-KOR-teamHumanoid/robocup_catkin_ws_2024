;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::Step_msg)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'Step_msg (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::STEP_MSG")
  (make-package "MSG_GENERATE::STEP_MSG"))

(in-package "ROS")
;;//! \htmlinclude Step_msg.msg.html


(defclass msg_generate::Step_msg
  :super ros::object
  :slots (_delay _time _id _position ))

(defmethod msg_generate::Step_msg
  (:init
   (&key
    ((:delay __delay) 0)
    ((:time __time) 0)
    ((:id __id) (make-array 0 :initial-element 0 :element-type :integer))
    ((:position __position) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _delay (round __delay))
   (setq _time (round __time))
   (setq _id __id)
   (setq _position __position)
   self)
  (:delay
   (&optional __delay)
   (if __delay (setq _delay __delay)) _delay)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:serialization-length
   ()
   (+
    ;; int32 _delay
    4
    ;; int32 _time
    4
    ;; int32[] _id
    (* 4    (length _id)) 4
    ;; int32[] _position
    (* 4    (length _position)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _delay
       (write-long _delay s)
     ;; int32 _time
       (write-long _time s)
     ;; int32[] _id
     (write-long (length _id) s)
     (dotimes (i (length _id))
       (write-long (elt _id i) s)
       )
     ;; int32[] _position
     (write-long (length _position) s)
     (dotimes (i (length _position))
       (write-long (elt _position i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _delay
     (setq _delay (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _id
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _id (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _id i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _position
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _position (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _position i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get msg_generate::Step_msg :md5sum-) "a82b6e64922c5569387165da569b0157")
(setf (get msg_generate::Step_msg :datatype-) "msg_generate/Step_msg")
(setf (get msg_generate::Step_msg :definition-)
      "int32 delay
int32 time
int32[] id
int32[] position



")



(provide :msg_generate/Step_msg "a82b6e64922c5569387165da569b0157")


