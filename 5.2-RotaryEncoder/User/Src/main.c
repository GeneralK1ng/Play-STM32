//
// Created by General_K1ng on 2024/4/24.
//
#include "OLED.h"
#include "Encoder.h"

int Num;

int main(void) {
    OLED_Init();
    Encoder_Init();

    OLED_ShowString(1, 3 , "Hello World!");
    OLED_ShowString(3, 3 , "General_K1ng");

    OLED_ShowString(2, 1, "Num: ");

    while (1) {
        Num += Encoder_GetCount();
        OLED_ShowSignedNum(2, 6, Num, 5);
    }
}