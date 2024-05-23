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

class ik_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X_length = null;
      this.Y_length = null;
      this.Yaw = null;
      this.flag = null;
      this.One_X_length = null;
      this.One_Y_length = null;
      this.One_YAW = null;
      this.One_step_flag = null;
    }
    else {
      if (initObj.hasOwnProperty('X_length')) {
        this.X_length = initObj.X_length
      }
      else {
        this.X_length = 0.0;
      }
      if (initObj.hasOwnProperty('Y_length')) {
        this.Y_length = initObj.Y_length
      }
      else {
        this.Y_length = 0.0;
      }
      if (initObj.hasOwnProperty('Yaw')) {
        this.Yaw = initObj.Yaw
      }
      else {
        this.Yaw = 0.0;
      }
      if (initObj.hasOwnProperty('flag')) {
        this.flag = initObj.flag
      }
      else {
        this.flag = 0.0;
      }
      if (initObj.hasOwnProperty('One_X_length')) {
        this.One_X_length = initObj.One_X_length
      }
      else {
        this.One_X_length = 0;
      }
      if (initObj.hasOwnProperty('One_Y_length')) {
        this.One_Y_length = initObj.One_Y_length
      }
      else {
        this.One_Y_length = 0;
      }
      if (initObj.hasOwnProperty('One_YAW')) {
        this.One_YAW = initObj.One_YAW
      }
      else {
        this.One_YAW = 0;
      }
      if (initObj.hasOwnProperty('One_step_flag')) {
        this.One_step_flag = initObj.One_step_flag
      }
      else {
        this.One_step_flag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ik_msg
    // Serialize message field [X_length]
    bufferOffset = _serializer.float64(obj.X_length, buffer, bufferOffset);
    // Serialize message field [Y_length]
    bufferOffset = _serializer.float64(obj.Y_length, buffer, bufferOffset);
    // Serialize message field [Yaw]
    bufferOffset = _serializer.float64(obj.Yaw, buffer, bufferOffset);
    // Serialize message field [flag]
    bufferOffset = _serializer.float64(obj.flag, buffer, bufferOffset);
    // Serialize message field [One_X_length]
    bufferOffset = _serializer.int32(obj.One_X_length, buffer, bufferOffset);
    // Serialize message field [One_Y_length]
    bufferOffset = _serializer.int32(obj.One_Y_length, buffer, bufferOffset);
    // Serialize message field [One_YAW]
    bufferOffset = _serializer.int32(obj.One_YAW, buffer, bufferOffset);
    // Serialize message field [One_step_flag]
    bufferOffset = _serializer.int32(obj.One_step_flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ik_msg
    let len;
    let data = new ik_msg(null);
    // Deserialize message field [X_length]
    data.X_length = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Y_length]
    data.Y_length = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Yaw]
    data.Yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [flag]
    data.flag = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [One_X_length]
    data.One_X_length = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [One_Y_length]
    data.One_Y_length = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [One_YAW]
    data.One_YAW = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [One_step_flag]
    data.One_step_flag = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/ik_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1e34403e3b7a9f4022bce7eaacc3d24d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 X_length
    float64 Y_length
    float64 Yaw
    float64 flag
    
    int32 One_X_length
    int32 One_Y_length
    int32 One_YAW
    int32 One_step_flag
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ik_msg(null);
    if (msg.X_length !== undefined) {
      resolved.X_length = msg.X_length;
    }
    else {
      resolved.X_length = 0.0
    }

    if (msg.Y_length !== undefined) {
      resolved.Y_length = msg.Y_length;
    }
    else {
      resolved.Y_length = 0.0
    }

    if (msg.Yaw !== undefined) {
      resolved.Yaw = msg.Yaw;
    }
    else {
      resolved.Yaw = 0.0
    }

    if (msg.flag !== undefined) {
      resolved.flag = msg.flag;
    }
    else {
      resolved.flag = 0.0
    }

    if (msg.One_X_length !== undefined) {
      resolved.One_X_length = msg.One_X_length;
    }
    else {
      resolved.One_X_length = 0
    }

    if (msg.One_Y_length !== undefined) {
      resolved.One_Y_length = msg.One_Y_length;
    }
    else {
      resolved.One_Y_length = 0
    }

    if (msg.One_YAW !== undefined) {
      resolved.One_YAW = msg.One_YAW;
    }
    else {
      resolved.One_YAW = 0
    }

    if (msg.One_step_flag !== undefined) {
      resolved.One_step_flag = msg.One_step_flag;
    }
    else {
      resolved.One_step_flag = 0
    }

    return resolved;
    }
};

module.exports = ik_msg;
