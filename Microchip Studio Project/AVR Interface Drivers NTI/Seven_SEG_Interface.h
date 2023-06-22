/*
 * Seven_SEG_Interface.h
 *
 * Created: 6/22/2023 12:21:57 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_

#define SSD1 PA3
#define SSD2 PA2
#define SSD3 PB5
#define SSD4 PB6

void SSD_INIT();
void WriteSSD(u8 num,u8 display);

#endif /* SEVEN_SEG_INTERFACE_H_ */