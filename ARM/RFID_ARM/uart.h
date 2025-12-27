#define Fpclk 15000000
 #define BAUD_BPS 9600
 void PLLConfig()
 {
 PLLCON=0x01;
 PLLCFG=0x24;
 PLLFEED=0xAA;
 PLLFEED=0x55;
 while(!(PLLSTAT&0x0400));
 PLLCON=0x03;
 PLLFEED=0xaa;
 PLLFEED=0x55;
 }

 void uart_init()
 {
 int baud16=Fpclk/(16*BAUD_BPS);
 U0LCR=0x83;
 U0DLL=baud16%256;
 U0DLM=baud16/256;
 U0LCR=0x03;
 }

void uart0_sendbyte(unsigned char ch)
 {
 U0THR=ch;
 while(!(U0LSR&0x04));
 }

 unsigned char uart0_getchar()
 {
 while(!(U0LSR&0x01));
 return U0RBR;
 }

 void uart0_sendstr(unsigned char *str)
 {
 while(*str)
 {
 uart0_sendbyte(*str);
 str++;
 }
 }