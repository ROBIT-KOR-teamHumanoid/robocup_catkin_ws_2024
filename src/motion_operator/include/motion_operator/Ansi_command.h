/*==============================================================================
 *
 *  Ansi command Module
 *
 *      File Name       : Ansi_command.c
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
#ifndef __ANSI_COMMAND_H
#define __ANSI_COMMAND_H

void Init_Command(void);
void Command_Process(void);
void Command_Execute(void);
unsigned char Command_Input(void);
void Read_Flash();
void Boot_Jump();
void Mode_Set();
char* Command_Get_String(unsigned char Argnum);
unsigned char Command_Get_ParameterNum(void);
char* Command_16Bit_Parameter_H(unsigned char Argnum);
char* Command_16Bit_Parameter_L(unsigned char Argnum);
long Command_Get_Dec(unsigned char Argnum);
long Command_Get_Hex(unsigned char Argnum);
long Command_Get_Hex_H(unsigned char Argnum);
long Command_Get_Hex_L(unsigned char Argnum);
long strtollll(const char *_Restrict _S, char **_Restrict _Endptr,int _Base);

#endif