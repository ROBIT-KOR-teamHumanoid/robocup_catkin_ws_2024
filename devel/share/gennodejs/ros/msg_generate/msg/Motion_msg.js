// Auto-generated. Do not edit!

// (in-package msg_generate.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Step_msg = require('./Step_msg.js');

//-----------------------------------------------------------

class Motion_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.max_step = null;
      this.repeat = null;
      this.acc = null;
      this.motion_data = null;
    }
    else {
      if (initObj.hasOwnProperty('max_step')) {
        this.max_step = initObj.max_step
      }
      else {
        this.max_step = 0;
      }
      if (initObj.hasOwnProperty('repeat')) {
        this.repeat = initObj.repeat
      }
      else {
        this.repeat = 0;
      }
      if (initObj.hasOwnProperty('acc')) {
        this.acc = initObj.acc
      }
      else {
        this.acc = 0;
      }
      if (initObj.hasOwnProperty('motion_data')) {
        this.motion_data = initObj.motion_data
      }
      else {
        this.motion_data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Motion_msg
    // Serialize message field [max_step]
    bufferOffset = _serializer.uint32(obj.max_step, buffer, bufferOffset);
    // Serialize message field [repeat]
    bufferOffset = _serializer.uint32(obj.repeat, buffer, bufferOffset);
    // Serialize message field [acc]
    bufferOffset = _serializer.uint32(obj.acc, buffer, bufferOffset);
    // Serialize message field [motion_data]
    // Serialize the length for message field [motion_data]
    bufferOffset = _serializer.uint32(obj.motion_data.length, buffer, bufferOffset);
    obj.motion_data.forEach((val) => {
      bufferOffset = Step_msg.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Motion_msg
    let len;
    let data = new Motion_msg(null);
    // Deserialize message field [max_step]
    data.max_step = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [repeat]
    data.repeat = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [acc]
    data.acc = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [motion_data]
    // Deserialize array length for message field [motion_data]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.motion_data = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.motion_data[i] = Step_msg.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.motion_data.forEach((val) => {
      length += Step_msg.getMessageSize(val);
    });
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/Motion_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fbcb902fe8f910d4d1cd05b17d5ee522';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 max_step
    uint32 repeat
    uint32 acc
    Step_msg[] motion_data
    
    ================================================================================
    MSG: msg_generate/Step_msg
    int32 delay
    int32 time
    int32[] id
    int32[] position
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Motion_msg(null);
    if (msg.max_step !== undefined) {
      resolved.max_step = msg.max_step;
    }
    else {
      resolved.max_step = 0
    }

    if (msg.repeat !== undefined) {
      resolved.repeat = msg.repeat;
    }
    else {
      resolved.repeat = 0
    }

    if (msg.acc !== undefined) {
      resolved.acc = msg.acc;
    }
    else {
      resolved.acc = 0
    }

    if (msg.motion_data !== undefined) {
      resolved.motion_data = new Array(msg.motion_data.length);
      for (let i = 0; i < resolved.motion_data.length; ++i) {
        resolved.motion_data[i] = Step_msg.Resolve(msg.motion_data[i]);
      }
    }
    else {
      resolved.motion_data = []
    }

    return resolved;
    }
};

module.exports = Motion_msg;
