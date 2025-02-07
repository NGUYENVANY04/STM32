#ifndef _BLINK_LED_H_
#define _BLINK_LED_H_
#include <cstdint>

#define GPIOA_BASE_ADDRESSS 0x40010800
#define GPIOB_BASE_ADDRESSS 0x40010C00
#define GPIOC_BASE_ADDRESSS 0x40011000
#define GPIOD_BASE_ADDRESSS 0x40011400
#define GPIOE_BASE_ADDRESSS 0x40011800
#define GPIOF_BASE_ADDRESSS 0x40011C00
#define GPIOG_BASE_ADDRESSS 0x40012000
typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t CBSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_REGISTER_t;

#define GPIOA ((GPIO_REGISTER_t *)GPIOA_BASE_ADDRESSS)
#define GPIOB ((GPIO_REGISTER_t *)GPIOB_BASE_ADDRESSS)
#define GPIOC ((GPIO_REGISTER_t *)GPIOC_BASE_ADDRESSS)
#define GPIOD ((GPIO_REGISTER_t *)GPIOD_BASE_ADDRESSS)
#define GPIOE ((GPIO_REGISTER_t *)GPIOE_BASE_ADDRESSS)
#define GPIOF ((GPIO_REGISTER_t *)GPIOF_BASE_ADDRESSS)
#define GPIOG ((GPIO_REGISTER_t *)GPIOG_BASE_ADDRESSS)
void set_mode();

#endif
