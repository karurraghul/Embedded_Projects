/*
 * ATmega16 + USART + 16x2 LCD (4-bit mode)
 * RW tied to GND (write-only)
 * F_CPU = 8 MHz, Baud = 9600
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

/* Connections (must match Proteus wiring)
   RS -> PD2 (pin 16)
   RW -> GND
   EN -> PD3 (pin 17)
   D4 -> PD4 (pin 18)
   D5 -> PD5 (pin 19)
   D6 -> PD6 (pin 20)
   D7 -> PD7 (pin 21)

   USART:
   RXD (PD0 pin14) <- VirtualTerminal TXD
   TXD (PD1 pin15) -> VirtualTerminal RXD
*/

#define LCD_PORT PORTD
#define LCD_DDR  DDRD
#define RS PD2
#define EN PD3

/* send 4-bit nibble (upper: boolean indicates whether sending high nibble already)
   We will place nibble in PD4..PD7 position (bits 4..7 of PORTD).
*/
static void lcd_nibble_write(uint8_t nibble)
{
    // nibble expected in lower 4 bits (0..3) ; move to bits 4..7
    uint8_t port = LCD_PORT & 0x0F;             // preserve lower 4 bits (PD0..PD3)
    port |= (nibble << 4);                      // put nibble to PD4..PD7
    LCD_PORT = port;
}

/* send command */
void lcd_cmd(uint8_t cmd)
{
    // high nibble
    LCD_PORT &= ~(1<<RS);           // RS = 0 (command)
    lcd_nibble_write((cmd >> 4) & 0x0F);
    // pulse EN
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_us(100);

    // low nibble
    lcd_nibble_write(cmd & 0x0F);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(2);
}

/* send data (character) */
void lcd_data(uint8_t data)
{
    // high nibble
    LCD_PORT |= (1<<RS);            // RS = 1 (data)
    lcd_nibble_write((data >> 4) & 0x0F);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_us(100);

    // low nibble
    lcd_nibble_write(data & 0x0F);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(2);
}

void lcd_init(void)
{
    LCD_DDR = 0xFF;           // make PORTD outputs (PD0..PD7). Be cautious: PD0/PD1 are UART pins �
                              // It's OK to set DDR as outputs after init; but for UART they must be controlled by hardware.
                              // To be safe, we set DDR for PD2..PD7 only below.
    // set PD0 and PD1 as inputs initially for UART
    DDRD &= ~((1<<PD0)|(1<<PD1));   // PD0/PD1 = input (UART)
    // ensure PD2..PD7 are outputs
    DDRD |= ((1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7));

    _delay_ms(40);

    // Initialization sequence for 4-bit mode
    // According to HD44780 initialization: send 0x03 three times then 0x02
    lcd_nibble_write(0x03);
    LCD_PORT &= ~(1<<RS); // command
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(5);

    lcd_nibble_write(0x03);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(5);

    lcd_nibble_write(0x03);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(1);

    lcd_nibble_write(0x02);   // set to 4-bit mode
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(1);

    // Function set: 4-bit, 2 lines, 5x8 dots
    lcd_cmd(0x28);
    // Display on, cursor off, blink off
    lcd_cmd(0x0C);
    // Entry mode set: increment, no shift
    lcd_cmd(0x06);
    // Clear display
    lcd_cmd(0x01);
    _delay_ms(2);
}

/* simple string print */
void lcd_string(const char *s)
{
    while(*s) {
        lcd_data((uint8_t)*s++);
    }
}

/* USART functions */
void USART_Init(unsigned int ubrr)
{
    // set baud rate
    UBRRH = (unsigned char)(ubrr >> 8);
    UBRRL = (unsigned char)ubrr;
    // enable receiver and transmitter
    UCSRB = (1<<RXEN) | (1<<TXEN);
    // frame format: 8data, 1stop
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
}

uint8_t USART_RxChar(void)
{
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

int main(void)
{
    uint8_t c;

    // init LCD
    lcd_init();

    // init USART: UBRR = 51 for 9600 @ 8MHz
    USART_Init(51);

    // show a header
    lcd_string("USART -> LCD");

    // main loop: echo each received char to LCD
    while(1)
    {
        c = USART_RxChar();
        // optional: handle CR/LF as new line logic or move cursor
        // simply display characters continuously; if you want newline handling,
        // add logic to move to second row on seeing '\n' or 16 chars etc.
        lcd_data(c);
    }

    return 0;
}
