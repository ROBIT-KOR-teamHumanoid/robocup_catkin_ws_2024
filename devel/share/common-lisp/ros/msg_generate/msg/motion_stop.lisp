; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude motion_stop.msg.html

(cl:defclass <motion_stop> (roslisp-msg-protocol:ros-message)
  ((motion_stop
    :reader motion_stop
    :initarg :motion_stop
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass motion_stop (<motion_stop>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motion_stop>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motion_stop)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<motion_stop> is deprecated: use msg_generate-msg:motion_stop instead.")))

(cl:ensure-generic-function 'motion_stop-val :lambda-list '(m))
(cl:defmethod motion_stop-val ((m <motion_stop>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:motion_stop-val is deprecated.  Use msg_generate-msg:motion_stop instead.")
  (motion_stop m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motion_stop>) ostream)
  "Serializes a message object of type '<motion_stop>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'motion_stop) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motion_stop>) istream)
  "Deserializes a message object of type '<motion_stop>"
    (cl:setf (cl:slot-value msg 'motion_stop) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motion_stop>)))
  "Returns string type for a message object of type '<motion_stop>"
  "msg_generate/motion_stop")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motion_stop)))
  "Returns string type for a message object of type 'motion_stop"
  "msg_generate/motion_stop")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motion_stop>)))
  "Returns md5sum for a message object of type '<motion_stop>"
  "26a67ab0046f1f409ea3537c40f97362")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motion_stop)))
  "Returns md5sum for a message object of type 'motion_stop"
  "26a67ab0046f1f409ea3537c40f97362")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motion_stop>)))
  "Returns full string definition for message of type '<motion_stop>"
  (cl:format cl:nil "bool motion_stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motion_stop)))
  "Returns full string definition for message of type 'motion_stop"
  (cl:format cl:nil "bool motion_stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motion_stop>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motion_stop>))
  "Converts a ROS message object to a list"
  (cl:list 'motion_stop
    (cl:cons ':motion_stop (motion_stop msg))
))
