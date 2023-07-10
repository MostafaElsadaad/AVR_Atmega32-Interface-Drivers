/*
 * EEPROM_program.c
 *
 * Created: 7/10/2023 8:02:43 PM
 *  Author: MostafaElSadaad
 */ 

#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"
#include "TWI_interface.h"



void EEPROM_INIT(){
	
	I2C_Init();
	
}

u8 EEPROM_Read (u8 address) // the function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in
{
	u8 data;
	
	I2C_Start(address);

	I2C_Write(0xA8);

	I2C_Write(address);

	I2C_Start(address);

	I2C_Write(0xA9);

	data = I2C_Read_Nack();

	I2C_Stop();

	return data;
}


void EEPROM_Write(u8 data, u8 address)

{

	I2C_Start(address);

	I2C_Write(0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate writing.

	I2C_Write(address);

	I2C_Write(data);

	I2C_Stop();

}



