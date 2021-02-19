#include "freeRTOS/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

//criação da mutexhandle
xSemaphoreHandle mutexBus;

void writeToBus(char *message)
{
  printf(message);
}

void task1(void * params)
{
  while(true)
  {
    if (xSemaphoreTake(mutexBus, 1000 / portTICK_PERIOD_MS))
    {
      writeToBus("humidity is 50\n");
      xSemaphoreGive(mutexBus);
    }
    else
    {
      printf("humidity timeout...\n");
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task2(void *params)
{
  uint32_t state;
  while(true)
  {
    if (xSemaphoreTake(mutexBus, 1000 / portTICK_PERIOD_MS))
    {
      writeToBus("temperature is 25C \n");
      xSemaphoreGive(mutexBus);
    }
    else
    {
      printf("temperature timeout...\n");
    }
    
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void app_main(void)
{
  mutexBus = xSemaphoreCreateMutex();
  xTaskCreate(&task1, "task1", 2048, NULL, 2, NULL);
  xTaskCreate(&task2, "task2", 2048, NULL, 2, NULL);
}
