/*
 * MCU_HW.h
 *
 *  Created on: Feb 18, 2023
 *      Author: joseph
 */

#ifndef MCU_HW_H_
#define MCU_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*DIO Registers*/
#define PORTA_REG   *((volatile u8*)0x3B)
#define PORTB_REG	*((volatile u8*)0x38)
#define PORTC_REG	*((volatile u8*)0x35)
#define PORTD_REG	*((volatile u8*)0x32)

#define DDRA_REG	*((volatile u8*)0x3A)
#define DDRB_REG	*((volatile u8*)0x37)
#define DDRC_REG	*((volatile u8*)0x34)
#define DDRD_REG	*((volatile u8*)0x31)

#define PINA_REG	*((volatile u8*)0x39)
#define PINB_REG	*((volatile u8*)0x36)
#define PINC_REG	*((volatile u8*)0x33)
#define PIND_REG	*((volatile u8*)0x30)
//////////////////////////////////////////////////////////////////////////////////////

/*GIE Registers*/
# define SREG 		*((volatile u8*)0x5F)
#define  GIE_BIT 	7
////////////////////////////////////////////////////////////////////////////////////////

/*External Interrupt Registers*/
#define MCUCR				*((volatile u8*)0x55)
#define MCUCR_ISC00_BIT		0
#define MCUCR_ISC01_BIT		1
#define MCUCR_ISC10_BIT		2
#define MCUCR_ISC11_BIT		3

#define GICR 				*((volatile u8*)0x5B)
#define GICR_INT2_BIT		5
#define GICR_INT0_BIT		6
#define GICR_INT1_BIT		7

#define MCUCSR				*((volatile u8*)0x54)
#define MCUCSR_ISC2_BIT		6
///////////////////////////////////////////////////////////////////////////////////////

/*Timer0 Registers*/
//Timer/Counter Control Register
#define TCCR0 		*((volatile u8*)0x53)
#define TCCR0_FOC0_BIT		7
#define TCCR0_WGM00_BIT		6
#define TCCR0_COM01_BIT		5
#define TCCR0_COM00_BIT		4
#define TCCR0_WGM01_BIT		3
#define TCCR0_CS02_BIT		2
#define TCCR0_CS01_BIT		1
#define TCCR0_CS00_BIT		0

//Timer/Counter Register
#define TCNT0 		*((volatile u8*)0x52)

//Output Compare Register
#define OCR0 		*((volatile u8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile u8*)0x59)
#define TIMSK_OCIE0_BIT		1
#define TIMSK_TOIE0_BIT		0
////////////////////////////////////////////////////////////////////////

/*TIMER1 Registers*/
#define TCCR1A				*((volatile u8*)0x4F)
#define TCCR1A_WGM10_BIT	0
#define TCCR1A_WGM11_BIT	1
#define TCCR1A_FOC1A_BIT	2
#define TCCR1A_FOC1B_BIT	3
#define TCCR1A_COM1B0_BIT	4
#define TCCR1A_COM1B1_BIT	5
#define TCCR1A_COM1A0_BIT	6
#define TCCR1A_COM1A1_BIT	7

#define TCCR1B				*((volatile u8*)0x4E)
#define TCCR1B_CS10_BIT		0
#define TCCR1B_CS11_BIT		1
#define TCCR1B_CS12_BIT		2
#define TCCR1B_WGM12_BIT	3
#define TCCR1B_WGM13_BIT	4
#define TCCR1B_ICES1_BIT	6
#define TCCR1B_ICNC1_BIT	7

#define TCNT1L				*((volatile u8*)0x4C)
#define TCNT1H				*((volatile u8*)0x4D)

#define OCR1AL				*((volatile u8*)0x4A)
#define OCR1AH				*((volatile u8*)0x4B)

#define OCR1BL				*((volatile u8*)0x48)
#define OCR1BH				*((volatile u8*)0x49)

#define ICR1L				*((volatile u8*)0x46)
#define ICR1H				*((volatile u8*)0x47)

#define TIMSK				*((volatile u8*)0x59)
#define TIMSK_TOIE1_BIT			2
#define TIMSK_OCIE1B_BIT		3
#define TIMSK_OCIE1A_BIT		4
#define TIMSK_TICIE1_BIT		5

