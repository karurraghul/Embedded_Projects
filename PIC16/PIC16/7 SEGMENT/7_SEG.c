#include<pic.h>
#include<htc.h>

void delay(int);

#define seven PORTC

void main()
{
	while(1)
		{
		TRISC=0x00;
		seven=0xc0;
		delay(5000);
		seven=0xf9;
		delay(5000);
		seven=0xa4;
		delay(5000);
		seven=0xb0;
		delay(5000);
		seven=0x99;
		delay(5000);
		seven=0x92;
		delay(5000);
		seven=0x82;
		delay(5000);
		seven=0xf8;
		delay(5000);
		seven=0x80;
		delay(5000);
		seven=0x90;
		delay(5000);
	}
}

void delay(int a)
{
	int i;
	for(i=0;i<=a;i++);
}