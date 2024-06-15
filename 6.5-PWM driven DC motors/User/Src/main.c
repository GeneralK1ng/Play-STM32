//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "DC_Motor.h"
#include "Key.h"
#include "Delay.h"

uint8_t  key_num;
int8_t speed;

int main(void) {

    OLED_Init();
    DC_Motor_Init();
    Key_Init();

    OLED_ShowString(2, 1, "DC Speed:");

    while (1) {
        key_num = Key_GetNum();
        if (key_num == 1) {
            speed += 20;
            if (speed > 100) {
                DC_Motor_SetSpeed(0);
                Delay_ms(1800);
                speed = -100;
            }
        }
        DC_Motor_SetSpeed(speed);
        OLED_ShowSignedNum(2, 11, speed, 3);
    }


}
