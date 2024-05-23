; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude pan_tilt_msg.msg.html

(cl:defclass <pan_tilt_msg> (roslisp-msg-protocol:ros-message)
  ((waist_flag
    :reader waist_flag
    :initarg :waist_flag
    :type cl:integer
    :initform 0)
   (Angle_Yaw
    :reader Angle_Yaw
    :initarg :Angle_Yaw
    :type cl:float
    :initform 0.0)
   (Angle_Pitch
    :reader Angle_Pitch
    :initarg :Angle_Pitch
    :type cl:float
    :initform 0.0))
)

(cl:defclass pan_tilt_msg (<pan_tilt_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pan_tilt_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pan_tilt_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<pan_tilt_msg> is deprecated: use msg_generate-msg:pan_tilt_msg instead.")))

(cl:ensure-generic-function 'waist_flag-val :lambda-list '(m))
(cl:defmethod waist_flag-val ((m <pan_tilt_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:waist_flag-val is deprecated.  Use msg_generate-msg:waist_flag instead.")
  (waist_flag m))

(cl:ensure-generic-function 'Angle_Yaw-val :lambda-list '(m))
(cl:defmethod Angle_Yaw-val ((m <pan_tilt_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Angle_Yaw-val is deprecated.  Use msg_generate-msg:Angle_Yaw instead.")
  (Angle_Yaw m))

(cl:ensure-generic-function 'Angle_Pitch-val :lambda-list '(m))
(cl:defmethod Angle_Pitch-val ((m <pan_tilt_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Angle_Pitch-val is deprecated.  Use msg_generate-msg:Angle_Pitch instead.")
  (Angle_Pitch m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pan_tilt_msg>) ostream)
  "Serializes a message object of type '<pan_tilt_msg>"
  (cl:let* ((signed (cl:slot-value msg 'waist_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Angle_Yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Angle_Pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pan_tilt_msg>) istream)
  "Deserializes a message object of type '<pan_tilt_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'waist_flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Angle_Yaw) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Angle_Pitch) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pan_tilt_msg>)))
  "Returns string type for a message object of type '<pan_tilt_msg>"
  "msg_generate/pan_tilt_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pan_tilt_msg)))
  "Returns string type for a message object of type 'pan_tilt_msg"
  "msg_generate/pan_tilt_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pan_tilt_msg>)))
  "Returns md5sum for a message object of type '<pan_tilt_msg>"
  "611b91cd650b11bf3bb556113e5f1029")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pan_tilt_msg)))
  "Returns md5sum for a message object of type 'pan_tilt_msg"
  "611b91cd650b11bf3bb556113e5f1029")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pan_tilt_msg>)))
  "Returns full string definition for message of type '<pan_tilt_msg>"
  (cl:format cl:nil "int32 waist_flag~%~%float64 Angle_Yaw~%float64 Angle_Pitch~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pan_tilt_msg)))
  "Returns full string definition for message of type 'pan_tilt_msg"
  (cl:format cl:nil "int32 waist_flag~%~%float64 Angle_Yaw~%float64 Angle_Pitch~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pan_tilt_msg>))
  (cl:+ 0
     4
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pan_tilt_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'pan_tilt_msg
    (cl:cons ':waist_flag (waist_flag msg))
    (cl:cons ':Angle_Yaw (Angle_Yaw msg))
    (cl:cons ':Angle_Pitch (Angle_Pitch msg))
))
