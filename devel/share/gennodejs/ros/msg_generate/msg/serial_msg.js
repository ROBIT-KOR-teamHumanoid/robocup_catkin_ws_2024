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

class serial_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.length = null;
      this.mode = null;
      this.id = null;
      this.speed = null;
      this.position = null;
      this.type = null;
      this.acceleration = null;
      this.Motion_Mode = null;
      this.Motion_Num = null;
    }
    else {
      if (initObj.hasOwnProperty('length')) {
        this.length = initObj.length
      }
      else {
        this.length = 0;
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = [];
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = [];
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = [];
      }
      if (initObj.hasOwnProperty('type')) {
        this.type = initObj.type
      }
      else {
        this.type = [];
      }
      if (initObj.hasOwnProperty('acceleration')) {
        this.acceleration = initObj.acceleration
      }
      else {
        this.acceleration = [];
      }
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
    // Serializes a message object of type serial_msg
    // Serialize message field [length]
    bufferOffset = _serializer.int32(obj.length, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.int32(obj.mode, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _arraySerializer.int32(obj.id, buffer, bufferOffset, null);
    // Serialize message field [speed]
    bufferOffset = _arraySerializer.int32(obj.speed, buffer, bufferOffset, null);
    // Serialize message field [position]
    bufferOffset = _arraySerializer.int32(obj.position, buffer, bufferOffset, null);
    // Serialize message field [type]
    bufferOffset = _arraySerializer.int32(obj.type, buffer, bufferOffset, null);
    // Serialize message field [acceleration]
    bufferOffset = _arraySerializer.int32(obj.acceleration, buffer, bufferOffset, null);
    // Serialize message field [Motion_Mode]
    bufferOffset = _serializer.int32(obj.Motion_Mode, buffer, bufferOffset);
    // Serialize message field [Motion_Num]
    bufferOffset = _serializer.char(obj.Motion_Num, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type serial_msg
    let len;
    let data = new serial_msg(null);
    // Deserialize message field [length]
    data.length = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [speed]
    data.speed = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [position]
    data.position = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [type]
    data.type = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [acceleration]
    data.acceleration = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [Motion_Mode]
    data.Motion_Mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Motion_Num]
    data.Motion_Num = _deserializer.char(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.id.length;
    length += 4 * object.speed.length;
    length += 4 * object.position.length;
    length += 4 * object.type.length;
    length += 4 * object.acceleration.length;
    return length + 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_generate/serial_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fbc3cf6a4f8860d2007547b0553a4524';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 length
    int32 mode
    int32[] id
    int32[] speed
    int32[] position
    int32[] type
    int32[] acceleration
    
    int32 Motion_Mode
    char Motion_Num
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new serial_msg(null);
    if (msg.length !== undefined) {
      resolved.length = msg.length;
    }
    else {
      resolved.length = 0
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = []
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = []
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = []
    }

    if (msg.type !== undefined) {
      resolved.type = msg.type;
    }
    else {
      resolved.type = []
    }

    if (msg.acceleration !== undefined) {
      resolved.acceleration = msg.acceleration;
    }
    else {
      resolved.acceleration = []
    }

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

module.exports = serial_msg;
