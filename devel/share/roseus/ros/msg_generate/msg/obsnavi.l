;; Auto-generated. Do not edit!


(when (boundp 'msg_generate::obsnavi)
  (if (not (find-package "MSG_GENERATE"))
    (make-package "MSG_GENERATE"))
  (shadow 'obsnavi (find-package "MSG_GENERATE")))
(unless (find-package "MSG_GENERATE::OBSNAVI")
  (make-package "MSG_GENERATE::OBSNAVI"))

(in-package "ROS")
;;//! \htmlinclude obsnavi.msg.html


(defclass msg_generate::obsnavi
  :super ros::object
  :slots (_DISTANCE _POINT_VEC_X _POINT_VEC_Y ))

(defmethod msg_generate::obsnavi
  (:init
   (&key
    ((:DISTANCE __DISTANCE) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:POINT_VEC_X __POINT_VEC_X) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:POINT_VEC_Y __POINT_VEC_Y) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _DISTANCE __DISTANCE)
   (setq _POINT_VEC_X __POINT_VEC_X)
   (setq _POINT_VEC_Y __POINT_VEC_Y)
   self)
  (:DISTANCE
   (&optional __DISTANCE)
   (if __DISTANCE (setq _DISTANCE __DISTANCE)) _DISTANCE)
  (:POINT_VEC_X
   (&optional __POINT_VEC_X)
   (if __POINT_VEC_X (setq _POINT_VEC_X __POINT_VEC_X)) _POINT_VEC_X)
  (:POINT_VEC_Y
   (&optional __POINT_VEC_Y)
   (if __POINT_VEC_Y (setq _POINT_VEC_Y __POINT_VEC_Y)) _POINT_VEC_Y)
  (:serialization-length
   ()
   (+
    ;; float64[] _DISTANCE
    (* 8    (length _DISTANCE)) 4
    ;; float64[] _POINT_VEC_X
    (* 8    (length _POINT_VEC_X)) 4
    ;; float64[] _POINT_VEC_Y
    (* 8    (length _POINT_VEC_Y)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _DISTANCE
     (write-long (length _DISTANCE) s)
     (dotimes (i (length _DISTANCE))
       (sys::poke (elt _DISTANCE i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _POINT_VEC_X
     (write-long (length _POINT_VEC_X) s)
     (dotimes (i (length _POINT_VEC_X))
       (sys::poke (elt _POINT_VEC_X i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _POINT_VEC_Y
     (write-long (length _POINT_VEC_Y) s)
     (dotimes (i (length _POINT_VEC_Y))
       (sys::poke (elt _POINT_VEC_Y i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _DISTANCE
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _DISTANCE (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _DISTANCE i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _POINT_VEC_X
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _POINT_VEC_X (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _POINT_VEC_X i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _POINT_VEC_Y
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _POINT_VEC_Y (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _POINT_VEC_Y i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get msg_generate::obsnavi :md5sum-) "91095f1ce1738209df71690fed654828")
(setf (get msg_generate::obsnavi :datatype-) "msg_generate/obsnavi")
(setf (get msg_generate::obsnavi :definition-)
      "float64[] DISTANCE
float64[] POINT_VEC_X
float64[] POINT_VEC_Y


")



(provide :msg_generate/obsnavi "91095f1ce1738209df71690fed654828")


