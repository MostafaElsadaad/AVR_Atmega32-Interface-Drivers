/*
 * WDG_program.c
 *
 * Created: 6/26/2023 3:33:33 PM
 *  Author: MostafaElSadaad
 */ 

#include "WDG_private.h"
#include "WDG_interface.h"


void WDG_ON()
{
	/*
	Watchdog timer enables with typical timeout period 2.1 
	second.
	*/
	WDTCR = (1<<2)|(1<<1)|(1<<0);
}

void WDG_sleep(){
	
	WDTCR = (1<<3);
}

void WDG_OFF()
{
	/*
	This function use for disable the watchdog timer.
	*/
	WDTCR = (1<<4)|(1<<3);
	WDTCR = 0x00;
}