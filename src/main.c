#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "gpio.h"
#include "stdbool.h"
#include "uart.h"
#include "adc.h"
#include "drivers/log_info.h"

int main(void)
{
    RCC->RCC_APB2ENR |= 1U << 4;
    GPIO_Config_t test = {
        .port = GPIOC,
        .mode = GPIO_MODE_OUTPUT_50MHz,
        .outputType = GPIO_OUTPUT_PUSH_PULL,
        .pin = 1U << 13,
    };
    GPIO_Config(&test);

    while (1)
    {
        gpio_set_level(&test, true);
        for (int i = 0; i < 100000; i++) { }
        gpio_set_level(&test, false);
        for (int i = 0; i < 100000; i++) { }
    }
}
