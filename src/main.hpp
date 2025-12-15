#pragma once
#include "stm32f4xx.h"
#include "init.hpp"
#include "display.hpp"
#include "spi.hpp"
#include "interrupt.hpp"

#define LED_ON()   (GPIOC->BSRR = GPIO_BSRR_BR13)
#define LED_OFF()  (GPIOC->BSRR = GPIO_BSRR_BS13)
#define LED_TOGGLE() (GPIOC->ODR ^= (1 << 13))

