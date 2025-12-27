#include <p18f4550.h>
#include "lcd.h"

void lcd_print(unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void adc_init(void)
{
    ADCON1 = 0x0E;   // Configure AN0 as analog, rest digital
    ADCON0 = 0x00;   // Select channel 0 initially
    ADCON2 = 0x8A;   // Right justified, Tacq=2TAD, Fosc/32
}

void dectoascii(int x)
{
    int s;

    s = x / 1000;
    x = x % 1000;
    if(s != 0)
        lcd_data(s + 48);
    else
        lcd_data(48);

    s = x / 100;
    x = x % 100;
    if(s != 0)
        lcd_data(s + 48);
    else
        lcd_data(48);

    s = x / 10;
    x = x % 10;
    lcd_data(s + 48);
    lcd_data(x + 48);
}   // <-- Added missing closing brace here

void main(void)
{
    unsigned char adc[] = "ADC";
    int adc_data;

    TRISD = 0x00;
    TRISA = 0xFF;   // PORTA as input for ADC

    lcd_init();
    adc_init();

    lcd_print(adc);
    ADCON0bits.ADON = 1;   // Enable ADC

    while(1)
    {
        ADCON0 = 0x01;              // Select channel 0, turn on ADC
        ADCON0bits.GO_DONE = 1;     // Start conversion
        while(ADCON0bits.GO_DONE);  // Wait until conversion complete

        adc_data = ADRESH;          // Only 8-bit result (from high byte)

        lcd_cmd(0x80);              // Move to first line
        dectoascii(adc_data);
    }
}
