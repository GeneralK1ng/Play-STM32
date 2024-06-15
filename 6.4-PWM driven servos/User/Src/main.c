//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "Servo.h"
#include "Delay.h"
#include "Key.h"

uint8_t key_num;
float angle;

int main(void) {

    OLED_Init();
    Key_Init();
    Servo_Init();

    OLED_ShowString(1, 1, "angle:");

    while (1) {
        key_num = Key_GetNum();
        if (key_num == 1) {
            angle += 30;
            if (angle > 180) {
                angle = 0;
            }
        }
        Servo_SetAngle(angle);
        OLED_ShowNum(1, 7, angle, 3);
    }
}

