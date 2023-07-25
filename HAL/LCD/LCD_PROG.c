/*
 * LCD_PROG.c
 *
 *  Created on: Feb 19, 2023
 *      Author: joseph
 */

#include <avr/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_INT.h"

#include "LCD_TYPES.h"
#include "LCD_CFG.h"
#include "LCD_PRIV.h"
#include "LCD_INT.h"


void H_LCD_void_Init()
{

#if LCD_MODE == _4BIT_MODE

	/*H_LCD_void_SendCommand(0b00100000);
	H_LCD_void_SendCommand(0b00100000);
	H_LCD_void_SendCommand(0b01000000);

	H_LCD_void_SendCommand(0b00000000);
	H_LCD_void_SendCommand(0b10000000);

	H_LCD_void_SendCommand(0b00000000);
	H_LCD_void_SendCommand(0b00010000);

	H_LCD_void_SendCommand(0b00000000);
	H_LCD_void_SendCommand(0b01110000);

	H_LCD_void_SendCommand(0b10000000);//Set DDRAM Address
	_delay_ms(2);*/

	H_LCD_void_SendCommand(0x02);		/* send for 4 bit initialization of LCD  */
	H_LCD_void_SendCommand(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	H_LCD_void_SendCommand(0x0c);              /* Display on cursor off*/
	H_LCD_void_SendCommand(0x06);              /* Increment cursor (shift cursor to right)*/
	H_LCD_void_SendCommand(0x01);              /* Clear display screen*/
	_delay_ms(2);


#elif LCD_MODE == _8BIT_MODE
		_delay_ms(35);
		H_LCD_void_SendCommand(LCD_FUNCTION_SET);
	    _delay_ms(1);
	    H_LCD_void_SendCommand(LCD_DISPLAY_ON);
	    _delay_ms(1);
	    H_LCD_void_SendCommand(LCD_CLEAR_DISPLAY);
	    _delay_ms(2);
	    H_LCD_void_SendCommand(LCD_ENTERY_SET);
#endif

}


static void H_LCD_void_LatchByte(u8 Data)
{
	//DIO_vid_SetPinValue(LCD_RW_PIN,0);//In FARES PCB it always low

#if LCD_MODE == _4BIT_MODE
	M_DIO_void_SetPinValue(LCD_D4_PIN, GET_BIT(Data,4));
	M_DIO_void_SetPinValue(LCD_D5_PIN, GET_BIT(Data,5));
	M_DIO_void_SetPinValue(LCD_D6_PIN, GET_BIT(Data,6));
	M_DIO_void_SetPinValue(LCD_D7_PIN, GET_BIT(Data,7));

	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_High);
	_delay_ms(1);
	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

	M_DIO_void_SetPinValue(LCD_D4_PIN, GET_BIT(Data,0));
	M_DIO_void_SetPinValue(LCD_D5_PIN, GET_BIT(Data,1));
	M_DIO_void_SetPinValue(LCD_D6_PIN, GET_BIT(Data,2));
	M_DIO_void_SetPinValue(LCD_D7_PIN, GET_BIT(Data,3));
	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_High);
	_delay_ms(1);
	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

#elif LCD_MODE == _8BIT_MODE
	M_DIO_void_SetPinValue(LCD_D0_PIN, GET_BIT(Data,0));
	M_DIO_void_SetPinValue(LCD_D1_PIN, GET_BIT(Data,1));
	M_DIO_void_SetPinValue(LCD_D2_PIN, GET_BIT(Data,2));
	M_DIO_void_SetPinValue(LCD_D3_PIN, GET_BIT(Data,3));
	M_DIO_void_SetPinValue(LCD_D4_PIN, GET_BIT(Data,4));
	M_DIO_void_SetPinValue(LCD_D5_PIN, GET_BIT(Data,5));
	M_DIO_void_SetPinValue(LCD_D6_PIN, GET_BIT(Data,6));
	M_DIO_void_SetPinValue(LCD_D7_PIN, GET_BIT(Data,7));
	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_High);

	_delay_ms(1);
	M_DIO_void_SetPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

#endif

}

void H_LCD_void_SendChar(u8 Data)
{
	M_DIO_void_SetPinValue(LCD_RS_PIN,DIO_High);

	H_LCD_void_LatchByte(Data);

}

void H_LCD_void_SendCommand(u8 Command)
{
	M_DIO_void_SetPinValue(LCD_RS_PIN,DIO_LOW);

	H_LCD_void_LatchByte(Command);

}

void H_LCD_void_SendString(u8* Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		H_LCD_void_SendChar(Str[i]);
		Str++;
	}
}

//need to change u16
void H_LCD_void_SendIntNum(s32 IntNumber)
{
	u16 u32IntNumber = 0;
	if(IntNumber > 0)
	{
		u32IntNumber = (u16)IntNumber;
	}
	else if(IntNumber<0)
	{
		u32IntNumber = (u16)IntNumber * -1;
		H_LCD_void_SendChar('-');
	}

	u8 str[100];
	itoa(u32IntNumber,str,10);//10 for decimal
	u8 index = 0;
	while(str[index] != '\0')
	{
		H_LCD_void_SendChar(str[index]);
		index++;
	}
}

void H_LCD_void_SendNumber(s32 copy_s32num)
{
	u8 str[20]={0};
	u8 i=0;
	u8 n_flag=0;
	u8 len=0;
	u8 temp=0;
	u8 last=0;
	if(copy_s32num == 0)
	{
		str[i]='0';
		i++;
	}
	else if(copy_s32num<0)
	{
		copy_s32num*=-1;
		n_flag=1;

	}
	while(copy_s32num)
	{
		str[i]=(copy_s32num%10)+'0';
		copy_s32num/=10;
		i++;
	}
	if(n_flag == 1)
	{
		str[i]='-';
		i++;
	}
	str[i]='\0';

	for(len=0;str[len];len++);
	last=len-1;
	for(i=0;i<len/2;i++)
	{
		temp=str[i];
		str[i]=str[last];
		str[last]=temp;
		last--;
	}
	for(i=0;str[i];i++)
	{
		H_LCD_void_SendChar(str[i]);
	}
}

void H_LCD_void_GotoXY(u8 Row, u8 Column)
{
	//0x80 for the first line
	//0xc0 for secod line
	if(Row == 0)
	{
		H_LCD_void_SendCommand(LCD_FIRST_LINE_ADDRESS + Column);
	}
	else if(Row == 1)
	{
		H_LCD_void_SendCommand(LCD_SECOND_LINE_ADDRESS + Column);
	}
}

void H_LCD_void_CreatCustomChar(const u8* ArrPattern, u8 CharLocation)
{
	if(CharLocation<8)
	{
		H_LCD_void_SendCommand(0x40 + (CharLocation*8));

		for(u8 i=0; i<8; i++)
		{
			H_LCD_void_SendChar(ArrPattern[i]);
		}
		H_LCD_void_GotoXY(0,0);//must set location to any place after make a custom character
	}

}

void H_LCD_void_DisplayCustomChar(u8 CharLocation)
{
	H_LCD_void_SendChar(CharLocation);
}
