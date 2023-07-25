/*
 * PORT_TYPES.h
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */

#ifndef PORT_PORT_TYPES_H_
#define PORT_PORT_TYPES_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
//Pins
typedef enum
{
	PORT_PA0 =10,
	PORT_PA1,
	PORT_PA2,
	PORT_PA3,
	PORT_PA4,
	PORT_PA5,
	PORT_PA6,
	PORT_PA7,

	PORT_PB0 =20,
	PORT_PB1,
	PORT_PB2,
	PORT_PB3,
	PORT_PB4,
	PORT_PB5,
	PORT_PB6,
	PORT_PB7,

	PORT_PC0 =30,
	PORT_PC1,
	PORT_PC2,
	PORT_PC3,
	PORT_PC4,
	PORT_PC5,
	PORT_PC6,
	PORT_PC7,

	PORT_PD0 = 40,
	PORT_PD1,
	PORT_PD2,
	PORT_PD3,
	PORT_PD4,
	PORT_PD5,
	PORT_PD6,
	PORT_PD7
}Port_PinType;

//ports
typedef enum
{
	port_PORTA = 1,
	port_PORTB,
	port_PORTC,
	port_PORTD

}Port_PortType;

//Pin Level
typedef enum
{
	PORT_LOW = 0,
	PORT_High
}Port_PinLevelType;

//Direction
typedef enum
{
	PORT_INPUT,
	PORT_OUTPUT
}Port_PinDirectionType;

typedef enum
{
	PORT_FLOATING,
	PORT_PULLUP
}Port_InternalAttachType;


#endif /* PORT_PORT_TYPES_H_ */
