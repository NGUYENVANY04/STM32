/**
  ******************************************************************************
  * @file    gpio.c
  * @author  NGUYENVANY
  * @version V1.0.0
  * @date    1-03-2025
  * @brief   GPIO module driver.
  *         This file provides firmware functions to manage the following
  *          functionalities of the General Purpose Input/Output (GPIO) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *
  @verbatim
  ==============================================================================
                    ##### GPIO Peripheral features #####
  ==============================================================================
  [..]
  Subject to the specific hardware characteristics of each I/O port listed in the datasheet, each
  port bit of the General Purpose IO (GPIO) Ports, can be individually configured by software
  in several modes:
  (+) Input mode
  (+) Analog mode
  (+) Output mode
  (+) Alternate function mode
  (+) External interrupt/event lines

  [..]
  During and just after reset, the alternate functions and external interrupt
  lines are not active and the I/O ports are configured in input floating mode.

  [..]
  All GPIO pins have weak internal pull-up and pull-down resistors, which can be
  activated or not.

  [..]
  In Output or Alternate mode, each IO can be configured on open-drain or push-pull
  type and the IO speed can be selected depending on the VDD value.

  [..]
  All ports have external interrupt/event capability. To use external interrupt
  lines, the port must be configured in input mode. All available GPIO pins are
  connected to the 16 external interrupt/event lines from EXTI0 to EXTI15.

  [..]
  The external interrupt/event controller consists of up to 20 edge detectors in connectivity
  line devices, or 19 edge detectors in other devices for generating event/interrupt requests.
  Each input line can be independently configured to select the type (event or interrupt) and
  the corresponding trigger event (rising or falling or both). Each line can also masked
  independently. A pending register maintains the status line of the interrupt requests

                     ##### How to use this driver #####
  ==============================================================================
 [..]
   (#) Enable the GPIO APB2 clock using the following function

   (#) Configure the GPIO pin(s) using GPIO_Config.
       (++) Configure the IO mode using "Mode" member from GPIO_Config_t structure
       (++) Activate Pull-up, Pull-down resistor using "Pull" member from GPIO_Config_t
            structure.
       (++) In case of Output or alternate function mode selection: the speed is
            configured through "Speed" member from GPIO_Config_t structure
       (++) Analog mode is required when a pin is to be used as ADC channel
            or DAC output.
       (++) In case of external interrupt/event selection the "Mode" member from
            GPIO_Config_t structure select the type (interrupt or event) and
            the corresponding trigger event (rising or falling or both).

   (#) In case of external interrupt/event mode selection, configure NVIC IRQ priority
       mapped to the EXTI line using HAL_NVIC_SetPriority() and enable it using
       HAL_NVIC_EnableIRQ().

   (#) To get the level of a pin configured in input mode use gpio_get_lever().

   (#) To set/reset the level of a pin configured in output mode use
       gpio_set_lever()/gpio_toggle_lever().

   (#) To lock pin configuration until next reset use gpio_lock.

   (#) During and just after reset, the alternate functions are not
       active and the GPIO pins are configured in input floating mode (except JTAG
       pins).

   (#) The LSE oscillator pins OSC32_IN and OSC32_OUT can be used as general purpose
       (PC14 and PC15, respectively) when the LSE oscillator is off. The LSE has
       priority over the GPIO function.

   (#) The HSE oscillator pins OSC_IN/OSC_OUT can be used as
       general purpose PD0 and PD1, respectively, when the HSE oscillator is off.
       The HSE has priority over the GPIO function.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>
/**
 * @brief  Configures the mode of a pin : input, output, alt or analog mode
 * @param  *GPIOx : GPIO Port Base address
 * @retval None
 */
void GPIO_Config(GPIO_Config_t *config)
{
    uint32_t index;
    uint32_t check_index = 0;
    uint32_t handle_index = 0;
    uint32_t config_used = 0;
    uint32_t *index_register = 0;
    uint32_t index_offset = 0;
    for (index = 0; index < 16; index++)
    {
        // dich bit de co pin tuong ung
        check_index = (uint32_t)1 << index;
        handle_index = config->pin & check_index;
        if (handle_index == check_index)
        {

            config_used =
                ((config->mode == GPIO_MODE_INPUT) ? (config->inputType << 2) | config->mode
                                                   : (config->outputType << 2) | config->mode);
            index_register = (index < 8) ? &config->port->CRL : &config->port->CRH;
            index_offset = (index < 8) ? (index << 2) : ((index - 8) << 2);
            // clear
            // set config used
            MODIFY_REG((*index_register), ((uint32_t)(0xF) << index_offset),
                       (config_used << index_offset));
        }
    }
}
/**
 * @brief  Write a value to given pin number
 * @param  *GPIOx : GPIO Port Base address
 * @param  value   : value to be written
 * @retval None
 */
void gpio_set_level(GPIO_Config_t *config, bool level)
{

    if (level)
        config->port->BSRR = (config->pin);
    else
        config->port->BRR = (config->pin);
}
/**
 * @brief  Read a value from a  given pin number
 * @param  *GPIOx : GPIO Port Base address
 * @retval uint8_t: Value read
 */
bool gpio_get_level(GPIO_Config_t *config)
{
    return (config->port->IDR & (config->pin)) ? true : false;
}
void gpio_toggle_level(GPIO_Config_t *config) { config->port->ODR ^= (config->pin); }
