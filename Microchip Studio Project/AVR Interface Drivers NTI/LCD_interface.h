/*
 * LCD_interface.h
 *
 * Created: 6/22/2023 1:47:21 PM
 *  Author: MostafaElSadaad
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_INIT();
void write4bit(u8 data);
void Send_Command(u8 Command);
void Send_Data(u8 Data);
void lcdWriteText(u8 * text);
void lcdGoToAddr(u8 addr);
void lcdGoToXY(u8 x, u8 y);
void LCD_Custom_Char (u8 loc, u8 *msg);
void LCD_CLR();
void LCD_voidWriteNumber(u32 COPY_u32Number,u8 COPY_u8XPos,u8 COPY_u8YPos);
void CLCD_voidGoToXY(u8 COPY_u8XPos,u8 COPY_u8YPos);



#endif /* LCD_INTERFACE_H_ */