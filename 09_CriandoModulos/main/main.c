#include <stdio.h>
#include "esp_log.h"
#include "module.h"
#include "module2.h"

void app_main(void)
{
  int result = functionModule(2,3);
  int result2 = functionModule2(2,3);
  printf("value id %d\n",  result);
  printf("value id %d\n",  result2);
  
}
