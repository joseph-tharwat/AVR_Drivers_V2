/*
 * PORT_INT.h
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */

#ifndef PORT_PORT_INT_H_
#define PORT_PORT_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "PORT_TYPES.h"
#include "PORT_CFG.h"
/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax :

  Description : Initialization of the pins that placed in the array

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : none
  parameters (out) : none
  Return Value     : None
******************************************/
void M_PORT_void_Int(Port_Config_Type* PORTConfigArr);


#endif /* PORT_PORT_INT_H_ */
