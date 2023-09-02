/*
 * KERNAL_program.c
 *
 * Created: 10/18/2022 9:58:15 AM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */ 
#include   "GI_interface.h"

/* RTOS Stack */ 
#include   "TMR_interface.h"
#include   "KERNAL_interface.h"
#include   "KERNAL_config.h"

Task_t TaskArr[RTOS_TASK_NUM] ;

void RTOS_start(void)
{
	GI_enable(); 
	TMR_timer0Init(); 
	TMR_timer0setCompareMatchValue(249);
	TMR_timer0_CTC_SetCallBack(&privateScedular);
	TMR_timer0Start();
}

void RTOS_createTask(u8 priority,u16 priodicity, void(*pTaskCode)(void))
{
	// u8 locaclErrorState = PASS ; 
	if((priority<RTOS_TASK_NUM) && (pTaskCode != NULL) && (TaskArr[priority].pTaskFunc == NULL))
	 {
		 TaskArr[priority].taskPriodicity = priodicity ;
		 TaskArr[priority].pTaskFunc = pTaskCode ;
		 TaskArr[priority].taskState = RTOS_TASK_REUSMED ;
	 }
	 
	 else 
	 {
		 // Do Nothing 
		 // locaclErrorState = FAIL ; 
	 }  
	 
	// return locaclErrorState ;         
}

void RTOS_suspendTask(u8 priority)
{
	TaskArr[priority].taskState = RTOS_TASK_SUSPENDED ;
}

void RTOS_resumeTask(u8 priority)
{
	TaskArr[priority].taskState = RTOS_TASK_REUSMED ;
}

void RTOS_deleteTask(u8 priority)
{
	TaskArr[priority].pTaskFunc = NULL ; 
}

static void privateScedular (void)
{
   	
	volatile static u16 tickCounter = 0 ;  
	++ tickCounter ; 
	
	u8 taskCounter;  
	  for (taskCounter = 0 ; taskCounter < RTOS_TASK_NUM ; taskCounter++)
	  {
		  if ((TaskArr[taskCounter].taskState == RTOS_TASK_REUSMED) && (tickCounter%(TaskArr[taskCounter].taskPriodicity)==0))
		  {
			  if (TaskArr[taskCounter].pTaskFunc != NULL)
			  {
				  // Call Task
				  TaskArr[taskCounter].pTaskFunc();
			  }
			  
			  else 
			  {
				 // Do Nothing   
			  }
			  
		  }
		  else 
		  {
			 // Continue   
		  }
	  }
}