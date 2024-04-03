#include <stdio.h>
#include <esp_log.h>
#include <esp_err.h>
#include "IS31FL3235A.hpp"

IS31FL3235A ledDriver(GPIO_NUM_11, GPIO_NUM_10, IS31FL3235A_ADDR);

extern "C" void app_main(void)
{
    ledDriver.begin();

ledDriver.sendConfig();

    while(1) {
        ledDriver.setPWM(8, 100);
        ledDriver.setPWM(9, 100);
        ledDriver.setLEDControl(8, true);
        ledDriver.setLEDControl(9, true);
        ledDriver.updatePWM();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
