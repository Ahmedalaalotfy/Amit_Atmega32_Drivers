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
#include   "TMR_config.h"

static void(*TMR_timer0_OVF_pCallBack)(void)= NULL ;
static void(*TMR_timer0_CTC_pCallBack)(void)= NULL ;

void TMR_timer0Init(void)
{
	
#if TMR_TMR0_MODE == TMR_TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	// Init Timer With Preload Value  
	TCNT0 = TMR_TMR0_PRELOAD_VALUE ;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,0);
	
#elif TMR_TMR0_MODE == TMR_TMR0_CTC_MODE
    // Select Mode = CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);
	
#elif TMR_TMR0_MODE == TMR_TMR0_FAST_PWM_MODE
	
	// Select Mode = Fast PWM Mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);  
	
	// Select Non-Inverting 
	  CLR_BIT(TCCR0,4);
	  SET_BIT(TCCR0,5);     
	            

#endif 
	
	
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



void TMR_timer0_OVF_SetCallBack(void(*ptr)(void))
{
	if (ptr != NULL)
	{
		TMR_timer0_OVF_pCallBack= ptr ;
	}
}

// ISR function prototype for TMR0 OVF
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static u16 counterOVF = 0 ;
	counterOVF ++ ; 
	
	// Set Preload Value
	TCNT0 = TMR_TMR0_PRELOAD_VALUE ;
	
	if ( TMR_TMR0_OVERFLOW_COUNTER == counterOVF )
	{
	  // Set Preload Value	
      TCNT0 = TMR_TMR0_PRELOAD_VALUE ;
	  
	  // Set Counter
	  counterOVF = 0 ; 
	  
	  // Call Action 
	   	if (TMR_timer0_OVF_pCallBack != NULL)
	   	{
		   	TMR_timer0_OVF_pCallBack();
	   	}	
	}
}

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
	static u16 counterCTC = 0 ;
	counterCTC ++ ;
	
	if ( TMR_TMR0_CTC_COUNTER == counterCTC )
	{
		// Clear Counter 
		counterCTC = 0 ;
		
		// Call Action               
		if (TMR_timer0_CTC_pCallBack != NULL)
		{
			TMR_timer0_CTC_pCallBack();
		}
	}
}