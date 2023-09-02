/*
 * KERNAL_interface.h
 *
 * Created: 10/18/2022 9:58:40 AM
 *  Author: ahmed
 */ 


#ifndef KERNAL_INTERFACE_H_
#define KERNAL_INTERFACE_H_

#define RTOS_TASK_SUSPENDED   1
#define RTOS_TASK_REUSMED     2
  
typedef struct 
{
  	void(*pTaskFunc)(void);
    u16 taskPriodicity ;
	u8  taskState ;
}Task_t;

void RTOS_start(void);
void RTOS_createTask(u8 priority,u16 priodicity, void(*pTaskCode)(void));
void RTOS_suspendTask(u8 priority);
void RTOS_resumeTask(u8 priority);
void RTOS_deleteTask(u8 priority);
static void privateScedular (void); 
     


#endif /* KERNAL_INTERFACE_H_ */