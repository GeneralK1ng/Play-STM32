//
// Created by General_K1ng on 2024/4/24.
//
#include <stdlib.h>
#include "stm32f10x.h"
#include "Delay.h"

int main(void) {
    // Initialize GPIO
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

    // 开启GPIOA使能时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    //GPIO_SetBits(GPIOA, GPIO_Pin_0);

    uint16_t mask = 0x0001;  // 初始化掩码为0001

    while (1) {
        for (int i = 0; i < 8; ++i) {
            GPIO_Write(GPIOA, ~(mask << i));
            int random = rand() % 500;
            Delay_ms(random);
        }
    }
}