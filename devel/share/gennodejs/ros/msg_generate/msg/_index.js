
"use strict";

let game_control_return_data = require('./game_control_return_data.js');
let udp_order = require('./udp_order.js');
let udp_kicker_msg = require('./udp_kicker_msg.js');
let zmp_msg = require('./zmp_msg.js');
let ikcoordinate_msg = require('./ikcoordinate_msg.js');
let robocup_localization24_obstacle = require('./robocup_localization24_obstacle.js');
let Serial2LC_msg = require('./Serial2LC_msg.js');
let obsnavi = require('./obsnavi.js');
let motionNum_msg = require('./motionNum_msg.js');
let master2hanoi_vision2019msg = require('./master2hanoi_vision2019msg.js');
let com_msg = require('./com_msg.js');
let R_LC_msg = require('./R_LC_msg.js');
let master2localization24 = require('./master2localization24.js');
let position_msg = require('./position_msg.js');
let Local_msg = require('./Local_msg.js');
let Motor_msg_pt = require('./Motor_msg_pt.js');
let udp_msg = require('./udp_msg.js');
let Local_Info = require('./Local_Info.js');
let serial_msg = require('./serial_msg.js');
let motion_stop = require('./motion_stop.js');
let Motion_msg = require('./Motion_msg.js');
let robocup_vision23_feature = require('./robocup_vision23_feature.js');
let localv2_msg = require('./localv2_msg.js');
let master2vision_msg = require('./master2vision_msg.js');
let localization_msg = require('./localization_msg.js');
let motion_balance = require('./motion_balance.js');
let master_2_robocup_vision24 = require('./master_2_robocup_vision24.js');
let udp_msg_TC_Kicker = require('./udp_msg_TC_Kicker.js');
let support_onestep_msg = require('./support_onestep_msg.js');
let yaw_set = require('./yaw_set.js');
let motion_operator_data = require('./motion_operator_data.js');
let Step_msg = require('./Step_msg.js');
let HSV = require('./HSV.js');
let eom_msg = require('./eom_msg.js');
let robocup24_master2udp = require('./robocup24_master2udp.js');
let udp_balldt = require('./udp_balldt.js');
let master2localization23 = require('./master2localization23.js');
let game_control_data = require('./game_control_data.js');
let ik_msg = require('./ik_msg.js');
let robocupvision = require('./robocupvision.js');
let robocup_localization23 = require('./robocup_localization23.js');
let master_2_robocup_vision23 = require('./master_2_robocup_vision23.js');
let master2localization23_technical_obstacle = require('./master2localization23_technical_obstacle.js');
let robocup_vision24 = require('./robocup_vision24.js');
let Mt2Serial_msg = require('./Mt2Serial_msg.js');
let pan_tilt_msg = require('./pan_tilt_msg.js');
let walk_pattern = require('./walk_pattern.js');
let angle2 = require('./angle2.js');
let tune2walk = require('./tune2walk.js');
let wheel_msg = require('./wheel_msg.js');
let ik_angle_sim = require('./ik_angle_sim.js');
let robocup_vision23 = require('./robocup_vision23.js');
let scv_vision = require('./scv_vision.js');
let master2path_msg = require('./master2path_msg.js');
let robocup_localization24 = require('./robocup_localization24.js');
let imu_msg = require('./imu_msg.js');
let pid_tuning = require('./pid_tuning.js');
let robocup_vision24_feature = require('./robocup_vision24_feature.js');
let udp_helper_msg = require('./udp_helper_msg.js');
let robocupcontroller = require('./robocupcontroller.js');
let motion_end = require('./motion_end.js');
let kuro_cotton_candy = require('./kuro_cotton_candy.js');
let Motor_msg = require('./Motor_msg.js');
let L_LC_msg = require('./L_LC_msg.js');
let Landing_Time_Control = require('./Landing_Time_Control.js');
let ikend_msg = require('./ikend_msg.js');
let udp_msg_TC_Helper = require('./udp_msg_TC_Helper.js');

module.exports = {
  game_control_return_data: game_control_return_data,
  udp_order: udp_order,
  udp_kicker_msg: udp_kicker_msg,
  zmp_msg: zmp_msg,
  ikcoordinate_msg: ikcoordinate_msg,
  robocup_localization24_obstacle: robocup_localization24_obstacle,
  Serial2LC_msg: Serial2LC_msg,
  obsnavi: obsnavi,
  motionNum_msg: motionNum_msg,
  master2hanoi_vision2019msg: master2hanoi_vision2019msg,
  com_msg: com_msg,
  R_LC_msg: R_LC_msg,
  master2localization24: master2localization24,
  position_msg: position_msg,
  Local_msg: Local_msg,
  Motor_msg_pt: Motor_msg_pt,
  udp_msg: udp_msg,
  Local_Info: Local_Info,
  serial_msg: serial_msg,
  motion_stop: motion_stop,
  Motion_msg: Motion_msg,
  robocup_vision23_feature: robocup_vision23_feature,
  localv2_msg: localv2_msg,
  master2vision_msg: master2vision_msg,
  localization_msg: localization_msg,
  motion_balance: motion_balance,
  master_2_robocup_vision24: master_2_robocup_vision24,
  udp_msg_TC_Kicker: udp_msg_TC_Kicker,
  support_onestep_msg: support_onestep_msg,
  yaw_set: yaw_set,
  motion_operator_data: motion_operator_data,
  Step_msg: Step_msg,
  HSV: HSV,
  eom_msg: eom_msg,
  robocup24_master2udp: robocup24_master2udp,
  udp_balldt: udp_balldt,
  master2localization23: master2localization23,
  game_control_data: game_control_data,
  ik_msg: ik_msg,
  robocupvision: robocupvision,
  robocup_localization23: robocup_localization23,
  master_2_robocup_vision23: master_2_robocup_vision23,
  master2localization23_technical_obstacle: master2localization23_technical_obstacle,
  robocup_vision24: robocup_vision24,
  Mt2Serial_msg: Mt2Serial_msg,
  pan_tilt_msg: pan_tilt_msg,
  walk_pattern: walk_pattern,
  angle2: angle2,
  tune2walk: tune2walk,
  wheel_msg: wheel_msg,
  ik_angle_sim: ik_angle_sim,
  robocup_vision23: robocup_vision23,
  scv_vision: scv_vision,
  master2path_msg: master2path_msg,
  robocup_localization24: robocup_localization24,
  imu_msg: imu_msg,
  pid_tuning: pid_tuning,
  robocup_vision24_feature: robocup_vision24_feature,
  udp_helper_msg: udp_helper_msg,
  robocupcontroller: robocupcontroller,
  motion_end: motion_end,
  kuro_cotton_candy: kuro_cotton_candy,
  Motor_msg: Motor_msg,
  L_LC_msg: L_LC_msg,
  Landing_Time_Control: Landing_Time_Control,
  ikend_msg: ikend_msg,
  udp_msg_TC_Helper: udp_msg_TC_Helper,
};
