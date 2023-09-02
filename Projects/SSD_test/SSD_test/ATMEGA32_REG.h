/*
 * ATMEGA32_REG.h
 *
 * Created: 9/7/2022 12:11:22 AM
 *  Author: ahmed
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/* DATA DIRECTION REGISTER */
#define DDRA   (*(volatile u8*)0x3A)
#define DDRB   (*(volatile u8*)0x37)
#define DDRC   (*(volatile u8*)0x34)
#define DDRD   (*(volatile u8*)0x31)

/* OUTPUT REGISTER */ 
#define PORTA  (*(volatile u8*)0x3B)
#define PORTB  (*(volatile u8*)0x38)
#define PORTC  (*(volatile u8*)0x35)
#define PORTD  (*(volatile u8*)0x32)

/* INPUT REGISTER */
#define PINA   (*(volatile u8*)0x39)
#define PINB   (*(volatile u8*)0x36)
#define PINC   (*(volatile u8*)0x33)
#define PIND   (*(volatile u8*)0x30)

/* EXTERNAL INTERRUPT REGISTERS */

// MCU CONTROL REGISTER
#define MCUCR   (*(volatile u8*)0x55)

// MCU CONTROL AND STATUS REGISTER
#define MCUCSR   (*(volatile u8*)0x54)

// GENERAL INTERRUPT CONTROL REGISTER
#define GICR   (*(volatile u8*)0x5B)

// GENERAL INTERRUPT FLAG REGISTER
#define GIFR   (*(volatile u8*)0x5A)

// STATUS REGISTER
#define SREG   (*(volatile u8*)0x5F)




#endif /* ATMEGA32_REG_H_ */