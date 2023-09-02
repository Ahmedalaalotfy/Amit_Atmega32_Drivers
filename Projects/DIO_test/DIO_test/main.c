/*
 * DIO_test.c
 *
 * Created: 9/6/2022 11:25:20 PM
 * Author : ahmed
 */ 

#define F_CPU 16000000
#include <util/delay.h> 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LED_interface.h"


int main(void)
{
    	LED_on(DIO_PORTC,DIO_PIN2);
    	LED_off(DIO_PORTC,DIO_PIN7);

    while (1) 
    {
		

		LED_toggle(DIO_PORTD,DIO_PIN3);
		_delay_ms(250) ; 
												
    }
}