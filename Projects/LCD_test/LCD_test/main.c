/*
 * LCD_test.c
 *
 * Created: 9/11/2022 11:27:12 AM
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

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"
#include "SWITCH_interface.h"

u8 customChar[] = {
	0x0A,
	0x0A,
	0x0A,
	0x00,
	0x11,
	0x11,
	0x0E,
	0x00
};

void Write_Custom_Character(void){
	LCD_sendCmnd(0x40);           // Set CGRAM Address in address counter to 0x00
	for(int i=0;i<8;i++){
		LCD_sendChar(customChar[i]); // Write data to CGRAM(Character Graphics Random Access Memory)
	}
	LCD_sendCmnd(0x01);           // Clear Display
	LCD_sendChar(0x00);              // Write the Data to LCD stored on address 0x00
}


int main(void)
{
	
	
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
		
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	LCD_init();
	
	
    u8 SWITCH_STATE ;
    while (1) 
    {
		
		
		LCD_goToSpecificPosition(1,4);
		LCD_sendString("LEVEL 1 ");
		
		LCD_goToSpecificPosition(2,0);
		LCD_sendString(">");
		
		LCD_goToSpecificPosition(2,15);
		LCD_sendString("I");
		
		
		_delay_ms(1000);
		DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		LCD_goToSpecificPosition(2,4);
		LCD_sendString("PRESS B0");
		_delay_ms(1000);
		DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		
		SWITCH_getState(DIO_PORTB,DIO_PIN0,forward,&SWITCH_STATE);
		
		if(SWITCH_STATE == SWITCH_PRESSED)
		{
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			LCD_goToSpecificPosition(2,4);
			LCD_sendString("        ");
			LCD_goToSpecificPosition(2,5);
			LCD_sendString("FIRE !");
			_delay_ms(1000);
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			
			
			int i ; 
			LCD_goToSpecificPosition(2,0);
			LCD_sendString("                ");
			
			LCD_goToSpecificPosition(2,0);
			LCD_sendString(">");
			
			LCD_goToSpecificPosition(2,15);
			LCD_sendString("I");
			
			for (i=2 ; i<16 ; i++ )
			{
				
				LCD_goToSpecificPosition(2,i-1);
				LCD_sendString(" ");
				
				DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
				
				DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
				LCD_goToSpecificPosition(2,i);
				LCD_sendChar(0b10100101);
				
				_delay_ms(200);
				
				DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
				
				DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
				
				_delay_ms(500);
			}
			
			
			
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			
			LCD_goToSpecificPosition(2,15);
			LCD_sendChar(0b01101111);
			_delay_ms(700);
			
			LCD_goToSpecificPosition(2,15);
			LCD_sendChar(0b01001111);
			_delay_ms(700);
			
			LCD_goToSpecificPosition(2,15);
			LCD_sendString(" ");

			_delay_ms(1500);
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			
			LCD_clear();
			LCD_goToSpecificPosition(1,0);
			LCD_sendString("WAIT FOR LEVEL 2");
			
			_delay_ms(3000);
			
			LCD_clear();
			Write_Custom_Character();
			Write_Custom_Character();
			
			_delay_ms(2000);
			
		}
		
		
		
		
       _delay_ms(500);

    } 
}


