#include<p18f4550.h>
#define LEDS LATD

void delay(unsigned int t){
	unsigned int i;
	while(t--){
		for(i=0;i<100;i++);
		}
}
void main(){
	TRISD=0X00;
	LEDS=0X00;
	while(1){
		LEDS=0XFF;
		delay(100);
		LEDS=0X00;
		delay(100);
	}
}