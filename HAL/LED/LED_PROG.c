/*
 * LED_PROG.c
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */


#include "STD_TYPES.h"
#include "DIO_INT.h"
#include "LED_PRIV.h"
#include "LED_CFG.h"
#include "LED_INT.h"

void H_LED_void_TurnOn(u8 LedId)
{
	switch(LedId)
	{
	case LED_RED:
#if(LED_RED_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_RED_PIN,DIO_High);
#elif(LED_RED_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_RED_PIN,DIO_LOW);
#else
	#error("Wrong LED_RED direction")
#endif
		break;
	case LED_BLUE:
#if(LED_BLUE_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_BLUE_PIN,DIO_High);
#elif(LED_BLUE_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_BLUE_PIN,DIO_LOW);
#else
	#error("Wrong LED_BLUE direction")
#endif
		break;
	case LED_GREEN:
#if(LED_GREEN_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_GREEN_PIN,DIO_High);
#elif(LED_GREEN_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_GREEN_PIN,DIO_LOW);
#else
	#error("Wrong LED_GREEN direction")
#endif
		break;
	case LED_YELLOW:
#if(LED_YELLOW_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_YELLOW_PIN,DIO_High);
#elif(LED_YELLOW_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_YELLOW_PIN,DIO_LOW);
#else
	#error("Wrong LED_YELLOW direction")
#endif
		break;
	}
}

void H_LED_void_TurnOff(u8 LedId)
{

	switch(LedId)
	{
	case LED_RED:
#if(LED_RED_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_RED_PIN,DIO_LOW);
#elif(LED_RED_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_RED_PIN,DIO_High);
#else
	#error("Wrong LED_RED direction")
#endif
		break;
	case LED_BLUE:
#if(LED_BLUE_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_BLUE_PIN,DIO_LOW);
#elif(LED_BLUE_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_BLUE_PIN,DIO_High);
#else
	#error("Wrong LED_BLUE direction")
#endif
		break;
	case LED_GREEN:
#if(LED_GREEN_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_GREEN_PIN,DIO_LOW);
#elif(LED_GREEN_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_GREEN_PIN,DIO_High);
#else
	#error("Wrong LED_GREEN direction")
#endif
		break;
	case LED_YELLOW:
#if(LED_YELLOW_DIRECTION == LED_FORWARD_DIRECTION)
		M_DIO_void_SetPinValue(LED_YELLOW_PIN,DIO_LOW);
#elif(LED_YELLOW_DIRECTION == LED_REVERSE_DIRECTION)
		M_DIO_void_SetPinValue(LED_YELLOW_PIN,DIO_High);
#else
	#error("Wrong LED_YELLOW direction")
#endif
		break;
	}
}

void H_LED_void_Toggle(u8 LedId)
{
	switch(LedId)
	{
	case LED_RED:
		M_DIO_void_TogglePinValue(LED_RED_PIN);
	break;

	case LED_GREEN:
		M_DIO_void_TogglePinValue(LED_GREEN_PIN);
	break;

	case LED_BLUE:
		M_DIO_void_TogglePinValue(LED_BLUE_PIN);
	break;

	case LED_YELLOW:
		M_DIO_void_TogglePinValue(LED_YELLOW_PIN);
	break;
	}
}
