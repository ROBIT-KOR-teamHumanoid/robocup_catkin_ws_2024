/*==============================================================================
 *
 *      ANSI/VT100 Terminal Module
 *
 *      File Name       : Ansi.c
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
#ifndef __ANSI_H
#define __ANSI_H

//-----------------------------------------------------------------------------
//                  ===== Define : Attribute Mode =====
//------------------------------------------------------------------------------
#define ANSI_ATTR_OFF       0

#define ANSI_BOLD           1
#define ANSI_USCORE         4
#define ANSI_BLINK          5
#define ANSI_REVERSE        7

#define ANSI_BOLD_OFF       21
#define ANSI_USCORE_OFF     24
#define ANSI_BLINK_OFF      25
#define ANSI_REVERSE_OFF    27
/*
//------------------------------------------------------------------------------
//                  ===== Define : Colors =====
//------------------------------------------------------------------------------
#define ANSI_BLACK          0
#define ANSI_RED            1
#define ANSI_GREEN          2
#define ANSI_BROWN          3
#define ANSI_BLUE           4
#define ANSI_MAGENTA        5
#define ANSI_CYAN           6
#define ANSI_WHITE          7

//------------------------------------------------------------------------------
//                  ===== Define : Foreground Colors =====
//------------------------------------------------------------------------------
#define FG_BLACK            30
#define FG_RED              31
#define FG_GREEN            32
#define FG_BROWN            33
#define FG_BLUE             34
#define FG_MAGENTA          35
#define FG_CYAN             36
#define FG_WHITE            37

//------------------------------------------------------------------------------
//                  ===== Define : Background Colors =====
//------------------------------------------------------------------------------
#define BG_BLACK            40
#define BG_RED              41
#define BG_GREEN            42
#define BG_BROWN            43
#define BG_BLUE             44
#define BG_MAGENTA          45
#define BG_CYAN             46
#define BG_WHITE            47
*/
//------------------------------------------------------------------------------
//                  ===== Define : Key Move =====
//------------------------------------------------------------------------------
#define KEY_UP              (0xFF)
#define KEY_DOWN            (0xFE)
#define KEY_LEFT            (0xFD)
#define KEY_RIGHT           (0xFC)
#define KEY_BS              (0xFB)
#define KEY_RET             (0xFA)
#define KEY_TAB             (0xF9)

//------------------------------------------------------------------------------
//                  ===== Define : Key Point =====
//------------------------------------------------------------------------------
#define FROM            0
#define UNTIL           1

//------------------------------------------------------------------------------
//                  ===== Funtion Prototype =====
//------------------------------------------------------------------------------
void ANSI_Send(uint8_t data);
void ANSI_Send_Num(uint8_t data);
uint8_t ANSI_Getch(void);
void ANSI_Normal(void);
void ANSI_Underline(uint8_t On_Off);
void ANSI_Blink(uint8_t On_Off);
void ANSI_Reverse(uint8_t On_Off);
void ANSI_Bold(uint8_t On_Off);
void ANSI_SetColor(uint8_t foreground, uint8_t background);
void ANSI_ClearScreen(uint8_t where);
void ANSI_ClearLine(uint8_t where);
void ANSI_GotoXY(uint8_t x, uint8_t y);
void ANSI_Cursor_Up(uint8_t amount);
void ANSI_Cursor_Down(uint8_t amount);
void ANSI_Cursor_Left(uint8_t amount);
void ANSI_Cursor_Right(uint8_t amount);
void ANSI_Scroll_Region(uint8_t top, uint8_t bottom);
void ANSI_Line(uint8_t y);




#endif
