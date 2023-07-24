/*
 * EXTI_interface.h
 *
 * Created: 9/15/2022 12:01:56 PM
 *  Author: ahmed
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

// FOR INTERRUPT SOURCE 
#define EXTI_INT0            0  // PORTD PIN2
#define EXTI_INT1            1  // PORTD PIN3
#define EXTI_INT2            2  // PORTB PIN2

// FOR ENTERUUPT TRIGGER EDGE 
#define EXTI_RISING_EDGE     0
#define EXTI_FALLING_EDGE    1
#define EXTI_LOW_LEVEL       2
#define EXTI_LOGICAL_CHANGE  3

void EXTI_enable (u8 interruptSource, u8 interruptTriggerEdge) ;
void EXTI_disable(u8 interruptSource) ;
void EXTI_INT0setCallBack(void(*ptr)(void));
void EXTI_INT1setCallBack(void(*ptr)(void));
void EXTI_INT2setCallBack(void(*ptr)(void));

#endif /* EXTI_INTERFACE_H_ */