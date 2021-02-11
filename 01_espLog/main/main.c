#include <stdio.h>
#include "esp_log.h"


void app_main(void)
{
  esp_log_level_set("LOG", ESP_LOG_INFO);
  ESP_LOGE("TAG", "Tihis is an error");
  ESP_LOGW("TAG", "This is a warning");
  ESP_LOGI("LOG", "This is an info");
  ESP_LOGD("TAG", "THis is debugg");
  ESP_LOGV("TAG", "This is verbose");

  int log = 0;
  ESP_LOGE("TAG 2", "Tihis is an error %d", log++);
  ESP_LOGW("TAG 2", "This is a warning %d", log++);
  ESP_LOGI("LOG 2", "This is an info %d", log++);
  ESP_LOGD("TAG 2", "THis is debugg %d", log++);
  ESP_LOGV("TAG 2", "This is verbose %d", log++);
}