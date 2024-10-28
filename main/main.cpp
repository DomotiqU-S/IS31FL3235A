#include <stdio.h>
#include <esp_log.h>
#include <esp_err.h>
#include "IS31FL3235A.hpp"

IS31FL3235A ledDriver(GPIO_NUM_11, GPIO_NUM_10, IS31FL3235A_ADDR);

extern "C" void app_main(void)
{
    ledDriver.begin();

    ledDriver.reset();
    ledDriver.sendConfig();

    while(1) {
        ledDriver.setPWM(6, 100);
        ledDriver.setPWM(7, 100);
        ledDriver.setLEDControl(6, true);
        ledDriver.setLEDControl(7, true);
        ledDriver.updatePWM();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
