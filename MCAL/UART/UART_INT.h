/*
 * UART_INT.h
 *
 *  Created on: Mar 4, 2023
 *      Author: joseph
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

#include "UART_TYPES.h"

void M_UART_Inite (UART_Baud_Rate BaudRate, UART_Word_Length Wordlength,UART_Parity_Mode ParityBits ,UART_Stop_Bits StopBits);

void M_UART_SendByte(u8 Data);

void M_UART_SendString(u8* String);

UART_Receive_Stutas M_UART_ReceiveByteSynchNonBlocking(u8* ReceivedData, u16 TimeMicroSec);

u8 M_UART_ReceiveByteAsynchCallBack(void(* CallBackFuncPtr)());

void M_UART_DisableInterrupt();

void M_UART_EnableInterrupt();

void M_UART_SetCallBack(void(* CallBackFuncPtr)());

#endif /* UART_UART_INT_H_ */
