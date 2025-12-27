#include <LPC214x.h>

#define EEPROM_ADDR_WRITE 0xA0
#define EEPROM_ADDR_READ  0xA1

// I2C Status codes
#define I2C_START_TRANSMITTED     0x08
#define I2C_RESTART_TRANSMITTED   0x10
#define I2C_SLA_W_ACK             0x18
#define I2C_SLA_R_ACK             0x40
#define I2C_DATA_TRANSMITTED_ACK  0x28
#define I2C_DATA_RECEIVED_NACK    0x58

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 6000; j++);
}

void I2C_Init() {
    PINSEL0 &= ~0x000000F0;
    PINSEL0 |= 0x00000050;
    I2C0CONCLR = 0x6C;
    I2C0SCLH = 60;
    I2C0SCLL = 60;
    I2C0CONSET = 0x40;
}

unsigned char I2C_GetStatus() {
    return (I2C0STAT & 0xF8);
}

void I2C_Start() {
    I2C0CONCLR = 0x28;
    I2C0CONSET = 0x20;
    while (!(I2C0CONSET & 0x08));
}

void I2C_Stop() {
    I2C0CONSET = 0x10;
    I2C0CONCLR = 0x08;
    while (I2C0CONSET & 0x10);
}

unsigned char I2C_Write(unsigned char data) {
    I2C0DAT = data;
    I2C0CONCLR = 0x08;
    while (!(I2C0CONSET & 0x08));
    return I2C_GetStatus();
}

unsigned char I2C_Read(unsigned char ack) {
    if (ack)
        I2C0CONSET = 0x04;
    else
        I2C0CONCLR = 0x04;
    
    I2C0CONCLR = 0x08;
    while (!(I2C0CONSET & 0x08));
    return I2C0DAT;
}

void UART0_Init() {
    PINSEL0 &= ~0x0000000F;
    PINSEL0 |= 0x00000005;
    U0LCR = 0x83;
    U0DLL = 78;
    U0DLM = 0;
    U0LCR = 0x03;
    U0FCR = 0x07;
}

void UART0_SendChar(char ch) {
    while (!(U0LSR & 0x20));
    U0THR = ch;
}

void UART0_SendString(const char *str) {
    while (*str) {
        UART0_SendChar(*str++);
    }
}

void UART0_SendHex(unsigned char value) {
    char hex[] = "0123456789ABCDEF";
    UART0_SendString("0x");
    UART0_SendChar(hex[(value >> 4) & 0x0F]);
    UART0_SendChar(hex[value & 0x0F]);
}

unsigned char EEPROM_Write(unsigned short addr, unsigned char data) {
    unsigned char status;
    I2C_Start();
    status = I2C_GetStatus();
    if (status != I2C_START_TRANSMITTED) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(EEPROM_ADDR_WRITE);
    if (status != I2C_SLA_W_ACK) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write((addr >> 8) & 0xFF);
    if (status != I2C_DATA_TRANSMITTED_ACK) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(addr & 0xFF);
    if (status != I2C_DATA_TRANSMITTED_ACK) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(data);
    if (status != I2C_DATA_TRANSMITTED_ACK) {
        I2C_Stop();
        return 0;
    }

    I2C_Stop();
    delay_ms(10);
    return 1;
}

unsigned char EEPROM_Read(unsigned short addr, unsigned char *data) {
    unsigned char status;
    I2C_Start();
    status = I2C_GetStatus();
    if (status != I2C_START_TRANSMITTED) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(EEPROM_ADDR_WRITE);
    if (status != I2C_SLA_W_ACK) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write((addr >> 8) & 0xFF);
    if (status != I2C_DATA_TRANSMITTED_ACK) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(addr & 0xFF);
    if (status != I2C_DATA_TRANSMITTED_ACK) {
        I2C_Stop();
        return 0;
    }

    I2C_Start();
    status = I2C_GetStatus();
    if (status != I2C_RESTART_TRANSMITTED) {
        I2C_Stop();
        return 0;
    }

    status = I2C_Write(EEPROM_ADDR_READ);
    if (status != I2C_SLA_R_ACK) {
        I2C_Stop();
        return 0;
    }

    *data = I2C_Read(0);
    status = I2C_GetStatus();
    if (status != I2C_DATA_RECEIVED_NACK) {
        I2C_Stop();
        return 0;
    }

    I2C_Stop();
    return 1;
}

int main(void) {
    unsigned char value;
    unsigned char result;
    unsigned char i;
    unsigned short test_addr;
    unsigned char test_data;

    VPBDIV = 0x01;
    UART0_Init();
    delay_ms(100);

    UART0_SendString("LPC2148 I2C EEPROM Test\r\n");
    UART0_SendString("Initializing I2C...\r\n");

    I2C_Init();
    delay_ms(100);

    UART0_SendString("Writing 'A' to address 0x000A...\r\n");

    result = EEPROM_Write(0x000A, 'A');
    if (result) {
        UART0_SendString("Write successful!\r\n");
    } else {
        UART0_SendString("Write failed!\r\n");
    }

    delay_ms(100);

    UART0_SendString("Reading from address 0x000A...\r\n");

    result = EEPROM_Read(0x000A, &value);
    if (result) {
        UART0_SendString("Read successful! Value: ");
        UART0_SendChar(value);
        UART0_SendString(" (");
        UART0_SendHex(value);
        UART0_SendString(")\r\n");
    } else {
        UART0_SendString("Read failed!\r\n");
    }

    UART0_SendString("\r\nTesting multiple values...\r\n");

    for (i = 0; i < 5; i++) {
        test_addr = 0x0010 + i;
        test_data = 'A' + i;

        UART0_SendString("Writing '");
        UART0_SendChar(test_data);
        UART0_SendString("' to address ");
        UART0_SendHex(test_addr >> 8);
        UART0_SendHex(test_addr & 0xFF);
        UART0_SendString("...\r\n");

        if (EEPROM_Write(test_addr, test_data)) {
            delay_ms(50);
            if (EEPROM_Read(test_addr, &value)) {
                UART0_SendString("Success! Read back: ");
                UART0_SendChar(value);
                UART0_SendString("\r\n");
            } else {
                UART0_SendString("Read failed!\r\n");
            }
        } else {
            UART0_SendString("Write failed!\r\n");
        }

        delay_ms(100);
    }

    UART0_SendString("\r\nTest completed!\r\n");

    while (1) {
        delay_ms(1000);
    }
}
