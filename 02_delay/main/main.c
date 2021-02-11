#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TAG "DELAY"

//utilizando deleay existente na biblioteca freeRTOS

void app_main(void)
{
     int i = 0;
     while(1)
     {
          vTaskDelay(1000 / portTICK_PERIOD_MS); //1segundo de delay (1000 milissegundos)
          ESP_LOGI(TAG, "in loop %d", i++);
     }
}
