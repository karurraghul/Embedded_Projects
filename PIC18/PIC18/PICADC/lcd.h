#define rs LATDbits.LATD0   // Use LAT registers for output
#define en LATDbits.LATD1
#define LCD LATD            // Whole port for data lines

void delay(unsigned int t)
{
    unsigned int i;
    while(t--)
    {
        for(i=0; i<1000; i++);
    }
}

void lcd_cmd(unsigned char ch)
{
    unsigned char temp;

    // upper nibble
    temp = ch & 0xF0;
    LCD &= 0x0F;       // clear upper nibble
    LCD |= temp;
    rs = 0;
    en = 1;
    delay(2);
    en = 0;

    // lower nibble
    temp = (ch & 0x0F) << 4;
    LCD &= 0x0F;
    LCD |= temp;
    rs = 0;
    en = 1;
    delay(2);
    en = 0;
}

void lcd_data(unsigned char ch)
{
    unsigned char temp;

    // upper nibble
    temp = ch & 0xF0;
    LCD &= 0x0F;
    LCD |= temp;
    rs = 1;
    en = 1;
    delay(2);
    en = 0;

    // lower nibble
    temp = (ch & 0x0F) << 4;
    LCD &= 0x0F;
    LCD |= temp;
    rs = 1;
    en = 1;
    delay(2);
    en = 0;
}

void lcd_init(void)
{
    TRISD = 0x00;      // make PORTD output
    lcd_cmd(0x02);
    lcd_cmd(0x28);
    lcd_cmd(0x06);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
}
