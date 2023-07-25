/*
 * SSD_PROG.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#include <avr/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"

#include "SSD_TYPES.h"
#include "SSD_PRIV.h"
#include "SSD_CFG.h"
#include "SSD_INT.h"

void H_SSD_void_DisplayIntNumber(u16 DisplyNumber)
{

	u8 ArrDigits[4] = {0};
	u8 i =0;
	while(DisplyNumber != 0 && i<4)// the second condition for 4-digit seven segment
	{
		ArrDigits[i] = DisplyNumber%10;
		DisplyNumber = DisplyNumber/10;
		i++;
	}

	for(u8 k=0; k<SDD_DISPLAY_TIME/4; k++)//4 for 4 ms delay in the implementation
	{
		for(i=0; i<4;i++)
		{
			M_DIO_void_SetPinValue(SSD_A_PIN, GET_BIT(ArrDigits[i], 0));
			M_DIO_void_SetPinValue(SSD_B_PIN, GET_BIT(ArrDigits[i], 1));
			M_DIO_void_SetPinValue(SSD_C_PIN, GET_BIT(ArrDigits[i], 2));
			M_DIO_void_SetPinValue(SSD_D_PIN, GET_BIT(ArrDigits[i], 3));
			if(i==0)
			{
				M_DIO_void_SetPinValue(SSD_DIG1_EN_PIN,DIO_LOW);	//Enable Active low
				_delay_ms(1);
				M_DIO_void_SetPinValue(SSD_DIG1_EN_PIN,DIO_High);	//Disable
			}
			else if(i==1)
			{
				M_DIO_void_SetPinValue(SSD_DIG2_EN_PIN,DIO_LOW);	//Enable Active low
				_delay_ms(1);
				M_DIO_void_SetPinValue(SSD_DIG2_EN_PIN,DIO_High);	//Disable
			}
			else if(i==2)
			{
				M_DIO_void_SetPinValue(SSD_DIG3_EN_PIN,DIO_LOW);	//Enable Active low
				_delay_ms(1);
				M_DIO_void_SetPinValue(SSD_DIG3_EN_PIN,DIO_High);	//Disable
			}
			else if(i == 3)
			{
				M_DIO_void_SetPinValue(SSD_DIG4_EN_PIN,DIO_LOW);	//Enable Active low
				_delay_ms(1);
				M_DIO_void_SetPinValue(SSD_DIG4_EN_PIN,DIO_High);	//Disable
			}

		}
	}
}
