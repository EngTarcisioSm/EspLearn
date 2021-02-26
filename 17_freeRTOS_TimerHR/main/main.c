#include <stdio.h>
#include "esp_timer.h"

void timer_callback(void *args)
{

}

void app_main(void)
{
	const esp_timer_create_args_t esp_timer_create_args = {
		.callback = timer_callback,
		.name = "Mytimer"
	};
	esp_timer_handle_t esp_timer_handle;
	esp_timer_create(esp_timer_create_args, &esp_timer_handle);

	//parei em 04:06
}
