/*
 * I2C_TYPES.h
 *
 *  Created on: Mar 9, 2023
 *      Author: joseph
 */

#ifndef I2C_I2C_TYPES_H_
#define I2C_I2C_TYPES_H_

//Prescaler Bits
#define I2C_DIV_1       1
#define I2C_DIV_4       4
#define I2C_DIV_16      16
#define I2C_DIV_64      64


typedef enum
{
	I2C_SLAVE_MODE =0,
	I2C_MASTER_MODE =1,
}I2C_Mode;

typedef enum
{
	I2C_CLK_DIV_1 = 1,
	I2C_CLK_DIV_4 = 4,
	I2C_CLK_DIV_16 = 16,
	I2C_CLK_DIV_64 = 64,
}I2C_Prescaler;

typedef enum
{
	I2C_WRITE = 0,
	I2C_READ = 1,
}I2C_RW;

#endif /* I2C_I2C_TYPES_H_ */
