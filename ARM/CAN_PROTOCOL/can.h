#ifndef CAN_H
#define CAN_H

#include <stdint.h>

// CAN frame structure
typedef struct {
    uint32_t id;       // 11-bit (std) or 29-bit (ext)
    uint8_t len;       // Data length (0–8)
    uint8_t data[8];   // Data payload
    uint8_t ext;       // 0 = standard frame, 1 = extended
    uint8_t rtr;       // Remote frame? 0 = data, 1 = remote
} can_msg_t;

// Initialization: configure SPI and MCP2515 with desired bitrate
int CAN_Init(void);

// Send a CAN frame
int CAN_Send(const can_msg_t *msg);

// Receive a CAN frame (polling mode)
int CAN_Receive(can_msg_t *msg);

#endif // CAN_H
