; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude udp_msg.msg.html

(cl:defclass <udp_msg> (roslisp-msg-protocol:ros-message)
  ((field_area
    :reader field_area
    :initarg :field_area
    :type cl:integer
    :initform 0)
   (ball_area
    :reader ball_area
    :initarg :ball_area
    :type cl:integer
    :initform 0)
   (robocup_case
    :reader robocup_case
    :initarg :robocup_case
    :type cl:integer
    :initform 0)
   (ballDist
    :reader ballDist
    :initarg :ballDist
    :type cl:float
    :initform 0.0))
)

(cl:defclass udp_msg (<udp_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <udp_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'udp_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<udp_msg> is deprecated: use msg_generate-msg:udp_msg instead.")))

(cl:ensure-generic-function 'field_area-val :lambda-list '(m))
(cl:defmethod field_area-val ((m <udp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:field_area-val is deprecated.  Use msg_generate-msg:field_area instead.")
  (field_area m))

(cl:ensure-generic-function 'ball_area-val :lambda-list '(m))
(cl:defmethod ball_area-val ((m <udp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ball_area-val is deprecated.  Use msg_generate-msg:ball_area instead.")
  (ball_area m))

(cl:ensure-generic-function 'robocup_case-val :lambda-list '(m))
(cl:defmethod robocup_case-val ((m <udp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:robocup_case-val is deprecated.  Use msg_generate-msg:robocup_case instead.")
  (robocup_case m))

(cl:ensure-generic-function 'ballDist-val :lambda-list '(m))
(cl:defmethod ballDist-val ((m <udp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ballDist-val is deprecated.  Use msg_generate-msg:ballDist instead.")
  (ballDist m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <udp_msg>) ostream)
  "Serializes a message object of type '<udp_msg>"
  (cl:let* ((signed (cl:slot-value msg 'field_area)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ball_area)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'robocup_case)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ballDist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <udp_msg>) istream)
  "Deserializes a message object of type '<udp_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'field_area) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ball_area) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'robocup_case) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ballDist) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<udp_msg>)))
  "Returns string type for a message object of type '<udp_msg>"
  "msg_generate/udp_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'udp_msg)))
  "Returns string type for a message object of type 'udp_msg"
  "msg_generate/udp_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<udp_msg>)))
  "Returns md5sum for a message object of type '<udp_msg>"
  "705379b613a1dfa415f111dd5f542624")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'udp_msg)))
  "Returns md5sum for a message object of type 'udp_msg"
  "705379b613a1dfa415f111dd5f542624")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<udp_msg>)))
  "Returns full string definition for message of type '<udp_msg>"
  (cl:format cl:nil "int32 field_area~%int32 ball_area~%int32 robocup_case~%float64 ballDist~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'udp_msg)))
  "Returns full string definition for message of type 'udp_msg"
  (cl:format cl:nil "int32 field_area~%int32 ball_area~%int32 robocup_case~%float64 ballDist~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <udp_msg>))
  (cl:+ 0
     4
     4
     4
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <udp_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'udp_msg
    (cl:cons ':field_area (field_area msg))
    (cl:cons ':ball_area (ball_area msg))
    (cl:cons ':robocup_case (robocup_case msg))
    (cl:cons ':ballDist (ballDist msg))
))
