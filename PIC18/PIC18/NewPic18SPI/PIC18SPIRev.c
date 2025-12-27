/*
 * SD Card Interface with PIC18F4550
 * Compiler: MPLAB C18
 * Target: PIC18F4550
 *
 * Description: Initialize SD card, write and read data
 * LED indicators show operation status
 *
 * SD Card Pin Configuration:
 * RC7 -> MOSI (Master Out Slave In) - SD Card DI
 * RB0 -> MISO (Master In Slave Out) - SD Card DO
 * RB1 -> SCK  (Serial Clock)         - SD Card CLK
 * RA5 -> CS   (Chip Select)          - SD Card CS
 *
 * MEMORY FIX: Split 512-byte buffer into two 256-byte halves to fit PIC18F4550 banks
 */

#include <p18f4550.h>
#include <delays.h>

// Configuration Bits
#pragma config FOSC = HS        // High-Speed Crystal
#pragma config WDT = OFF        // Watchdog Timer Off
#pragma config LVP = OFF        // Low Voltage Programming Off
#pragma config PBADEN = OFF     // PORTB A/D Enable OFF

// Pin Definitions
#define SD_CS LATAbits.LATA5      // SD Card Chip Select (Active Low)
#define LED_INIT LATBbits.LATB2   // Initialization status LED
#define LED_WRITE LATBbits.LATB3  // Write operation LED
#define LED_READ LATBbits.LATB4   // Read operation LED
#define LED_ERROR LATBbits.LATB5  // Error LED

// SD Card Commands
#define CMD0    0x40    // GO_IDLE_STATE - Reset SD card
#define CMD1    0x41    // SEND_OP_COND - Initialize card
#define CMD8    0x48    // SEND_IF_COND - Check voltage range
#define CMD55   0x77    // APP_CMD - Next command is application specific
#define ACMD41  0x69    // SD_SEND_OP_COND - Start initialization
#define CMD16   0x50    // SET_BLOCKLEN - Set block length
#define CMD17   0x51    // READ_SINGLE_BLOCK - Read a block
#define CMD24   0x58    // WRITE_BLOCK - Write a block

// SD Card Response Tokens
#define SD_SUCCESS          0x00
#define SD_IDLE_STATE       0x01
#define SD_READY            0x00
#define SD_START_TOKEN      0xFE
#define SD_DATA_ACCEPTED    0x05

// Split 512-byte buffer into two 256-byte halves so it fits in PIC18 banks
// Split 512-byte buffer into two 256-byte halves placed in separate banks
#pragma udata bufferA=0x100
unsigned char sd_buffer_A[256];
#pragma udata bufferB=0x200
unsigned char sd_buffer_B[256];
#pragma udata


// Function Prototypes
void SPI_Init(void);
unsigned char SPI_Transfer(unsigned char data);
void SD_CS_Enable(void);
void SD_CS_Disable(void);
unsigned char SD_SendCommand(unsigned char cmd, unsigned long arg);
unsigned char SD_Init(void);
unsigned char SD_ReadBlock(unsigned long block_addr, unsigned char *buffer);   // not used with split buffer
unsigned char SD_WriteBlock(unsigned long block_addr, unsigned char *buffer);  // not used with split buffer
unsigned char SD_WriteBlock512(unsigned long block_addr);  // writes 512 bytes from sd_buffer_A/B
unsigned char SD_ReadBlock512(unsigned long block_addr);   // reads 512 bytes into sd_buffer_A/B
void delay_ms(unsigned int ms);
void Blink_LED(unsigned char led_pin, unsigned char times);

