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

class Running_2020_vision {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Way = null;
      this.start_x = null;
      this.start_y = null;
      this.goal_x = null;
      this.goal_y = null;
      this.direction = null;
      this.recog_goal_x = null;
    }
    else {
      if (initObj.hasOwnProperty('Way')) {
        this.Way = initObj.Way
      }
      else {
        this.Way = 0;
      }
      if (initObj.hasOwnProperty('start_x')) {
        this.start_x = initObj.start_x
      }
      else {
        this.start_x = 0;
      }
      if (initObj.hasOwnProperty('start_y')) {
        this.start_y = initObj.start_y
      }
      else {
        this.start_y = 0;
      }
      if (initObj.hasOwnProperty('goal_x')) {
        this.goal_x = initObj.goal_x
      }
      else {
        this.goal_x = 0;
      }
      if (initObj.hasOwnProperty('goal_y')) {
        this.goal_y = initObj.goal_y
      }
      else {
        this.goal_y = 0;
      }
      if (initObj.hasOwnProperty('direction')) {
        this.direction = initObj.direction
      }
      else {
        this.direction = 0;
      }
      if (initObj.hasOwnProperty('recog_goal_x')) {
        this.recog_goal_x = initObj.recog_goal_x
      }
      else {
        this.recog_goal_x = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Running_2020_vision
    // Serialize message field [Way]
    bufferOffset = _serializer.int64(obj.Way, buffer, bufferOffset);
    // Serialize message field [start_x]
    bufferOffset = _serializer.int64(obj.start_x, buffer, bufferOffset);
    // Serialize message field [start_y]
    bufferOffset = _serializer.int64(obj.start_y, buffer, bufferOffset);
    // Serialize message field [goal_x]
    bufferOffset = _serializer.int64(obj.goal_x, buffer, bufferOffset);
    // Serialize message field [goal_y]
    bufferOffset = _serializer.int64(obj.goal_y, buffer, bufferOffset);
    // Serialize message field [direction]
    bufferOffset = _serializer.int64(obj.direction, buffer, bufferOffset);
    // Serialize message field [recog_goal_x]
    bufferOffset = _serializer.bool(obj.recog_goal_x, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Running_2020_vision
    let len;
    let data = new Running_2020_vision(null);
    // Deserialize message field [Way]
    data.Way = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [start_x]
    data.start_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [start_y]
    data.start_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [goal_x]
    data.goal_x = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [goal_y]
    data.goal_y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [direction]
    data.direction = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [recog_goal_x]
    data.recog_goal_x = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 49;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/Running_2020_vision';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4006f37f440c035b6febc61d2cd4ff1a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 Way
    int64 start_x
    int64 start_y
    int64 goal_x
    int64 goal_y
    int64 direction
    bool recog_goal_x
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Running_2020_vision(null);
    if (msg.Way !== undefined) {
      resolved.Way = msg.Way;
    }
    else {
      resolved.Way = 0
    }

    if (msg.start_x !== undefined) {
      resolved.start_x = msg.start_x;
    }
    else {
      resolved.start_x = 0
    }

    if (msg.start_y !== undefined) {
      resolved.start_y = msg.start_y;
    }
    else {
      resolved.start_y = 0
    }

    if (msg.goal_x !== undefined) {
      resolved.goal_x = msg.goal_x;
    }
    else {
      resolved.goal_x = 0
    }

    if (msg.goal_y !== undefined) {
      resolved.goal_y = msg.goal_y;
    }
    else {
      resolved.goal_y = 0
    }

    if (msg.direction !== undefined) {
      resolved.direction = msg.direction;
    }
    else {
      resolved.direction = 0
    }

    if (msg.recog_goal_x !== undefined) {
      resolved.recog_goal_x = msg.recog_goal_x;
    }
    else {
      resolved.recog_goal_x = false
    }

    return resolved;
    }
};

module.exports = Running_2020_vision;
