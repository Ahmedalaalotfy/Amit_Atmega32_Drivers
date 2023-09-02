/*
 * STEPM_program.c
 *
 * Created: 9/27/2022 2:24:36 PM
 *  Author: ahmed
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
#include "STEPM_interface.h"

void STEPM_on(u16 Degree)
{
	u16 counter ; 
	u16 rotationValue ;
	
	rotationValue = (Degree)/(0.175*4);
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	for (counter = 0 ; counter < rotationValue ; counter ++ )
	{
		// step 1
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
		_delay_ms(10);
		
		// step 2
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
		_delay_ms(10);
		
		// step 3
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
		_delay_ms(10);
		
		// step 4
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
		_delay_ms(10);
	}
}