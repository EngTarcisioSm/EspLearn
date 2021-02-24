#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

EventGroupHandle_t evGrp;

const int gotHttp = BIT0; //(1<<0)
const int gotBLUE = BIT1; //(1<<1)


void listenForHTTP(void *params)
{
	while (1)
	{
		//seta um unico bit
		xEventGroupSetBits(evGrp, gotHttp);
		printf("got http\n");
		vTaskDelay(2000 / portTICK_PERIOD_MS);
	}
}

void ListenForBluetooth(void *params)
{
	while (1)
	{
		xEventGroupSetBits(evGrp, gotBLUE);
		printf("got Blue\n");
		vTaskDelay(5000 / portTICK_PERIOD_MS);
	}
}

void task1(void *params)
{
	while (1)
	{
		//função de verificação dos bits ativos 
		xEventGroupWaitBits(evGrp, gotHttp | gotBLUE,true, true, portMAX_DELAY);
		printf("received http and BLUE\n");
	}
}

void app_main(void)
{
	//definição do evento group
	evGrp = xEventGroupCreate();
	xTaskCreate(&listenForHTTP ,"get http",2048,NULL,1,NULL);
	xTaskCreate(&ListenForBluetooth ,"get bluetooth",2048,NULL,1,NULL);
	xTaskCreate(&task1 ,"task1",2048,NULL,1,NULL);
}
