#include "can.h"

void CAN1_Init(void) {
    // Power up CAN
    PCONP |= (1 << 13);  // Enable CAN1
    PCONP |= (1 << 14);  // Enable CAN2

    // P0.0 = RD1, P0.1 = TD1
    PINSEL0 |= (1 << 0) | (1 << 2);

    // Reset CAN1
    C1MOD = 1;  // Reset mode

    // Baud rate setup: 125 kbps @ 12MHz
    C1BTR = (4 << 0) | (2 << 14) | (1 << 16); 

    // Acceptance filter bypass (receive all)
    AFMR = 0x02;

    // Normal mode
    C1MOD = 0;
}

void CAN2_Init(void) {
    // P0.4 = RD2, P0.5 = TD2
    PINSEL0 |= (1 << 8) | (1 << 10);

    C2MOD = 1; // Reset mode
    C2BTR = (4 << 0) | (2 << 14) | (1 << 16);
    AFMR = 0x02;
    C2MOD = 0;
}

void CAN1_Send(can_msg_t *msg) {
    // Load ID
    C1TID1 = msg->id & 0x7FF;

    // Load DLC
    C1TFI1 = (msg->len & 0xF) << 16;

    // Load data bytes
    C1TDA1 = msg->data[0] | (msg->data[1] << 8) |
             (msg->data[2] << 16) | (msg->data[3] << 24);

    C1TDB1 = msg->data[4] | (msg->data[5] << 8) |
             (msg->data[6] << 16) | (msg->data[7] << 24);

    // Send request
    C1CMR = (1 << 0) | (1 << 5);  // Transmission request + select buffer 1
}

int CAN2_Receive(can_msg_t *msg) {
    uint32_t dataA;
    uint32_t dataB;

    if (C2GSR & (1 << 0)) { // RX buffer full
        msg->id  = C2RID & 0x7FF;
        msg->len = (C2RFS >> 16) & 0xF;

        dataA = C2RDA;
        dataB = C2RDB;

        msg->data[0] = dataA & 0xFF;
        msg->data[1] = (dataA >> 8) & 0xFF;
        msg->data[2] = (dataA >> 16) & 0xFF;
        msg->data[3] = (dataA >> 24) & 0xFF;

        msg->data[4] = dataB & 0xFF;
        msg->data[5] = (dataB >> 8) & 0xFF;
        msg->data[6] = (dataB >> 16) & 0xFF;
        msg->data[7] = (dataB >> 24) & 0xFF;

        // Release receive buffer
        C2CMR = (1 << 2);
        return 1;
    }
    return 0;
}

