/*
 * TWI_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_





void I2C_Init();
u8 I2C_Start(u8 write_address);
u8 I2C_Repeated_Start(u8 read_address);
u8 I2C_Write(u8 data);
u8 I2C_Read_Ack();
u8 I2C_Read_Nack();
void I2C_Stop();


void I2C_Slave_Init(u8 slave_address);
u8 I2C_Slave_Listen();
u8 I2C_Slave_Transmit(u8 data);
u8 I2C_Slave_Receive();



/*


typedef enum
{
	NO_ERROR,
	START_ERROR,
	REPEATED_STSRT_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	SEND_BYTE_ERROR,
	READ_BYTE_ERROR

}TWI_ERROR_STATUS;
void M_TWI_void_Init(void);
u8 M_TWI_u8_StartCondition(void);
void M_TWI_void_StopCondition(void);
u8 M_TWI_u8_RepeatedStart(void);
u8 M_TWI_u8_SendSlaveAddressWrite(u8);
u8 M_TWI_u8_SendSlaveAddressRead(u8);
u8 M_TWI_u8_SendByte(u8);
u8 M_TWI_u8_ReadByte(u8 *TWI_DATA);

*/



#endif /* TWI_TWI_INT_H_ */
