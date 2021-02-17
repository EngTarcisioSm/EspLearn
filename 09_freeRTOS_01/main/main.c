#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void task1()
{
  while(true)
  {
    printf("reading temperature \n");
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
  }
}

void task2()
{
  while(true)
  {
    printf("reading humidity\n");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}


void app_main(void)
{
  xTaskCreate(&task1, "temperature reading", 2048, NULL,2,NULL);
  xTaskCreate(&task2, "humidity reading", 2048, NULL, 2, NULL);
}
