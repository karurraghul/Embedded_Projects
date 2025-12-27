#include "can.h"
#include <LPC21xx.h>  /* Adjust header if needed */

/* MCP2515 SPI opcodes */
#define MCP_RESET     0xC0
#define MCP_READ      0x03
#define MCP_WRITE     0x02
#define MCP_BITMOD    0x05
#define MCP_READSTAT  0xA0
#define MCP_RTS_TXB0  0x81
#define MCP_RXSTATUS  0xB0

/* MCP2515 register definitions */
#define CANCTRL       0x0F
#define CANSTAT       0x0E
#define CNF1          0x2A
#define CNF2          0x29
#define CNF3          0x28
#define CANINTE       0x2B
#define CANINTF       0x2C
#define TXB0CTRL      0x30
#define TXB0SIDH      0x31
#define RXB0CTRL      0x60
#define RXB0SIDH      0x61

/* MCU SPI / GPIO placeholders — implement these for LPC2138 */
static uint8_t spi_txrx(uint8_t b) {
    /* Add SPI transmit/receive logic here */
    return 0;
}

static void CS_LOW(void) { 
    /* Assert chip-select */ 
}

static void CS_HIGH(void) { 
    /* Deassert chip-select */ 
}

void mcp2515_reset(void) {
    CS_LOW();
    spi_txrx(MCP_RESET);
    CS_HIGH();
}

uint8_t mcp2515_read(uint8_t addr) {
    uint8_t v;
    CS_LOW();
    spi_txrx(MCP_READ);
    spi_txrx(addr);
    v = spi_txrx(0xFF);
    CS_HIGH();
    return v;
}

void mcp2515_write(uint8_t addr, uint8_t val) {
    CS_LOW();
    spi_txrx(MCP_WRITE);
    spi_txrx(addr);
    spi_txrx(val);
    CS_HIGH();
}

void mcp2515_bit_modify(uint8_t addr, uint8_t mask, uint8_t val) {
    CS_LOW();
    spi_txrx(MCP_BITMOD);
    spi_txrx(addr);
    spi_txrx(mask);
    spi_txrx(val);
    CS_HIGH();
}

void mcp2515_init_125k_16MHz(void) {
    mcp2515_reset();
    mcp2515_write(CANCTRL, 0x80); /* Configuration Mode */
    /* Bit timing: 125 kbps @ 16 MHz */
    mcp2515_write(CNF1, 0x03);
    mcp2515_write(CNF2, 0xF0);
    mcp2515_write(CNF3, 0x86);
    mcp2515_write(RXB0CTRL, 0x00);
    mcp2515_write(CANINTE, 0x03); /* Enable RX interrupts */
    mcp2515_bit_modify(CANCTRL, 0xE0, 0x00); /* Normal Mode */
}

int mcp2515_send(const can_msg_t *m) {
    uint8_t sidh, sidl, eid8 = 0, eid0 = 0;
    int i;
    
    if (!m->ext) {
        sidh = (m->id >> 3) & 0xFF;
        sidl = (m->id << 5) & 0xE0;
    } else {
        sidh = (m->id >> 21) & 0xFF;
        sidl = (1 << 3) | ((m->id >> 16) & 0x03) << 5;
        eid8 = (m->id >> 8) & 0xFF;
        eid0 = m->id & 0xFF;
    }
    
    CS_LOW();
    spi_txrx(MCP_WRITE);
    spi_txrx(TXB0SIDH);
    spi_txrx(sidh);
    spi_txrx(sidl);
    spi_txrx(eid8);
    spi_txrx(eid0);
    spi_txrx((m->rtr << 6) | (m->len & 0x0F));
    
    for (i = 0; i < m->len; i++) {
        spi_txrx(m->data[i]);
    }
    
    CS_HIGH();
    
    CS_LOW();
    spi_txrx(MCP_RTS_TXB0); /* Request to send */
    CS_HIGH();
    
    return 0;
}

int mcp2515_recv(can_msg_t *m) {
    uint8_t stat;
    uint8_t sidh, sidl, eid8, eid0, dlc;
    int i;
    
    CS_LOW();
    spi_txrx(MCP_RXSTATUS);
    stat = spi_txrx(0xFF);
    CS_HIGH();
    
    if (!(stat & 0xC0)) {
        return 0; /* no message */
    }

    CS_LOW();
    spi_txrx(MCP_READ);
    spi_txrx(RXB0SIDH);
    sidh = spi_txrx(0xFF);
    sidl = spi_txrx(0xFF);
    eid8 = spi_txrx(0xFF);
    eid0 = spi_txrx(0xFF);
    dlc = spi_txrx(0xFF) & 0x0F;
    
    m->ext = (sidl & (1 << 3)) ? 1 : 0;
    m->rtr = (dlc & 0x40) ? 1 : 0;
    m->len = dlc;
    
    if (!m->ext) {
        m->id = (sidh << 3) | (sidl >> 5);
    } else {
        m->id = (sidh << 21) | ((sidl >> 5) << 16) | (eid8 << 8) | eid0;
    }
    
    for (i = 0; i < m->len; i++) {
        m->data[i] = spi_txrx(0xFF);
    }
    
    CS_HIGH();
    mcp2515_bit_modify(CANINTF, 0x01, 0x00); /* Clear RX0IF */
    return 1;
}

/* Public CAN interface */
int CAN_Init(void) {
    /* Initialize SPI and GPIO here... */
    mcp2515_init_125k_16MHz();
    return 0;
}

int CAN_Send(const can_msg_t *msg) {
    return mcp2515_send(msg);
}

int CAN_Receive(can_msg_t *msg) {
    return mcp2515_recv(msg);
}
