/*
 * EEPROM_interface.h
 *
 * Created: 7/10/2023 8:02:01 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_INIT();
u8 EEPROM_Read (u8 address);
void EEPROM_Write(u8 data, u8 address);



#endif /* EEPROM_INTERFACE_H_ */