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

class HSV {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.red1_dis = null;
      this.red1_the = null;
      this.red2_dis = null;
      this.red2_the = null;
      this.blue1_dis = null;
      this.blue1_the = null;
      this.blue2_dis = null;
      this.blue2_the = null;
    }
    else {
      if (initObj.hasOwnProperty('red1_dis')) {
        this.red1_dis = initObj.red1_dis
      }
      else {
        this.red1_dis = 0.0;
      }
      if (initObj.hasOwnProperty('red1_the')) {
        this.red1_the = initObj.red1_the
      }
      else {
        this.red1_the = 0.0;
      }
      if (initObj.hasOwnProperty('red2_dis')) {
        this.red2_dis = initObj.red2_dis
      }
      else {
        this.red2_dis = 0.0;
      }
      if (initObj.hasOwnProperty('red2_the')) {
        this.red2_the = initObj.red2_the
      }
      else {
        this.red2_the = 0.0;
      }
      if (initObj.hasOwnProperty('blue1_dis')) {
        this.blue1_dis = initObj.blue1_dis
      }
      else {
        this.blue1_dis = 0.0;
      }
      if (initObj.hasOwnProperty('blue1_the')) {
        this.blue1_the = initObj.blue1_the
      }
      else {
        this.blue1_the = 0.0;
      }
      if (initObj.hasOwnProperty('blue2_dis')) {
        this.blue2_dis = initObj.blue2_dis
      }
      else {
        this.blue2_dis = 0.0;
      }
      if (initObj.hasOwnProperty('blue2_the')) {
        this.blue2_the = initObj.blue2_the
      }
      else {
        this.blue2_the = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HSV
    // Serialize message field [red1_dis]
    bufferOffset = _serializer.float64(obj.red1_dis, buffer, bufferOffset);
    // Serialize message field [red1_the]
    bufferOffset = _serializer.float64(obj.red1_the, buffer, bufferOffset);
    // Serialize message field [red2_dis]
    bufferOffset = _serializer.float64(obj.red2_dis, buffer, bufferOffset);
    // Serialize message field [red2_the]
    bufferOffset = _serializer.float64(obj.red2_the, buffer, bufferOffset);
    // Serialize message field [blue1_dis]
    bufferOffset = _serializer.float64(obj.blue1_dis, buffer, bufferOffset);
    // Serialize message field [blue1_the]
    bufferOffset = _serializer.float64(obj.blue1_the, buffer, bufferOffset);
    // Serialize message field [blue2_dis]
    bufferOffset = _serializer.float64(obj.blue2_dis, buffer, bufferOffset);
    // Serialize message field [blue2_the]
    bufferOffset = _serializer.float64(obj.blue2_the, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HSV
    let len;
    let data = new HSV(null);
    // Deserialize message field [red1_dis]
    data.red1_dis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [red1_the]
    data.red1_the = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [red2_dis]
    data.red2_dis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [red2_the]
    data.red2_the = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [blue1_dis]
    data.blue1_dis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [blue1_the]
    data.blue1_the = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [blue2_dis]
    data.blue2_dis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [blue2_the]
    data.blue2_the = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 64;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/HSV';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5e59624369bde37201fa1c7dfe803e91';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 red1_dis
    float64 red1_the
    float64 red2_dis
    float64 red2_the
    float64 blue1_dis
    float64 blue1_the
    float64 blue2_dis
    float64 blue2_the
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new HSV(null);
    if (msg.red1_dis !== undefined) {
      resolved.red1_dis = msg.red1_dis;
    }
    else {
      resolved.red1_dis = 0.0
    }

    if (msg.red1_the !== undefined) {
      resolved.red1_the = msg.red1_the;
    }
    else {
      resolved.red1_the = 0.0
    }

    if (msg.red2_dis !== undefined) {
      resolved.red2_dis = msg.red2_dis;
    }
    else {
      resolved.red2_dis = 0.0
    }

    if (msg.red2_the !== undefined) {
      resolved.red2_the = msg.red2_the;
    }
    else {
      resolved.red2_the = 0.0
    }

    if (msg.blue1_dis !== undefined) {
      resolved.blue1_dis = msg.blue1_dis;
    }
    else {
      resolved.blue1_dis = 0.0
    }

    if (msg.blue1_the !== undefined) {
      resolved.blue1_the = msg.blue1_the;
    }
    else {
      resolved.blue1_the = 0.0
    }

    if (msg.blue2_dis !== undefined) {
      resolved.blue2_dis = msg.blue2_dis;
    }
    else {
      resolved.blue2_dis = 0.0
    }

    if (msg.blue2_the !== undefined) {
      resolved.blue2_the = msg.blue2_the;
    }
    else {
      resolved.blue2_the = 0.0
    }

    return resolved;
    }
};

module.exports = HSV;
