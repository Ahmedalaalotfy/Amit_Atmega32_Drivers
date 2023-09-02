/*
 * AVR_test.c
 *
 * Created: 9/4/2022 9:59:22 PM
 * Author : ahmed
 */ 

#include <avr/io.h>
#define F_CPU 8000000 
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h" 

int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRD,3); //CONFIGURE PC2 AS OUTPUT PIN
	SET_BIT(DDRC,2);
	
    while (1) 
    {
		TOG_BIT(PORTD,3); //LED TOGGLE
		TOG_BIT(PORTC,2); 
		_delay_ms(250); // delay time by milli second 
    }
}

