/*
 * DIO_program.c
 *
 * Created: 6/19/2023 11:35:19 PM
 *  Author: MostafaElSadaad
 */ 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

u8 pinMode(u8 pin,u8 direction){  // Sets Pin Direction

	if(direction == INPUT)
		switch(pin){
			case PA0 ... PA7: CLR_bit(DDRA,pin);		 break;
			case PB0 ... PB7: CLR_bit(DDRB,(pin-PB0));	 break;
			case PC0 ... PC7: CLR_bit(DDRC,(pin-PC0));	 break;
			case PD0 ... PD7: CLR_bit(DDRD,(pin-PD0));	 break;
		}
		
	else if(direction == OUTPUT){
		switch(pin){
			case PA0 ... PA7: SET_bit(DDRA,pin);	   break;
			case PB0 ... PB7: SET_bit(DDRB,(pin-PB0)); break;
			case PC0 ... PC7: SET_bit(DDRC,(pin-PC0)); break;
			case PD0 ... PD7: SET_bit(DDRD,(pin-PD0)); break;
		}
	}
	else if(direction == INPUT_PULLUP){
		switch(pin){
			case PA0 ... PA7: CLR_bit(DDRA,pin);		 digitalWrite(pin,HIGH);	 break;
			case PB0 ... PB7: CLR_bit(DDRB,(pin-PB0));   digitalWrite(pin,HIGH);	 break;
			case PC0 ... PC7: CLR_bit(DDRC,(pin-PC0));   digitalWrite(pin,HIGH);	 break;
			case PD0 ... PD7: CLR_bit(DDRD,(pin-PD0));   digitalWrite(pin,HIGH);	 break;
		}
	}
	else{
		//for error handling later
	}
	
	return 0;
}


u8 digitalWrite(u8 pin,u8 value){  // Sets Pin Value

	if(value == LOW)
	switch(pin){
		case PA0 ... PA7: CLR_bit(PORTA,pin);		break;
		case PB0 ... PB7: CLR_bit(PORTB,(pin-PB0)); break;
		case PC0 ... PC7: CLR_bit(PORTC,(pin-PC0)); break;
		case PD0 ... PD7: CLR_bit(PORTD,(pin-PD0)); break;
		default: break;
	}
	
	else if(value == HIGH){
		switch(pin){
		case PA0 ... PA7: SET_bit(PORTA,pin);	    break;
		case PB0 ... PB7: SET_bit(PORTB,(pin-PB0)); break;
		case PC0 ... PC7: SET_bit(PORTC,(pin-PC0)); break;
		case PD0 ... PD7: SET_bit(PORTD,(pin-PD0)); break;
		default: break;
		}
	}
	
	else{
		//for error handling later
	}
	
	return 0;
}

u8 digitalRead(u8 pin){
	u8 value=0;
	
	switch(pin){
		case PA0 ... PA7: value = GET_bit(PINA,pin);	   break;
		case PB0 ... PB7: value = GET_bit(PINB,(pin-PB0)); break;
		case PC0 ... PC7: value = GET_bit(PINC,(pin-PC0)); break;
		case PD0 ... PD7: value = GET_bit(PIND,(pin-PD0)); break;
		default: break;
	}
	
	
	return value;
}
