/*
 * I2C_INT.h
 *
 *  Created on: Mar 9, 2023
 *      Author: joseph
 */

#ifndef I2C_I2C_INT_H_
#define I2C_I2C_INT_H_

#include "I2C_TYPES.h"

void M_I2C_Init(I2C_Prescaler Prescaler, u16 Frequency);

void M_I2C_SendAddress(u8 Address, I2C_RW SelectRW);

void M_I2C_SendByte(u8 Byte);

void M_I2C_SendStart();

void M_I2C_SendStop();

void M_I2C_ReceiveByte_ACK(u8* Byte);

void M_I2C_ReceiveByte_NoACK(u8* Byte);

void M_I2C_GetStatus(u8* Status);

#endif /* I2C_I2C_INT_H_ */
