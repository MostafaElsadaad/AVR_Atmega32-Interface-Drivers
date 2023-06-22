/*
 * LCD_program.c
 *
 * Created: 6/22/2023 1:47:35 PM
 *  Author: MostafaElSadaad
 */ 

#define  F_CPU 16000000UL
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include <stdlib.h>

void LCD_INIT(){
	pinMode(RS_PIN,OUTPUT);
	pinMode(EN_PIN,OUTPUT);

	pinMode(DATA_PIN4,OUTPUT);
	pinMode(DATA_PIN5,OUTPUT);
	pinMode(DATA_PIN6,OUTPUT);
	pinMode(DATA_PIN7,OUTPUT);


	_delay_ms(40);
	Send_Command(0x33);
	_delay_ms(10);
	Send_Command(0x32);
	_delay_ms(10);
	Send_Command(0x28);
	Send_Command(0x0c);
	LCD_CLR();

}


void write4bit(u8 data){
	digitalWrite(DATA_PIN4,GET_bit(data,4));
	digitalWrite(DATA_PIN5,GET_bit(data,5));
	digitalWrite(DATA_PIN6,GET_bit(data,6));
	digitalWrite(DATA_PIN7,GET_bit(data,7));
	

	digitalWrite(EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(EN_PIN,LOW);
	
	digitalWrite(DATA_PIN4,GET_bit(data,0));
	digitalWrite(DATA_PIN5,GET_bit(data,1));
	digitalWrite(DATA_PIN6,GET_bit(data,2));
	digitalWrite(DATA_PIN7,GET_bit(data,3));

	
	digitalWrite(EN_PIN,HIGH);
	_delay_ms(2);
	digitalWrite(EN_PIN,LOW);
	
}

void Send_Command(u8 Command){

	digitalWrite(RS_PIN,LOW);
	digitalWrite(EN_PIN,LOW);
	
	write4bit(Command);

}

void Send_Data(u8 Data){
	
	digitalWrite(RS_PIN,HIGH);
	digitalWrite(EN_PIN,LOW);

	write4bit(Data);
	
}

void lcdWriteText(u8 * text)
{
	
	//Send_Data(text);

	while( *text)
	{
		digitalWrite(RS_PIN,HIGH);
		Send_Data(*text++);
	}
}


void lcdGoToXY(u8 x, u8 y)
{
	char addr = 0;
	switch(x)
	{
		case 0: addr = 0x00; break; //Starting address of 1st line
		case 1: addr = 0x40; break; //Starting address of 2nd line
		case 2: addr = 0x14; break; //Starting address of 3rd line
		case 3: addr = 0x54; break; //Starting address of 4th line
		default: ;
	}
	
	addr +=y;
	
	lcdGoToAddr(addr);
}


void lcdGoToAddr(u8 addr)
{
	char cmd = 0x80 | addr;
	Send_Command(cmd);
}

void LCD_Custom_Char (u8 loc, u8 *msg)
{
	unsigned char i;
	if(loc<8)
	{
		Send_Command(64 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		Send_Data(msg[i]);
	}
}




void LCD_CLR(){
	Send_Command(0x01);	/* clear display */
	Send_Command(0x80);
}


void LCD_voidWriteNumber(u32 COPY_u32Number,u8 COPY_u8XPos,u8 COPY_u8YPos)
{
	if(COPY_u32Number == 0){
		Send_Data('0');
		return;
	}
	u8 Local_u8digit = 0;
	u8 Local_u8NumOfDigits =0;
	u32 copy = COPY_u32Number;
	while (copy != 0)
	{
		copy = copy/10;
		Local_u8NumOfDigits++;
	}
	Local_u8NumOfDigits--;
	while (COPY_u32Number != 0)
	{
		Local_u8digit = COPY_u32Number %10;
		COPY_u32Number = COPY_u32Number /10;

		switch (Local_u8digit)
		{
			case 0 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('0');
			Local_u8NumOfDigits--;
			break;
			case 1 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('1');
			Local_u8NumOfDigits--;
			break;
			case 2 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('2');
			Local_u8NumOfDigits--;
			break;
			case 3 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('3');
			Local_u8NumOfDigits--;
			break;
			case 4 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('4');
			Local_u8NumOfDigits--;
			break;
			case 5 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('5');
			Local_u8NumOfDigits--;
			break;

			case 6 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('6');
			Local_u8NumOfDigits--;
			break;

			case 7 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('7');
			Local_u8NumOfDigits--;
			break;

			case 8 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('8');
			Local_u8NumOfDigits--;
			break;
			case 9 :
			lcdGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			Send_Data('9');
			Local_u8NumOfDigits--;
			break;
		}
	}
}