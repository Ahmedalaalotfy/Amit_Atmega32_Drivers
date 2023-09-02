/*
 * SSD_interface.h
 *
 * Created: 9/18/2022 12:37:10 PM
 *  Author: ahmed
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

void SSD_on(void);
void SSD_off(void);
void SSD_displayNumber(u8 desiredNumber);
void SSD_displayFullNumber(u8 firstNumber,u8 secondNumber);

static void writeHalfPort(u8 Value);


#endif /* SSD_INTERFACE_H_ */