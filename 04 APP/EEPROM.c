/*
 * AVR Interface Drivers NTI.c
 *
 * Created: 6/19/2023 8:59:28 PM
 * Author : MostafaElSadaad
 */ 

#define  F_CPU 16000000UL
//#define	 F_CPU 8000000UL	//for proteus
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
#include "TIMER0_private.h"
#include "Math.h"
#include "WDG_interface.h"
#include "UART_interface.h"
#include "SPI_interface.h"
#include <util/delay.h>






int main(void)

{

	u8 R;

	pinMode(PA7,OUTPUT);

	I2C_Init();

	while(1)

	{

		EEPROM_Write(0xE0,0x00);

		_delay_ms(1000); // allowing the eeprom to finish its writing cycle

		EEPROM_Read(0x00,&R);

		if (R==0xE0)

		{

			digitalWrite(PA7,HIGH);

		}

	}

}





