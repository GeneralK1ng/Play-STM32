//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "AD.h"
#include "Delay.h"

uint16_t AD_value;
float AD_voltage;

int main(void) {
    OLED_Init();
    AD_Init();

    OLED_ShowString(2, 1, "ADValue:");
    OLED_ShowString(3, 1, "Voltage:0.00V");

    while (1) {
        AD_value = AD_GetValue();
        AD_voltage = (float)AD_value / 4095.0 * 3.3;
        OLED_ShowNum(2, 9, AD_value, 4);
        OLED_ShowNum(3, 9, AD_voltage, 1);
        OLED_ShowNum(3, 11, (uint16_t)(AD_voltage * 100) % 100, 2);

        Delay_ms(100);
    }
}