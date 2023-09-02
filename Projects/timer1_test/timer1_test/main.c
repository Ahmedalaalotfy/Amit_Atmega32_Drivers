/*
 * timer1_test.c
 *
 * Created: 9/29/2022 10:28:22 AM
 * Author : ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "TMR_interface.h"
#include   "TMR_config.h"
#include   "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	
	TMR_timer1Init();
	TMR_timer1setCompareAMatchValue(499);
	TMR_timer1Start();
	
    while (1) 
    {
	  	              
    }
}

