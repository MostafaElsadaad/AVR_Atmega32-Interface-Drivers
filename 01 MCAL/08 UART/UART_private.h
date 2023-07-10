/*
 * UART_private.h
 *
 * Created: 7/2/2023 12:00:53 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_



#define UCSRB	 (*(volatile u8*)0x2A)
#define UCSRC	 (*(volatile u8*)0x40)
#define UBRRH	 (*(volatile u8*)0x40)
#define UBRRL	 (*(volatile u8*)0x29)
#define UCSRA	 (*(volatile u8*)0x2B)
#define UDR		 (*(volatile u8*)0x2C)


#define	RXEN	4
#define	TXEN	3
#define	URSEL	7
#define	TXEN	3
#define	UCSZ0	1
#define	UCSZ1	2
#define RXC		7
#define UDRE    5
#define RXCIE	7






#endif /* UART_PRIVATE_H_ */