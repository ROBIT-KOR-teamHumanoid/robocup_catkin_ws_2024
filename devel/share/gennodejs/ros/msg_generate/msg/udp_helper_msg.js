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

class udp_helper_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robot_num = null;
      this.robot_case = null;
      this.robot_x_order = null;
      this.robot_y_order = null;
      this.robot_ik_x_order = null;
      this.robot_ik_y_order = null;
      this.robot_ik_yaw_order = null;
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
      if (initObj.hasOwnProperty('robot_x_order')) {
        this.robot_x_order = initObj.robot_x_order
      }
      else {
        this.robot_x_order = 0;
      }
      if (initObj.hasOwnProperty('robot_y_order')) {
        this.robot_y_order = initObj.robot_y_order
      }
      else {
        this.robot_y_order = 0;
      }
      if (initObj.hasOwnProperty('robot_ik_x_order')) {
        this.robot_ik_x_order = initObj.robot_ik_x_order
      }
      else {
        this.robot_ik_x_order = 0;
      }
      if (initObj.hasOwnProperty('robot_ik_y_order')) {
        this.robot_ik_y_order = initObj.robot_ik_y_order
      }
      else {
        this.robot_ik_y_order = 0;
      }
      if (initObj.hasOwnProperty('robot_ik_yaw_order')) {
        this.robot_ik_yaw_order = initObj.robot_ik_yaw_order
      }
      else {
        this.robot_ik_yaw_order = 0;
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
    // Serializes a message object of type udp_helper_msg
    // Serialize message field [robot_num]
    bufferOffset = _serializer.int64(obj.robot_num, buffer, bufferOffset);
    // Serialize message field [robot_case]
    bufferOffset = _serializer.int64(obj.robot_case, buffer, bufferOffset);
    // Serialize message field [robot_x_order]
    bufferOffset = _serializer.int64(obj.robot_x_order, buffer, bufferOffset);
    // Serialize message field [robot_y_order]
    bufferOffset = _serializer.int64(obj.robot_y_order, buffer, bufferOffset);
    // Serialize message field [robot_ik_x_order]
    bufferOffset = _serializer.int64(obj.robot_ik_x_order, buffer, bufferOffset);
    // Serialize message field [robot_ik_y_order]
    bufferOffset = _serializer.int64(obj.robot_ik_y_order, buffer, bufferOffset);
    // Serialize message field [robot_ik_yaw_order]
    bufferOffset = _serializer.int64(obj.robot_ik_yaw_order, buffer, bufferOffset);
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
    //deserializes a message object of type udp_helper_msg
    let len;
    let data = new udp_helper_msg(null);
    // Deserialize message field [robot_num]
    data.robot_num = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_case]
    data.robot_case = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_x_order]
    data.robot_x_order = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_y_order]
    data.robot_y_order = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_ik_x_order]
    data.robot_ik_x_order = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_ik_y_order]
    data.robot_ik_y_order = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_ik_yaw_order]
    data.robot_ik_yaw_order = _deserializer.int64(buffer, bufferOffset);
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
    return 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/udp_helper_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6961c7de19af71cbd4139ee3940f46a0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robot_num
    int64 robot_case
    
    int64 robot_x_order
    int64 robot_y_order 
    
    int64 robot_ik_x_order
    int64 robot_ik_y_order
    int64 robot_ik_yaw_order
    
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
    const resolved = new udp_helper_msg(null);
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

    if (msg.robot_x_order !== undefined) {
      resolved.robot_x_order = msg.robot_x_order;
    }
    else {
      resolved.robot_x_order = 0
    }

    if (msg.robot_y_order !== undefined) {
      resolved.robot_y_order = msg.robot_y_order;
    }
    else {
      resolved.robot_y_order = 0
    }

    if (msg.robot_ik_x_order !== undefined) {
      resolved.robot_ik_x_order = msg.robot_ik_x_order;
    }
    else {
      resolved.robot_ik_x_order = 0
    }

    if (msg.robot_ik_y_order !== undefined) {
      resolved.robot_ik_y_order = msg.robot_ik_y_order;
    }
    else {
      resolved.robot_ik_y_order = 0
    }

    if (msg.robot_ik_yaw_order !== undefined) {
      resolved.robot_ik_yaw_order = msg.robot_ik_yaw_order;
    }
    else {
      resolved.robot_ik_yaw_order = 0
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

module.exports = udp_helper_msg;
