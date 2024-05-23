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

class L_LC_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.L_LC_Data = null;
    }
    else {
      if (initObj.hasOwnProperty('L_LC_Data')) {
        this.L_LC_Data = initObj.L_LC_Data
      }
      else {
        this.L_LC_Data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type L_LC_msg
    // Serialize message field [L_LC_Data]
    bufferOffset = _arraySerializer.int32(obj.L_LC_Data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type L_LC_msg
    let len;
    let data = new L_LC_msg(null);
    // Deserialize message field [L_LC_Data]
    data.L_LC_Data = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.L_LC_Data.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/L_LC_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4073ba7351186b3518f6130a0a0b94b2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] L_LC_Data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new L_LC_msg(null);
    if (msg.L_LC_Data !== undefined) {
      resolved.L_LC_Data = msg.L_LC_Data;
    }
    else {
      resolved.L_LC_Data = []
    }

    return resolved;
    }
};

module.exports = L_LC_msg;
