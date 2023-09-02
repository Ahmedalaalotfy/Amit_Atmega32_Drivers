/*
 * SSD_test.c
 *
 * Created: 9/18/2022 12:36:24 PM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h"


int main(void)
{
    u8 Ones , Tens , Timer ; 
    SSD_on();
	
    while (1) 
    {
		for (Tens= 0 ; Tens < 10 ; Tens++ )
		{
			for (Ones= 0 ; Ones < 10 ; Ones++)
			{
				_delay_ms(900);
				for (Timer = 0 ; Timer < 10 ; Timer++ )
				{
					SSD_displayFullNumber(Tens,Ones);
					_delay_ms(7);
				}
			}
		}
    }
}

