/*
 * LED_INT.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#ifndef LED_LED_INT_H_
#define LED_LED_INT_H_


#define LED_RED		0
#define LED_BLUE	1
#define LED_GREEN	2
#define LED_YELLOW	3

void H_LED_void_TurnOff(u8 LedId);

void H_LED_void_TurnOn(u8 LedId);

void H_LED_void_Toggle(u8 LedId);


#endif /* LED_LED_INT_H_ */
