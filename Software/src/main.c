#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_GPIO 2
void app_main() {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED_GPIO, 1); // Turn LED on
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
        gpio_set_level(LED_GPIO, 0); // Turn LED off
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}