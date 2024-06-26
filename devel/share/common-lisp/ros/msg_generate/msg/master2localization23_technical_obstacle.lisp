; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude master2localization23_technical_obstacle.msg.html

(cl:defclass <master2localization23_technical_obstacle> (roslisp-msg-protocol:ros-message)
  ((sector
    :reader sector
    :initarg :sector
    :type cl:integer
    :initform 0)
   (obs_1
    :reader obs_1
    :initarg :obs_1
    :type cl:integer
    :initform 0)
   (obs_2
    :reader obs_2
    :initarg :obs_2
    :type cl:integer
    :initform 0))
)

(cl:defclass master2localization23_technical_obstacle (<master2localization23_technical_obstacle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <master2localization23_technical_obstacle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'master2localization23_technical_obstacle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<master2localization23_technical_obstacle> is deprecated: use msg_generate-msg:master2localization23_technical_obstacle instead.")))

(cl:ensure-generic-function 'sector-val :lambda-list '(m))
(cl:defmethod sector-val ((m <master2localization23_technical_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:sector-val is deprecated.  Use msg_generate-msg:sector instead.")
  (sector m))

(cl:ensure-generic-function 'obs_1-val :lambda-list '(m))
(cl:defmethod obs_1-val ((m <master2localization23_technical_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:obs_1-val is deprecated.  Use msg_generate-msg:obs_1 instead.")
  (obs_1 m))

(cl:ensure-generic-function 'obs_2-val :lambda-list '(m))
(cl:defmethod obs_2-val ((m <master2localization23_technical_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:obs_2-val is deprecated.  Use msg_generate-msg:obs_2 instead.")
  (obs_2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <master2localization23_technical_obstacle>) ostream)
  "Serializes a message object of type '<master2localization23_technical_obstacle>"
  (cl:let* ((signed (cl:slot-value msg 'sector)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obs_2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <master2localization23_technical_obstacle>) istream)
  "Deserializes a message object of type '<master2localization23_technical_obstacle>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sector) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_1) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obs_2) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<master2localization23_technical_obstacle>)))
  "Returns string type for a message object of type '<master2localization23_technical_obstacle>"
  "msg_generate/master2localization23_technical_obstacle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'master2localization23_technical_obstacle)))
  "Returns string type for a message object of type 'master2localization23_technical_obstacle"
  "msg_generate/master2localization23_technical_obstacle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<master2localization23_technical_obstacle>)))
  "Returns md5sum for a message object of type '<master2localization23_technical_obstacle>"
  "84cbbda57e228d1e1a9085de32393705")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'master2localization23_technical_obstacle)))
  "Returns md5sum for a message object of type 'master2localization23_technical_obstacle"
  "84cbbda57e228d1e1a9085de32393705")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<master2localization23_technical_obstacle>)))
  "Returns full string definition for message of type '<master2localization23_technical_obstacle>"
  (cl:format cl:nil "int64 sector~%int64 obs_1~%int64 obs_2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'master2localization23_technical_obstacle)))
  "Returns full string definition for message of type 'master2localization23_technical_obstacle"
  (cl:format cl:nil "int64 sector~%int64 obs_1~%int64 obs_2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <master2localization23_technical_obstacle>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <master2localization23_technical_obstacle>))
  "Converts a ROS message object to a list"
  (cl:list 'master2localization23_technical_obstacle
    (cl:cons ':sector (sector msg))
    (cl:cons ':obs_1 (obs_1 msg))
    (cl:cons ':obs_2 (obs_2 msg))
))
