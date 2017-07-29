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

#include "platform_sensors.h"
#include "hwgpio.h"
#include "hwadc.h"
#include "hwatomic.h"
#include "scheduler.h"
#include <string.h>
#include <debug.h>

//TODO Lightsensor uses ACMP, LESENSE, PRS
//#define LIGHT_SENSOR_ENABLE_PORTPIN		D6
////#define LIGHT_SENSOR_ENABLE_PORT		gpioPortD
//#define LIGHT_SENSOR_READ_PORT			gpioPortC
//#define LIGHT_SENSOR_READ_PORTPIN		C6

static uint32_t temp_offset;

void initSensors()
{
	

}

//__LINK_C void lightsensor_init();
//__LINK_C void lightsensor_enable();
//__LINK_C void lightsensor_dissable();
//__LINK_C uint32_t lightsensor_read();


/*! \brief Initializes ADC to measure the internal temperature
 */
void internalTempSensor_init()
{
	
}

/*! \brief Measures the interternal temperature using the ADC and converts it to Celcius
 *	\note It expects the user to initialise the ADC using internalTempSensor_init()
 */
float hw_get_internal_temperature()
{
	return 27.5;
}

/*! \brief Convert a temperature ADC sample to temperature taking into account the factory calibration
 * 	\note See section 2.3.4 in the reference manual for details on this calculation
 *
 * 	\param adcSample Raw value from ADC to be converted to Celsius
 * 	\return The temperature in degrees Celsius.
 */
float convertAdcToCelsius(int32_t adcSample) {
	return adcSample + 27.5;
}


void init_external_adc() {

}

void adc_start_scan() {
	
}

void adc_clear_scan_interupt() {
	
}

uint32_t adc_get_scan_result() {
	return 42;
}

//void lightsensor_init()
//{
//	/* Configure the drive strength of the ports for the light sensor. */
//	//GPIO_DriveModeSet(LIGHT_SENSOR_ENABLE_PORTPIN, gpioDriveModeStandard);
//	//GPIO_DriveModeSet(LIGHT_SENSOR_READ_PORT, gpioDriveModeStandard);
//
//	// LIGHT SENSOR
//	error_t err = hw_gpio_configure_pin(LIGHT_SENSOR_ENABLE_PORTPIN, false, gpioModeDisabled, 0);
//	err = hw_gpio_configure_pin(LIGHT_SENSOR_READ_PORTPIN, false, gpioModeDisabled, 0);
//	assert(err == SUCCESS);
//
//
//}
//
//void lightsensor_enable()
//{
//	hw_gpio_set(LIGHT_SENSOR_ENABLE_PORTPIN);
//}
//
//void lightsensor_dissable()
//{
//	hw_gpio_clr(LIGHT_SENSOR_ENABLE_PORTPIN);
//}
//
//uint32_t lightsensor_read()
//{
//
//}
