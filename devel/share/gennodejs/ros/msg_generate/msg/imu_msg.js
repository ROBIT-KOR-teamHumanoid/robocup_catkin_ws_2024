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

class imu_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.roll = null;
      this.pitch = null;
      this.yaw = null;
      this.roll_acc = null;
      this.pitch_acc = null;
      this.yaw_acc = null;
    }
    else {
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0.0;
      }
      if (initObj.hasOwnProperty('roll_acc')) {
        this.roll_acc = initObj.roll_acc
      }
      else {
        this.roll_acc = 0.0;
      }
      if (initObj.hasOwnProperty('pitch_acc')) {
        this.pitch_acc = initObj.pitch_acc
      }
      else {
        this.pitch_acc = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_acc')) {
        this.yaw_acc = initObj.yaw_acc
      }
      else {
        this.yaw_acc = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type imu_msg
    // Serialize message field [roll]
    bufferOffset = _serializer.float32(obj.roll, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float32(obj.pitch, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float32(obj.yaw, buffer, bufferOffset);
    // Serialize message field [roll_acc]
    bufferOffset = _serializer.float32(obj.roll_acc, buffer, bufferOffset);
    // Serialize message field [pitch_acc]
    bufferOffset = _serializer.float32(obj.pitch_acc, buffer, bufferOffset);
    // Serialize message field [yaw_acc]
    bufferOffset = _serializer.float32(obj.yaw_acc, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type imu_msg
    let len;
    let data = new imu_msg(null);
    // Deserialize message field [roll]
    data.roll = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [roll_acc]
    data.roll_acc = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch_acc]
    data.pitch_acc = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw_acc]
    data.yaw_acc = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/imu_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7a5074fa2c7055370ef50e1051a0c7bf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 roll
    float32 pitch
    float32 yaw
    float32 roll_acc
    float32 pitch_acc
    float32 yaw_acc
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new imu_msg(null);
    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0.0
    }

    if (msg.roll_acc !== undefined) {
      resolved.roll_acc = msg.roll_acc;
    }
    else {
      resolved.roll_acc = 0.0
    }

    if (msg.pitch_acc !== undefined) {
      resolved.pitch_acc = msg.pitch_acc;
    }
    else {
      resolved.pitch_acc = 0.0
    }

    if (msg.yaw_acc !== undefined) {
      resolved.yaw_acc = msg.yaw_acc;
    }
    else {
      resolved.yaw_acc = 0.0
    }

    return resolved;
    }
};

module.exports = imu_msg;
