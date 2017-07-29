/* * OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
 * lowpower wireless sensor communication
 *
 * Copyright 2015 University of Antwerp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define USE_STDPERIPH_DRIVER
#include "stm32f7.h"
#include "stm32f7_mcu.h"
#include "bootstrap.h"
#include "hwgpio.h"
#include "hwleds.h"
#include "button.h"
#include "stm32f7_gpio.h"
#include "hwsystem.h"
#include "debug.h"
#include "stm32f7_pins.h"
#include "stm32f7_hal.h"


#if defined(USE_SX127X) && defined(PLATFORM_SX127X_USE_RESET_PIN)
static void reset_sx127x()
{
  error_t e;
  e = hw_gpio_configure_pin(SX127x_RESET_PIN, false, GPIO_MODE_OUTPUT_PP, 0); assert(e == SUCCESS); // TODO platform specific
  hw_busy_wait(150);
  e = hw_gpio_configure_pin(SX127x_RESET_PIN, false, GPIO_MODE_INPUT, 1); assert(e == SUCCESS); // TODO platform specific
  hw_busy_wait(6000);
}
#endif


void __platform_init()
{
    __stm32f7xx_mcu_init();
    __gpio_init();

#ifdef USE_SX127X
    // configure the interrupt pins here, since hw_gpio_configure_pin() is MCU
    // specific and not part of the common HAL API
    hw_gpio_configure_pin(SX127x_DIO0_PIN, true, GPIO_MODE_INPUT, 0);
    hw_gpio_configure_pin(SX127x_DIO1_PIN, true, GPIO_MODE_INPUT, 0);
#ifdef PLATFORM_SX127X_USE_DIO3_PIN
    hw_gpio_configure_pin(SX127x_DIO3_PIN, true, GPIO_MODE_INPUT, 0);
#endif
#ifdef PLATFORM_SX127X_USE_RESET_PIN
    hw_gpio_configure_pin(SX127x_RESET_PIN, false, GPIO_MODE_OUTPUT_PP, 1);
    reset_sx127x();
#endif
#endif

#if defined(USE_SX127X) && defined(PLATFORM_SX127X_USE_RESET_PIN)
    reset_sx127x();
#endif

    HAL_EnableDBGSleepMode(); // TODO impact on power?
}

void __platform_post_framework_init()
{
    __ubutton_init();
//    led_init();
}


//Quick hack, approximately 1ms delay
void ms_delay(int ms)
{
   while (ms-- > 0) {
      volatile int x=5971;
      while (x-- > 0)
         __asm("nop");
   }
}

int main()
{
//    //initialise the platform itself
    __platform_init();
//    //do not initialise the scheduler, this is done by __framework_bootstrap()
    __framework_bootstrap();
//    //initialise platform functionality that depends on the framework
    __platform_post_framework_init();

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  // enable the clock to GPIOD
    __asm("dsb");                         // stall instruction pipeline, until instruction completes, as
                                          //    per Errata 2.1.13, "Delay after an RCC peripheral clock enabling"
    GPIOD->MODER = (1 << 26);             // set pin 13 to be general purpose output

    for (;;) {
       int i = 0;
       ms_delay(1000);
       GPIOD->ODR ^= (1 << 13);           // Toggle the pin
    }

    scheduler_run();
    return 0;
}
