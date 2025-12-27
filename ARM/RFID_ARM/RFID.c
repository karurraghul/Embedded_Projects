#include<lpc213x.h>
#include<string.h>
#include"lcd.h"
#include"uart.h"
int main()
{
char card_id[14];
int i=0;
PINSEL0=0x00000005;
PINSEL2=0x00000000;
IODIR1=0x03ff0000;
PLLConfig();
lcd_init();
uart_init();
//lcd_cmd(0x0f);
lcd_print("RFID attendance");
lcd_cmd(0xc0);
lcd_print("mgmt system");
delay_ms(100);
while(1)
{
lcd_cmd(0x01);
lcd_print("Place card");
lcd_cmd(0xc0);
for(i=0;i<12;i++)
card_id[i]=uart0_getchar();
card_id[i]='\0';
if(strcmp(card_id,"650024170C5A")==0)
{
lcd_cmd(0x01);
lcd_print("livewire");
delay_ms(100);
}
else if(strcmp(card_id,"6D003F2E5529")==0)
{
lcd_cmd(0x01);
lcd_print("welcome");
delay_ms(100);
}
else
{
lcd_cmd(0x01);
lcd_print("invalid card");
delay_ms(100);
}
}
}