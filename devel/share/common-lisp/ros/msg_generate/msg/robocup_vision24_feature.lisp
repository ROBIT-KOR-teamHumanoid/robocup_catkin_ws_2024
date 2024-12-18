; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude robocup_vision24_feature.msg.html

(cl:defclass <robocup_vision24_feature> (roslisp-msg-protocol:ros-message)
  ((CONFIDENCE
    :reader CONFIDENCE
    :initarg :CONFIDENCE
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (DISTANCE
    :reader DISTANCE
    :initarg :DISTANCE
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (POINT_VEC_X
    :reader POINT_VEC_X
    :initarg :POINT_VEC_X
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (POINT_VEC_Y
    :reader POINT_VEC_Y
    :initarg :POINT_VEC_Y
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (TYPE
    :reader TYPE
    :initarg :TYPE
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass robocup_vision24_feature (<robocup_vision24_feature>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robocup_vision24_feature>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robocup_vision24_feature)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<robocup_vision24_feature> is deprecated: use msg_generate-msg:robocup_vision24_feature instead.")))

(cl:ensure-generic-function 'CONFIDENCE-val :lambda-list '(m))
(cl:defmethod CONFIDENCE-val ((m <robocup_vision24_feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:CONFIDENCE-val is deprecated.  Use msg_generate-msg:CONFIDENCE instead.")
  (CONFIDENCE m))

(cl:ensure-generic-function 'DISTANCE-val :lambda-list '(m))
(cl:defmethod DISTANCE-val ((m <robocup_vision24_feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:DISTANCE-val is deprecated.  Use msg_generate-msg:DISTANCE instead.")
  (DISTANCE m))

(cl:ensure-generic-function 'POINT_VEC_X-val :lambda-list '(m))
(cl:defmethod POINT_VEC_X-val ((m <robocup_vision24_feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:POINT_VEC_X-val is deprecated.  Use msg_generate-msg:POINT_VEC_X instead.")
  (POINT_VEC_X m))

(cl:ensure-generic-function 'POINT_VEC_Y-val :lambda-list '(m))
(cl:defmethod POINT_VEC_Y-val ((m <robocup_vision24_feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:POINT_VEC_Y-val is deprecated.  Use msg_generate-msg:POINT_VEC_Y instead.")
  (POINT_VEC_Y m))

(cl:ensure-generic-function 'TYPE-val :lambda-list '(m))
(cl:defmethod TYPE-val ((m <robocup_vision24_feature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:TYPE-val is deprecated.  Use msg_generate-msg:TYPE instead.")
  (TYPE m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robocup_vision24_feature>) ostream)
  "Serializes a message object of type '<robocup_vision24_feature>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'CONFIDENCE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'CONFIDENCE))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'DISTANCE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'DISTANCE))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'POINT_VEC_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'POINT_VEC_X))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'POINT_VEC_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'POINT_VEC_Y))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'TYPE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'TYPE))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robocup_vision24_feature>) istream)
  "Deserializes a message object of type '<robocup_vision24_feature>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'CONFIDENCE) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'CONFIDENCE)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'DISTANCE) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'DISTANCE)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'POINT_VEC_X) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'POINT_VEC_X)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'POINT_VEC_Y) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'POINT_VEC_Y)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'TYPE) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'TYPE)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robocup_vision24_feature>)))
  "Returns string type for a message object of type '<robocup_vision24_feature>"
  "msg_generate/robocup_vision24_feature")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robocup_vision24_feature)))
  "Returns string type for a message object of type 'robocup_vision24_feature"
  "msg_generate/robocup_vision24_feature")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robocup_vision24_feature>)))
  "Returns md5sum for a message object of type '<robocup_vision24_feature>"
  "90f95fdb2af41305af35e1195995ece4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robocup_vision24_feature)))
  "Returns md5sum for a message object of type 'robocup_vision24_feature"
  "90f95fdb2af41305af35e1195995ece4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robocup_vision24_feature>)))
  "Returns full string definition for message of type '<robocup_vision24_feature>"
  (cl:format cl:nil "float64[] CONFIDENCE~%float64[] DISTANCE~%float64[] POINT_VEC_X~%float64[] POINT_VEC_Y~%float64[] TYPE~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robocup_vision24_feature)))
  "Returns full string definition for message of type 'robocup_vision24_feature"
  (cl:format cl:nil "float64[] CONFIDENCE~%float64[] DISTANCE~%float64[] POINT_VEC_X~%float64[] POINT_VEC_Y~%float64[] TYPE~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robocup_vision24_feature>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'CONFIDENCE) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'DISTANCE) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'POINT_VEC_X) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'POINT_VEC_Y) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'TYPE) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robocup_vision24_feature>))
  "Converts a ROS message object to a list"
  (cl:list 'robocup_vision24_feature
    (cl:cons ':CONFIDENCE (CONFIDENCE msg))
    (cl:cons ':DISTANCE (DISTANCE msg))
    (cl:cons ':POINT_VEC_X (POINT_VEC_X msg))
    (cl:cons ':POINT_VEC_Y (POINT_VEC_Y msg))
    (cl:cons ':TYPE (TYPE msg))
))
