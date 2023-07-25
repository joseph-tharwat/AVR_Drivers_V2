/*
 * ExInt_INT.h
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#ifndef EXTERNAL_INTERRUPT_EXINT_INT_H_
#define EXTERNAL_INTERRUPT_EXINT_INT_H_

#include "ExInt_TYPES.h"

ExInt_Error_Status M_ExInt_Enable(u8 InterruptNumber, u8 TriggerState);

ExInt_Error_Status M_ExInt_Disable(u8 InterruptNumber);

ExInt_Error_Status M_ExInt_SetCallBackFunction(void (*ptrFunc)(), u8 InterruptNumber);

#endif /* EXTERNAL_INTERRUPT_EXINT_INT_H_ */
