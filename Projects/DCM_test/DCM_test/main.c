/*
 * DCM_test.c
 *
 * Created: 9/27/2022 10:46:45 AM
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
#include "TMR_interface.h"
#include "TMR_config.h"

/* HAL */
#include "DCM_interface.h"


int main(void)
{
    /*DIO_setPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH); */
	
	
	
	/*DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT); // EN1
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT); // EN2
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT); // MA_1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT); // MA_2
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT); // MB_1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT); // MB_2
	
	DIO_setPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH); // EN1
	DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH); // EN2
	
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH); // MA_1
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW); // MA_2
			  
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH); // MB_1
	DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW); // MB_2 */ 
	
	
	
	DCM_speed(DCM_MOTORA,DCM_DIRECTION_CW,100);
	
    while (1) 
    {
		
    }
}

