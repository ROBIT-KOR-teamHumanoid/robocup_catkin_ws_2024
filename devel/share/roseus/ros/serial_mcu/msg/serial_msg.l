;; Auto-generated. Do not edit!


(when (boundp 'serial_mcu::serial_msg)
  (if (not (find-package "SERIAL_MCU"))
    (make-package "SERIAL_MCU"))
  (shadow 'serial_msg (find-package "SERIAL_MCU")))
(unless (find-package "SERIAL_MCU::SERIAL_MSG")
  (make-package "SERIAL_MCU::SERIAL_MSG"))

(in-package "ROS")
;;//! \htmlinclude serial_msg.msg.html


(defclass serial_mcu::serial_msg
  :super ros::object
  :slots (_length _mode _id _speed _position _type _acceleration _Motion_Mode _Motion_Num ))

(defmethod serial_mcu::serial_msg
  (:init
   (&key
    ((:length __length) 0)
    ((:mode __mode) 0)
    ((:id __id) (make-array 0 :initial-element 0 :element-type :integer))
    ((:speed __speed) (make-array 0 :initial-element 0 :element-type :integer))
    ((:position __position) (make-array 0 :initial-element 0 :element-type :integer))
    ((:type __type) (make-array 0 :initial-element 0 :element-type :integer))
    ((:acceleration __acceleration) (make-array 0 :initial-element 0 :element-type :integer))
    ((:Motion_Mode __Motion_Mode) 0)
    ((:Motion_Num __Motion_Num) 0)
    )
   (send-super :init)
   (setq _length (round __length))
   (setq _mode (round __mode))
   (setq _id __id)
   (setq _speed __speed)
   (setq _position __position)
   (setq _type __type)
   (setq _acceleration __acceleration)
   (setq _Motion_Mode (round __Motion_Mode))
   (setq _Motion_Num (round __Motion_Num))
   self)
  (:length
   (&optional __length)
   (if __length (setq _length __length)) _length)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:Motion_Mode
   (&optional __Motion_Mode)
   (if __Motion_Mode (setq _Motion_Mode __Motion_Mode)) _Motion_Mode)
  (:Motion_Num
   (&optional __Motion_Num)
   (if __Motion_Num (setq _Motion_Num __Motion_Num)) _Motion_Num)
  (:serialization-length
   ()
   (+
    ;; int32 _length
    4
    ;; int32 _mode
    4
    ;; int32[] _id
    (* 4    (length _id)) 4
    ;; int32[] _speed
    (* 4    (length _speed)) 4
    ;; int32[] _position
    (* 4    (length _position)) 4
    ;; int32[] _type
    (* 4    (length _type)) 4
    ;; int32[] _acceleration
    (* 4    (length _acceleration)) 4
    ;; int32 _Motion_Mode
    4
    ;; char _Motion_Num
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _length
       (write-long _length s)
     ;; int32 _mode
       (write-long _mode s)
     ;; int32[] _id
     (write-long (length _id) s)
     (dotimes (i (length _id))
       (write-long (elt _id i) s)
       )
     ;; int32[] _speed
     (write-long (length _speed) s)
     (dotimes (i (length _speed))
       (write-long (elt _speed i) s)
       )
     ;; int32[] _position
     (write-long (length _position) s)
     (dotimes (i (length _position))
       (write-long (elt _position i) s)
       )
     ;; int32[] _type
     (write-long (length _type) s)
     (dotimes (i (length _type))
       (write-long (elt _type i) s)
       )
     ;; int32[] _acceleration
     (write-long (length _acceleration) s)
     (dotimes (i (length _acceleration))
       (write-long (elt _acceleration i) s)
       )
     ;; int32 _Motion_Mode
       (write-long _Motion_Mode s)
     ;; char _Motion_Num
       (write-byte _Motion_Num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _length
     (setq _length (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _id
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _id (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _id i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _speed
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _speed (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _speed i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _position
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _position (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _position i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _type
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _type (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _type i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _acceleration
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _acceleration (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _acceleration i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32 _Motion_Mode
     (setq _Motion_Mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; char _Motion_Num
     (setq _Motion_Num (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get serial_mcu::serial_msg :md5sum-) "fbc3cf6a4f8860d2007547b0553a4524")
(setf (get serial_mcu::serial_msg :datatype-) "serial_mcu/serial_msg")
(setf (get serial_mcu::serial_msg :definition-)
      "int32 length
int32 mode
int32[] id
int32[] speed
int32[] position
int32[] type
int32[] acceleration

int32 Motion_Mode
char Motion_Num

")



(provide :serial_mcu/serial_msg "fbc3cf6a4f8860d2007547b0553a4524")


