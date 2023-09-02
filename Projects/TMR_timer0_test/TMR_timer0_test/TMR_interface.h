/*
 * TMR_interface.h
 *
 * Created: 9/22/2022 12:37:39 PM
 *  Author: ahmed
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_
 
#define TMR_TMR0_NORMAL_MODE   1
#define TMR_TMR0_CTC_MODE      2
#define TMR_TMR0_FAST_PWM_MODE 3

void TMR_timer0Init(void);
void TMR_timer0_OVF_SetCallBack(void(*ptr)(void));
void TMR_timer0_CTC_SetCallBack(void(*ptr)(void));
void TMR_timer0setCompareMatchValue(u8 OCR0_value);
void TMR_timer0Start(void); 
void TMR_timer0Stop(void);



#endif /* TMR_INTERFACE_H_ */