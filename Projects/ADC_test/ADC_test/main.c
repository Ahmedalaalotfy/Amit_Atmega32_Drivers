#define F_CPU 16000000UL
#include <util/delay.h>

//UTILES
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"

// HAL
#include "LCD_Interface.h"
#include "LCD_config.h"

int main(void)
{
	
	// LCD Set Direction
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_INPUT);
	
	
	/*DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);*/
	
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT); // Rx
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); //Tx
	
	UART_init();
	
	
	ADC_init();
	
	u16 digitalValue ,analogVal ;
	
	while (1)
	{
		ADC_getDigitalValue(ADC_CHANNEL6,&digitalValue);
		
		
		
		UART_TxChar((u8)(digitalValue-500));
		_delay_ms(500);
		
		
		
		
		
		
		
		
		
		
		
		//analogVal= (((u32)digitalValue*5000UL)/1024) ;
		
		/*if (digitalValue > 925)
		{
			
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			
		}
		else if(digitalValue > 920)
		{
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		}
		else if(digitalValue > 915)
		{
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
			
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			
		}
		else
		{
			
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
			
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			
			
		}*/
		
	}
}