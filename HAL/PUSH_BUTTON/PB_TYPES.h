/*
 * PB_TYPES.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#ifndef PUSH_BUTTON_PB_TYPES_H_
#define PUSH_BUTTON_PB_TYPES_H_

typedef enum
{
	PB1 = 0,
	PB2,
	PB3,
	PB4
}PB_ID;


typedef enum
{
	PB_UNPRESSED = 0,
	PB_PRESSED
}PB_STATE;

typedef enum
{
	PB_ACTIVELOW = 0,
	PB_ACTIVEHIGH
}PB_TYPE;


#endif /* PUSH_BUTTON_PB_TYPES_H_ */
