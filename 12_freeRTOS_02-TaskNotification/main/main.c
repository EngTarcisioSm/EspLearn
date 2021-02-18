#include "freeRTOS/FreeRTOS.h"
#include "freertos/task.h"

//criação da taskhandle
static TaskHandle_t receiverHandler = NULL;

void sender(void * params)
{
  while(true)
  {
    xTaskNotify(receiverHandler,(1<<0),eSetBits);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
    xTaskNotify(receiverHandler,(1<<1),eSetBits);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
    xTaskNotify(receiverHandler,(1<<2),eSetBits);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
    xTaskNotify(receiverHandler,(1<<3),eSetBits);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
    
  }
}

void receiver(void *params)
{
  uint32_t state;
  while(true)
  {
    xTaskNotifyWait(0xFFFFFF,0,&state,portMAX_DELAY);
    printf("receive state %d time\n", state);
  }
}

void app_main(void)
{
  xTaskCreate(&receiver, "receiver", 2048, NULL, 2, &receiverHandler);
  xTaskCreate(&sender, "sender", 2048, NULL, 2, NULL);
}
