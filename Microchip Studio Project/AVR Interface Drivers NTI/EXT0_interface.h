/*
 * EXT0_interface.h
 *
 * Created: 6/22/2023 3:24:08 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef EXT0_INTERFACE_H_
#define EXT0_INTERFACE_H_

#define IOC			1
#define FALLING		4
#define RISING		7
#define LOW_LEVEL	10

void EXT0_voidInit ( void );							//Initialize EXT0
void EXT0_voidEnable( void );							//Enable EXT0
void EXT0_voidDisable( void );							//Disable EXT0
void EXT0_voidCallBack(void  (*addresscpy)(void));		//Callback function to communicate with the function in the APP layer
void EXT0_voidSetSignalch(u8 SenseCpy);					//Sets sense mode


#endif /* EXT0_INTERFACE_H_ */