/*==============================================================================
 *
 *   Dynamixel Motion Play Module
 *
 *      File Name       : Motion_play.c
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
#ifndef __MOTION_PLAY_H
#define __MOTION_PLAY_H


#define TEACH_MODE 0
#define PLAY_MODE  1

//------------------------------------------------------------------------------
//                  ===== Funtion Prototype =====
//------------------------------------------------------------------------------
uint16_t AccTime_Calc(uint8_t AccStep_Number);
DATA Speed_Calc(uint8_t Step_Number, uint8_t DXL_ID, uint8_t *DXL_half_flag, uint8_t *DXL_Acclink, uint16_t *Acting_Time_Acc);
void Play_Motion(void);
void Power_Robot(uint8_t ONOFF);

void On_Timer0(void);
void Off_Timer0(void);

#endif