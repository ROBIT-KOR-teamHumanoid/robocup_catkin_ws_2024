; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude support_onestep_msg.msg.html

(cl:defclass <support_onestep_msg> (roslisp-msg-protocol:ros-message)
  ((onestep_checker
    :reader onestep_checker
    :initarg :onestep_checker
    :type cl:integer
    :initform 0))
)

(cl:defclass support_onestep_msg (<support_onestep_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <support_onestep_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'support_onestep_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<support_onestep_msg> is deprecated: use msg_generate-msg:support_onestep_msg instead.")))

(cl:ensure-generic-function 'onestep_checker-val :lambda-list '(m))
(cl:defmethod onestep_checker-val ((m <support_onestep_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:onestep_checker-val is deprecated.  Use msg_generate-msg:onestep_checker instead.")
  (onestep_checker m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <support_onestep_msg>) ostream)
  "Serializes a message object of type '<support_onestep_msg>"
  (cl:let* ((signed (cl:slot-value msg 'onestep_checker)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <support_onestep_msg>) istream)
  "Deserializes a message object of type '<support_onestep_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'onestep_checker) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<support_onestep_msg>)))
  "Returns string type for a message object of type '<support_onestep_msg>"
  "msg_generate/support_onestep_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'support_onestep_msg)))
  "Returns string type for a message object of type 'support_onestep_msg"
  "msg_generate/support_onestep_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<support_onestep_msg>)))
  "Returns md5sum for a message object of type '<support_onestep_msg>"
  "260ab72f5eacc5be420032b06460a43f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'support_onestep_msg)))
  "Returns md5sum for a message object of type 'support_onestep_msg"
  "260ab72f5eacc5be420032b06460a43f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<support_onestep_msg>)))
  "Returns full string definition for message of type '<support_onestep_msg>"
  (cl:format cl:nil "int32 onestep_checker~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'support_onestep_msg)))
  "Returns full string definition for message of type 'support_onestep_msg"
  (cl:format cl:nil "int32 onestep_checker~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <support_onestep_msg>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <support_onestep_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'support_onestep_msg
    (cl:cons ':onestep_checker (onestep_checker msg))
))
