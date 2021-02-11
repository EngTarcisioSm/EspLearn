#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//contem função para gerar números aleatórios 
#include "esp_system.h"

//tratar os numeros aleatorios com alguns métodos de math.h
#include "math.h"

#define TAG "DADOS"

int dado()
{
  int random = esp_random();
  //abs() retorna o numero absoluto, sendo negativo, converte-o para positivo 
  int positiveNumber = abs(random);
  //retorna o resto da divisão limitando o numero a um valor de 0 a 5
  int diceNumber = positiveNumber % 6;
  //+1 faz o valor a ser retornado estar em um range de 1 ~ 6'
  return diceNumber +1;
}

void app_main(void)
{
  while(1)
  {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    ESP_LOGI(TAG,"número aleatório %d", dado());
  }
}
