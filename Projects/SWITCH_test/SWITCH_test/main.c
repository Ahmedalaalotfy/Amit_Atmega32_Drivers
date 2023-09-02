/*
 * SWITCH_test.c
 *
 * Created: 9/19/2022 1:58:12 PM
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
#include "SWITCH_interface.h"
#include "LED_interface.h" 


int main(void)
{
	DIO_setPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT); 
	DIO_setInputPinResistance(DIO_PORTB,DIO_PIN0);
	
    u8 switch_stateValue ; 
    while (1) 
    {
		SWITCH_getState(DIO_PORTB,DIO_PIN0,forward,&switch_stateValue);
		
		if (switch_stateValue == SWITCH_PRESSED )
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		}
		else if (switch_stateValue == SWITCH_NOT_PRESSED )
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		}
    }
}

