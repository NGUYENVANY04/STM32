/*
 *   Driver gpio stm32f103c8t6
 */

#ifndef _GPIO_H_
#define _GPIO_H_
#include <stdbool.h>
#include <stdint.h>

#define SET_BIT(REG, BIT) ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT) ((REG) & (BIT))
#define CLEAR_REG(REG) ((REG) = (0x0))
#define WRITE_REG(REG, VAL) ((REG) = (VAL))
#define READ_REG(REG) ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)                                                        \
    WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define GPIOA_BASE_ADDRESSS 0x40010800
#define GPIOB_BASE_ADDRESSS 0x40010C00
#define GPIOC_BASE_ADDRESSS 0x40011000
#define GPIOD_BASE_ADDRESSS 0x40011400
#define GPIOE_BASE_ADDRESSS 0x40011800
#define GPIOF_BASE_ADDRESSS 0x40011C00
#define GPIOG_BASE_ADDRESSS 0x40012000
typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_REGISTER_t;
#define GPIOA ((GPIO_REGISTER_t *)GPIOA_BASE_ADDRESSS)
#define GPIOB ((GPIO_REGISTER_t *)GPIOB_BASE_ADDRESSS)
#define GPIOC ((GPIO_REGISTER_t *)GPIOC_BASE_ADDRESSS)
#define GPIOD ((GPIO_REGISTER_t *)GPIOD_BASE_ADDRESSS)
#define GPIOE ((GPIO_REGISTER_t *)GPIOE_BASE_ADDRESSS)
#define GPIOF ((GPIO_REGISTER_t *)GPIOF_BASE_ADDRESSS)
#define GPIOG ((GPIO_REGISTER_t *)GPIOG_BASE_ADDRESSS)
typedef enum
{
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT_10MHz = 1,
    GPIO_MODE_OUTPUT_2MHz,
    GPIO_MODE_OUTPUT_50MHz,
} GPIO_MODE_t;

typedef enum
{
    GPIO_INPUT_ANALOG = 0,
    GPIO_INPUT_FLOATING,
    GPIO_INPUT_PULL_UP_DOWN,
} GPIO_InputType_t;

typedef enum
{
    GPIO_OUTPUT_PUSH_PULL = 0,
    GPIO_OUTPUT_OPEN_DRAIN,
    GPIO_OUTPUT_AF_PUSH_PULL,
    GPIO_OUTPUT_AF_OPEN_DRAIN,
} GPIO_OutputType_t;
/*
 * port config A,B ....
 * mode : out, In
 * pin : use mode
 */
typedef struct
{
    uint16_t pin;
    GPIO_REGISTER_t *port;
    GPIO_MODE_t mode;
    union
    {
        GPIO_InputType_t inputType;
        GPIO_OutputType_t outputType;
    };
} GPIO_Config_t;

/***************** API gpio by Nguyen Van Y ******************/
/**
 * @brief GPIO common configuration
 *
 *        Configure GPIO's Mode,pull-up,PullDown,IntrType
 *
 * @param  config Pointer to GPIO configure struct
 *
 * @return
 *     - Void
 */
void GPIO_Config(GPIO_Config_t *config);
void gpio_set_level(GPIO_Config_t *config, bool lever);
bool gpio_get_level(GPIO_Config_t *config);
void gpio_toggle_level(GPIO_Config_t *config);
#endif

