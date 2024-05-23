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

class localization_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ballDist = null;
      this.ballTheta = null;
      this.xcrossDist = null;
      this.xcrossTheta = null;
      this.goalpostDist = null;
      this.goalpostTheta = null;
      this.pointDist = null;
      this.pointTheta = null;
      this.penaltyCircleDist = null;
      this.penaltyCircleTheta = null;
      this.oneline = null;
    }
    else {
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
      if (initObj.hasOwnProperty('xcrossDist')) {
        this.xcrossDist = initObj.xcrossDist
      }
      else {
        this.xcrossDist = [];
      }
      if (initObj.hasOwnProperty('xcrossTheta')) {
        this.xcrossTheta = initObj.xcrossTheta
      }
      else {
        this.xcrossTheta = [];
      }
      if (initObj.hasOwnProperty('goalpostDist')) {
        this.goalpostDist = initObj.goalpostDist
      }
      else {
        this.goalpostDist = [];
      }
      if (initObj.hasOwnProperty('goalpostTheta')) {
        this.goalpostTheta = initObj.goalpostTheta
      }
      else {
        this.goalpostTheta = [];
      }
      if (initObj.hasOwnProperty('pointDist')) {
        this.pointDist = initObj.pointDist
      }
      else {
        this.pointDist = [];
      }
      if (initObj.hasOwnProperty('pointTheta')) {
        this.pointTheta = initObj.pointTheta
      }
      else {
        this.pointTheta = [];
      }
      if (initObj.hasOwnProperty('penaltyCircleDist')) {
        this.penaltyCircleDist = initObj.penaltyCircleDist
      }
      else {
        this.penaltyCircleDist = [];
      }
      if (initObj.hasOwnProperty('penaltyCircleTheta')) {
        this.penaltyCircleTheta = initObj.penaltyCircleTheta
      }
      else {
        this.penaltyCircleTheta = [];
      }
      if (initObj.hasOwnProperty('oneline')) {
        this.oneline = initObj.oneline
      }
      else {
        this.oneline = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type localization_msg
    // Serialize message field [ballDist]
    bufferOffset = _serializer.int64(obj.ballDist, buffer, bufferOffset);
    // Serialize message field [ballTheta]
    bufferOffset = _serializer.int64(obj.ballTheta, buffer, bufferOffset);
    // Serialize message field [xcrossDist]
    bufferOffset = _arraySerializer.int64(obj.xcrossDist, buffer, bufferOffset, null);
    // Serialize message field [xcrossTheta]
    bufferOffset = _arraySerializer.int64(obj.xcrossTheta, buffer, bufferOffset, null);
    // Serialize message field [goalpostDist]
    bufferOffset = _arraySerializer.int64(obj.goalpostDist, buffer, bufferOffset, null);
    // Serialize message field [goalpostTheta]
    bufferOffset = _arraySerializer.int64(obj.goalpostTheta, buffer, bufferOffset, null);
    // Serialize message field [pointDist]
    bufferOffset = _arraySerializer.int64(obj.pointDist, buffer, bufferOffset, null);
    // Serialize message field [pointTheta]
    bufferOffset = _arraySerializer.int64(obj.pointTheta, buffer, bufferOffset, null);
    // Serialize message field [penaltyCircleDist]
    bufferOffset = _arraySerializer.int64(obj.penaltyCircleDist, buffer, bufferOffset, null);
    // Serialize message field [penaltyCircleTheta]
    bufferOffset = _arraySerializer.int64(obj.penaltyCircleTheta, buffer, bufferOffset, null);
    // Serialize message field [oneline]
    bufferOffset = _serializer.int64(obj.oneline, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type localization_msg
    let len;
    let data = new localization_msg(null);
    // Deserialize message field [ballDist]
    data.ballDist = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [ballTheta]
    data.ballTheta = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [xcrossDist]
    data.xcrossDist = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [xcrossTheta]
    data.xcrossTheta = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [goalpostDist]
    data.goalpostDist = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [goalpostTheta]
    data.goalpostTheta = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [pointDist]
    data.pointDist = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [pointTheta]
    data.pointTheta = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [penaltyCircleDist]
    data.penaltyCircleDist = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [penaltyCircleTheta]
    data.penaltyCircleTheta = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [oneline]
    data.oneline = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.xcrossDist.length;
    length += 8 * object.xcrossTheta.length;
    length += 8 * object.goalpostDist.length;
    length += 8 * object.goalpostTheta.length;
    length += 8 * object.pointDist.length;
    length += 8 * object.pointTheta.length;
    length += 8 * object.penaltyCircleDist.length;
    length += 8 * object.penaltyCircleTheta.length;
    return length + 56;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/localization_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1199688341e3ebe99dc4295b1eed20cc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 ballDist
    int64 ballTheta
    
    int64[] xcrossDist
    int64[] xcrossTheta
    
    int64[] goalpostDist
    int64[] goalpostTheta
    
    int64[] pointDist
    int64[] pointTheta
    
    int64[] penaltyCircleDist
    int64[] penaltyCircleTheta
    
    int64 oneline
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new localization_msg(null);
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

    if (msg.xcrossDist !== undefined) {
      resolved.xcrossDist = msg.xcrossDist;
    }
    else {
      resolved.xcrossDist = []
    }

    if (msg.xcrossTheta !== undefined) {
      resolved.xcrossTheta = msg.xcrossTheta;
    }
    else {
      resolved.xcrossTheta = []
    }

    if (msg.goalpostDist !== undefined) {
      resolved.goalpostDist = msg.goalpostDist;
    }
    else {
      resolved.goalpostDist = []
    }

    if (msg.goalpostTheta !== undefined) {
      resolved.goalpostTheta = msg.goalpostTheta;
    }
    else {
      resolved.goalpostTheta = []
    }

    if (msg.pointDist !== undefined) {
      resolved.pointDist = msg.pointDist;
    }
    else {
      resolved.pointDist = []
    }

    if (msg.pointTheta !== undefined) {
      resolved.pointTheta = msg.pointTheta;
    }
    else {
      resolved.pointTheta = []
    }

    if (msg.penaltyCircleDist !== undefined) {
      resolved.penaltyCircleDist = msg.penaltyCircleDist;
    }
    else {
      resolved.penaltyCircleDist = []
    }

    if (msg.penaltyCircleTheta !== undefined) {
      resolved.penaltyCircleTheta = msg.penaltyCircleTheta;
    }
    else {
      resolved.penaltyCircleTheta = []
    }

    if (msg.oneline !== undefined) {
      resolved.oneline = msg.oneline;
    }
    else {
      resolved.oneline = 0
    }

    return resolved;
    }
};

module.exports = localization_msg;
