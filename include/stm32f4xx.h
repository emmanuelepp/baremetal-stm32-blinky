/* stm32f4xx.h */
#ifndef STM32F4XX_H
#define STM32F4XX_H

#include <stdint.h>

/* ---------------- Base addresses ---------------- */

#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)   
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)   

/* ---------------- GPIO register layout ---------------- */

typedef struct
{
    volatile uint32_t MODER;   /*!< GPIO port mode register,               offset 0x00 */
    volatile uint32_t OTYPER;  /*!< GPIO port output type register,        offset 0x04 */
    volatile uint32_t OSPEEDR; /*!< GPIO port output speed register,       offset 0x08 */
    volatile uint32_t PUPDR;   /*!< GPIO port pull-up/pull-down register,  offset 0x0C */
    volatile uint32_t IDR;     /*!< GPIO port input data register,         offset 0x10 */
    volatile uint32_t ODR;     /*!< GPIO port output data register,        offset 0x14 */
    volatile uint32_t BSRR;    /*!< GPIO port bit set/reset register,      offset 0x18 */
    volatile uint32_t LCKR;    /*!< GPIO port configuration lock register, offset 0x1C */
    volatile uint32_t AFR[2];  /*!< GPIO alternate function registers,     offset 0x20-0x24 */
} GPIO_TypeDef;

/* ---------------- RCC register layout (minimal) ---------------- */

typedef struct
{
    volatile uint32_t CR;        /*!< Clock control register,           offset 0x00 */
    volatile uint32_t PLLCFGR;   /*!< PLL configuration register,       offset 0x04 */
    volatile uint32_t CFGR;      /*!< Clock configuration register,     offset 0x08 */
    volatile uint32_t CIR;       /*!< Clock interrupt register,         offset 0x0C */
    volatile uint32_t AHB1RSTR;  /*!< AHB1 peripheral reset register,   offset 0x10 */
    volatile uint32_t AHB2RSTR;  /*!< AHB2 peripheral reset register,   offset 0x14 */
    volatile uint32_t AHB3RSTR;  /*!< AHB3 peripheral reset register,   offset 0x18 */
    uint32_t          RESERVED0; /*!< Reserved,                         offset 0x1C */
    volatile uint32_t APB1RSTR;  /*!< APB1 peripheral reset register,   offset 0x20 */
    volatile uint32_t APB2RSTR;  /*!< APB2 peripheral reset register,   offset 0x24 */
    uint32_t          RESERVED1[2];
    volatile uint32_t AHB1ENR;   /*!< AHB1 peripheral clock enable,     offset 0x30 */
    volatile uint32_t AHB2ENR;   /*!< AHB2 peripheral clock enable,     offset 0x34 */
    volatile uint32_t AHB3ENR;   /*!< AHB3 peripheral clock enable,     offset 0x38 */
    uint32_t          RESERVED2;
    volatile uint32_t APB1ENR;   /*!< APB1 peripheral clock enable,     offset 0x40 */
    volatile uint32_t APB2ENR;   /*!< APB2 peripheral clock enable,     offset 0x44 */
} RCC_TypeDef;

/* ---------------- Peripheral instances ---------------- */

#define RCC   ((RCC_TypeDef *) RCC_BASE)
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)

/* ---------------- Useful bit definitions ---------------- */

/* RCC AHB1 peripheral clock enable register bits */
#define RCC_AHB1ENR_GPIOAEN   (1U << 0) 

/* GPIO MODER bits for pin 5 */
#define GPIO_MODER_MODER5_Pos  (5U * 2U)
#define GPIO_MODER_MODER5_Msk  (3U << GPIO_MODER_MODER5_Pos)
#define GPIO_MODER_MODER5_OUTPUT (1U << GPIO_MODER_MODER5_Pos)

/* GPIO ODR bit for pin 5 */
#define GPIO_ODR_OD5           (1U << 5)

#endif