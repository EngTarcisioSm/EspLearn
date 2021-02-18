#include "freeRTOS/FreeRTOS.h"
#include "freertos/task.h"

//criação da taskhandle
static TaskHandle_t receiverHandler = NULL;

void sender(void * params)
{
  while(true)
  {
    static uint32_t count = 0;
    xTaskNotifyGive(receiverHandler);
    printf("sender %d\n", count++);
    vTaskDelay( 5000 / portTICK_PERIOD_MS);
  }
}

void receiver(void *params)
{
  while(true)
  {
    ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
    printf("received notification\n");
  }
}

void app_main(void)
{
  xTaskCreate(&receiver, "receiver", 2048, NULL, 2, &receiverHandler);
  xTaskCreate(&sender, "sender", 2048, NULL, 2, NULL);
}
