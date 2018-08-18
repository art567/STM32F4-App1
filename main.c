#include "stm32f4xx_hal.h"
 
int main() {
    HAL_Init();
 
    // Разрешить тактирование порта A.
    __HAL_RCC_GPIOA_CLK_ENABLE();
 
    // Настройки порта 6.
    GPIO_InitTypeDef p6;
    p6.Pin   = GPIO_PIN_6;                // Вывод 6.
    p6.Mode  = GPIO_MODE_OUTPUT_PP;       // Цифровой выход.
    p6.Pull  = GPIO_NOPULL;               // Без подтяжки.
    p6.Speed = GPIO_SPEED_FREQ_VERY_HIGH; // Максимальная скорость.
 
    // Настройки порта 6.
    GPIO_InitTypeDef p7;
    p7.Pin   = GPIO_PIN_7;                // Вывод 7.
    p7.Mode  = GPIO_MODE_OUTPUT_PP;       // Цифровой выход.
    p7.Pull  = GPIO_NOPULL;               // Без подтяжки.
    p7.Speed = GPIO_SPEED_FREQ_VERY_HIGH; // Максимальная скорость.
  
    // Настроить вывод 6 порт A.
    HAL_GPIO_Init(GPIOA, &p6);
    // Настроить вывод 7 порт A.
    HAL_GPIO_Init(GPIOA, &p7);
 
    // Бесконечно переключать состояние порта с максимальной скоростью.
    while(1) {
        HAL_Delay(500);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
    }
 
    //return 0;
}
 
void SysTick_Handler(void) {
    HAL_IncTick();
}
