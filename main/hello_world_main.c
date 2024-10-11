#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED GPIO_NUM_12 // Sử dụng chân GPIO 12

void led_task(void *pvParameter)
{
    // Cấu hình chân GPIO cho LED
    esp_rom_gpio_pad_select_gpio(LED);
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    while (1) // Vòng lặp vô hạn để task không bị kết thúc
    {
        // Bật LED
        gpio_set_level(LED, 1);
        vTaskDelay(100 / portTICK_PERIOD_MS); // LED On trong 100ms

        // Tắt LED
        gpio_set_level(LED, 0);
        vTaskDelay(400 / portTICK_PERIOD_MS); // LED Off trong 400ms
    }
}

void app_main(void)
{
    // Tạo task điều khiển LED
    xTaskCreate(&led_task, "led_task", 2048, NULL, 5, NULL);
}
