/*
 * TIMER0_private.h
 *
 * Created: 6/22/2023 4:57:26 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define TIMSK	 (*(volatile u8*)0x59)
#define OCR0 	 (*(volatile u8*)0x5C)
#define TCCR0	 (*(volatile u8*)0x53)
#define TCNT0	 (*(volatile u8*)0x52)
#define TIFR	 (*(volatile u8*)0x58)

/*        ----- TIMER 1 -----    (under development)  */
#define TCCR1A		(*(volatile u8*)0x4F)
#define TCCR1B		(*(volatile u8*)0x4E)
#define TCCR1B		(*(volatile u8*)0x4E)
#define ICR1L		(*(volatile u8*)0x46)
#define ICR1H		(*(volatile u8*)0x47)
#define ICR1		(*(volatile u16*)0x46)
#define OCR1AL		(*(volatile u16*)0x4A)
#define OCR1AH		(*(volatile u16*)0x4A)
#define OCR1A		(*(volatile u16*)0x4A)



#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15


#define TIMER0_NO_ACTION	100
#define TIMER0_TOGGLE		12
#define TIMER0_SET			20
#define TIMER0_CLEAR		25






#endif /* TIMER0_PRIVATE_H_ */