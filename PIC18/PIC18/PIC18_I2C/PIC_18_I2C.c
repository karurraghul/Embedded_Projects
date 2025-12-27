// PIC18F4550 I2C EEPROM (24LC256) - OPTIMIZED FOR OSCILLOSCOPE VIEWING
// MPLAB C18 Compiler
// Perfect waveforms for analysis

#include <p18f4550.h>
#include <delays.h>

// Configuration bits
#pragma config FOSC = HS        // High Speed Crystal
#pragma config WDT = OFF        // Watchdog Timer disabled
#pragma config LVP = OFF        // Low Voltage Programming disabled
#pragma config PBADEN = OFF     // PORTB pins are digital I/O
#pragma config MCLRE = ON       // MCLR enabled
#pragma config PWRT = ON        // Power-up Timer enabled

// 24LC256 I2C Address
#define EEPROM_ADDR 0xA0        // Write address (0x50 << 1)

// LED indicator on RA0 (optional - to see when operations occur)
#define LED_PIN LATAbits.LATA0

// Function Prototypes
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Write(unsigned char data);
unsigned char I2C_Read(unsigned char ack);
void I2C_Wait(void);

void EEPROM_WriteByte(unsigned int address, unsigned char data);
unsigned char EEPROM_ReadByte(unsigned int address);

void DelayMs(unsigned int ms);
void DelayUs(unsigned int us);

// Precise delay functions
void DelayMs(unsigned int ms) {
    unsigned int i;
    for(i = 0; i < ms; i++) {
        Delay1KTCYx(5);  // 5ms with 20MHz
    }
}

void DelayUs(unsigned int us) {
    unsigned int i;
    for(i = 0; i < us; i++) {
        Delay10TCYx(2);  // ~10us with 20MHz
    }
}

// I2C Functions
void I2C_Init(void) {
    SSPCON1 = 0x28;             // I2C Master mode
    SSPCON2 = 0x00;
    SSPADD = 49;                // 100kHz I2C clock with 20MHz crystal
    SSPSTAT = 0x80;             // Slew rate control disabled for standard mode
    
    TRISBbits.TRISB0 = 1;       // SDA as input
    TRISBbits.TRISB1 = 1;       // SCL as input
}

void I2C_Wait(void) {
    while((SSPCON2 & 0x1F) || (SSPSTATbits.R_W));
}

void I2C_Start(void) {
    I2C_Wait();
    SSPCON2bits.SEN = 1;        // Initiate Start condition
    while(SSPCON2bits.SEN);     // Wait for Start to complete
}

void I2C_Stop(void) {
    I2C_Wait();
    SSPCON2bits.PEN = 1;        // Initiate Stop condition
    while(SSPCON2bits.PEN);     // Wait for Stop to complete
}

void I2C_Restart(void) {
    I2C_Wait();
    SSPCON2bits.RSEN = 1;       // Initiate Restart condition
    while(SSPCON2bits.RSEN);    // Wait for Restart to complete
}

void I2C_Write(unsigned char data) {
    I2C_Wait();
    SSPBUF = data;              // Load data into buffer
    while(SSPSTATbits.BF);      // Wait until write complete
    I2C_Wait();
}

unsigned char I2C_Read(unsigned char ack) {
    unsigned char data;
    I2C_Wait();
    SSPCON2bits.RCEN = 1;       // Enable receive mode
    while(!SSPSTATbits.BF);     // Wait for buffer full
    data = SSPBUF;              // Read received data
    I2C_Wait();
    
    if(ack) {
        SSPCON2bits.ACKDT = 0;  // Send ACK
    } else {
        SSPCON2bits.ACKDT = 1;  // Send NACK
    }
    SSPCON2bits.ACKEN = 1;      // Initiate ACK/NACK
    while(SSPCON2bits.ACKEN);   // Wait for ACK/NACK to complete
    
    return data;
}

// EEPROM Single Byte Write
void EEPROM_WriteByte(unsigned int address, unsigned char data) {
    unsigned char addr_high;
    unsigned char addr_low;
    
    addr_high = (unsigned char)(address >> 8);
    addr_low = (unsigned char)(address & 0xFF);
    
    I2C_Start();                // START condition
    I2C_Write(EEPROM_ADDR);     // Device address + Write bit (0xA0)
    I2C_Write(addr_high);       // Memory address high byte
    I2C_Write(addr_low);        // Memory address low byte
    I2C_Write(data);            // Data byte to write
    I2C_Stop();                 // STOP condition
    
    DelayMs(5);                 // EEPROM write cycle time (5ms max)
}

