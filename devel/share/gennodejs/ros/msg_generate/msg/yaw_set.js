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

class yaw_set {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isYawSet = null;
    }
    else {
      if (initObj.hasOwnProperty('isYawSet')) {
        this.isYawSet = initObj.isYawSet
      }
      else {
        this.isYawSet = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type yaw_set
    // Serialize message field [isYawSet]
    bufferOffset = _serializer.bool(obj.isYawSet, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type yaw_set
    let len;
    let data = new yaw_set(null);
    // Deserialize message field [isYawSet]
    data.isYawSet = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/yaw_set';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dd1fd0ebc1d42598eb0e74fe046655f8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool isYawSet
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new yaw_set(null);
    if (msg.isYawSet !== undefined) {
      resolved.isYawSet = msg.isYawSet;
    }
    else {
      resolved.isYawSet = false
    }

    return resolved;
    }
};

module.exports = yaw_set;
