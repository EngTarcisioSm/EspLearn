#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>

void callingFunc()
{
	char buffer[30];
	memset(buffer,'x', sizeof(buffer));
	printf("buffer is %s\n", buffer);
	for (int i = 0; i < 30; i++)
	{
		int num = rand() % 5;
		if (num == 0) num = 1;
		int known = 1000;
		printf("result is %d\n", known / num);
	}
	
}

void task1(void *params)
{
	callingFunc();
	vTaskDelete(NULL);
}

void app_main(void)
{
	xTaskCreate(task1, "task1", 1024 * 2, NULL, 5, NULL);
}

//parei em 11:14