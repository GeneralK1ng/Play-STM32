//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "PWM.h"
#include "Delay.h"

uint8_t light = 0;

void lightControlLoop(); // 循环控制光亮度

int main(void) {

    OLED_Init();
    PWM_Init();

    lightControlLoop();

}

void updateOLEDAndPWM(int light) {
    OLED_ShowString(1, 1, "Light: ");
    OLED_ShowNum(1, 7, light, 3);
    PWM_SetCompare1(light);
    Delay_ms(50);
}

void lightControlLoop() {
    int direction = 1; // 1表示增加光亮度，-1表示减少光亮度

    while (1) {
        light += direction;

        if (light >= 100) {
            light = 100;
            direction = -1; // 开始递减
        } else if (light <= 0) {
            light = 0;
            direction = 1; // 开始递增
        }

        updateOLEDAndPWM(light);
    }
}