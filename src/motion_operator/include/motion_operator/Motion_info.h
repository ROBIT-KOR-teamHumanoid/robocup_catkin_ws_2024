/*==============================================================================
 *
 *   Dynamixel Motion Information Module
 *
 *      File Name       : Motion_info.c
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
#ifndef __MOTION_INFO_H
#define __MOTION_INFO_H

void Get_DXL_Position(void);    // 지정된 ID의 모터의 Current Step에서의 위치 값을 얻는다
void Get_DXL_Load(void);        // 모터에 걸리는 하중에 대한 정보를 얻는다.
void Get_DXL_Voltage(void);     // 모터에 걸리는 전압에 대한 정보를 얻는다.
void Get_DXL_Temperature(void); // 모터의 온도에 대한 정보를 얻는다.
void Get_Step_Position(void);   // 지정된 스텝의 POSITION을 얻는다
void Get_Factory_Position(void);// 공장 POSITION 값을 얻는다.
void Get_Step_Info(void);       // 지정된 스텝의 INFO를 얻는다.
void Get_Motion_Info(void);     // Motion Table의  모션 INFO를 얻는다.

void Put_Step_Position(void);   // 지정된 스텝에 POSITION 값을 넣는다.
void Put_Step_Speed(void);      // 지정된 스텝에 SPEED 값을 넣는다.
void Put_Step_Info(void);       // 지정된 스텝에 스텝 INFO 값을 넣는다.
void Put_Motion_Info(void);     // Motion Table에 모션 INFO를 넣는다.

#endif