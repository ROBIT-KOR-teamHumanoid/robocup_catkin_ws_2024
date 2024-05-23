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

class Serial2LC_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.R_LC_Data = null;
      this.L_LC_Data = null;
    }
    else {
      if (initObj.hasOwnProperty('R_LC_Data')) {
        this.R_LC_Data = initObj.R_LC_Data
      }
      else {
        this.R_LC_Data = [];
      }
      if (initObj.hasOwnProperty('L_LC_Data')) {
        this.L_LC_Data = initObj.L_LC_Data
      }
      else {
        this.L_LC_Data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Serial2LC_msg
    // Serialize message field [R_LC_Data]
    bufferOffset = _arraySerializer.int32(obj.R_LC_Data, buffer, bufferOffset, null);
    // Serialize message field [L_LC_Data]
    bufferOffset = _arraySerializer.int32(obj.L_LC_Data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Serial2LC_msg
    let len;
    let data = new Serial2LC_msg(null);
    // Deserialize message field [R_LC_Data]
    data.R_LC_Data = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [L_LC_Data]
    data.L_LC_Data = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.R_LC_Data.length;
    length += 4 * object.L_LC_Data.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/Serial2LC_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '16af27aff42ac803037661af665964ee';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] R_LC_Data
    int32[] L_LC_Data
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Serial2LC_msg(null);
    if (msg.R_LC_Data !== undefined) {
      resolved.R_LC_Data = msg.R_LC_Data;
    }
    else {
      resolved.R_LC_Data = []
    }

    if (msg.L_LC_Data !== undefined) {
      resolved.L_LC_Data = msg.L_LC_Data;
    }
    else {
      resolved.L_LC_Data = []
    }

    return resolved;
    }
};

module.exports = Serial2LC_msg;
