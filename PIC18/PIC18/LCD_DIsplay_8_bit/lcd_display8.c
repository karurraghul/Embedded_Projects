#include <p18f4550.h>

// Configuration bits
#pragma config FOSC = INTOSCIO_EC   // Internal oscillator
#pragma config WDT = OFF            // Watchdog timer off
#pragma config MCLRE = ON           // MCLR pin enabled
#pragma config LVP = OFF            // Low voltage programming off
#pragma config PBADEN = OFF         // PORTB<4:0> as digital I/O

// Pin definitions to match your circuit
#define RS LATBbits.LATB0
#define EN LATBbits.LATB1
// RW is tied to ground in your circuit

// Function prototypes
void delay(unsigned int i);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_print(unsigned char *str);
void lcd_init(void);

void delay(unsigned int i)
{
    unsigned int j;
    while(i--)
    {
        for(j=0; j<1000; j++);
    }
}

void lcd_cmd(unsigned char ch)
{
    LATD = ch;          // Send full 8-bit command directly
    RS = 0;             // Command mode
    EN = 1;             // Enable high
    delay(2);           // Hold enable
    EN = 0;             // Enable low
    delay(2);           // Command processing time
}

void lcd_data(unsigned char ch)
{
    LATD = ch;          // Send full 8-bit data directly  
    RS = 1;             // Data mode
    EN = 1;             // Enable high
    delay(2);           // Hold enable
    EN = 0;             // Enable low
    delay(2);           // Data processing time
}

void lcd_print(unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void lcd_init(void)
{
    // Initialize ports
    TRISD = 0x00;       // PORTD as output for data
    TRISBbits.TRISB0 = 0;  // RB0 (RS) as output
    TRISBbits.TRISB1 = 0;  // RB1 (EN) as output
    
    // Initialize control pins
    RS = 0;
    EN = 0;
    LATD = 0x00;
    
    // Wait for LCD power up
    delay(50);
    
    // LCD initialization sequence (8-bit mode)
    lcd_cmd(0x30);      // Function set: 8-bit interface
    delay(5);
    lcd_cmd(0x30);      // Function set: 8-bit interface  
    delay(1);
    lcd_cmd(0x30);      // Function set: 8-bit interface
    delay(1);
    
    // Configure LCD for 8-bit, 2-line operation
    lcd_cmd(0x38);      // Function set: 8-bit, 2 lines, 5x7 font
    lcd_cmd(0x08);      // Display off
    lcd_cmd(0x01);      // Clear display
    delay(2);           // Clear command needs extra time
    lcd_cmd(0x06);      // Entry mode: increment cursor
    lcd_cmd(0x0C);      // Display on, cursor off
}

void main()
{
    unsigned char str1[] = "LIVE WIRE";
    unsigned char str2[] = "Training";
    
    // Set internal oscillator to 8MHz
    OSCCON = 0x72;
    
    TRISD = 0x00;       // PORTD as output
    lcd_init();         // Initialize LCD
    
    lcd_print(str1);    // Display first string
    lcd_cmd(0xC0);      // Move to second line (address 0xC0)
    lcd_print(str2);    // Display second string
    
    while(1)            // Stay here forever
    {
        // Optional: Add blinking or updating display
        delay(1000);
        lcd_cmd(0x01);  // Clear screen
        delay(2);
        lcd_print(str1);
        lcd_cmd(0xC0);
        lcd_print(str2);
        delay(1000);
    }
}