#define TIFR				*((volatile u8*)0x58)
///////////////////////////////////////////////////////////////

/*ADC Registers*/
#define ADMUX 				*((volatile u8*)0x27)

#define ADCSRA 				*((volatile u8*)0x26)

#define ADCH 				*((volatile u8*)0x25)
#define ADCL 				*((volatile u8*)0x24)
#define ADCLH				*((volatile u16*)0x24)

#define SFIOR				*((volatile u8*)0x50)
///////////////////////////////////////////////////////////////

/*UART Registers*/
#define UDR  	*((volatile u8*)(0x2C))

#define UCSRA  	*((volatile u8*)(0x2B))
#define UCSRA_RXC_BIT	7
#define UCSRA_TXC_BIT	6
#define UCSRA_UDRE_BIT	5
#define UCSRA_FE_BIT	4
#define UCSRA_DOR_BIT	3
#define UCSRA_PE_BIT	2
#define UCSRA_U2X_BIT	1
#define UCSRA_MPCM_BIT	0

#define UCSRB  				*((volatile u8*)(0x2A))
#define UCSRB_RXCIE_BIT		7
#define UCSRB_TXCIE_BIT		6
#define UCSRB_UDRIE_BIT		5
#define UCSRB_RXEN_BIT		4
#define UCSRB_TXEN_BIT		3
#define UCSRB_UCSZ2_BIT		2
#define UCSRB_RXB8_BIT		1
#define UCSRB_TXB8_BIT		0

#define UCSRC_UBRRH  		*((volatile u8*)(0x40))
#define UCSRC_URSEL_BIT		7		//1 to use as UCSRC and 0 to use as UBRRH
#define UCSRC_UMSEL_BIT		6
#define UCSRC_UPM1_BIT		5
#define UCSRC_UPM0_BIT		4
#define UCSRC_USBS_BIT		3
#define UCSRC_UCSZ1_BIT		2
#define UCSRC_UCSZ0_BIT		1
#define UCSRC_UCPOL_BIT		0

#define UBRRL  	*((volatile u8*)(0x29))
//////////////////////////////////////////////////////////////

/*SPI Registers*/
//SPI Control Register
#define SPCR   			(*((volatile u8 *)0x2D))
#define SPCR_SPIE_BIT 	7  //SPI Interrupt Enable
#define SPCR_SPE_BIT  	6  //SPI Enable

#define SPCR_SPR1_BIT 	1  //SPI Clock Rate Select
#define SPCR_SPR0_BIT	 0  //SPI Clock Rate Select

//SPI Status Register
#define SPSR   (*((volatile u8 *)0x2E))
#define SPSR_SPIF_BIT	  7  //SPI Interrupt Flag
#define SPSR_SPI2X_BIT	 	0  //Double SPI Speed Bit and used with SPR1 and SPR0 to select clock rate

//SPI Data Register
#define SPDR  (*((volatile u8 *)0x2F))
///////////////////////////////////////////////////////////////

/*I2c Registers*/
#define TWBR            *((volatile u8*)(0x20))

#define TWCR            *((volatile u8*)(0x56))
#define TWCR_TWINT_BIT     7
#define TWCR_TWEA_BIT      6
#define TWCR_TWSTA_BIT     5
#define TWCR_TWSTO_BIT     4
#define TWCR_TWWC_BIT      3
#define TWCR_TWEN_BIT      2
#define TWCR_TWIE_BIT      0

#define TWSR            *((volatile u8*)(0x21))
#define TWSR_TWPS0_BIT  0
#define TWSR_TWPS1_BIT  1
#define TWSR_TWS3_BIT   3
#define TWSR_TWS4_BIT   4
#define TWSR_TWS5_BIT   5
#define TWSR_TWS6_BIT   6
#define TWSR_TWS7_BIT   7

#define TWDR            *((volatile u8*)(0x23))
#define TWDR_TWD0_BIT   0

#define TWAR             *((volatile u8*)(0x22))
#define TWAR_TWGCE_BIT


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

#endif /* MCU_HW_H_ */
