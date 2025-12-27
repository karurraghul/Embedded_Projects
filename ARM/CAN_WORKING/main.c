#include "can.h"

static void delay(void) {
    volatile int i;
    for (i = 0; i < 500000; i++);
}

int main(void) {
    can_msg_t tx, rx;
    int i;

    CAN1_Init();
    CAN2_Init();

    tx.id = 0x123;
    tx.len = 8;
    for (i = 0; i < 8; i++) {
        tx.data[i] = i;
    }

    while (1) {
        CAN1_Send(&tx);

        if (CAN2_Receive(&rx)) {
            // Example: toggle LED or debug via UART
            // For now just reload tx with received data and echo back
            tx.id = 0x124;
            for (i = 0; i < rx.len; i++) {
                tx.data[i] = rx.data[i] + 1;
            }
            CAN1_Send(&tx);
        }

        delay();
    }
}
