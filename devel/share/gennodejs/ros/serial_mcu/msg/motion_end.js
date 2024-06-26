// Auto-generated. Do not edit!

// (in-package serial_mcu.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class motion_end {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motion_end = null;
    }
    else {
      if (initObj.hasOwnProperty('motion_end')) {
        this.motion_end = initObj.motion_end
      }
      else {
        this.motion_end = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motion_end
    // Serialize message field [motion_end]
    bufferOffset = _serializer.int32(obj.motion_end, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motion_end
    let len;
    let data = new motion_end(null);
    // Deserialize message field [motion_end]
    data.motion_end = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'serial_mcu/motion_end';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3aa7962353285617f39219e4e26c45c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 motion_end
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motion_end(null);
    if (msg.motion_end !== undefined) {
      resolved.motion_end = msg.motion_end;
    }
    else {
      resolved.motion_end = 0
    }

    return resolved;
    }
};

module.exports = motion_end;
