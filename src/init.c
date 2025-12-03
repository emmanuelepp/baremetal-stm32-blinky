#include "stm32f4xx.h"

void SystemInit(void)
{

}

void led_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    (void)RCC->AHB1ENR;

    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    GPIOA->OTYPER &= ~(1U << 5);

    GPIOA->OSPEEDR &= ~(3U << (5 * 2));
    GPIOA->OSPEEDR |=  (2U << (5 * 2));

    GPIOA->PUPDR &= ~(3U << (5 * 2));
}
