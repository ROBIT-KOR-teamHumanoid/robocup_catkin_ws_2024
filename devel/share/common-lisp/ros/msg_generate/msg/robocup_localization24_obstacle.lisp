; Auto-generated. Do not edit!


(cl:in-package msg_generate-msg)


;//! \htmlinclude robocup_localization24_obstacle.msg.html

(cl:defclass <robocup_localization24_obstacle> (roslisp-msg-protocol:ros-message)
  ((Ball_X
    :reader Ball_X
    :initarg :Ball_X
    :type cl:float
    :initform 0.0)
   (Ball_Y
    :reader Ball_Y
    :initarg :Ball_Y
    :type cl:float
    :initform 0.0)
   (Ball_speed_X
    :reader Ball_speed_X
    :initarg :Ball_speed_X
    :type cl:float
    :initform 0.0)
   (Ball_speed_Y
    :reader Ball_speed_Y
    :initarg :Ball_speed_Y
    :type cl:float
    :initform 0.0)
   (Robot_X
    :reader Robot_X
    :initarg :Robot_X
    :type cl:float
    :initform 0.0)
   (Robot_Y
    :reader Robot_Y
    :initarg :Robot_Y
    :type cl:float
    :initform 0.0)
   (Obstacle0_X
    :reader Obstacle0_X
    :initarg :Obstacle0_X
    :type cl:float
    :initform 0.0)
   (Obstacle0_Y
    :reader Obstacle0_Y
    :initarg :Obstacle0_Y
    :type cl:float
    :initform 0.0)
   (Obstacle1_X
    :reader Obstacle1_X
    :initarg :Obstacle1_X
    :type cl:float
    :initform 0.0)
   (Obstacle1_Y
    :reader Obstacle1_Y
    :initarg :Obstacle1_Y
    :type cl:float
    :initform 0.0)
   (Obstacle2_X
    :reader Obstacle2_X
    :initarg :Obstacle2_X
    :type cl:float
    :initform 0.0)
   (Obstacle2_Y
    :reader Obstacle2_Y
    :initarg :Obstacle2_Y
    :type cl:float
    :initform 0.0)
   (Obstacle3_X
    :reader Obstacle3_X
    :initarg :Obstacle3_X
    :type cl:float
    :initform 0.0)
   (Obstacle3_Y
    :reader Obstacle3_Y
    :initarg :Obstacle3_Y
    :type cl:float
    :initform 0.0))
)

