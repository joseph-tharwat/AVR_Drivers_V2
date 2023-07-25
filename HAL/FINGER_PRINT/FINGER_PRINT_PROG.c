/*
 * FINGER_PRINT_PROG.c
 *
 *  Created on: Mar 12, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"

#include "UART_INT.h"

#include "FINGER_PRINT_TYPES.h"
#include "FINGER_PRINT_PRIV.h"
#include "FINGER_PRINT_INT.h"

void H_FP_Init()
{
	M_UART_Inite(UART_BAUD_57600, UART_8BIT_MODE, UART_PARITY_DISABLED, UART_STOP_1BIT);
}

static void H_FP_SendHeaderAndAddress()
{
	//Header
	M_UART_SendByte(FP_HEADER_UPPER_BYTE);
	M_UART_SendByte(FP_HEADER_LOWER_BYTE);
	//Module Address
	M_UART_SendByte(FP_ADDRESS_BYTE);
	M_UART_SendByte(FP_ADDRESS_BYTE);
	M_UART_SendByte(FP_ADDRESS_BYTE);
	M_UART_SendByte(FP_ADDRESS_BYTE);
}

FP_Confirmation_Code H_FP_HandShake()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(FP_HANDSHAKE_COMMAND);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x44);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte = '\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_CheckSensor()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(FP_CHECKSENSOR_COMMAND);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x3A);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_CollectFingerImage()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(FP_COLLECT_FINGER_IMAGE_COMMAND);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x05);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_GenerateCharacterFileFirstScan()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x04);

	//Instruction Code
	M_UART_SendByte(FP_GENERATE_CHARACTER_FILE_COMMAND);
	//CharBuffer1
	M_UART_SendByte(0x1);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x08);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_GenerateCharacterFileSecondScan()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x04);

	//Instruction Code
	M_UART_SendByte(FP_GENERATE_CHARACTER_FILE_COMMAND);
	//CharBuffer2
	M_UART_SendByte(0x2);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x09);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_FirstScan()
{
	FP_Confirmation_Code ConfirmationCode = H_FP_CollectFingerImage();
	if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
	{
		ConfirmationCode = H_FP_GenerateCharacterFileFirstScan();
	}
	return ConfirmationCode;
}

FP_Confirmation_Code H_FP_SecondScan()
{
	FP_Confirmation_Code ConfirmationCode = H_FP_CollectFingerImage();
	if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
	{
		ConfirmationCode = H_FP_GenerateCharacterFileSecondScan();
	}
	return ConfirmationCode;
}

FP_Confirmation_Code H_FP_GenerateTemplate()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(FP_GENERATE_TEMPLATE_COMMAND);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x09);

	//Wait to receive the Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_StoreTemplate(u8 PageID)
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x06);

	//Instruction Code
	M_UART_SendByte(FP_STORE_TEMPLATE_COMMAND);
	//CharBuffer1
	M_UART_SendByte(0x1);
	//PageID
	M_UART_SendByte(PageID);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(PageID + 0xE);

	//Wait to receive the Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_ScanAndStore(u8 PageID)
{
	FP_Confirmation_Code ConfirmationCode = H_FP_FirstScan();
	if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
	{
		ConfirmationCode = H_FP_SecondScan();
		if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
		{
			ConfirmationCode = H_FP_GenerateTemplate();
			if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
			{
				ConfirmationCode = H_FP_StoreTemplate(PageID);
			}
		}
	}
	return ConfirmationCode;

}

FP_Confirmation_Code H_FP_MatchTwoFingerTemplates()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(FP_MATCHING_TWO_FINGER_COMMAND);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x07);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_SearchFingerLibrary(u16 StartPageNumber,u16 SearchingNumbers)
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x08);

	//Instruction Code
	M_UART_SendByte(FP_SEARCH_FINGER_LIBRARY_COMMAND);
	//CharBuffer1
	M_UART_SendByte(0x1);
	//Start page number
	M_UART_SendByte((u8)((StartPageNumber & 0b1111111100000000)>>8));
	M_UART_SendByte((u8)(StartPageNumber));
	//Searching numbers
	M_UART_SendByte((u8)((SearchingNumbers & 0b1111111100000000)>>8));
	M_UART_SendByte((u8)(SearchingNumbers));

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x0E + StartPageNumber + SearchingNumbers);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_ScanAndSearch(u16 StartPageNumber,u16 SearchingNumbers)
{
	FP_Confirmation_Code ConfirmationCode = H_FP_FirstScan();
	if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
	{
		ConfirmationCode = H_FP_SearchFingerLibrary(StartPageNumber, SearchingNumbers);
	}
	return ConfirmationCode;
}

FP_Confirmation_Code H_FP_ReadTemplate(u8 PageID)
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x06);

	//Instruction Code
	M_UART_SendByte(0x07);
	//CharBuffer2
	M_UART_SendByte(0x2);
	//PageID
	M_UART_SendByte(PageID);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(PageID + 0x10);

	//Wait to receive the Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte= '\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}

FP_Confirmation_Code H_FP_ScanAndVerify(u8 PageID)
{
	FP_Confirmation_Code ConfirmationCode = H_FP_FirstScan();

	if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
	{
		ConfirmationCode = H_FP_ReadTemplate(PageID);
		if(ConfirmationCode == COMMAND_EXECUTION_COMPLETE)
		{
			ConfirmationCode = H_FP_MatchTwoFingerTemplates();
		}
	}
	return ConfirmationCode;
}

FP_Confirmation_Code H_FP_EmptyLibrary()
{
	H_FP_SendHeaderAndAddress();

	//PAckage Identifier
	M_UART_SendByte(FP_IDENTIFIER_COMMAND);

	//Package Length
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x03);

	//Instruction Code
	M_UART_SendByte(0x0d);

	//CheckSum
	M_UART_SendByte(0x00);
	M_UART_SendByte(0x11);

	//Receive Acknowledge
	u8 AcknowledgePackage[12];
	u8 Byte='\0';
	for(u8 i=0; i<12;i++)
	{
		if(M_UART_ReceiveByteSynchNonBlocking((AcknowledgePackage+i), 100000) == UART_RECEIVE_NOT_COMPLETE)
		{
			return	ERROR_WHEN_RECEIVING_DATA_PACKAGE;
		}
	}
	//Confirmation Response
	return AcknowledgePackage[9];
}
