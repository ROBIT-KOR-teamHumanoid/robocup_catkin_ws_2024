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

class walk_pattern {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.xlpattern = null;
      this.ylpattern = null;
      this.zlpattern = null;
      this.slpattern = null;
      this.tlpattern = null;
      this.xrpattern = null;
      this.yrpattern = null;
      this.zrpattern = null;
      this.srpattern = null;
      this.trpattern = null;
    }
    else {
      if (initObj.hasOwnProperty('xlpattern')) {
        this.xlpattern = initObj.xlpattern
      }
      else {
        this.xlpattern = 0.0;
      }
      if (initObj.hasOwnProperty('ylpattern')) {
        this.ylpattern = initObj.ylpattern
      }
      else {
        this.ylpattern = 0.0;
      }
      if (initObj.hasOwnProperty('zlpattern')) {
        this.zlpattern = initObj.zlpattern
      }
      else {
        this.zlpattern = 0.0;
      }
      if (initObj.hasOwnProperty('slpattern')) {
        this.slpattern = initObj.slpattern
      }
      else {
        this.slpattern = 0.0;
      }
      if (initObj.hasOwnProperty('tlpattern')) {
        this.tlpattern = initObj.tlpattern
      }
      else {
        this.tlpattern = 0.0;
      }
      if (initObj.hasOwnProperty('xrpattern')) {
        this.xrpattern = initObj.xrpattern
      }
      else {
        this.xrpattern = 0.0;
      }
      if (initObj.hasOwnProperty('yrpattern')) {
        this.yrpattern = initObj.yrpattern
      }
      else {
        this.yrpattern = 0.0;
      }
      if (initObj.hasOwnProperty('zrpattern')) {
        this.zrpattern = initObj.zrpattern
      }
      else {
        this.zrpattern = 0.0;
      }
      if (initObj.hasOwnProperty('srpattern')) {
        this.srpattern = initObj.srpattern
      }
      else {
        this.srpattern = 0.0;
      }
      if (initObj.hasOwnProperty('trpattern')) {
        this.trpattern = initObj.trpattern
      }
      else {
        this.trpattern = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type walk_pattern
    // Serialize message field [xlpattern]
    bufferOffset = _serializer.float64(obj.xlpattern, buffer, bufferOffset);
    // Serialize message field [ylpattern]
    bufferOffset = _serializer.float64(obj.ylpattern, buffer, bufferOffset);
    // Serialize message field [zlpattern]
    bufferOffset = _serializer.float64(obj.zlpattern, buffer, bufferOffset);
    // Serialize message field [slpattern]
    bufferOffset = _serializer.float64(obj.slpattern, buffer, bufferOffset);
    // Serialize message field [tlpattern]
    bufferOffset = _serializer.float64(obj.tlpattern, buffer, bufferOffset);
    // Serialize message field [xrpattern]
    bufferOffset = _serializer.float64(obj.xrpattern, buffer, bufferOffset);
    // Serialize message field [yrpattern]
    bufferOffset = _serializer.float64(obj.yrpattern, buffer, bufferOffset);
    // Serialize message field [zrpattern]
    bufferOffset = _serializer.float64(obj.zrpattern, buffer, bufferOffset);
    // Serialize message field [srpattern]
    bufferOffset = _serializer.float64(obj.srpattern, buffer, bufferOffset);
    // Serialize message field [trpattern]
    bufferOffset = _serializer.float64(obj.trpattern, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type walk_pattern
    let len;
    let data = new walk_pattern(null);
    // Deserialize message field [xlpattern]
    data.xlpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ylpattern]
    data.ylpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [zlpattern]
    data.zlpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [slpattern]
    data.slpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [tlpattern]
    data.tlpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [xrpattern]
    data.xrpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yrpattern]
    data.yrpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [zrpattern]
    data.zrpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [srpattern]
    data.srpattern = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [trpattern]
    data.trpattern = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 80;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/walk_pattern';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bb4fe551ab158f80aba28048dfbba352';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 xlpattern
    float64 ylpattern
    float64 zlpattern
    float64 slpattern
    float64 tlpattern
    float64 xrpattern
    float64 yrpattern
    float64 zrpattern
    float64 srpattern
    float64 trpattern
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new walk_pattern(null);
    if (msg.xlpattern !== undefined) {
      resolved.xlpattern = msg.xlpattern;
    }
    else {
      resolved.xlpattern = 0.0
    }

    if (msg.ylpattern !== undefined) {
      resolved.ylpattern = msg.ylpattern;
    }
    else {
      resolved.ylpattern = 0.0
    }

    if (msg.zlpattern !== undefined) {
      resolved.zlpattern = msg.zlpattern;
    }
    else {
      resolved.zlpattern = 0.0
    }

    if (msg.slpattern !== undefined) {
      resolved.slpattern = msg.slpattern;
    }
    else {
      resolved.slpattern = 0.0
    }

    if (msg.tlpattern !== undefined) {
      resolved.tlpattern = msg.tlpattern;
    }
    else {
      resolved.tlpattern = 0.0
    }

    if (msg.xrpattern !== undefined) {
      resolved.xrpattern = msg.xrpattern;
    }
    else {
      resolved.xrpattern = 0.0
    }

    if (msg.yrpattern !== undefined) {
      resolved.yrpattern = msg.yrpattern;
    }
    else {
      resolved.yrpattern = 0.0
    }

    if (msg.zrpattern !== undefined) {
      resolved.zrpattern = msg.zrpattern;
    }
    else {
      resolved.zrpattern = 0.0
    }

    if (msg.srpattern !== undefined) {
      resolved.srpattern = msg.srpattern;
    }
    else {
      resolved.srpattern = 0.0
    }

    if (msg.trpattern !== undefined) {
      resolved.trpattern = msg.trpattern;
    }
    else {
      resolved.trpattern = 0.0
    }

    return resolved;
    }
};

module.exports = walk_pattern;
