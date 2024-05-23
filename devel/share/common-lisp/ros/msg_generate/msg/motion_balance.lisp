; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude motion_balance.msg.html

(cl:defclass <motion_balance> (roslisp-msg-protocol:ros-message)
  ((Left_10
    :reader Left_10
    :initarg :Left_10
    :type cl:float
    :initform 0.0)
   (Right_11
    :reader Right_11
    :initarg :Right_11
    :type cl:float
    :initform 0.0)
   (Left_14
    :reader Left_14
    :initarg :Left_14
    :type cl:float
    :initform 0.0)
   (Right_15
    :reader Right_15
    :initarg :Right_15
    :type cl:float
    :initform 0.0)
   (Left_16
    :reader Left_16
    :initarg :Left_16
    :type cl:float
    :initform 0.0)
   (Right_17
    :reader Right_17
    :initarg :Right_17
    :type cl:float
    :initform 0.0)
   (Left_18
    :reader Left_18
    :initarg :Left_18
    :type cl:float
    :initform 0.0)
   (Right_19
    :reader Right_19
    :initarg :Right_19
    :type cl:float
    :initform 0.0)
   (Left_20
    :reader Left_20
    :initarg :Left_20
    :type cl:float
    :initform 0.0)
   (Right_21
    :reader Right_21
    :initarg :Right_21
    :type cl:float
    :initform 0.0)
   (support_L
    :reader support_L
    :initarg :support_L
    :type cl:boolean
    :initform cl:nil)
   (support_R
    :reader support_R
    :initarg :support_R
    :type cl:boolean
    :initform cl:nil)
   (support_B
    :reader support_B
    :initarg :support_B
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass motion_balance (<motion_balance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motion_balance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motion_balance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<motion_balance> is deprecated: use msg_generate-msg:motion_balance instead.")))

(cl:ensure-generic-function 'Left_10-val :lambda-list '(m))
(cl:defmethod Left_10-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_10-val is deprecated.  Use msg_generate-msg:Left_10 instead.")
  (Left_10 m))

(cl:ensure-generic-function 'Right_11-val :lambda-list '(m))
(cl:defmethod Right_11-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_11-val is deprecated.  Use msg_generate-msg:Right_11 instead.")
  (Right_11 m))

(cl:ensure-generic-function 'Left_14-val :lambda-list '(m))
(cl:defmethod Left_14-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_14-val is deprecated.  Use msg_generate-msg:Left_14 instead.")
  (Left_14 m))

(cl:ensure-generic-function 'Right_15-val :lambda-list '(m))
(cl:defmethod Right_15-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_15-val is deprecated.  Use msg_generate-msg:Right_15 instead.")
  (Right_15 m))

(cl:ensure-generic-function 'Left_16-val :lambda-list '(m))
(cl:defmethod Left_16-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_16-val is deprecated.  Use msg_generate-msg:Left_16 instead.")
  (Left_16 m))

(cl:ensure-generic-function 'Right_17-val :lambda-list '(m))
(cl:defmethod Right_17-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_17-val is deprecated.  Use msg_generate-msg:Right_17 instead.")
  (Right_17 m))

(cl:ensure-generic-function 'Left_18-val :lambda-list '(m))
(cl:defmethod Left_18-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_18-val is deprecated.  Use msg_generate-msg:Left_18 instead.")
  (Left_18 m))

(cl:ensure-generic-function 'Right_19-val :lambda-list '(m))
(cl:defmethod Right_19-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_19-val is deprecated.  Use msg_generate-msg:Right_19 instead.")
  (Right_19 m))

(cl:ensure-generic-function 'Left_20-val :lambda-list '(m))
(cl:defmethod Left_20-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_20-val is deprecated.  Use msg_generate-msg:Left_20 instead.")
  (Left_20 m))

(cl:ensure-generic-function 'Right_21-val :lambda-list '(m))
(cl:defmethod Right_21-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_21-val is deprecated.  Use msg_generate-msg:Right_21 instead.")
  (Right_21 m))

(cl:ensure-generic-function 'support_L-val :lambda-list '(m))
(cl:defmethod support_L-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:support_L-val is deprecated.  Use msg_generate-msg:support_L instead.")
  (support_L m))

(cl:ensure-generic-function 'support_R-val :lambda-list '(m))
(cl:defmethod support_R-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:support_R-val is deprecated.  Use msg_generate-msg:support_R instead.")
  (support_R m))

(cl:ensure-generic-function 'support_B-val :lambda-list '(m))
(cl:defmethod support_B-val ((m <motion_balance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:support_B-val is deprecated.  Use msg_generate-msg:support_B instead.")
  (support_B m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motion_balance>) ostream)
  "Serializes a message object of type '<motion_balance>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Left_10))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Right_11))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Left_14))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Right_15))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Left_16))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Right_17))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Left_18))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Right_19))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Left_20))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Right_21))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'support_L) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'support_R) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'support_B) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motion_balance>) istream)
  "Deserializes a message object of type '<motion_balance>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_10) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_11) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_14) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_15) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_16) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_17) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_18) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_19) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_20) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_21) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'support_L) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'support_R) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'support_B) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motion_balance>)))
  "Returns string type for a message object of type '<motion_balance>"
  "msg_generate/motion_balance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motion_balance)))
  "Returns string type for a message object of type 'motion_balance"
  "msg_generate/motion_balance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motion_balance>)))
  "Returns md5sum for a message object of type '<motion_balance>"
  "03d17ac032478d225abd4895f2c60b7c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motion_balance)))
  "Returns md5sum for a message object of type 'motion_balance"
  "03d17ac032478d225abd4895f2c60b7c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motion_balance>)))
  "Returns full string definition for message of type '<motion_balance>"
  (cl:format cl:nil "float32 Left_10~%float32 Right_11~%float32 Left_14~%float32 Right_15~%float32 Left_16~%float32 Right_17~%float32 Left_18~%float32 Right_19~%float32 Left_20~%float32 Right_21~%~%bool support_L~%bool support_R~%bool support_B~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motion_balance)))
  "Returns full string definition for message of type 'motion_balance"
  (cl:format cl:nil "float32 Left_10~%float32 Right_11~%float32 Left_14~%float32 Right_15~%float32 Left_16~%float32 Right_17~%float32 Left_18~%float32 Right_19~%float32 Left_20~%float32 Right_21~%~%bool support_L~%bool support_R~%bool support_B~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motion_balance>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motion_balance>))
  "Converts a ROS message object to a list"
  (cl:list 'motion_balance
    (cl:cons ':Left_10 (Left_10 msg))
    (cl:cons ':Right_11 (Right_11 msg))
    (cl:cons ':Left_14 (Left_14 msg))
    (cl:cons ':Right_15 (Right_15 msg))
    (cl:cons ':Left_16 (Left_16 msg))
    (cl:cons ':Right_17 (Right_17 msg))
    (cl:cons ':Left_18 (Left_18 msg))
    (cl:cons ':Right_19 (Right_19 msg))
    (cl:cons ':Left_20 (Left_20 msg))
    (cl:cons ':Right_21 (Right_21 msg))
    (cl:cons ':support_L (support_L msg))
    (cl:cons ':support_R (support_R msg))
    (cl:cons ':support_B (support_B msg))
))
