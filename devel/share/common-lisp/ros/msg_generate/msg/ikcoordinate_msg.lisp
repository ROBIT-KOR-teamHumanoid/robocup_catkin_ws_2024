; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude ikcoordinate_msg.msg.html

(cl:defclass <ikcoordinate_msg> (roslisp-msg-protocol:ros-message)
  ((X
    :reader X
    :initarg :X
    :type cl:integer
    :initform 0)
   (Y
    :reader Y
    :initarg :Y
    :type cl:integer
    :initform 0))
)

(cl:defclass ikcoordinate_msg (<ikcoordinate_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ikcoordinate_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ikcoordinate_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<ikcoordinate_msg> is deprecated: use msg_generate-msg:ikcoordinate_msg instead.")))

(cl:ensure-generic-function 'X-val :lambda-list '(m))
(cl:defmethod X-val ((m <ikcoordinate_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:X-val is deprecated.  Use msg_generate-msg:X instead.")
  (X m))

(cl:ensure-generic-function 'Y-val :lambda-list '(m))
(cl:defmethod Y-val ((m <ikcoordinate_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Y-val is deprecated.  Use msg_generate-msg:Y instead.")
  (Y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ikcoordinate_msg>) ostream)
  "Serializes a message object of type '<ikcoordinate_msg>"
  (cl:let* ((signed (cl:slot-value msg 'X)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ikcoordinate_msg>) istream)
  "Deserializes a message object of type '<ikcoordinate_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'X) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ikcoordinate_msg>)))
  "Returns string type for a message object of type '<ikcoordinate_msg>"
  "msg_generate/ikcoordinate_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ikcoordinate_msg)))
  "Returns string type for a message object of type 'ikcoordinate_msg"
  "msg_generate/ikcoordinate_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ikcoordinate_msg>)))
  "Returns md5sum for a message object of type '<ikcoordinate_msg>"
  "4d09a2d26153835cde0795d12585c794")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ikcoordinate_msg)))
  "Returns md5sum for a message object of type 'ikcoordinate_msg"
  "4d09a2d26153835cde0795d12585c794")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ikcoordinate_msg>)))
  "Returns full string definition for message of type '<ikcoordinate_msg>"
  (cl:format cl:nil "int32 X~%int32 Y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ikcoordinate_msg)))
  "Returns full string definition for message of type 'ikcoordinate_msg"
  (cl:format cl:nil "int32 X~%int32 Y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ikcoordinate_msg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ikcoordinate_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'ikcoordinate_msg
    (cl:cons ':X (X msg))
    (cl:cons ':Y (Y msg))
))
