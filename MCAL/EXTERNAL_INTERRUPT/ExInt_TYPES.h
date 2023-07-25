/*
 * ExInt_TYPES.h
 *
 *  Created on: Feb 24, 2023
 *      Author: joseph
 */

#ifndef EXTERNAL_INTERRUPT_EXINT_TYPES_H_
#define EXTERNAL_INTERRUPT_EXINT_TYPES_H_

typedef enum
{
	ExInt_OUT_OF_RANGE_VALUE = 0,
	ExInt_NULL_POINTER,
	ExInt_NO_ERROR
}ExInt_Error_Status;

typedef enum
{
	ExInt_INT0 = 0,
	ExInt_INT1,
	ExInt_INT2
}ExInt_Interrupt_Number;

typedef enum
{
	ExInt_TRIGGER_LOW_LEVEL = 0,
	ExInt_TRIGGER_LOGICAL_CHANGE,
	ExInt_TRIGGER_FALLING_EDGE,
	ExInt_TRIGGER_RISIN_EDGE
}ExInt_TRIGGER_Status;



#endif /* EXTERNAL_INTERRUPT_EXINT_TYPES_H_ */
