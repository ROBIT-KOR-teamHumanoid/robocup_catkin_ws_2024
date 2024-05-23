; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude yaw_set.msg.html

(cl:defclass <yaw_set> (roslisp-msg-protocol:ros-message)
  ((isYawSet
    :reader isYawSet
    :initarg :isYawSet
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass yaw_set (<yaw_set>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <yaw_set>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'yaw_set)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<yaw_set> is deprecated: use msg_generate-msg:yaw_set instead.")))

(cl:ensure-generic-function 'isYawSet-val :lambda-list '(m))
(cl:defmethod isYawSet-val ((m <yaw_set>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:isYawSet-val is deprecated.  Use msg_generate-msg:isYawSet instead.")
  (isYawSet m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <yaw_set>) ostream)
  "Serializes a message object of type '<yaw_set>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isYawSet) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <yaw_set>) istream)
  "Deserializes a message object of type '<yaw_set>"
    (cl:setf (cl:slot-value msg 'isYawSet) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<yaw_set>)))
  "Returns string type for a message object of type '<yaw_set>"
  "msg_generate/yaw_set")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'yaw_set)))
  "Returns string type for a message object of type 'yaw_set"
  "msg_generate/yaw_set")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<yaw_set>)))
  "Returns md5sum for a message object of type '<yaw_set>"
  "dd1fd0ebc1d42598eb0e74fe046655f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'yaw_set)))
  "Returns md5sum for a message object of type 'yaw_set"
  "dd1fd0ebc1d42598eb0e74fe046655f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<yaw_set>)))
  "Returns full string definition for message of type '<yaw_set>"
  (cl:format cl:nil "bool isYawSet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'yaw_set)))
  "Returns full string definition for message of type 'yaw_set"
  (cl:format cl:nil "bool isYawSet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <yaw_set>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <yaw_set>))
  "Converts a ROS message object to a list"
  (cl:list 'yaw_set
    (cl:cons ':isYawSet (isYawSet msg))
))
