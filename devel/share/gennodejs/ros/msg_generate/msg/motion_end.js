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

class motion_end {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motion_end = null;
      this.motion_ing = null;
      this.motion_start_ing = null;
      this.motion_end_ing = null;
      this.motion_num = null;
    }
    else {
      if (initObj.hasOwnProperty('motion_end')) {
        this.motion_end = initObj.motion_end
      }
      else {
        this.motion_end = 0;
      }
      if (initObj.hasOwnProperty('motion_ing')) {
        this.motion_ing = initObj.motion_ing
      }
      else {
        this.motion_ing = 0;
      }
      if (initObj.hasOwnProperty('motion_start_ing')) {
        this.motion_start_ing = initObj.motion_start_ing
      }
      else {
        this.motion_start_ing = 0;
      }
      if (initObj.hasOwnProperty('motion_end_ing')) {
        this.motion_end_ing = initObj.motion_end_ing
      }
      else {
        this.motion_end_ing = 0;
      }
      if (initObj.hasOwnProperty('motion_num')) {
        this.motion_num = initObj.motion_num
      }
      else {
        this.motion_num = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motion_end
    // Serialize message field [motion_end]
    bufferOffset = _serializer.int32(obj.motion_end, buffer, bufferOffset);
    // Serialize message field [motion_ing]
    bufferOffset = _serializer.int32(obj.motion_ing, buffer, bufferOffset);
    // Serialize message field [motion_start_ing]
    bufferOffset = _serializer.int32(obj.motion_start_ing, buffer, bufferOffset);
    // Serialize message field [motion_end_ing]
    bufferOffset = _serializer.int32(obj.motion_end_ing, buffer, bufferOffset);
    // Serialize message field [motion_num]
    bufferOffset = _serializer.int32(obj.motion_num, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motion_end
    let len;
    let data = new motion_end(null);
    // Deserialize message field [motion_end]
    data.motion_end = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [motion_ing]
    data.motion_ing = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [motion_start_ing]
    data.motion_start_ing = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [motion_end_ing]
    data.motion_end_ing = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [motion_num]
    data.motion_num = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/motion_end';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '25f699e9aaf9930abdbe2aaa9b5b0063';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 motion_end
    int32 motion_ing
    int32 motion_start_ing
    int32 motion_end_ing
    
    int32 motion_num
    
    
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

    if (msg.motion_ing !== undefined) {
      resolved.motion_ing = msg.motion_ing;
    }
    else {
      resolved.motion_ing = 0
    }

    if (msg.motion_start_ing !== undefined) {
      resolved.motion_start_ing = msg.motion_start_ing;
    }
    else {
      resolved.motion_start_ing = 0
    }

    if (msg.motion_end_ing !== undefined) {
      resolved.motion_end_ing = msg.motion_end_ing;
    }
    else {
      resolved.motion_end_ing = 0
    }

    if (msg.motion_num !== undefined) {
      resolved.motion_num = msg.motion_num;
    }
    else {
      resolved.motion_num = 0
    }

    return resolved;
    }
};

module.exports = motion_end;
