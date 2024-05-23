; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude master2vision_msg.msg.html

(cl:defclass <master2vision_msg> (roslisp-msg-protocol:ros-message)
  ((TILT
    :reader TILT
    :initarg :TILT
    :type cl:float
    :initform 0.0)
   (PAN
    :reader PAN
    :initarg :PAN
    :type cl:float
    :initform 0.0))
)

(cl:defclass master2vision_msg (<master2vision_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <master2vision_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'master2vision_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<master2vision_msg> is deprecated: use msg_generate-msg:master2vision_msg instead.")))

(cl:ensure-generic-function 'TILT-val :lambda-list '(m))
(cl:defmethod TILT-val ((m <master2vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:TILT-val is deprecated.  Use msg_generate-msg:TILT instead.")
  (TILT m))

(cl:ensure-generic-function 'PAN-val :lambda-list '(m))
(cl:defmethod PAN-val ((m <master2vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:PAN-val is deprecated.  Use msg_generate-msg:PAN instead.")
  (PAN m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <master2vision_msg>) ostream)
  "Serializes a message object of type '<master2vision_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'TILT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'PAN))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <master2vision_msg>) istream)
  "Deserializes a message object of type '<master2vision_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'TILT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'PAN) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<master2vision_msg>)))
  "Returns string type for a message object of type '<master2vision_msg>"
  "msg_generate/master2vision_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'master2vision_msg)))
  "Returns string type for a message object of type 'master2vision_msg"
  "msg_generate/master2vision_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<master2vision_msg>)))
  "Returns md5sum for a message object of type '<master2vision_msg>"
  "8e3fffe76719ba65b10a2f461e54333b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'master2vision_msg)))
  "Returns md5sum for a message object of type 'master2vision_msg"
  "8e3fffe76719ba65b10a2f461e54333b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<master2vision_msg>)))
  "Returns full string definition for message of type '<master2vision_msg>"
  (cl:format cl:nil "float64 TILT~%float64 PAN~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'master2vision_msg)))
  "Returns full string definition for message of type 'master2vision_msg"
  (cl:format cl:nil "float64 TILT~%float64 PAN~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <master2vision_msg>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <master2vision_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'master2vision_msg
    (cl:cons ':TILT (TILT msg))
    (cl:cons ':PAN (PAN msg))
))
