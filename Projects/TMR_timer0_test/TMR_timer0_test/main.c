/*
 * TMR_timer0_test.c
 *
 * Created: 9/22/2022 12:35:14 PM
 * Author : ahmed
 */

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "TMR_interface.h"
#include   "TMR_config.h"
#include   "DIO_interface.h"
#include   "GI_interface.h"

/* HAL */ 
#include   "LED_interface.h"
#include   "LCD_interface.h"
#include   "LCD_config.h"


void OVF_func (void);
void CTC_func (void); 




int main(void)
{
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	
	LCD_init();
	//GI_enable();
    //TMR_timer0_CTC_SetCallBack(&CTC_func);
	
	TMR_timer0Init();
	TMR_timer0Start();
	u8 K = 0 ;
	 
    while (1) 
    {
		TMR_timer0setCompareMatchValue(K);
		K++ ;
		_delay_ms(10);
    }
}

void OVF_func(void)
{
  static u8 i =0 ;
  LCD_clear();	
  LCD_writeNumber(i);
  i++ ;	
}

void CTC_func(void)
{
	static u8 i =0 ;
	LCD_clear();
	LCD_writeNumber(i);
	i++ ;
}

