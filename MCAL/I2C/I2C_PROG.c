/*
 * I2C_PROG.c
 *
 *  Created on: Mar 9, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "I2C_CFG.h"
#include "I2C_PRIV.h"
#include "I2C_TYPES.h"
#include "I2C_INT.h"

//#include <math.h>

static u16 I2C_pow(u16 Numper, u16 Power)
{
	u16 result = Numper;
	for(u8 i = 1; i< Power; i++)
	{
		result = result * Numper;
	}
	return result;
}

void M_I2C_Init(I2C_Prescaler Prescaler, u16 Frequency)
{
	//Initialize the frequency speed
	TWBR = ((CPU_FREQ/Frequency)-16)/(2*I2C_pow(4,Prescaler));
	TWBR =72;
	//Set Prescaler
	if(Prescaler == I2C_CLK_DIV_1)
	{
		CLEAR_BIT(TWSR,TWSR_TWPS0_BIT);
		CLEAR_BIT(TWSR,TWSR_TWPS1_BIT);
	}
	else if(Prescaler == I2C_CLK_DIV_4)
	{
		SET_BIT(TWSR,TWSR_TWPS0_BIT);
		CLEAR_BIT(TWSR,TWSR_TWPS1_BIT);
	}
	else if(Prescaler == I2C_CLK_DIV_16)
	{
		CLEAR_BIT(TWSR,TWSR_TWPS0_BIT);
		SET_BIT(TWSR,TWSR_TWPS1_BIT);
	}
	else if(Prescaler == I2C_CLK_DIV_64)
	{
		SET_BIT(TWSR,TWSR_TWPS0_BIT);
		SET_BIT(TWSR,TWSR_TWPS1_BIT);
	}

	//Enable Interrupt
	SET_BIT(TWCR,TWCR_TWIE_BIT);

	//Enale I2C
	SET_BIT(TWCR,TWCR_TWEN_BIT);
}

void M_I2C_SendAddress(u8 Address, I2C_RW SelectRW)
{
	M_I2C_SendByte( ((Address<<1) | SelectRW) ) ;
}

void M_I2C_SendByte(u8 Byte)
{
	TWDR = Byte;
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while((GET_BIT(TWCR,TWCR_TWINT_BIT)) == 0)
	{

	}
}

void M_I2C_SendStart()
{
	TWCR = (1<<TWCR_TWSTA_BIT) | (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);

	//Wait until transmit Start
	while((GET_BIT(TWCR,TWCR_TWINT_BIT)) == 0)
	{

	}

}

void M_I2C_SendStop()
{
	TWCR = (1<<TWCR_TWSTO_BIT) | (1<<TWCR_TWEN_BIT) | (1<<TWCR_TWINT_BIT) ;
}

void M_I2C_ReceiveByte_ACK(u8* Byte)
{
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT) | (1<<TWCR_TWEA_BIT);
	while((GET_BIT(TWCR,TWCR_TWINT_BIT)) == 0 )
	{

	}
	*Byte = TWDR;
}

void M_I2C_ReceiveByte_NoACK(u8* Byte)
{
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while((GET_BIT(TWCR,TWCR_TWINT_BIT)) == 0 )
	{

	}
	*Byte = TWDR;
	//return TWDR;
}

void M_I2C_GetStatus(u8* Status)
{
	*Status = (TWSR & 0xF8);
}
