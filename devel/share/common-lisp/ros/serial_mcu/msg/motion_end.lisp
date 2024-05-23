; Auto-generated. Do not edit!


(cl:in-package serial_mcu-msg)


;//! \htmlinclude motion_end.msg.html

(cl:defclass <motion_end> (roslisp-msg-protocol:ros-message)
  ((motion_end
    :reader motion_end
    :initarg :motion_end
    :type cl:integer
    :initform 0))
)

(cl:defclass motion_end (<motion_end>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motion_end>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motion_end)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name serial_mcu-msg:<motion_end> is deprecated: use serial_mcu-msg:motion_end instead.")))

(cl:ensure-generic-function 'motion_end-val :lambda-list '(m))
(cl:defmethod motion_end-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader serial_mcu-msg:motion_end-val is deprecated.  Use serial_mcu-msg:motion_end instead.")
  (motion_end m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motion_end>) ostream)
  "Serializes a message object of type '<motion_end>"
  (cl:let* ((signed (cl:slot-value msg 'motion_end)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motion_end>) istream)
  "Deserializes a message object of type '<motion_end>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_end) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motion_end>)))
  "Returns string type for a message object of type '<motion_end>"
  "serial_mcu/motion_end")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motion_end)))
  "Returns string type for a message object of type 'motion_end"
  "serial_mcu/motion_end")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motion_end>)))
  "Returns md5sum for a message object of type '<motion_end>"
  "d3aa7962353285617f39219e4e26c45c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motion_end)))
  "Returns md5sum for a message object of type 'motion_end"
  "d3aa7962353285617f39219e4e26c45c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motion_end>)))
  "Returns full string definition for message of type '<motion_end>"
  (cl:format cl:nil "int32 motion_end~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motion_end)))
  "Returns full string definition for message of type 'motion_end"
  (cl:format cl:nil "int32 motion_end~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motion_end>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motion_end>))
  "Converts a ROS message object to a list"
  (cl:list 'motion_end
    (cl:cons ':motion_end (motion_end msg))
))
