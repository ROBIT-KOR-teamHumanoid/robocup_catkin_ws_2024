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

class motion_stop {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motion_stop = null;
    }
    else {
      if (initObj.hasOwnProperty('motion_stop')) {
        this.motion_stop = initObj.motion_stop
      }
      else {
        this.motion_stop = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motion_stop
    // Serialize message field [motion_stop]
    bufferOffset = _serializer.bool(obj.motion_stop, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motion_stop
    let len;
    let data = new motion_stop(null);
    // Deserialize message field [motion_stop]
    data.motion_stop = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/motion_stop';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '26a67ab0046f1f409ea3537c40f97362';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool motion_stop
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motion_stop(null);
    if (msg.motion_stop !== undefined) {
      resolved.motion_stop = msg.motion_stop;
    }
    else {
      resolved.motion_stop = false
    }

    return resolved;
    }
};

module.exports = motion_stop;
