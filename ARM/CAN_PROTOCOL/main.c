#include "can.h"
#include "LPC21xx.h"  /* Ensure this matches your toolchain */

static void delay(volatile uint32_t d) {
    while (d--) __asm("nop");
}

int main(void) {
    can_msg_t tx;
    can_msg_t rx;
    int i;
    
    CAN_Init();

    /* Initialize tx message structure */
    tx.id = 0x100;
    tx.len = 8;
    tx.ext = 0;
    tx.rtr = 0;
    
    /* Initialize data array */
    for (i = 0; i < 8; i++) {
        tx.data[i] = i;
    }

    while (1) {
        CAN_Send(&tx);
        delay(100000);
        
        if (CAN_Receive(&rx)) {
            /* Echo back with new ID */
            rx.id = 0x200;
            CAN_Send(&rx);
        }
    }
}
