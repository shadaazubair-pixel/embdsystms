#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_GPIO 2
#define BUTTON_GPIO 0

void app_main(void)
{
    gpio_reset_pin(BUTTON_GPIO);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_GPIO);
    


    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    

    while(1)
    {
        if((gpio_get_level(BUTTON_GPIO)))
        {
            gpio_set_level(LED_GPIO, 0);
        }
        else{
            gpio_set_level(LED_GPIO, 1);
        }

         vTaskDelay(1000/portTICK_PERIOD_MS);


        

    }



}
