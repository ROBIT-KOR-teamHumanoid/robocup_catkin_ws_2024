// Auto-generated. Do not edit!

// (in-package serial_mcu.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Mt2Serial_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Motion_Mode = null;
      this.Motion_Num = null;
    }
    else {
      if (initObj.hasOwnProperty('Motion_Mode')) {
        this.Motion_Mode = initObj.Motion_Mode
      }
      else {
        this.Motion_Mode = 0;
      }
      if (initObj.hasOwnProperty('Motion_Num')) {
        this.Motion_Num = initObj.Motion_Num
      }
      else {
        this.Motion_Num = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Mt2Serial_msg
    // Serialize message field [Motion_Mode]
    bufferOffset = _serializer.int32(obj.Motion_Mode, buffer, bufferOffset);
    // Serialize message field [Motion_Num]
    bufferOffset = _serializer.int32(obj.Motion_Num, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Mt2Serial_msg
    let len;
    let data = new Mt2Serial_msg(null);
    // Deserialize message field [Motion_Mode]
    data.Motion_Mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Motion_Num]
    data.Motion_Num = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'serial_mcu/Mt2Serial_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e3f9ec431b0fdc81956c12a8b317c691';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 Motion_Mode
    int32 Motion_Num
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Mt2Serial_msg(null);
    if (msg.Motion_Mode !== undefined) {
      resolved.Motion_Mode = msg.Motion_Mode;
    }
    else {
      resolved.Motion_Mode = 0
    }

    if (msg.Motion_Num !== undefined) {
      resolved.Motion_Num = msg.Motion_Num;
    }
    else {
      resolved.Motion_Num = 0
    }

    return resolved;
    }
};

module.exports = Mt2Serial_msg;
