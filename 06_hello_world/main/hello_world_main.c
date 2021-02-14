/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
//lidar com timer, neste caso em especifico para efetuar delays 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//trás informações sobre o chip
#include "esp_system.h"
//trás informações sobre a memoria flash
#include "esp_spi_flash.h"


void app_main()
{
    printf("Hello world!\n");

    /* Print chip information */
    //estrutura que pode ser vista sua logica, contem informações do chip como modelo, caracteristicas, numero de nucleo e informações a respeito o modelo de revisão do chip, a variavel da estrutura features, de 32 bits é uma mascara de bits contendo diversas informações a respeito do chip:
    //  -tem memoria flash embutida?
    //  - tem wifi
    //  - tem bluetooth low energy
    //  - tem bluetooth 
    //  - ...
    esp_chip_info_t chip_info;
    //a função abaixo retornará os dados da do chip passando o endereço da estrutura acima 
    esp_chip_info(&chip_info);
    //printa o numero de de cores do microcontrolador, se existe bluetooth 
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    //printa o numero da revisão do microcontrolador
    printf("silicon revision %d, ", chip_info.revision);

    //printa a quantidade de memoria flash  disponivel  retornando esse numero em megabytes, retorna também se esse valor esta integrado no chip ou externo ao chip, como se trata do WROOM estará externo 
    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    //saber a versão da idf que esta sendo executada 
    printf("idf version is %s\n", esp_get_idf_version());

    //saber o mac address do chip
    //  -passo1 criar um array de 6 posições para armazenar o valor 
    uint8_t chipId[0];
    //  -passo2 chamar a função que preenche o array acima com o valor do mac address 
    esp_efuse_mac_get_default(&chipId);
    //  -passo3 imprimir os valores, configurando para a impressão retornar o valor em hexa, utilizando %x, o numero afrente indica a quantidade de espaço entre os numeros, no caso abaixo seriam 2 espaços
    printf("mac / chip id: %02x%02x%02x%02x%02x%02x \n",chipId[0],chipId[1],chipId[2],chipId[3],chipId[4],chipId[5]);

    //animação indicando que o chip será resetado, efetuando uma contagem de 10 a 0 
    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    //Maneira de limpar o buffer serial 
    fflush(stdout);
    //reseta o chip
    esp_restart();
}
