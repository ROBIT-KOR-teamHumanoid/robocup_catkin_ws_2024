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

class basketball_vision23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal_cam_X = null;
      this.goal_cam_Y = null;
      this.goal_2d_X = null;
      this.goal_2d_Y = null;
      this.goal_local_X = null;
      this.goal_local_Y = null;
      this.goal_D = null;
      this.robot_local_X = null;
      this.robot_local_Y = null;
      this.PAN = null;
      this.TILT = null;
      this.Scan_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('goal_cam_X')) {
        this.goal_cam_X = initObj.goal_cam_X
      }
      else {
        this.goal_cam_X = 0;
      }
      if (initObj.hasOwnProperty('goal_cam_Y')) {
        this.goal_cam_Y = initObj.goal_cam_Y
      }
      else {
        this.goal_cam_Y = 0;
      }
      if (initObj.hasOwnProperty('goal_2d_X')) {
        this.goal_2d_X = initObj.goal_2d_X
      }
      else {
        this.goal_2d_X = 0.0;
      }
      if (initObj.hasOwnProperty('goal_2d_Y')) {
        this.goal_2d_Y = initObj.goal_2d_Y
      }
      else {
        this.goal_2d_Y = 0.0;
      }
      if (initObj.hasOwnProperty('goal_local_X')) {
        this.goal_local_X = initObj.goal_local_X
      }
      else {
        this.goal_local_X = 0.0;
      }
      if (initObj.hasOwnProperty('goal_local_Y')) {
        this.goal_local_Y = initObj.goal_local_Y
      }
      else {
        this.goal_local_Y = 0.0;
      }
      if (initObj.hasOwnProperty('goal_D')) {
        this.goal_D = initObj.goal_D
      }
      else {
        this.goal_D = 0.0;
      }
      if (initObj.hasOwnProperty('robot_local_X')) {
        this.robot_local_X = initObj.robot_local_X
      }
      else {
        this.robot_local_X = 0.0;
      }
      if (initObj.hasOwnProperty('robot_local_Y')) {
        this.robot_local_Y = initObj.robot_local_Y
      }
      else {
        this.robot_local_Y = 0.0;
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
      if (initObj.hasOwnProperty('Scan_mode')) {
        this.Scan_mode = initObj.Scan_mode
      }
      else {
        this.Scan_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type basketball_vision23
    // Serialize message field [goal_cam_X]
    bufferOffset = _serializer.int64(obj.goal_cam_X, buffer, bufferOffset);
    // Serialize message field [goal_cam_Y]
    bufferOffset = _serializer.int64(obj.goal_cam_Y, buffer, bufferOffset);
    // Serialize message field [goal_2d_X]
    bufferOffset = _serializer.float64(obj.goal_2d_X, buffer, bufferOffset);
    // Serialize message field [goal_2d_Y]
    bufferOffset = _serializer.float64(obj.goal_2d_Y, buffer, bufferOffset);
    // Serialize message field [goal_local_X]
    bufferOffset = _serializer.float64(obj.goal_local_X, buffer, bufferOffset);
    // Serialize message field [goal_local_Y]
    bufferOffset = _serializer.float64(obj.goal_local_Y, buffer, bufferOffset);
    // Serialize message field [goal_D]
    bufferOffset = _serializer.float64(obj.goal_D, buffer, bufferOffset);
    // Serialize message field [robot_local_X]
    bufferOffset = _serializer.float64(obj.robot_local_X, buffer, bufferOffset);
    // Serialize message field [robot_local_Y]
    bufferOffset = _serializer.float64(obj.robot_local_Y, buffer, bufferOffset);
    // Serialize message field [PAN]
    bufferOffset = _serializer.float64(obj.PAN, buffer, bufferOffset);
    // Serialize message field [TILT]
    bufferOffset = _serializer.float64(obj.TILT, buffer, bufferOffset);
    // Serialize message field [Scan_mode]
    bufferOffset = _serializer.int64(obj.Scan_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type basketball_vision23
    let len;
    let data = new basketball_vision23(null);
    // Deserialize message field [goal_cam_X]
    data.goal_cam_X = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [goal_cam_Y]
    data.goal_cam_Y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [goal_2d_X]
    data.goal_2d_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [goal_2d_Y]
    data.goal_2d_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [goal_local_X]
    data.goal_local_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [goal_local_Y]
    data.goal_local_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [goal_D]
    data.goal_D = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [robot_local_X]
    data.robot_local_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [robot_local_Y]
    data.robot_local_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [PAN]
    data.PAN = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [TILT]
    data.TILT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Scan_mode]
    data.Scan_mode = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 96;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/basketball_vision23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e6ef028504654d91012c2d8d50a3e391';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 goal_cam_X
    int64 goal_cam_Y
    float64 goal_2d_X
    float64 goal_2d_Y
    float64 goal_local_X
    float64 goal_local_Y
    float64 goal_D
    float64 robot_local_X
    float64 robot_local_Y
    float64 PAN
    float64 TILT
    int64 Scan_mode
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new basketball_vision23(null);
    if (msg.goal_cam_X !== undefined) {
      resolved.goal_cam_X = msg.goal_cam_X;
    }
    else {
      resolved.goal_cam_X = 0
    }

    if (msg.goal_cam_Y !== undefined) {
      resolved.goal_cam_Y = msg.goal_cam_Y;
    }
    else {
      resolved.goal_cam_Y = 0
    }

    if (msg.goal_2d_X !== undefined) {
      resolved.goal_2d_X = msg.goal_2d_X;
    }
    else {
      resolved.goal_2d_X = 0.0
    }

    if (msg.goal_2d_Y !== undefined) {
      resolved.goal_2d_Y = msg.goal_2d_Y;
    }
    else {
      resolved.goal_2d_Y = 0.0
    }

    if (msg.goal_local_X !== undefined) {
      resolved.goal_local_X = msg.goal_local_X;
    }
    else {
      resolved.goal_local_X = 0.0
    }

    if (msg.goal_local_Y !== undefined) {
      resolved.goal_local_Y = msg.goal_local_Y;
    }
    else {
      resolved.goal_local_Y = 0.0
    }

    if (msg.goal_D !== undefined) {
      resolved.goal_D = msg.goal_D;
    }
    else {
      resolved.goal_D = 0.0
    }

    if (msg.robot_local_X !== undefined) {
      resolved.robot_local_X = msg.robot_local_X;
    }
    else {
      resolved.robot_local_X = 0.0
    }

    if (msg.robot_local_Y !== undefined) {
      resolved.robot_local_Y = msg.robot_local_Y;
    }
    else {
      resolved.robot_local_Y = 0.0
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

    if (msg.Scan_mode !== undefined) {
      resolved.Scan_mode = msg.Scan_mode;
    }
    else {
      resolved.Scan_mode = 0
    }

    return resolved;
    }
};

module.exports = basketball_vision23;
