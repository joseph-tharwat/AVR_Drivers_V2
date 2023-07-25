/*
 * ExEEPROM_INT.h
 *
 *  Created on: Mar 9, 2023
 *      Author: joseph
 */

#ifndef EXTERNAL_EEPROM_EXEEPROM_INT_H_
#define EXTERNAL_EEPROM_EXEEPROM_INT_H_

void H_ExEEPROM_WriteByte(u16 Address, u8 Byte);

void H_ExEEPROM_WriteBuffer(u16 Address, u8* Buffer, u16 Count);

void H_ExEEPROM_ReadByte(u16 Address, u8* Byte);

void H_ExEEPROM_ReadBuffer(u16 Address, u8* Buffer, u16 Count);

#endif /* EXTERNAL_EEPROM_EXEEPROM_INT_H_ */
