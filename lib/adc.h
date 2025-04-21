#ifndef _ADC_H_
#define _ADC_H_
#include <stdio.h>
#include <stdint.h>

#define ADC1_ADRESS 0x40012400
#define ADC2_ADRESS 0x40012800

typedef struct
{
    volatile uint32_t ADC_SR;
    volatile uint32_t ADC_CR1;
    volatile uint32_t ADC_CR2;
    volatile uint32_t ADC_SMPR1;
    volatile uint32_t ADC_SMPR2;
    volatile uint32_t ADC_JOFR1;
    volatile uint32_t ADC_JOFR2;
    volatile uint32_t ADC_JOFR3;
    volatile uint32_t ADC_JOFR4;
    volatile uint32_t ADC_HTR;
    volatile uint32_t ADC_LTR;
    volatile uint32_t ADC_SQR1;
    volatile uint32_t ADC_SQR2;
    volatile uint32_t ADC_SQR3;
    volatile uint32_t ADC_JSQR;
    volatile uint32_t ADC_JDR1;
    volatile uint32_t ADC_JDR2;
    volatile uint32_t ADC_JDR3;
    volatile uint32_t ADC_JDR4;
    volatile uint32_t ADC_DR;
} ADC_t;

#define ADC1 ((ADC_t *)ADC1_ADRESS)
#define ADC2 ((ADC_t *)ADC2_ADRESS)
void init_adc(void);
#endif
