/*
 * Math.c
 *
 * Created: 6/22/2023 5:06:32 PM
 *  Author: MostafaElSadaad
 */ 
#include "STD_TYPES.h"

u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max)
{
	return  (x - in_min) * (out_max - out_min) / ((in_max - in_min) + out_min);
}