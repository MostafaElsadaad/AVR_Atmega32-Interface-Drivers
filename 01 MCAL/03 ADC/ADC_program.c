/*
 * ADC_program.c
 *
 * Created: 6/22/2023 3:59:45 PM
 *  Author: MostafaElSadaad
 */ 

#define  F_CPU 16000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include <util/delay.h>


void ADC_Init()
{
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
		//CLR_bit( SFIOR , 0 ); for interrupt
		//SET_bit( SFIOR , 1 );
		//CLR_bit( SFIOR , 2 );
	
}

u16 ADC_Read(u8 channel)
{
	u32 Ain,AinLow;
	//GIE_voidEnable();
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	SET_bit( ADCSRA , 6 );	/* Start conversion */
	while(GET_bit(ADCSRA,4) == 0 );	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	AinLow = (u16)ADCL;		/* Read lower byte*/
	Ain = (u16)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}

void ADC_voidInterrputEnable()
{

	
	SET_bit( ADCSRA , 3 );
	
}

void ADC_voidAutoTrigger()
{
	

	/****************************************************************/
	/** !comment : From Data Sheet : Starting conversion on positive*/
	/*			   edge when ADATE = 1						    	*/
	/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_bit( ADATE , 5 ); 			   **/

	SET_bit( ADCSRA , 5 );
	

	/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE
	CLR_bit( SFIOR , 0 );
	CLR_bit( SFIOR , 1 );
	CLR_bit( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_bit( SFIOR , 0 );
	CLR_bit( SFIOR , 1 );
	CLR_bit( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLR_bit( SFIOR , 0 );
	SET_bit( SFIOR , 1 );
	CLR_bit( SFIOR , 2 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_bit( SFIOR , 0 );
	SET_bit( SFIOR , 1 );
	CLR_bit( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLR_bit( SFIOR , 0 );
	CLR_bit( SFIOR , 1 );
	SET_bit( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_bit( SFIOR , 0 );
	CLR_bit( SFIOR , 1 );
	SET_bit( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLR_bit( SFIOR , 0 );
	SET_bit( SFIOR , 1 );
	SET_bit( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_bit( SFIOR , 0 );
	SET_bit( SFIOR , 1 );
	SET_bit( SFIOR , 2 );
	
	#endif
	/* End ( if ) condition for Macros */
	
}


static void (*ADCX) (void);

void ADC_INT_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		ADCX = addresscpy;
	}
}


void __vector_16(void) __attribute__(( signal , used ));


void __vector_16(void)
{

	ADCX();
	
}