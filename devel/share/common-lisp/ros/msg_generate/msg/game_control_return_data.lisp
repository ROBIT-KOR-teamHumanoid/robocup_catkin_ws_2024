; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude game_control_return_data.msg.html

(cl:defclass <game_control_return_data> (roslisp-msg-protocol:ros-message)
  ((message
    :reader message
    :initarg :message
    :type cl:integer
    :initform 0))
)

(cl:defclass game_control_return_data (<game_control_return_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <game_control_return_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'game_control_return_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<game_control_return_data> is deprecated: use msg_generate-msg:game_control_return_data instead.")))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <game_control_return_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:message-val is deprecated.  Use msg_generate-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <game_control_return_data>) ostream)
  "Serializes a message object of type '<game_control_return_data>"
  (cl:let* ((signed (cl:slot-value msg 'message)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <game_control_return_data>) istream)
  "Deserializes a message object of type '<game_control_return_data>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<game_control_return_data>)))
  "Returns string type for a message object of type '<game_control_return_data>"
  "msg_generate/game_control_return_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'game_control_return_data)))
  "Returns string type for a message object of type 'game_control_return_data"
  "msg_generate/game_control_return_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<game_control_return_data>)))
  "Returns md5sum for a message object of type '<game_control_return_data>"
  "9b8769cd592bd7dbe979986bd8cd4f43")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'game_control_return_data)))
  "Returns md5sum for a message object of type 'game_control_return_data"
  "9b8769cd592bd7dbe979986bd8cd4f43")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<game_control_return_data>)))
  "Returns full string definition for message of type '<game_control_return_data>"
  (cl:format cl:nil "int64 message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'game_control_return_data)))
  "Returns full string definition for message of type 'game_control_return_data"
  (cl:format cl:nil "int64 message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <game_control_return_data>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <game_control_return_data>))
  "Converts a ROS message object to a list"
  (cl:list 'game_control_return_data
    (cl:cons ':message (message msg))
))
