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

class robocupcontroller {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robotNum = null;
      this.state = null;
      this.readyTime = null;
      this.penalty = null;
      this.firstHalf = null;
      this.firstside = null;
      this.kickoffTeam = null;
      this.secondState = null;
      this.secondInfo = null;
    }
    else {
      if (initObj.hasOwnProperty('robotNum')) {
        this.robotNum = initObj.robotNum
      }
      else {
        this.robotNum = 0;
      }
      if (initObj.hasOwnProperty('state')) {
        this.state = initObj.state
      }
      else {
        this.state = 0;
      }
      if (initObj.hasOwnProperty('readyTime')) {
        this.readyTime = initObj.readyTime
      }
      else {
        this.readyTime = 0;
      }
      if (initObj.hasOwnProperty('penalty')) {
        this.penalty = initObj.penalty
      }
      else {
        this.penalty = 0;
      }
      if (initObj.hasOwnProperty('firstHalf')) {
        this.firstHalf = initObj.firstHalf
      }
      else {
        this.firstHalf = 0;
      }
      if (initObj.hasOwnProperty('firstside')) {
        this.firstside = initObj.firstside
      }
      else {
        this.firstside = 0;
      }
      if (initObj.hasOwnProperty('kickoffTeam')) {
        this.kickoffTeam = initObj.kickoffTeam
      }
      else {
        this.kickoffTeam = 0;
      }
      if (initObj.hasOwnProperty('secondState')) {
        this.secondState = initObj.secondState
      }
      else {
        this.secondState = 0;
      }
      if (initObj.hasOwnProperty('secondInfo')) {
        this.secondInfo = initObj.secondInfo
      }
      else {
        this.secondInfo = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocupcontroller
    // Serialize message field [robotNum]
    bufferOffset = _serializer.int64(obj.robotNum, buffer, bufferOffset);
    // Serialize message field [state]
    bufferOffset = _serializer.int64(obj.state, buffer, bufferOffset);
    // Serialize message field [readyTime]
    bufferOffset = _serializer.int64(obj.readyTime, buffer, bufferOffset);
    // Serialize message field [penalty]
    bufferOffset = _serializer.int64(obj.penalty, buffer, bufferOffset);
    // Serialize message field [firstHalf]
    bufferOffset = _serializer.int64(obj.firstHalf, buffer, bufferOffset);
    // Serialize message field [firstside]
    bufferOffset = _serializer.int64(obj.firstside, buffer, bufferOffset);
    // Serialize message field [kickoffTeam]
    bufferOffset = _serializer.int64(obj.kickoffTeam, buffer, bufferOffset);
    // Serialize message field [secondState]
    bufferOffset = _serializer.int64(obj.secondState, buffer, bufferOffset);
    // Serialize message field [secondInfo]
    bufferOffset = _arraySerializer.int64(obj.secondInfo, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocupcontroller
    let len;
    let data = new robocupcontroller(null);
    // Deserialize message field [robotNum]
    data.robotNum = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [state]
    data.state = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [readyTime]
    data.readyTime = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [penalty]
    data.penalty = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [firstHalf]
    data.firstHalf = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [firstside]
    data.firstside = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [kickoffTeam]
    data.kickoffTeam = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [secondState]
    data.secondState = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [secondInfo]
    data.secondInfo = _arrayDeserializer.int64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.secondInfo.length;
    return length + 68;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocupcontroller';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '878b95f20caac6a00b10d1f878052102';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robotNum
    int64 state
    int64 readyTime
    int64 penalty
    int64 firstHalf
    int64 firstside
    int64 kickoffTeam
    int64 secondState
    int64[] secondInfo
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocupcontroller(null);
    if (msg.robotNum !== undefined) {
      resolved.robotNum = msg.robotNum;
    }
    else {
      resolved.robotNum = 0
    }

    if (msg.state !== undefined) {
      resolved.state = msg.state;
    }
    else {
      resolved.state = 0
    }

    if (msg.readyTime !== undefined) {
      resolved.readyTime = msg.readyTime;
    }
    else {
      resolved.readyTime = 0
    }

    if (msg.penalty !== undefined) {
      resolved.penalty = msg.penalty;
    }
    else {
      resolved.penalty = 0
    }

    if (msg.firstHalf !== undefined) {
      resolved.firstHalf = msg.firstHalf;
    }
    else {
      resolved.firstHalf = 0
    }

    if (msg.firstside !== undefined) {
      resolved.firstside = msg.firstside;
    }
    else {
      resolved.firstside = 0
    }

    if (msg.kickoffTeam !== undefined) {
      resolved.kickoffTeam = msg.kickoffTeam;
    }
    else {
      resolved.kickoffTeam = 0
    }

    if (msg.secondState !== undefined) {
      resolved.secondState = msg.secondState;
    }
    else {
      resolved.secondState = 0
    }

    if (msg.secondInfo !== undefined) {
      resolved.secondInfo = msg.secondInfo;
    }
    else {
      resolved.secondInfo = []
    }

    return resolved;
    }
};

module.exports = robocupcontroller;
