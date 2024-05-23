; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude robocupvision.msg.html

(cl:defclass <robocupvision> (roslisp-msg-protocol:ros-message)
  ((ballX
    :reader ballX
    :initarg :ballX
    :type cl:integer
    :initform 0)
   (ballY
    :reader ballY
    :initarg :ballY
    :type cl:integer
    :initform 0)
   (ballDist
    :reader ballDist
    :initarg :ballDist
    :type cl:integer
    :initform 0)
   (ballTheta
    :reader ballTheta
    :initarg :ballTheta
    :type cl:float
    :initform 0.0))
)

(cl:defclass robocupvision (<robocupvision>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robocupvision>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robocupvision)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<robocupvision> is deprecated: use msg_generate-msg:robocupvision instead.")))

(cl:ensure-generic-function 'ballX-val :lambda-list '(m))
(cl:defmethod ballX-val ((m <robocupvision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ballX-val is deprecated.  Use msg_generate-msg:ballX instead.")
  (ballX m))

(cl:ensure-generic-function 'ballY-val :lambda-list '(m))
(cl:defmethod ballY-val ((m <robocupvision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ballY-val is deprecated.  Use msg_generate-msg:ballY instead.")
  (ballY m))

(cl:ensure-generic-function 'ballDist-val :lambda-list '(m))
(cl:defmethod ballDist-val ((m <robocupvision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ballDist-val is deprecated.  Use msg_generate-msg:ballDist instead.")
  (ballDist m))

(cl:ensure-generic-function 'ballTheta-val :lambda-list '(m))
(cl:defmethod ballTheta-val ((m <robocupvision>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ballTheta-val is deprecated.  Use msg_generate-msg:ballTheta instead.")
  (ballTheta m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robocupvision>) ostream)
  "Serializes a message object of type '<robocupvision>"
  (cl:let* ((signed (cl:slot-value msg 'ballX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ballY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ballDist)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ballTheta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robocupvision>) istream)
  "Deserializes a message object of type '<robocupvision>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ballX) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ballY) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ballDist) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ballTheta) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robocupvision>)))
  "Returns string type for a message object of type '<robocupvision>"
  "msg_generate/robocupvision")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robocupvision)))
  "Returns string type for a message object of type 'robocupvision"
  "msg_generate/robocupvision")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robocupvision>)))
  "Returns md5sum for a message object of type '<robocupvision>"
  "42c32a1bbbff9d4d2593036e1e947112")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robocupvision)))
  "Returns md5sum for a message object of type 'robocupvision"
  "42c32a1bbbff9d4d2593036e1e947112")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robocupvision>)))
  "Returns full string definition for message of type '<robocupvision>"
  (cl:format cl:nil "int64 ballX~%int64 ballY~%int64 ballDist~%float64 ballTheta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robocupvision)))
  "Returns full string definition for message of type 'robocupvision"
  (cl:format cl:nil "int64 ballX~%int64 ballY~%int64 ballDist~%float64 ballTheta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robocupvision>))
  (cl:+ 0
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robocupvision>))
  "Converts a ROS message object to a list"
  (cl:list 'robocupvision
    (cl:cons ':ballX (ballX msg))
    (cl:cons ':ballY (ballY msg))
    (cl:cons ':ballDist (ballDist msg))
    (cl:cons ':ballTheta (ballTheta msg))
))
