#include <p18f4550.h>
#include <spi.h>
#include <delays.h>

// Configuration bits (adjust if needed)
#pragma config FOSC = HSPLL_HS, WDT = OFF, LVP = OFF, MCLRE = ON

#define CS      LATAbits.LATA5   // Chip Select for MCP4921
#define CS_TRIS TRISAbits.TRISA5

void MCP4921_Send(unsigned int value);

void main(void) {
    unsigned int i;

    // Configure RA5 as output for CS
    CS_TRIS = 0;
    CS = 1; // CS idle high

    // Configure SPI pins:
    // RB1 = SCK (output), RC7 = SDO (output), RB0 = SDI (input, not used here)
    TRISBbits.TRISB1 = 0;  
    TRISCbits.TRISC7 = 0;  
    TRISBbits.TRISB0 = 1;  

    // Open SPI: Master, Fosc/16, Mode 0, sample at end
    OpenSPI(SPI_FOSC_16, MODE_00, SMPEND);

    while(1) {
        // Generate sawtooth by sending values 0–4095
        for(i = 0; i < 4096; i+=64) {
            MCP4921_Send(i);
            //Delay1KTCYx(1000);  // Small delay (tune as needed)
        }
    }
}

// Function to send 12-bit data to MCP4921
void MCP4921_Send(unsigned int value) {
    unsigned char highByte, lowByte;

    // MCP4921 control bits:
    // bit15: 0=write to DAC A
    // bit14: BUF (0=unbuffered)
    // bit13: GA (1=1x gain)
    // bit12: SHDN (1=active)
    // bits11-0: data
    unsigned int command = 0x3000;  // 0b0011xxxx.... (DAC A, unbuffered, gain=1x, active)
    command |= (value & 0x0FFF);    // add 12-bit value

    highByte = (command >> 8) & 0xFF;
    lowByte  = command & 0xFF;

    CS = 0;             // Select DAC
    WriteSPI(highByte); // Send high byte
    WriteSPI(lowByte);  // Send low byte
    CS = 1;             // Deselect DAC
}
