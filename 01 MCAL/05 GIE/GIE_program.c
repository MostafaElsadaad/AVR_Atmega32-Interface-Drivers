/*
 * GIE_program.c
 *
 * Created: 6/22/2023 3:09:54 PM
 *  Author: MostafaElSadaad
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_voidEnable()
{
	SET_bit(SREG , 7);
}

void GIE_voidDisable()
{
	CLR_bit(SREG , 7);
}