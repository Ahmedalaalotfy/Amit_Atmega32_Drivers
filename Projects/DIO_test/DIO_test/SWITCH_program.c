/*
 * SWITCH_program.c
 *
 * Created: 9/10/2022 11:11:40 PM
 *  Author: ahmed
 */ 


/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SWITCH_interface.h"

void SWITCH_getState(u8 PortId, u8 PinId,u8* StateValue) 

{
    if ( (PortId<=3) && (PinId<=7) && (StateValue != NULL ) ) 
	{
		switch (PortId) 
		{
			case 0 : // PORTA 
			DIO_setPinDirection(DIO_PORTA,PinId,DIO_PIN_INPUT) ;
			DIO_getPinValue(DIO_PORTA,PinId,StateValue) ;
			break ; 
			
			case 1 : // PORTB
			DIO_setPinDirection(DIO_PORTB,PinId,DIO_PIN_INPUT) ;
			DIO_getPinValue(DIO_PORTB,PinId,StateValue) ;
			break ;
			
			case 2 : // PORTC
			DIO_setPinDirection(DIO_PORTC,PinId,DIO_PIN_INPUT) ;
			DIO_getPinValue(DIO_PORTC,PinId,StateValue) ;
			break ;
			
			case 3 : // PORTD
			DIO_setPinDirection(DIO_PORTD,PinId,DIO_PIN_INPUT) ;
			DIO_getPinValue(DIO_PORTD,PinId,StateValue) ;
			break ;
			
		}
	}
}