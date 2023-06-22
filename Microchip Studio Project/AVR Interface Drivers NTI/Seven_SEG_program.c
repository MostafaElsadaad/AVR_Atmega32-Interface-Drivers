/*
 * Seven_SEG_program.c
 *
 * Created: 6/22/2023 12:23:10 PM
 *  Author: MostafaElSadaad
 */ 


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"
#include "Seven_SEG_config.h"
#include "Seven_SEG_Interface.h"

void SSD_INIT(){
	
	pinMode(PB0,OUTPUT);
	pinMode(PB1,OUTPUT);
	pinMode(PB2,OUTPUT);
	pinMode(PB4,OUTPUT);

	pinMode(PA3,OUTPUT);
	pinMode(PA2,OUTPUT);
	pinMode(PB5,OUTPUT);
	pinMode(PB6,OUTPUT);
	
	digitalWrite(PA3,HIGH);
	digitalWrite(PA2,HIGH);
	digitalWrite(PB5,HIGH);
	digitalWrite(PB6,HIGH);
}


void WriteSSD(u8 num,u8 display){

	digitalWrite(PA3,HIGH);
	digitalWrite(PA2,HIGH);
	digitalWrite(PB5,HIGH);
	digitalWrite(PB6,HIGH);
	
	digitalWrite(display,LOW);

	digitalWrite(SSDA,GET_bit(num,0));
	digitalWrite(SSDB,GET_bit(num,1));
	digitalWrite(SSDC,GET_bit(num,2));
	digitalWrite(SSDD,GET_bit(num,4));

}
