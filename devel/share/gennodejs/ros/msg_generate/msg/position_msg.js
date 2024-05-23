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

class position_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robot_area = null;
      this.ball_area = null;
      this.yaw = null;
    }
    else {
      if (initObj.hasOwnProperty('robot_area')) {
        this.robot_area = initObj.robot_area
      }
      else {
        this.robot_area = 0;
      }
      if (initObj.hasOwnProperty('ball_area')) {
        this.ball_area = initObj.ball_area
      }
      else {
        this.ball_area = 0;
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type position_msg
    // Serialize message field [robot_area]
    bufferOffset = _serializer.int64(obj.robot_area, buffer, bufferOffset);
    // Serialize message field [ball_area]
    bufferOffset = _serializer.int64(obj.ball_area, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.int64(obj.yaw, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type position_msg
    let len;
    let data = new position_msg(null);
    // Deserialize message field [robot_area]
    data.robot_area = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ball_area]
    data.ball_area = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/position_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '592ace443c869809edf4b9d783f51103';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robot_area
    int64 ball_area
    int64 yaw
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new position_msg(null);
    if (msg.robot_area !== undefined) {
      resolved.robot_area = msg.robot_area;
    }
    else {
      resolved.robot_area = 0
    }

    if (msg.ball_area !== undefined) {
      resolved.ball_area = msg.ball_area;
    }
    else {
      resolved.ball_area = 0
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0
    }

    return resolved;
    }
};

module.exports = position_msg;
