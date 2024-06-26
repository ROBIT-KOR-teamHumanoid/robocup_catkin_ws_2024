; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude HSV.msg.html

(cl:defclass <HSV> (roslisp-msg-protocol:ros-message)
  ((red1_dis
    :reader red1_dis
    :initarg :red1_dis
    :type cl:float
    :initform 0.0)
   (red1_the
    :reader red1_the
    :initarg :red1_the
    :type cl:float
    :initform 0.0)
   (red2_dis
    :reader red2_dis
    :initarg :red2_dis
    :type cl:float
    :initform 0.0)
   (red2_the
    :reader red2_the
    :initarg :red2_the
    :type cl:float
    :initform 0.0)
   (blue1_dis
    :reader blue1_dis
    :initarg :blue1_dis
    :type cl:float
    :initform 0.0)
   (blue1_the
    :reader blue1_the
    :initarg :blue1_the
    :type cl:float
    :initform 0.0)
   (blue2_dis
    :reader blue2_dis
    :initarg :blue2_dis
    :type cl:float
    :initform 0.0)
   (blue2_the
    :reader blue2_the
    :initarg :blue2_the
    :type cl:float
    :initform 0.0))
)

(cl:defclass HSV (<HSV>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HSV>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HSV)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<HSV> is deprecated: use msg_generate-msg:HSV instead.")))

(cl:ensure-generic-function 'red1_dis-val :lambda-list '(m))
(cl:defmethod red1_dis-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:red1_dis-val is deprecated.  Use msg_generate-msg:red1_dis instead.")
  (red1_dis m))

(cl:ensure-generic-function 'red1_the-val :lambda-list '(m))
(cl:defmethod red1_the-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:red1_the-val is deprecated.  Use msg_generate-msg:red1_the instead.")
  (red1_the m))

(cl:ensure-generic-function 'red2_dis-val :lambda-list '(m))
(cl:defmethod red2_dis-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:red2_dis-val is deprecated.  Use msg_generate-msg:red2_dis instead.")
  (red2_dis m))

(cl:ensure-generic-function 'red2_the-val :lambda-list '(m))
(cl:defmethod red2_the-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:red2_the-val is deprecated.  Use msg_generate-msg:red2_the instead.")
  (red2_the m))

(cl:ensure-generic-function 'blue1_dis-val :lambda-list '(m))
(cl:defmethod blue1_dis-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:blue1_dis-val is deprecated.  Use msg_generate-msg:blue1_dis instead.")
  (blue1_dis m))

(cl:ensure-generic-function 'blue1_the-val :lambda-list '(m))
(cl:defmethod blue1_the-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:blue1_the-val is deprecated.  Use msg_generate-msg:blue1_the instead.")
  (blue1_the m))

(cl:ensure-generic-function 'blue2_dis-val :lambda-list '(m))
(cl:defmethod blue2_dis-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:blue2_dis-val is deprecated.  Use msg_generate-msg:blue2_dis instead.")
  (blue2_dis m))

(cl:ensure-generic-function 'blue2_the-val :lambda-list '(m))
(cl:defmethod blue2_the-val ((m <HSV>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:blue2_the-val is deprecated.  Use msg_generate-msg:blue2_the instead.")
  (blue2_the m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HSV>) ostream)
  "Serializes a message object of type '<HSV>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'red1_dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'red1_the))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'red2_dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'red2_the))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'blue1_dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'blue1_the))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'blue2_dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'blue2_the))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HSV>) istream)
  "Deserializes a message object of type '<HSV>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'red1_dis) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'red1_the) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'red2_dis) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'red2_the) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'blue1_dis) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'blue1_the) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'blue2_dis) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'blue2_the) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HSV>)))
  "Returns string type for a message object of type '<HSV>"
  "msg_generate/HSV")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HSV)))
  "Returns string type for a message object of type 'HSV"
  "msg_generate/HSV")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HSV>)))
  "Returns md5sum for a message object of type '<HSV>"
  "5e59624369bde37201fa1c7dfe803e91")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HSV)))
  "Returns md5sum for a message object of type 'HSV"
  "5e59624369bde37201fa1c7dfe803e91")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HSV>)))
  "Returns full string definition for message of type '<HSV>"
  (cl:format cl:nil "float64 red1_dis~%float64 red1_the~%float64 red2_dis~%float64 red2_the~%float64 blue1_dis~%float64 blue1_the~%float64 blue2_dis~%float64 blue2_the~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HSV)))
  "Returns full string definition for message of type 'HSV"
  (cl:format cl:nil "float64 red1_dis~%float64 red1_the~%float64 red2_dis~%float64 red2_the~%float64 blue1_dis~%float64 blue1_the~%float64 blue2_dis~%float64 blue2_the~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HSV>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HSV>))
  "Converts a ROS message object to a list"
  (cl:list 'HSV
    (cl:cons ':red1_dis (red1_dis msg))
    (cl:cons ':red1_the (red1_the msg))
    (cl:cons ':red2_dis (red2_dis msg))
    (cl:cons ':red2_the (red2_the msg))
    (cl:cons ':blue1_dis (blue1_dis msg))
    (cl:cons ':blue1_the (blue1_the msg))
    (cl:cons ':blue2_dis (blue2_dis msg))
    (cl:cons ':blue2_the (blue2_the msg))
))
