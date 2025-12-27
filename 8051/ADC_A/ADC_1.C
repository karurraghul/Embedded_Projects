#include <reg51.h>

// Pin declarations
sbit ale    = P1 ^ 0;
sbit oe     = P1 ^ 3;
sbit sc     = P1 ^ 1;
sbit eoc    = P1 ^ 2;
sbit clk    = P1 ^ 7;
sbit add_a  = P1 ^ 4;
sbit add_b  = P1 ^ 5;
sbit add_c  = P1 ^ 6;

#define lcd_datapin P2
sbit rs = P3 ^ 0;
sbit rw = P3 ^ 1;
sbit en = P3 ^ 6;

#define input_port P0

unsigned int bitvalue, key1, decimal_value, value, number;
unsigned int ascii1, ascii2, ascii3, flag, key;

// Timer interrupt to toggle clock
void timer0() interrupt 1 {
    clk = ~clk;
}

// Delay function
void delay(unsigned int count) {
    int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 1275; j++);
}

// LCD command function
void lcd_command(unsigned char comm) {
    lcd_datapin = comm;
    rs = 0;
    rw = 0;
    en = 1;
    delay(10);
    en = 0;
}

// LCD data function
void lcd_data(unsigned char disp) {
    lcd_datapin = disp;
    en = 1;
    rs = 1;
    rw = 0;
    delay(10);
    en = 0;
}

// Send string to LCD
void lcd_dataa(unsigned char *disp) {
    int x;
    for (x = 0; disp[x] != 0; x++) {
        lcd_data(disp[x]);
    }
}

// Initialize LCD
void lcd_ini() {
    lcd_command(0x38);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x80);
}

// Convert and display BCD value
void bcd() {
    key1++;
    key = 0;
    flag = 0;

    number = input_port;
    value = number % 10;
    number = number / 10;
    ascii1 = value + 48;

    if (number != 0) {
        value = number % 10;
        number = number / 10;
        ascii2 = value + 48;
        flag = 1;
    } else {
        ascii2 = 48;
        flag = 1;
    }

    if (number != 0) {
        value = number % 10;
        number = number / 10;
        ascii3 = value + 48;
        key = 2;
    } else {
        ascii3 = 48;
        key = 2;
    }

    if (key == 2) lcd_data(ascii3);
    if (flag == 1) lcd_data(ascii2);
    lcd_data(ascii1);

    if (key1 == 3) {
        key1 = 0;
        ascii3 = 0;
        ascii2 = 0;
        ascii1 = 0;
        delay(10);
    }
}

// ADC function
void adc() {
    while (1) {
        add_c = 0;
        add_b = 0;
        add_a = 1;

        delay(2);
        ale = 1;
        delay(2);
        sc = 1;
        delay(1);
        sc = 0;

        while (eoc == 1);
        while (eoc == 0);

        oe = 1;
        bcd();
        lcd_command(0x88);
        delay(2);
        oe = 0;
    }
}

// Main function
void main() {
    eoc = 1;
    ale = 0;
    oe = 0;
    sc = 0;
    key1 = 0;

    TMOD = 0x02;
    TH0 = 0xFD;
    IE = 0x82;
    TR0 = 1;

    lcd_ini();
    lcd_dataa("value:");
    lcd_command(0x88);

    adc();
}
