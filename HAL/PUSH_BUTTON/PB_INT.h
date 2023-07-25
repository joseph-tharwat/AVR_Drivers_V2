/*
 * PB_INT.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#ifndef PUSH_BUTTON_PB_INT_H_
#define PUSH_BUTTON_PB_INT_H_
#include "PB_TYPES.h"

#define PB_DEBOUNCING_LIMIT		10

PB_STATE H_PB_u8_ReadButton(PB_ID ButtomId);

#endif /* PUSH_BUTTON_PB_INT_H_ */
