#include <lpc214x.h>

#define BIT(x)      (1 << (x))

// PIR sensor input pin (P1.24)
#define PIR_PIN     BIT(24)
#define PIR         (IO1PIN & PIR_PIN)

// LCD control pins (P0.8, P0.9, P0.10)
#define RS          BIT(8)
#define RW          BIT(9)
#define EN          BIT(10)

// Function prototypes
void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_string(const char *str);
void delay_ms(unsigned int ms);

int main(void) {
    int lastState = -1;
    int refreshCounter = 0;

    IO1DIR &= ~PIR_PIN;                 // P1.24 as input
    IO0DIR |= 0xFF | RS | RW | EN;      // P0.0–P0.7 + control pins as output

    lcd_init();

    while (1) {
        int currentState = PIR ? 0 : 1;

        // Update if PIR state changes OR every ~1s for logic toggle mode
        if (currentState != lastState || refreshCounter >= 10) {
            lcd_cmd(0x01); // Clear display
            delay_ms(2);

            if (currentState) {
                lcd_string("Motion Detected");
            } else {
                lcd_string("No Motion");
            }

            lastState = currentState;
            refreshCounter = 0;
        }

        delay_ms(100);       // Small loop delay (~100ms)
        refreshCounter++;    // Count for periodic refresh
    }
}

// Initialize LCD
void lcd_init(void) {
    delay_ms(20);  // LCD power-on delay
    lcd_cmd(0x38); // 8-bit, 2 line, 5x7 font
    lcd_cmd(0x0C); // Display ON, cursor OFF
    lcd_cmd(0x06); // Entry mode
    lcd_cmd(0x01); // Clear display
    delay_ms(2);
    lcd_cmd(0x80); // Cursor to home
}

// Send command to LCD
void lcd_cmd(unsigned char cmd) {
    IO0CLR = 0xFF;             // Clear data bits
    IO0SET = (cmd & 0xFF);     // Set data bits

    IO0CLR = RS;               // RS = 0 for command
    IO0CLR = RW;               // RW = 0 for write
    IO0SET = EN;                // EN = 1
    delay_ms(2);
    IO0CLR = EN;               // EN = 0
}

// Send data to LCD
void lcd_data(unsigned char data) {
    IO0CLR = 0xFF;             // Clear data bits
    IO0SET = (data & 0xFF);    // Set data bits

    IO0SET = RS;               // RS = 1 for data
    IO0CLR = RW;               // RW = 0 for write
    IO0SET = EN;               // EN = 1
    delay_ms(2);
    IO0CLR = EN;               // EN = 0
}

// Send string to LCD
void lcd_string(const char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

// Delay function (blocking)
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 3000; j++) {
            __asm("NOP");
        }
    }
}
