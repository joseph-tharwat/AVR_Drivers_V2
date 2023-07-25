/*
 * RTC_INT.h
 *
 *  Created on: Mar 11, 2023
 *      Author: joseph
 */

#ifndef RTC_RTC_INT_H_
#define RTC_RTC_INT_H_

#include "RTC_TYPES.h"

void H_RTC_Init();

void H_RTC_SetTime(RTC_Time_Struct TimeStruct);

RTC_Time_Struct H_RTC_GetTime();

void H_RTC_SetDate(RTC_Date_Struct DateStruct);

RTC_Date_Struct H_RTC_GetDate();

//void H_RTC_DisplayTime(RTC_Time_Struct* TimeStruct);
void H_RTC_DisplayTime(RTC_Time_Struct TimeStruct);
void H_RTC_DisplayDate(RTC_Date_Struct* DateStruct);

#endif /* RTC_RTC_INT_H_ */
