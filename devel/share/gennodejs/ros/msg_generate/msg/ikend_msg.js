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

class ikend_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ikend = null;
      this.onestep_end = null;
    }
    else {
      if (initObj.hasOwnProperty('ikend')) {
        this.ikend = initObj.ikend
      }
      else {
        this.ikend = 0;
      }
      if (initObj.hasOwnProperty('onestep_end')) {
        this.onestep_end = initObj.onestep_end
      }
      else {
        this.onestep_end = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ikend_msg
    // Serialize message field [ikend]
    bufferOffset = _serializer.int32(obj.ikend, buffer, bufferOffset);
    // Serialize message field [onestep_end]
    bufferOffset = _serializer.int32(obj.onestep_end, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ikend_msg
    let len;
    let data = new ikend_msg(null);
    // Deserialize message field [ikend]
    data.ikend = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [onestep_end]
    data.onestep_end = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/ikend_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '927f1106013c7f12a325ab4e0c8eb54f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 ikend
    int32 onestep_end
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ikend_msg(null);
    if (msg.ikend !== undefined) {
      resolved.ikend = msg.ikend;
    }
    else {
      resolved.ikend = 0
    }

    if (msg.onestep_end !== undefined) {
      resolved.onestep_end = msg.onestep_end;
    }
    else {
      resolved.onestep_end = 0
    }

    return resolved;
    }
};

module.exports = ikend_msg;
