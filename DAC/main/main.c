#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/dac.h"


void app_main(void)
{
  unsigned char value = 0;
  dac_output_enable(DAC_CHANNEL_1);
  while(1)
  {
    dac_output_voltage(DAC_CHANNEL_1,value);
    value+=5;
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
