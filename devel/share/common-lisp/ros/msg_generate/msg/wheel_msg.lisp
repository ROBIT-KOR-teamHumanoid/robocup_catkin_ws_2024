; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude wheel_msg.msg.html

(cl:defclass <wheel_msg> (roslisp-msg-protocol:ros-message)
  ((ang_r_0
    :reader ang_r_0
    :initarg :ang_r_0
    :type cl:float
    :initform 0.0)
   (ang_r_1
    :reader ang_r_1
    :initarg :ang_r_1
    :type cl:float
    :initform 0.0))
)

(cl:defclass wheel_msg (<wheel_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <wheel_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'wheel_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<wheel_msg> is deprecated: use msg_generate-msg:wheel_msg instead.")))

(cl:ensure-generic-function 'ang_r_0-val :lambda-list '(m))
(cl:defmethod ang_r_0-val ((m <wheel_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ang_r_0-val is deprecated.  Use msg_generate-msg:ang_r_0 instead.")
  (ang_r_0 m))

(cl:ensure-generic-function 'ang_r_1-val :lambda-list '(m))
(cl:defmethod ang_r_1-val ((m <wheel_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ang_r_1-val is deprecated.  Use msg_generate-msg:ang_r_1 instead.")
  (ang_r_1 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <wheel_msg>) ostream)
  "Serializes a message object of type '<wheel_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ang_r_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ang_r_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <wheel_msg>) istream)
  "Deserializes a message object of type '<wheel_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ang_r_0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ang_r_1) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<wheel_msg>)))
  "Returns string type for a message object of type '<wheel_msg>"
  "msg_generate/wheel_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'wheel_msg)))
  "Returns string type for a message object of type 'wheel_msg"
  "msg_generate/wheel_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<wheel_msg>)))
  "Returns md5sum for a message object of type '<wheel_msg>"
  "56b78b37c2cdbee448584402f58a25fd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'wheel_msg)))
  "Returns md5sum for a message object of type 'wheel_msg"
  "56b78b37c2cdbee448584402f58a25fd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<wheel_msg>)))
  "Returns full string definition for message of type '<wheel_msg>"
  (cl:format cl:nil "float64 ang_r_0~%float64 ang_r_1~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'wheel_msg)))
  "Returns full string definition for message of type 'wheel_msg"
  (cl:format cl:nil "float64 ang_r_0~%float64 ang_r_1~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <wheel_msg>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <wheel_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'wheel_msg
    (cl:cons ':ang_r_0 (ang_r_0 msg))
    (cl:cons ':ang_r_1 (ang_r_1 msg))
))
