/*
 * SERVOM_test.c
 *
 * Created: 9/29/2022 5:38:01 PM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "SERVOM_interface.h"
#include   "TMR_interface.h"
#include   "TMR_config.h"
#include   "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
    
	SERVOM_on(90);
    while (1) 
    {
    }
}

