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

class master2vision_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.TILT = null;
      this.PAN = null;
    }
    else {
      if (initObj.hasOwnProperty('TILT')) {
        this.TILT = initObj.TILT
      }
      else {
        this.TILT = 0.0;
      }
      if (initObj.hasOwnProperty('PAN')) {
        this.PAN = initObj.PAN
      }
      else {
        this.PAN = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master2vision_msg
    // Serialize message field [TILT]
    bufferOffset = _serializer.float64(obj.TILT, buffer, bufferOffset);
    // Serialize message field [PAN]
    bufferOffset = _serializer.float64(obj.PAN, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master2vision_msg
    let len;
    let data = new master2vision_msg(null);
    // Deserialize message field [TILT]
    data.TILT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [PAN]
    data.PAN = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master2vision_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8e3fffe76719ba65b10a2f461e54333b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 TILT
    float64 PAN
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master2vision_msg(null);
    if (msg.TILT !== undefined) {
      resolved.TILT = msg.TILT;
    }
    else {
      resolved.TILT = 0.0
    }

    if (msg.PAN !== undefined) {
      resolved.PAN = msg.PAN;
    }
    else {
      resolved.PAN = 0.0
    }

    return resolved;
    }
};

module.exports = master2vision_msg;
