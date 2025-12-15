#pragma once
#include "main.hpp"

#define LCD_CLK_1 (GPIOA->BSRR |= GPIO_BSRR_BS6)
#define LCD_CLK_0 (GPIOA->BSRR |= GPIO_BSRR_BR6)
#define LCD_CLK_TOGGLE (GPIOA->ODR ^= GPIO_ODR_OD6)
#define LCD_LOAD_1 (GPIOA->BSRR |= GPIO_BSRR_BS4)
#define LCD_LOAD_0 (GPIOA->BSRR |= GPIO_BSRR_BR4)

#define LCD_POS1    lcd_arr[10]
#define LCD_POS2    lcd_arr[9]
#define LCD_POS3    lcd_arr[8]
#define LCD_POS4    lcd_arr[7]
#define LCD_POS5    lcd_arr[6]
#define LCD_POS6    lcd_arr[5]
#define LCD_POS7    lcd_arr[4]
#define LCD_POS8    lcd_arr[3]
#define LCD_POS9    lcd_arr[2]
#define LCD_POS10   lcd_arr[1]
#define LCD_POS11   lcd_arr[0]

#define DIG_POS1    3
#define DIG_POS2    2
#define DIG_POS3    1
#define DIG_POS4    0


extern uint8_t lcd_buffer[11];

void lcd_send_data(uint8_t data);
void lcd_clear();
void lcd_update();
void lcd_write_buffer();
void lcd_print_digit(uint8_t digit, uint8_t position);
void lcd_print_all();
void lcd_print_value(uint16_t val);
uint8_t dec_to_lcd(uint8_t val, uint8_t dig_pos);