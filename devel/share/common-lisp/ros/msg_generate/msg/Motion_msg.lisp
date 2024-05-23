; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude Motion_msg.msg.html

(cl:defclass <Motion_msg> (roslisp-msg-protocol:ros-message)
  ((max_step
    :reader max_step
    :initarg :max_step
    :type cl:integer
    :initform 0)
   (repeat
    :reader repeat
    :initarg :repeat
    :type cl:integer
    :initform 0)
   (acc
    :reader acc
    :initarg :acc
    :type cl:integer
    :initform 0)
   (motion_data
    :reader motion_data
    :initarg :motion_data
    :type (cl:vector msg_generate-msg:Step_msg)
   :initform (cl:make-array 0 :element-type 'msg_generate-msg:Step_msg :initial-element (cl:make-instance 'msg_generate-msg:Step_msg))))
)

(cl:defclass Motion_msg (<Motion_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Motion_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Motion_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<Motion_msg> is deprecated: use msg_generate-msg:Motion_msg instead.")))

(cl:ensure-generic-function 'max_step-val :lambda-list '(m))
(cl:defmethod max_step-val ((m <Motion_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:max_step-val is deprecated.  Use msg_generate-msg:max_step instead.")
  (max_step m))

(cl:ensure-generic-function 'repeat-val :lambda-list '(m))
(cl:defmethod repeat-val ((m <Motion_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:repeat-val is deprecated.  Use msg_generate-msg:repeat instead.")
  (repeat m))

(cl:ensure-generic-function 'acc-val :lambda-list '(m))
(cl:defmethod acc-val ((m <Motion_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:acc-val is deprecated.  Use msg_generate-msg:acc instead.")
  (acc m))

(cl:ensure-generic-function 'motion_data-val :lambda-list '(m))
(cl:defmethod motion_data-val ((m <Motion_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_data-val is deprecated.  Use msg_generate-msg:motion_data instead.")
  (motion_data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Motion_msg>) ostream)
  "Serializes a message object of type '<Motion_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'max_step)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'max_step)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'max_step)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'max_step)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'repeat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'repeat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'repeat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'repeat)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'acc)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'acc)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'acc)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'acc)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'motion_data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'motion_data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Motion_msg>) istream)
  "Deserializes a message object of type '<Motion_msg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'max_step)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'max_step)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'max_step)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'max_step)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'repeat)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'repeat)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'repeat)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'repeat)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'acc)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'acc)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'acc)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'acc)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'motion_data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'motion_data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'msg_generate-msg:Step_msg))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Motion_msg>)))
  "Returns string type for a message object of type '<Motion_msg>"
  "msg_generate/Motion_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Motion_msg)))
  "Returns string type for a message object of type 'Motion_msg"
  "msg_generate/Motion_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Motion_msg>)))
  "Returns md5sum for a message object of type '<Motion_msg>"
  "fbcb902fe8f910d4d1cd05b17d5ee522")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Motion_msg)))
  "Returns md5sum for a message object of type 'Motion_msg"
  "fbcb902fe8f910d4d1cd05b17d5ee522")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Motion_msg>)))
  "Returns full string definition for message of type '<Motion_msg>"
  (cl:format cl:nil "uint32 max_step~%uint32 repeat~%uint32 acc~%Step_msg[] motion_data~%~%================================================================================~%MSG: msg_generate/Step_msg~%int32 delay~%int32 time~%int32[] id~%int32[] position~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Motion_msg)))
  "Returns full string definition for message of type 'Motion_msg"
  (cl:format cl:nil "uint32 max_step~%uint32 repeat~%uint32 acc~%Step_msg[] motion_data~%~%================================================================================~%MSG: msg_generate/Step_msg~%int32 delay~%int32 time~%int32[] id~%int32[] position~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Motion_msg>))
  (cl:+ 0
     4
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motion_data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Motion_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Motion_msg
    (cl:cons ':max_step (max_step msg))
    (cl:cons ':repeat (repeat msg))
    (cl:cons ':acc (acc msg))
    (cl:cons ':motion_data (motion_data msg))
))
