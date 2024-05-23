; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude motion_operator_data.msg.html

(cl:defclass <motion_operator_data> (roslisp-msg-protocol:ros-message)
  ((yaw_data
    :reader yaw_data
    :initarg :yaw_data
    :type cl:integer
    :initform 0)
   (startmotion
    :reader startmotion
    :initarg :startmotion
    :type cl:integer
    :initform 0))
)

(cl:defclass motion_operator_data (<motion_operator_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motion_operator_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motion_operator_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<motion_operator_data> is deprecated: use msg_generate-msg:motion_operator_data instead.")))

(cl:ensure-generic-function 'yaw_data-val :lambda-list '(m))
(cl:defmethod yaw_data-val ((m <motion_operator_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:yaw_data-val is deprecated.  Use msg_generate-msg:yaw_data instead.")
  (yaw_data m))

(cl:ensure-generic-function 'startmotion-val :lambda-list '(m))
(cl:defmethod startmotion-val ((m <motion_operator_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:startmotion-val is deprecated.  Use msg_generate-msg:startmotion instead.")
  (startmotion m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motion_operator_data>) ostream)
  "Serializes a message object of type '<motion_operator_data>"
  (cl:let* ((signed (cl:slot-value msg 'yaw_data)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'startmotion)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motion_operator_data>) istream)
  "Deserializes a message object of type '<motion_operator_data>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'yaw_data) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'startmotion) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motion_operator_data>)))
  "Returns string type for a message object of type '<motion_operator_data>"
  "msg_generate/motion_operator_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motion_operator_data)))
  "Returns string type for a message object of type 'motion_operator_data"
  "msg_generate/motion_operator_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motion_operator_data>)))
  "Returns md5sum for a message object of type '<motion_operator_data>"
  "ca7ee85fd473a08527f7d102be53f660")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motion_operator_data)))
  "Returns md5sum for a message object of type 'motion_operator_data"
  "ca7ee85fd473a08527f7d102be53f660")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motion_operator_data>)))
  "Returns full string definition for message of type '<motion_operator_data>"
  (cl:format cl:nil "int32 yaw_data~%int32 startmotion~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motion_operator_data)))
  "Returns full string definition for message of type 'motion_operator_data"
  (cl:format cl:nil "int32 yaw_data~%int32 startmotion~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motion_operator_data>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motion_operator_data>))
  "Converts a ROS message object to a list"
  (cl:list 'motion_operator_data
    (cl:cons ':yaw_data (yaw_data msg))
    (cl:cons ':startmotion (startmotion msg))
))
