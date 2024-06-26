; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude master_2_robocup_vision24.msg.html

(cl:defclass <master_2_robocup_vision24> (roslisp-msg-protocol:ros-message)
  ((Scan_Mode
    :reader Scan_Mode
    :initarg :Scan_Mode
    :type cl:integer
    :initform 0)
   (PAN
    :reader PAN
    :initarg :PAN
    :type cl:float
    :initform 0.0)
   (TILT
    :reader TILT
    :initarg :TILT
    :type cl:float
    :initform 0.0))
)

(cl:defclass master_2_robocup_vision24 (<master_2_robocup_vision24>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <master_2_robocup_vision24>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'master_2_robocup_vision24)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<master_2_robocup_vision24> is deprecated: use msg_generate-msg:master_2_robocup_vision24 instead.")))

(cl:ensure-generic-function 'Scan_Mode-val :lambda-list '(m))
(cl:defmethod Scan_Mode-val ((m <master_2_robocup_vision24>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Scan_Mode-val is deprecated.  Use msg_generate-msg:Scan_Mode instead.")
  (Scan_Mode m))

(cl:ensure-generic-function 'PAN-val :lambda-list '(m))
(cl:defmethod PAN-val ((m <master_2_robocup_vision24>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:PAN-val is deprecated.  Use msg_generate-msg:PAN instead.")
  (PAN m))

(cl:ensure-generic-function 'TILT-val :lambda-list '(m))
(cl:defmethod TILT-val ((m <master_2_robocup_vision24>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:TILT-val is deprecated.  Use msg_generate-msg:TILT instead.")
  (TILT m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <master_2_robocup_vision24>) ostream)
  "Serializes a message object of type '<master_2_robocup_vision24>"
  (cl:let* ((signed (cl:slot-value msg 'Scan_Mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'PAN))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'TILT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <master_2_robocup_vision24>) istream)
  "Deserializes a message object of type '<master_2_robocup_vision24>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Scan_Mode) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<master_2_robocup_vision24>)))
  "Returns string type for a message object of type '<master_2_robocup_vision24>"
  "msg_generate/master_2_robocup_vision24")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'master_2_robocup_vision24)))
  "Returns string type for a message object of type 'master_2_robocup_vision24"
  "msg_generate/master_2_robocup_vision24")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<master_2_robocup_vision24>)))
  "Returns md5sum for a message object of type '<master_2_robocup_vision24>"
  "b5fe0eb4136cf0ddbbf95ffa2d2e7754")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'master_2_robocup_vision24)))
  "Returns md5sum for a message object of type 'master_2_robocup_vision24"
  "b5fe0eb4136cf0ddbbf95ffa2d2e7754")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<master_2_robocup_vision24>)))
  "Returns full string definition for message of type '<master_2_robocup_vision24>"
  (cl:format cl:nil "int64 Scan_Mode~%float64 PAN~%float64 TILT~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'master_2_robocup_vision24)))
  "Returns full string definition for message of type 'master_2_robocup_vision24"
  (cl:format cl:nil "int64 Scan_Mode~%float64 PAN~%float64 TILT~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <master_2_robocup_vision24>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <master_2_robocup_vision24>))
  "Converts a ROS message object to a list"
  (cl:list 'master_2_robocup_vision24
    (cl:cons ':Scan_Mode (Scan_Mode msg))
    (cl:cons ':PAN (PAN msg))
    (cl:cons ':TILT (TILT msg))
))
