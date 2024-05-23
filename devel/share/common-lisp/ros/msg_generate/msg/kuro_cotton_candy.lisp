; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude kuro_cotton_candy.msg.html

(cl:defclass <kuro_cotton_candy> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:boolean
    :initform cl:nil)
   (start
    :reader start
    :initarg :start
    :type cl:boolean
    :initform cl:nil)
   (stop
    :reader stop
    :initarg :stop
    :type cl:boolean
    :initform cl:nil)
   (timer
    :reader timer
    :initarg :timer
    :type cl:float
    :initform 0.0))
)

(cl:defclass kuro_cotton_candy (<kuro_cotton_candy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <kuro_cotton_candy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'kuro_cotton_candy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<kuro_cotton_candy> is deprecated: use msg_generate-msg:kuro_cotton_candy instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <kuro_cotton_candy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:ready-val is deprecated.  Use msg_generate-msg:ready instead.")
  (ready m))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <kuro_cotton_candy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:start-val is deprecated.  Use msg_generate-msg:start instead.")
  (start m))

(cl:ensure-generic-function 'stop-val :lambda-list '(m))
(cl:defmethod stop-val ((m <kuro_cotton_candy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:stop-val is deprecated.  Use msg_generate-msg:stop instead.")
  (stop m))

(cl:ensure-generic-function 'timer-val :lambda-list '(m))
(cl:defmethod timer-val ((m <kuro_cotton_candy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:timer-val is deprecated.  Use msg_generate-msg:timer instead.")
  (timer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <kuro_cotton_candy>) ostream)
  "Serializes a message object of type '<kuro_cotton_candy>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ready) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'start) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'stop) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'timer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <kuro_cotton_candy>) istream)
  "Deserializes a message object of type '<kuro_cotton_candy>"
    (cl:setf (cl:slot-value msg 'ready) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'start) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'stop) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'timer) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<kuro_cotton_candy>)))
  "Returns string type for a message object of type '<kuro_cotton_candy>"
  "msg_generate/kuro_cotton_candy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'kuro_cotton_candy)))
  "Returns string type for a message object of type 'kuro_cotton_candy"
  "msg_generate/kuro_cotton_candy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<kuro_cotton_candy>)))
  "Returns md5sum for a message object of type '<kuro_cotton_candy>"
  "d9f3ac83b00612092e5b577721e3b2ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'kuro_cotton_candy)))
  "Returns md5sum for a message object of type 'kuro_cotton_candy"
  "d9f3ac83b00612092e5b577721e3b2ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<kuro_cotton_candy>)))
  "Returns full string definition for message of type '<kuro_cotton_candy>"
  (cl:format cl:nil "bool ready~%bool start~%bool stop~%float64 timer ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'kuro_cotton_candy)))
  "Returns full string definition for message of type 'kuro_cotton_candy"
  (cl:format cl:nil "bool ready~%bool start~%bool stop~%float64 timer ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <kuro_cotton_candy>))
  (cl:+ 0
     1
     1
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <kuro_cotton_candy>))
  "Converts a ROS message object to a list"
  (cl:list 'kuro_cotton_candy
    (cl:cons ':ready (ready msg))
    (cl:cons ':start (start msg))
    (cl:cons ':stop (stop msg))
    (cl:cons ':timer (timer msg))
))
