/*
 * ADC_TYPES.h
 *
 *  Created on: Mar 3, 2023
 *      Author: joseph
 */

#ifndef ADC_ADC_TYPES_H_
#define ADC_ADC_TYPES_H_

typedef enum
{
	ADC_CH0 = 0,
	ADC_CH1 = 1,
	ADC_CH2 = 2,
	ADC_CH3 = 3,
	ADC_CH4 = 4,
	ADC_CH5 = 5,
	ADC_CH6 = 6,
	ADC_CH7 = 7,
}ADC_Channel_Number;

typedef enum
{
	ADC_Disable = 0,
	ADC_Enable = 1,
}ADC_Enable_Satus;

typedef enum
{
	ADC_FREE_RUNNING = 0x00,
	ADC_ANALOG_COMPARATOR = 0x20,
	ADC_EXTERNAL_INTERRUPT = 0x40,
	ADC_TIMER0_COMPARE_MATCH = 0x60,
	ADC_TIMER0_OVERFLOW = 0x80,
	ADC_TIMER1_COMPARE_MATCHB = 0xA0,
	ADC_TIMER1_OVERFLOW = 0xC0,
	ADC_TIMER1_CAPTURE_EVENT = 0xE0
}ADC_Auto_Trigger_Source;

typedef enum
{
	ADC_CLK_DIV_2 = 2,
	ADC_CLK_DIV_4 = 4,
	ADC_CLK_DIV_8 = 8,
	ADC_CLK_DIV_16 = 16,
	ADC_CLK_DIV_32 = 32,
	ADC_CLK_DIV_64 = 64,
	ADC_CLK_DIV_128 = 128,

}ADC_PreScaler;

typedef enum
{
	ADC_ADJUST_RIGHT = 0x00,
	ADC_ADJUST_LEFT = 0x20,
}ADC_Adjust;

typedef enum
{
	ADC_AREF = 0x00,
	ADC_AVCC = 0x40,
	ADC_INTERNAL = 0xC0
}ADC_Referance_Selection;

#endif /* ADC_ADC_TYPES_H_ */
