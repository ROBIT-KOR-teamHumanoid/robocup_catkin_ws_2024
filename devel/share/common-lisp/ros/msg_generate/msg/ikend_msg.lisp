; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude ikend_msg.msg.html

(cl:defclass <ikend_msg> (roslisp-msg-protocol:ros-message)
  ((ikend
    :reader ikend
    :initarg :ikend
    :type cl:integer
    :initform 0)
   (onestep_end
    :reader onestep_end
    :initarg :onestep_end
    :type cl:integer
    :initform 0))
)

(cl:defclass ikend_msg (<ikend_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ikend_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ikend_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<ikend_msg> is deprecated: use msg_generate-msg:ikend_msg instead.")))

(cl:ensure-generic-function 'ikend-val :lambda-list '(m))
(cl:defmethod ikend-val ((m <ikend_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ikend-val is deprecated.  Use msg_generate-msg:ikend instead.")
  (ikend m))

(cl:ensure-generic-function 'onestep_end-val :lambda-list '(m))
(cl:defmethod onestep_end-val ((m <ikend_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:onestep_end-val is deprecated.  Use msg_generate-msg:onestep_end instead.")
  (onestep_end m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ikend_msg>) ostream)
  "Serializes a message object of type '<ikend_msg>"
  (cl:let* ((signed (cl:slot-value msg 'ikend)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'onestep_end)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ikend_msg>) istream)
  "Deserializes a message object of type '<ikend_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ikend) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'onestep_end) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ikend_msg>)))
  "Returns string type for a message object of type '<ikend_msg>"
  "msg_generate/ikend_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ikend_msg)))
  "Returns string type for a message object of type 'ikend_msg"
  "msg_generate/ikend_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ikend_msg>)))
  "Returns md5sum for a message object of type '<ikend_msg>"
  "927f1106013c7f12a325ab4e0c8eb54f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ikend_msg)))
  "Returns md5sum for a message object of type 'ikend_msg"
  "927f1106013c7f12a325ab4e0c8eb54f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ikend_msg>)))
  "Returns full string definition for message of type '<ikend_msg>"
  (cl:format cl:nil "int32 ikend~%int32 onestep_end~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ikend_msg)))
  "Returns full string definition for message of type 'ikend_msg"
  (cl:format cl:nil "int32 ikend~%int32 onestep_end~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ikend_msg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ikend_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'ikend_msg
    (cl:cons ':ikend (ikend msg))
    (cl:cons ':onestep_end (onestep_end msg))
))
