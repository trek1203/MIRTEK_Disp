#include "init.hpp"

void INIT(void){
    init_RCC();
    init_GPIO();
    init_SPI();
    init_TIM3();
    lcd_clear();
}

void init_RCC(){
    RCC->CR |= RCC_CR_HSEON; // External clocking 25MHz
    while(!(RCC->CR & RCC_CR_HSERDY)); // Waiting for readiness
    FLASH->ACR = (FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_1WS);
    RCC->CFGR |= RCC_CFGR_SW_HSE; // As main clocking 
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
}

void init_GPIO(){
    //--- GPIOC ---//
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;  
    // PC13 LED
    GPIOC->MODER |= (0b01U << GPIO_MODER_MODER13_Pos);  // Output
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT13;
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED13_Msk; // Middle speed
    GPIOC->OSPEEDR |= (0b01U << GPIO_OSPEEDR_OSPEED13_Pos);
    //--- GPIOA ---//
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // PA4 Disp_Load
    GPIOA->MODER |= (0b01U << GPIO_MODER_MODER4_Pos); // Output
    GPIOA->OSPEEDR |= (0b10U << GPIO_OSPEEDR_OSPEED4_Pos); // Fast speed
    LCD_LOAD_0;
    // PA5 SPI_Sck
    GPIOA->MODER |= (1U << GPIO_MODER_MODER5_Pos); // Output
    GPIOA->OSPEEDR |= (0b10U << GPIO_OSPEEDR_OSPEED5_Pos); // Fast speed
    // PA6 Disp_CLK
    GPIOA->MODER |= (0b01U << GPIO_MODER_MODER6_Pos); // Output
    GPIOA->OSPEEDR |= (0b10U << GPIO_OSPEEDR_OSPEED6_Pos); // Fast speed
    LCD_CLK_0;
    // PA7 SPI_MOSI
    GPIOA->MODER |= (1U << GPIO_MODER_MODER7_Pos); // Output
    GPIOA->OSPEEDR |= (0b10U << GPIO_OSPEEDR_OSPEED7_Pos); // Fast speed
}

void init_TIM3(){
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->CR1 &= ~TIM_CR1_CEN;
    TIM3->PSC = 250U;      
    TIM3->ARR = 1500U;      
    TIM3->CNT = 0;
    TIM3->SR = 0;
    TIM3->DIER = TIM_DIER_UIE;
    TIM3->SR = 0;
    NVIC_EnableIRQ(TIM3_IRQn);
    NVIC_SetPriority(TIM3_IRQn, 1);  
    TIM3->CR1 = TIM_CR1_CEN;
}