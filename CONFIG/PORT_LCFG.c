/*
 * PORT_LCFG.c
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "PORT_CFG.h"


/******************************************
  Local Macros / Functions
*******************************************/


/******************************************
  Local Data
*******************************************/

/******************************************
  Global Data
*******************************************/

/*
typedef struct
{
	Port_PinType PinNumber;
	Port_PinLevelType PinLevel;
	Port_PinDirectionType PinDirection;
	Port_InternalAttachType PinInternalAttachType;
}Port_Config_Type;
*/
const Port_Config_Type PORT_Config_Arr[PORT_CONFIG_ARR_SIZE] = {
		//column config
		/*{PORT_PD7,PORT_High,PORT_INPUT,PORT_FLOATING},
		{PORT_PD6,PORT_High,PORT_INPUT,PORT_FLOATING},
		{PORT_PD5,PORT_High,PORT_INPUT,PORT_FLOATING},
		{PORT_PD3,PORT_High,PORT_INPUT,PORT_FLOATING},
		//row config
		{PORT_PC5,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PC4,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PC3,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PC2,PORT_High,PORT_OUTPUT,PORT_PULLUP},*/
		//lcd config
		{PORT_PA3,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PA2,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB0,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB1,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB2,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB4,PORT_High,PORT_OUTPUT,PORT_PULLUP},

		//ExInt0
		{PORT_PD2,PORT_High,PORT_INPUT,PORT_PULLUP},

		//LED
		{PORT_PB7,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PA6,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PA5,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PA4,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},

		//ULTRASONIC
		//{PORT_PC6,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		//{PORT_PD6,PORT_LOW,PORT_INPUT,PORT_PULLUP},

		//ADC
		//{PORT_PA0,PORT_High,PORT_INPUT,PORT_FLOATING},

		//SPI
		{PORT_PB5,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB6,PORT_LOW,PORT_INPUT,PORT_FLOATING},
		{PORT_PB7,PORT_LOW,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PB4,PORT_High,PORT_OUTPUT,PORT_PULLUP},

		//I2C
		{PORT_PC1,PORT_High,PORT_OUTPUT,PORT_PULLUP},
		{PORT_PC0,PORT_High,PORT_OUTPUT,PORT_PULLUP},

};



