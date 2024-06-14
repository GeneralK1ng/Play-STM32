//
// Created by General_K1ng on 2024/4/24.
//
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void) {
    LED_Init();
    Key_Init();

    while (1) {
        KeyNum = Key_GetNum();

        if (KeyNum == 1) {
            LED1_Turn();
        } else if (KeyNum == 2) {
            LED2_Turn();
        }
    }
}