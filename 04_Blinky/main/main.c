#include <stdio.h>

//utilização dos pinos
#include "driver/gpio.h"

//freeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 4


void app_main(void)
{
  //configura o pino como um gpio comum
  gpio_pad_select_gpio(PIN);
  //CONFIGURA COMO ENTRADA OU SAÍDA
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

  int isOn = 0;

  while(1)
  {
    isOn = !isOn;
    gpio_set_level(PIN,isOn);
    vTaskDelay(125 / portTICK_PERIOD_MS);
  }
}
