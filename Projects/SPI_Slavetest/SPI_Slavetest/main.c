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
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);  // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT); // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);  //CLK
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT); //SS
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT); // LED0
	
	
	
	SPI_initSlave();
	u8 slaveReturnedData ;
	

    while (1) 
    {
		SPI_transieve(5,&slaveReturnedData);
		
		if (10 == slaveReturnedData)
		{
			TOG_BIT(PORTD,3);
			_delay_ms(500);
		}
    }
}

