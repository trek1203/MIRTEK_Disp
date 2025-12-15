#include "interrupt.hpp"

void TIM3_IRQHandler()
{
   static uint8_t counter = 0;
   if (TIM3->SR & TIM_SR_UIF)
   {
      TIM3->SR &= ~TIM_SR_UIF;

      LCD_CLK_TOGGLE;
      counter++;
      if (counter >= 50)
      {
         LED_TOGGLE();
         counter = 0;
      }
   }
}
