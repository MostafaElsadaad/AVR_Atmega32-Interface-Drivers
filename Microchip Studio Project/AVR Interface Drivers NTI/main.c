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
	ADC_Init();
	LCD_INIT();
	TIMER0_void_Init();
	pinMode(PB3,OUTPUT);
	u16 adc_val=0;
	u16 brightness=0;
	
	u8 Sleeping[8] = { 0x0E, 0x0E, 0x04, 0x04, 0x0E, 0x15, 0x0A, 0x11};
	u8 Idle[8] = { 0x0E, 0x0E, 0x04, 0x04, 0x1F, 0x04, 0x0A, 0x11};
	u8 Active[8] = { 0x0E, 0x0E, 0x04, 0x15, 0x0E, 0x04, 0x0A, 0x11};
	
	LCD_Custom_Char(0, Active);
	LCD_Custom_Char(1, Idle);
	LCD_Custom_Char(2, Sleeping);
	
    while (1) 
    {
	adc_val = ADC_Read(0);
	
	brightness = 100 - map(adc_val,30,900,0,100);
	lcdGoToXY(0,0);
	lcdWriteText("Brightness=");
	LCD_voidWriteNumber(brightness,0,11);
	
	if(brightness>9){
		lcdGoToXY(0,13);
	}
	else{
		lcdGoToXY(0,12);
	}
	
	Send_Data('%');

	if(brightness>25 && brightness<75){
		lcdGoToXY(1,0);
		Send_Data(1);
	}
	else if(brightness>=75){
		lcdGoToXY(1,0);
		Send_Data(0);
	}
	else if(brightness<=25){
		lcdGoToXY(1,0);
		Send_Data(2);
	}
	
	TIMER0_void_SetCompareVal(brightness);

	_delay_ms(60);
	LCD_CLR();


	}
	
	
}

