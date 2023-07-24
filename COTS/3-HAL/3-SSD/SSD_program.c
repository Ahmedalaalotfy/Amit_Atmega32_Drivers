/*
 * SSD_program.c
 *
 * Created: 9/18/2022 12:36:51 PM
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
#include "SSD_interface.h"

void SSD_on(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);   
}
void SSD_off(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}
void SSD_displayNumber(u8 desiredNumber)
{
	writeHalfPort(desiredNumber);
}

static void writeHalfPort(u8 Value)
{
	if (1==GET_BIT(Value,0))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,1))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,2))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,3))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
}

void SSD_displayFullNumber(u8 firstNumber,u8 secondNumber)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	writeHalfPort(secondNumber);
	_delay_ms(7);
	
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	writeHalfPort(firstNumber);
	_delay_ms(7);
	
}