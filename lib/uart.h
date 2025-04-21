#ifndef _UART_H_
#define _UART_H_
#include <stdint.h>

#define USART1_ADDRESS 0x40013800
#define USART2_ADDRESS 0x40004400
#define USART3_ADDRESS 0x40004800

typedef struct
{
    volatile uint32_t USART_SR, USART_DR, USART_BRR, USART_CR1, USART_CR2, USART_CR3, USART_GTPR;
} USART_t;

#define USART1 ((USART_t *)(USART1_ADDRESS))
#define USART2 ((USART_t *)(USART2_ADDRESS))
#define USART3 ((USART_t *)(USART3_ADDRESS))
#endif
