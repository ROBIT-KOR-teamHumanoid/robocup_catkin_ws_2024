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

class zmp_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Left_X_zmp = null;
      this.Left_Y_zmp = null;
      this.Right_X_zmp = null;
      this.Right_Y_zmp = null;
      this.Total_X_zmp = null;
      this.Total_Y_zmp = null;
      this.Left_Foot = null;
      this.Right_Foot = null;
      this.Both_Feet = null;
    }
    else {
      if (initObj.hasOwnProperty('Left_X_zmp')) {
        this.Left_X_zmp = initObj.Left_X_zmp
      }
      else {
        this.Left_X_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Left_Y_zmp')) {
        this.Left_Y_zmp = initObj.Left_Y_zmp
      }
      else {
        this.Left_Y_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Right_X_zmp')) {
        this.Right_X_zmp = initObj.Right_X_zmp
      }
      else {
        this.Right_X_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Right_Y_zmp')) {
        this.Right_Y_zmp = initObj.Right_Y_zmp
      }
      else {
        this.Right_Y_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Total_X_zmp')) {
        this.Total_X_zmp = initObj.Total_X_zmp
      }
      else {
        this.Total_X_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Total_Y_zmp')) {
        this.Total_Y_zmp = initObj.Total_Y_zmp
      }
      else {
        this.Total_Y_zmp = 0.0;
      }
      if (initObj.hasOwnProperty('Left_Foot')) {
        this.Left_Foot = initObj.Left_Foot
      }
      else {
        this.Left_Foot = false;
      }
      if (initObj.hasOwnProperty('Right_Foot')) {
        this.Right_Foot = initObj.Right_Foot
      }
      else {
        this.Right_Foot = false;
      }
      if (initObj.hasOwnProperty('Both_Feet')) {
        this.Both_Feet = initObj.Both_Feet
      }
      else {
        this.Both_Feet = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type zmp_msg
    // Serialize message field [Left_X_zmp]
    bufferOffset = _serializer.float64(obj.Left_X_zmp, buffer, bufferOffset);
    // Serialize message field [Left_Y_zmp]
    bufferOffset = _serializer.float64(obj.Left_Y_zmp, buffer, bufferOffset);
    // Serialize message field [Right_X_zmp]
    bufferOffset = _serializer.float64(obj.Right_X_zmp, buffer, bufferOffset);
    // Serialize message field [Right_Y_zmp]
    bufferOffset = _serializer.float64(obj.Right_Y_zmp, buffer, bufferOffset);
    // Serialize message field [Total_X_zmp]
    bufferOffset = _serializer.float64(obj.Total_X_zmp, buffer, bufferOffset);
    // Serialize message field [Total_Y_zmp]
    bufferOffset = _serializer.float64(obj.Total_Y_zmp, buffer, bufferOffset);
    // Serialize message field [Left_Foot]
    bufferOffset = _serializer.bool(obj.Left_Foot, buffer, bufferOffset);
    // Serialize message field [Right_Foot]
    bufferOffset = _serializer.bool(obj.Right_Foot, buffer, bufferOffset);
    // Serialize message field [Both_Feet]
    bufferOffset = _serializer.bool(obj.Both_Feet, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type zmp_msg
    let len;
    let data = new zmp_msg(null);
    // Deserialize message field [Left_X_zmp]
    data.Left_X_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Left_Y_zmp]
    data.Left_Y_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Right_X_zmp]
    data.Right_X_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Right_Y_zmp]
    data.Right_Y_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Total_X_zmp]
    data.Total_X_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Total_Y_zmp]
    data.Total_Y_zmp = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Left_Foot]
    data.Left_Foot = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Right_Foot]
    data.Right_Foot = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Both_Feet]
    data.Both_Feet = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 51;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/zmp_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b6dd8aae25ccfd762514817678c236ea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 Left_X_zmp
    float64 Left_Y_zmp
    float64 Right_X_zmp
    float64 Right_Y_zmp
    float64 Total_X_zmp
    float64 Total_Y_zmp
    bool Left_Foot
    bool Right_Foot
    bool Both_Feet
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new zmp_msg(null);
    if (msg.Left_X_zmp !== undefined) {
      resolved.Left_X_zmp = msg.Left_X_zmp;
    }
    else {
      resolved.Left_X_zmp = 0.0
    }

    if (msg.Left_Y_zmp !== undefined) {
      resolved.Left_Y_zmp = msg.Left_Y_zmp;
    }
    else {
      resolved.Left_Y_zmp = 0.0
    }

    if (msg.Right_X_zmp !== undefined) {
      resolved.Right_X_zmp = msg.Right_X_zmp;
    }
    else {
      resolved.Right_X_zmp = 0.0
    }

    if (msg.Right_Y_zmp !== undefined) {
      resolved.Right_Y_zmp = msg.Right_Y_zmp;
    }
    else {
      resolved.Right_Y_zmp = 0.0
    }

    if (msg.Total_X_zmp !== undefined) {
      resolved.Total_X_zmp = msg.Total_X_zmp;
    }
    else {
      resolved.Total_X_zmp = 0.0
    }

    if (msg.Total_Y_zmp !== undefined) {
      resolved.Total_Y_zmp = msg.Total_Y_zmp;
    }
    else {
      resolved.Total_Y_zmp = 0.0
    }

    if (msg.Left_Foot !== undefined) {
      resolved.Left_Foot = msg.Left_Foot;
    }
    else {
      resolved.Left_Foot = false
    }

    if (msg.Right_Foot !== undefined) {
      resolved.Right_Foot = msg.Right_Foot;
    }
    else {
      resolved.Right_Foot = false
    }

    if (msg.Both_Feet !== undefined) {
      resolved.Both_Feet = msg.Both_Feet;
    }
    else {
      resolved.Both_Feet = false
    }

    return resolved;
    }
};

module.exports = zmp_msg;
