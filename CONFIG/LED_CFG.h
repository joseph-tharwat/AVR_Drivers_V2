/*
 * LED_CFG.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_

/*
 * Please config the led pins
 * LED_PIN	ex: DIO_PB7
 *
 * please config the led direction
 * LED_FORWARD_DIRECTION
 * LED_REVERSE_DIRECTION
 */

#define LED_RED_PIN				DIO_PB7
#define LED_RED_DIRECTION		LED_FORWARD_DIRECTION

#define LED_GREEN_PIN			DIO_PA4
#define LED_GREEN_DIRECTION		LED_FORWARD_DIRECTION

#define LED_BLUE_PIN			DIO_PA5
#define LED_BLUE_DIRECTION		LED_FORWARD_DIRECTION

#define LED_YELLOW_PIN			DIO_PA6
#define LED_YELLOW_DIRECTION	LED_FORWARD_DIRECTION


#endif /* LED_CFG_H_ */
