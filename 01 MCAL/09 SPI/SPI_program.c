/*
 * SPI_program.c
 *
 * Created: 7/2/2023 11:59:21 PM
 *  Author: MostafaElSadaad
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Math.h"
#include "DIO_interface.h"

#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

#define	 F_CPU 8000000UL	//for Proteus
#include <util/delay.h>





void SPI_Init()					/* SPI MASTER/SLAVE Initialize function */
{
	#if SPI_MASTER_SLAVE_MODE	==	SPI_MASTER
	
	pinMode(MOSI,OUTPUT);
	pinMode(SCK,OUTPUT);
	pinMode(SS,OUTPUT);
	
	pinMode(MISO,INPUT);					/* Make MISO pin as input pin */
	digitalWrite(SS,HIGH);					/* Make high on SS pin */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI in master mode with Fosc/16 */
	SPSR &= ~(1<<SPI2X);					/* Disable speed doubler */
	
	#elif	SPI_MASTER_SLAVE_MODE	==	SPI_SLAVE

	/* Make MOSI, SCK, SS as input pins */
	pinMode(MOSI,INPUT);
	pinMode(SCK,INPUT);
	pinMode(SS,INPUT);
	
	pinMode(MISO,OUTPUT);					/* Make MISO pin as Output pin */
	
	SPCR = (1<<SPE);						/* Enable SPI in slave mode */
	
	#endif
	
}



void SPI_Send(u8 data)		/* SPI MASTER write data function */
{
	u8 flush_buffer;
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	flush_buffer = SPDR;		/* Flush received data */
	/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}


u8 SPI_Recieve()				/* SPI MASTER/SLAVE read data function */
{
	#if SPI_MASTER_SLAVE_MODE ==	SPI_MASTER
	SPDR = 0xFF;
	#endif
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}t


void SPI_SendString(s8 *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		_delay_ms(10);
		SPI_Send(str[j]);
		j++;
	}
}

