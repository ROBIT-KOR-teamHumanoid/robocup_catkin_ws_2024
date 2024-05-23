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

class com_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X_com = null;
      this.Y_com = null;
    }
    else {
      if (initObj.hasOwnProperty('X_com')) {
        this.X_com = initObj.X_com
      }
      else {
        this.X_com = 0.0;
      }
      if (initObj.hasOwnProperty('Y_com')) {
        this.Y_com = initObj.Y_com
      }
      else {
        this.Y_com = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type com_msg
    // Serialize message field [X_com]
    bufferOffset = _serializer.float64(obj.X_com, buffer, bufferOffset);
    // Serialize message field [Y_com]
    bufferOffset = _serializer.float64(obj.Y_com, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type com_msg
    let len;
    let data = new com_msg(null);
    // Deserialize message field [X_com]
    data.X_com = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Y_com]
    data.Y_com = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/com_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '47867f34a56c5603eede6e151741abd1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 X_com
    float64 Y_com
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new com_msg(null);
    if (msg.X_com !== undefined) {
      resolved.X_com = msg.X_com;
    }
    else {
      resolved.X_com = 0.0
    }

    if (msg.Y_com !== undefined) {
      resolved.Y_com = msg.Y_com;
    }
    else {
      resolved.Y_com = 0.0
    }

    return resolved;
    }
};

module.exports = com_msg;
