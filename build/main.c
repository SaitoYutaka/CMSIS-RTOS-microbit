#include<nrfx.h>
#include<nrf_gpio.h>
/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions

#define ROW3 15
#define ROW2 14
#define ROW1 13
#define COL9 12
#define COL8 11
#define COL7 10
#define COL6  9
#define COL5  8
#define COL4  7
#define COL3  6
#define COL2  5
#define COL1  4

extern void sample_name (void const *argument) {
  nrf_gpio_pin_dir_set(ROW1, NRF_GPIO_PIN_DIR_OUTPUT);
  nrf_gpio_pin_dir_set(COL9, NRF_GPIO_PIN_DIR_OUTPUT);

  nrf_gpio_pin_clear(COL9);
  for (;;) {
    nrf_gpio_pin_clear(ROW1);
    for(int i = 0; i<800000;i++);
    nrf_gpio_pin_set(ROW1);
    for(int i = 0; i<800000;i++);
  }
}


/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS

  // initialize peripherals here

  tid_sample_name = osThreadCreate(osThread(sample_name), NULL);

  osKernelStart ();                         // start thread execution 
}
