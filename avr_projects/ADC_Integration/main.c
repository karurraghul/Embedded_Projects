/*
 * ADC_Interfacing.c
 *
 * Created: 20-09-2025 11:11:37
 * Author : karur
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"
int adc_re();
int lcd_pos(int x,int y);
unsigned int rec;

int main(void)
{
	char a[5];
	DDRA=0x00;
	DDRB=0xff;
	DDRC=0xff;
	lcd_ini();
	ADCSRA=0xcc;
	lcd_str("values of ADC is ");
	while(1)
	{
		adc_re();
		sprintf(a,"%d",rec);
		lcd_pos(1,0);
		lcd_str(" ");
		lcd_pos(1,0);
		lcd_str(a);
		_delay_ms(300);
	}
}

int adc_re()
{
	DDRA=0x00;		//make channel; 0 as input
	ADMUX=0x40;
	ADCSRA|=(1<<ADSC);
	while(((ADCSRA&(1<<4))==0));
	rec=ADC;
	ADCSRA|=(0<<ADSC);
	return rec;
}

int lcd_pos(int x,int y)
{
	if(x==0)
	cmd(0x80+y);
	else if(x==1)
	cmd(0xc0+y);
	return '0';
}

