/*
 * LCD_INT.h
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

#include "LCD_PRIV.h"

void H_LCD_void_Init();

void H_LCD_void_SendChar(u8 Data);

void H_LCD_void_SendCommand(u8 Command);

void H_LCD_void_SendString(u8* Str);

void H_LCD_void_SendIntNum(s32 IntNumber);

void H_LCD_void_SendNumber(s32 copy_s32num);

void H_LCD_void_GotoXY(u8 Row, u8 Column);

void H_LCD_void_CreatCustomChar(const u8* ArrPattern, u8 charCode);

void H_LCD_void_DisplayCustomChar(u8 CharCode);

#endif /* LCD_LCD_INT_H_ */
