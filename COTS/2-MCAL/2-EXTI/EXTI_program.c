/*
 * EXTI_program.c
 *
 * Created: 9/15/2022 12:01:35 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"

static void(*INT0pCallBack)(void)= NULL ;
static void(*INT1pCallBack)(void)= NULL ;
static void(*INT2pCallBack)(void)= NULL ;

void EXTI_enable (u8 interruptSource, u8 interruptTriggerEdge) 

{
     switch (interruptSource)
	 {
		 case EXTI_INT0 :
		 if (EXTI_RISING_EDGE == interruptTriggerEdge)
		 {
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1); 
		 }
		 else if (EXTI_FALLING_EDGE == interruptTriggerEdge)
		 {
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1); 
		 }
		 else if (EXTI_LOW_LEVEL == interruptTriggerEdge)
		 {
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1); 
		 }
		 else if (EXTI_LOGICAL_CHANGE == interruptTriggerEdge)
		 {
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1); 
		 }
		 
		 // ENABLE EXTI0 (PIE) 
		 SET_BIT(GICR,6);
		 break ; 
		 
		 case EXTI_INT1 :
		 
		 if (EXTI_RISING_EDGE == interruptTriggerEdge)
		 {
			 SET_BIT(MCUCR,2);
			 SET_BIT(MCUCR,3);
		 }
		 else if (EXTI_FALLING_EDGE == interruptTriggerEdge)
		 {
			 CLR_BIT(MCUCR,2);
			 SET_BIT(MCUCR,3);
		 }
		 else if (EXTI_LOW_LEVEL == interruptTriggerEdge)
		 {
			 CLR_BIT(MCUCR,2);
			 CLR_BIT(MCUCR,3);
		 }
		 else if (EXTI_LOGICAL_CHANGE == interruptTriggerEdge)
		 {
			 SET_BIT(MCUCR,2);
			 CLR_BIT(MCUCR,3);
		 }
		 
		 // ENABLE EXTI1 (PIE)
		 SET_BIT(GICR,7);
		 break ;
		 
		 case EXTI_INT2 :
		 
		 if (EXTI_RISING_EDGE == interruptTriggerEdge)
		 {
			 SET_BIT(MCUCSR,6);
		 }
		 else if (EXTI_FALLING_EDGE == interruptTriggerEdge)
		 {
			 CLR_BIT(MCUCSR,6);
		 }
		 
		 // ENABLE EXTI2 (PIE)
		 SET_BIT(GICR,5);
		 break ;
	 }	
}

void EXTI_disable(u8 interruptSource) 
{
	switch (interruptSource)
	{
		case EXTI_INT0 :
		
		// DISABLE EXTI0 (PIE)
		CLR_BIT(GICR,6);
		break ; 
		
		case EXTI_INT1 :
		// DISABLE EXTI1 (PIE)
		CLR_BIT(GICR,7);
		break ;
		
		case EXTI_INT2 :
		// DISABLE EXTI2 (PIE)
		CLR_BIT(GICR,5);
		break ;
	}
}

void EXTI_INT0setCallBack(void(*ptr)(void))
{
	if (ptr != NULL)
	{
	INT0pCallBack= ptr ;
	}
}

// ISR function prototype for EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if (INT0pCallBack != NULL)
	{
		INT0pCallBack();
	}
}

void EXTI_INT1setCallBack(void(*ptr)(void))
{
	if (ptr != NULL)
	{
		INT1pCallBack= ptr ;
	}
}

// ISR function prototype for EXTI1
void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{
	if (INT1pCallBack != NULL)
	{
		INT1pCallBack();
	}
}

void EXTI_INT2setCallBack(void(*ptr)(void))
{
	if (ptr != NULL)
	{
		INT2pCallBack= ptr ;
	}
}

// ISR function prototype for EXTI2
void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{
	if (INT2pCallBack != NULL)
	{
		INT2pCallBack();
	}
}



