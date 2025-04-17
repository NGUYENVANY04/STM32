#include "rcc.h"
#include <stdio.h>
/*
Bit 4 IOPCEN: IO port C clock enable
Set and cleared by software.
0: IO port C clock disabled
1: IO port C clock enabled
*/
void enable_clock() { RCC->RCC_APB2ENR |= (1 << 2); }

