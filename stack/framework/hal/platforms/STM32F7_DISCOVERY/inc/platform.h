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

#ifndef __PLATFORM_H_
#define __PLATFORM_H_

#include "platform_defs.h"

#ifndef PLATFORM_STM32F7_DISCOVERY
    #error Mismatch between the configured platform and the actual platform. Expected PLATFORM_STM32F7_DISCOVERY to be defined
#endif

/********************
 * LED DEFINITIONS *
 *******************/

#define HW_NUM_LEDS 4


/********************
 * UART DEFINITIONS *
 *******************/

// console configuration
#define CONSOLE_UART        0
#define CONSOLE_LOCATION    1
#define CONSOLE_BAUDRATE    115200

/*************************
 * DEBUG PIN DEFINITIONS *
 ************************/

// #define DEBUG_PIN_NUM 4
// #define DEBUG0	D4
// #define DEBUG1	D5
// #define DEBUG2	D6
// #define DEBUG3	D7

/**************************
 * USERBUTTON DEFINITIONS *
 *************************/

#define NUM_USERBUTTONS 	1
// #define BUTTON0				B9


// CC1101 PIN definitions
// #ifdef USE_CC1101
// #define CC1101_SPI_USART    1
// #define CC1101_SPI_BAUDRATE 6000000
// #define CC1101_SPI_LOCATION 1
// #define CC1101_SPI_PIN_CS   D3
// #define CC1101_GDO0_PIN     C3
// #define CC1101_GDO2_PIN     C4
// #endif

#define PLATFORM_NUM_TIMERS 1

#endif
