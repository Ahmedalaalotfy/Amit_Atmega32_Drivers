/*
 * RTOS_test.c
 *
 * Created: 10/18/2022 9:56:40 AM
 * Author : ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "GI_interface.h"
#include   "DIO_interface.h"

/* RTOS Stack */
#include   "KERNAL_interface.h"

void LED_0(void); 
void LED_1(void); 
void LED_2(void); 
void BUZZER(void);

int main(void)
{
    DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); // LED0 
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT); // LED1
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT); // LED2
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT); // BUZZER
	
	RTOS_createTask(0,1000,&LED_0);
	RTOS_createTask(1,1000,&LED_1);
	RTOS_createTask(2,1500,&LED_2);
	RTOS_createTask(3,2000,&BUZZER);
	
	RTOS_deleteTask(1);
	RTOS_createTask(1,2000,&LED_1);
	
	RTOS_start();
    while (1) 
    {
    }
}

void LED_0(void) 
{
	 DIO_togglePinValue(DIO_PORTC,DIO_PIN2); // LED0
}

void LED_1(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN7); // LED0
}

void LED_2(void)
{
	DIO_togglePinValue(DIO_PORTD,DIO_PIN3); // LED0
}

void BUZZER(void)
{
	DIO_togglePinValue(DIO_PORTA,DIO_PIN3); // LED0
	
}
