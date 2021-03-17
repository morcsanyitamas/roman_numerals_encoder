/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "ws2812.h"
// #include "ws2812_test.h"

static const char *TAG = "example";

const ws2812_pixel_t green_pixel = {255, 0, 0};
const ws2812_pixel_t red_pixel = {0, 255, 0};
const ws2812_pixel_t blue_pixel = {0, 0, 255};

ws2812_pixel_t pixels[64] = {green_pixel, red_pixel, blue_pixel};

void set_pixel(ws2812_pixel_t *pixels, uint8_t index) {
  for (uint8_t i = 0; i < 64; i++) {
    pixels[i].green = 0;
    pixels[i].red = 0;
    pixels[i].blue = 0;
  }
  pixels[index].blue = 100;
  pixels[index].red = 0;
  pixels[index].green = 0;
}

void app_main(void) {
  ws2812_init();
  ESP_LOGI(TAG, "WS2812 init done...");
  vTaskDelay(200 / portTICK_PERIOD_MS);

  ESP_LOGI(TAG, "Turning on -- 0 -- LED to BLUE");
  set_pixel(pixels, 7);
  ws2812_update(pixels);

  // vTaskDelay(200 / portTICK_PERIOD_MS);

  // ESP_LOGI(TAG, "Turning on -- 1 -- LED to BLUE");
  // set_pixel(pixels, 1);
  // ws2812_update(pixels);

  // for (uint8_t i = 0; i < 64; i++) {
  //   ESP_LOGI(TAG, "Turning on -- %d -- LED to BLUE", i);
  //   set_pixel(pixels, i);
  //   ws2812_update(pixels);
  //   vTaskDelay(5000 / portTICK_PERIOD_MS);
  // }

  uint32_t counter = 0;

  while (1) {
    ESP_LOGI(TAG, "counter value: %d", counter);

    set_pixel(pixels, counter);
    ws2812_update(pixels);
    counter++;

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
