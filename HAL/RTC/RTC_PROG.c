/*
 * RTC_PROG.c
 *
 *  Created on: Mar 11, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_INT.h"

#include "RTC_CFG.h"
#include "RTC_TYPES.h"
#include "RTC_PRIV.h"
#include "RTC_INT.h"

void H_RTC_Init()
{
	M_I2C_Init(I2C_DIV_1, 10000);
}

static void H_RTC_HandleTimeStruct(RTC_Time_Struct* TimeStruct)
{
	//CH = 0
	TimeStruct->Seconds = TimeStruct->Seconds & 0b01111111;

	TimeStruct->Seconds = ((TimeStruct->Seconds/10)<<4) | (TimeStruct->Seconds%10);
	TimeStruct->Minutes = ((TimeStruct->Minutes/10)<<4) | (TimeStruct->Minutes%10);

	u8 TempHours = TimeStruct->Hours;

	TimeStruct->Hours = TimeStruct->Hours%10;

	//12 Mode
	//if(((TimeStruct->Hours & 0b01000000)>>6) == 1)
	if(TimeStruct->Mode12_24 == RTC_12_MODE)
	{
		//PM
		if(TimeStruct->AM_PM = RTC_PM)
		{
			SET_BIT(TimeStruct->Hours, 5);
		}
		//AM
		else
		{
			CLEAR_BIT(TimeStruct->Hours, 5);
		}

		if(TimeStruct->Hours >= 10)
		{
			SET_BIT(TimeStruct->Hours, 4);
		}
		else
		{
			CLEAR_BIT(TimeStruct->Hours, 4);
		}
	}
	//24 Mode
	else
	{
		if(TempHours >= 10 && TempHours <= 19)
		{
			SET_BIT(TimeStruct->Hours, 4);
			CLEAR_BIT(TimeStruct->Hours, 5);
		}
		else if(TempHours >= 20)
		{
			SET_BIT(TimeStruct->Hours, 4);
			SET_BIT(TimeStruct->Hours, 5);
		}
	}
}

void H_RTC_SetTime(RTC_Time_Struct TimeStruct)
{
	H_RTC_HandleTimeStruct(&TimeStruct);

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_WRITE);
	M_I2C_SendByte(RTC_SECONDS_ADDRESS);
	M_I2C_SendByte(TimeStruct.Seconds);
	M_I2C_SendByte(TimeStruct.Minutes);
	M_I2C_SendByte(TimeStruct.Hours);
	M_I2C_SendStop();
}
static void H_RTC_ExtractTime(RTC_Time_Struct* TimeStruct)
{
	TimeStruct->Seconds = ((TimeStruct->Seconds & 0b1110000)>>4)*10 + (TimeStruct->Seconds & 0b1111);
	TimeStruct->Minutes = ((TimeStruct->Minutes & 0b1110000)>>4)*10 + (TimeStruct->Minutes & 0b1111);

	//12 Mode
	if((GET_BIT(TimeStruct->Hours, 6)) == 1)
	{
		TimeStruct->Mode12_24 = RTC_12_MODE;
		//PM
		if((GET_BIT(TimeStruct->Hours, 5)) == 1)
		{
			TimeStruct->AM_PM = RTC_PM;
		}
		//AM
		else
		{
			TimeStruct->AM_PM = RTC_AM;
		}
		TimeStruct->Hours = ((TimeStruct->Hours & 0b10000)>>4)*10 + (TimeStruct->Hours & 0b1111);
	}
	//24 Mode
	else
	{
		TimeStruct->Mode12_24 = RTC_24_MODE;
		TimeStruct->Hours = ((TimeStruct->Hours & 0b110000)>>4)*10 + (TimeStruct->Hours & 0b1111);
	}

}

RTC_Time_Struct H_RTC_GetTime()
{
	RTC_Time_Struct TimeStruct;

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_WRITE);
	M_I2C_SendByte(RTC_SECONDS_ADDRESS);

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_READ);
	u8 Byte = '\0';
	M_I2C_ReceiveByte_ACK(&Byte);
	TimeStruct.Seconds = Byte;
	M_I2C_ReceiveByte_ACK(&Byte);
	TimeStruct.Minutes = Byte;
	M_I2C_ReceiveByte_NoACK(&Byte);
	TimeStruct.Hours = Byte;

	H_RTC_ExtractTime(&TimeStruct);

	return TimeStruct;
}


static void H_RTC_HandleDateStruct(RTC_Date_Struct* DateStruct)
{
	DateStruct->DayDate = ((DateStruct->DayDate/10)<<4) | (DateStruct->DayDate%10);
	DateStruct->Month = ((DateStruct->Month/10)<<4) | (DateStruct->Month%10);
	DateStruct->Year = /*((DateStruct->Year/100)<<4) |*/ ((DateStruct->Year%100)/10)<<4 | ((DateStruct->Year%100)%10);


}

