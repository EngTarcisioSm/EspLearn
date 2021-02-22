#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

//1 - Primeiro passo para criar uma QUEUE, criar o seu handle
xQueueHandle queue;

//3- Neste exemplo esta sendo simulado o recebimento de um valor inteiro por uma requisição http, que se da através da variavel count que é incrementada a cada ciclo da tarefa 
void listenForHTTP(void *params)
{
    int count = 0;
    while(1)
    {
        count++;
        printf("received http message\n");
        //3 - a função queue armazena o valor a ser encaminhado dentro da "queue"
        //o primeiro parametro é o nome da queue o segundo parametro é o ponteiro para o valor a ser armazenado e o terceiro valor é o tempo de espera 
        long ok = xQueueSend(queue,&count, 1000 / portTICK_PERIOD_MS);
        if(ok)
        {
            printf("added message to queue!\n");
        }
        else
        {
            printf("failed to add message to queue!\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

//4 -Recebe valores pela QUEUE 
void task1(void *params)
{
    while(1)
    {
        int rxInt;
        if(xQueueReceive(queue, &rxInt, 5000 /portTICK_PERIOD_MS))
        {
            printf("doing something with http %d\n", rxInt);
        }
        else
        {
            printf("none!\n");
        }
    }
}


void app_main(void)
{
    //Passo 2 - criando a queue
    //  -neste caso uma queue com 3 elementos do tipo inteiro 
    queue = xQueueCreate(3,sizeof(int));

    xTaskCreate(&listenForHTTP,"get http", 2048, NULL, 1, NULL);
    xTaskCreate(&task1, "do something with http", 2048, NULL, 1, NULL);
}
