/*
 * DCM_interface.h
 *
 * Created: 9/27/2022 10:47:34 AM
 *  Author: ahmed
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define DCM_MOTORA            0
#define DCM_MOTORB            1

#define DCM_DIRECTION_CW      0
#define DCM_DIRECTION_CCW     1


void DCM_on(u8 motorName ,u8 motorDirection); 
void DCM_off(u8 motorName); 
void DCM_speed(u8 motorName ,u8 motorDirection ,u8 motorSpeedPercentage); 



#endif /* DCM_INTERFACE_H_ */