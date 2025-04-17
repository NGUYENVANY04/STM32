#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "gpio.h"
#include "stdbool.h"
#include "uart.h"
void test_uart()
{
    USART1->USART_CR1 |= (uint32_t)1 << 13;
    USART1->USART_CR1 |= (uint32_t)0 << 12;
    USART1->USART_CR2 |= (uint32_t)0 << 12;
    USART1->USART_BRR = ((0x1D4 << 4) | 0xC);
    USART1->USART_CR1 |= (uint32_t)1 << 3;
}
int main(void)
{
    enable_clock();
    RCC->RCC_APB2ENR |= (1 << 14); // Bật clock USART1

    GPIO_Config_t gpio_tx = {
        .port = GPIOA,
        .pin = (uint16_t)1 << 9,
        .mode = GPIO_MODE_OUTPUT_50MHz,
        .outputType = GPIO_OUTPUT_AF_PUSH_PULL,
    };

    GPIO_Config_t gpio_output = {
        .port = GPIOC,
        .pin = (uint16_t)1 << 13,
        .mode = GPIO_MODE_OUTPUT_2MHz,
        .outputType = GPIO_OUTPUT_PUSH_PULL,

    };
    GPIO_Config_t gpio_input = {
        .port = GPIOC,
        .pin = (uint16_t)1 << 14,
        .mode = GPIO_MODE_INPUT,
        .inputType = GPIO_INPUT_FLOATING,
    };
    GPIO_Config(&gpio_tx);
    GPIO_Config(&gpio_output);
    GPIO_Config(&gpio_input);
    test_uart();
    while (1)
    {
        int data = gpio_get_level(&gpio_input);
        gpio_set_level(&gpio_output, data);
        for (int i = 0; i < 100000; i++) { }
        // gpio_set_level(&gpio_output, 0);
        // while (!(USART1->USART_SR & (1 << 7)))
        //  ; // Chờ TXE = 1 (Sẵn sàng gửi)
        // for (int i = 0; i < 100000; i++) { }

        // USART1->USART_DR = 'y';
    }
}