void H_RTC_SetDate(RTC_Date_Struct DateStruct)
{
	H_RTC_HandleDateStruct(&DateStruct);

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_WRITE);
	M_I2C_SendByte(RTC_DAY_ADDRESS);
	M_I2C_SendByte(DateStruct.Day);
	M_I2C_SendByte(DateStruct.DayDate);
	M_I2C_SendByte(DateStruct.Month);
	M_I2C_SendByte(DateStruct.Year);
	M_I2C_SendStop();
}

static void H_RTC_ExtractDate(RTC_Date_Struct* DateStruct)
{
	DateStruct->Day = (DateStruct->Day & 0b111);
	DateStruct->DayDate = ((DateStruct->DayDate & 0b110000)>>4)*10 + (DateStruct->DayDate & 0b1111);
	DateStruct->Month = ((DateStruct->Month & 0b10000)>>4)*10 + (DateStruct->Month & 0b1111);
	DateStruct->Year = ((DateStruct->Year & 0b11110000)>>4)*10 + (DateStruct->Year & 0b1111);
}

RTC_Date_Struct H_RTC_GetDate()
{
	RTC_Date_Struct DateStruct;

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_WRITE);
	M_I2C_SendByte(RTC_DAY_ADDRESS);

	M_I2C_SendStart();
	M_I2C_SendAddress(RTC_ADDRESS, I2C_READ);
	u8 Byte ='\0';
	M_I2C_ReceiveByte_ACK(&Byte);
	DateStruct.Day = Byte;
	M_I2C_ReceiveByte_ACK(&Byte);
	DateStruct.DayDate = Byte;
	M_I2C_ReceiveByte_ACK(&Byte);
	DateStruct.Month = Byte;
	M_I2C_ReceiveByte_NoACK(&Byte);
	DateStruct.Year = Byte;
	M_I2C_SendStop();

	H_RTC_ExtractDate(&DateStruct);

	return DateStruct;
}


void H_RTC_DisplayTime(/*RTC_Time_Struct* const TimeStruct*/ RTC_Time_Struct T)
{
	H_LCD_void_SendNumber(T.Hours);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(T.Minutes);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(T.Seconds);
	H_LCD_void_SendChar(' ');
	if(T.AM_PM == RTC_AM)
		H_LCD_void_SendString(" AM");
	else if(T.AM_PM == RTC_PM)
		H_LCD_void_SendString(" PM");
/*
	H_LCD_void_SendNumber(TimeStruct->Hours);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(TimeStruct->Minutes);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(TimeStruct->Seconds);
	H_LCD_void_SendChar(' ');
	if(TimeStruct->AM_PM == RTC_AM)
		H_LCD_void_SendString(" AM");
	else if(TimeStruct->AM_PM == RTC_PM)
		H_LCD_void_SendString(" PM");*/
}

void H_RTC_DisplayDate(RTC_Date_Struct* const DateStruct)
{
	switch(DateStruct->Day)
	{
	case RTC_SUNDAY:
		H_LCD_void_SendString("SUN ");
	break;
	case RTC_MONDAY:
		H_LCD_void_SendString("MON ");
	break;
	case RTC_TUESDAY:
		H_LCD_void_SendString("TUES ");
	break;
	case RTC_WEDNESDAY:
		H_LCD_void_SendString("WEDNES ");
	break;
	case RTC_THURSDAY:
		H_LCD_void_SendString("THURS ");
	break;
	case RTC_FRIDAY:
		H_LCD_void_SendString("FRI ");
	break;
	case RTC_SATURDAY:
		H_LCD_void_SendString("SAT ");
	break;
	}
	H_LCD_void_SendNumber(DateStruct->DayDate);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(DateStruct->Month);
	H_LCD_void_SendChar(' ');
	H_LCD_void_SendNumber(DateStruct->Year);
	H_LCD_void_SendChar(' ');
}
