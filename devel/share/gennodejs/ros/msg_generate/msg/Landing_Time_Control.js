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

class Landing_Time_Control {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Entire_Time = null;
      this.Swing_Gain_L = null;
      this.Swing_Gain_R = null;
      this.Warning = null;
      this.Safe = null;
      this.Landing_Time_L = null;
      this.Landing_Time_R = null;
      this.Landing_Error_L = null;
      this.Landing_Error_R = null;
    }
    else {
      if (initObj.hasOwnProperty('Entire_Time')) {
        this.Entire_Time = initObj.Entire_Time
      }
      else {
        this.Entire_Time = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Gain_L')) {
        this.Swing_Gain_L = initObj.Swing_Gain_L
      }
      else {
        this.Swing_Gain_L = 0.0;
      }
      if (initObj.hasOwnProperty('Swing_Gain_R')) {
        this.Swing_Gain_R = initObj.Swing_Gain_R
      }
      else {
        this.Swing_Gain_R = 0.0;
      }
      if (initObj.hasOwnProperty('Warning')) {
        this.Warning = initObj.Warning
      }
      else {
        this.Warning = 0;
      }
      if (initObj.hasOwnProperty('Safe')) {
        this.Safe = initObj.Safe
      }
      else {
        this.Safe = 0;
      }
      if (initObj.hasOwnProperty('Landing_Time_L')) {
        this.Landing_Time_L = initObj.Landing_Time_L
      }
      else {
        this.Landing_Time_L = 0.0;
      }
      if (initObj.hasOwnProperty('Landing_Time_R')) {
        this.Landing_Time_R = initObj.Landing_Time_R
      }
      else {
        this.Landing_Time_R = 0.0;
      }
      if (initObj.hasOwnProperty('Landing_Error_L')) {
        this.Landing_Error_L = initObj.Landing_Error_L
      }
      else {
        this.Landing_Error_L = 0.0;
      }
      if (initObj.hasOwnProperty('Landing_Error_R')) {
        this.Landing_Error_R = initObj.Landing_Error_R
      }
      else {
        this.Landing_Error_R = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Landing_Time_Control
    // Serialize message field [Entire_Time]
    bufferOffset = _serializer.float64(obj.Entire_Time, buffer, bufferOffset);
    // Serialize message field [Swing_Gain_L]
    bufferOffset = _serializer.float64(obj.Swing_Gain_L, buffer, bufferOffset);
    // Serialize message field [Swing_Gain_R]
    bufferOffset = _serializer.float64(obj.Swing_Gain_R, buffer, bufferOffset);
    // Serialize message field [Warning]
    bufferOffset = _serializer.int64(obj.Warning, buffer, bufferOffset);
    // Serialize message field [Safe]
    bufferOffset = _serializer.int64(obj.Safe, buffer, bufferOffset);
    // Serialize message field [Landing_Time_L]
    bufferOffset = _serializer.float64(obj.Landing_Time_L, buffer, bufferOffset);
    // Serialize message field [Landing_Time_R]
    bufferOffset = _serializer.float64(obj.Landing_Time_R, buffer, bufferOffset);
    // Serialize message field [Landing_Error_L]
    bufferOffset = _serializer.float64(obj.Landing_Error_L, buffer, bufferOffset);
    // Serialize message field [Landing_Error_R]
    bufferOffset = _serializer.float64(obj.Landing_Error_R, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Landing_Time_Control
    let len;
    let data = new Landing_Time_Control(null);
    // Deserialize message field [Entire_Time]
    data.Entire_Time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Gain_L]
    data.Swing_Gain_L = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Swing_Gain_R]
    data.Swing_Gain_R = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Warning]
    data.Warning = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Safe]
    data.Safe = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [Landing_Time_L]
    data.Landing_Time_L = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Landing_Time_R]
    data.Landing_Time_R = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Landing_Error_L]
    data.Landing_Error_L = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Landing_Error_R]
    data.Landing_Error_R = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/Landing_Time_Control';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0231e6c7c4e3ed975ff22fc97b613ccc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 Entire_Time
    float64 Swing_Gain_L
    float64 Swing_Gain_R
    int64 Warning
    int64 Safe
    
    float64 Landing_Time_L
    float64 Landing_Time_R
    
    float64 Landing_Error_L
    float64 Landing_Error_R
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Landing_Time_Control(null);
    if (msg.Entire_Time !== undefined) {
      resolved.Entire_Time = msg.Entire_Time;
    }
    else {
      resolved.Entire_Time = 0.0
    }

    if (msg.Swing_Gain_L !== undefined) {
      resolved.Swing_Gain_L = msg.Swing_Gain_L;
    }
    else {
      resolved.Swing_Gain_L = 0.0
    }

    if (msg.Swing_Gain_R !== undefined) {
      resolved.Swing_Gain_R = msg.Swing_Gain_R;
    }
    else {
      resolved.Swing_Gain_R = 0.0
    }

    if (msg.Warning !== undefined) {
      resolved.Warning = msg.Warning;
    }
    else {
      resolved.Warning = 0
    }

    if (msg.Safe !== undefined) {
      resolved.Safe = msg.Safe;
    }
    else {
      resolved.Safe = 0
    }

    if (msg.Landing_Time_L !== undefined) {
      resolved.Landing_Time_L = msg.Landing_Time_L;
    }
    else {
      resolved.Landing_Time_L = 0.0
    }

    if (msg.Landing_Time_R !== undefined) {
      resolved.Landing_Time_R = msg.Landing_Time_R;
    }
    else {
      resolved.Landing_Time_R = 0.0
    }

    if (msg.Landing_Error_L !== undefined) {
      resolved.Landing_Error_L = msg.Landing_Error_L;
    }
    else {
      resolved.Landing_Error_L = 0.0
    }

    if (msg.Landing_Error_R !== undefined) {
      resolved.Landing_Error_R = msg.Landing_Error_R;
    }
    else {
      resolved.Landing_Error_R = 0.0
    }

    return resolved;
    }
};

module.exports = Landing_Time_Control;
