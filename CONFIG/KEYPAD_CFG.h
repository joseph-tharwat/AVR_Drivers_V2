/*
 * KEYPAD_CFG.h
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define KEYPAD_UNPRESSED	'\0'

/*
 *configire the keypad
 */
#define KEYPAD_R1C1		'7'
#define KEYPAD_R1C2		'8'
#define KEYPAD_R1C3		'9'
#define KEYPAD_R1C4		'/'

#define KEYPAD_R2C1		'4'
#define KEYPAD_R2C2		'5'
#define KEYPAD_R2C3		'6'
#define KEYPAD_R2C4		'*'

#define KEYPAD_R3C1		'1'
#define KEYPAD_R3C2		'2'
#define KEYPAD_R3C3		'3'
#define KEYPAD_R3C4		'-'

#define KEYPAD_R4C1		'c'//c for clear
#define KEYPAD_R4C2		'0'
#define KEYPAD_R4C3		'='
#define KEYPAD_R4C4		'+'
////////////////////////////////////

/*
 * Configer the pins of the MCU that connected to the KEYPAD
 */
#define KEYPAD_ROW1			DIO_PC5
#define KEYPAD_ROW2			DIO_PC4
#define KEYPAD_ROW3			DIO_PC3
#define KEYPAD_ROW4			DIO_PC2

#define KEYPAD_COLUMN1		DIO_PD7
#define KEYPAD_COLUMN2		DIO_PD6
#define KEYPAD_COLUMN3		DIO_PD5
#define KEYPAD_COLUMN4		DIO_PD3


#endif /* KEYPAD_CFG_H_ */
