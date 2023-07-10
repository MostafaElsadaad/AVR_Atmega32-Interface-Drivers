/*
 * UART_config.h
 *
 * Created: 7/2/2023 12:01:16 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define F_CPU 8000000UL		/* Define frequency here its 8MHz */
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)



#endif /* UART_CONFIG_H_ */