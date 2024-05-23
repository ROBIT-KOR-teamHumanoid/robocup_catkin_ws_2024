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

class motion_balance {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Left_10 = null;
      this.Right_11 = null;
      this.Left_14 = null;
      this.Right_15 = null;
      this.Left_16 = null;
      this.Right_17 = null;
      this.Left_18 = null;
      this.Right_19 = null;
      this.Left_20 = null;
      this.Right_21 = null;
      this.support_L = null;
      this.support_R = null;
      this.support_B = null;
    }
    else {
      if (initObj.hasOwnProperty('Left_10')) {
        this.Left_10 = initObj.Left_10
      }
      else {
        this.Left_10 = 0.0;
      }
      if (initObj.hasOwnProperty('Right_11')) {
        this.Right_11 = initObj.Right_11
      }
      else {
        this.Right_11 = 0.0;
      }
      if (initObj.hasOwnProperty('Left_14')) {
        this.Left_14 = initObj.Left_14
      }
      else {
        this.Left_14 = 0.0;
      }
      if (initObj.hasOwnProperty('Right_15')) {
        this.Right_15 = initObj.Right_15
      }
      else {
        this.Right_15 = 0.0;
      }
      if (initObj.hasOwnProperty('Left_16')) {
        this.Left_16 = initObj.Left_16
      }
      else {
        this.Left_16 = 0.0;
      }
      if (initObj.hasOwnProperty('Right_17')) {
        this.Right_17 = initObj.Right_17
      }
      else {
        this.Right_17 = 0.0;
      }
      if (initObj.hasOwnProperty('Left_18')) {
        this.Left_18 = initObj.Left_18
      }
      else {
        this.Left_18 = 0.0;
      }
      if (initObj.hasOwnProperty('Right_19')) {
        this.Right_19 = initObj.Right_19
      }
      else {
        this.Right_19 = 0.0;
      }
      if (initObj.hasOwnProperty('Left_20')) {
        this.Left_20 = initObj.Left_20
      }
      else {
        this.Left_20 = 0.0;
      }
      if (initObj.hasOwnProperty('Right_21')) {
        this.Right_21 = initObj.Right_21
      }
      else {
        this.Right_21 = 0.0;
      }
      if (initObj.hasOwnProperty('support_L')) {
        this.support_L = initObj.support_L
      }
      else {
        this.support_L = false;
      }
      if (initObj.hasOwnProperty('support_R')) {
        this.support_R = initObj.support_R
      }
      else {
        this.support_R = false;
      }
      if (initObj.hasOwnProperty('support_B')) {
        this.support_B = initObj.support_B
      }
      else {
        this.support_B = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motion_balance
    // Serialize message field [Left_10]
    bufferOffset = _serializer.float32(obj.Left_10, buffer, bufferOffset);
    // Serialize message field [Right_11]
    bufferOffset = _serializer.float32(obj.Right_11, buffer, bufferOffset);
    // Serialize message field [Left_14]
    bufferOffset = _serializer.float32(obj.Left_14, buffer, bufferOffset);
    // Serialize message field [Right_15]
    bufferOffset = _serializer.float32(obj.Right_15, buffer, bufferOffset);
    // Serialize message field [Left_16]
    bufferOffset = _serializer.float32(obj.Left_16, buffer, bufferOffset);
    // Serialize message field [Right_17]
    bufferOffset = _serializer.float32(obj.Right_17, buffer, bufferOffset);
    // Serialize message field [Left_18]
    bufferOffset = _serializer.float32(obj.Left_18, buffer, bufferOffset);
    // Serialize message field [Right_19]
    bufferOffset = _serializer.float32(obj.Right_19, buffer, bufferOffset);
    // Serialize message field [Left_20]
    bufferOffset = _serializer.float32(obj.Left_20, buffer, bufferOffset);
    // Serialize message field [Right_21]
    bufferOffset = _serializer.float32(obj.Right_21, buffer, bufferOffset);
    // Serialize message field [support_L]
    bufferOffset = _serializer.bool(obj.support_L, buffer, bufferOffset);
    // Serialize message field [support_R]
    bufferOffset = _serializer.bool(obj.support_R, buffer, bufferOffset);
    // Serialize message field [support_B]
    bufferOffset = _serializer.bool(obj.support_B, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motion_balance
    let len;
    let data = new motion_balance(null);
    // Deserialize message field [Left_10]
    data.Left_10 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Right_11]
    data.Right_11 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Left_14]
    data.Left_14 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Right_15]
    data.Right_15 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Left_16]
    data.Left_16 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Right_17]
    data.Right_17 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Left_18]
    data.Left_18 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Right_19]
    data.Right_19 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Left_20]
    data.Left_20 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Right_21]
    data.Right_21 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [support_L]
    data.support_L = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [support_R]
    data.support_R = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [support_B]
    data.support_B = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 43;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/motion_balance';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '03d17ac032478d225abd4895f2c60b7c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 Left_10
    float32 Right_11
    float32 Left_14
    float32 Right_15
    float32 Left_16
    float32 Right_17
    float32 Left_18
    float32 Right_19
    float32 Left_20
    float32 Right_21
    
    bool support_L
    bool support_R
    bool support_B
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motion_balance(null);
    if (msg.Left_10 !== undefined) {
      resolved.Left_10 = msg.Left_10;
    }
    else {
      resolved.Left_10 = 0.0
    }

    if (msg.Right_11 !== undefined) {
      resolved.Right_11 = msg.Right_11;
    }
    else {
      resolved.Right_11 = 0.0
    }

    if (msg.Left_14 !== undefined) {
      resolved.Left_14 = msg.Left_14;
    }
    else {
      resolved.Left_14 = 0.0
    }

    if (msg.Right_15 !== undefined) {
      resolved.Right_15 = msg.Right_15;
    }
    else {
      resolved.Right_15 = 0.0
    }

    if (msg.Left_16 !== undefined) {
      resolved.Left_16 = msg.Left_16;
    }
    else {
      resolved.Left_16 = 0.0
    }

    if (msg.Right_17 !== undefined) {
      resolved.Right_17 = msg.Right_17;
    }
    else {
      resolved.Right_17 = 0.0
    }

    if (msg.Left_18 !== undefined) {
      resolved.Left_18 = msg.Left_18;
    }
    else {
      resolved.Left_18 = 0.0
    }

    if (msg.Right_19 !== undefined) {
      resolved.Right_19 = msg.Right_19;
    }
    else {
      resolved.Right_19 = 0.0
    }

    if (msg.Left_20 !== undefined) {
      resolved.Left_20 = msg.Left_20;
    }
    else {
      resolved.Left_20 = 0.0
    }

    if (msg.Right_21 !== undefined) {
      resolved.Right_21 = msg.Right_21;
    }
    else {
      resolved.Right_21 = 0.0
    }

    if (msg.support_L !== undefined) {
      resolved.support_L = msg.support_L;
    }
    else {
      resolved.support_L = false
    }

    if (msg.support_R !== undefined) {
      resolved.support_R = msg.support_R;
    }
    else {
      resolved.support_R = false
    }

    if (msg.support_B !== undefined) {
      resolved.support_B = msg.support_B;
    }
    else {
      resolved.support_B = false
    }

    return resolved;
    }
};

module.exports = motion_balance;
