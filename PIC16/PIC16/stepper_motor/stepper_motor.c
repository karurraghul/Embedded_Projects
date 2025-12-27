#include <htc.h>  // For Hi-Tech C
#define _XTAL_FREQ 8000000  // Define your crystal frequency

#define stepper PORTC

void delay(unsigned int time)
{
    while(time--)
        __delay_ms(1);
}

void main()
{
    TRISC = 0x00;    // Set PORTC as output
    PORTC = 0x00;    // Initialize PORTC to 0

    while(1)
    {
        stepper = 0x01;  // Step 1
        delay(100);

        stepper = 0x03;  // Step 2
        delay(100);

        stepper = 0x02;  // Step 3
        delay(100);

        stepper = 0x06;  // Step 4
        delay(100);

        stepper = 0x04;  // Step 5
        delay(100);

        stepper = 0x0C;  // Step 6
        delay(100);

        stepper = 0x08;  // Step 7
        delay(100);

        stepper = 0x09;  // Step 8
        delay(100);
    }
}