void main(void)
{
    unsigned int i;
    unsigned char status;
    
    // Configure oscillator (primary oscillator device specific)
    OSCCON = 0x00;  // Use primary oscillator as original
    
    // Configure LED pins as outputs
    TRISBbits.TRISB2 = 0;  // LED_INIT
    TRISBbits.TRISB3 = 0;  // LED_WRITE
    TRISBbits.TRISB4 = 0;  // LED_READ
    TRISBbits.TRISB5 = 0;  // LED_ERROR
    
    // Turn off all LEDs initially
    LED_INIT = 0;
    LED_WRITE = 0;
    LED_READ = 0;
    LED_ERROR = 0;
    
    // Initialize SPI
    SPI_Init();
    delay_ms(100);
    
    // Initialize SD Card
    LED_INIT = 1;
    status = SD_Init();
    
    if(status == SD_SUCCESS)
    {
        // SD Card initialized successfully
        Blink_LED(2, 3);  // Blink INIT LED 3 times
        LED_INIT = 1;
        
        // Prepare data to write (pattern 0..255 repeated twice)
        for(i = 0; i < 256; i++)
        {
            sd_buffer_A[i] = (unsigned char)(i & 0xFF);       // bytes 0..255
            sd_buffer_B[i] = (unsigned char)(i & 0xFF);       // bytes 256..511 (same pattern)
        }
        
        // Write block to SD card (Block address 0x00000100)
        LED_WRITE = 1;
        status = SD_WriteBlock512(0x00000100);
        LED_WRITE = 0;
        
        if(status == SD_SUCCESS)
        {
            Blink_LED(3, 2);  // Blink WRITE LED 2 times
            delay_ms(500);
            
            // Clear buffer halves
            for(i = 0; i < 256; i++)
            {
                sd_buffer_A[i] = 0;
                sd_buffer_B[i] = 0;
            }
            
            // Read block from SD card into the two halves
            LED_READ = 1;
            status = SD_ReadBlock512(0x00000100);
            LED_READ = 0;
            
            if(status == SD_SUCCESS)
            {
                Blink_LED(4, 2);  // Blink READ LED 2 times
                
                // Verify data (check a few sample bytes inside first half)
                if(sd_buffer_A[0] == 0 && sd_buffer_A[10] == 10 && sd_buffer_A[255] == 255)
                {
                    // Data verified successfully
                    LED_INIT = 1;
                    LED_READ = 1;
                }
                else
                {
                    LED_ERROR = 1;  // Verification failed
                }
            }
            else
            {
                LED_ERROR = 1;  // Read failed
            }
        }
        else
        {
            LED_ERROR = 1;  // Write failed
        }
    }
    else
    {
        // SD Card initialization failed
        LED_ERROR = 1;
        Blink_LED(5, 5);  // Blink ERROR LED 5 times
    }
    
    // Keep LEDs in final state
    while(1);
}

void SPI_Init(void)
{
    // Configure SPI pins
    TRISBbits.TRISB0 = 1;  // RB0 as input (MISO)
    TRISBbits.TRISB1 = 0;  // RB1 as output (SCK)
    TRISAbits.TRISA5 = 0;  // RA5 as output (CS)
    TRISCbits.TRISC7 = 0;  // RC7 as output (MOSI)
    
    // Disable ADC on pins used
    ADCON0 = 0x00;
    ADCON1 = 0x0F;
    
    // Deselect SD card initially
    SD_CS = 1;
    
    // Configure SSPSTAT
    // SMP = 0: Sample at middle
    // CKE = 1: Transmit on rising edge
    SSPSTAT = 0x40;
    
    // Configure SSPCON1
    // SSPEN = 1: Enable SPI
    // CKP = 0: Clock idle low
    // SSPM = 0001: Fosc/16 (slower for SD card initialization)
    SSPCON1 = 0x21;
    
    PIR1bits.SSPIF = 0;
}

unsigned char SPI_Transfer(unsigned char data)
{
    SSPBUF = data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    return SSPBUF;
}

void SD_CS_Enable(void)
{
    SD_CS = 0;
    Delay10TCYx(1);  // Small delay after CS enable
}

void SD_CS_Disable(void)
{
    SD_CS = 1;
    Delay10TCYx(1);  // Small delay after CS disable
}

