/*
 * PB_PROG.c
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_INT.h"

#include "PB_TYPES.h"
#include "PB_PRIV.h"
#include "PB_CFG.h"
#include "PB_INT.h"

PB_STATE H_PB_u8_ReadButton(PB_ID ButtonId)
{
	static u8 DepouncingCounter1 = 0;
	static u8 DepouncingCounter2 = 0;
	static u8 DepouncingCounter3 = 0;
	static u8 DepouncingCounter4 = 0;

	PB_STATE ButtonValue = PB_UNPRESSED;

		switch(ButtonId)
		{
		case PB1:
#if(PB_1_TYPE == PB_ACTIVELOW)
			{
				ButtonValue = !M_DIO_u8_GetPinValue(PB_1_PIN);
				if(ButtonValue == PB_PRESSED)
				{
					if(DepouncingCounter1 >= PB_DEBOUNCING_LIMIT)
					{
						DepouncingCounter1 = 0;
						return ButtonValue;
					}
					else
					{
						return PB_UNPRESSED;
					}
				}
				else if(ButtonValue == PB_UNPRESSED)
				{
					DepouncingCounter1++;
					return ButtonValue;
				}

			}
#elif(PB_1_TYPE == PB_ACTIVEHIGH)
				{
					ButtonValue = M_DIO_u8_GetPinValue(PB_1_PIN);
					if(ButtonValue == PB_PRESSED)
					{
						if(DepouncingCounter1 >= PB_DEBOUNCING_LIMIT)
						{
							DepouncingCounter1 = 0;
							return ButtonValue;
						}
						else
						{
							return PB_UNPRESSED;
						}
					}
					else if(ButtonValue == PB_UNPRESSED)
					{
						DepouncingCounter1++;
						return ButtonValue;
					}
				}
#endif
		break;
		case PB2:
#if(PB_2_TYPE == PB_ACTIVELOW)
			{
				ButtonValue = !M_DIO_u8_GetPinValue(PB_2_PIN);
				if(ButtonValue == PB_PRESSED)
				{
					if(DepouncingCounter2 >= PB_DEBOUNCING_LIMIT)
					{
						DepouncingCounter2 = 0;
						return ButtonValue;
					}
					else
					{
						return PB_UNPRESSED;
					}
				}
				else if(ButtonValue == PB_UNPRESSED)
				{
					DepouncingCounter2++;
					return ButtonValue;
				}
			}

#elif(PB_2_TYPE == PB_ACTIVEHIGH)
				ButtonValue = M_DIO_u8_GetPinValue(PB_2_PIN);
				if(ButtonValue == PB_PRESSED)
				{
					if(DepouncingCounter2 >= PB_DEBOUNCING_LIMIT)
					{
						DepouncingCounter2 = 0;
						return ButtonValue;
					}
					else
					{
						return PB_UNPRESSED;
					}
				}
				else if(ButtonValue == PB_UNPRESSED)
				{
					DepouncingCounter2++;
					return ButtonValue;
				}
#endif
		break;
		case PB3:
#if(PB_3_TYPE == PB_ACTIVELOW)
				{
					ButtonValue = !M_DIO_u8_GetPinValue(PB_3_PIN);
					if(ButtonValue == PB_PRESSED)
					{
						if(DepouncingCounter2 >= PB_DEBOUNCING_LIMIT)
						{
							DepouncingCounter3 = 0;
							return ButtonValue;
						}
						else
						{
							return PB_UNPRESSED;
						}
					}
					else if(ButtonValue == PB_UNPRESSED)
					{
						DepouncingCounter3++;
						return ButtonValue;
					}
				}
#elif(PB_3_TYPE == PB_ACTIVEHIGH)
				{
					ButtonValue = M_DIO_u8_GetPinValue(PB_3_PIN);
					if(ButtonValue == PB_PRESSED)
					{
						if(DepouncingCounter3 >= PB_DEBOUNCING_LIMIT)
						{
							DepouncingCounter3 = 0;
							return ButtonValue;
						}
						else
						{
							return PB_UNPRESSED;
						}
					}
					else if(ButtonValue == PB_UNPRESSED)
					{
						DepouncingCounter3++;
						return ButtonValue;
					}
				}
#endif
		break;
		case PB4:
#if(PB_4_TYPE == PB_ACTIVELOW)
				{
					ButtonValue = !M_DIO_u8_GetPinValue(PB_4_PIN);
					if(ButtonValue == PB_PRESSED)
					{
						if(DepouncingCounter4 >= PB_DEBOUNCING_LIMIT)
						{
							DepouncingCounter4 = 0;
							return ButtonValue;
						}
						else
						{
							return PB_UNPRESSED;
						}
					}
					else if(ButtonValue == PB_UNPRESSED)
					{
						DepouncingCounter4++;
						return ButtonValue;
					}

				}
#elif(PB_4_TYPE == PB_ACTIVEHIGH)
				{
					ButtonValue = M_DIO_u8_GetPinValue(PB_4_PIN);
					if(ButtonValue == PB_PRESSED)
					{
						if(DepouncingCounter4 >= PB_DEBOUNCING_LIMIT)
						{
							DepouncingCounter4 = 0;
							return ButtonValue;
						}
						else
						{
							return PB_UNPRESSED;
						}
					}
					else if(ButtonValue == PB_UNPRESSED)
					{
						DepouncingCounter4++;
						return ButtonValue;
					}
				{
#endif
		break;
		}

	return ButtonValue;
}

