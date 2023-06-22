#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_bit(Num,Bit_no) Num|=(1<<Bit_no)
#define CLR_bit(Num,Bit_no) Num&=~(1<<Bit_no)
#define TOG_bit(Num,Bit_no) Num^=(1<<Bit_no)
#define GET_bit(Num,Bit_no) (1&(Num>>Bit_no))

#endif 
