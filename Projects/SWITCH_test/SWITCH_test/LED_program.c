/*
 * CFile1.c
 *
 * Created: 9/10/2022 10:27:37 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */ 
#include "LED_interface.h"

void LED_on(u8 PortId, u8 PinId)

{
	if ( (PortId<=3) && (PinId<=7) ) 
	{
		switch (PortId)  
		{
		case 0 : //PORTA 
		DIO_setPinDirection(DIO_PORTA,PinId,DIO_PIN_OUTPUT);
		DIO_setPinValue(DIO_PORTA,PinId,DIO_PIN_HIGH);
		break ;
		
		case 1 : //PORTB
		DIO_setPinDirection(DIO_PORTB,PinId,DIO_PIN_OUTPUT);
		DIO_setPinValue(DIO_PORTB,PinId,DIO_PIN_HIGH);
		break ;
		
		 case 2 : //PORTC
		 DIO_setPinDirection(DIO_PORTC,PinId,DIO_PIN_OUTPUT);
		 DIO_setPinValue(DIO_PORTC,PinId,DIO_PIN_HIGH);
		 break ;
		  
		 case 3 : //PORTA
		 DIO_setPinDirection(DIO_PORTD,PinId,DIO_PIN_OUTPUT);
		 DIO_setPinValue(DIO_PORTD,PinId,DIO_PIN_HIGH);
		 break ;
		} 
	}
}
void LED_off(u8 PortId, u8 PinId)

{
	if ( (PortId<=3) && (PinId<=7) )
	{
		switch (PortId)
		{
			case 0 : //PORTA
			DIO_setPinDirection(DIO_PORTA,PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(DIO_PORTA,PinId,DIO_PIN_LOW);
			break ;
			
			case 1 : //PORTB
			DIO_setPinDirection(DIO_PORTB,PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(DIO_PORTB,PinId,DIO_PIN_LOW);
			break ;
			
			case 2 : //PORTC
			DIO_setPinDirection(DIO_PORTC,PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(DIO_PORTC,PinId,DIO_PIN_LOW);
			break ;
			
			case 3 : //PORTA
			DIO_setPinDirection(DIO_PORTD,PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(DIO_PORTD,PinId,DIO_PIN_LOW);
			break ;
		}
	}
}

void LED_toggle(u8 PortId, u8 PinId)

{
	if ( (PortId<=3) && (PinId<=7) )
	{
		switch (PortId)
		{
			case 0 : //PORTA
			DIO_setPinDirection(DIO_PORTA,PinId,DIO_PIN_OUTPUT);
			DIO_togglePinValue(DIO_PORTA,PinId);
			break ;
			
			case 1 : //PORTB
			DIO_setPinDirection(DIO_PORTB,PinId,DIO_PIN_OUTPUT);
			DIO_togglePinValue(DIO_PORTB,PinId);
			break ;
			
			case 2 : //PORTC
			DIO_setPinDirection(DIO_PORTC,PinId,DIO_PIN_OUTPUT);
			DIO_togglePinValue(DIO_PORTC,PinId);
			break ;
			
			case 3 : //PORTA
			DIO_setPinDirection(DIO_PORTD,PinId,DIO_PIN_OUTPUT);
			DIO_togglePinValue(DIO_PORTD,PinId);
			break ;
		}
	}
}
