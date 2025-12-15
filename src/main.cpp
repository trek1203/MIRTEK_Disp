#include "main.hpp"

int main(void)
{
    INIT();
    lcd_print_value(8888);
    uint16_t counter = 0;
    while (1) // Counter
    {
        counter++;
        if (counter > 9999)
        {
            counter = 0;
        }
        lcd_print_value(counter);
        for (uint32_t i = 0; i < 60000; i++);
    }
    return 0;
}