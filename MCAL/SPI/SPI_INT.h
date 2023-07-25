/*
 * SOI_INT.h
 *
 *  Created on: Mar 8, 2023
 *      Author: joseph
 */

#ifndef SPI_SPI_INT_H_
#define SPI_SPI_INT_H_

#include "SPI_TYPES.h"

void M_SPI_Init(SPI_Master_Slave MassterSlave, SPI_Clock_Rate ClkRate, SPI_Data_Order DataOrder, SPI_Mode Mode);

void M_SPI_SetCallBackFunction(void (*CallBackFunc)());

void M_SPI_SendByte(u8 Byte);

u8 M_SPI_ReceiveByte();

#endif /* SPI_SPI_INT_H_ */
