#include "Includes.h"
 
// Configuration word for PIC16F877A
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & CP_OFF & BOREN_ON
         & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

// Main Function
void main(void)
{
	TRISB0 = 0;				   // Make RB0 pin output
	RB0    = 0;				   // Make RB0 low
	
	InitTimer1();			   // Initialize timer 1
	
	while(1)
	{
	}
}