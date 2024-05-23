; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude Mt2Serial_msg.msg.html

(cl:defclass <Mt2Serial_msg> (roslisp-msg-protocol:ros-message)
  ((Motion_Mode
    :reader Motion_Mode
    :initarg :Motion_Mode
    :type cl:integer
    :initform 0)
   (Motion_Num
    :reader Motion_Num
    :initarg :Motion_Num
    :type cl:integer
    :initform 0))
)

(cl:defclass Mt2Serial_msg (<Mt2Serial_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Mt2Serial_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Mt2Serial_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<Mt2Serial_msg> is deprecated: use msg_generate-msg:Mt2Serial_msg instead.")))

(cl:ensure-generic-function 'Motion_Mode-val :lambda-list '(m))
(cl:defmethod Motion_Mode-val ((m <Mt2Serial_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Motion_Mode-val is deprecated.  Use msg_generate-msg:Motion_Mode instead.")
  (Motion_Mode m))

(cl:ensure-generic-function 'Motion_Num-val :lambda-list '(m))
(cl:defmethod Motion_Num-val ((m <Mt2Serial_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Motion_Num-val is deprecated.  Use msg_generate-msg:Motion_Num instead.")
  (Motion_Num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Mt2Serial_msg>) ostream)
  "Serializes a message object of type '<Mt2Serial_msg>"
  (cl:let* ((signed (cl:slot-value msg 'Motion_Mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Motion_Num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Mt2Serial_msg>) istream)
  "Deserializes a message object of type '<Mt2Serial_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Motion_Mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Motion_Num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Mt2Serial_msg>)))
  "Returns string type for a message object of type '<Mt2Serial_msg>"
  "msg_generate/Mt2Serial_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Mt2Serial_msg)))
  "Returns string type for a message object of type 'Mt2Serial_msg"
  "msg_generate/Mt2Serial_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Mt2Serial_msg>)))
  "Returns md5sum for a message object of type '<Mt2Serial_msg>"
  "e3f9ec431b0fdc81956c12a8b317c691")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Mt2Serial_msg)))
  "Returns md5sum for a message object of type 'Mt2Serial_msg"
  "e3f9ec431b0fdc81956c12a8b317c691")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Mt2Serial_msg>)))
  "Returns full string definition for message of type '<Mt2Serial_msg>"
  (cl:format cl:nil "int32 Motion_Mode~%int32 Motion_Num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Mt2Serial_msg)))
  "Returns full string definition for message of type 'Mt2Serial_msg"
  (cl:format cl:nil "int32 Motion_Mode~%int32 Motion_Num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Mt2Serial_msg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Mt2Serial_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Mt2Serial_msg
    (cl:cons ':Motion_Mode (Motion_Mode msg))
    (cl:cons ':Motion_Num (Motion_Num msg))
))
