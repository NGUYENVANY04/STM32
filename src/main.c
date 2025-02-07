#include <stdio.h>
#include "drivers/rcc.h"
#include "drivers/blink_led.h"
void delay(volatile uint32_t time)
{
    while (time--)
        ;
}
int main()
{
    enable_clock();
    set_mode();
    printf("Hello world !!!");
    while (1)
    {
        GPIOC->ODR &= ~(1 << 13); // Tắt LED (GPIOC, pin 13)
        delay(1000000);
        GPIOC->ODR |= (1 << 13); // Bật LED (GPIOC, pin 13)
        delay(1000000);
    }
    return 0;
}
