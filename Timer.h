/*
 * Timer.h
 *
 * Created: 9/26/2020 9:22:02 PM
 *  Author: monad
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <avr/interrupt.h>
#include <avr/io.h>
#define TCNT_Ctrl_REG (*((volatile unsigned char*)0x53))             //TCCR0
#define TCNT_REG      (*((volatile unsigned char*)0x52))            //TCNT0
#define TCNT_INTMSK   (*((volatile unsigned char*)0x59))           //TIMSK
#define TCNT_CMP_REG   (*((volatile unsigned char*)0x5C))          //OCR0
#define SetBIT(REG,BIT)    REG |=(1<<BIT)
#define ClearBIT(REG,BIT)  REG &=~(1<<BIT)
#define Prescl_2      2
#define Prescl_1      1
#define Prescl_0      0
#define WaveGenbit_0  6
#define WaveGenbit_1  3
#define Timer_INT_EN  0
volatile unsigned short overflow_counter;
void Timer_Init(void);
void Delay_Timer (unsigned char Delay_Time);
struct structure {
	unsigned short counter;
}CNT;




#endif /* TIMER_H_ */