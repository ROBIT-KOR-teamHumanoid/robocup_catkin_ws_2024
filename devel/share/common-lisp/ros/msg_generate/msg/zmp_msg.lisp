; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude zmp_msg.msg.html

(cl:defclass <zmp_msg> (roslisp-msg-protocol:ros-message)
  ((Left_X_zmp
    :reader Left_X_zmp
    :initarg :Left_X_zmp
    :type cl:float
    :initform 0.0)
   (Left_Y_zmp
    :reader Left_Y_zmp
    :initarg :Left_Y_zmp
    :type cl:float
    :initform 0.0)
   (Right_X_zmp
    :reader Right_X_zmp
    :initarg :Right_X_zmp
    :type cl:float
    :initform 0.0)
   (Right_Y_zmp
    :reader Right_Y_zmp
    :initarg :Right_Y_zmp
    :type cl:float
    :initform 0.0)
   (Total_X_zmp
    :reader Total_X_zmp
    :initarg :Total_X_zmp
    :type cl:float
    :initform 0.0)
   (Total_Y_zmp
    :reader Total_Y_zmp
    :initarg :Total_Y_zmp
    :type cl:float
    :initform 0.0)
   (Left_Foot
    :reader Left_Foot
    :initarg :Left_Foot
    :type cl:boolean
    :initform cl:nil)
   (Right_Foot
    :reader Right_Foot
    :initarg :Right_Foot
    :type cl:boolean
    :initform cl:nil)
   (Both_Feet
    :reader Both_Feet
    :initarg :Both_Feet
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass zmp_msg (<zmp_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <zmp_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'zmp_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<zmp_msg> is deprecated: use msg_generate-msg:zmp_msg instead.")))

(cl:ensure-generic-function 'Left_X_zmp-val :lambda-list '(m))
(cl:defmethod Left_X_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_X_zmp-val is deprecated.  Use msg_generate-msg:Left_X_zmp instead.")
  (Left_X_zmp m))

(cl:ensure-generic-function 'Left_Y_zmp-val :lambda-list '(m))
(cl:defmethod Left_Y_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_Y_zmp-val is deprecated.  Use msg_generate-msg:Left_Y_zmp instead.")
  (Left_Y_zmp m))

(cl:ensure-generic-function 'Right_X_zmp-val :lambda-list '(m))
(cl:defmethod Right_X_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_X_zmp-val is deprecated.  Use msg_generate-msg:Right_X_zmp instead.")
  (Right_X_zmp m))

(cl:ensure-generic-function 'Right_Y_zmp-val :lambda-list '(m))
(cl:defmethod Right_Y_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_Y_zmp-val is deprecated.  Use msg_generate-msg:Right_Y_zmp instead.")
  (Right_Y_zmp m))

(cl:ensure-generic-function 'Total_X_zmp-val :lambda-list '(m))
(cl:defmethod Total_X_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Total_X_zmp-val is deprecated.  Use msg_generate-msg:Total_X_zmp instead.")
  (Total_X_zmp m))

(cl:ensure-generic-function 'Total_Y_zmp-val :lambda-list '(m))
(cl:defmethod Total_Y_zmp-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Total_Y_zmp-val is deprecated.  Use msg_generate-msg:Total_Y_zmp instead.")
  (Total_Y_zmp m))

(cl:ensure-generic-function 'Left_Foot-val :lambda-list '(m))
(cl:defmethod Left_Foot-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Left_Foot-val is deprecated.  Use msg_generate-msg:Left_Foot instead.")
  (Left_Foot m))

(cl:ensure-generic-function 'Right_Foot-val :lambda-list '(m))
(cl:defmethod Right_Foot-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Right_Foot-val is deprecated.  Use msg_generate-msg:Right_Foot instead.")
  (Right_Foot m))

(cl:ensure-generic-function 'Both_Feet-val :lambda-list '(m))
(cl:defmethod Both_Feet-val ((m <zmp_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Both_Feet-val is deprecated.  Use msg_generate-msg:Both_Feet instead.")
  (Both_Feet m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <zmp_msg>) ostream)
  "Serializes a message object of type '<zmp_msg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Left_X_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Left_Y_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Right_X_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Right_Y_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Total_X_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Total_Y_zmp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Left_Foot) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Right_Foot) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Both_Feet) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <zmp_msg>) istream)
  "Deserializes a message object of type '<zmp_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_X_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Left_Y_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_X_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Right_Y_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Total_X_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Total_Y_zmp) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'Left_Foot) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Right_Foot) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Both_Feet) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<zmp_msg>)))
  "Returns string type for a message object of type '<zmp_msg>"
  "msg_generate/zmp_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'zmp_msg)))
  "Returns string type for a message object of type 'zmp_msg"
  "msg_generate/zmp_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<zmp_msg>)))
  "Returns md5sum for a message object of type '<zmp_msg>"
  "b6dd8aae25ccfd762514817678c236ea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'zmp_msg)))
  "Returns md5sum for a message object of type 'zmp_msg"
  "b6dd8aae25ccfd762514817678c236ea")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<zmp_msg>)))
  "Returns full string definition for message of type '<zmp_msg>"
  (cl:format cl:nil "float64 Left_X_zmp~%float64 Left_Y_zmp~%float64 Right_X_zmp~%float64 Right_Y_zmp~%float64 Total_X_zmp~%float64 Total_Y_zmp~%bool Left_Foot~%bool Right_Foot~%bool Both_Feet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'zmp_msg)))
  "Returns full string definition for message of type 'zmp_msg"
  (cl:format cl:nil "float64 Left_X_zmp~%float64 Left_Y_zmp~%float64 Right_X_zmp~%float64 Right_Y_zmp~%float64 Total_X_zmp~%float64 Total_Y_zmp~%bool Left_Foot~%bool Right_Foot~%bool Both_Feet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <zmp_msg>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <zmp_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'zmp_msg
    (cl:cons ':Left_X_zmp (Left_X_zmp msg))
    (cl:cons ':Left_Y_zmp (Left_Y_zmp msg))
    (cl:cons ':Right_X_zmp (Right_X_zmp msg))
    (cl:cons ':Right_Y_zmp (Right_Y_zmp msg))
    (cl:cons ':Total_X_zmp (Total_X_zmp msg))
    (cl:cons ':Total_Y_zmp (Total_Y_zmp msg))
    (cl:cons ':Left_Foot (Left_Foot msg))
    (cl:cons ':Right_Foot (Right_Foot msg))
    (cl:cons ':Both_Feet (Both_Feet msg))
))
