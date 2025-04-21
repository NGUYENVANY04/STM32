#include "log_info.h"
#include "uart.h"
#include <stdint.h>
void log_info(int data)
{

    // print data by uart
    USART1->USART_DR = data; // LOad the Data
    while (!(USART1->USART_SR & (1 << 6)))
        ;
}

