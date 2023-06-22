/*
 * AVR Interface Drivers NTI.c
 *
 * Created: 6/19/2023 8:59:28 PM
 * Author : MostafaElSadaad
 */ 

#define  F_CPU 16000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Seven_SEG_Interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "GIE_interface.h"
#include "EXT0_interface.h"
#include "ADC_interface.h"
#include "TIMER0_interface.h"
#include "Math.h"
#include <util/delay.h>


u16 readTemp(u16 adc_readd){
	f32 celsius;
	celsius = (adc_readd/2.048);
	celsius = celsius * 100;
	return (u16)celsius;
}

int main(void)
{
	/* Initializations, Declarations and configurations */
	ADC_Init();
	LCD_INIT();
	pinMode(PB3,OUTPUT);
	u16 adc_val=0;
	u16 temp;
	u16 temppoint;
	
	
	
    while (1) 
    {
	adc_val = ADC_Read(1);
	temp = readTemp(adc_val);
	temppoint = temp % 100;
	temp /=100;
	
	lcdGoToXY(0,0);
	lcdWriteText("Temperature:");
	LCD_voidWriteNumber(temp,1,0);
	lcdGoToXY(1,2);
	Send_Data('.');
	LCD_voidWriteNumber(temppoint,1,3);
	lcdGoToXY(1,5);
	lcdWriteText("C");
	
	_delay_ms(60);
	LCD_CLR();

	}
	
	
}

