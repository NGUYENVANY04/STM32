#include "adc.h"

void init_adc(void)
{
    ADC1->ADC_CR2 |= 1U << 23; // 1: Temperature sensor and V REFINT channel enabled
    ADC1->ADC_CR2 |= 1U << 1;
    //  1 : Continuous conversion mode
    //   ADC1->ADC_CR2 |= 1U << 22; // 1: Starts conversion of regular channels
    ADC1->ADC_SQR3 &= ~(0x1F); // clear SQ1
    ADC1->ADC_SQR3 |= (16U << 0); // SQ1 = channel 16

    ADC1->ADC_SMPR1 &= ~(7U << 18); // Clear các bit đã chọn cho kênh 16
    ADC1->ADC_SMPR1 |= (6U << 18); // Cấu hình thời gian mẫu 71.5 cycles
                                   //
    ADC1->ADC_CR2 |= 1U << 22; // 1: Start conversion of regular channels
                               //   ADC1->ADC_SQR3 |= 16U << 0; // Bits 4:0 SQ1[4:0]: first
                               //   conversion in regular sequence
}



void start_adc(void)
{
    // Bật ADC lần 1 (wake up)
    ADC1->ADC_CR2 |= 1U << 0;
    for (volatile int i = 0; i < 10000; i++)
        ; // delay nhỏ

    // Bắt đầu chuyển đổi bằng phần mềm
    ADC1->ADC_CR2 |= 1U << 22;
}
