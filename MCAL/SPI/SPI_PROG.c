/*
 * SPI_PROG.c
 *
 *  Created on: Mar 8, 2023
 *      Author: joseph
 */

#include "MCU_HW.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_CFG.h"
#include "SPI_PRIV.h"
#include "SPI_TYPES.h"
#include "SPI_INT.h"

#include "avr/interrupt.h"

void (*SPI_ISR_Function)() = NULL;

void M_SPI_Init(SPI_Master_Slave MasterSlave, SPI_Clock_Rate ClkRate, SPI_Data_Order DataOrder, SPI_Mode Mode)
{
	//Master Slave Select
	SPCR = SPCR|MasterSlave;

	//Select Clock Rate
	switch(ClkRate)
	{
	case SPI_CLK_DIV_4:
		CLEAR_BIT(SPCR,SPCR_SPR0_BIT);
		CLEAR_BIT(SPCR,SPCR_SPR1_BIT);
	break;
	case SPI_CLK_DIV_16:
		SET_BIT(SPCR,SPCR_SPR0_BIT);
		CLEAR_BIT(SPCR,SPCR_SPR1_BIT);
	break;
	case SPI_CLK_DIV_64:
		CLEAR_BIT(SPCR,SPCR_SPR0_BIT);
		SET_BIT(SPCR,SPCR_SPR1_BIT);
	break;
	case SPI_CLK_DIV_128:
		SET_BIT(SPCR,SPCR_SPR0_BIT);
		SET_BIT(SPCR,SPCR_SPR1_BIT);
	break;
	case SPI_CLK_DIV_2:
		CLEAR_BIT(SPCR,SPCR_SPR0_BIT);
		CLEAR_BIT(SPCR,SPCR_SPR1_BIT);
		SET_BIT(SPSR,SPSR_SPI2X_BIT);
	break;
	case SPI_CLK_DIV_8:
		SET_BIT(SPCR,SPCR_SPR0_BIT);
		CLEAR_BIT(SPCR,SPCR_SPR1_BIT);
		SET_BIT(SPSR,SPSR_SPI2X_BIT);
	break;
	case SPI_CLK_DIV_32:
		CLEAR_BIT(SPCR,SPCR_SPR0_BIT);
		SET_BIT(SPCR,SPCR_SPR1_BIT);
		SET_BIT(SPSR,SPSR_SPI2X_BIT);
	break;
	}

	//Select Data Order
	SPCR = SPCR | DataOrder;

	switch(Mode)
	{
	case SPI_MODE_0:
		SPCR = SPCR | SPI_LEADING_SAMPLE;
		SPCR = SPCR | SPI_LEADING_RISING;
	break;
	case SPI_MODE_1:
		SPCR = SPCR | SPI_LEADING_SETUP;
		SPCR = SPCR | SPI_LEADING_RISING;
	break;
	case SPI_MODE_2:
		SPCR = SPCR | SPI_LEADING_SAMPLE;
		SPCR = SPCR | SPI_LEADING_FALLING;
	break;
	case SPI_MODE_3:
		SPCR = SPCR | SPI_LEADING_SETUP;
		SPCR = SPCR | SPI_LEADING_FALLING;
	break;
	}

	//Enable SPI
	SET_BIT(SPCR,SPCR_SPE_BIT);

	//Enable Interrupt
	SET_BIT(SPCR,SPCR_SPIE_BIT);
}

void M_SPI_SetCallBackFunction(void (*CallBackFunc)())
{
	SPI_ISR_Function = CallBackFunc;
}

void M_SPI_SendByte(u8 Byte)
{
	SPDR = Byte;
	while((GET_BIT(SPSR,SPSR_SPIF_BIT)) == 0 )
	{

	}
	//SET_BIT(SPSR, SPSR_SPIF_BIT);
}

u8 M_SPI_ReceiveByte()
{
	while((GET_BIT(SPSR,SPSR_SPIF_BIT)) == 0)
	{

	}
	return SPDR;
}

ISR(SPI_STC_vect)
{
	if(SPI_ISR_Function != NULL)
	{
		SPI_ISR_Function();
	}

}
