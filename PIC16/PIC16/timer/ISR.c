#include "Includes.h"


void interrupt ISR(void)
{
	if(TMR1IF)  //If Timer1 Interrupt
	{
		RB0 = ~RB0;  //	Toggle RB0 pin	

		TMR1IF = 0;    // clear the interrupt
	}
}