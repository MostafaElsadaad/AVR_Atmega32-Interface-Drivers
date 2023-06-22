/*
 * Keypad_interface.h
 *
 * Created: 6/22/2023 2:12:14 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_



#define KEYPAD_COL1_PIN		PD7
#define KEYPAD_COL2_PIN		PD6
#define KEYPAD_COL3_PIN		PD5
#define KEYPAD_COL4_PIN		PD3

#define KEYPAD_ROW1_PIN		PC5
#define KEYPAD_ROW2_PIN		PC4
#define KEYPAD_ROW3_PIN		PC3
#define KEYPAD_ROW4_PIN		PC2

void KEYPAD_INIT();
u8 KeyFind();





#endif /* KEYPAD_INTERFACE_H_ */