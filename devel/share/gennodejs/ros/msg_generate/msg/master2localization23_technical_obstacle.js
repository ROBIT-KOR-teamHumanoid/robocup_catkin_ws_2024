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

class master2localization23_technical_obstacle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sector = null;
      this.obs_1 = null;
      this.obs_2 = null;
    }
    else {
      if (initObj.hasOwnProperty('sector')) {
        this.sector = initObj.sector
      }
      else {
        this.sector = 0;
      }
      if (initObj.hasOwnProperty('obs_1')) {
        this.obs_1 = initObj.obs_1
      }
      else {
        this.obs_1 = 0;
      }
      if (initObj.hasOwnProperty('obs_2')) {
        this.obs_2 = initObj.obs_2
      }
      else {
        this.obs_2 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master2localization23_technical_obstacle
    // Serialize message field [sector]
    bufferOffset = _serializer.int64(obj.sector, buffer, bufferOffset);
    // Serialize message field [obs_1]
    bufferOffset = _serializer.int64(obj.obs_1, buffer, bufferOffset);
    // Serialize message field [obs_2]
    bufferOffset = _serializer.int64(obj.obs_2, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master2localization23_technical_obstacle
    let len;
    let data = new master2localization23_technical_obstacle(null);
    // Deserialize message field [sector]
    data.sector = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [obs_1]
    data.obs_1 = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [obs_2]
    data.obs_2 = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master2localization23_technical_obstacle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '84cbbda57e228d1e1a9085de32393705';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 sector
    int64 obs_1
    int64 obs_2
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master2localization23_technical_obstacle(null);
    if (msg.sector !== undefined) {
      resolved.sector = msg.sector;
    }
    else {
      resolved.sector = 0
    }

    if (msg.obs_1 !== undefined) {
      resolved.obs_1 = msg.obs_1;
    }
    else {
      resolved.obs_1 = 0
    }

    if (msg.obs_2 !== undefined) {
      resolved.obs_2 = msg.obs_2;
    }
    else {
      resolved.obs_2 = 0
    }

    return resolved;
    }
};

module.exports = master2localization23_technical_obstacle;