(cl:defclass robocup_localization24_obstacle (<robocup_localization24_obstacle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robocup_localization24_obstacle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robocup_localization24_obstacle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_generate-msg:<robocup_localization24_obstacle> is deprecated: use msg_generate-msg:robocup_localization24_obstacle instead.")))

(cl:ensure-generic-function 'Ball_X-val :lambda-list '(m))
(cl:defmethod Ball_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Ball_X-val is deprecated.  Use msg_generate-msg:Ball_X instead.")
  (Ball_X m))

(cl:ensure-generic-function 'Ball_Y-val :lambda-list '(m))
(cl:defmethod Ball_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Ball_Y-val is deprecated.  Use msg_generate-msg:Ball_Y instead.")
  (Ball_Y m))

(cl:ensure-generic-function 'Ball_speed_X-val :lambda-list '(m))
(cl:defmethod Ball_speed_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Ball_speed_X-val is deprecated.  Use msg_generate-msg:Ball_speed_X instead.")
  (Ball_speed_X m))

(cl:ensure-generic-function 'Ball_speed_Y-val :lambda-list '(m))
(cl:defmethod Ball_speed_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Ball_speed_Y-val is deprecated.  Use msg_generate-msg:Ball_speed_Y instead.")
  (Ball_speed_Y m))

(cl:ensure-generic-function 'Robot_X-val :lambda-list '(m))
(cl:defmethod Robot_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Robot_X-val is deprecated.  Use msg_generate-msg:Robot_X instead.")
  (Robot_X m))

(cl:ensure-generic-function 'Robot_Y-val :lambda-list '(m))
(cl:defmethod Robot_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Robot_Y-val is deprecated.  Use msg_generate-msg:Robot_Y instead.")
  (Robot_Y m))

(cl:ensure-generic-function 'Obstacle0_X-val :lambda-list '(m))
(cl:defmethod Obstacle0_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle0_X-val is deprecated.  Use msg_generate-msg:Obstacle0_X instead.")
  (Obstacle0_X m))

(cl:ensure-generic-function 'Obstacle0_Y-val :lambda-list '(m))
(cl:defmethod Obstacle0_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle0_Y-val is deprecated.  Use msg_generate-msg:Obstacle0_Y instead.")
  (Obstacle0_Y m))

(cl:ensure-generic-function 'Obstacle1_X-val :lambda-list '(m))
(cl:defmethod Obstacle1_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle1_X-val is deprecated.  Use msg_generate-msg:Obstacle1_X instead.")
  (Obstacle1_X m))

(cl:ensure-generic-function 'Obstacle1_Y-val :lambda-list '(m))
(cl:defmethod Obstacle1_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle1_Y-val is deprecated.  Use msg_generate-msg:Obstacle1_Y instead.")
  (Obstacle1_Y m))

(cl:ensure-generic-function 'Obstacle2_X-val :lambda-list '(m))
(cl:defmethod Obstacle2_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle2_X-val is deprecated.  Use msg_generate-msg:Obstacle2_X instead.")
  (Obstacle2_X m))

(cl:ensure-generic-function 'Obstacle2_Y-val :lambda-list '(m))
(cl:defmethod Obstacle2_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle2_Y-val is deprecated.  Use msg_generate-msg:Obstacle2_Y instead.")
  (Obstacle2_Y m))

(cl:ensure-generic-function 'Obstacle3_X-val :lambda-list '(m))
(cl:defmethod Obstacle3_X-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle3_X-val is deprecated.  Use msg_generate-msg:Obstacle3_X instead.")
  (Obstacle3_X m))

(cl:ensure-generic-function 'Obstacle3_Y-val :lambda-list '(m))
(cl:defmethod Obstacle3_Y-val ((m <robocup_localization24_obstacle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_generate-msg:Obstacle3_Y-val is deprecated.  Use msg_generate-msg:Obstacle3_Y instead.")
  (Obstacle3_Y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robocup_localization24_obstacle>) ostream)
  "Serializes a message object of type '<robocup_localization24_obstacle>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Ball_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Ball_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Ball_speed_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Ball_speed_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Robot_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Robot_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle0_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle0_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle1_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle1_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle2_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle2_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle3_X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Obstacle3_Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robocup_localization24_obstacle>) istream)
  "Deserializes a message object of type '<robocup_localization24_obstacle>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ball_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ball_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ball_speed_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ball_speed_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Robot_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Robot_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle0_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle0_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle1_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle1_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle2_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle2_Y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle3_X) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Obstacle3_Y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robocup_localization24_obstacle>)))
  "Returns string type for a message object of type '<robocup_localization24_obstacle>"
  "msg_generate/robocup_localization24_obstacle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robocup_localization24_obstacle)))
  "Returns string type for a message object of type 'robocup_localization24_obstacle"
  "msg_generate/robocup_localization24_obstacle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robocup_localization24_obstacle>)))
  "Returns md5sum for a message object of type '<robocup_localization24_obstacle>"
  "2b8377baa9d999eda3c851f4b34ed1a5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robocup_localization24_obstacle)))
  "Returns md5sum for a message object of type 'robocup_localization24_obstacle"
  "2b8377baa9d999eda3c851f4b34ed1a5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robocup_localization24_obstacle>)))
  "Returns full string definition for message of type '<robocup_localization24_obstacle>"
  (cl:format cl:nil "float64 Ball_X~%float64 Ball_Y~%float64 Ball_speed_X~%float64 Ball_speed_Y~%float64 Robot_X~%float64 Robot_Y~%float64 Obstacle0_X~%float64 Obstacle0_Y~%float64 Obstacle1_X~%float64 Obstacle1_Y~%float64 Obstacle2_X~%float64 Obstacle2_Y~%float64 Obstacle3_X~%float64 Obstacle3_Y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robocup_localization24_obstacle)))
  "Returns full string definition for message of type 'robocup_localization24_obstacle"
  (cl:format cl:nil "float64 Ball_X~%float64 Ball_Y~%float64 Ball_speed_X~%float64 Ball_speed_Y~%float64 Robot_X~%float64 Robot_Y~%float64 Obstacle0_X~%float64 Obstacle0_Y~%float64 Obstacle1_X~%float64 Obstacle1_Y~%float64 Obstacle2_X~%float64 Obstacle2_Y~%float64 Obstacle3_X~%float64 Obstacle3_Y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robocup_localization24_obstacle>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robocup_localization24_obstacle>))
  "Converts a ROS message object to a list"
  (cl:list 'robocup_localization24_obstacle
    (cl:cons ':Ball_X (Ball_X msg))
    (cl:cons ':Ball_Y (Ball_Y msg))
    (cl:cons ':Ball_speed_X (Ball_speed_X msg))
    (cl:cons ':Ball_speed_Y (Ball_speed_Y msg))
    (cl:cons ':Robot_X (Robot_X msg))
    (cl:cons ':Robot_Y (Robot_Y msg))
    (cl:cons ':Obstacle0_X (Obstacle0_X msg))
    (cl:cons ':Obstacle0_Y (Obstacle0_Y msg))
    (cl:cons ':Obstacle1_X (Obstacle1_X msg))
    (cl:cons ':Obstacle1_Y (Obstacle1_Y msg))
    (cl:cons ':Obstacle2_X (Obstacle2_X msg))
    (cl:cons ':Obstacle2_Y (Obstacle2_Y msg))
    (cl:cons ':Obstacle3_X (Obstacle3_X msg))
    (cl:cons ':Obstacle3_Y (Obstacle3_Y msg))
))
