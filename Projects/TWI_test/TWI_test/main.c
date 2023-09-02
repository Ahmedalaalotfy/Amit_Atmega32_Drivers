/*
 * TWI_test.c
 *
 * Created: 10/6/2022 1:23:15 PM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "TWI_interface.h"
#include "DIO_interface.h"

/* HAL */
#include "EEPROM_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"



int main(void)
{
	 DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	 DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	 DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	 DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	 
	 DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	 DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	 DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	 
	 LCD_init();
	
	u8 data ;  
	
    TWI_initMaster(); 
	
	EEPROM_writeByte(94,'A');
	EEPROM_readByte(94,&data); 
	
	LCD_sendChar(data);
    while (1) 
    {
    }
}

