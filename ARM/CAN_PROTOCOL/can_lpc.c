#include "can.h"
#include <LPC214x.h>  // or your specific MCU header

// Enable acceptance filter in bypass mode
static void af_enable_bypass(void) {
    AFMR = 0x02;  // Bypass: accept all messages
}

// Initialize CAN1 with specified Bit Timing Register (BTR)
void can1_init(uint32_t btr) {
    PCONP |= (1 << 13);       // Power up CAN1 module

    // Pin setup: P0.0 = RD1, P0.1 = TD1
    PINSEL0 &= ~((3 << 0) | (3 << 2));
    PINSEL0 |=  ((1 << 0) | (1 << 2));

    C1MOD = 1;                 // Reset CAN controller
    C1GSR = 0;                 // Clear status
    C1BTR = btr;               // Set bit timing
    af_enable_bypass();        // Accept all messages
    C1MOD = 0;                 // Normal operation
}

// Send a CAN frame via Transmit Buffer 1
int can1_send(const can_msg_t *m) {
    if (!(C1SR & (1 << 2))) {  // TBS1 bit must be set (free)
        return -1;
    }

    if (!m->ext) {
        C1TID1 = (m->id & 0x7FF);
        C1TFI1 = (m->rtr ? (1 << 30) : 0) | ((m->len & 0xF) << 16);
    } else {
        C1TID1 = (m->id & 0x1FFFFFFF) | (1 << 31);
        C1TFI1 = (m->rtr ? (1 << 30) : 0) | ((m->len & 0xF) << 16) | (1 << 31);
    }

    // Pack data into two 32-bit registers
    uint32_t d0 = (m->data[3] << 24) | (m->data[2] << 16) |
                  (m->data[1] << 8)  | (m->data[0]);
    uint32_t d1 = (m->data[7] << 24) | (m->data[6] << 16) |
                  (m->data[5] << 8)  | (m->data[4]);
    C1TDA1 = d0;
    C1TDB1 = d1;

    C1CMR = (1 << 0) | (1 << 5);  // TXRQ and STB1 bits
    return 0;
}

// Poll for received frame in Rx Buffer 1
int can1_recv(can_msg_t *m) {
    if (!(C1GSR & (1 << 0))) {  // RBS bit must indicate message
        return 0;
    }

    uint32_t rfs = C1RFS;
    uint32_t rid = C1RID;
    uint32_t rda = C1RDA;
    uint32_t rdb = C1RDB;

    m->len = (rfs >> 16) & 0x0F;
    m->rtr = (rfs >> 30) & 0x01;
    m->ext = (rfs >> 31) & 0x01;

    m->id = m->ext ? (rid & 0x1FFFFFFF) : (rid & 0x7FF);

    m->data[0] = (uint8_t)(rda);
    m->data[1] = (uint8_t)(rda >> 8);
    m->data[2] = (uint8_t)(rda >> 16);
    m->data[3] = (uint8_t)(rda >> 24);
    m->data[4] = (uint8_t)(rdb);
    m->data[5] = (uint8_t)(rdb >> 8);
    m->data[6] = (uint8_t)(rdb >> 16);
    m->data[7] = (uint8_t)(rdb >> 24);

    C1CMR = (1 << 2); // Release receive buffer
    return 1;
}
