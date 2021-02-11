#include <stdio.h>
#include "esp_log.h"
#include "string.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
  uint8_t u8c = 0;
  uint8_t u8str[100];

  memset(&u8str, 0x00, sizeof(u8str));

  //capturar a tela até que apareça "\n"
  while(u8c != '\n')
  {
    u8c = getchar();
    if(u8c != 0xff)
    {
      //a fun~]ap str len informa o tamanho de uma string ou de um array, não contando o zero 
      u8str[strlen(&u8str)] = u8c;
      printf("%c", u8c);
      //printf("%c", "u8c");
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  printf("\nVoce digitou: %s\n", u8str);
}
