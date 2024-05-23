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

class robocupvision {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ballX = null;
      this.ballY = null;
      this.ballDist = null;
      this.ballTheta = null;
    }
    else {
      if (initObj.hasOwnProperty('ballX')) {
        this.ballX = initObj.ballX
      }
      else {
        this.ballX = 0;
      }
      if (initObj.hasOwnProperty('ballY')) {
        this.ballY = initObj.ballY
      }
      else {
        this.ballY = 0;
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
        this.ballTheta = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocupvision
    // Serialize message field [ballX]
    bufferOffset = _serializer.int64(obj.ballX, buffer, bufferOffset);
    // Serialize message field [ballY]
    bufferOffset = _serializer.int64(obj.ballY, buffer, bufferOffset);
    // Serialize message field [ballDist]
    bufferOffset = _serializer.int64(obj.ballDist, buffer, bufferOffset);
    // Serialize message field [ballTheta]
    bufferOffset = _serializer.float64(obj.ballTheta, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocupvision
    let len;
    let data = new robocupvision(null);
    // Deserialize message field [ballX]
    data.ballX = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballY]
    data.ballY = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballDist]
    data.ballDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballTheta]
    data.ballTheta = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocupvision';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '42c32a1bbbff9d4d2593036e1e947112';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 ballX
    int64 ballY
    int64 ballDist
    float64 ballTheta
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocupvision(null);
    if (msg.ballX !== undefined) {
      resolved.ballX = msg.ballX;
    }
    else {
      resolved.ballX = 0
    }

    if (msg.ballY !== undefined) {
      resolved.ballY = msg.ballY;
    }
    else {
      resolved.ballY = 0
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
      resolved.ballTheta = 0.0
    }

    return resolved;
    }
};

module.exports = robocupvision;
