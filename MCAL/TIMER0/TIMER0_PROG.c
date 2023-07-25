/*
 * TIMER0_PROG.c
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "TIMER0_CFG.h"
#include "TIMER0_TYPES.h"
#include "TIMER0_PRIV.h"
#include "TIMER0_INT.h"

#include <avr/interrupt.h>



TIMER0_Error_Status M_TIMER0_Int(Timer0_Mode Timer0Mode, Timer_OC0_Mode OC0Mode)
{
	if(Timer0Mode == TIMER0_NORMAL_MODE)
	{
		SET_BIT(TCCR0,TCCR0_FOC0_BIT);

		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(Timer0Mode == TIMER0_PWM_MODE)
	{
		CLEAR_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_BIT);
	}
	else if(Timer0Mode == TIMER0_CTC_MODE)
	{
		SET_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
	else if(Timer0Mode == TIMER0_FASTPWM_MODE)
	{
		CLEAR_BIT(TCCR0,TCCR0_FOC0_BIT);

		SET_BIT(TCCR0,TCCR0_WGM01_BIT);
		SET_BIT(TCCR0,TCCR0_WGM00_BIT);
	}
	else
	{
		return TIMER0_MODE_ERROR;
	}

	///////////////
	if(Timer0Mode == TIMER0_NORMAL_MODE || Timer0Mode == TIMER0_CTC_MODE)
	{
		if(OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_TOGGLE)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_CLEAR)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_SET)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else
		{
			return TIMER0_OC0_MODE_ERROR;
		}
	}
	else if(Timer0Mode == TIMER0_PWM_MODE)
	{
		if(OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_CLEAR_ON_COMPARE_COUNTING_UP_SET_ON_COMPARE_COUNTING_DOWN)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_SET_ON_COMPARE_COUNTING_UP_CLEAR_ON_COMPARE_COUNTING_DOWN)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else
		{
			return TIMER0_OC0_MODE_ERROR;
		}
	}
	else if(Timer0Mode == TIMER0_FASTPWM_MODE)
	{
		if(OC0Mode == OC0_DISCONNECTED)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			CLEAR_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_CLEAR_ON_COMPARE_SET_AT_TOP)
		{
			CLEAR_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else if(OC0Mode == OC0_SET_ON_COMPARE_CLEAR_AT_TOP)
		{
			SET_BIT(TCCR0,TCCR0_COM00_BIT);
			SET_BIT(TCCR0,TCCR0_COM01_BIT);
		}
		else
		{
			return TIMER0_OC0_MODE_ERROR;
		}
	}

	return TIMER0_NO_ERROR;
}


void M_TIMER0_Start(Timer0_Frequency_PreScaler PreScalerClk)
{
	if(PreScalerClk == TIMER0_STOPPED)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_CLK)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_CLK_DIV_8)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);

	}
	else if(PreScalerClk == TIMER0_CLK_DIV_64)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_CLK_DIV_256)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_CLK_DIV_1024)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_EXTERNAL_FALLING_EDGE)
	{
		CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
	else if(PreScalerClk == TIMER0_EXTERNAL_RISING_EDGE)
	{
		SET_BIT(TCCR0,TCCR0_CS00_BIT);
		SET_BIT(TCCR0,TCCR0_CS01_BIT);
		SET_BIT(TCCR0,TCCR0_CS02_BIT);
	}
}

void M_TIMER0_Stop()
{
	//clear prescaler
	CLEAR_BIT(TCCR0,TCCR0_CS00_BIT);
	CLEAR_BIT(TCCR0,TCCR0_CS01_BIT);
	CLEAR_BIT(TCCR0,TCCR0_CS02_BIT);
}

u8 M_TIMER0_GetCounts()
{
	return TCNT0;
}

void M_TIMER0_SetTimerPreload(u8 Value)
{
	TCNT0 = Value;
}

void M_TIMER0_SetOutputCompare(u8 Value)
{
	OCR0 = Value;
}

static u16 DelayNumberOverflowNeed = 0;
static f32 DelayNumberTicksNeed =0;
static u16 DelayOverflowCounter = 0;
static void (*ptrDelayFunction)();
void ISR_OverflowDelay()//new call back function
{
	DelayOverflowCounter++;

	if(DelayOverflowCounter > DelayNumberOverflowNeed)
	{
		(*ptrDelayFunction)();//what the user want to do
		DelayOverflowCounter = 0;
		M_TIMER0_Stop();
	}
}

TIMER0_Delay_Status M_Timer0_SetDelayTimeMilliSec(u16 TimeMilliSec, void (*ptrDelaySetCallBackFunction)())
{
	if(DelayOverflowCounter == 0)
	{
		ptrDelayFunction = ptrDelaySetCallBackFunction;

		TimeMilliSec = TimeMilliSec/1000;//convert to second

		//DelayNumberOverflowNeed =  TimeMilliSec / (256*((f32)(1/(f32)(CPU_CLK/TIMER0_CLK_DIV_8)))); //TIMER0_CLK_DIV_8 may be change by testing
		DelayNumberTicksNeed = (f32)(TimeMilliSec / ((f32)(1/(f32)(CPU_CLK/TIMER0_CLK_DIV_8))));
		DelayNumberOverflowNeed = DelayNumberTicksNeed/256;
		u8 RemainingTicks = (u32)DelayNumberTicksNeed%256;
		if(RemainingTicks != 0)
		{
			M_TIMER0_SetTimerPreload(256 - RemainingTicks);
			DelayNumberOverflowNeed =DelayNumberOverflowNeed+1;
		}
		M_TIMER0_Int(TIMER0_NORMAL_MODE, OC0_DISCONNECTED);
		M_TIMER0_SetCallBackFunction(ISR_OverflowDelay, TIMER0_INTERRUPT_OVERFLOW);
		M_TIMER0_EnableInterrupt(TIMER0_INTERRUPT_OVERFLOW);
		M_TIMER0_Start(TIMER0_CLK_DIV_8); //TIMER0_CLK_DIV_8 may be change by testing

		return TIMER0_DELAY_NO_ERROR;
	}
	else
	{
		return TIMER0_DELAY_BUSY;
	}
}

TIMER0_Error_Status M_TIMER0_EnableInterrupt(Timer0_INTERRUPT_ID InterruptMode)
{
	switch(InterruptMode)
	{
	case TIMER0_INTERRUPT_OVERFLOW:
		SET_BIT(TIMSK,TIMSK_TOIE0_BIT);
	break;
	case TIMER0_INTERRUPT_COMPARE_MATCH:
		SET_BIT(TIMSK,TIMSK_OCIE0_BIT);
	break;
	default:
		return TIMER0_INTERRUPT_ERROR;
	break;
	}
	return TIMER0_NO_ERROR;
}

TIMER0_Error_Status M_TIMER0_DisableInterrupt(Timer0_INTERRUPT_ID InterruptMode)
{
	switch(InterruptMode)
	{
	case TIMER0_INTERRUPT_OVERFLOW:
		CLEAR_BIT(TIMSK,TIMSK_TOIE0_BIT);
	break;
	case TIMER0_INTERRUPT_COMPARE_MATCH:
		CLEAR_BIT(TIMSK,TIMSK_OCIE0_BIT);
	break;
	default:
		return TIMER0_INTERRUPT_ERROR;
	break;
	}
	return TIMER0_NO_ERROR;
}



void (*TIMER0_ptrFunctionInterruptArray[2])();

TIMER0_Error_Status M_TIMER0_SetCallBackFunction(void (*ptrFunction)(), Timer0_INTERRUPT_ID InterruptMode)
{
	switch(InterruptMode)
	{
	case TIMER0_INTERRUPT_OVERFLOW:
		TIMER0_ptrFunctionInterruptArray[0] = ptrFunction;
	break;
	case TIMER0_INTERRUPT_COMPARE_MATCH:
		TIMER0_ptrFunctionInterruptArray[1] = ptrFunction;
	break;
	default:
		return TIMER0_INTERRUPT_ERROR;
	break;
	}
	return TIMER0_NO_ERROR;

}

ISR(TIMER0_OVF_vect)
{
	TIMER0_ptrFunctionInterruptArray[0]();
}

ISR(TIMER0_COMP_vect)
{
	TIMER0_ptrFunctionInterruptArray[1]();
}

TIMER0_Error_Status TIMER0_SetFastPWM(f32 PwmFrequency, u8 DutyPrcent)
{
	OCR0 = (u8)(DutyPrcent* TIMER0_MAX_VALUE / 100) -1;//for non inverted
	//OCR0 = (u8)(DutyPrcent* TIMER0_MAX_VALUE / 100) + 255 ;//for inverted

	u16 PreScaler = CPU_CLK /(PwmFrequency*256);

	if(PreScaler <  TIMER0_CLK_DIV_8)
	{
		M_TIMER0_Start(TIMER0_CLK);
	}
	else if(PreScaler > TIMER0_CLK_DIV_8 && PreScaler < TIMER0_CLK_DIV_64)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_8);
	}
	else if(PreScaler > TIMER0_CLK_DIV_64 && PreScaler < TIMER0_CLK_DIV_256)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_64);
	}
	else if(PreScaler > TIMER0_CLK_DIV_256 && PreScaler < TIMER0_CLK_DIV_1024)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_256);
	}
	else if(PreScaler == TIMER0_CLK_DIV_1024)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_1024);
	}
	else
	{
		return TIMER0_OUT_OF_RANGE_VALUE;
	}

	return TIMER0_NO_ERROR;

}


TIMER0_Error_Status TIMER0_SetphaseCorrectPWM(u8 PwmFrequency, u8 DutyPrcent)
{
	OCR0 = (u8)(DutyPrcent* (TIMER0_MAX_VALUE) / 100) ;//for non inverted
	//OCR0 = (u8)(DutyPrcent* (TIMER0_MAX_VALUE-1) / 100) + 255 ;//for inverted

	u16 PreScaler = CPU_CLK /(PwmFrequency * 510);

	if(PreScaler < TIMER0_CLK_DIV_8)
	{
		M_TIMER0_Start(1);
	}
	else if(PreScaler > TIMER0_CLK_DIV_8 && PreScaler < TIMER0_CLK_DIV_64)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_8);
	}
	else if(PreScaler > TIMER0_CLK_DIV_64 && PreScaler < TIMER0_CLK_DIV_256)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_64);
	}
	else if(PreScaler > TIMER0_CLK_DIV_256 && PreScaler < TIMER0_CLK_DIV_1024)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_256);
	}
	else if(PreScaler == TIMER0_CLK_DIV_1024)
	{
		M_TIMER0_Start(TIMER0_CLK_DIV_1024);
	}
	else
	{
		return TIMER0_OUT_OF_RANGE_VALUE;
	}

	return TIMER0_NO_ERROR;
}

