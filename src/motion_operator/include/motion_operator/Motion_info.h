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

void Get_DXL_Position(void);    // ������ ID�� ������ Current Step������ ��ġ ���� ��´�
void Get_DXL_Load(void);        // ���Ϳ� �ɸ��� ���߿� ���� ������ ��´�.
void Get_DXL_Voltage(void);     // ���Ϳ� �ɸ��� ���п� ���� ������ ��´�.
void Get_DXL_Temperature(void); // ������ �µ��� ���� ������ ��´�.
void Get_Step_Position(void);   // ������ ������ POSITION�� ��´�
void Get_Factory_Position(void);// ���� POSITION ���� ��´�.
void Get_Step_Info(void);       // ������ ������ INFO�� ��´�.
void Get_Motion_Info(void);     // Motion Table��  ��� INFO�� ��´�.

void Put_Step_Position(void);   // ������ ���ܿ� POSITION ���� �ִ´�.
void Put_Step_Speed(void);      // ������ ���ܿ� SPEED ���� �ִ´�.
void Put_Step_Info(void);       // ������ ���ܿ� ���� INFO ���� �ִ´�.
void Put_Motion_Info(void);     // Motion Table�� ��� INFO�� �ִ´�.

#endif