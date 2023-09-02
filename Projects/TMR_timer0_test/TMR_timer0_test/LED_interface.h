/*
 * LED_interface.h
 *
 * Created: 9/10/2022 10:28:52 PM
 *  Author: ahmed
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define forward  1 // active high
#define reverse  0 // active low  

void LED_on(u8 PortId, u8 PinId,u8 connectionType); 
void LED_off(u8 PortId, u8 PinId, u8 connectionType);
void LED_toggle(u8 PortId, u8 PinId); 



#endif /* LED_INTERFACE_H_ */