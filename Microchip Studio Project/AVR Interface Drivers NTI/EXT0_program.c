/*
 * EXT0_program.c
 *
 * Created: 6/22/2023 3:24:31 PM
 *  Author: MostafaElSadaad
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXT0_interface.h"
#include "EXT0_config.h"
#include "EXT0_private.h"

/*
To use EXT0

EXT0_voidInit();
GIE_voidEnable();
EXT0_voidEnable();

pinMode(PD2,INPUT_PULLUP);
EXT0_voidCallBack(&ISRFUNCTION);

*/

static void (*x) (void); //pointer to function for callback



void EXT0_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXT0_SENSE_MODE == IOC
	SET_bit(MCUCR , 0);
	CLR_bit(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == RISING
	SET_bit(MCUCR , 0);
	SET_bit(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == FALLING
	CLR_bit(MCUCR , 0);
	SET_bit(MCUCR , 1);
	
	#elif EXT0_SENSE_MODE == LOW_LEVEL
	CLR_bit(MCUCR , 0);
	CLR_bit(MCUCR , 1);
	
	#endif
	/* End ( if ) condition for Macros */

	/** disable EXT0 in initialization function  **/
	/** like : void EXT0_voidDisable(); 		  */
	CLR_bit(GICR , 6 );
	SET_bit(GIFR , 6 ) ;
	
}


void EXT0_voidEnable()
{
	
	SET_bit( GICR , 6 );
	
}

void EXT0_voidDisable()
{
	
	CLR_bit( GICR , 6 );
	
}


void EXT0_voidCallBack(void (*addresscpy)(void))
{
	if(addresscpy != NULL)
	{
		x = addresscpy;
	}
}


void EXT0_voidSetSignalch(u8 SenseCpy)
{
	
	if (SenseCpy == IOC)
	{
		SET_bit(MCUCR , 0);
		CLR_bit(MCUCR , 1);
	}
	else if (SenseCpy == RISING)
	{
		SET_bit(MCUCR , 0);
		SET_bit(MCUCR , 1);
	}
	else if (SenseCpy == FALLING)
	{
		CLR_bit(MCUCR , 0);
		SET_bit(MCUCR , 1);
	}
	else if (SenseCpy == LOW_LEVEL)
	{
		CLR_bit(MCUCR , 0);
		CLR_bit(MCUCR , 1);
	}
	
	
}



void __vector_1(void) __attribute__(( signal , used ));


void __vector_1(void)
{
	x();
	
}