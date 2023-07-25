/*
 * KEYPAD_PROG.c
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"

#include "DIO_INT.h"

#include "KEYPAD_TYPES.h"
#include "KEYPAD_CFG.h"
#include "KEYPAD_INT.h"

u8 H_KEYPAD_u8_GetPressedKey(void)
{

	static u8 DepouncingCounter1 = 0;
	static u8 DepouncingCounter2 = 0;
	static u8 DepouncingCounter3 = 0;
	static u8 DepouncingCounter4 = 0;

	u8 ButtonValue = '\0';

	M_DIO_void_SetPinValue(KEYPAD_ROW1,DIO_LOW);
	M_DIO_void_SetPinValue(KEYPAD_ROW2,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW3,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW4,DIO_High);
	if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R1C1;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R1C2;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R1C3;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R1C4;
	}

	if(ButtonValue == KEYPAD_R1C1 || ButtonValue == KEYPAD_R1C2 || ButtonValue == KEYPAD_R1C3 || ButtonValue == KEYPAD_R1C4)
	{
		if(DepouncingCounter1 >= KEYPAD_DEBOUNCING_LIMIT)
		{
			DepouncingCounter1 = 0;
			return ButtonValue;
		}
		else
		{
			DepouncingCounter1 = 0;
			return KEYPAD_UNPRESSED;
		}
	}
	else
	{
		if(DepouncingCounter1 <= KEYPAD_DEBOUNCING_LIMIT)
			DepouncingCounter1++;
		//return ButtonValue;	//continue checking the other rows
	}

	M_DIO_void_SetPinValue(KEYPAD_ROW1,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW2,DIO_LOW);
	M_DIO_void_SetPinValue(KEYPAD_ROW3,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW4,DIO_High);
	if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R2C1;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R2C2;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R2C3;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R2C4;
	}

	if(ButtonValue == KEYPAD_R2C1 || ButtonValue == KEYPAD_R2C2 || ButtonValue == KEYPAD_R2C3 || ButtonValue == KEYPAD_R2C4)
	{
		if(DepouncingCounter2 >= KEYPAD_DEBOUNCING_LIMIT)
		{
			DepouncingCounter2 = 0;
			return ButtonValue;
		}
		else
		{
			return KEYPAD_UNPRESSED;
		}
	}
	else
	{
		DepouncingCounter2++;
		//return ButtonValue;	//continue checking the other rows
	}


	M_DIO_void_SetPinValue(KEYPAD_ROW1,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW2,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW3,DIO_LOW);
	M_DIO_void_SetPinValue(KEYPAD_ROW4,DIO_High);
	if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R3C1;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R3C2;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R3C3;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R3C4;
	}

	if(ButtonValue == KEYPAD_R3C1 || ButtonValue == KEYPAD_R3C2 || ButtonValue == KEYPAD_R3C3 || ButtonValue == KEYPAD_R3C4)
	{
		if(DepouncingCounter3 >= KEYPAD_DEBOUNCING_LIMIT)
		{
			DepouncingCounter3 = 0;
			return ButtonValue;
		}
		else
		{
			return KEYPAD_UNPRESSED;
		}
	}
	else
	{
		DepouncingCounter3++;
		//return ButtonValue;	//continue checking the other rows
	}


	M_DIO_void_SetPinValue(KEYPAD_ROW1,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW2,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW3,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW4,DIO_LOW);
	if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN1) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R4C1;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN2) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R4C2;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN3) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R4C3;
	}
	else if(M_DIO_u8_GetPinValue(KEYPAD_COLUMN4) == DIO_LOW)
	{
		ButtonValue = KEYPAD_R4C4;
	}

	if(ButtonValue == KEYPAD_R4C1 || ButtonValue == KEYPAD_R4C2 || ButtonValue == KEYPAD_R4C3 || ButtonValue == KEYPAD_R4C4)
	{
		if(DepouncingCounter4 >= KEYPAD_DEBOUNCING_LIMIT)
		{
			DepouncingCounter4 = 0;
			return ButtonValue;
		}
		else
		{
			return KEYPAD_UNPRESSED;
		}
	}
	else
	{
		DepouncingCounter4++;
		//return ButtonValue;	//continue checking the other rows
	}


	M_DIO_void_SetPinValue(KEYPAD_ROW1,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW2,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW3,DIO_High);
	M_DIO_void_SetPinValue(KEYPAD_ROW4,DIO_High);

	return ButtonValue;
}
