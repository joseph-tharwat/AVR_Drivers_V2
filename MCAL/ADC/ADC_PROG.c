/*
 * ADC_PROG.c
 *
 *  Created on: Mar 3, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "ADC_TYPES.h"
#include "ADC_CONFIG.h"
#include "ADC_PRIV.h"
#include "ADC_INT.h"

#include <avr/interrupt.h>
#include <avr/delay.h>

u16 ADC_LastResult = 0;

void M_ADC_void_Init(ADC_Referance_Selection Vref, ADC_Adjust AdjustMode, ADC_PreScaler Prescaler, ADC_Auto_Trigger_Source AutotrigerSource, ADC_Enable_Satus EnableStatus)
{
	//Set Vref mode
	ADMUX = ADMUX & ADC_MASK_VREF_CLEAR;//Clear
	ADMUX = ADMUX | Vref;//Set

	//Set Adjust Mode
	ADMUX = ADMUX | AdjustMode;

	//Set Prescaler
	ADCSRA = ADCSRA & ADC_MASK_PRESCALER_CLEAR;	//clear
	switch(Prescaler)//set
	{
	case ADC_CLK_DIV_2:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_2;
	break;
	case ADC_CLK_DIV_4:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_4;
	break;
	case ADC_CLK_DIV_8:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_8;
	break;
	case ADC_CLK_DIV_16:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_16;
	break;
	case ADC_CLK_DIV_32:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_32;
	break;
	case ADC_CLK_DIV_64:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_64;
	break;
	case ADC_CLK_DIV_128:
		ADCSRA = ADCSRA | ADC_MASK_PRESCALER_CLK_128;
	break;
	}

	//Set Auto Trigger Source
	SFIOR =	SFIOR & ADC_MASK_AUTO_TRIGER_CLEAR;//clear
	SFIOR =	SFIOR | AutotrigerSource;//set

	//ADC Enable
	ADCSRA = ADCSRA | ADC_MASK_ENABLE_ADC;

}


u16 M_ADC_u16_GetDigitalValueSynchNonBlocking(ADC_Channel_Number ChannelNumber, u16 TimeOutMicroSec)
{
	//Set the channel
	ADMUX = ADMUX & ADC_MASK_CHANNEL_CLEAR;
	ADMUX = ADMUX | ChannelNumber;

	//Auto Trigger Enable
	ADCSRA = ADCSRA | ADC_MASK_ENABLE_AUTO_TRIGGER;

	u16 DelayCounter;

	//Start Conversion
	ADCSRA = ADCSRA | ADC_MASK_START_CONVERTION;

	//wait the flag
	while((ADMUX & ADC_MASK_INTERRUPT_FLAG) == 1)
	{
		//_delay_ms(1);
		DelayCounter++;
		if(DelayCounter == TimeOutMicroSec)
			return 0;
	}

	ADC_LastResult = M_ADC_u16_GetLastResultDigital();
	return ADC_LastResult;

}

void (*CallBackFunc)();

u16 M_ADC_u16_GetDigitalValueAsynchCallBack(ADC_Channel_Number ChannelNumber, void(*FuncAfterConversion)())
{
	//Set the channel
	ADMUX = ADMUX & ADC_MASK_CHANNEL_CLEAR;
	ADMUX = ADMUX | ChannelNumber;

	//Auto Trigger Enable
	ADCSRA = ADCSRA | ADC_MASK_ENABLE_AUTO_TRIGGER;

	//Set CallBack Function
	CallBackFunc = FuncAfterConversion;

	//Enterrupt Enable
	ADCSRA = ADCSRA | ADC_MASK_ENABLE_INTERRUPT;

	//Start Conversion
	ADCSRA = ADCSRA | ADC_MASK_START_CONVERTION;

}

u16 M_ADC_u16_GetLastResultDigital()
{
	//return ADCLH;//for test only

	u8 LowerByte = ADCL;
	u8 HigherByte = ADCH;
	//if left
	if(ADMUX & ADC_ADJUST_LEFT)
	{
		ADC_LastResult = (LowerByte>>6) | (HigherByte<<2);
		return ADC_LastResult;
	}
	//if right
	else if((ADMUX & ADC_ADJUST_LEFT) == 0)
	{
		ADC_LastResult = LowerByte | (HigherByte<<8);
		return ADC_LastResult;
	}
}

f32 M_ADC_f32_GetLastResultVoltage()
{
	return ((f32)(ADC_LastResult*5)/1024);
}

ISR(ADC_vect)
{
	ADC_LastResult  =  M_ADC_u16_GetLastResultDigital();
	CallBackFunc();

}
