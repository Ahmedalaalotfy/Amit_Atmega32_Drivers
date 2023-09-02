/*
 * LED_test.c
 *
 * Created: 9/18/2022 1:44:20 PM
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
#include "LED_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
    
    while (1) 
    {
		LED_on(DIO_PORTC,DIO_PIN2,forward); 
		_delay_ms(500);
		LED_off(DIO_PORTC,DIO_PIN2,forward);
        _delay_ms(500);
		
		DIO_togglePinValue(DIO_PORTA,DIO_PIN3);
	}  
}

