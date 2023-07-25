/*
 * MOTOR_PROG.c
 *
 *  Created on: Mar 4, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_INT.h"
#include "TIMER0_INT.h"

#include "MOTOR_CFG.h"
#include "MOTOR_TYPES.h"
#include "MOTOR_PRIV.h"
#include "MOTOR_INT.h"

void H_MOTOR_void_Init()
{
	//M_TIMER0_Int(TIMER0_PWM_MODE, OC0_CLEAR_ON_COMPARE_COUNTING_UP_SET_ON_COMPARE_COUNTING_DOWN);
	M_TIMER0_Int(TIMER0_FASTPWM_MODE, OC0_CLEAR_ON_COMPARE_SET_AT_TOP);
}

void H_MOTOR_void_SetDirection(MOTOR_Direction Direction)
{
	switch(Direction)
	{
	case MOTOR_LEFT_DIRECTION:
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_L1,DIO_High);
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_L2,DIO_High);

		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_R1,DIO_LOW);
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_R2,DIO_LOW);

	break;
	case MOTOR_RIGHT_DIRECTION:
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_R1,DIO_High);
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_R2,DIO_High);

		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_L1,DIO_LOW);
		M_DIO_void_SetPinValue(MOTOR_HBRIDGE_PIN_L2,DIO_LOW);
	break;
	}
}

void H_MOTOR_void_SetFrequancy(u16 Frequancy,u8 Duty)
{
	//TIMER0_SetphaseCorrectPWM(Frequancy, Duty);
	TIMER0_SetFastPWM(Frequancy, Duty);
}

void H_MOTOR_void_SetDuty(u16 Frequancy, u8 Duty)
{
	//TIMER0_SetphaseCorrectPWM(Frequancy, Duty);
	TIMER0_SetFastPWM(Frequancy, Duty);
}
