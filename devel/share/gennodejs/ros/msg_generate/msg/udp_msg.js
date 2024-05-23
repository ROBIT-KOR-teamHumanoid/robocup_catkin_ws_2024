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

class udp_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.field_area = null;
      this.ball_area = null;
      this.robocup_case = null;
      this.ballDist = null;
    }
    else {
      if (initObj.hasOwnProperty('field_area')) {
        this.field_area = initObj.field_area
      }
      else {
        this.field_area = 0;
      }
      if (initObj.hasOwnProperty('ball_area')) {
        this.ball_area = initObj.ball_area
      }
      else {
        this.ball_area = 0;
      }
      if (initObj.hasOwnProperty('robocup_case')) {
        this.robocup_case = initObj.robocup_case
      }
      else {
        this.robocup_case = 0;
      }
      if (initObj.hasOwnProperty('ballDist')) {
        this.ballDist = initObj.ballDist
      }
      else {
        this.ballDist = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type udp_msg
    // Serialize message field [field_area]
    bufferOffset = _serializer.int32(obj.field_area, buffer, bufferOffset);
    // Serialize message field [ball_area]
    bufferOffset = _serializer.int32(obj.ball_area, buffer, bufferOffset);
    // Serialize message field [robocup_case]
    bufferOffset = _serializer.int32(obj.robocup_case, buffer, bufferOffset);
    // Serialize message field [ballDist]
    bufferOffset = _serializer.float64(obj.ballDist, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type udp_msg
    let len;
    let data = new udp_msg(null);
    // Deserialize message field [field_area]
    data.field_area = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [ball_area]
    data.ball_area = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [robocup_case]
    data.robocup_case = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [ballDist]
    data.ballDist = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/udp_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '705379b613a1dfa415f111dd5f542624';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 field_area
    int32 ball_area
    int32 robocup_case
    float64 ballDist
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new udp_msg(null);
    if (msg.field_area !== undefined) {
      resolved.field_area = msg.field_area;
    }
    else {
      resolved.field_area = 0
    }

    if (msg.ball_area !== undefined) {
      resolved.ball_area = msg.ball_area;
    }
    else {
      resolved.ball_area = 0
    }

    if (msg.robocup_case !== undefined) {
      resolved.robocup_case = msg.robocup_case;
    }
    else {
      resolved.robocup_case = 0
    }

    if (msg.ballDist !== undefined) {
      resolved.ballDist = msg.ballDist;
    }
    else {
      resolved.ballDist = 0.0
    }

    return resolved;
    }
};

module.exports = udp_msg;
