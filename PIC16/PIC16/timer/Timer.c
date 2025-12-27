#include "Includes.h"




void InitTimer1(void)
{	
	TMR1H = 0;				// Cleat timer1 registers
	TMR1L = 0;				// before enabling timer1

	// Timer1 is 16bit timer
	T1CON = 0x01;			// Prescalar 1:1, Timer1 On

	TMR1IF = 0;				// Clear interrupt bit
	TMR1IE = 1;				// Enable Timer1 interrupt
	PEIE = 1; 				// Enable peripheral interrupts
	GIE = 1;				// Enable global interrupts
}