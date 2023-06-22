/*
 * ADC_private.h
 *
 * Created: 6/22/2023 3:59:14 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADCSRA		*((volatile u8*)0X26)
#define ADMUX       *((volatile u8*)0X27)
#define ADCL        *((volatile u8*)0X24)
#define ADCH        *((volatile u8*)0X25)
#define SFIOR       *((volatile u8*)0X50)



#endif /* ADC_PRIVATE_H_ */