; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude udp_msg_TC_Kicker.msg.html

(cl:defclass <udp_msg_TC_Kicker> (roslisp-msg-protocol:ros-message)
  ((robot_num
    :reader robot_num
    :initarg :robot_num
    :type cl:integer
    :initform 0)
   (robot_case
    :reader robot_case
    :initarg :robot_case
    :type cl:integer
    :initform 0)
   (local_x
    :reader local_x
    :initarg :local_x
    :type cl:integer
    :initform 0)
   (local_y
    :reader local_y
    :initarg :local_y
    :type cl:integer
    :initform 0)
   (local_yaw
    :reader local_yaw
    :initarg :local_yaw
    :type cl:integer
    :initform 0))
)

(cl:defclass udp_msg_TC_Kicker (<udp_msg_TC_Kicker>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <udp_msg_TC_Kicker>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'udp_msg_TC_Kicker)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<udp_msg_TC_Kicker> is deprecated: use msg_generate-msg:udp_msg_TC_Kicker instead.")))

(cl:ensure-generic-function 'robot_num-val :lambda-list '(m))
(cl:defmethod robot_num-val ((m <udp_msg_TC_Kicker>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:robot_num-val is deprecated.  Use msg_generate-msg:robot_num instead.")
  (robot_num m))

(cl:ensure-generic-function 'robot_case-val :lambda-list '(m))
(cl:defmethod robot_case-val ((m <udp_msg_TC_Kicker>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:robot_case-val is deprecated.  Use msg_generate-msg:robot_case instead.")
  (robot_case m))

(cl:ensure-generic-function 'local_x-val :lambda-list '(m))
(cl:defmethod local_x-val ((m <udp_msg_TC_Kicker>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:local_x-val is deprecated.  Use msg_generate-msg:local_x instead.")
  (local_x m))

(cl:ensure-generic-function 'local_y-val :lambda-list '(m))
(cl:defmethod local_y-val ((m <udp_msg_TC_Kicker>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:local_y-val is deprecated.  Use msg_generate-msg:local_y instead.")
  (local_y m))

(cl:ensure-generic-function 'local_yaw-val :lambda-list '(m))
(cl:defmethod local_yaw-val ((m <udp_msg_TC_Kicker>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:local_yaw-val is deprecated.  Use msg_generate-msg:local_yaw instead.")
  (local_yaw m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <udp_msg_TC_Kicker>) ostream)
  "Serializes a message object of type '<udp_msg_TC_Kicker>"
  (cl:let* ((signed (cl:slot-value msg 'robot_num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'robot_case)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'local_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'local_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'local_yaw)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <udp_msg_TC_Kicker>) istream)
  "Deserializes a message object of type '<udp_msg_TC_Kicker>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'robot_num) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'robot_case) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'local_x) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'local_y) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'local_yaw) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<udp_msg_TC_Kicker>)))
  "Returns string type for a message object of type '<udp_msg_TC_Kicker>"
  "msg_generate/udp_msg_TC_Kicker")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'udp_msg_TC_Kicker)))
  "Returns string type for a message object of type 'udp_msg_TC_Kicker"
  "msg_generate/udp_msg_TC_Kicker")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<udp_msg_TC_Kicker>)))
  "Returns md5sum for a message object of type '<udp_msg_TC_Kicker>"
  "4f5ba7b091b51220f871e749e172c551")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'udp_msg_TC_Kicker)))
  "Returns md5sum for a message object of type 'udp_msg_TC_Kicker"
  "4f5ba7b091b51220f871e749e172c551")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<udp_msg_TC_Kicker>)))
  "Returns full string definition for message of type '<udp_msg_TC_Kicker>"
  (cl:format cl:nil "int64 robot_num~%int64 robot_case~%~%int64 local_x~%int64 local_y ~%int64 local_yaw~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'udp_msg_TC_Kicker)))
  "Returns full string definition for message of type 'udp_msg_TC_Kicker"
  (cl:format cl:nil "int64 robot_num~%int64 robot_case~%~%int64 local_x~%int64 local_y ~%int64 local_yaw~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <udp_msg_TC_Kicker>))
  (cl:+ 0
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <udp_msg_TC_Kicker>))
  "Converts a ROS message object to a list"
  (cl:list 'udp_msg_TC_Kicker
    (cl:cons ':robot_num (robot_num msg))
    (cl:cons ':robot_case (robot_case msg))
    (cl:cons ':local_x (local_x msg))
    (cl:cons ':local_y (local_y msg))
    (cl:cons ':local_yaw (local_yaw msg))
))
