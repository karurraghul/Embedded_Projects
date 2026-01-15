/*
 * SPI_Comm.c
 *
 * Created: 28-09-2025
 * Author : karur
 *
 * ATmega16 (Master) ---- MAX7221 (Slave)
 * MOSI -> DIN
 * SCK  -> CLK
 * SS   -> CS
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define MOSI 5   // PB5
#define SCK  7   // PB7
#define SS   4   // PB4

// Lookup table for displaying numbers 0-9 in raw 7-segment format
// (Only used if decode mode is OFF)
int seg_table[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

// Digit positions in MAX7221 (1 = rightmost digit, 8 = leftmost)
int digit_pos[8] = {1,2,3,4,5,6,7,8};

void spi_init();
void spi_transmit(unsigned char cmd, unsigned char data);
void max7221_init();

int main(void)
{
    int a,b,c,d,e,f,g,h;
    a=b=c=d=e=f=g=h=0;

    spi_init();       // Initialize SPI
    max7221_init();   // Initialize MAX7221

    while(1)
    {
        // Update all 8 digits
        spi_transmit(digit_pos[7], seg_table[a]);
        spi_transmit(digit_pos[6], seg_table[b]);
        spi_transmit(digit_pos[5], seg_table[c]);
        spi_transmit(digit_pos[4], seg_table[d]);
        spi_transmit(digit_pos[3], seg_table[e]);
        spi_transmit(digit_pos[2], seg_table[f]);
        spi_transmit(digit_pos[1], seg_table[g]);
        spi_transmit(digit_pos[0], seg_table[h]);

        // Increment digit counters like a digital counter
        a++;
        if (a==10) { a=0; b++; }
        if (b==10) { b=0; c++; }
        if (c==10) { c=0; d++; }
        if (d==10) { d=0; e++; }
        if (e==10) { e=0; f++; }
        if (f==10) { f=0; g++; }
        if (g==10) { g=0; h++; }
        if (h==10) { h=0; }

        _delay_ms(2);
    }
}

/* ---------------- SPI FUNCTIONS ---------------- */

void spi_init()
{
    // MOSI, SCK, SS as output
    DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);

    // Enable SPI, Master Mode, Clock = Fosc/64
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);
}

void spi_transmit(unsigned char cmd, unsigned char data)
{
    PORTB &= ~(1<<SS);      // Pull SS low to select MAX7221

    SPDR = cmd;             // Send command (digit address or register)
    while(!(SPSR & (1<<SPIF))); // Wait until transfer complete

    SPDR = data;            // Send data (digit value or setting)
    while(!(SPSR & (1<<SPIF))); // Wait until transfer complete

    PORTB |= (1<<SS);       // Pull SS high to deselect MAX7221
}

/* ---------------- MAX7221 INITIALIZATION ---------------- */
void max7221_init()
{
    // Decode mode OFF (we send raw 7-seg codes from seg_table[])
    spi_transmit(0x09, 0x00);

    // Intensity (0x0 to 0xF) -> medium brightness
    spi_transmit(0x0A, 0x0F);

    // Scan limit -> use all 8 digits (0-7)
    spi_transmit(0x0B, 0x07);

    // Shutdown register -> Normal operation
    spi_transmit(0x0C, 0x01);

    // Display test -> OFF
    spi_transmit(0x0F, 0x00);

    // Clear all digits initially
    for (int i=1; i<=8; i++) {
        spi_transmit(i, 0x00);
    }
}

