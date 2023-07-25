/*
 * MOTOR_INT.h
 *
 *  Created on: Mar 4, 2023
 *      Author: joseph
 */

#ifndef HAL_MOTOR_DRIVER_MOTOR_INT_H_
#define HAL_MOTOR_DRIVER_MOTOR_INT_H_

#include "MOTOR_TYPES.h"

void H_MOTOR_void_Init();

void H_MOTOR_void_SetDirection(MOTOR_Direction Direction);

void H_MOTOR_void_SetFrequancy(u16 Frequancy, u8 Duty);

void H_MOTOR_void_SetDuty(u16 Frequancy,u8 Duty);


#endif /* HAL_MOTOR_DRIVER_MOTOR_INT_H_ */