// EEPROM Single Byte Read
unsigned char EEPROM_ReadByte(unsigned int address) {
    unsigned char data;
    unsigned char addr_high;
    unsigned char addr_low;
    
    addr_high = (unsigned char)(address >> 8);
    addr_low = (unsigned char)(address & 0xFF);
    
    I2C_Start();                // START condition
    I2C_Write(EEPROM_ADDR);     // Device address + Write bit (0xA0)
    I2C_Write(addr_high);       // Memory address high byte
    I2C_Write(addr_low);        // Memory address low byte
    
    I2C_Restart();              // RESTART condition
    I2C_Write(EEPROM_ADDR | 0x01);  // Device address + Read bit (0xA1)
    data = I2C_Read(0);         // Read byte with NACK
    I2C_Stop();                 // STOP condition
    
    return data;
}

// Main Function - OPTIMIZED FOR SCOPE VIEWING
void main(void) {
    unsigned char readData;
    
    // Configure ports
    ADCON1 = 0x0F;              // All digital I/O
    TRISAbits.TRISA0 = 0;       // RA0 as output for LED indicator
    LED_PIN = 0;                // LED off initially
    
    // Initialize I2C
    I2C_Init();
    
    DelayMs(100);               // Initial stabilization delay
    
    // ============================================================
    // TEST PATTERN 1: Simple Single Byte Write (Best for START/STOP)
    // ============================================================
    LED_PIN = 1;                // Turn on LED during operation
    EEPROM_WriteByte(0x0000, 0xAA);
    LED_PIN = 0;
    DelayMs(500);               // Long delay to separate transactions
    
    // ============================================================
    // TEST PATTERN 2: Single Byte Read (Shows RESTART condition)
    // ============================================================
    LED_PIN = 1;
    readData = EEPROM_ReadByte(0x0000);
    LED_PIN = 0;
    DelayMs(500);
    
    // ============================================================
    // TEST PATTERN 3: Write Different Data Patterns (for bit analysis)
    // ============================================================
    LED_PIN = 1;
    EEPROM_WriteByte(0x0001, 0x55);  // Pattern: 01010101
    LED_PIN = 0;
    DelayMs(500);
    
    LED_PIN = 1;
    EEPROM_WriteByte(0x0002, 0xFF);  // Pattern: 11111111
    LED_PIN = 0;
    DelayMs(500);
    
    LED_PIN = 1;
    EEPROM_WriteByte(0x0003, 0x00);  // Pattern: 00000000
    LED_PIN = 0;
    DelayMs(500);
    
    // ============================================================
    // TEST PATTERN 4: Sequential Writes (to see multiple transactions)
    // ============================================================
    LED_PIN = 1;
    EEPROM_WriteByte(0x0010, 0x11);
    DelayMs(10);                // Short delay between writes
    EEPROM_WriteByte(0x0011, 0x22);
    DelayMs(10);
    EEPROM_WriteByte(0x0012, 0x33);
    LED_PIN = 0;
    DelayMs(500);
    
    // ============================================================
    // TEST PATTERN 5: Sequential Reads
    // ============================================================
    LED_PIN = 1;
    readData = EEPROM_ReadByte(0x0010);
    DelayMs(10);
    readData = EEPROM_ReadByte(0x0011);
    DelayMs(10);
    readData = EEPROM_ReadByte(0x0012);
    LED_PIN = 0;
    DelayMs(500);
    
    // ============================================================
    // MAIN LOOP: Continuous operation with clear patterns
    // ============================================================
    while(1) {
        // Pattern A: Write 0xAA
        LED_PIN = 1;
        EEPROM_WriteByte(0x0100, 0xAA);
        LED_PIN = 0;
        DelayMs(1000);          // 1 second pause for easy triggering
        
        // Pattern B: Read back
        LED_PIN = 1;
        readData = EEPROM_ReadByte(0x0100);
        LED_PIN = 0;
        DelayMs(1000);
        
        // Pattern C: Write 0x55
        LED_PIN = 1;
        EEPROM_WriteByte(0x0100, 0x55);
        LED_PIN = 0;
        DelayMs(1000);
        
        // Pattern D: Read back
        LED_PIN = 1;
        readData = EEPROM_ReadByte(0x0100);
        LED_PIN = 0;
        DelayMs(1000);
    }
}