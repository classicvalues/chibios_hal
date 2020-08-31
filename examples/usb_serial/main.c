/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
    NOTE: This file has been modified.
*/

#include "hal.h"
#include "usb_serial.h"

/*
 * Application entry point.
 */
int main(void)
{

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */
  halInit();

  /*
   * Enabling interrupts, initialization done.
   */
  osalSysEnable();

  /*
   * Initializes a serial-over-USB CDC driver.
   */
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg);

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   * Note, a delay is inserted in order to not have to disconnect the cable
   * after a reset.
   */
  usbDisconnectBus(serusbcfg.usbp);
  osalThreadSleepMilliseconds(1000);
  usbStart(serusbcfg.usbp, &usbcfg);
  usbConnectBus(serusbcfg.usbp);

  bool led_status = true;

  /*
   * Normal main() thread activity, in this demo it just performs
   * a shell respawn upon its termination.
   */
  while (true)
  {

    if (led_status)
    {
      palSetPad(GPIOB, GPIOB_LED_STAT); /* Blue.    */
    }
    else
    {
      palClearPad(GPIOB, GPIOB_LED_STAT); /* Blue.    */
    }
    led_status = !led_status;

    palSetPad(GPIOB, GPIOB_LED_WARN); /* Orange.  */
    osalThreadSleepMilliseconds(500);
    palClearPad(GPIOB, GPIOB_LED_WARN); /* Orange.  */
    osalThreadSleepMilliseconds(500);

    chnWriteTimeout(&SDU1, (uint8_t *)"Hello World!\r\n", 14, TIME_INFINITE);
  }
}
