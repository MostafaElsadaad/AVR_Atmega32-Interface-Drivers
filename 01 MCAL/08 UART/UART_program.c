/*
 * UART_program.c
 *
 * Created: 7/2/2023 12:01:42 PM
 *  Author: MostafaElSadaad
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Math.h"

#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"
#define	 F_CPU 8000000UL	//for proteus
#include <util/delay.h>

void UART_init()
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);						/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);	/* Use 8-bit char size */
	UBRRL = BAUD_PRESCALE;									/* Load lower 8-bits of the baud rate */
	UBRRH = (BAUD_PRESCALE >> 8);							/* Load upper 8-bits*/
}

void UART_init_INT()
{
	UCSRB |= (1 << RXEN) | (1 << RXCIE);					/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);	/* Use 8-bit char size */
	UBRRL = BAUD_PRESCALE;									/* Load lower 8-bits of the baud rate */
	UBRRH = (BAUD_PRESCALE >> 8);							/* Load upper 8-bits*/
}


u8 UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0);						/* Wait till data is received */
	return(UDR);											/* Return the byte */
}

void UART_TxChar(s8 ch)
{
	while (! (UCSRA & (1<<UDRE)));							/* Wait for empty transmit buffer */
	UDR = ch ;
}

void UART_SendString(s8 *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		_delay_ms(10);
		UART_TxChar(str[j]);
		j++;
	}
}

