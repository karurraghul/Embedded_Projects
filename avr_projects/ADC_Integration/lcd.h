#define lcd PORTC
void cmd(char x)
{
	lcd=x;
	PORTB&=~(1<<0);
	PORTB&=~(1<<1);
	PORTB|=(1<<2);
	_delay_ms(1);
	PORTB&=~(1<<2);
}

void lcd_display(char x)
{
	lcd =x;
	PORTB|=(1<<0);
	PORTB&=~(1<<1);
	PORTB|=(1<<2);
	_delay_ms(1);
	PORTB&=~(1<<2);
}

void lcd_ini()
{
	cmd(0x38);
	cmd(0x0e);
	cmd(0x01);
	cmd(0x06);
	cmd(0x80);
}

void lcd_str(char *str)
{
	while (*str!='\0')
	{
		lcd_display(*str);
		str++;
	}
}
