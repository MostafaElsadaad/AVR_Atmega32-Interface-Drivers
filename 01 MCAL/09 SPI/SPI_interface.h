/*
 * SPI_interface.h
 *
 * Created: 7/2/2023 11:59:10 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define	 SPI_MASTER		1
#define	 SPI_SLAVE		2


void SPI_Init();
void SPI_Send(u8 data);
u8	 SPI_Recieve();



#endif /* SPI_INTERFACE_H_ */