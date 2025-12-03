#include "stm32f4xx.h"

void led_init(void);

static void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm__("nop");
    }
}

int main(void)
{
    led_init();

    while (1)
    {
        GPIOA->ODR ^= (1U << 5);

        delay(200000);
    }

    return 0;
}
