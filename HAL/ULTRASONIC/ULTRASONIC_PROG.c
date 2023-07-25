/*
 * ULTRASONIC_PROG.c
 *
 *  Created on: Feb 26, 2023
 *      Author: joseph
 */

#include "DIO_INT.h"

#include "TIMER1_INT.h"

#include "ULTRASONIC_CFG.h"
#include "ULTRASONIC_TYPES.h"
#include "ULTRASONIC_PRIV.h"
#include "ULTRASONIC_INT.h"

#include <avr/delay.h>

#include "LCD_INT.h"

volatile u32 R1 = 0;
volatile u32 R2 = 0;
volatile u8 Flag = 0;
volatile u32 ULTRASONICOverflow = 0;

void H_ULTRASONIC_ISR()
{
	if(Flag == 0)
	{
		R1 = M_TIMER1_GetCountsICU();
		Flag++;
	}
	else if(Flag == 1)
	{
		R2 = M_TIMER1_GetCountsICU();
		ULTRASONICOverflow = M_TIMER1_GetOverflowCounterICU();
		Flag++;
	}
}

static u32 H_ULTRASONIC_CalculatDistance()
{
	f32 Loc_Result = 0;
	if(ULTRASONICOverflow == 0)
	{
		Loc_Result = R2 - R1;
	}
	else
	{
		ULTRASONICOverflow--;
		Loc_Result = (TIMER1_MAX_VALUE - R1) + (ULTRASONICOverflow * TIMER1_MAX_VALUE) + R2;
	}

	Loc_Result = Loc_Result * ((f32)TIMER1_CLK_DIV_1024/F_CPU);//calculate the total time
	Loc_Result = Loc_Result/2;//calculate the time in one way
	Loc_Result = Loc_Result* SOUND_SPEED;//Distance in meters
	Loc_Result = Loc_Result * 100;//to convert to cm

	Flag = 0;
	R1 = 0;
	R2 = 0;
	return Loc_Result;
}

void H_ULTRASONIC_Init()
{
	/*Initialize TIMER1 to ICU mode*/
	M_TIMER1_Int(TIMER1_NORMAL_MODE, OC1_DISCONNECTED, ICU_RISING_FALLING_RF_MODE);
	M_TIMER1_SetCallBackFunction(H_ULTRASONIC_ISR, TIMER1_INTERRUPT_INPUT_CAPTURE);
	M_TIMER1_EnableInterrupt(TIMER1_INTERRUPT_INPUT_CAPTURE);
	M_TIMER1_Start(TIMER1_CLK_DIV_1024);
}

u32 H_ULTRASONIC_Trigger()
{
	/*Puls to ultrasonic*/
	M_DIO_void_SetPinValue(ULTRASONIC_TRIGGER_PIN,DIO_High);
	_delay_us(12);	// ultrasonic need 10 us
	M_DIO_void_SetPinValue(ULTRASONIC_TRIGGER_PIN,DIO_LOW);

	while(Flag != 2)
	{
		//do nothing
	}

	return H_ULTRASONIC_CalculatDistance();
}

