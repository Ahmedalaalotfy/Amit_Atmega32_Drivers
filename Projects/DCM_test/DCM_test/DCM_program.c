/*
 * DCM_program.c
 *
 * Created: 9/27/2022 10:47:16 AM
 *  Author: ahmed
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"
#include "TMR_interface.h"
#include "TMR_config.h"

/* HAL */
#include "DCM_interface.h"

void DCM_on(u8 motorName ,u8 motorDirection)
{
 if ((motorName==DCM_MOTORA || motorName==DCM_MOTORB) && (motorDirection == DCM_DIRECTION_CW || motorDirection == DCM_DIRECTION_CCW))
 {
	 switch(motorName) 
	 {
		 case DCM_MOTORA : 
		 DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT); // EN1
		 DIO_setPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH); // EN1
		 
		 DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT); // MA_1
		 DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT); // MA_2
		 if (motorDirection == DCM_DIRECTION_CW)
		 {
			 DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH); // MA_1
			 DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW); // MA_2
		 }
		 
		 else if(motorDirection == DCM_DIRECTION_CCW )
		 {
			 DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW); // MA_1
			 DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH); // MA_2
		 }
		 
		 break ; 
		 
		 case DCM_MOTORB : 
		 DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT); // EN2
		 DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH); // EN2
		 
		 DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT); // MB_1
		 DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT); // MB_2
		 
		 if (motorDirection == DCM_DIRECTION_CW)
		 {
			 DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH); // MB_1
			 DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW); // MB_2
		 }
		 
		 else if(motorDirection == DCM_DIRECTION_CCW )
		 {
			 DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW); // MB_1
			 DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH); // MB_2 
		 }
		 
		 
		 break ; 
	 }
 }	
}

void DCM_off(u8 motorName)
{
	if (motorName == DCM_MOTORA || motorName == DCM_MOTORB)
	{
		switch (motorName)
		{
			case DCM_MOTORA : 
			DIO_setPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_LOW); // EN1
			break ; 
			
			case DCM_MOTORB : 
			DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_LOW); // EN2
			break; 
		}
	}
}


void DCM_speed(u8 motorName ,u8 motorDirection ,u8 motorSpeedPercentage)
{
	
	if ((motorName==DCM_MOTORA || motorName==DCM_MOTORB) && (motorDirection == DCM_DIRECTION_CW || motorDirection == DCM_DIRECTION_CCW) && (motorSpeedPercentage >=0 || motorSpeedPercentage <=100))
	{
		
		DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
		
		u16 OC0Value = (motorSpeedPercentage*255)/100 ; 
		TMR_timer0Init();
		TMR_timer0Start();
		TMR_timer0setCompareMatchValue(OC0Value);
		
		switch(motorName)
		{
			case DCM_MOTORA :
			DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT); // EN1
			DIO_setPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH); // EN1
			
			DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT); // MA_1
			DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT); // MA_2
			if (motorDirection == DCM_DIRECTION_CW)
			{
				DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH); // MA_1
				DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW); // MA_2
			}
			
			else if(motorDirection == DCM_DIRECTION_CCW )
			{
				DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW); // MA_1
				DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH); // MA_2
			}
			
			break ;
			
			case DCM_MOTORB :
			DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT); // EN2
			DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH); // EN2
			
			DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT); // MB_1
			DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT); // MB_2
			
			if (motorDirection == DCM_DIRECTION_CW)
			{
				DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH); // MB_1
				DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW); // MB_2
			}
			
			else if(motorDirection == DCM_DIRECTION_CCW )
			{
				DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW); // MB_1
				DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH); // MB_2
			}
			
			
			break ;
		}
	}
}