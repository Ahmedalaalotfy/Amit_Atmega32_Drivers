/*
 * UART_test.c
 *
 * Created: 10/4/2022 9:29:10 AM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "UART_interface.h"
#include   "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT); // Rx
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); //Tx
	
	UART_init(); 
	
    
    while (1) 
    {
		UART_TxString((u8)"AHMED");
		_delay_ms(1000);
		
    }
}

