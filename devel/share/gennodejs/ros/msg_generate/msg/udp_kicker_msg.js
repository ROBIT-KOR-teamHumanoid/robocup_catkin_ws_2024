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

class udp_kicker_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robot_num = null;
      this.robot_case = null;
      this.local_x = null;
      this.local_y = null;
      this.local_yaw = null;
    }
    else {
      if (initObj.hasOwnProperty('robot_num')) {
        this.robot_num = initObj.robot_num
      }
      else {
        this.robot_num = 0;
      }
      if (initObj.hasOwnProperty('robot_case')) {
        this.robot_case = initObj.robot_case
      }
      else {
        this.robot_case = 0;
      }
      if (initObj.hasOwnProperty('local_x')) {
        this.local_x = initObj.local_x
      }
      else {
        this.local_x = 0;
      }
      if (initObj.hasOwnProperty('local_y')) {
        this.local_y = initObj.local_y
      }
      else {
        this.local_y = 0;
      }
      if (initObj.hasOwnProperty('local_yaw')) {
        this.local_yaw = initObj.local_yaw
      }
      else {
        this.local_yaw = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type udp_kicker_msg
    // Serialize message field [robot_num]
    bufferOffset = _serializer.int64(obj.robot_num, buffer, bufferOffset);
    // Serialize message field [robot_case]
    bufferOffset = _serializer.int64(obj.robot_case, buffer, bufferOffset);
    // Serialize message field [local_x]
    bufferOffset = _serializer.int64(obj.local_x, buffer, bufferOffset);
    // Serialize message field [local_y]
    bufferOffset = _serializer.int64(obj.local_y, buffer, bufferOffset);
    // Serialize message field [local_yaw]
    bufferOffset = _serializer.int64(obj.local_yaw, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type udp_kicker_msg
    let len;
    let data = new udp_kicker_msg(null);
    // Deserialize message field [robot_num]
    data.robot_num = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_case]
    data.robot_case = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [local_x]
    data.local_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [local_y]
    data.local_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [local_yaw]
    data.local_yaw = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/udp_kicker_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4f5ba7b091b51220f871e749e172c551';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robot_num
    int64 robot_case
    
    int64 local_x
    int64 local_y 
    int64 local_yaw
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new udp_kicker_msg(null);
    if (msg.robot_num !== undefined) {
      resolved.robot_num = msg.robot_num;
    }
    else {
      resolved.robot_num = 0
    }

    if (msg.robot_case !== undefined) {
      resolved.robot_case = msg.robot_case;
    }
    else {
      resolved.robot_case = 0
    }

    if (msg.local_x !== undefined) {
      resolved.local_x = msg.local_x;
    }
    else {
      resolved.local_x = 0
    }

    if (msg.local_y !== undefined) {
      resolved.local_y = msg.local_y;
    }
    else {
      resolved.local_y = 0
    }

    if (msg.local_yaw !== undefined) {
      resolved.local_yaw = msg.local_yaw;
    }
    else {
      resolved.local_yaw = 0
    }

    return resolved;
    }
};

module.exports = udp_kicker_msg;
