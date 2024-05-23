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

class pan_tilt_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.waist_flag = null;
      this.Angle_Yaw = null;
      this.Angle_Pitch = null;
    }
    else {
      if (initObj.hasOwnProperty('waist_flag')) {
        this.waist_flag = initObj.waist_flag
      }
      else {
        this.waist_flag = 0;
      }
      if (initObj.hasOwnProperty('Angle_Yaw')) {
        this.Angle_Yaw = initObj.Angle_Yaw
      }
      else {
        this.Angle_Yaw = 0.0;
      }
      if (initObj.hasOwnProperty('Angle_Pitch')) {
        this.Angle_Pitch = initObj.Angle_Pitch
      }
      else {
        this.Angle_Pitch = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pan_tilt_msg
    // Serialize message field [waist_flag]
    bufferOffset = _serializer.int32(obj.waist_flag, buffer, bufferOffset);
    // Serialize message field [Angle_Yaw]
    bufferOffset = _serializer.float64(obj.Angle_Yaw, buffer, bufferOffset);
    // Serialize message field [Angle_Pitch]
    bufferOffset = _serializer.float64(obj.Angle_Pitch, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pan_tilt_msg
    let len;
    let data = new pan_tilt_msg(null);
    // Deserialize message field [waist_flag]
    data.waist_flag = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Angle_Yaw]
    data.Angle_Yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Angle_Pitch]
    data.Angle_Pitch = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/pan_tilt_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '611b91cd650b11bf3bb556113e5f1029';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 waist_flag
    
    float64 Angle_Yaw
    float64 Angle_Pitch
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pan_tilt_msg(null);
    if (msg.waist_flag !== undefined) {
      resolved.waist_flag = msg.waist_flag;
    }
    else {
      resolved.waist_flag = 0
    }

    if (msg.Angle_Yaw !== undefined) {
      resolved.Angle_Yaw = msg.Angle_Yaw;
    }
    else {
      resolved.Angle_Yaw = 0.0
    }

    if (msg.Angle_Pitch !== undefined) {
      resolved.Angle_Pitch = msg.Angle_Pitch;
    }
    else {
      resolved.Angle_Pitch = 0.0
    }

    return resolved;
    }
};

module.exports = pan_tilt_msg;
