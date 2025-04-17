#ifndef _RCC_H_
#define _RCC_H_
#include <stdint.h>
#define ADRESS_BASE_RCC 0x40021000
typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_AHBENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
} RCC_REGISTER_t;
#define RCC ((RCC_REGISTER_t *)(ADRESS_BASE_RCC))
void enable_clock(void);
#endif

