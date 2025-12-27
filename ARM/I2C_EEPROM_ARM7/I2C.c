#include <LPC214x.h>  // Header for LPC2148

#define EEPROM_ADDR   0xA0           // 8-bit I2C address (Write: 0xA0, Read: 0xA1)
#define PCLK          12000000UL     // Peripheral Clock Frequency


#define I2SCLH     (*(volatile unsigned int *)0xE001C010)
#define I2SCLL     (*(volatile unsigned int *)0xE001C014)
#define I2CONSET   (*(volatile unsigned int *)0xE001C000)
#define I2CONCLR   (*(volatile unsigned int *)0xE001C018)
#define I2STAT     (*(volatile unsigned int *)0xE001C004)
#define I2DAT      (*(volatile unsigned int *)0xE001C008)


// ===== UART Functions =====
void UART0_Init(void);
void UART0_SendChar(char c);
void UART0_SendString(char *str);

// ===== I2C Functions =====
void I2C0_Init(void);
void I2C0_Start(void);
void I2C0_Stop(void);
void I2C0_WriteByte(unsigned char data);
unsigned char I2C0_ReadByte_ACK(void);
unsigned char I2C0_ReadByte_NACK(void);

// ===== EEPROM Functions =====
void EEPROM_WriteBuffer(unsigned int addr, unsigned char *buf, unsigned int len);
void EEPROM_ReadBuffer(unsigned int addr, unsigned char *buf, unsigned int len);

// ===== Delay =====
void delay_ms(unsigned int ms);

// ===== Main Function =====
int main(void) {
    char write_buf[] = "HELLO EEPROM";
    char read_buf[sizeof(write_buf)];

    I2C0_Init();
    UART0_Init();

    UART0_SendString("Writing to EEPROM...\r\n");
    EEPROM_WriteBuffer(0x0000, (unsigned char *)write_buf, sizeof(write_buf));
    delay_ms(10);  // EEPROM write delay

    UART0_SendString("Reading back...\r\n");
    EEPROM_ReadBuffer(0x0000, (unsigned char *)read_buf, sizeof(read_buf));

    UART0_SendString("Data Read: ");
    UART0_SendString(read_buf);
    UART0_SendString("\r\n");

    while (1);  // Infinite loop
}

// ===== UART0 Implementation =====
void UART0_Init(void) {
    unsigned int baud_div;

    PINSEL0 |= (1 << 0) | (1 << 2);   // P0.0 = RXD0, P0.1 = TXD0
    U0LCR = 0x83;                     // 8-bit, 1 stop bit, enable DLAB
    baud_div = (PCLK / 16) / 9600;    // Baud rate divisor
    U0DLL = baud_div & 0xFF;
    U0DLM = baud_div >> 8;
    U0LCR = 0x03;                     // Disable DLAB
}

void UART0_SendChar(char c) {
    while (!(U0LSR & (1 << 5)));      // Wait for THR empty
    U0THR = c;
		delay_ms(5); 
}

void UART0_SendString(char *str) {
    while (*str) {
        UART0_SendChar(*str++);
    }
}

// ===== I2C0 Implementation =====
void I2C0_Init(void) {
    PINSEL0 |= (1 << 4) | (1 << 6);   // P0.2 = SCL0, P0.3 = SDA0
    I2SCLH = I2SCLL = (PCLK / (100000UL * 2));  // Set to ~100kHz
    I2CONSET = (1 << 6);              // Enable I2C
}

void I2C0_Start(void) {
    I2CONSET = (1 << 5);              // Set STA
    while (!(I2CONSET & (1 << 3)));   // Wait for SI
    I2CONCLR = (1 << 5) | (1 << 3);   // Clear STA and SI
}

void I2C0_Stop(void) {
    I2CONSET = (1 << 4);              // Set STO
    I2CONCLR = (1 << 3);              // Clear SI
}

void I2C0_WriteByte(unsigned char data) {
    I2DAT = data;
    I2CONCLR = (1 << 3);              // Clear SI
    while (!(I2CONSET & (1 << 3)));   // Wait for SI
}

unsigned char I2C0_ReadByte_ACK(void) {
    I2CONSET = (1 << 2);              // Set AA = 1 (ACK)
    I2CONCLR = (1 << 3);              // Clear SI
    while (!(I2CONSET & (1 << 3)));   // Wait for SI
    return I2DAT;
}

unsigned char I2C0_ReadByte_NACK(void) {
    I2CONCLR = (1 << 2) | (1 << 3);   // Clear AA, SI
    while (!(I2CONSET & (1 << 3)));   // Wait for SI
    return I2DAT;
}

// ===== EEPROM Implementation =====
void EEPROM_WriteBuffer(unsigned int addr, unsigned char *buf, unsigned int len) {
    unsigned int i;

    I2C0_Start();
    I2C0_WriteByte(EEPROM_ADDR);              // Write mode
    I2C0_WriteByte((addr >> 8) & 0xFF);       // Address high byte
    I2C0_WriteByte(addr & 0xFF);              // Address low byte

    for (i = 0; i < len; i++) {
        I2C0_WriteByte(buf[i]);
    }

    I2C0_Stop();
    delay_ms(5);  // EEPROM write cycle time
}

void EEPROM_ReadBuffer(unsigned int addr, unsigned char *buf, unsigned int len) {
    unsigned int i;

    I2C0_Start();
    I2C0_WriteByte(EEPROM_ADDR);              // Write mode
    I2C0_WriteByte((addr >> 8) & 0xFF);
    I2C0_WriteByte(addr & 0xFF);

    I2C0_Start();                              // Repeated Start
    I2C0_WriteByte(EEPROM_ADDR | 0x01);        // Read mode

    for (i = 0; i < len - 1; i++) {
        buf[i] = I2C0_ReadByte_ACK();
    }

    buf[len - 1] = I2C0_ReadByte_NACK();       // Final byte with NACK
    I2C0_Stop();
}

// ===== Simple Delay Function =====
void delay_ms(unsigned int ms) {
    volatile unsigned int i;
    while (ms--) {
        for (i = 0; i < 6000; i++);  // Approximate delay
    }
}
