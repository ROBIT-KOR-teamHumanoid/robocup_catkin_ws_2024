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

class master2localization24 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal_x = null;
      this.goal_y = null;
      this.target_x = null;
      this.target_y = null;
      this.robot_allowance_error = null;
      this.robot_cali_radius = null;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master2localization24
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
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master2localization24
    let len;
    let data = new master2localization24(null);
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
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master2localization24';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '327d5f269dd6e3ee84371d4f5cf9b95e';
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
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master2localization24(null);
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

    return resolved;
    }
};

module.exports = master2localization24;
