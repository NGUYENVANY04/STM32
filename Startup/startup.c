#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (20 * 1024) // SIZE SRAM
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_START SRAM_END


extern uint32_t _estack;  // Stack pointer defined in linker script
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;
extern int main(void);

/*
_estack: Con trỏ stack, trỏ đến đỉnh của stack trong RAM.
_sidata: Điểm bắt đầu của .data trong Flash (nguồn dữ liệu).
_sdata: Điểm bắt đầu của .data trong RAM (đích cần copy).
_edata: Điểm kết thúc của .data trong RAM (dừng copy).
_sbss: Điểm bắt đầu của .bss trong RAM.
_ebss: Điểm kết thúc của .bss trong RAM.*/


extern void Reset_Handler(void);
extern void Default_Handle(void);

// Cortex-M3 Exception Handlers
void NMI_handle(void) __attribute__((weak, alias("Default_Handle")));
void HardFault_handle(void) __attribute__((weak, alias("Default_Handle")));
void MemManage_handle(void) __attribute__((weak, alias("Default_Handle")));
void BusFault_handle(void) __attribute__((weak, alias("Default_Handle")));
void UsageFault_handle(void) __attribute__((weak, alias("Default_Handle")));
void SVCall_handle(void) __attribute__((weak, alias("Default_Handle")));
void Debug_Monitor_handle(void) __attribute__((weak, alias("Default_Handle")));
void PendSV_handle(void) __attribute__((weak, alias("Default_Handle")));
void SysTick_handle(void) __attribute__((weak, alias("Default_Handle")));

