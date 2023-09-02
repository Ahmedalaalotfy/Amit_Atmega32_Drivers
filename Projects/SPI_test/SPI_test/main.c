/*
 * SPI_test.c
 *
 * Created: 10/4/2022 1:03:24 PM
 * Author : ahmed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "SPI_interface.h"
#include "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT); // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);  // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT); //CLK
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT); //SS
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); // LED0
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW); //SS = 0 
	
	SPI_initMaster();
	u8 returnedData ;
	

    while (1) 
    {
		SPI_transieve(10,&returnedData);
		
		if (5 == returnedData)
		{
			TOG_BIT(PORTC,2);
			_delay_ms(500);
		}
    }
}

