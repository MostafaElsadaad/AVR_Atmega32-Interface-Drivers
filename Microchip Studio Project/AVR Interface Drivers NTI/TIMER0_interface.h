/*
 * TIMER0_interface.h
 *
 * Created: 6/22/2023 4:58:40 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;

u16 CalculateOverflows(f32 time);




#endif /* TIMER0_INTERFACE_H_ */