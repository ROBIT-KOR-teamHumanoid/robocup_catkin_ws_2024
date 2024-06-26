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

class robocup_vision24_feature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.CONFIDENCE = null;
      this.DISTANCE = null;
      this.POINT_VEC_X = null;
      this.POINT_VEC_Y = null;
      this.TYPE = null;
    }
    else {
      if (initObj.hasOwnProperty('CONFIDENCE')) {
        this.CONFIDENCE = initObj.CONFIDENCE
      }
      else {
        this.CONFIDENCE = [];
      }
      if (initObj.hasOwnProperty('DISTANCE')) {
        this.DISTANCE = initObj.DISTANCE
      }
      else {
        this.DISTANCE = [];
      }
      if (initObj.hasOwnProperty('POINT_VEC_X')) {
        this.POINT_VEC_X = initObj.POINT_VEC_X
      }
      else {
        this.POINT_VEC_X = [];
      }
      if (initObj.hasOwnProperty('POINT_VEC_Y')) {
        this.POINT_VEC_Y = initObj.POINT_VEC_Y
      }
      else {
        this.POINT_VEC_Y = [];
      }
      if (initObj.hasOwnProperty('TYPE')) {
        this.TYPE = initObj.TYPE
      }
      else {
        this.TYPE = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robocup_vision24_feature
    // Serialize message field [CONFIDENCE]
    bufferOffset = _arraySerializer.float64(obj.CONFIDENCE, buffer, bufferOffset, null);
    // Serialize message field [DISTANCE]
    bufferOffset = _arraySerializer.float64(obj.DISTANCE, buffer, bufferOffset, null);
    // Serialize message field [POINT_VEC_X]
    bufferOffset = _arraySerializer.float64(obj.POINT_VEC_X, buffer, bufferOffset, null);
    // Serialize message field [POINT_VEC_Y]
    bufferOffset = _arraySerializer.float64(obj.POINT_VEC_Y, buffer, bufferOffset, null);
    // Serialize message field [TYPE]
    bufferOffset = _arraySerializer.float64(obj.TYPE, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robocup_vision24_feature
    let len;
    let data = new robocup_vision24_feature(null);
    // Deserialize message field [CONFIDENCE]
    data.CONFIDENCE = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [DISTANCE]
    data.DISTANCE = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [POINT_VEC_X]
    data.POINT_VEC_X = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [POINT_VEC_Y]
    data.POINT_VEC_Y = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [TYPE]
    data.TYPE = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.CONFIDENCE.length;
    length += 8 * object.DISTANCE.length;
    length += 8 * object.POINT_VEC_X.length;
    length += 8 * object.POINT_VEC_Y.length;
    length += 8 * object.TYPE.length;
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/robocup_vision24_feature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '90f95fdb2af41305af35e1195995ece4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] CONFIDENCE
    float64[] DISTANCE
    float64[] POINT_VEC_X
    float64[] POINT_VEC_Y
    float64[] TYPE
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robocup_vision24_feature(null);
    if (msg.CONFIDENCE !== undefined) {
      resolved.CONFIDENCE = msg.CONFIDENCE;
    }
    else {
      resolved.CONFIDENCE = []
    }

    if (msg.DISTANCE !== undefined) {
      resolved.DISTANCE = msg.DISTANCE;
    }
    else {
      resolved.DISTANCE = []
    }

    if (msg.POINT_VEC_X !== undefined) {
      resolved.POINT_VEC_X = msg.POINT_VEC_X;
    }
    else {
      resolved.POINT_VEC_X = []
    }

    if (msg.POINT_VEC_Y !== undefined) {
      resolved.POINT_VEC_Y = msg.POINT_VEC_Y;
    }
    else {
      resolved.POINT_VEC_Y = []
    }

    if (msg.TYPE !== undefined) {
      resolved.TYPE = msg.TYPE;
    }
    else {
      resolved.TYPE = []
    }

    return resolved;
    }
};

module.exports = robocup_vision24_feature;
