/*
 * lcd_Data.c
 *
 * Created: 20-09-2025 10:20:19
 * Author : karur
 */ 

#define F_CPU 12000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#define rs PA0
#define rw PA1
#define en PA2
void lcd_init();
void dis_cmd(char);
void dis_data(char);
void lcdcmd(char);
void lcddata(char);

int main(void)
{
	unsigned char data0[16]="LCD Interfacing";
	unsigned char data1[16]="Cyber Crime";
	int i=0;
	DDRA=0xff;
	lcd_init();
	while (data0[i]!='\0')
	{
		dis_data(data0[i]);
		_delay_ms(20);
		i++;
	}
	dis_cmd(0xc5);
	i=0;
	while (data1[i]!='\0')
	{
		dis_data(data1[i]);
		_delay_ms(20);
		i++;
	}
	
	while(1);
}

void lcd_init()
{
	dis_cmd(0x02);	//initilize in 4 bit mode
	dis_cmd(0x28);	//initialize in 2 lines, 5�*7 dots and 4 bit mode
	dis_cmd(0x0c);
	dis_cmd(0x06);
	dis_cmd(0x80);
}

void dis_cmd(char cmd_value)
{
	char cmd_value1;
	cmd_value1=(cmd_value & 0xf0);	//mask lower nibble because PA4-PA7 pins are unused
	lcdcmd(cmd_value1);				//send to lcd
	cmd_value1 = ((cmd_value<<4) & 0xf0);
	lcdcmd(cmd_value1);
}

void dis_data(char data_value)
{
	char data_value1;
	data_value1=(data_value & 0xf0);	//mask lower nibble because PA4-PA7 pins are unused
	lcddata(data_value1);				//send to lcd
	data_value1 = ((data_value<<4) & 0xf0);
	lcddata(data_value1);
}

void lcdcmd(char cmdout)
{
	PORTA=cmdout;
	PORTA&=~(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
}

void lcddata(char dataout)
{
	PORTA=dataout;
	PORTA|=(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
}

