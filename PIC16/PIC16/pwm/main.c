#include "Includes.h"

// Configuration word for PIC16F877A
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & CP_OFF & BOREN_ON
         & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

// Define CPU Frequency
// This must be defined, if __delay_ms() or 
// __delay_us() functions are used in the code
#define _XTAL_FREQ   20000000  


// Main function
void main(void)
{
	InitPWM();	

	SetPWMDutyCycle(1,127);   //50% duty cycle on CCP1
	SetPWMDutyCycle(2,127);   //75% duty cycle on CCP2

	while(1)
	{
		
	}
}