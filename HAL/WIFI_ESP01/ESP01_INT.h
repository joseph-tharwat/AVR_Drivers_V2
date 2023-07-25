/*
 * ESP01_INT.h
 *
 *  Created on: Mar 5, 2023
 *      Author: joseph
 */

#ifndef WIFI_ESP01_ESP01_INT_H_
#define WIFI_ESP01_ESP01_INT_H_

#include "ESP01_TYPES.h"

void H_ESP01_void_Init();

void H_ESP01_void_SendCommand(u8* Command);

void H_ESP_EchoCancel();

void H_ESP_void_SetMode(ESP_Mode EspMode, u8* WifiName, u8* WifiPassword);

void H_ESP_void_InitializeTCP(u8* AddressIP, u16 PortNumber);

void H_ESP_StartReceiveData();

void H_ESP_void_SetModeStation();

void H_ESP_void_SetModeSoftAP();

void H_ESP_void_SetModeStationSoftAP();

void H_ESP_void_SendByte(u8 Data);

void H_ESP_void_SendString(u8* String);

void H_ESP_void_ReceiveByteSynchNonBlocking(u8* Data, u16 TimeMicroSec);

void H_ESP_void_ReceiveByteAsynchCallBack(void(* CallBackFuncPtr)());

void H_ESP_void_ReceiveStringSynchNonBlocking(u8* OutputString, u8 StringLength, u8 EndChar, u16 TimeOutMMiliSec);

EPS01_Receive_Status H_ESP_CheckIfReceivedData();

#endif /* WIFI_ESP01_ESP01_INT_H_ */
