/*
 * SPI_private.h
 *
 * Created: 7/2/2023 11:58:43 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR	(*(volatile u8*)0x2D)
#define SPSR	(*(volatile u8*)0x2E)
#define SPDR	(*(volatile u8*)0x2F)

/*		SPCR    	*/
#define SPE		6
#define MSTR	4
#define SPR0	0
/*		SPSR		*/
#define SPI2X	0
#define SPIF    7



#endif /* SPI_PRIVATE_H_ */