//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

int main(void) {

    OLED_Init();
    PWM_Init();
    IC_Init();

    OLED_ShowString(2, 1, "Freq: 00000Hz");

    PWM_SetPrescaler(720 - 1);
    PWM_SetCompare1(50);

    while (1) {
        OLED_ShowNum(2, 7, IC_GetFreq(), 5);
    }
}
