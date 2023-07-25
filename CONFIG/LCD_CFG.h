/*
 * LCD_CFG.h
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
/*
 * Select the MODE _4BIT_MODE or _8BIT_MODE
 */
#define LCD_MODE 		_4BIT_MODE

#define LCD_RS_PIN		DIO_PA3
//#define LCD_RW	//Always connected to ground in FARES PCB
#define LCD_EN_PIN		DIO_PA2


/*
 * First four pins is not supported in FARES PCB
 * */
#define LCD_D0_PIN		0
#define LCD_D1_PIN		0
#define LCD_D2_PIN		0
#define LCD_D3_PIN		0

#define LCD_D4_PIN		DIO_PB0
#define LCD_D5_PIN		DIO_PB1
#define LCD_D6_PIN		DIO_PB2
#define LCD_D7_PIN		DIO_PB4


#endif /* LCD_CFG_H_ */
