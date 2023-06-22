/*
 * Keypad_program.c
 *
 * Created: 6/22/2023 2:12:29 PM
 *  Author: MostafaElSadaad
 */ 
#define  F_CPU 16000000UL
#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "Keypad_interface.h"


u8 keypad[4][4] = {	{'7','8','9','/'},
				  {'4','5','6','*'},
				  {'1','2','3','-'},
				  {' ','0','=','+'}};
	
u8 rowloc_pins[4] = {KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN,KEYPAD_ROW4_PIN};
u8 colloc_pins[4] = {KEYPAD_COL1_PIN,KEYPAD_COL2_PIN,KEYPAD_COL3_PIN,KEYPAD_COL4_PIN};
u8 colloc, rowloc;


void KEYPAD_INIT(){
	
	pinMode(KEYPAD_COL1_PIN,INPUT_PULLUP);
	pinMode(KEYPAD_COL2_PIN,INPUT_PULLUP);
	pinMode(KEYPAD_COL3_PIN,INPUT_PULLUP);
	pinMode(KEYPAD_COL4_PIN,INPUT_PULLUP);
	
	pinMode(KEYPAD_ROW1_PIN,OUTPUT);
	pinMode(KEYPAD_ROW2_PIN,OUTPUT);
	pinMode(KEYPAD_ROW3_PIN,OUTPUT);
	pinMode(KEYPAD_ROW4_PIN,OUTPUT);
	
	digitalWrite(KEYPAD_ROW1_PIN,HIGH);
	digitalWrite(KEYPAD_ROW2_PIN,HIGH);
	digitalWrite(KEYPAD_ROW3_PIN,HIGH);
	digitalWrite(KEYPAD_ROW4_PIN,HIGH);
	
}

u8 KeyFind(){ //bug : on holding it returns the same location in first row || EX: holding 1 gives 7 and holding a 5 gives 8
	
	for(rowloc = 0; rowloc<4;rowloc++){
		digitalWrite(rowloc_pins[rowloc],LOW);
		for (colloc = 0; colloc<4;colloc++)
		{
			if(digitalRead(colloc_pins[colloc])==LOW) return keypad[rowloc][colloc];
		}
		digitalWrite(rowloc_pins[rowloc],HIGH);
	}
	return 0;
}