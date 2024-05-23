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

class game_control_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robotNum = null;
      this.position = null;
      this.myTeam = null;
      this.state = null;
      this.mySide = null;
      this.iskickoff = null;
      this.readyTime = null;
      this.penalty = null;
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
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = 0;
      }
      if (initObj.hasOwnProperty('myTeam')) {
        this.myTeam = initObj.myTeam
      }
      else {
        this.myTeam = 0;
      }
      if (initObj.hasOwnProperty('state')) {
        this.state = initObj.state
      }
      else {
        this.state = 0;
      }
      if (initObj.hasOwnProperty('mySide')) {
        this.mySide = initObj.mySide
      }
      else {
        this.mySide = 0;
      }
      if (initObj.hasOwnProperty('iskickoff')) {
        this.iskickoff = initObj.iskickoff
      }
      else {
        this.iskickoff = 0;
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
    // Serializes a message object of type game_control_data
    // Serialize message field [robotNum]
    bufferOffset = _serializer.int64(obj.robotNum, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.int64(obj.position, buffer, bufferOffset);
    // Serialize message field [myTeam]
    bufferOffset = _serializer.int64(obj.myTeam, buffer, bufferOffset);
    // Serialize message field [state]
    bufferOffset = _serializer.int64(obj.state, buffer, bufferOffset);
    // Serialize message field [mySide]
    bufferOffset = _serializer.int64(obj.mySide, buffer, bufferOffset);
    // Serialize message field [iskickoff]
    bufferOffset = _serializer.int64(obj.iskickoff, buffer, bufferOffset);
    // Serialize message field [readyTime]
    bufferOffset = _serializer.int64(obj.readyTime, buffer, bufferOffset);
    // Serialize message field [penalty]
    bufferOffset = _serializer.int64(obj.penalty, buffer, bufferOffset);
    // Serialize message field [secondState]
    bufferOffset = _serializer.int64(obj.secondState, buffer, bufferOffset);
    // Serialize message field [secondInfo]
    bufferOffset = _arraySerializer.int64(obj.secondInfo, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type game_control_data
    let len;
    let data = new game_control_data(null);
    // Deserialize message field [robotNum]
    data.robotNum = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [myTeam]
    data.myTeam = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [state]
    data.state = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [mySide]
    data.mySide = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [iskickoff]
    data.iskickoff = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [readyTime]
    data.readyTime = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [penalty]
    data.penalty = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [secondState]
    data.secondState = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [secondInfo]
    data.secondInfo = _arrayDeserializer.int64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.secondInfo.length;
    return length + 76;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/game_control_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2d9766fbb6334c79351c86b83016bef8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 robotNum
    int64 position
    int64 myTeam
    
    int64 state
    int64 mySide
    int64 iskickoff
    int64 readyTime
    int64 penalty
    int64 secondState
    int64[] secondInfo
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new game_control_data(null);
    if (msg.robotNum !== undefined) {
      resolved.robotNum = msg.robotNum;
    }
    else {
      resolved.robotNum = 0
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = 0
    }

    if (msg.myTeam !== undefined) {
      resolved.myTeam = msg.myTeam;
    }
    else {
      resolved.myTeam = 0
    }

    if (msg.state !== undefined) {
      resolved.state = msg.state;
    }
    else {
      resolved.state = 0
    }

    if (msg.mySide !== undefined) {
      resolved.mySide = msg.mySide;
    }
    else {
      resolved.mySide = 0
    }

    if (msg.iskickoff !== undefined) {
      resolved.iskickoff = msg.iskickoff;
    }
    else {
      resolved.iskickoff = 0
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

module.exports = game_control_data;
