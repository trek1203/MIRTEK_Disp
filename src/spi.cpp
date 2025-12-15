#include "spi.hpp"

void spi_transmit(uint8_t data) {
    for(int8_t i = 7; i >= 0; i--) {
        if(data & (1 << i)) {
            GPIOA->BSRR = GPIO_BSRR_BS7;  // MOSI = 1
        } else {
            GPIOA->BSRR = GPIO_BSRR_BR7;  // MOSI = 0
        }
        for(volatile uint32_t d = 0; d < 5; d++);
        GPIOA->BSRR = GPIO_BSRR_BS5;  // SCK = 1
        for(volatile uint32_t d = 0; d < 10; d++);
        GPIOA->BSRR = GPIO_BRR_BR5;   // SCK = 0
        for(volatile uint32_t d = 0; d < 10; d++);
    }
}