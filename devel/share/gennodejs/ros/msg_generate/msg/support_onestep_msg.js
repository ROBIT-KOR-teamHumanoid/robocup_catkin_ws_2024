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

class support_onestep_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.onestep_checker = null;
    }
    else {
      if (initObj.hasOwnProperty('onestep_checker')) {
        this.onestep_checker = initObj.onestep_checker
      }
      else {
        this.onestep_checker = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type support_onestep_msg
    // Serialize message field [onestep_checker]
    bufferOffset = _serializer.int32(obj.onestep_checker, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type support_onestep_msg
    let len;
    let data = new support_onestep_msg(null);
    // Deserialize message field [onestep_checker]
    data.onestep_checker = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/support_onestep_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '260ab72f5eacc5be420032b06460a43f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 onestep_checker
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new support_onestep_msg(null);
    if (msg.onestep_checker !== undefined) {
      resolved.onestep_checker = msg.onestep_checker;
    }
    else {
      resolved.onestep_checker = 0
    }

    return resolved;
    }
};

module.exports = support_onestep_msg;
