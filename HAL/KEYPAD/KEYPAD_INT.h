/*
 * KEYPAD_INT.h
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#ifndef KEYPAD_KEYPAD_INT_H_
#define KEYPAD_KEYPAD_INT_H_

#include "KEYPAD_CFG.h"

#define KEYPAD_DEBOUNCING_LIMIT		15

u8 H_KEYPAD_u8_GetPressedKey(void);


#endif /* KEYPAD_KEYPAD_INT_H_ */
