#define RS_High() IOSET1=(1<<24)
#define RS_Low() IOCLR1=(1<<24)
#define EN_High() IOSET1=(1<<25)
#define EN_Low() IOCLR1=(1<<25)
void delay_ms(unsigned int t)
{
unsigned int i,j;
for(i=0;i<t;i++)
for(j=0;j<4000;j++);
}

void lcd_cmd(unsigned char ch)
{
IOPIN1&=0xff00ffff;
IOPIN1|=ch<<16;
RS_Low();
EN_High();
delay_ms(2);
EN_Low();
}

void lcd_data(unsigned char ch)
{
IOPIN1&=0xff00ffff;
IOPIN1|=ch<<16;
RS_High();
EN_High();
delay_ms(2);
EN_Low();
}

void lcd_init()
{
lcd_cmd(0x38);
//lcd_cmd(0x06);
lcd_cmd(0x0f);
//lcd_cmd(0x01);
}

void lcd_print(unsigned char *str)
{
while(*str)
{
lcd_data(*str);
str++;
}
}