/*
 * Send a command to the SD card. cmd: command byte (with 0x40), arg: 32-bit argument.
 * Returns the 1-byte R1 response (MSB clear when valid).
 */
unsigned char SD_SendCommand(unsigned char cmd, unsigned long arg)
{
    unsigned char response;
    unsigned char retry;
    
    // Send command packet (6 bytes)
    SPI_Transfer(cmd);
    SPI_Transfer((unsigned char)(arg >> 24));
    SPI_Transfer((unsigned char)(arg >> 16));
    SPI_Transfer((unsigned char)(arg >> 8));
    SPI_Transfer((unsigned char)arg);
    
    // Send CRC (only important for CMD0 and CMD8)
    if(cmd == CMD0)
        SPI_Transfer(0x95);  // Valid CRC for CMD0
    else if(cmd == CMD8)
        SPI_Transfer(0x87);  // Valid CRC for CMD8
    else
        SPI_Transfer(0xFF);  // Dummy CRC for other commands
    
    // Wait for response (up to 8 bytes)
    for(retry = 0; retry < 8; retry++)
    {
        response = SPI_Transfer(0xFF);
        if((response & 0x80) == 0)  // Valid response has MSB = 0
            break;
    }
    
    return response;
}

unsigned char SD_Init(void)
{
    unsigned char response;
    unsigned int retry;
    unsigned char i;
    
    // Send at least 74 clock pulses with CS high
    SD_CS_Disable();
    for(i = 0; i < 10; i++)
    {
        SPI_Transfer(0xFF);
    }
    
    // Send CMD0 to reset card
    SD_CS_Enable();
    response = SD_SendCommand(CMD0, 0);
    SD_CS_Disable();
    
    if(response != SD_IDLE_STATE)
    {
        return 0xFF;  // Card not in idle state
    }
    
    // Send CMD8 to check voltage range (SD v2.0)
    SD_CS_Enable();
    response = SD_SendCommand(CMD8, 0x000001AA);
    
    if(response == SD_IDLE_STATE)
    {
        // Read additional 4 bytes of R7 response
        SPI_Transfer(0xFF);
        SPI_Transfer(0xFF);
        SPI_Transfer(0xFF);
        SPI_Transfer(0xFF);
    }
    SD_CS_Disable();
    
    // Send ACMD41 to initialize card
    retry = 0;
    do
    {
        // Send CMD55 first
        SD_CS_Enable();
        response = SD_SendCommand(CMD55, 0);
        SD_CS_Disable();
        
        // Then send ACMD41
        SD_CS_Enable();
        response = SD_SendCommand(ACMD41, 0x40000000);
        SD_CS_Disable();
        
        retry++;
        delay_ms(10);
        
        if(retry > 100)
            return 0xFE;  // Timeout
    } while(response != SD_READY);
    
    // Set block length to 512 bytes
    SD_CS_Enable();
    response = SD_SendCommand(CMD16, 512);
    SD_CS_Disable();
    
    if(response != SD_READY)
        return 0xFD;  // Block length error
    
    // Switch to faster SPI clock (Fosc/4)
    SSPCON1 = 0x20;
    
    return SD_SUCCESS;
}

/*
 * SD_WriteBlock512
 * Sends a WRITE_BLOCK (CMD24) for a single 512-byte block using the two 256-byte halves.
 * Returns SD_SUCCESS on success or error codes consistent with earlier behavior.
 */
