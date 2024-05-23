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

class wheel_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ang_r_0 = null;
      this.ang_r_1 = null;
    }
    else {
      if (initObj.hasOwnProperty('ang_r_0')) {
        this.ang_r_0 = initObj.ang_r_0
      }
      else {
        this.ang_r_0 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_r_1')) {
        this.ang_r_1 = initObj.ang_r_1
      }
      else {
        this.ang_r_1 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type wheel_msg
    // Serialize message field [ang_r_0]
    bufferOffset = _serializer.float64(obj.ang_r_0, buffer, bufferOffset);
    // Serialize message field [ang_r_1]
    bufferOffset = _serializer.float64(obj.ang_r_1, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type wheel_msg
    let len;
    let data = new wheel_msg(null);
    // Deserialize message field [ang_r_0]
    data.ang_r_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_1]
    data.ang_r_1 = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/wheel_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '56b78b37c2cdbee448584402f58a25fd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 ang_r_0
    float64 ang_r_1
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new wheel_msg(null);
    if (msg.ang_r_0 !== undefined) {
      resolved.ang_r_0 = msg.ang_r_0;
    }
    else {
      resolved.ang_r_0 = 0.0
    }

    if (msg.ang_r_1 !== undefined) {
      resolved.ang_r_1 = msg.ang_r_1;
    }
    else {
      resolved.ang_r_1 = 0.0
    }

    return resolved;
    }
};

module.exports = wheel_msg;
