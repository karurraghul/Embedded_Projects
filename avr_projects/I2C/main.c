/*
 * I2CDateTime.c
 *
 * Created: 27-09-2025 10:30:52
 * Author : karur
 */ 

#define F_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>

// LCD connection
#define LCD_PORTA PORTA
#define LCD_DDR   DDRA

// Function prototypes
void serial_ini();
void serial_tr(unsigned char);
void serial_tr_bcd(unsigned char);
void i2c_ini();
void i2c_start();
void i2c_wr(unsigned char);
unsigned char i2c_re(unsigned char);
void i2c_stop();
void rtc_ini();
void rtc_set_t(unsigned char h, unsigned char m, unsigned char s);
void rtc_set_d(unsigned char y, unsigned char m, unsigned char d);
void rtc_get_t(unsigned char *h, unsigned char *m, unsigned char *s);
void rtc_get_d(unsigned char *y, unsigned char *m, unsigned char *d);
void cmd(unsigned char x);
void lcd_display(unsigned char x);
void lcd_ini();
void lcd_str(char *str);
void lcd_pos(int line, int pos);

int main()
{
    unsigned char i, j, k, p, q, r;
    LCD_DDR = 0xFF;  // LCD data as output
    DDRB = 0xFF;     // LCD control as output
    
    rtc_ini();
	rtc_set_t(0x10, 0x52, 0x00); // 10:52:00 (current time)
	rtc_set_d(0x25, 0x09, 0x27); // 27/09/2025 (today's date)
    
    serial_ini();
    lcd_ini();
    lcd_str("TIME");
    lcd_pos(2, 0);
    lcd_str("DATE");
    
    while (1)
    {
        // time
        lcd_pos(1, 6);
        rtc_get_t(&i, &j, &k);
        lcd_display('0' + (i >> 4));
        lcd_display('0' + (i & 0x0F));
        lcd_display(':');
        lcd_display('0' + (j >> 4));
        lcd_display('0' + (j & 0x0F));
        lcd_display(':');
        lcd_display('0' + (k >> 4));
        lcd_display('0' + (k & 0x0F));
        _delay_ms(500);

        // date
        lcd_pos(2, 6);
        rtc_get_d(&p, &q, &r);
        lcd_display('0' + (r >> 4));
        lcd_display('0' + (r & 0x0F));
        lcd_display('/');
        lcd_display('0' + (q >> 4));
        lcd_display('0' + (q & 0x0F));
        lcd_display('/');
        lcd_display('0' + (p >> 4));
        lcd_display('0' + (p & 0x0F));
        _delay_ms(500);
    }
    
    return 0;
}

// ---------------- UART ----------------
void serial_ini()
{
    UCSRB = (1 << TXEN);                             // Enable transmitter
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); // 8-bit data
    UBRRL = 0x33;                                    // Baud rate
}

void serial_tr(unsigned char x)
{
    while (!(UCSRA & (1 << UDRE))); // Wait for empty buffer
    UDR = x;
    while (!(UCSRA & (1 << TXC)));  // Wait for transmission complete
    UCSRA |= (1 << TXC);            // Clear TXC
}

void serial_tr_bcd(unsigned char x)
{
    serial_tr('0' + (x >> 4));
    serial_tr('0' + (x & 0x0F));
}

// ---------------- I2C ----------------
void i2c_ini()
{
    TWSR = 0x00;
    TWBR = 0x47;
    TWCR = 0x04;
}

void i2c_start()
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_wr(unsigned char x)
{
    TWDR = x;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

unsigned char i2c_re(unsigned char ack)
{
    if (ack)
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    else
        TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

void i2c_stop()
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
    _delay_ms(1);
}

// ---------------- RTC (DS1307) ----------------
void rtc_ini()
{
    i2c_ini();
    i2c_start();
    i2c_wr(0xD0); // DS1307 write
    i2c_wr(0x07); // Control register
    i2c_wr(0x00); // Enable oscillator
    i2c_stop();
}

void rtc_set_t(unsigned char h, unsigned char m, unsigned char s)
{
    i2c_start();
    i2c_wr(0xD0);
    i2c_wr(0x00);
    i2c_wr(s);
    i2c_wr(m);
    i2c_wr(h);
    i2c_stop();
}

void rtc_set_d(unsigned char y, unsigned char m, unsigned char d)
{
    i2c_start();
    i2c_wr(0xD0);
    i2c_wr(0x04);
    i2c_wr(d);
    i2c_wr(m);
    i2c_wr(y);
    i2c_stop();
}

void rtc_get_t(unsigned char *h, unsigned char *m, unsigned char *s)
{
    i2c_start();
    i2c_wr(0xD0);
    i2c_wr(0x00);
    i2c_stop();

    i2c_start();
    i2c_wr(0xD1);
    *s = i2c_re(1);
    *m = i2c_re(1);
    *h = i2c_re(0);
    i2c_stop();
}

void rtc_get_d(unsigned char *y, unsigned char *m, unsigned char *d)
{
    i2c_start();
    i2c_wr(0xD0);
    i2c_wr(0x04);
    i2c_stop();

    i2c_start();
    i2c_wr(0xD1);
    *d = i2c_re(1);
    *m = i2c_re(1);
    *y = i2c_re(0);
    i2c_stop();
}

// ---------------- LCD ----------------
void cmd(unsigned char x)
{
    LCD_PORTA = x;
    PORTB = (0 << 0) | (0 << 1) | (0 << 2);
    _delay_ms(2);
    PORTB = (0 << 0) | (0 << 1) | (1 << 2);
    _delay_ms(2);
    PORTB = (0 << 0) | (0 << 1) | (0 << 2);
}

void lcd_display(unsigned char x)
{
    LCD_PORTA = x;
    PORTB = (1 << 0) | (0 << 1) | (0 << 2);
    _delay_ms(2);
    PORTB = (1 << 0) | (0 << 1) | (1 << 2);
    _delay_ms(2);
    PORTB = (1 << 0) | (0 << 1) | (0 << 2);
}

void lcd_ini()
{
    cmd(0x38); // 8-bit, 2 lines, 5x7
    cmd(0x0C); // Display ON, cursor OFF
    cmd(0x01); // Clear display
    cmd(0x06); // Increment cursor
}

void lcd_str(char *str)
{
    while (*str != '\0')
    {
        lcd_display(*str);
        str++;
    }
}

void lcd_pos(int line, int pos)
{
    if (line == 1)
        cmd(0x80 + pos);
    else if (line == 2)
        cmd(0xC0 + pos);
}
