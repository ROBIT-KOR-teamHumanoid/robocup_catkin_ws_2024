/*==============================================================================
 *
 *   Dynamixel Drive Module
 *
 *      File Name       : Motor_dxl.c
 *      Version         : 1.5
 *      Date            : 2017.06.23
 *      Modified        : 2017.06.23 By Cho, Young-Sin
 *      Author          : Cho, Young-Sin  (ROBIT 8st, Kwangwoon University)
 *      MPU_Type        : STM32F446RB(180MHz)
 *      Compiler        : IAR Eebedded Workbench IDE - ARM 8.11.2
 *      Copyright(c) 2017 ROBIT, Kwangwoon University.
 *      All Rights Reserved.
 *
==============================================================================*/

#ifndef __MOTOR_DXL_h
#define __MOTOR_DXL_h

//-------------------------------------------------------------------------------------------------------------------------------
// define - Dynamixel Hex code table 
//-------------------------------------------------------------------------------------------------------------------------------
                                // EEPROM AREA  
#define P_MODEL_NUMBER_L            0
#define P_MODEL_NUMBER_H            1
#define P_VERSION                   2
#define P_ID                        3
#define P_BAUD_RATE                 4
#define P_RETURN_DELAY_TIME         5
#define P_CW_ANGLE_LIMIT_L          6
#define P_CW_ANGLE_LIMIT_H          7
#define P_CCW_ANGLE_LIMIT_L         8
#define P_CCW_ANGLE_LIMIT_H         9   
#define P_SYSTEM_DATA2              10
#define P_LIMIT_TEMPERATURE         11
#define P_DOWN_LIMIT_VOLTAGE        12
#define P_UP_LIMIT_VOLTAGE          13
#define P_MAX_TORQUE_L              14
#define P_MAX_TORQUE_H              15
#define P_RETURN_LEVEL              16
#define P_ALARM_LED                 17
#define P_ALARM_SHUTDOWN            18
#define P_OPERATING_MODE            19
#define P_DOWN_CALIBRATION_L        20
#define P_DOWN_CALIBRATION_H        21
#define P_UP_CALIBRATION_L          22
#define P_UP_CALIBRATION_H          23

                                // RAM AREA  
#define P_TORQUE_ENABLE             (24)
#define P_LED                       (25)
#define P_CW_COMPLIANCE_MARGIN      (26)
#define P_CCW_COMPLIANCE_MARGIN     (27)
#define P_CW_COMPLIANCE_SLOPE       (28)
#define P_CCW_COMPLIANCE_SLOPE      (29)
#define P_GOAL_POSITION_L           (30)
#define P_GOAL_POSITION_H           (31)
#define P_GOAL_SPEED_L              (32)
#define P_GOAL_SPEED_H              (33)
#define P_TORQUE_LIMIT_L            (34)
#define P_TORQUE_LIMIT_H            (35)
#define P_PRESENT_POSITION_L        (36)
#define P_PRESENT_POSITION_H        (37)
#define P_PRESENT_SPEED_L           (38)
#define P_PRESENT_SPEED_H           (39)
#define P_PRESENT_LOAD_L            (40)
#define P_PRESENT_LOAD_H            (41)
#define P_PRESENT_VOLTAGE           (42)
#define P_PRESENT_TEMPERATURE       (43)
#define P_REGISTERED_INSTRUCTION    (44)
#define P_PAUSE_TIME                (45)
#define P_MOVING                    (46)
#define P_LOCK                      (47)
#define P_PUNCH_L                   (48)
#define P_PUNCH_H                   (49)


//-------------------------------------------------------------------------------------------------------------------------------
// Instruction commands Set 
//-------------------------------------------------------------------------------------------------------------------------------

