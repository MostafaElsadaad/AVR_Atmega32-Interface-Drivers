/*
 * DIO_interface.h
 *
 * Created: 6/19/2023 11:27:10 PM
 *  Author: MostafaElSadaad
 */ 
#include "STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 10
#define PB1 11
#define PB2 12
#define PB3 13
#define PB4 14
#define PB5 15
#define PB6 16
#define PB7 17

#define PC0 20
#define PC1 21
#define PC2 22
#define PC3 23
#define PC4 24
#define PC5 25
#define PC6 26
#define PC7 27

#define PD0 30
#define PD1 31
#define PD2 32
#define PD3 33
#define PD4 34
#define PD5 35
#define PD6 36
#define PD7 37

#define LOW	 0
#define HIGH 1

#define INPUT  0
#define OUTPUT 1
#define INPUT_PULLUP 3

u8 pinMode(u8 pin,u8 direction);
u8 digitalWrite(u8 pin,u8 value);
u8 digitalRead(u8 pin);


#endif /* DIO_INTERFACE_H_ */