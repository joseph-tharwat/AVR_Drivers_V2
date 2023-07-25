/*
 * TIMER1_PROG.c
 *
 *  Created on: Feb 25, 2023
 *      Author: joseph
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "TIMER1_CFG.h"
#include "TIMER1_PRIV.h"
#include "TIMER1_TYPES.h"
#include "TIMER1_INT.h"

#include <avr/interrupt.h>

static Timer1_ICU_Edge_Mode global_TIMER1_ICU_MODE = ICU_NO_USE;
static Timer1_ICU_Edge_Mode global_TIMER1_ICU_PREVIOUS_MODE = ICU_NO_USE;
static u16 global_TIMER1_OverflowCounterICU = 0;

TIMER1_Error_Status M_TIMER1_Int(Timer1_Mode Timer1Mode, Timer_OC1_Mode OC1Mode, Timer1_ICU_Edge_Mode ICUEdgeMode)
{
	switch(Timer1Mode)
	{
	case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A, TCCR1A_WGM10_BIT);
		CLEAR_BIT(TCCR1A, TCCR1A_WGM11_BIT);

		CLEAR_BIT(TCCR1B, TCCR1B_WGM12_BIT);
		CLEAR_BIT(TCCR1B, TCCR1B_WGM13_BIT);

		if(ICUEdgeMode == ICU_FALLING_EDGE_MODE)
		{
			M_TIMER1_ICU_void_setTrigger(ICU_FALLING_EDGE_MODE);
		}
		else if(ICUEdgeMode == ICU_RISING_EDGE_MODE)
		{
			M_TIMER1_ICU_void_setTrigger(ICU_RISING_EDGE_MODE);
		}
		else if(ICUEdgeMode == ICU_RISING_FALLING_RF_MODE)
		{
			M_TIMER1_ICU_void_setTrigger(ICU_RISING_EDGE_MODE);
			global_TIMER1_ICU_PREVIOUS_MODE = ICU_RISING_EDGE_MODE;
		}
		else if(ICUEdgeMode == ICU_RISING_FALLING_FF_MODE)
		{
			M_TIMER1_ICU_void_setTrigger(ICU_FALLING_EDGE_MODE);
			global_TIMER1_ICU_PREVIOUS_MODE = ICU_FALLING_EDGE_MODE;
		}
		global_TIMER1_ICU_MODE = ICUEdgeMode;

	break;
	default:
		return TIMER1_MODE_ERROR;
	break;
	}

	switch(OC1Mode)
	{
	case OC1_DISCONNECTED:
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0_BIT);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1_BIT);
	break;
	default:
		return TIMER1_OC1_MODE_ERROR;
	break;
	}
	return TIMER1_NO_ERROR;
}

void M_TIMER1_Start(Timer1_Frequency_PreScaler PreScalerClk)
{
	if(PreScalerClk == TIMER1_STOPPED)
	{
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_CLK)
	{
		SET_BIT(TCCR1B,TCCR1B_CS10_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_CLK_DIV_8)
	{
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS11_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);

	}
	else if(PreScalerClk == TIMER1_CLK_DIV_64)
	{
		SET_BIT(TCCR1B,TCCR1B_CS10_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS11_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_CLK_DIV_256)
	{
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_CLK_DIV_1024)
	{
		SET_BIT(TCCR1B,TCCR1B_CS10_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS11_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_EXTERNAL_FALLING_EDGE)
	{
		CLEAR_BIT(TCCR1B,TCCR1B_CS10_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS11_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
	else if(PreScalerClk == TIMER1_EXTERNAL_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_CS10_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS11_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}
}

void M_TIMER1_Stop()
{
	CLEAR_BIT(TCCR1B,TCCR1B_CS10_BIT);
	CLEAR_BIT(TCCR1B,TCCR1B_CS11_BIT);
	CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);
}

u16 M_TIMER1_GetCountsICU()
{
	return (ICR1H<<8 | ICR1L);
}

u32 M_TIMER1_GetOverflowCounterICU()
{
	return global_TIMER1_OverflowCounterICU;
}

#include "LCD_INT.h"
TIMER1_Error_Status M_TIMER1_EnableInterrupt(Timer1_INTERRUPT_ID InterruptMode)
{
	if(InterruptMode == TIMER1_INTERRUPT_INPUT_CAPTURE)
	{
		TIMSK = TIMSK | TIMER1_INTERRUPT_INPUT_CAPTURE;
		TIMSK = TIMSK | TIMER1_INTERRUPT_OVERFLOW;	//need the overflow interrupt while using ICU
		return TIMER1_NO_ERROR;
	}
	else if(InterruptMode == TIMER1_INTERRUPT_OVERFLOW ||
			InterruptMode == TIMER1_INTERRUPT_COMPARE_MATCH_B ||
			InterruptMode == TIMER1_INTERRUPT_COMPARE_MATCH_A )
	{
		TIMSK = TIMSK | InterruptMode;
		return TIMER1_NO_ERROR;
	}
	else
	{
		return TIMER1_INTERRUPT_MODE_ERROR;
	}

}

TIMER1_Error_Status M_TIMER1_DisableInterrupt(Timer1_INTERRUPT_ID InterruptMode)
{
	if(InterruptMode == TIMER1_INTERRUPT_OVERFLOW ||
				InterruptMode == TIMER1_INTERRUPT_COMPARE_MATCH_B ||
				InterruptMode == TIMER1_INTERRUPT_COMPARE_MATCH_A ||
				InterruptMode == TIMER1_INTERRUPT_INPUT_CAPTURE)
	{
		TIMSK = TIMSK & (~InterruptMode);
		return TIMER1_NO_ERROR;
	}
	else
	{
		return TIMER1_INTERRUPT_MODE_ERROR;
	}
}

void (*TIMER1_ptrFunctionInterruptArray[4])();

TIMER1_Error_Status M_TIMER1_SetCallBackFunction(void (*ptrFunction)(), Timer1_INTERRUPT_ID InterruptMode)
{
	switch(InterruptMode)
	{
	case TIMER1_INTERRUPT_OVERFLOW:
		TIMER1_ptrFunctionInterruptArray[0] = ptrFunction;
	break;
	case TIMER1_INTERRUPT_COMPARE_MATCH_A:
		TIMER1_ptrFunctionInterruptArray[1] = ptrFunction;
	break;
	case TIMER1_INTERRUPT_COMPARE_MATCH_B:
		TIMER1_ptrFunctionInterruptArray[2] = ptrFunction;
	break;
	case TIMER1_INTERRUPT_INPUT_CAPTURE:
		TIMER1_ptrFunctionInterruptArray[3] = ptrFunction;

	break;
	default:
		return TIMER1_INTERRUPT_MODE_ERROR;
	break;
	}
	return TIMER1_NO_ERROR;
}

TIMER1_Error_Status M_TIMER1_ICU_void_setTrigger(Timer1_ICU_Edge_Mode ICUEdgeMode)
{
	if(ICUEdgeMode == ICU_FALLING_EDGE_MODE)
	{
		CLEAR_BIT(TCCR1B, TCCR1B_ICES1_BIT);
	}
	else if(ICUEdgeMode == ICU_RISING_EDGE_MODE)
	{
		SET_BIT(TCCR1B, TCCR1B_ICES1_BIT);
	}
	else if(ICUEdgeMode == ICU_RISING_FALLING_FF_MODE)
	{
		CLEAR_BIT(TCCR1B, TCCR1B_ICES1_BIT);//falling
	}
	else if(ICUEdgeMode == ICU_RISING_FALLING_FF_MODE)
	{
		SET_BIT(TCCR1B, TCCR1B_ICES1_BIT);//rising
	}

	if(global_TIMER1_ICU_MODE == ICU_RISING_FALLING_FF_MODE || global_TIMER1_ICU_MODE == ICU_RISING_FALLING_RF_MODE)
	{
		//do nothing
	}
	else
	{
		global_TIMER1_ICU_MODE = ICUEdgeMode;
	}

	global_TIMER1_ICU_PREVIOUS_MODE = ICUEdgeMode;
}

ISR(TIMER1_OVF_vect)
{
	global_TIMER1_OverflowCounterICU++;
	TIMER1_ptrFunctionInterruptArray[0]();
}

ISR(TIMER1_COMPA_vect)
{
	TIMER1_ptrFunctionInterruptArray[1]();
}

ISR(TIMER1_COMPB_vect)
{
	TIMER1_ptrFunctionInterruptArray[2]();
}


ISR(TIMER1_CAPT_vect)
{
	if(global_TIMER1_ICU_MODE == ICU_RISING_FALLING_FF_MODE || global_TIMER1_ICU_MODE == ICU_RISING_FALLING_RF_MODE)
	{
		switch(global_TIMER1_ICU_PREVIOUS_MODE)
		{
		case ICU_FALLING_EDGE_MODE:
			M_TIMER1_ICU_void_setTrigger(ICU_RISING_EDGE_MODE);
		break;
		case ICU_RISING_EDGE_MODE:
			M_TIMER1_ICU_void_setTrigger(ICU_FALLING_EDGE_MODE);
		break;
		}
	}

	TIMER1_ptrFunctionInterruptArray[3]();

	global_TIMER1_OverflowCounterICU = 0;
}
