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

class scv_vision {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ballX = null;
      this.ballY = null;
      this.ballDist = null;
      this.ballTheta = null;
      this.cylinderX = null;
      this.cylinderY = null;
      this.cylinderDist = null;
      this.cylinderTheta = null;
      this.directX = null;
      this.directY = null;
      this.directDist = null;
      this.directTheta = null;
      this.first_start = null;
      this.circlex = null;
      this.circley = null;
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
      if (initObj.hasOwnProperty('cylinderX')) {
        this.cylinderX = initObj.cylinderX
      }
      else {
        this.cylinderX = 0;
      }
      if (initObj.hasOwnProperty('cylinderY')) {
        this.cylinderY = initObj.cylinderY
      }
      else {
        this.cylinderY = 0;
      }
      if (initObj.hasOwnProperty('cylinderDist')) {
        this.cylinderDist = initObj.cylinderDist
      }
      else {
        this.cylinderDist = 0;
      }
      if (initObj.hasOwnProperty('cylinderTheta')) {
        this.cylinderTheta = initObj.cylinderTheta
      }
      else {
        this.cylinderTheta = 0.0;
      }
      if (initObj.hasOwnProperty('directX')) {
        this.directX = initObj.directX
      }
      else {
        this.directX = 0;
      }
      if (initObj.hasOwnProperty('directY')) {
        this.directY = initObj.directY
      }
      else {
        this.directY = 0;
      }
      if (initObj.hasOwnProperty('directDist')) {
        this.directDist = initObj.directDist
      }
      else {
        this.directDist = 0;
      }
      if (initObj.hasOwnProperty('directTheta')) {
        this.directTheta = initObj.directTheta
      }
      else {
        this.directTheta = 0.0;
      }
      if (initObj.hasOwnProperty('first_start')) {
        this.first_start = initObj.first_start
      }
      else {
        this.first_start = 0;
      }
      if (initObj.hasOwnProperty('circlex')) {
        this.circlex = initObj.circlex
      }
      else {
        this.circlex = 0;
      }
      if (initObj.hasOwnProperty('circley')) {
        this.circley = initObj.circley
      }
      else {
        this.circley = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type scv_vision
    // Serialize message field [ballX]
    bufferOffset = _serializer.int64(obj.ballX, buffer, bufferOffset);
    // Serialize message field [ballY]
    bufferOffset = _serializer.int64(obj.ballY, buffer, bufferOffset);
    // Serialize message field [ballDist]
    bufferOffset = _serializer.int64(obj.ballDist, buffer, bufferOffset);
    // Serialize message field [ballTheta]
    bufferOffset = _serializer.float64(obj.ballTheta, buffer, bufferOffset);
    // Serialize message field [cylinderX]
    bufferOffset = _serializer.int64(obj.cylinderX, buffer, bufferOffset);
    // Serialize message field [cylinderY]
    bufferOffset = _serializer.int64(obj.cylinderY, buffer, bufferOffset);
    // Serialize message field [cylinderDist]
    bufferOffset = _serializer.int64(obj.cylinderDist, buffer, bufferOffset);
    // Serialize message field [cylinderTheta]
    bufferOffset = _serializer.float64(obj.cylinderTheta, buffer, bufferOffset);
    // Serialize message field [directX]
    bufferOffset = _serializer.int64(obj.directX, buffer, bufferOffset);
    // Serialize message field [directY]
    bufferOffset = _serializer.int64(obj.directY, buffer, bufferOffset);
    // Serialize message field [directDist]
    bufferOffset = _serializer.int64(obj.directDist, buffer, bufferOffset);
    // Serialize message field [directTheta]
    bufferOffset = _serializer.float64(obj.directTheta, buffer, bufferOffset);
    // Serialize message field [first_start]
    bufferOffset = _serializer.int64(obj.first_start, buffer, bufferOffset);
    // Serialize message field [circlex]
    bufferOffset = _serializer.int64(obj.circlex, buffer, bufferOffset);
    // Serialize message field [circley]
    bufferOffset = _serializer.int64(obj.circley, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type scv_vision
    let len;
    let data = new scv_vision(null);
    // Deserialize message field [ballX]
    data.ballX = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballY]
    data.ballY = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballDist]
    data.ballDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballTheta]
    data.ballTheta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cylinderX]
    data.cylinderX = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [cylinderY]
    data.cylinderY = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [cylinderDist]
    data.cylinderDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [cylinderTheta]
    data.cylinderTheta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [directX]
    data.directX = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [directY]
    data.directY = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [directDist]
    data.directDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [directTheta]
    data.directTheta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [first_start]
    data.first_start = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [circlex]
    data.circlex = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [circley]
    data.circley = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 120;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/scv_vision';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '65c896941af724ac4f09562adde2b414';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 ballX
    int64 ballY
    int64 ballDist
    float64 ballTheta
    int64 cylinderX
    int64 cylinderY
    int64 cylinderDist
    float64 cylinderTheta
    int64 directX
    int64 directY
    int64 directDist
    float64 directTheta
    int64 first_start
    int64 circlex
    int64 circley
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new scv_vision(null);
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

    if (msg.cylinderX !== undefined) {
      resolved.cylinderX = msg.cylinderX;
    }
    else {
      resolved.cylinderX = 0
    }

    if (msg.cylinderY !== undefined) {
      resolved.cylinderY = msg.cylinderY;
    }
    else {
      resolved.cylinderY = 0
    }

    if (msg.cylinderDist !== undefined) {
      resolved.cylinderDist = msg.cylinderDist;
    }
    else {
      resolved.cylinderDist = 0
    }

    if (msg.cylinderTheta !== undefined) {
      resolved.cylinderTheta = msg.cylinderTheta;
    }
    else {
      resolved.cylinderTheta = 0.0
    }

    if (msg.directX !== undefined) {
      resolved.directX = msg.directX;
    }
    else {
      resolved.directX = 0
    }

    if (msg.directY !== undefined) {
      resolved.directY = msg.directY;
    }
    else {
      resolved.directY = 0
    }

    if (msg.directDist !== undefined) {
      resolved.directDist = msg.directDist;
    }
    else {
      resolved.directDist = 0
    }

    if (msg.directTheta !== undefined) {
      resolved.directTheta = msg.directTheta;
    }
    else {
      resolved.directTheta = 0.0
    }

    if (msg.first_start !== undefined) {
      resolved.first_start = msg.first_start;
    }
    else {
      resolved.first_start = 0
    }

    if (msg.circlex !== undefined) {
      resolved.circlex = msg.circlex;
    }
    else {
      resolved.circlex = 0
    }

    if (msg.circley !== undefined) {
      resolved.circley = msg.circley;
    }
    else {
      resolved.circley = 0
    }

    return resolved;
    }
};

module.exports = scv_vision;
