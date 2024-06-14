//
// Created by General_K1ng on 2024/4/24.
//
#include "stm32f10x.h"
#include "OLED.h"
#include "delay.h"
#include "LED.h"

int main(void) {
    OLED_Init();
    LED_Init();

    OLED_ShowString(1, 3 , "Hello World!");
    OLED_ShowString(3, 3 , "General_K1ng");

    while (1) {

        LED1_ON();
        Delay_ms(100);
        LED1_OFF();
        Delay_ms(100);
    }
}