/*
 * ADC_INT.h
 *
 *  Created on: Mar 3, 2023
 *      Author: joseph
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

#include "ADC_TYPES.h"

void M_ADC_void_Init(ADC_Referance_Selection Vref, ADC_Adjust AdjustMode, ADC_PreScaler Prescaler, ADC_Auto_Trigger_Source AutotrigerSource, ADC_Enable_Satus EnableStatus);

u16 M_ADC_u16_GetDigitalValueSynchNonBlocking(ADC_Channel_Number ChannelNumber, u16 TimeOut);

u16 M_ADC_u16_GetDigitalValueAsynchCallBack(ADC_Channel_Number ChannelNumber, void(*FuncAfterConversion)());

u16 M_ADC_u16_GetLastResultDigital();

f32 M_ADC_f32_GetLastResultVoltage();

#endif /* ADC_ADC_INT_H_ */
