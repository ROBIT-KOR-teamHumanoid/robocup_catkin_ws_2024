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

class master2hanoi_vision2019msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.color_what = null;
      this.alpha_check = null;
    }
    else {
      if (initObj.hasOwnProperty('color_what')) {
        this.color_what = initObj.color_what
      }
      else {
        this.color_what = 0;
      }
      if (initObj.hasOwnProperty('alpha_check')) {
        this.alpha_check = initObj.alpha_check
      }
      else {
        this.alpha_check = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master2hanoi_vision2019msg
    // Serialize message field [color_what]
    bufferOffset = _serializer.int32(obj.color_what, buffer, bufferOffset);
    // Serialize message field [alpha_check]
    bufferOffset = _serializer.bool(obj.alpha_check, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master2hanoi_vision2019msg
    let len;
    let data = new master2hanoi_vision2019msg(null);
    // Deserialize message field [color_what]
    data.color_what = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [alpha_check]
    data.alpha_check = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master2hanoi_vision2019msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0da4621181e0545911e6b295c023e0d4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 color_what
    bool alpha_check
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master2hanoi_vision2019msg(null);
    if (msg.color_what !== undefined) {
      resolved.color_what = msg.color_what;
    }
    else {
      resolved.color_what = 0
    }

    if (msg.alpha_check !== undefined) {
      resolved.alpha_check = msg.alpha_check;
    }
    else {
      resolved.alpha_check = false
    }

    return resolved;
    }
};

module.exports = master2hanoi_vision2019msg;
