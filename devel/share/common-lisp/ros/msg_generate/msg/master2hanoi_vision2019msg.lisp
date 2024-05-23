; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude master2hanoi_vision2019msg.msg.html

(cl:defclass <master2hanoi_vision2019msg> (roslisp-msg-protocol:ros-message)
  ((color_what
    :reader color_what
    :initarg :color_what
    :type cl:integer
    :initform 0)
   (alpha_check
    :reader alpha_check
    :initarg :alpha_check
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass master2hanoi_vision2019msg (<master2hanoi_vision2019msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <master2hanoi_vision2019msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'master2hanoi_vision2019msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<master2hanoi_vision2019msg> is deprecated: use msg_generate-msg:master2hanoi_vision2019msg instead.")))

(cl:ensure-generic-function 'color_what-val :lambda-list '(m))
(cl:defmethod color_what-val ((m <master2hanoi_vision2019msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:color_what-val is deprecated.  Use msg_generate-msg:color_what instead.")
  (color_what m))

(cl:ensure-generic-function 'alpha_check-val :lambda-list '(m))
(cl:defmethod alpha_check-val ((m <master2hanoi_vision2019msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:alpha_check-val is deprecated.  Use msg_generate-msg:alpha_check instead.")
  (alpha_check m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <master2hanoi_vision2019msg>) ostream)
  "Serializes a message object of type '<master2hanoi_vision2019msg>"
  (cl:let* ((signed (cl:slot-value msg 'color_what)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'alpha_check) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <master2hanoi_vision2019msg>) istream)
  "Deserializes a message object of type '<master2hanoi_vision2019msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color_what) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'alpha_check) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<master2hanoi_vision2019msg>)))
  "Returns string type for a message object of type '<master2hanoi_vision2019msg>"
  "msg_generate/master2hanoi_vision2019msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'master2hanoi_vision2019msg)))
  "Returns string type for a message object of type 'master2hanoi_vision2019msg"
  "msg_generate/master2hanoi_vision2019msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<master2hanoi_vision2019msg>)))
  "Returns md5sum for a message object of type '<master2hanoi_vision2019msg>"
  "0da4621181e0545911e6b295c023e0d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'master2hanoi_vision2019msg)))
  "Returns md5sum for a message object of type 'master2hanoi_vision2019msg"
  "0da4621181e0545911e6b295c023e0d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<master2hanoi_vision2019msg>)))
  "Returns full string definition for message of type '<master2hanoi_vision2019msg>"
  (cl:format cl:nil "int32 color_what~%bool alpha_check~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'master2hanoi_vision2019msg)))
  "Returns full string definition for message of type 'master2hanoi_vision2019msg"
  (cl:format cl:nil "int32 color_what~%bool alpha_check~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <master2hanoi_vision2019msg>))
  (cl:+ 0
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <master2hanoi_vision2019msg>))
  "Converts a ROS message object to a list"
  (cl:list 'master2hanoi_vision2019msg
    (cl:cons ':color_what (color_what msg))
    (cl:cons ':alpha_check (alpha_check msg))
))
