// Auto-generated. Do not edit!

// (in-package msg_generate.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Local_msg = require('./Local_msg.js');

//-----------------------------------------------------------

class Local_Info {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.featureData = null;
    }
    else {
      if (initObj.hasOwnProperty('featureData')) {
        this.featureData = initObj.featureData
      }
      else {
        this.featureData = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Local_Info
    // Serialize message field [featureData]
    // Serialize the length for message field [featureData]
    bufferOffset = _serializer.uint32(obj.featureData.length, buffer, bufferOffset);
    obj.featureData.forEach((val) => {
      bufferOffset = Local_msg.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Local_Info
    let len;
    let data = new Local_Info(null);
    // Deserialize message field [featureData]
    // Deserialize array length for message field [featureData]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.featureData = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.featureData[i] = Local_msg.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 24 * object.featureData.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/Local_Info';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'db10bb32b399e072a5d60b68deb7697e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Local_msg[] featureData
    
    ================================================================================
    MSG: msg_generate/Local_msg
    float64 Id
    float64 dist
    float64 theta
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Local_Info(null);
    if (msg.featureData !== undefined) {
      resolved.featureData = new Array(msg.featureData.length);
      for (let i = 0; i < resolved.featureData.length; ++i) {
        resolved.featureData[i] = Local_msg.Resolve(msg.featureData[i]);
      }
    }
    else {
      resolved.featureData = []
    }

    return resolved;
    }
};

module.exports = Local_Info;
