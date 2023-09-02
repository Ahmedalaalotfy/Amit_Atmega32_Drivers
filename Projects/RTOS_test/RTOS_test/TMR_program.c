/*
 * TMR_program.c
 *
 * Created: 9/22/2022 12:37:18 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "TMR_interface.h"
#include   "DIO_interface.h"


static void(*TMR_timer0_CTC_pCallBack)(void)= NULL ;

void TMR_timer0Init(void)
{
	
    // Select Mode = CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);
	
	
}

void TMR_timer0setCompareMatchValue(u8 OCR0_value)
{
	//Init  Timer With Compare Value
	OCR0 = OCR0_value ;
}

void TMR_timer0Start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void TMR_timer0Stop(void)
{
	// Stop Clock
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}




// ISR 


void TMR_timer0_CTC_SetCallBack(void(*ptr)(void))
{
	if (ptr != NULL)
	{
		TMR_timer0_CTC_pCallBack= ptr ;
	}
}

// ISR function prototype for TMR0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
		// Call Action               
		if (TMR_timer0_CTC_pCallBack != NULL)
		{
			TMR_timer0_CTC_pCallBack();
		}
}

