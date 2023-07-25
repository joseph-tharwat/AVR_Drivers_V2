/*
 * TIMER1_INT.h
 *
 *  Created on: Feb 25, 2023
 *      Author: joseph
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_

#include "TIMER1_TYPES.h"
#include  "TIMER1_PRIV.h"

TIMER1_Error_Status M_TIMER1_Int(Timer1_Mode Timer1Mode, Timer_OC1_Mode OC1Mode, Timer1_ICU_Edge_Mode ICUEdgeMode);

void M_TIMER1_Start(Timer1_Frequency_PreScaler PreScaler);

void M_TIMER1_Stop();

u16 M_TIMER1_GetCountsICU();

u32 M_TIMER1_GetOverflowCounterICU();

TIMER1_Error_Status M_TIMER1_ICU_void_setTrigger(Timer1_ICU_Edge_Mode ICUEdgeMode);

TIMER1_Error_Status M_TIMER1_EnableInterrupt(Timer1_INTERRUPT_ID InterruptMode);

TIMER1_Error_Status M_TIMER1_DisableInterrupt(Timer1_INTERRUPT_ID InterruptMode);

TIMER1_Error_Status M_TIMER1_SetCallBackFunction(void (*ptrFunction)(), Timer1_INTERRUPT_ID InterruptMode);


#endif /* TIMER1_TIMER1_INT_H_ */
