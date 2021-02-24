#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "esp_system.h"


void on_timer(TimerHandle_t xTime)
{
	printf("time hit %lld\n", esp_timer_get_time() /1000);
}


void app_main(void)
{
	//retorna o tempo do microcontrolador em microssegundos 
	printf("app started %lld\n", esp_timer_get_time() / 1000);

	//timer com freeRTOS 
	//primeiro parametro: nome do timer (string normal)
	//segundo parametro: quantidade de tempo a ser contado 
	//terceiro paramenttro: repetição do timer (true ou false ) 
	//quarto parametro ID do timer 
	//quinto parametro: função de callback 
	TimerHandle_t xTimer = xTimerCreate("my timer", pdMS_TO_TICKS(1000), true, NULL, on_timer);

	xTimerStart(xTimer,0);
}