// STM32F103 IRQ Handlers
void WWDG_handle(void) __attribute__((weak, alias("Default_Handle")));
void PVD_handle(void) __attribute__((weak, alias("Default_Handle")));
void TAMPER_handle(void) __attribute__((weak, alias("Default_Handle")));
void RTC_handle(void) __attribute__((weak, alias("Default_Handle")));
void FLASH_handle(void) __attribute__((weak, alias("Default_Handle")));
void RCC_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI0_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI1_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI2_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI3_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI4_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel1_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel2_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel3_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel4_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel5_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel6_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA1_Channel7_handle(void) __attribute__((weak, alias("Default_Handle")));
void ADC1_2_handle(void) __attribute__((weak, alias("Default_Handle")));
void USB_HP_CAN_TX_handle(void) __attribute__((weak, alias("Default_Handle")));
void USB_LP_CAN_RX0_handle(void) __attribute__((weak, alias("Default_Handle")));
void CAN_RX1_handle(void) __attribute__((weak, alias("Default_Handle")));
void CAN_SCE_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI9_5_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM1_BRK_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM1_UP_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM1_TRG_COM_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM1_CC_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM2_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM3_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM4_handle(void) __attribute__((weak, alias("Default_Handle")));
void I2C1_EV_handle(void) __attribute__((weak, alias("Default_Handle")));
void I2C1_ER_handle(void) __attribute__((weak, alias("Default_Handle")));
void I2C2_EV_handle(void) __attribute__((weak, alias("Default_Handle")));
void I2C2_ER_handle(void) __attribute__((weak, alias("Default_Handle")));
void SPI1_handle(void) __attribute__((weak, alias("Default_Handle")));
void SPI2_handle(void) __attribute__((weak, alias("Default_Handle")));
void USART1_handle(void) __attribute__((weak, alias("Default_Handle")));
void USART2_handle(void) __attribute__((weak, alias("Default_Handle")));
void USART3_handle(void) __attribute__((weak, alias("Default_Handle")));
void EXTI15_10_handle(void) __attribute__((weak, alias("Default_Handle")));
void RTCAlarm_handle(void) __attribute__((weak, alias("Default_Handle")));
void USBWakeUp_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM8_BRK_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM8_UP_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM8_TRG_COM_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM8_CC_handle(void) __attribute__((weak, alias("Default_Handle")));
void ADC3_handle(void) __attribute__((weak, alias("Default_Handle")));
void FSMC_handle(void) __attribute__((weak, alias("Default_Handle")));
void SDIO_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM5_handle(void) __attribute__((weak, alias("Default_Handle")));
void SPI3_handle(void) __attribute__((weak, alias("Default_Handle")));
void UART4_handle(void) __attribute__((weak, alias("Default_Handle")));
void UART5_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM6_handle(void) __attribute__((weak, alias("Default_Handle")));
void TIM7_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA2_Channel1_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA2_Channel2_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA2_Channel3_handle(void) __attribute__((weak, alias("Default_Handle")));
void DMA2_Channel4_5_handle(void) __attribute__((weak, alias("Default_Handle")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = { 
    // 0x00000000000
    STACK_START,// 0x00000000000
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_handle,
    (uint32_t)&HardFault_handle,
    (uint32_t)&MemManage_handle,
    (uint32_t)&BusFault_handle,
    (uint32_t)&UsageFault_handle,
    0, 0, 0, 0,                     // Reserved
    (uint32_t)&SVCall_handle,
    (uint32_t)&Debug_Monitor_handle,
    0,                              // Reserved
    (uint32_t)&PendSV_handle,
    (uint32_t)&SysTick_handle,

    // External Interrupts
    (uint32_t)&WWDG_handle,
    (uint32_t)&PVD_handle,
    (uint32_t)&TAMPER_handle,
    (uint32_t)&RTC_handle,
    (uint32_t)&FLASH_handle,
    (uint32_t)&RCC_handle,
    (uint32_t)&EXTI0_handle,
    (uint32_t)&EXTI1_handle,
    (uint32_t)&EXTI2_handle,
    (uint32_t)&EXTI3_handle,
    (uint32_t)&EXTI4_handle,
    (uint32_t)&DMA1_Channel1_handle,
    (uint32_t)&DMA1_Channel2_handle,
    (uint32_t)&DMA1_Channel3_handle,
    (uint32_t)&DMA1_Channel4_handle,
    (uint32_t)&DMA1_Channel5_handle,
    (uint32_t)&DMA1_Channel6_handle,
    (uint32_t)&DMA1_Channel7_handle,
    (uint32_t)&ADC1_2_handle,
    (uint32_t)&USB_HP_CAN_TX_handle,
    (uint32_t)&USB_LP_CAN_RX0_handle,
    (uint32_t)&CAN_RX1_handle,
    (uint32_t)&CAN_SCE_handle,
    (uint32_t)&EXTI9_5_handle,
    (uint32_t)&TIM1_BRK_handle,
    (uint32_t)&TIM1_UP_handle,
    (uint32_t)&TIM1_TRG_COM_handle,
    (uint32_t)&TIM1_CC_handle,
    (uint32_t)&TIM2_handle,
    (uint32_t)&TIM3_handle,
    (uint32_t)&TIM4_handle,
    (uint32_t)&I2C1_EV_handle,
    (uint32_t)&I2C1_ER_handle,
    (uint32_t)&I2C2_EV_handle,
    (uint32_t)&I2C2_ER_handle,
    (uint32_t)&SPI1_handle,
    (uint32_t)&SPI2_handle,
    (uint32_t)&USART1_handle,
    (uint32_t)&USART2_handle,
    (uint32_t)&USART3_handle,
    (uint32_t)&EXTI15_10_handle,
    (uint32_t)&RTCAlarm_handle,
    (uint32_t)&USBWakeUp_handle,
    (uint32_t)&TIM8_BRK_handle,
    (uint32_t)&TIM8_UP_handle,
    (uint32_t)&TIM8_TRG_COM_handle,
    (uint32_t)&TIM8_CC_handle,
    (uint32_t)&ADC3_handle,
    (uint32_t)&FSMC_handle,
    (uint32_t)&SDIO_handle,
    (uint32_t)&TIM5_handle,
    (uint32_t)&SPI3_handle,
    (uint32_t)&UART4_handle,
    (uint32_t)&UART5_handle,
    (uint32_t)&TIM6_handle,
    (uint32_t)&TIM7_handle,
    (uint32_t)&DMA2_Channel1_handle,
    (uint32_t)&DMA2_Channel2_handle,
    (uint32_t)&DMA2_Channel3_handle,
    (uint32_t)&DMA2_Channel4_5_handle
};

void Reset_Handler(void)
{
/* Copy initialized data from flash to RAM */
    uint32_t *pSrc = &_sidata;
    uint32_t *pDest = &_sdata;
    while (pDest < &_edata) {
        *pDest++ = *pSrc++;
       
    }
    
    /* Zero initialize the .bss section */
    pDest = &_sbss;
    while (pDest < &_ebss) {
        *pDest++ = 0;
    }
    
    /* Call the main function */
 
    main();
    

    while (1);

}
void Default_Handle(void)
{
    while (1);
}
