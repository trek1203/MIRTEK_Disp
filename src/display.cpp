#include "display.hpp"

uint8_t lcd_buffer[11] = {0};

void lcd_send_data(uint8_t data)
{
    LCD_LOAD_1;
    spi_transmit(data);
    LCD_LOAD_0;
    for (uint8_t i = 0; i < 5; i++)
        ;
}

void lcd_clear()
{
    for (uint8_t pos = 11; pos > 0; pos--)
    {
        lcd_send_data(0x00);
        for (uint32_t i = 0; i < 5; i++)
            ;
    }
}

void lcd_print_all()
{
    for (uint8_t pos = 11; pos > 0; pos--)
    {
        lcd_send_data(0xff);
        for (uint32_t i = 0; i < 5; i++);
    }
}

void lcd_update()
{
    for (uint8_t pos = 0; pos < sizeof(lcd_buffer); pos++)
    {
        lcd_send_data(lcd_buffer[pos]);
        for (uint32_t i = 0; i < 5; i++)
            ;
    }
}

void lcd_write_buffer(uint8_t digit, uint8_t dig_pos){
    uint8_t lcd_data = 0;
    lcd_data = dec_to_lcd(digit, dig_pos);
    if(lcd_data & 0x01){
        lcd_data &= 0b11111110;
        lcd_buffer[dig_pos - 1] = (lcd_buffer[dig_pos - 1] | 0x01); 
    }
    lcd_buffer[dig_pos] = lcd_data;
}

void lcd_print_digit(uint8_t digit, uint8_t position){
    lcd_write_buffer(digit, position);
    lcd_update();
}

uint8_t dec_to_lcd(uint8_t val, uint8_t dig_pos)
{
    dig_pos %= 2;
    switch (val)
    {
    case 0:
        dig_pos == 0 ? val = 0b11011110: val = 0b10111101;
        break;
    case 1:
        dig_pos == 0 ? val = 0b00000110: val = 0b00001100;
        break;
    case 2:
        dig_pos == 0 ? val = 0b10111010: val = 0b01110101;
        break;
    case 3:
        dig_pos == 0 ? val = 0b10101110: val = 0b01011101;
        break;
    case 4:
        dig_pos == 0 ? val = 0b01100110: val = 0b11001100;
        break;
    case 5:
        dig_pos == 0 ? val = 0b11101100: val = 0b11011001;
        break;
    case 6:
        dig_pos == 0 ? val = 0b11111100: val = 0b11111001;
        break;
    case 7:
        dig_pos == 0 ? val = 0b10000110: val = 0b00001101;
        break;
    case 8:
        dig_pos == 0 ? val = 0b11111110: val = 0b11111101;
        break;
    case 9:
        dig_pos == 0 ? val = 0b11101110: val = 0b11011101;
        break;
    default:
        val = 0;
        break;
    }
    return val;
}

void lcd_print_value(uint16_t val){
    uint8_t thousands = 0, hundreds = 0, tens = 0, units = 0;
    if(val > 9999){ return; }
    while(val >= 1000){
        val -= 1000;
        thousands++;
    }
    while(val >= 100){
        val -= 100;
        hundreds++;
    }
    while(val >= 10){
        val -= 10;
        tens++;
    }
    units = (uint8_t)val;
    lcd_write_buffer(thousands, DIG_POS4);
    lcd_write_buffer(hundreds, DIG_POS3);
    lcd_write_buffer(tens, DIG_POS2);
    lcd_write_buffer(units, DIG_POS1);
    lcd_update();    
}