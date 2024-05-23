; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude R_LC_msg.msg.html

(cl:defclass <R_LC_msg> (roslisp-msg-protocol:ros-message)
  ((R_LC_Data
    :reader R_LC_Data
    :initarg :R_LC_Data
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass R_LC_msg (<R_LC_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <R_LC_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'R_LC_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<R_LC_msg> is deprecated: use msg_generate-msg:R_LC_msg instead.")))

(cl:ensure-generic-function 'R_LC_Data-val :lambda-list '(m))
(cl:defmethod R_LC_Data-val ((m <R_LC_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:R_LC_Data-val is deprecated.  Use msg_generate-msg:R_LC_Data instead.")
  (R_LC_Data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <R_LC_msg>) ostream)
  "Serializes a message object of type '<R_LC_msg>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'R_LC_Data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'R_LC_Data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <R_LC_msg>) istream)
  "Deserializes a message object of type '<R_LC_msg>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'R_LC_Data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'R_LC_Data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<R_LC_msg>)))
  "Returns string type for a message object of type '<R_LC_msg>"
  "msg_generate/R_LC_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'R_LC_msg)))
  "Returns string type for a message object of type 'R_LC_msg"
  "msg_generate/R_LC_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<R_LC_msg>)))
  "Returns md5sum for a message object of type '<R_LC_msg>"
  "1d93107f948628f0a69348074e2aa35d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'R_LC_msg)))
  "Returns md5sum for a message object of type 'R_LC_msg"
  "1d93107f948628f0a69348074e2aa35d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<R_LC_msg>)))
  "Returns full string definition for message of type '<R_LC_msg>"
  (cl:format cl:nil "int32[] R_LC_Data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'R_LC_msg)))
  "Returns full string definition for message of type 'R_LC_msg"
  (cl:format cl:nil "int32[] R_LC_Data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <R_LC_msg>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'R_LC_Data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <R_LC_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'R_LC_msg
    (cl:cons ':R_LC_Data (R_LC_Data msg))
))