unsigned char SD_WriteBlock512(unsigned long block_addr)
{
    unsigned char response;
    unsigned int i;
    unsigned long retry;
    
    // Send WRITE_BLOCK command
    SD_CS_Enable();
    response = SD_SendCommand(CMD24, block_addr);
    
    if(response != SD_READY)
    {
        SD_CS_Disable();
        return 0xFF;
    }
    
    // Send start token
    SPI_Transfer(SD_START_TOKEN);
    
    // Write 512 bytes of data (first half, then second half)
    for(i = 0; i < 256; i++)
    {
        SPI_Transfer(sd_buffer_A[i]);
    }
    for(i = 0; i < 256; i++)
    {
        SPI_Transfer(sd_buffer_B[i]);
    }
    
    // Send dummy CRC (2 bytes)
    SPI_Transfer(0xFF);
    SPI_Transfer(0xFF);
    
    // Read data response token
    response = SPI_Transfer(0xFF);
    
    if((response & 0x1F) != SD_DATA_ACCEPTED)
    {
        SD_CS_Disable();
        return 0xFD;  // Write error
    }
    
    // Wait for card to finish programming (busy signal)
    retry = 0;
    while(SPI_Transfer(0xFF) == 0x00)
    {
        retry++;
        if(retry > 50000)
        {
            SD_CS_Disable();
            return 0xFC;  // Timeout
        }
    }
    
    SD_CS_Disable();
    SPI_Transfer(0xFF);  // Extra clock cycle
    
    return SD_SUCCESS;
}

/*
 * SD_ReadBlock512
 * Sends a READ_SINGLE_BLOCK (CMD17) and reads 512 bytes into the two halves.
 */
unsigned char SD_ReadBlock512(unsigned long block_addr)
{
    unsigned char response;
    unsigned int i;
    unsigned long retry;
    
    // Send READ_SINGLE_BLOCK command
    SD_CS_Enable();
    response = SD_SendCommand(CMD17, block_addr);
    
    if(response != SD_READY)
    {
        SD_CS_Disable();
        return 0xFF;
    }
    
    // Wait for start token (0xFE)
    retry = 0;
    do
    {
        response = SPI_Transfer(0xFF);
        retry++;
        if(retry > 10000)
        {
            SD_CS_Disable();
            return 0xFE;  // Timeout
        }
    } while(response != SD_START_TOKEN);
    
    // Read 512 bytes of data into halves
    for(i = 0; i < 256; i++)
    {
        sd_buffer_A[i] = SPI_Transfer(0xFF);
    }
    for(i = 0; i < 256; i++)
    {
        sd_buffer_B[i] = SPI_Transfer(0xFF);
    }
    
    // Read 2-byte CRC (discard)
    SPI_Transfer(0xFF);
    SPI_Transfer(0xFF);
    
    SD_CS_Disable();
    SPI_Transfer(0xFF);  // Extra clock cycles
    
    return SD_SUCCESS;
}

/* (Original SD_ReadBlock/SD_WriteBlock kept for reference if you want to use contiguous buffers
   - These will not be used with split buffers and are left here commented for clarity.)
*/

/*
unsigned char SD_ReadBlock(unsigned long block_addr, unsigned char *buffer)
{
    unsigned char response;
    unsigned int i;
    unsigned int retry;
    // original implementation (reads 512 bytes into buffer[])
    ...
}
*/

/*
unsigned char SD_WriteBlock(unsigned long block_addr, unsigned char *buffer)
{
    unsigned char response;
    unsigned int i;
    unsigned int retry;
    // original implementation (writes 512 bytes from buffer[])
    ...
}
*/

void Blink_LED(unsigned char led_pin, unsigned char times)
{
    unsigned char i;
    for(i = 0; i < times; i++)
    {
        switch(led_pin)
        {
            case 2: LED_INIT = 1; break;
            case 3: LED_WRITE = 1; break;
            case 4: LED_READ = 1; break;
            case 5: LED_ERROR = 1; break;
        }
        delay_ms(200);
        
        switch(led_pin)
        {
            case 2: LED_INIT = 0; break;
            case 3: LED_WRITE = 0; break;
            case 4: LED_READ = 0; break;
            case 5: LED_ERROR = 0; break;
        }
        delay_ms(200);
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i;
    for(i = 0; i < ms; i++)
    {
        Delay1KTCYx(5);  // 5ms @ 20MHz (as original)
    }
}
