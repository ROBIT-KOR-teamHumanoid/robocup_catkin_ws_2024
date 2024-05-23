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

class motion_operator_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.yaw_data = null;
      this.startmotion = null;
    }
    else {
      if (initObj.hasOwnProperty('yaw_data')) {
        this.yaw_data = initObj.yaw_data
      }
      else {
        this.yaw_data = 0;
      }
      if (initObj.hasOwnProperty('startmotion')) {
        this.startmotion = initObj.startmotion
      }
      else {
        this.startmotion = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motion_operator_data
    // Serialize message field [yaw_data]
    bufferOffset = _serializer.int32(obj.yaw_data, buffer, bufferOffset);
    // Serialize message field [startmotion]
    bufferOffset = _serializer.int32(obj.startmotion, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motion_operator_data
    let len;
    let data = new motion_operator_data(null);
    // Deserialize message field [yaw_data]
    data.yaw_data = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [startmotion]
    data.startmotion = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/motion_operator_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ca7ee85fd473a08527f7d102be53f660';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 yaw_data
    int32 startmotion
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motion_operator_data(null);
    if (msg.yaw_data !== undefined) {
      resolved.yaw_data = msg.yaw_data;
    }
    else {
      resolved.yaw_data = 0
    }

    if (msg.startmotion !== undefined) {
      resolved.startmotion = msg.startmotion;
    }
    else {
      resolved.startmotion = 0
    }

    return resolved;
    }
};

module.exports = motion_operator_data;
