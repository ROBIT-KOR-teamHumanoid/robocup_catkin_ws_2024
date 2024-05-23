; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude udp_order.msg.html

(cl:defclass <udp_order> (roslisp-msg-protocol:ros-message)
  ((order
    :reader order
    :initarg :order
    :type cl:fixnum
    :initform 0))
)

(cl:defclass udp_order (<udp_order>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <udp_order>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'udp_order)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<udp_order> is deprecated: use msg_generate-msg:udp_order instead.")))

(cl:ensure-generic-function 'order-val :lambda-list '(m))
(cl:defmethod order-val ((m <udp_order>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:order-val is deprecated.  Use msg_generate-msg:order instead.")
  (order m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <udp_order>) ostream)
  "Serializes a message object of type '<udp_order>"
  (cl:let* ((signed (cl:slot-value msg 'order)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <udp_order>) istream)
  "Deserializes a message object of type '<udp_order>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'order) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<udp_order>)))
  "Returns string type for a message object of type '<udp_order>"
  "msg_generate/udp_order")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'udp_order)))
  "Returns string type for a message object of type 'udp_order"
  "msg_generate/udp_order")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<udp_order>)))
  "Returns md5sum for a message object of type '<udp_order>"
  "2966e63ad91c66f88bbe7ef4becb02eb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'udp_order)))
  "Returns md5sum for a message object of type 'udp_order"
  "2966e63ad91c66f88bbe7ef4becb02eb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<udp_order>)))
  "Returns full string definition for message of type '<udp_order>"
  (cl:format cl:nil "int16 order~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'udp_order)))
  "Returns full string definition for message of type 'udp_order"
  (cl:format cl:nil "int16 order~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <udp_order>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <udp_order>))
  "Converts a ROS message object to a list"
  (cl:list 'udp_order
    (cl:cons ':order (order msg))
))
