/*
 * UART_PROG.c
 *
 *  Created on: Mar 4, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "DIO_INT.h"

#include "UART_CFG.h"
#include "UART_TYPES.h"
#include "UART_PRIV.h"
#include "UART_INT.h"

#include <avr/interrupt.h>
#include <avr/delay.h>

volatile u8 global_ReceivedData = '\0';

void M_UART_Inite(UART_Baud_Rate BaudRate, UART_Word_Length Wordlength,UART_Parity_Mode ParityBits ,UART_Stop_Bits StopBits)
{
	//Enable Receive
	SET_BIT(UCSRB,UCSRB_RXEN_BIT);

	//Enable Transmition
	SET_BIT(UCSRB,UCSRB_TXEN_BIT);

	//Set Word Length
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register
	switch(Wordlength)
	{
	case UART_5BIT_MODE:
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	break;
	case UART_6BIT_MODE:
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	break;
	case UART_7BIT_MODE:
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	break;
	case UART_8BIT_MODE:
		CLEAR_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	break;
	case UART_9BIT_MODE:
		SET_BIT(UCSRB,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UCSZ0_BIT);
	break;
	}

	//Set Parity Bits
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register

	if(ParityBits == UART_PARITY_DISABLED)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}
	else if(ParityBits == UART_PARITY_EVEN)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}
	else if(ParityBits == UART_PARITY_ODD)
	{
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM0_BIT);
		SET_BIT(UCSRC_UBRRH,UCSRC_UPM1_BIT);
	}

	//Set Stop Bits
	SET_BIT(UCSRC_UBRRH,UCSRC_URSEL_BIT);	//select UCSRC register
	if(StopBits == UART_STOP_1BIT)
	{
		CLEAR_BIT(UCSRC_UBRRH,UCSRC_USBS_BIT);
	}
	else if(StopBits == UART_STOP_2BIT)
	{
		SET_BIT(UCSRC_UBRRH,UCSRC_USBS_BIT);
	}

	//Set Bude Rate
#warning "Not Supported all buad Rats"
	UBRRL = BaudRate;
	UBRRH =  0;
}

void M_UART_SendByte(u8 Data)
{
	//wait untill UDR is empty
	while((GET_BIT(UCSRA, UCSRA_UDRE_BIT)) == 0)
	{

	}

	UDR = Data;

}

void M_UART_SendString(u8* String)
{
	u8 i = 0;
	while(String[i] != '\0')
	{
		M_UART_SendByte(String[i]);
		i++;
	}
}

UART_Receive_Stutas M_UART_ReceiveByteSynchNonBlocking(u8* ReceivedData, u16 TimeMicroSec)
{
	//Wait until receive
	u16	TimerCounter = 0;

	//while(GET_BIT(UCSRA,UCSRA_UDRE_BIT) == 0)
	while( (GET_BIT(UCSRA, UCSRA_RXC_BIT)) == 0 )
	{
		TimerCounter++;
		if(TimerCounter == TimeMicroSec)
			return UART_RECEIVE_NOT_COMPLETE;
	}
	*ReceivedData = UDR;
	return UART_RECEIVE_COMPLETE;
}

//
void(* CallBackReceiveFunc)();

u8 M_UART_ReceiveByteAsynchCallBack(void(* CallBackFuncPtr)())
{
	//Enable Receive Interrupt
	SET_BIT(UCSRB,UCSRB_RXCIE_BIT);

	//Set CallBack Function
	CallBackReceiveFunc = CallBackFuncPtr;
}

void M_UART_DisableInterrupt()
{
	//Disable Receive Interrupt
	CLEAR_BIT(UCSRB,UCSRB_RXCIE_BIT);
}

void M_UART_EnableInterrupt()
{
	//Enable Receive Interrupt
	SET_BIT(UCSRB,UCSRB_RXCIE_BIT);
}

UART_Receive_Stutas M_UART_ReceiveStringSynchNonBlocking(u8* OutputString ,u8 StringLength, u8 EndChar, u16 TimeOutMMiliSec)
{
	u8 Data;
	u8 i = 0;
	u16 TimeCounter = 0;
	UART_Receive_Stutas Rstatus = UART_RECEIVE_NOT_COMPLETE;

	for(u8 k = 0; k<StringLength; k++)
	{
		Rstatus = M_UART_ReceiveByteSynchNonBlocking(&Data, 100000);
		if(Rstatus == UART_RECEIVE_COMPLETE)
		{
			OutputString[i] = Data;
			i++;

			if(Data == EndChar)
			{
				OutputString[i+1] = '\0';
				return UART_RECEIVE_COMPLETE;
			}
		}

		TimeCounter++;
		if(TimeCounter == TimeOutMMiliSec)
		{
			return UART_RECEIVE_NOT_COMPLETE;
		}
	}
	OutputString[i+1] = '\0';

}



ISR(USART_RXC_vect)
{
	global_ReceivedData = UDR;
	CallBackReceiveFunc();
}

