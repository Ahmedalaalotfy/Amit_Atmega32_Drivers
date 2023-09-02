/*
 * KPF_test.cpp
 *
 * Created: 9/13/2022 10:00:36 AM
 * Author : ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"




int main(void)
{
	/* Replace with your application code */
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);
	
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW0_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW1_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW2_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW3_PIN);
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	u8 kpdkey;
	while (1)
	{
		KPD_getValue(&kpdkey);
		if(KPD_NOT_PRESSED != kpdkey)
		{
			switch(kpdkey)
			{
				case '0':
				DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
				break;
				
				case '1':
				DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
				break;
				
				case '2':
				DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
				break;
				
				case '3':
				DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
				DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
				DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
				break;
				
				default:
				DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
				DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
				DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
				break;
			}
		}
	}
}