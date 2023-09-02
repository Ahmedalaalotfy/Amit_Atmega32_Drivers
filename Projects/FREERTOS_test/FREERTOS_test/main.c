/*
 * FREERTOS_test.c
 *
 * Created: 10/24/2022 10:08:14 PM
 * Author : ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* RTOS */
#include   "FreeRTOS.h"
#include   "task.h"

void LED_0();
void LED_1();
void LED_2();

int main(void)
{
    DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	xTaskCreate(&LED_0,NULL,100,NULL,0,NULL);
	xTaskCreate(&LED_1,NULL,100,NULL,1,NULL);
	xTaskCreate(&LED_2,NULL,100,NULL,2,NULL);
	
	vTaskStartScheduler();
    while (1) 
    {
    }
}

void LED_0()
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
		vTaskDelay(1000);
	}
	
}

void LED_1()
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTC,DIO_PIN7);
		vTaskDelay(2000);
	}
	
}

void LED_2()
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTD,DIO_PIN3);
		vTaskDelay(3000);
	}
	
}