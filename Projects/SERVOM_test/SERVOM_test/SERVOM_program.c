/*
 * SERVOM_program.c
 *
 * Created: 9/29/2022 8:29:26 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "SERVOM_interface.h"
#include   "TMR_interface.h"
#include   "TMR_config.h"


void SERVOM_on(s8 Degree)
{
	if ((Degree >= -90) || (Degree <= 90) )
	{
	u16 OCR1A_passValue ;
	
	OCR1A_passValue = (((u16)Degree+90)*(250)/(180)) + 249 ;
	
	TMR_timer1Init();
	TMR_timer1setCompareAMatchValue(OCR1A_passValue);
	TMR_timer1Start();
	}
}