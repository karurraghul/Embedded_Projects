#include <p18f4450.h>    // Device header file

#define LED LATD         // Alias for PORTD latch

void delay(unsigned int j);

//------------------ MAIN ------------------//
void main(void) {
    unsigned char pos;   // pos = variable for LED position

    TRISD = 0x00;        // Set PORTD as output
    LED   = 0x00;        // Clear all LEDs

    while(1) {
        LED = 0x01;      // Start with first LED ON
        delay(200);

        for(pos = 0; pos < 7; pos++) {
            LED = LED << 1;   // Shift LED left
            delay(200);
        }
    }
}

//------------------ DELAY ------------------//
void delay(unsigned int j) {
    unsigned char i;
    for(; j > 0; j--) {
        for(i = 250; i > 0; i--);
    }
}
