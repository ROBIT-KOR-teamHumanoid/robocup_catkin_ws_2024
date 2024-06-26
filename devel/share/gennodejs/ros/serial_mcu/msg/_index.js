
"use strict";

let serial_msg = require('./serial_msg.js');
let Mt2Serial_msg = require('./Mt2Serial_msg.js');
<<<<<<< Updated upstream
let Motor_msg = require('./Motor_msg.js');
let motion_end = require('./motion_end.js');
=======
let motion_end = require('./motion_end.js');
let Motor_msg = require('./Motor_msg.js');
>>>>>>> Stashed changes

module.exports = {
  serial_msg: serial_msg,
  Mt2Serial_msg: Mt2Serial_msg,
<<<<<<< Updated upstream
  Motor_msg: Motor_msg,
  motion_end: motion_end,
=======
  motion_end: motion_end,
  Motor_msg: Motor_msg,
>>>>>>> Stashed changes
};
