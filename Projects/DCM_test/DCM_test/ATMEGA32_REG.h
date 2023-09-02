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

                     /* ADC REGISTERS */ 
					 
// ADC Multiplexer Selection			 
#define ADMUX     (*(volatile u8*)0x27)

// ADC Control and Status
#define ADCSRA    (*(volatile u8*)0x26)

// The ADC Data Register
#define ADCL      (*(volatile u8*)0x24)
#define ADCH      (*(volatile u8*)0x25)
#define ADC_u16   (*(volatile u16*)0x24)

// Special FunctionIO Register
#define SFIOR     (*(volatile u8*)0x50)


              /* TIMERS REGISTERS */

// Timer/Counter Control Register
#define TCCR0     (*(volatile u8*)0x53)

// Timer/Counter Register
#define TCNT0     (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0     (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK     (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR     (*(volatile u8*)0x58)

#endif /* ATMEGA32_REG_H_ */