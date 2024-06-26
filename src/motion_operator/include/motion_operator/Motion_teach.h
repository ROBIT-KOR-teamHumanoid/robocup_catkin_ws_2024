/*==============================================================================
 *
 *   Dynamixel Motion Teach Module
 *
 *      File Name       : Motion_teach.c
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
#ifndef __MOTION_TEACH_H
#define __MOTION_TEACH_H

#define MAX_PARAMETER_NUM       255         // Maximum parameter number
#define MAX_STEP_NUM            15          // Maximum Present DX Motor number

//----------------------23EA 모터 지원용 수정 후 -----------------------------//

#define MAX_DXL_NUM         22          // Maximum Present DX Motor number
                                // ID=0x00~0x16, 23EA 모터중 가장 큰 ID

//----------------------23EA 모터 지원용 수정 후 -----------------------------//

#define STEP_SPEED      0
#define STEP_DELAY      1

#define LEFT            0
#define RIGHT           1

#define JOIN            1
#define BLANK           2

#define FACTORY         1
#define INITIAL         2

#define ALL_DXL         0xFE

#define ARM_LEFT        9
#define ARM             8
#define ARM_RIGHT       7
#define PELVIS_LEFT     6
#define PELVIS_PITCH    5
#define PELVIS_RIGHT    4
#define LEG_LEFT        3
#define LEG             2
#define LEG_RIGHT       1

#define MODE_7          7
#define MODE_6          6
#define MODE_5          5
#define MODE_4          4
#define MODE_3          3
#define MODE_2          2
#define E_MODE          1
#define P_MODE          0
//------------------------------------------------------------------------------
//                  ===== Struct Declaration =====
//------------------------------------------------------------------------------
typedef struct _DXL_INST_PACKET
{
    uint8_t ID;                     // Dynamixel ID
    uint8_t Length;                     // Packet length = parameter's number + 1(ID) + 1(Instruction) + 1(address)
    uint8_t Instruction;                    // Instruction code
    uint8_t Address;                    // Start Address
    uint8_t Parameter[MAX_PARAMETER_NUM];                   // Parameters
} DXL_INST_PACKET;

typedef struct _DXL_STATUS_PACKET
{
    uint8_t ID;                         // Dynamixel ID
    uint8_t Length;                         // Packet length = parameter's number + 1(ID) + 1(error)
    uint8_t Error;                          // Error code
    uint8_t Parameter[MAX_PARAMETER_NUM];   // Parameters                               
} DXL_STATUS_PACKET;


/*----------------------23EA 모터 지원용 수정 전 -----------------------------//
// DXL      RX[22]                  // 모터 22개
// MOTION   Motion                  // 모션  1개 (스텝,스텝정보,모션정보 포함)
//----------------------23EA 모터 지원용 수정 전 -----------------------------*/

//----------------------23EA 모터 지원용 수정 후 -----------------------------//
// DXL      RX[22]                  // 모터 23개
// MOTION   Motion                  // 모션  1개 (스텝,스텝정보,모션정보 포함)
//----------------------23EA 모터 지원용 수정 후 -----------------------------//

typedef union _DATA
{
    uint16_t Word;
    struct _Byte
    {
        uint8_t L;
        uint8_t H;
    } Byte;
} DATA;             // 16bit
// DATA Tilt_X;
// Tilt_X.Word = Tilt_X.Byte.L + Tilt_X.Byte.H

typedef union _DXLP
{
    uint16_t Position;
    struct _POSITON
    {
        uint8_t L;
        uint8_t H;
    } PositionByte;
} DXLP;                 // 16bit

/*----------------------23EA 모터 지원용 수정 전 -----------------------------//
// DXL RX[22];
// RX[1].Position =  RX[1].PositionByte.H  +  RX[1].PositionByte.L
//----------------------23EA 모터 지원용 수정 전 -----------------------------*/


//----------------------23EA 모터 지원용 수정 후 -----------------------------//
// DXL RX[23];
// RX[1].Position =  RX[1].PositionByte.H  +  RX[1].PositionByte.L
//----------------------23EA 모터 지원용 수정 후 -----------------------------//

typedef union _DXLS
{
    uint16_t Speed;
    struct _SPEED
    {
        uint8_t L;
        uint8_t H;
    } SpeedByte;
} DXLS;                 // 16bit

typedef struct _STEP
{
    DXLP RXP[MAX_DXL_NUM+1];
    uint8_t  Speed;
    uint8_t  Delay;
}STEP;                  // 16*22 + 8*2 = 368 bit = 46 byte
                                        //수정 후 16*23 + 8*2 = 384bit = 48byte

typedef struct _MOTION
{
    uint8_t Play_Step;              // Motion_Step;
    uint8_t Play_Count;                 // Motion_Count;
    uint8_t Play_Speed;                 // Motion_Speed;
    uint8_t Accel_Time;
    uint8_t Delay_Time;
    uint8_t Mode;
    uint8_t Format;
    uint8_t Start_Step;
    uint8_t End_Step;

    STEP Step[16];
} MOTION;               // 8*11 + 8*10 + 368*16 = 6056 bit = 757 byte

typedef struct _STEPSPEED
{
    DXLS RXS[MAX_DXL_NUM+1];
}STEPSPEED;

// 수정 후 8*11 + 8*10 + 384*16 = 6312 bit = 789 byte
// MOTION Motion
// Motion.Step[0].RX[0].Position = Motion.Step[1].RX[0].Position

//------------------------------------------------------------------------------
//                  ===== Funtion Prototype =====
//------------------------------------------------------------------------------
uint8_t Check_ID(uint8_t *MotorMAXNumber, uint8_t *MotorNumber);
void Init_Teach(void);
void Save_Step(void);
void Load_Step(uint8_t Place);
void On_Torque(void);
void Off_Torque();
void Set_Single_Position(void);
void Set_Multi_Position(void);
void Set_Step_Speed(void);
void Set_Step_Delay(void);
void Write_Step(void);
void Insert_Step(void);
void Go_Step(void);
void Copy_Step(void);
void Delete_Step(uint8_t Option);
void New_Motion(void);
void Teach_Play_Motion(void);




#endif