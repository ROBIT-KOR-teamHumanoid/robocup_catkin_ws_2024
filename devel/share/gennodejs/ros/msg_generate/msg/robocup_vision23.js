// Auto-generated. Do not edit!

// (in-package msg_generate.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class robocup_vision23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Ball_cam_X = null;
      this.Ball_cam_Y = null;
      this.Ball_2d_X = null;
      this.Ball_2d_Y = null;
      this.Ball_D = null;
      this.PAN = null;
      this.TILT = null;
      this.Ball_speed_X = null;
      this.Ball_speed_Y = null;
      this.ROBOT_VEC_X = null;
      this.ROBOT_VEC_Y = null;
      this.Ball_speed_level = null;
      this.Scan_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('Ball_cam_X')) {
        this.Ball_cam_X = initObj.Ball_cam_X
      }
      else {
        this.Ball_cam_X = 0;
      }
      if (initObj.hasOwnProperty('Ball_cam_Y')) {
        this.Ball_cam_Y = initObj.Ball_cam_Y
      }
      else {
        this.Ball_cam_Y = 0;
      }
      if (initObj.hasOwnProperty('Ball_2d_X')) {
        this.Ball_2d_X = initObj.Ball_2d_X
      }
      else {
        this.Ball_2d_X = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_2d_Y')) {
        this.Ball_2d_Y = initObj.Ball_2d_Y
      }
      else {
        this.Ball_2d_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_D')) {
        this.Ball_D = initObj.Ball_D
      }
      else {
        this.Ball_D = 0.0;
      }
      if (initObj.hasOwnProperty('PAN')) {
        this.PAN = initObj.PAN
      }
      else {
        this.PAN = 0.0;
      }
      if (initObj.hasOwnProperty('TILT')) {
        this.TILT = initObj.TILT
      }
      else {
        this.TILT = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_speed_X')) {
        this.Ball_speed_X = initObj.Ball_speed_X
      }
      else {
        this.Ball_speed_X = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_speed_Y')) {
        this.Ball_speed_Y = initObj.Ball_speed_Y
      }
      else {
        this.Ball_speed_Y = 0.0;
      }
      if (initObj.hasOwnProperty('ROBOT_VEC_X')) {
        this.ROBOT_VEC_X = initObj.ROBOT_VEC_X
      }
      else {
        this.ROBOT_VEC_X = [];
      }
      if (initObj.hasOwnProperty('ROBOT_VEC_Y')) {
        this.ROBOT_VEC_Y = initObj.ROBOT_VEC_Y
      }
      else {
        this.ROBOT_VEC_Y = [];
      }
      if (initObj.hasOwnProperty('Ball_speed_level')) {
        this.Ball_speed_level = initObj.Ball_speed_level
      }
      else {
        this.Ball_speed_level = 0;
      }
      if (initObj.hasOwnProperty('Scan_mode')) {
        this.Scan_mode = initObj.Scan_mode
      }
      else {
        this.Scan_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocup_vision23
    // Serialize message field [Ball_cam_X]
    bufferOffset = _serializer.int64(obj.Ball_cam_X, buffer, bufferOffset);
    // Serialize message field [Ball_cam_Y]
    bufferOffset = _serializer.int64(obj.Ball_cam_Y, buffer, bufferOffset);
    // Serialize message field [Ball_2d_X]
    bufferOffset = _serializer.float64(obj.Ball_2d_X, buffer, bufferOffset);
    // Serialize message field [Ball_2d_Y]
    bufferOffset = _serializer.float64(obj.Ball_2d_Y, buffer, bufferOffset);
    // Serialize message field [Ball_D]
    bufferOffset = _serializer.float64(obj.Ball_D, buffer, bufferOffset);
    // Serialize message field [PAN]
    bufferOffset = _serializer.float64(obj.PAN, buffer, bufferOffset);
    // Serialize message field [TILT]
    bufferOffset = _serializer.float64(obj.TILT, buffer, bufferOffset);
    // Serialize message field [Ball_speed_X]
    bufferOffset = _serializer.float64(obj.Ball_speed_X, buffer, bufferOffset);
    // Serialize message field [Ball_speed_Y]
    bufferOffset = _serializer.float64(obj.Ball_speed_Y, buffer, bufferOffset);
    // Serialize message field [ROBOT_VEC_X]
    bufferOffset = _arraySerializer.float64(obj.ROBOT_VEC_X, buffer, bufferOffset, null);
    // Serialize message field [ROBOT_VEC_Y]
    bufferOffset = _arraySerializer.float64(obj.ROBOT_VEC_Y, buffer, bufferOffset, null);
    // Serialize message field [Ball_speed_level]
    bufferOffset = _serializer.int64(obj.Ball_speed_level, buffer, bufferOffset);
    // Serialize message field [Scan_mode]
    bufferOffset = _serializer.int64(obj.Scan_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocup_vision23
    let len;
    let data = new robocup_vision23(null);
    // Deserialize message field [Ball_cam_X]
    data.Ball_cam_X = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Ball_cam_Y]
    data.Ball_cam_Y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Ball_2d_X]
    data.Ball_2d_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_2d_Y]
    data.Ball_2d_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_D]
    data.Ball_D = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [PAN]
    data.PAN = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [TILT]
    data.TILT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_speed_X]
    data.Ball_speed_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_speed_Y]
    data.Ball_speed_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ROBOT_VEC_X]
    data.ROBOT_VEC_X = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [ROBOT_VEC_Y]
    data.ROBOT_VEC_Y = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [Ball_speed_level]
    data.Ball_speed_level = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Scan_mode]
    data.Scan_mode = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.ROBOT_VEC_X.length;
    length += 8 * object.ROBOT_VEC_Y.length;
    return length + 96;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocup_vision23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e7c23af0ec42fde2be9393d1f1e88db0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 Ball_cam_X
    int64 Ball_cam_Y
    float64 Ball_2d_X
    float64 Ball_2d_Y
    float64 Ball_D
    float64 PAN
    float64 TILT
    float64 Ball_speed_X
    float64 Ball_speed_Y
    float64[] ROBOT_VEC_X
    float64[] ROBOT_VEC_Y
    int64 Ball_speed_level
    int64 Scan_mode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocup_vision23(null);
    if (msg.Ball_cam_X !== undefined) {
      resolved.Ball_cam_X = msg.Ball_cam_X;
    }
    else {
      resolved.Ball_cam_X = 0
    }

    if (msg.Ball_cam_Y !== undefined) {
      resolved.Ball_cam_Y = msg.Ball_cam_Y;
    }
    else {
      resolved.Ball_cam_Y = 0
    }

    if (msg.Ball_2d_X !== undefined) {
      resolved.Ball_2d_X = msg.Ball_2d_X;
    }
    else {
      resolved.Ball_2d_X = 0.0
    }

    if (msg.Ball_2d_Y !== undefined) {
      resolved.Ball_2d_Y = msg.Ball_2d_Y;
    }
    else {
      resolved.Ball_2d_Y = 0.0
    }

    if (msg.Ball_D !== undefined) {
      resolved.Ball_D = msg.Ball_D;
    }
    else {
      resolved.Ball_D = 0.0
    }

    if (msg.PAN !== undefined) {
      resolved.PAN = msg.PAN;
    }
    else {
      resolved.PAN = 0.0
    }

    if (msg.TILT !== undefined) {
      resolved.TILT = msg.TILT;
    }
    else {
      resolved.TILT = 0.0
    }

    if (msg.Ball_speed_X !== undefined) {
      resolved.Ball_speed_X = msg.Ball_speed_X;
    }
    else {
      resolved.Ball_speed_X = 0.0
    }

    if (msg.Ball_speed_Y !== undefined) {
      resolved.Ball_speed_Y = msg.Ball_speed_Y;
    }
    else {
      resolved.Ball_speed_Y = 0.0
    }

    if (msg.ROBOT_VEC_X !== undefined) {
      resolved.ROBOT_VEC_X = msg.ROBOT_VEC_X;
    }
    else {
      resolved.ROBOT_VEC_X = []
    }

    if (msg.ROBOT_VEC_Y !== undefined) {
      resolved.ROBOT_VEC_Y = msg.ROBOT_VEC_Y;
    }
    else {
      resolved.ROBOT_VEC_Y = []
    }

    if (msg.Ball_speed_level !== undefined) {
      resolved.Ball_speed_level = msg.Ball_speed_level;
    }
    else {
      resolved.Ball_speed_level = 0
    }

    if (msg.Scan_mode !== undefined) {
      resolved.Scan_mode = msg.Scan_mode;
    }
    else {
      resolved.Scan_mode = 0
    }

    return resolved;
    }
};

module.exports = robocup_vision23;