#define INST_PING                   0x01    // 수행없이 DX의 상태값 확인
#define INST_READ                   0x02    // Control Table 읽기
#define INST_WRITE                  0x03    // Control Table 단일 쓰기
#define INST_REG_WRITE              0x04        // Control Table 단일 쓰기 예약
#define INST_ACTION                 0x05    // Control Table 예약 기능 스타트
#define INST_RESET                  0x06    // Control Table 초기화(주의)
#define INST_DIGITAL_RESET          0x07    // Reserved ?
#define INST_SYSTEM_READ            0x0C    // Reserved ?
#define INST_SYSTEM_WRITE           0x0D    // Reserved ?
#define INST_SYNC_WRITE             0x83    // Control Table 다중 쓰기
#define INST_SYNC_REG_WRITE         0x84    // Control Table 다중 쓰기 예약

//------------------------------------------------------------------------------
//                  ===== User Define =====
//------------------------------------------------------------------------------
#define CLEAR_BUFFER RxBufferReadPointer = RxBufferWritePointer
#define DEFAULT_RETURN_PACKET_SIZE  6
#define BROADCASTING_ID             0xFE
#define DEFAULT_BAUD_RATE   1                           //1000000bps at 16MHz


//-------------------------------------------------------------------------------------------------------------------------------
//Instruction packet lengths 

#define READ_ONE_BYTE_LENGTH            0x01
#define READ_TWO_BYTE_LENGTH            0x02
#define RESET_LENGTH                    0x02
#define PING_LENGTH                     0x02
#define ACTION_LENGTH                   0x02
#define SET_ID_LENGTH                   0x04
#define SET_BD_LENGTH                   0x04
#define SET_RETURN_LEVEL_LENGTH         0x04
#define READ_TEMP_LENGTH                0x04
#define READ_POS_LENGTH                 0x04
#define READ_LOAD_LENGTH                0x04
#define READ_SPEED_LENGTH               0x04
#define READ_VOLT_LENGTH                0x04
#define READ_REGISTER_LENGTH            0x04
#define READ_MOVING_LENGTH              0x04
#define READ_LOCK_LENGTH                0x04
#define LED_LENGTH                      0x04
#define SET_HOLDING_TORQUE_LENGTH       0x04
#define SET_MAX_TORQUE_LENGTH           0x05
#define SET_ALARM_LENGTH                0x04
#define READ_LOAD_LENGTH                0x04
#define SET_RETURN_LENGTH               0x04
#define WHEEL_LENGTH                    0x05
#define SERVO_GOAL_LENGTH               0x07
#define SET_MODE_LENGTH                 0x07
#define SET_PUNCH_LENGTH                0x04
#define SET_PID_LENGTH                  0x06
#define SET_TEMP_LENGTH                 0x04
#define SET_VOLT_LENGTH                 0x05
#define SYNC_LOAD_LENGTH                0x0D
#define SYNC_DATA_LENGTH                0x02        


//-------------------------------------------------------------------------------------------------------------------------------
// Specials 
//-------------------------------------------------------------------------------------------------------------------------------

#define SERVO                           0x01
#define WHEEL                           0x00

#define NONE                            0x00
#define READ                            0x01
#define ALL                             0x02

#define BROADCAST_ID                    0xFE

#define HEADER                          0xFF

#define STATUS_PACKET_TIMEOUT           50      // in millis()
#define STATUS_FRAME_BUFFER             5
//------------------------------------------------------------------------------
//         			===== Funtion Prototype =====
//------------------------------------------------------------------------------
uint8_t Get_DXL_Data(uint8_t DXL_ID, uint8_t DX_Addr);
uint16_t Get_DXL_Data2(uint8_t DXL_ID, uint8_t DX_Addr);
void Set_Upper_Torque(uint8_t Torque);
void Save_DXL(uint8_t Instruction, uint8_t Parameter_Num, uint16_t Data1,uint16_t Data2);
uint8_t TxPacket(uint8_t ID, uint8_t Instruction, uint8_t ParameterLength);
uint8_t RxPacket(uint8_t RxPacketLength);



#endif