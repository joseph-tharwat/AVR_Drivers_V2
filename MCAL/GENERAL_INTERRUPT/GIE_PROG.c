/*
 * GIE_PROG.c
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"

#include "GIE_INT.h"

void M_GIE_Enable()
{
	SET_BIT(SREG,GIE_BIT);
}

void M_GIE_Disable()
{
	CLR_BIT(SREG,GIE_BIT);
}
