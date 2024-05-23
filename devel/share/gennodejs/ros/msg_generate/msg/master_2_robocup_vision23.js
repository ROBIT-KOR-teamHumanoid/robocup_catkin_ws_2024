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

class master_2_robocup_vision23 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Scan_Mode = null;
      this.PAN = null;
      this.TILT = null;
    }
    else {
      if (initObj.hasOwnProperty('Scan_Mode')) {
        this.Scan_Mode = initObj.Scan_Mode
      }
      else {
        this.Scan_Mode = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type master_2_robocup_vision23
    // Serialize message field [Scan_Mode]
    bufferOffset = _serializer.int64(obj.Scan_Mode, buffer, bufferOffset);
    // Serialize message field [PAN]
    bufferOffset = _serializer.float64(obj.PAN, buffer, bufferOffset);
    // Serialize message field [TILT]
    bufferOffset = _serializer.float64(obj.TILT, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type master_2_robocup_vision23
    let len;
    let data = new master_2_robocup_vision23(null);
    // Deserialize message field [Scan_Mode]
    data.Scan_Mode = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [PAN]
    data.PAN = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [TILT]
    data.TILT = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/master_2_robocup_vision23';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b5fe0eb4136cf0ddbbf95ffa2d2e7754';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 Scan_Mode
    float64 PAN
    float64 TILT
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new master_2_robocup_vision23(null);
    if (msg.Scan_Mode !== undefined) {
      resolved.Scan_Mode = msg.Scan_Mode;
    }
    else {
      resolved.Scan_Mode = 0
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

    return resolved;
    }
};

module.exports = master_2_robocup_vision23;
