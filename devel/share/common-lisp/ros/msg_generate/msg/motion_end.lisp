; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude motion_end.msg.html

(cl:defclass <motion_end> (roslisp-msg-protocol:ros-message)
  ((motion_end
    :reader motion_end
    :initarg :motion_end
    :type cl:integer
    :initform 0)
   (motion_ing
    :reader motion_ing
    :initarg :motion_ing
    :type cl:integer
    :initform 0)
   (motion_start_ing
    :reader motion_start_ing
    :initarg :motion_start_ing
    :type cl:integer
    :initform 0)
   (motion_end_ing
    :reader motion_end_ing
    :initarg :motion_end_ing
    :type cl:integer
    :initform 0)
   (motion_num
    :reader motion_num
    :initarg :motion_num
    :type cl:integer
    :initform 0))
)

(cl:defclass motion_end (<motion_end>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motion_end>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motion_end)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<motion_end> is deprecated: use msg_generate-msg:motion_end instead.")))

(cl:ensure-generic-function 'motion_end-val :lambda-list '(m))
(cl:defmethod motion_end-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_end-val is deprecated.  Use msg_generate-msg:motion_end instead.")
  (motion_end m))

(cl:ensure-generic-function 'motion_ing-val :lambda-list '(m))
(cl:defmethod motion_ing-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_ing-val is deprecated.  Use msg_generate-msg:motion_ing instead.")
  (motion_ing m))

(cl:ensure-generic-function 'motion_start_ing-val :lambda-list '(m))
(cl:defmethod motion_start_ing-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_start_ing-val is deprecated.  Use msg_generate-msg:motion_start_ing instead.")
  (motion_start_ing m))

(cl:ensure-generic-function 'motion_end_ing-val :lambda-list '(m))
(cl:defmethod motion_end_ing-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_end_ing-val is deprecated.  Use msg_generate-msg:motion_end_ing instead.")
  (motion_end_ing m))

(cl:ensure-generic-function 'motion_num-val :lambda-list '(m))
(cl:defmethod motion_num-val ((m <motion_end>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_num-val is deprecated.  Use msg_generate-msg:motion_num instead.")
  (motion_num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motion_end>) ostream)
  "Serializes a message object of type '<motion_end>"
  (cl:let* ((signed (cl:slot-value msg 'motion_end)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motion_ing)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motion_start_ing)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motion_end_ing)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motion_num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motion_end>) istream)
  "Deserializes a message object of type '<motion_end>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_end) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_ing) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_start_ing) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_end_ing) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motion_num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motion_end>)))
  "Returns string type for a message object of type '<motion_end>"
  "msg_generate/motion_end")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motion_end)))
  "Returns string type for a message object of type 'motion_end"
  "msg_generate/motion_end")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motion_end>)))
  "Returns md5sum for a message object of type '<motion_end>"
  "25f699e9aaf9930abdbe2aaa9b5b0063")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motion_end)))
  "Returns md5sum for a message object of type 'motion_end"
  "25f699e9aaf9930abdbe2aaa9b5b0063")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motion_end>)))
  "Returns full string definition for message of type '<motion_end>"
  (cl:format cl:nil "int32 motion_end~%int32 motion_ing~%int32 motion_start_ing~%int32 motion_end_ing~%~%int32 motion_num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motion_end)))
  "Returns full string definition for message of type 'motion_end"
  (cl:format cl:nil "int32 motion_end~%int32 motion_ing~%int32 motion_start_ing~%int32 motion_end_ing~%~%int32 motion_num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motion_end>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motion_end>))
  "Converts a ROS message object to a list"
  (cl:list 'motion_end
    (cl:cons ':motion_end (motion_end msg))
    (cl:cons ':motion_ing (motion_ing msg))
    (cl:cons ':motion_start_ing (motion_start_ing msg))
    (cl:cons ':motion_end_ing (motion_end_ing msg))
    (cl:cons ':motion_num (motion_num msg))
))
