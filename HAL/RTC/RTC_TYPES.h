/*
 * RTC_TYPES.h
 *
 *  Created on: Mar 11, 2023
 *      Author: joseph
 */

#ifndef RTC_RTC_TYPES_H_
#define RTC_RTC_TYPES_H_

typedef enum
{
	RTC_12_MODE = 12,
	RTC_24_MODE = 24,
}RTC_Time_Mode;

typedef enum
{
	RTC_AM = 0,
	RTC_PM = 1,
}RTC_AM_PM;


typedef struct
{
	u8 Hours;
	u8 Minutes;
	u8 Seconds;
	RTC_AM_PM AM_PM;
	RTC_Time_Mode Mode12_24;
}RTC_Time_Struct;

typedef enum
{
	RTC_SUNDAY = 1,
	RTC_MONDAY,
	RTC_TUESDAY,
	RTC_WEDNESDAY,
	RTC_THURSDAY,
	RTC_FRIDAY,
	RTC_SATURDAY,
}RTC_Day;

typedef struct
{
	RTC_Day Day;
	u8 DayDate;
	u8 Month;
	u16 Year;
}RTC_Date_Struct;

#endif /* RTC_RTC_TYPES_H_ */
