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

class master2localization23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal_x = null;
      this.goal_y = null;
      this.target_x = null;
      this.target_y = null;
      this.robot_allowance_error = null;
      this.robot_cali_radius = null;
      this.mf_robot_x = null;
      this.mf_robot_y = null;
      this.mf_ball_x = null;
      this.mf_ball_y = null;
    }
    else {
      if (initObj.hasOwnProperty('goal_x')) {
        this.goal_x = initObj.goal_x
      }
      else {
        this.goal_x = 0;
      }
      if (initObj.hasOwnProperty('goal_y')) {
        this.goal_y = initObj.goal_y
      }
      else {
        this.goal_y = 0;
      }
      if (initObj.hasOwnProperty('target_x')) {
        this.target_x = initObj.target_x
      }
      else {
        this.target_x = 0;
      }
      if (initObj.hasOwnProperty('target_y')) {
        this.target_y = initObj.target_y
      }
      else {
        this.target_y = 0;
      }
      if (initObj.hasOwnProperty('robot_allowance_error')) {
        this.robot_allowance_error = initObj.robot_allowance_error
      }
      else {
        this.robot_allowance_error = 0;
      }
      if (initObj.hasOwnProperty('robot_cali_radius')) {
        this.robot_cali_radius = initObj.robot_cali_radius
      }
      else {
        this.robot_cali_radius = 0;
      }
      if (initObj.hasOwnProperty('mf_robot_x')) {
        this.mf_robot_x = initObj.mf_robot_x
      }
      else {
        this.mf_robot_x = 0;
      }
      if (initObj.hasOwnProperty('mf_robot_y')) {
        this.mf_robot_y = initObj.mf_robot_y
      }
      else {
        this.mf_robot_y = 0;
      }
      if (initObj.hasOwnProperty('mf_ball_x')) {
        this.mf_ball_x = initObj.mf_ball_x
      }
      else {
        this.mf_ball_x = 0;
      }
      if (initObj.hasOwnProperty('mf_ball_y')) {
        this.mf_ball_y = initObj.mf_ball_y
      }
      else {
        this.mf_ball_y = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master2localization23
    // Serialize message field [goal_x]
    bufferOffset = _serializer.int64(obj.goal_x, buffer, bufferOffset);
    // Serialize message field [goal_y]
    bufferOffset = _serializer.int64(obj.goal_y, buffer, bufferOffset);
    // Serialize message field [target_x]
    bufferOffset = _serializer.int64(obj.target_x, buffer, bufferOffset);
    // Serialize message field [target_y]
    bufferOffset = _serializer.int64(obj.target_y, buffer, bufferOffset);
    // Serialize message field [robot_allowance_error]
    bufferOffset = _serializer.int64(obj.robot_allowance_error, buffer, bufferOffset);
    // Serialize message field [robot_cali_radius]
    bufferOffset = _serializer.int64(obj.robot_cali_radius, buffer, bufferOffset);
    // Serialize message field [mf_robot_x]
    bufferOffset = _serializer.int64(obj.mf_robot_x, buffer, bufferOffset);
    // Serialize message field [mf_robot_y]
    bufferOffset = _serializer.int64(obj.mf_robot_y, buffer, bufferOffset);
    // Serialize message field [mf_ball_x]
    bufferOffset = _serializer.int64(obj.mf_ball_x, buffer, bufferOffset);
    // Serialize message field [mf_ball_y]
    bufferOffset = _serializer.int64(obj.mf_ball_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master2localization23
    let len;
    let data = new master2localization23(null);
    // Deserialize message field [goal_x]
    data.goal_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [goal_y]
    data.goal_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [target_x]
    data.target_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [target_y]
    data.target_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_allowance_error]
    data.robot_allowance_error = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_cali_radius]
    data.robot_cali_radius = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [mf_robot_x]
    data.mf_robot_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [mf_robot_y]
    data.mf_robot_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [mf_ball_x]
    data.mf_ball_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [mf_ball_y]
    data.mf_ball_y = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 80;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master2localization23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'be324128966108ecba95dfb7b6938f0f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 goal_x
    int64 goal_y
    int64 target_x
    int64 target_y
    int64 robot_allowance_error
    int64 robot_cali_radius
    int64 mf_robot_x
    int64 mf_robot_y
    int64 mf_ball_x
    int64 mf_ball_y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master2localization23(null);
    if (msg.goal_x !== undefined) {
      resolved.goal_x = msg.goal_x;
    }
    else {
      resolved.goal_x = 0
    }

    if (msg.goal_y !== undefined) {
      resolved.goal_y = msg.goal_y;
    }
    else {
      resolved.goal_y = 0
    }

    if (msg.target_x !== undefined) {
      resolved.target_x = msg.target_x;
    }
    else {
      resolved.target_x = 0
    }

    if (msg.target_y !== undefined) {
      resolved.target_y = msg.target_y;
    }
    else {
      resolved.target_y = 0
    }

    if (msg.robot_allowance_error !== undefined) {
      resolved.robot_allowance_error = msg.robot_allowance_error;
    }
    else {
      resolved.robot_allowance_error = 0
    }

    if (msg.robot_cali_radius !== undefined) {
      resolved.robot_cali_radius = msg.robot_cali_radius;
    }
    else {
      resolved.robot_cali_radius = 0
    }

    if (msg.mf_robot_x !== undefined) {
      resolved.mf_robot_x = msg.mf_robot_x;
    }
    else {
      resolved.mf_robot_x = 0
    }

    if (msg.mf_robot_y !== undefined) {
      resolved.mf_robot_y = msg.mf_robot_y;
    }
    else {
      resolved.mf_robot_y = 0
    }

    if (msg.mf_ball_x !== undefined) {
      resolved.mf_ball_x = msg.mf_ball_x;
    }
    else {
      resolved.mf_ball_x = 0
    }

    if (msg.mf_ball_y !== undefined) {
      resolved.mf_ball_y = msg.mf_ball_y;
    }
    else {
      resolved.mf_ball_y = 0
    }

    return resolved;
    }
};

module.exports = master2localization23;
