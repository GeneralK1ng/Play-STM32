//
// Created by General_K1ng on 2024/4/24.
//
#include "stm32f10x.h"

void delay(int64_t time) {
    while (time--) {
        __NOP();
    }
}

int main(void) {
    // 寄存器点灯
    /*
     *  RCC->APB2ENR = 0x00000010;
        GPIOC->CRH = 0x00300000;
        GPIOC->ODR = 0x00000000;*/

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    while (1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay(2000000);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay(5000000);
    }
}