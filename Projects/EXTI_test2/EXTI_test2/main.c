/*
 * EXTI_test.cpp
 *
 * Created: 9/15/2022 11:59:08 AM
 * Author : ahmed
 */

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "EXTI_interface.h"
#include   "DIO_interface.h"
#include   "GI_interface.h"

/* HAL */ 
#include "LCD_interface.h"
#include "LCD_config.h"

void func(void);


int main(void)
{
	/*DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);*/
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	
	LCD_init();
	
	LCD_sendString("Press Button 2");
	
	// GENERAL INTERRUPT ENABLE 
	GI_enable();
	
	EXTI_INT0setCallBack(&func);
    EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
	
    while (1) 
    {
    }
}
         
void func(void) 

{
	DIO_togglePinValue(DIO_PORTA,DIO_PIN3);
	LCD_clear();
	LCD_sendString("Ahmed Alaalotfy");
}