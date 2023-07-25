/*
 * TIMER0_INT.h
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "TIMER0_TYPES.h"

TIMER0_Error_Status M_TIMER0_Int(Timer0_Mode Timer0Mode, Timer_OC0_Mode OC0Mode);

void M_TIMER0_Start(Timer0_Frequency_PreScaler PreScaler);

void M_TIMER0_Stop();

u8 M_TIMER0_GetCounts();

void M_TIMER0_SetTimerPreload(u8 Value);

void M_TIMER0_SetOutputCompare(u8 Value);

TIMER0_Delay_Status M_Timer0_SetDelayTimeMilliSec(u16 TimeMilliSec, void (*ptrDelayFunction)());

TIMER0_Error_Status M_TIMER0_EnableInterrupt(Timer0_INTERRUPT_ID InterruptMode);

TIMER0_Error_Status M_TIMER0_DisableInterrupt(Timer0_INTERRUPT_ID InterruptMode);

TIMER0_Error_Status M_TIMER0_SetCallBackFunction(void (*ptrFunction)(), Timer0_INTERRUPT_ID InterruptMode);

TIMER0_Error_Status TIMER0_SetFastPWM(f32 PwmFrequency, u8 DutyPrcent);

TIMER0_Error_Status TIMER0_SetphaseCorrectPWM(u8 PwmFrequency, u8 DutyPrcent);



#endif /* TIMER0_TIMER0_INT_H_ */
