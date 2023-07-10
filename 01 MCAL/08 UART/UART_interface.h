/*
 * UART_interface.h
 *
 * Created: 7/2/2023 12:01:26 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init();
u8 UART_RxChar();
void UART_TxChar(s8 ch);
void UART_SendString(s8 *str);


#endif /* UART_INTERFACE_H_ */