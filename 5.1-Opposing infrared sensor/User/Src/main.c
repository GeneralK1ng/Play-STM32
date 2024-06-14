//
// Created by General_K1ng on 2024/4/24.
//
#include "stm32f10x.h"
#include "OLED.h"
#include "CountSensor.h"


int main(void) {
    OLED_Init();
    CountSensor_Init();

    OLED_ShowString(1, 3 , "Hello World!");
    OLED_ShowString(3, 3 , "General_K1ng");

    OLED_ShowString(2, 1 , "Count: ");



    while (1) {
        OLED_ShowNum(2, 8, CountSensor_GetCount(), 5);
    }
}