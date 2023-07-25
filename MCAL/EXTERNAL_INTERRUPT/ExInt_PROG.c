/*
 * ExInt_PROG.c
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"

#include "ExInt_PRIV.h"
#include "ExInt_TYPES.h"
#include "ExInt_CFG.h"
#include "ExInt_INT.h"

#include <avr/interrupt.h>

ExInt_Error_Status M_ExInt_Enable(ExInt_Interrupt_Number InterruptNumber, ExInt_TRIGGER_Status TriggerState)
{

	if(InterruptNumber == ExInt_INT0)
	{
		SET_BIT(GICR,GICR_INT0_BIT);	//Enable bit

		//Configuration
		switch(TriggerState)
		{
		case ExInt_TRIGGER_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
		break;
		case ExInt_TRIGGER_LOGICAL_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR,MCUCR_ISC01_BIT);
		break;
		case ExInt_TRIGGER_FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
		break;
		case ExInt_TRIGGER_RISIN_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR,MCUCR_ISC01_BIT);
		break;
		default:
			return ExInt_OUT_OF_RANGE_VALUE;
		break;
		}
	}
	else if(InterruptNumber == ExInt_INT1)
	{
		SET_BIT(GICR,GICR_INT1_BIT);	//Enable bit

		//Configuration
		switch(TriggerState)
		{
		case ExInt_TRIGGER_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
		break;
		case ExInt_TRIGGER_LOGICAL_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR,MCUCR_ISC11_BIT);
		break;
		case ExInt_TRIGGER_FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC10_BIT);
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
		break;
		case ExInt_TRIGGER_RISIN_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC10_BIT);
			SET_BIT(MCUCR,MCUCR_ISC11_BIT);
		break;
		default:
			return ExInt_OUT_OF_RANGE_VALUE;
		break;
		}
	}
	else if(InterruptNumber == ExInt_INT2)
	{
		SET_BIT(GICR,GICR_INT2_BIT);	//Enable bit

		//Configuration
		switch(TriggerState)
		{
		case ExInt_TRIGGER_FALLING_EDGE:
			CLR_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		break;
		case ExInt_TRIGGER_RISIN_EDGE:
			SET_BIT(MCUCSR,MCUCSR_ISC2_BIT);
		break;
		default:
			return ExInt_OUT_OF_RANGE_VALUE;
		break;
		}

	}
	else
	{
		return ExInt_OUT_OF_RANGE_VALUE;
	}

	return ExInt_NO_ERROR;

}

ExInt_Error_Status M_ExInt_Disable(ExInt_Interrupt_Number InterruptNumber)
{
	switch(InterruptNumber)
	{
	case ExInt_INT0:
		SET_BIT(GICR,GICR_INT0_BIT);
	break;
	case ExInt_INT1:
		SET_BIT(GICR,GICR_INT1_BIT);
	break;
	case ExInt_INT2:
		SET_BIT(GICR,GICR_INT2_BIT);
	break;
	default:
		return ExInt_OUT_OF_RANGE_VALUE;
	break;
	}
	return ExInt_NO_ERROR;
}


void (*ExInter_ptrFunctionArray[3])();

ExInt_Error_Status M_ExInt_SetCallBackFunction(void (*ptrFunc)(), u8 InterruptNumber)
{
	if(ptrFunc != NULL)
	{
		switch(InterruptNumber)
		{
		case ExInt_INT0:
			ExInter_ptrFunctionArray[0] = ptrFunc;
		break;
		case ExInt_INT1:
			ExInter_ptrFunctionArray[1] = ptrFunc;
		break;
		case ExInt_INT2:
			ExInter_ptrFunctionArray[2] = ptrFunc;
		break;
		default:
			return ExInt_OUT_OF_RANGE_VALUE;
		break;
		}
	}
	else
	{
		return ExInt_NULL_POINTER;
	}

	return ExInt_NO_ERROR;
}

ISR(INT0_vect)
{
	if(ExInter_ptrFunctionArray[0] != NULL)
		(ExInter_ptrFunctionArray[0])();
}

ISR(INT1_vect)
{
	if(ExInter_ptrFunctionArray[1] != NULL)
		(ExInter_ptrFunctionArray[1])();
}

ISR(INT2_vect)
{
	if(ExInter_ptrFunctionArray[2] != NULL)
		(*ExInter_ptrFunctionArray[2])();
}
