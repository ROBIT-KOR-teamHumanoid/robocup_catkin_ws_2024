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

class localv2_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robot_num = null;
      this.robot_case = null;
      this.local_x = null;
      this.local_y = null;
      this.local_yaw = null;
      this.ball_x = null;
      this.ball_y = null;
      this.ballDist = null;
      this.ballTheta = null;
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
      if (initObj.hasOwnProperty('ball_x')) {
        this.ball_x = initObj.ball_x
      }
      else {
        this.ball_x = 0;
      }
      if (initObj.hasOwnProperty('ball_y')) {
        this.ball_y = initObj.ball_y
      }
      else {
        this.ball_y = 0;
      }
      if (initObj.hasOwnProperty('ballDist')) {
        this.ballDist = initObj.ballDist
      }
      else {
        this.ballDist = 0;
      }
      if (initObj.hasOwnProperty('ballTheta')) {
        this.ballTheta = initObj.ballTheta
      }
      else {
        this.ballTheta = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type localv2_msg
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
    // Serialize message field [ball_x]
    bufferOffset = _serializer.int64(obj.ball_x, buffer, bufferOffset);
    // Serialize message field [ball_y]
    bufferOffset = _serializer.int64(obj.ball_y, buffer, bufferOffset);
    // Serialize message field [ballDist]
    bufferOffset = _serializer.int64(obj.ballDist, buffer, bufferOffset);
    // Serialize message field [ballTheta]
    bufferOffset = _serializer.int64(obj.ballTheta, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type localv2_msg
    let len;
    let data = new localv2_msg(null);
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
    // Deserialize message field [ball_x]
    data.ball_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ball_y]
    data.ball_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballDist]
    data.ballDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballTheta]
    data.ballTheta = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/localv2_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd38b9edd3a71a67cf30bc44ca69d472a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robot_num
    int64 robot_case
    
    int64 local_x
    int64 local_y 
    int64 local_yaw
    
    int64 ball_x
    int64 ball_y
    int64 ballDist
    int64 ballTheta
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new localv2_msg(null);
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

    if (msg.ball_x !== undefined) {
      resolved.ball_x = msg.ball_x;
    }
    else {
      resolved.ball_x = 0
    }

    if (msg.ball_y !== undefined) {
      resolved.ball_y = msg.ball_y;
    }
    else {
      resolved.ball_y = 0
    }

    if (msg.ballDist !== undefined) {
      resolved.ballDist = msg.ballDist;
    }
    else {
      resolved.ballDist = 0
    }

    if (msg.ballTheta !== undefined) {
      resolved.ballTheta = msg.ballTheta;
    }
    else {
      resolved.ballTheta = 0
    }

    return resolved;
    }
};

module.exports = localv2_msg;
