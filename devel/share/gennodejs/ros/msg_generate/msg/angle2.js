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

class angle2 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ang_r_0 = null;
      this.ang_r_1 = null;
      this.ang_r_2 = null;
      this.ang_r_3 = null;
      this.ang_r_4 = null;
      this.ang_r_5 = null;
      this.ang_l_0 = null;
      this.ang_l_1 = null;
      this.ang_l_2 = null;
      this.ang_l_3 = null;
      this.ang_l_4 = null;
      this.ang_l_5 = null;
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
      if (initObj.hasOwnProperty('ang_r_2')) {
        this.ang_r_2 = initObj.ang_r_2
      }
      else {
        this.ang_r_2 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_r_3')) {
        this.ang_r_3 = initObj.ang_r_3
      }
      else {
        this.ang_r_3 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_r_4')) {
        this.ang_r_4 = initObj.ang_r_4
      }
      else {
        this.ang_r_4 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_r_5')) {
        this.ang_r_5 = initObj.ang_r_5
      }
      else {
        this.ang_r_5 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_0')) {
        this.ang_l_0 = initObj.ang_l_0
      }
      else {
        this.ang_l_0 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_1')) {
        this.ang_l_1 = initObj.ang_l_1
      }
      else {
        this.ang_l_1 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_2')) {
        this.ang_l_2 = initObj.ang_l_2
      }
      else {
        this.ang_l_2 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_3')) {
        this.ang_l_3 = initObj.ang_l_3
      }
      else {
        this.ang_l_3 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_4')) {
        this.ang_l_4 = initObj.ang_l_4
      }
      else {
        this.ang_l_4 = 0.0;
      }
      if (initObj.hasOwnProperty('ang_l_5')) {
        this.ang_l_5 = initObj.ang_l_5
      }
      else {
        this.ang_l_5 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type angle2
    // Serialize message field [ang_r_0]
    bufferOffset = _serializer.float64(obj.ang_r_0, buffer, bufferOffset);
    // Serialize message field [ang_r_1]
    bufferOffset = _serializer.float64(obj.ang_r_1, buffer, bufferOffset);
    // Serialize message field [ang_r_2]
    bufferOffset = _serializer.float64(obj.ang_r_2, buffer, bufferOffset);
    // Serialize message field [ang_r_3]
    bufferOffset = _serializer.float64(obj.ang_r_3, buffer, bufferOffset);
    // Serialize message field [ang_r_4]
    bufferOffset = _serializer.float64(obj.ang_r_4, buffer, bufferOffset);
    // Serialize message field [ang_r_5]
    bufferOffset = _serializer.float64(obj.ang_r_5, buffer, bufferOffset);
    // Serialize message field [ang_l_0]
    bufferOffset = _serializer.float64(obj.ang_l_0, buffer, bufferOffset);
    // Serialize message field [ang_l_1]
    bufferOffset = _serializer.float64(obj.ang_l_1, buffer, bufferOffset);
    // Serialize message field [ang_l_2]
    bufferOffset = _serializer.float64(obj.ang_l_2, buffer, bufferOffset);
    // Serialize message field [ang_l_3]
    bufferOffset = _serializer.float64(obj.ang_l_3, buffer, bufferOffset);
    // Serialize message field [ang_l_4]
    bufferOffset = _serializer.float64(obj.ang_l_4, buffer, bufferOffset);
    // Serialize message field [ang_l_5]
    bufferOffset = _serializer.float64(obj.ang_l_5, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type angle2
    let len;
    let data = new angle2(null);
    // Deserialize message field [ang_r_0]
    data.ang_r_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_1]
    data.ang_r_1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_2]
    data.ang_r_2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_3]
    data.ang_r_3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_4]
    data.ang_r_4 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_r_5]
    data.ang_r_5 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_0]
    data.ang_l_0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_1]
    data.ang_l_1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_2]
    data.ang_l_2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_3]
    data.ang_l_3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_4]
    data.ang_l_4 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ang_l_5]
    data.ang_l_5 = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 96;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/angle2';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fb3bce9c774e8adb8b04618b1b2cb9fc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 ang_r_0
    float64 ang_r_1
    float64 ang_r_2
    float64 ang_r_3
    float64 ang_r_4
    float64 ang_r_5
    float64 ang_l_0
    float64 ang_l_1
    float64 ang_l_2
    float64 ang_l_3
    float64 ang_l_4
    float64 ang_l_5
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new angle2(null);
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

    if (msg.ang_r_2 !== undefined) {
      resolved.ang_r_2 = msg.ang_r_2;
    }
    else {
      resolved.ang_r_2 = 0.0
    }

    if (msg.ang_r_3 !== undefined) {
      resolved.ang_r_3 = msg.ang_r_3;
    }
    else {
      resolved.ang_r_3 = 0.0
    }

    if (msg.ang_r_4 !== undefined) {
      resolved.ang_r_4 = msg.ang_r_4;
    }
    else {
      resolved.ang_r_4 = 0.0
    }

    if (msg.ang_r_5 !== undefined) {
      resolved.ang_r_5 = msg.ang_r_5;
    }
    else {
      resolved.ang_r_5 = 0.0
    }

    if (msg.ang_l_0 !== undefined) {
      resolved.ang_l_0 = msg.ang_l_0;
    }
    else {
      resolved.ang_l_0 = 0.0
    }

    if (msg.ang_l_1 !== undefined) {
      resolved.ang_l_1 = msg.ang_l_1;
    }
    else {
      resolved.ang_l_1 = 0.0
    }

    if (msg.ang_l_2 !== undefined) {
      resolved.ang_l_2 = msg.ang_l_2;
    }
    else {
      resolved.ang_l_2 = 0.0
    }

    if (msg.ang_l_3 !== undefined) {
      resolved.ang_l_3 = msg.ang_l_3;
    }
    else {
      resolved.ang_l_3 = 0.0
    }

    if (msg.ang_l_4 !== undefined) {
      resolved.ang_l_4 = msg.ang_l_4;
    }
    else {
      resolved.ang_l_4 = 0.0
    }

    if (msg.ang_l_5 !== undefined) {
      resolved.ang_l_5 = msg.ang_l_5;
    }
    else {
      resolved.ang_l_5 = 0.0
    }

    return resolved;
    }
};

module.exports = angle2;
