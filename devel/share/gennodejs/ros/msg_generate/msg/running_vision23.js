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

class running_vision23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.line_cam_X = null;
      this.line_cam_Y = null;
      this.line_2d_X = null;
      this.line_2d_Y = null;
      this.line_D = null;
      this.line_theta = null;
      this.cross_cam_X = null;
      this.cross_cam_Y = null;
      this.cross_2d_X = null;
      this.cross_2d_Y = null;
      this.cross_D = null;
      this.hurdle_cam_X = null;
      this.hurdle_cam_Y = null;
      this.hurdle_2d_X = null;
      this.hurdle_2d_Y = null;
      this.hurdle_D = null;
      this.hurdle_theta = null;
      this.PAN = null;
      this.TILT = null;
      this.Scan_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('line_cam_X')) {
        this.line_cam_X = initObj.line_cam_X
      }
      else {
        this.line_cam_X = [];
      }
      if (initObj.hasOwnProperty('line_cam_Y')) {
        this.line_cam_Y = initObj.line_cam_Y
      }
      else {
        this.line_cam_Y = [];
      }
      if (initObj.hasOwnProperty('line_2d_X')) {
        this.line_2d_X = initObj.line_2d_X
      }
      else {
        this.line_2d_X = [];
      }
      if (initObj.hasOwnProperty('line_2d_Y')) {
        this.line_2d_Y = initObj.line_2d_Y
      }
      else {
        this.line_2d_Y = [];
      }
      if (initObj.hasOwnProperty('line_D')) {
        this.line_D = initObj.line_D
      }
      else {
        this.line_D = [];
      }
      if (initObj.hasOwnProperty('line_theta')) {
        this.line_theta = initObj.line_theta
      }
      else {
        this.line_theta = 0.0;
      }
      if (initObj.hasOwnProperty('cross_cam_X')) {
        this.cross_cam_X = initObj.cross_cam_X
      }
      else {
        this.cross_cam_X = 0;
      }
      if (initObj.hasOwnProperty('cross_cam_Y')) {
        this.cross_cam_Y = initObj.cross_cam_Y
      }
      else {
        this.cross_cam_Y = 0;
      }
      if (initObj.hasOwnProperty('cross_2d_X')) {
        this.cross_2d_X = initObj.cross_2d_X
      }
      else {
        this.cross_2d_X = 0.0;
      }
      if (initObj.hasOwnProperty('cross_2d_Y')) {
        this.cross_2d_Y = initObj.cross_2d_Y
      }
      else {
        this.cross_2d_Y = 0.0;
      }
      if (initObj.hasOwnProperty('cross_D')) {
        this.cross_D = initObj.cross_D
      }
      else {
        this.cross_D = 0.0;
      }
      if (initObj.hasOwnProperty('hurdle_cam_X')) {
        this.hurdle_cam_X = initObj.hurdle_cam_X
      }
      else {
        this.hurdle_cam_X = 0;
      }
      if (initObj.hasOwnProperty('hurdle_cam_Y')) {
        this.hurdle_cam_Y = initObj.hurdle_cam_Y
      }
      else {
        this.hurdle_cam_Y = 0;
      }
      if (initObj.hasOwnProperty('hurdle_2d_X')) {
        this.hurdle_2d_X = initObj.hurdle_2d_X
      }
      else {
        this.hurdle_2d_X = 0.0;
      }
      if (initObj.hasOwnProperty('hurdle_2d_Y')) {
        this.hurdle_2d_Y = initObj.hurdle_2d_Y
      }
      else {
        this.hurdle_2d_Y = 0.0;
      }
      if (initObj.hasOwnProperty('hurdle_D')) {
        this.hurdle_D = initObj.hurdle_D
      }
      else {
        this.hurdle_D = 0.0;
      }
      if (initObj.hasOwnProperty('hurdle_theta')) {
        this.hurdle_theta = initObj.hurdle_theta
      }
      else {
        this.hurdle_theta = 0.0;
      }
      if (initObj.hasOwnProperty('PAN')) {
        this.PAN = initObj.PAN
      }
      else {
        this.PAN = 0.0;
      }
      if (initObj.hasOwnProperty('TILT')) {
        this.TILT = initObj.TILT
      }
      else {
        this.TILT = 0.0;
      }
      if (initObj.hasOwnProperty('Scan_mode')) {
        this.Scan_mode = initObj.Scan_mode
      }
      else {
        this.Scan_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type running_vision23
    // Serialize message field [line_cam_X]
    bufferOffset = _arraySerializer.int64(obj.line_cam_X, buffer, bufferOffset, null);
    // Serialize message field [line_cam_Y]
    bufferOffset = _arraySerializer.int64(obj.line_cam_Y, buffer, bufferOffset, null);
    // Serialize message field [line_2d_X]
    bufferOffset = _arraySerializer.float64(obj.line_2d_X, buffer, bufferOffset, null);
    // Serialize message field [line_2d_Y]
    bufferOffset = _arraySerializer.float64(obj.line_2d_Y, buffer, bufferOffset, null);
    // Serialize message field [line_D]
    bufferOffset = _arraySerializer.float64(obj.line_D, buffer, bufferOffset, null);
    // Serialize message field [line_theta]
    bufferOffset = _serializer.float64(obj.line_theta, buffer, bufferOffset);
    // Serialize message field [cross_cam_X]
    bufferOffset = _serializer.int64(obj.cross_cam_X, buffer, bufferOffset);
    // Serialize message field [cross_cam_Y]
    bufferOffset = _serializer.int64(obj.cross_cam_Y, buffer, bufferOffset);
    // Serialize message field [cross_2d_X]
    bufferOffset = _serializer.float64(obj.cross_2d_X, buffer, bufferOffset);
    // Serialize message field [cross_2d_Y]
    bufferOffset = _serializer.float64(obj.cross_2d_Y, buffer, bufferOffset);
    // Serialize message field [cross_D]
    bufferOffset = _serializer.float64(obj.cross_D, buffer, bufferOffset);
    // Serialize message field [hurdle_cam_X]
    bufferOffset = _serializer.int64(obj.hurdle_cam_X, buffer, bufferOffset);
    // Serialize message field [hurdle_cam_Y]
    bufferOffset = _serializer.int64(obj.hurdle_cam_Y, buffer, bufferOffset);
    // Serialize message field [hurdle_2d_X]
    bufferOffset = _serializer.float64(obj.hurdle_2d_X, buffer, bufferOffset);
    // Serialize message field [hurdle_2d_Y]
    bufferOffset = _serializer.float64(obj.hurdle_2d_Y, buffer, bufferOffset);
    // Serialize message field [hurdle_D]
    bufferOffset = _serializer.float64(obj.hurdle_D, buffer, bufferOffset);
    // Serialize message field [hurdle_theta]
    bufferOffset = _serializer.float64(obj.hurdle_theta, buffer, bufferOffset);
    // Serialize message field [PAN]
    bufferOffset = _serializer.float64(obj.PAN, buffer, bufferOffset);
    // Serialize message field [TILT]
    bufferOffset = _serializer.float64(obj.TILT, buffer, bufferOffset);
    // Serialize message field [Scan_mode]
    bufferOffset = _serializer.int64(obj.Scan_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type running_vision23
    let len;
    let data = new running_vision23(null);
    // Deserialize message field [line_cam_X]
    data.line_cam_X = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [line_cam_Y]
    data.line_cam_Y = _arrayDeserializer.int64(buffer, bufferOffset, null)
    // Deserialize message field [line_2d_X]
    data.line_2d_X = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [line_2d_Y]
    data.line_2d_Y = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [line_D]
    data.line_D = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [line_theta]
    data.line_theta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cross_cam_X]
    data.cross_cam_X = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [cross_cam_Y]
    data.cross_cam_Y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [cross_2d_X]
    data.cross_2d_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cross_2d_Y]
    data.cross_2d_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cross_D]
    data.cross_D = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [hurdle_cam_X]
    data.hurdle_cam_X = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hurdle_cam_Y]
    data.hurdle_cam_Y = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hurdle_2d_X]
    data.hurdle_2d_X = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [hurdle_2d_Y]
    data.hurdle_2d_Y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [hurdle_D]
    data.hurdle_D = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [hurdle_theta]
    data.hurdle_theta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [PAN]
    data.PAN = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [TILT]
    data.TILT = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Scan_mode]
    data.Scan_mode = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.line_cam_X.length;
    length += 8 * object.line_cam_Y.length;
    length += 8 * object.line_2d_X.length;
    length += 8 * object.line_2d_Y.length;
    length += 8 * object.line_D.length;
    return length + 140;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/running_vision23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '84bbd3957c09a95986b5eb7beba9cf54';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64[] line_cam_X
    int64[] line_cam_Y
    float64[] line_2d_X
    float64[] line_2d_Y
    float64[] line_D
    float64 line_theta
    
    int64 cross_cam_X
    int64 cross_cam_Y
    float64 cross_2d_X
    float64 cross_2d_Y
    float64 cross_D
    
    int64 hurdle_cam_X
    int64 hurdle_cam_Y
    float64 hurdle_2d_X
    float64 hurdle_2d_Y
    float64 hurdle_D
    float64 hurdle_theta
    
    float64 PAN
    float64 TILT
    int64 Scan_mode
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new running_vision23(null);
    if (msg.line_cam_X !== undefined) {
      resolved.line_cam_X = msg.line_cam_X;
    }
    else {
      resolved.line_cam_X = []
    }

    if (msg.line_cam_Y !== undefined) {
      resolved.line_cam_Y = msg.line_cam_Y;
    }
    else {
      resolved.line_cam_Y = []
    }

    if (msg.line_2d_X !== undefined) {
      resolved.line_2d_X = msg.line_2d_X;
    }
    else {
      resolved.line_2d_X = []
    }

    if (msg.line_2d_Y !== undefined) {
      resolved.line_2d_Y = msg.line_2d_Y;
    }
    else {
      resolved.line_2d_Y = []
    }

    if (msg.line_D !== undefined) {
      resolved.line_D = msg.line_D;
    }
    else {
      resolved.line_D = []
    }

    if (msg.line_theta !== undefined) {
      resolved.line_theta = msg.line_theta;
    }
    else {
      resolved.line_theta = 0.0
    }

    if (msg.cross_cam_X !== undefined) {
      resolved.cross_cam_X = msg.cross_cam_X;
    }
    else {
      resolved.cross_cam_X = 0
    }

    if (msg.cross_cam_Y !== undefined) {
      resolved.cross_cam_Y = msg.cross_cam_Y;
    }
    else {
      resolved.cross_cam_Y = 0
    }

    if (msg.cross_2d_X !== undefined) {
      resolved.cross_2d_X = msg.cross_2d_X;
    }
    else {
      resolved.cross_2d_X = 0.0
    }

    if (msg.cross_2d_Y !== undefined) {
      resolved.cross_2d_Y = msg.cross_2d_Y;
    }
    else {
      resolved.cross_2d_Y = 0.0
    }

    if (msg.cross_D !== undefined) {
      resolved.cross_D = msg.cross_D;
    }
    else {
      resolved.cross_D = 0.0
    }

    if (msg.hurdle_cam_X !== undefined) {
      resolved.hurdle_cam_X = msg.hurdle_cam_X;
    }
    else {
      resolved.hurdle_cam_X = 0
    }

    if (msg.hurdle_cam_Y !== undefined) {
      resolved.hurdle_cam_Y = msg.hurdle_cam_Y;
    }
    else {
      resolved.hurdle_cam_Y = 0
    }

    if (msg.hurdle_2d_X !== undefined) {
      resolved.hurdle_2d_X = msg.hurdle_2d_X;
    }
    else {
      resolved.hurdle_2d_X = 0.0
    }

    if (msg.hurdle_2d_Y !== undefined) {
      resolved.hurdle_2d_Y = msg.hurdle_2d_Y;
    }
    else {
      resolved.hurdle_2d_Y = 0.0
    }

    if (msg.hurdle_D !== undefined) {
      resolved.hurdle_D = msg.hurdle_D;
    }
    else {
      resolved.hurdle_D = 0.0
    }

    if (msg.hurdle_theta !== undefined) {
      resolved.hurdle_theta = msg.hurdle_theta;
    }
    else {
      resolved.hurdle_theta = 0.0
    }

    if (msg.PAN !== undefined) {
      resolved.PAN = msg.PAN;
    }
    else {
      resolved.PAN = 0.0
    }

    if (msg.TILT !== undefined) {
      resolved.TILT = msg.TILT;
    }
    else {
      resolved.TILT = 0.0
    }

    if (msg.Scan_mode !== undefined) {
      resolved.Scan_mode = msg.Scan_mode;
    }
    else {
      resolved.Scan_mode = 0
    }

    return resolved;
    }
};

module.exports = running_vision23;
