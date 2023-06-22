/*
 * TIMER0_program.c
 *
 * Created: 6/22/2023 4:58:46 PM
 *  Author: MostafaElSadaad
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Math.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_void_Init(void)
{
	#if(TIMER0_MODE == TIMER0_NORMAL)
	CLR_bit(TCCR0 , 6);
	CLR_bit(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
	CLR_bit(TCCR0 , 6);
	SET_bit(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
	SET_bit(TCCR0 , 6);
	SET_bit(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
	SET_bit(TCCR0 , 6);
	CLR_bit(TCCR0 , 3);
	
	#endif
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
	SET_bit(TCCR0 , 0);
	CLR_bit(TCCR0 , 1);
	CLR_bit(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
	CLR_bit(TCCR0 , 0);
	SET_bit(TCCR0 , 1);
	CLR_bit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
	SET_bit(TCCR0 , 0);
	SET_bit(TCCR0 , 1);
	CLR_bit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
	CLR_bit(TCCR0 , 0);
	CLR_bit(TCCR0 , 1);
	SET_bit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
	SET_bit(TCCR0 , 0);
	CLR_bit(TCCR0 , 1);
	SET_bit(TCCR0 , 2);
	
	#endif
	
	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
	CLR_bit(TCCR0 , 4);
	CLR_bit(TCCR0 , 5);
	
	
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
	SET_bit(TCCR0 , 4)
	CLR_bit(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
	CLR_bit(TCCR0 , 4);
	SET_bit(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
	SET_bit(TCCR0 , 4);
	SET_bit(TCCR0 , 5);

	
	#endif
	/*Disable Interrupts*/
	CLR_bit(TIMSK , 0);
	CLR_bit(TIMSK , 1);
	/*CLEAR FLAGS*/
	SET_bit(TIFR , 0);
	SET_bit(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
	
}


u16 CalculateOverflows(f32 time){
	f32 overflows = 0;

	overflows =  256 * ((f32)8/16000000);
	overflows = time/overflows ;
	return (u16)overflows ;
}




void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{	
	TCNT0 = map(Copy_uint8Val,0,100,0,255);
}

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = map(Copy_uint8Val,0,100,0,255); ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_bit(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	CLR_bit(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	SET_bit(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLR_bit(TIMSK , 1);
}

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}