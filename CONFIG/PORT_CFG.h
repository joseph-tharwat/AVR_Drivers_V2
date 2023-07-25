/*
 * PORT_CFG.h
 *
 *  Created on: Feb 17, 2023
 *  Author: joseph
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/******************************************
  INCLUDES
*******************************************/
#include "PORT_TYPES.h"

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define PORT_CONFIG_ARR_SIZE 	32

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/

typedef struct
{
	Port_PinType PinNumber;
	Port_PinLevelType PinLevel;
	Port_PinDirectionType PinDirection;
	Port_InternalAttachType PinInternalAttachType;
}Port_Config_Type;


#endif /* PORT_CFG_H_ */
