/*
 * UART_TYPES.h
 *
 *  Created on: Mar 4, 2023
 *      Author: joseph
 */

#ifndef UART_UART_TYPES_H_
#define UART_UART_TYPES_H_

//Wordlength,u8 ParityBits ,u8 StopBits);

typedef enum
{
	UART_5BIT_MODE = 5,
	UART_6BIT_MODE = 6,
	UART_7BIT_MODE = 7,
	UART_8BIT_MODE = 8,
	UART_9BIT_MODE = 9,
}UART_Word_Length;

typedef enum
{
	UART_STOP_1BIT = 1,
	UART_STOP_2BIT = 2,
}UART_Stop_Bits;

typedef enum
{
	UART_PARITY_DISABLED = 0,
	UART_PARITY_EVEN = 1,
	UART_PARITY_ODD = 2
}UART_Parity_Mode;

//Buad for 16M
typedef enum
{
	UART_BAUD_2400 = 416,
	UART_BAUD_4800 = 207,
	UART_BAUD_9600 = 103,
	UART_BAUD_14400 = 68,
	UART_BAUD_19200 = 51,
	UART_BAUD_28800 = 34,
	UART_BAUD_38400 = 25,
	UART_BAUD_57600 = 16,
	UART_BAUD_76800 = 12,
	UART_BAUD_115200 = 8,
	UART_BAUD_230400 = 3,
	UART_BAUD_250000 = 3,
	UART_BAUD_500000 = 1,
	UART_BAUD_1000000 = 0,
}UART_Baud_Rate;

typedef enum
{
	UART_RECEIVE_NOT_COMPLETE = 0,
	UART_RECEIVE_COMPLETE = 1,
}UART_Receive_Stutas;


#endif /* UART_UART_TYPES_H_ */
