#ifndef CAN_H
#define CAN_H

#include <LPC21xx.h>
#include <stdint.h>

typedef struct {
    uint32_t id;       // 11-bit identifier
    uint8_t len;       // data length code (0–8)
    uint8_t data[8];   // payload
} can_msg_t;

void CAN1_Init(void);
void CAN2_Init(void);
void CAN1_Send(can_msg_t *msg);
int  CAN2_Receive(can_msg_t *msg);

#endif
