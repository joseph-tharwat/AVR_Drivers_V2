/*
 * PORT_PROG.c
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */


/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_TYPES.h"
#include "PORT_INT.h"
#include "PORT_CFG.h"
#include "MCU_HW.h"



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
  Global Functions body
*******************************************/

void M_PORT_void_Int(Port_Config_Type* PORTConfigArr)
{
	for(u8 i=0; i< PORT_CONFIG_ARR_SIZE;i++)
	{
		u8 PortNumber = PORTConfigArr[i].PinNumber /10;
		u8 PinNumber = PORTConfigArr[i].PinNumber %10;

		if(PORTConfigArr[i].PinDirection == PORT_INPUT || PORTConfigArr[i].PinDirection == PORT_OUTPUT)
		{
			switch(PortNumber)
			{
			case port_PORTA:
				DDRA_REG = DDRA_REG| PORTConfigArr[i].PinDirection<<PinNumber;
			break;
			case port_PORTB:
				DDRB_REG = DDRB_REG| PORTConfigArr[i].PinDirection<<PinNumber;
			break;
			case port_PORTC:
				DDRC_REG = DDRC_REG| PORTConfigArr[i].PinDirection<<PinNumber;
			break;
			case port_PORTD:
				DDRD_REG = DDRD_REG| PORTConfigArr[i].PinDirection<<PinNumber;
			break;
			}
		}

		if(PORTConfigArr[i].PinDirection == PORT_INPUT)
		{
			if(PORTConfigArr[i].PinInternalAttachType == PORT_FLOATING ||PORTConfigArr[i].PinInternalAttachType == PORT_PULLUP)
			{
				switch(PortNumber)
				{
				case port_PORTA:
					PORTA_REG = PORTA_REG| PORTConfigArr[i].PinInternalAttachType<<PinNumber;
				break;
				case port_PORTB:
					PORTB_REG = PORTB_REG| PORTConfigArr[i].PinInternalAttachType<<PinNumber;
				break;
				case port_PORTC:
					PORTC_REG = PORTC_REG| PORTConfigArr[i].PinInternalAttachType<<PinNumber;
				break;
				case port_PORTD:
					PORTD_REG = PORTD_REG| PORTConfigArr[i].PinInternalAttachType<<PinNumber;
				break;
				}
			}
		}
		else if(PORTConfigArr[i].PinDirection == PORT_OUTPUT)
		{
			if(PORTConfigArr[i].PinLevel == PORT_High ||PORTConfigArr[i].PinLevel==PORT_LOW)
			{
				switch(PortNumber)
				{
				case port_PORTA:
					PORTA_REG = PORTA_REG| PORTConfigArr[i].PinLevel<<PinNumber;
				break;
				case port_PORTB:
					PORTB_REG = PORTB_REG| PORTConfigArr[i].PinLevel<<PinNumber;
				break;
				case port_PORTC:
					PORTC_REG = PORTC_REG| PORTConfigArr[i].PinLevel<<PinNumber;
				break;
				case port_PORTD:
					PORTD_REG = PORTD_REG| PORTConfigArr[i].PinLevel<<PinNumber;
				break;
				}
			}
		}

	}
}
