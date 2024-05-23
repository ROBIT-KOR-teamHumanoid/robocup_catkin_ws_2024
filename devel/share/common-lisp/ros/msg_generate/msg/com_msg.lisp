; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude com_msg.msg.html

(cl:defclass <com_msg> (roslisp-msg-protocol:ros-message)
  ((X_com
    :reader X_com
    :initarg :X_com
    :type cl:float
    :initform 0.0)
   (Y_com
    :reader Y_com
    :initarg :Y_com
    :type cl:float
    :initform 0.0))
)

(cl:defclass com_msg (<com_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <com_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'com_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<com_msg> is deprecated: use msg_generate-msg:com_msg instead.")))

(cl:ensure-generic-function 'X_com-val :lambda-list '(m))
(cl:defmethod X_com-val ((m <com_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:X_com-val is deprecated.  Use msg_generate-msg:X_com instead.")
  (X_com m))

(cl:ensure-generic-function 'Y_com-val :lambda-list '(m))
(cl:defmethod Y_com-val ((m <com_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Y_com-val is deprecated.  Use msg_generate-msg:Y_com instead.")
  (Y_com m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <com_msg>) ostream)
  "Serializes a message object of type '<com_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'X_com))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Y_com))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <com_msg>) istream)
  "Deserializes a message object of type '<com_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X_com) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y_com) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<com_msg>)))
  "Returns string type for a message object of type '<com_msg>"
  "msg_generate/com_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'com_msg)))
  "Returns string type for a message object of type 'com_msg"
  "msg_generate/com_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<com_msg>)))
  "Returns md5sum for a message object of type '<com_msg>"
  "47867f34a56c5603eede6e151741abd1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'com_msg)))
  "Returns md5sum for a message object of type 'com_msg"
  "47867f34a56c5603eede6e151741abd1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<com_msg>)))
  "Returns full string definition for message of type '<com_msg>"
  (cl:format cl:nil "float64 X_com~%float64 Y_com~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'com_msg)))
  "Returns full string definition for message of type 'com_msg"
  (cl:format cl:nil "float64 X_com~%float64 Y_com~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <com_msg>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <com_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'com_msg
    (cl:cons ':X_com (X_com msg))
    (cl:cons ':Y_com (Y_com msg))
))
