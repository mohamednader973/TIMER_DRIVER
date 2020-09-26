/*
 * Timer.c
 *
 * Created: 9/26/2020 9:21:49 PM
 *  Author: monad
 */ 
#include "Timer.h"
void Timer_Init(void)
{
	//TCNT_REG=112;
	TCNT_CMP_REG =143;
	SetBIT(TCNT_Ctrl_REG,Prescl_0);   // Set prescalar to 64
	SetBIT(TCNT_Ctrl_REG,Prescl_1);
	ClearBIT(TCNT_Ctrl_REG,Prescl_2);
	SetBIT(TCNT_INTMSK,Timer_INT_EN);
	sei();
	
}

void Delay_Timer (unsigned char Delay_Time)
{
	overflow_counter++;
	if (overflow_counter==977)
	{
		
		CNT.counter++;
		//TCNT_REG=112;
		TCNT_CMP_REG =143;
		overflow_counter=0;
	}
	if (CNT.counter== Delay_Time-1)
	{
		PORTC ^=(1<<7);
		CNT.counter=0;
	}
}