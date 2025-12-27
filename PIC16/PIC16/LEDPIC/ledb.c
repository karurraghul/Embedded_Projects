#include<pic.h>
#include<htc.h>

void delay(int);

#define LED PORTC

void main()
{
	while(1)
	{
	TRISC0=0;
	LED=0;
	delay(1000);
	LED=1;
	delay(1000);
	}
}
void delay(int a)
{
	int i;
	for(i=0;i<=a;i++);
}