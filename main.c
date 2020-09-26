/*
 * Timer_Driver.c
 *
 * Created: 9/26/2020 9:21:22 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "Timer.h"
int main(void)
{
	Timer_Init();
    /* Replace with your application code */
    while (1) 
    {
    }
}
ISR (TIMER0_OVF_vect)
{
	Delay_Timer(3);
}
ISR (TIMER0_COMP_vect)
{
	if (overflow_counter==0)
	{
		TCNT0=0;
	}
	
}
