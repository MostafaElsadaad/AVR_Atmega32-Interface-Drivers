/*
 * ADC_interface.h
 *
 * Created: 6/22/2023 3:59:36 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define AVCC 					5
#define AREF 					4
#define INTERNAL				2.56

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1


#define DIVID_BY_2				1
#define DIVID_BY_4				2
#define DIVID_BY_8				3
#define DIVID_BY_16				4
#define DIVID_BY_32				5
#define DIVID_BY_64				6
#define DIVID_BY_128			7


#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7



void ADC_voidInterrputEnable(); //Enables ADC interrupt


void ADC_INT_voidCallBack(void (*addresscpy)(void)); // Callback Function to interrupt|| used after Interrupt Initialization

void ADC_voidAutoTrigger(); // Set latch interrupt || Depends on Sense mode

void ADC_Init();

u16 ADC_Read(u8 channel);



#endif /* ADC_INTERFACE_H_ */