; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude Local_Info.msg.html

(cl:defclass <Local_Info> (roslisp-msg-protocol:ros-message)
  ((featureData
    :reader featureData
    :initarg :featureData
    :type (cl:vector msg_generate-msg:Local_msg)
   :initform (cl:make-array 0 :element-type 'msg_generate-msg:Local_msg :initial-element (cl:make-instance 'msg_generate-msg:Local_msg))))
)

(cl:defclass Local_Info (<Local_Info>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Local_Info>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Local_Info)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<Local_Info> is deprecated: use msg_generate-msg:Local_Info instead.")))

(cl:ensure-generic-function 'featureData-val :lambda-list '(m))
(cl:defmethod featureData-val ((m <Local_Info>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:featureData-val is deprecated.  Use msg_generate-msg:featureData instead.")
  (featureData m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Local_Info>) ostream)
  "Serializes a message object of type '<Local_Info>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'featureData))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'featureData))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Local_Info>) istream)
  "Deserializes a message object of type '<Local_Info>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'featureData) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'featureData)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'msg_generate-msg:Local_msg))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Local_Info>)))
  "Returns string type for a message object of type '<Local_Info>"
  "msg_generate/Local_Info")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Local_Info)))
  "Returns string type for a message object of type 'Local_Info"
  "msg_generate/Local_Info")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Local_Info>)))
  "Returns md5sum for a message object of type '<Local_Info>"
  "db10bb32b399e072a5d60b68deb7697e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Local_Info)))
  "Returns md5sum for a message object of type 'Local_Info"
  "db10bb32b399e072a5d60b68deb7697e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Local_Info>)))
  "Returns full string definition for message of type '<Local_Info>"
  (cl:format cl:nil "Local_msg[] featureData~%~%================================================================================~%MSG: msg_generate/Local_msg~%float64 Id~%float64 dist~%float64 theta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Local_Info)))
  "Returns full string definition for message of type 'Local_Info"
  (cl:format cl:nil "Local_msg[] featureData~%~%================================================================================~%MSG: msg_generate/Local_msg~%float64 Id~%float64 dist~%float64 theta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Local_Info>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'featureData) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Local_Info>))
  "Converts a ROS message object to a list"
  (cl:list 'Local_Info
    (cl:cons ':featureData (featureData msg))
))
