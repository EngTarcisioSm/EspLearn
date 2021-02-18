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
    vTaskDelay(1500 / portTICK_PERIOD_MS);
  }
}


void app_main(void)
{
  xTaskCreate(&task1, "temperature reading", 2048, NULL,2,NULL);
  xTaskCreatePinnedToCore(&task2,"humidity readity",2048,"task2",2,NULL,1);
}
