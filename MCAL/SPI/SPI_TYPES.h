/*
 * SPI_TYPES.h
 *
 *  Created on: Mar 8, 2023
 *      Author: joseph
 */

#ifndef SPI_SPI_TYPES_H_
#define SPI_SPI_TYPES_H_

typedef enum
{
	SPI_LEADING_RISING = 0x0,
	SPI_LEADING_FALLING = 0x8
}SPI_Clock_Polarity;

typedef enum
{
	SPI_LEADING_SAMPLE = 0x0,
	SPI_LEADING_SETUP = 0x4
}SPI_Clock_Phase;

typedef enum
{
	SPI_CLK_DIV_4 = 4,
	SPI_CLK_DIV_16 = 16,
	SPI_CLK_DIV_64 = 64,
	SPI_CLK_DIV_128 = 128,
	SPI_CLK_DIV_2 = 2,
	SPI_CLK_DIV_8 = 8,
	SPI_CLK_DIV_32 = 32,
}SPI_Clock_Rate;

typedef enum
{
	SPI_LSB_FIRST = 0,
	SPI_MSB_FIRST = 0x20
}SPI_Data_Order;

typedef enum
{
	SPI_SLAVE_MODE = 0,
	SPI_MASTER_MODE = 0x10
}SPI_Master_Slave;

typedef enum
{
	SPI_MODE_0 = 0,
	SPI_MODE_1,
	SPI_MODE_2,
	SPI_MODE_3
}SPI_Mode;

#endif /* SPI_SPI_TYPES_H_ */
