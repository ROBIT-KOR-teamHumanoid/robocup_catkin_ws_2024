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

class robocup_localization23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Ball_X = null;
      this.Ball_Y = null;
      this.Ball_speed_X = null;
      this.Ball_speed_Y = null;
      this.Robot_X = null;
      this.Robot_Y = null;
      this.Obstacle0_X = null;
      this.Obstacle0_Y = null;
      this.Obstacle1_X = null;
      this.Obstacle1_Y = null;
      this.Obstacle2_X = null;
      this.Obstacle2_Y = null;
      this.Obstacle3_X = null;
      this.Obstacle3_Y = null;
    }
    else {
      if (initObj.hasOwnProperty('Ball_X')) {
        this.Ball_X = initObj.Ball_X
      }
      else {
        this.Ball_X = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_Y')) {
        this.Ball_Y = initObj.Ball_Y
      }
      else {
        this.Ball_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_speed_X')) {
        this.Ball_speed_X = initObj.Ball_speed_X
      }
      else {
        this.Ball_speed_X = 0.0;
      }
      if (initObj.hasOwnProperty('Ball_speed_Y')) {
        this.Ball_speed_Y = initObj.Ball_speed_Y
      }
      else {
        this.Ball_speed_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Robot_X')) {
        this.Robot_X = initObj.Robot_X
      }
      else {
        this.Robot_X = 0.0;
      }
      if (initObj.hasOwnProperty('Robot_Y')) {
        this.Robot_Y = initObj.Robot_Y
      }
      else {
        this.Robot_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle0_X')) {
        this.Obstacle0_X = initObj.Obstacle0_X
      }
      else {
        this.Obstacle0_X = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle0_Y')) {
        this.Obstacle0_Y = initObj.Obstacle0_Y
      }
      else {
        this.Obstacle0_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle1_X')) {
        this.Obstacle1_X = initObj.Obstacle1_X
      }
      else {
        this.Obstacle1_X = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle1_Y')) {
        this.Obstacle1_Y = initObj.Obstacle1_Y
      }
      else {
        this.Obstacle1_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle2_X')) {
        this.Obstacle2_X = initObj.Obstacle2_X
      }
      else {
        this.Obstacle2_X = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle2_Y')) {
        this.Obstacle2_Y = initObj.Obstacle2_Y
      }
      else {
        this.Obstacle2_Y = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle3_X')) {
        this.Obstacle3_X = initObj.Obstacle3_X
      }
      else {
        this.Obstacle3_X = 0.0;
      }
      if (initObj.hasOwnProperty('Obstacle3_Y')) {
        this.Obstacle3_Y = initObj.Obstacle3_Y
      }
      else {
        this.Obstacle3_Y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocup_localization23
    // Serialize message field [Ball_X]
    bufferOffset = _serializer.float64(obj.Ball_X, buffer, bufferOffset);
    // Serialize message field [Ball_Y]
    bufferOffset = _serializer.float64(obj.Ball_Y, buffer, bufferOffset);
    // Serialize message field [Ball_speed_X]
    bufferOffset = _serializer.float64(obj.Ball_speed_X, buffer, bufferOffset);
    // Serialize message field [Ball_speed_Y]
    bufferOffset = _serializer.float64(obj.Ball_speed_Y, buffer, bufferOffset);
    // Serialize message field [Robot_X]
    bufferOffset = _serializer.float64(obj.Robot_X, buffer, bufferOffset);
    // Serialize message field [Robot_Y]
    bufferOffset = _serializer.float64(obj.Robot_Y, buffer, bufferOffset);
    // Serialize message field [Obstacle0_X]
    bufferOffset = _serializer.float64(obj.Obstacle0_X, buffer, bufferOffset);
    // Serialize message field [Obstacle0_Y]
    bufferOffset = _serializer.float64(obj.Obstacle0_Y, buffer, bufferOffset);
    // Serialize message field [Obstacle1_X]
    bufferOffset = _serializer.float64(obj.Obstacle1_X, buffer, bufferOffset);
    // Serialize message field [Obstacle1_Y]
    bufferOffset = _serializer.float64(obj.Obstacle1_Y, buffer, bufferOffset);
    // Serialize message field [Obstacle2_X]
    bufferOffset = _serializer.float64(obj.Obstacle2_X, buffer, bufferOffset);
    // Serialize message field [Obstacle2_Y]
    bufferOffset = _serializer.float64(obj.Obstacle2_Y, buffer, bufferOffset);
    // Serialize message field [Obstacle3_X]
    bufferOffset = _serializer.float64(obj.Obstacle3_X, buffer, bufferOffset);
    // Serialize message field [Obstacle3_Y]
    bufferOffset = _serializer.float64(obj.Obstacle3_Y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocup_localization23
    let len;
    let data = new robocup_localization23(null);
    // Deserialize message field [Ball_X]
    data.Ball_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_Y]
    data.Ball_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_speed_X]
    data.Ball_speed_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ball_speed_Y]
    data.Ball_speed_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Robot_X]
    data.Robot_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Robot_Y]
    data.Robot_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle0_X]
    data.Obstacle0_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle0_Y]
    data.Obstacle0_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle1_X]
    data.Obstacle1_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle1_Y]
    data.Obstacle1_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle2_X]
    data.Obstacle2_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle2_Y]
    data.Obstacle2_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle3_X]
    data.Obstacle3_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Obstacle3_Y]
    data.Obstacle3_Y = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 112;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocup_localization23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2b8377baa9d999eda3c851f4b34ed1a5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 Ball_X
    float64 Ball_Y
    float64 Ball_speed_X
    float64 Ball_speed_Y
    float64 Robot_X
    float64 Robot_Y
    float64 Obstacle0_X
    float64 Obstacle0_Y
    float64 Obstacle1_X
    float64 Obstacle1_Y
    float64 Obstacle2_X
    float64 Obstacle2_Y
    float64 Obstacle3_X
    float64 Obstacle3_Y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocup_localization23(null);
    if (msg.Ball_X !== undefined) {
      resolved.Ball_X = msg.Ball_X;
    }
    else {
      resolved.Ball_X = 0.0
    }

    if (msg.Ball_Y !== undefined) {
      resolved.Ball_Y = msg.Ball_Y;
    }
    else {
      resolved.Ball_Y = 0.0
    }

    if (msg.Ball_speed_X !== undefined) {
      resolved.Ball_speed_X = msg.Ball_speed_X;
    }
    else {
      resolved.Ball_speed_X = 0.0
    }

    if (msg.Ball_speed_Y !== undefined) {
      resolved.Ball_speed_Y = msg.Ball_speed_Y;
    }
    else {
      resolved.Ball_speed_Y = 0.0
    }

    if (msg.Robot_X !== undefined) {
      resolved.Robot_X = msg.Robot_X;
    }
    else {
      resolved.Robot_X = 0.0
    }

    if (msg.Robot_Y !== undefined) {
      resolved.Robot_Y = msg.Robot_Y;
    }
    else {
      resolved.Robot_Y = 0.0
    }

    if (msg.Obstacle0_X !== undefined) {
      resolved.Obstacle0_X = msg.Obstacle0_X;
    }
    else {
      resolved.Obstacle0_X = 0.0
    }

    if (msg.Obstacle0_Y !== undefined) {
      resolved.Obstacle0_Y = msg.Obstacle0_Y;
    }
    else {
      resolved.Obstacle0_Y = 0.0
    }

    if (msg.Obstacle1_X !== undefined) {
      resolved.Obstacle1_X = msg.Obstacle1_X;
    }
    else {
      resolved.Obstacle1_X = 0.0
    }

    if (msg.Obstacle1_Y !== undefined) {
      resolved.Obstacle1_Y = msg.Obstacle1_Y;
    }
    else {
      resolved.Obstacle1_Y = 0.0
    }

    if (msg.Obstacle2_X !== undefined) {
      resolved.Obstacle2_X = msg.Obstacle2_X;
    }
    else {
      resolved.Obstacle2_X = 0.0
    }

    if (msg.Obstacle2_Y !== undefined) {
      resolved.Obstacle2_Y = msg.Obstacle2_Y;
    }
    else {
      resolved.Obstacle2_Y = 0.0
    }

    if (msg.Obstacle3_X !== undefined) {
      resolved.Obstacle3_X = msg.Obstacle3_X;
    }
    else {
      resolved.Obstacle3_X = 0.0
    }

    if (msg.Obstacle3_Y !== undefined) {
      resolved.Obstacle3_Y = msg.Obstacle3_Y;
    }
    else {
      resolved.Obstacle3_Y = 0.0
    }

    return resolved;
    }
};

module.exports = robocup_localization23;
