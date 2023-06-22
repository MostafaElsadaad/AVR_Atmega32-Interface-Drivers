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
	pinMode(PB7,OUTPUT);
	u16 adc_val=0;
	u16 voltpoint=0;
	float volt=0;
	u8 Vin = 5;
	u16 vout = 0;
	u16 r1 = 10000; // known resistor
	u16 r2 = 0;
	u16 buffer = 0;
	
    while (1) 
    {
	adc_val = ADC_Read(0); // ADC0 is connected to a voltage divider with a known resistor and unknown resistor
	buffer = adc_val * Vin;
	vout = buffer/1024;
	buffer = (Vin/vout) - 1;
	r2 = r1 * buffer;
	
	
	LCD_voidWriteNumber(r2,0,0);
	

	
	_delay_ms(60);
	LCD_CLR();

	}
	
	
}

