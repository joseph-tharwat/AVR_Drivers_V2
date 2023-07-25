/*
 * DIO_PROG.c
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */

/******************************************
  INCLUDES
*******************************************/
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "MCU_HW.h"
/******************************************
  Local Data
*******************************************/


/******************************************
  Local Data
*******************************************/



/******************************************
  Global Data
*******************************************/


/******************************************
  Local Functions  body
*******************************************/


/******************************************
  Global Functions  body
*******************************************/


/******************************************
  syntax :

  Description : Set pin to high or low

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number , pin level
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_SetPinValue(Dio_PinLevelType PinId, Dio_PinLevelType Level)
{
	u8 PinNumber = PinId % 10;
	u8 PortNumber = PinId / 10;

	switch(Level)
	{
		case DIO_High:
			if(PortNumber == DIO_PORTA)
				SET_BIT(PORTA_REG,PinNumber);
			else if(PortNumber == DIO_PORTB)
				SET_BIT(PORTB_REG,PinNumber);
			else if(PortNumber == DIO_PORTC)
				SET_BIT(PORTC_REG,PinNumber);
			else if(PortNumber == DIO_PORTD)
				SET_BIT(PORTD_REG,PinNumber);

		break;
		case DIO_LOW:
			if(PortNumber == DIO_PORTA)
				CLR_BIT(PORTA_REG,PinNumber);
			else if(PortNumber == DIO_PORTB)
				CLR_BIT(PORTB_REG,PinNumber);
			else if(PortNumber == DIO_PORTC)
				CLR_BIT(PORTC_REG,PinNumber);
			else if(PortNumber == DIO_PORTD)
				CLR_BIT(PORTD_REG,PinNumber);
		break;
	}
}


/******************************************
  syntax :

  Description : Get pin value

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number
  parameters (out) : Non
  Return Value     : pin value
******************************************/
Dio_PinLevelType M_DIO_u8_GetPinValue(Dio_PinLevelType PinId)
{
	u8 PinNumber = PinId % 10;
	u8 PortNumber = PinId / 10;

	u8 PinValue = 0;
	if(PortNumber == DIO_PORTA)
		PinValue = GET_BIT(PINA_REG,PinNumber);
	else if(PortNumber == DIO_PORTB)
		PinValue = GET_BIT(PINB_REG,PinNumber);
	else if(PortNumber == DIO_PORTC)
		PinValue = GET_BIT(PINC_REG,PinNumber);
	else if(PortNumber == DIO_PORTD)
		PinValue = GET_BIT(PIND_REG,PinNumber);

	return PinValue;

}


/******************************************
  syntax :

  Description : Toggle pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_TogglePinValue(Dio_PinLevelType PinId)
{
	u8 PinNumber = PinId % 10;
	u8 PortNumber = PinId / 10;

	switch(PortNumber)
	{
		case DIO_PORTA:
			TOG_BIT(PORTA_REG,PinNumber);
		break;
		case DIO_PORTB:
			TOG_BIT(PORTB_REG,PinNumber);
		break;
		case DIO_PORTC:
			TOG_BIT(PORTC_REG,PinNumber);
		break;
		case DIO_PORTD:
			TOG_BIT(PORTD_REG,PinNumber);
		break;
	}

}


/******************************************
  syntax :

  Description : Set value to port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : port number, port value
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_SetPortValue(Dio_PortType PortId, Dio_PortLevelType PortValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
			PORTA_REG = PortValue;
		break;
		case DIO_PORTB:
			PORTB_REG = PortValue;
		break;
		case DIO_PORTC:
			PORTC_REG = PortValue;
		break;
		case DIO_PORTD:
			PORTD_REG = PortValue;
		break;
	}
}


/******************************************
  syntax :

  Description : Get pin to high or low

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : port number
  parameters (out) : Non
  Return Value     : port value
******************************************/
Dio_PortLevelType M_DIO_void_GetPortValue(Dio_PortType PortId)
{
	Dio_PortLevelType PortValue = 0;
	switch(PortId)
	{
		case DIO_PORTA:
			PortValue = PORTA_REG;
		break;
		case DIO_PORTB:
			PortValue = PORTB_REG;
		break;
		case DIO_PORTC:
			PortValue = PORTC_REG;
		break;
		case DIO_PORTD:
			PortValue = PORTD_REG;
		break;
	}
	return PortValue;
}




