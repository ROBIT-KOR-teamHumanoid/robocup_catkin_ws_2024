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

class robocup23_master2udp {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robot_num = null;
      this.robot_state = null;
      this.robot_coor_x = null;
      this.robot_coor_y = null;
      this.roboy_imu_yaw = null;
      this.ball_dist = null;
      this.ball_coor_x = null;
      this.ball_coor_y = null;
      this.myTeam = null;
    }
    else {
      if (initObj.hasOwnProperty('robot_num')) {
        this.robot_num = initObj.robot_num
      }
      else {
        this.robot_num = 0;
      }
      if (initObj.hasOwnProperty('robot_state')) {
        this.robot_state = initObj.robot_state
      }
      else {
        this.robot_state = 0;
      }
      if (initObj.hasOwnProperty('robot_coor_x')) {
        this.robot_coor_x = initObj.robot_coor_x
      }
      else {
        this.robot_coor_x = 0;
      }
      if (initObj.hasOwnProperty('robot_coor_y')) {
        this.robot_coor_y = initObj.robot_coor_y
      }
      else {
        this.robot_coor_y = 0;
      }
      if (initObj.hasOwnProperty('roboy_imu_yaw')) {
        this.roboy_imu_yaw = initObj.roboy_imu_yaw
      }
      else {
        this.roboy_imu_yaw = 0;
      }
      if (initObj.hasOwnProperty('ball_dist')) {
        this.ball_dist = initObj.ball_dist
      }
      else {
        this.ball_dist = 0;
      }
      if (initObj.hasOwnProperty('ball_coor_x')) {
        this.ball_coor_x = initObj.ball_coor_x
      }
      else {
        this.ball_coor_x = 0;
      }
      if (initObj.hasOwnProperty('ball_coor_y')) {
        this.ball_coor_y = initObj.ball_coor_y
      }
      else {
        this.ball_coor_y = 0;
      }
      if (initObj.hasOwnProperty('myTeam')) {
        this.myTeam = initObj.myTeam
      }
      else {
        this.myTeam = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocup23_master2udp
    // Serialize message field [robot_num]
    bufferOffset = _serializer.int64(obj.robot_num, buffer, bufferOffset);
    // Serialize message field [robot_state]
    bufferOffset = _serializer.int64(obj.robot_state, buffer, bufferOffset);
    // Serialize message field [robot_coor_x]
    bufferOffset = _serializer.int64(obj.robot_coor_x, buffer, bufferOffset);
    // Serialize message field [robot_coor_y]
    bufferOffset = _serializer.int64(obj.robot_coor_y, buffer, bufferOffset);
    // Serialize message field [roboy_imu_yaw]
    bufferOffset = _serializer.int64(obj.roboy_imu_yaw, buffer, bufferOffset);
    // Serialize message field [ball_dist]
    bufferOffset = _serializer.int64(obj.ball_dist, buffer, bufferOffset);
    // Serialize message field [ball_coor_x]
    bufferOffset = _serializer.int64(obj.ball_coor_x, buffer, bufferOffset);
    // Serialize message field [ball_coor_y]
    bufferOffset = _serializer.int64(obj.ball_coor_y, buffer, bufferOffset);
    // Serialize message field [myTeam]
    bufferOffset = _serializer.int64(obj.myTeam, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocup23_master2udp
    let len;
    let data = new robocup23_master2udp(null);
    // Deserialize message field [robot_num]
    data.robot_num = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_state]
    data.robot_state = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_coor_x]
    data.robot_coor_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [robot_coor_y]
    data.robot_coor_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [roboy_imu_yaw]
    data.roboy_imu_yaw = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ball_dist]
    data.ball_dist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ball_coor_x]
    data.ball_coor_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ball_coor_y]
    data.ball_coor_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [myTeam]
    data.myTeam = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocup23_master2udp';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c362ddeab15e7aaf6c2da6140bdfe915';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robot_num
    int64 robot_state
    int64 robot_coor_x
    int64 robot_coor_y
    int64 roboy_imu_yaw
    int64 ball_dist
    int64 ball_coor_x
    int64 ball_coor_y
    int64 myTeam
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocup23_master2udp(null);
    if (msg.robot_num !== undefined) {
      resolved.robot_num = msg.robot_num;
    }
    else {
      resolved.robot_num = 0
    }

    if (msg.robot_state !== undefined) {
      resolved.robot_state = msg.robot_state;
    }
    else {
      resolved.robot_state = 0
    }

    if (msg.robot_coor_x !== undefined) {
      resolved.robot_coor_x = msg.robot_coor_x;
    }
    else {
      resolved.robot_coor_x = 0
    }

    if (msg.robot_coor_y !== undefined) {
      resolved.robot_coor_y = msg.robot_coor_y;
    }
    else {
      resolved.robot_coor_y = 0
    }

    if (msg.roboy_imu_yaw !== undefined) {
      resolved.roboy_imu_yaw = msg.roboy_imu_yaw;
    }
    else {
      resolved.roboy_imu_yaw = 0
    }

    if (msg.ball_dist !== undefined) {
      resolved.ball_dist = msg.ball_dist;
    }
    else {
      resolved.ball_dist = 0
    }

    if (msg.ball_coor_x !== undefined) {
      resolved.ball_coor_x = msg.ball_coor_x;
    }
    else {
      resolved.ball_coor_x = 0
    }

    if (msg.ball_coor_y !== undefined) {
      resolved.ball_coor_y = msg.ball_coor_y;
    }
    else {
      resolved.ball_coor_y = 0
    }

    if (msg.myTeam !== undefined) {
      resolved.myTeam = msg.myTeam;
    }
    else {
      resolved.myTeam = 0
    }

    return resolved;
    }
};

module.exports = robocup23_master2udp;
