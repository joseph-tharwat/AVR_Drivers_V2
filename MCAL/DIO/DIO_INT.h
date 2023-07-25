/*
 * DIO_INT.h
 *
 *  Created on: Feb 17, 2023
 *      Author: joseph
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_


/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "DIO_TYPES.h"
#include "DIO_CFG.h"
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

  Description : Set pin to high or low

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number , pin level
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_SetPinValue(Dio_PinLevelType PinId, Dio_PinLevelType Level);


/******************************************
  syntax :

  Description : Get pin value

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number
  parameters (out) : Non
  Return Value     : pin value
******************************************/
Dio_PinLevelType M_DIO_u8_GetPinValue(Dio_PinLevelType PinId);


/******************************************
  syntax :

  Description : Toggle pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : pin number
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_TogglePinValue(Dio_PinLevelType PinId);


/******************************************
  syntax :

  Description : Set value to port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : port number, port value
  parameters (out) : Non
  Return Value     : Non
******************************************/
void M_DIO_void_SetPortValue(Dio_PortType PortId, Dio_PortLevelType PortValue);


/******************************************
  syntax :

  Description : Set pin to high or low

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : port number
  parameters (out) : Non
  Return Value     : port value
******************************************/
Dio_PortLevelType M_DIO_void_GetPortValue(Dio_PortType PortId);


#endif /* DIO_DIO_INT_H_ */
