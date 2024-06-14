//
// Created by General_K1ng on 2024/4/25.
//

#include "stm32f10x.h"

void Buzzer_Init(void) {
    // 启用GPIOB的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 配置GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; // 配置PIN1和PIN2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 输出模式，推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 高速，50MHz

    // 根据结构体参数初始化GPIOA
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 将PIN1和PIN2设置为高电平
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_ON(void) {
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_OFF(void) {
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void Buzzer_Turn(void) {
    if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 0) {
        Buzzer_OFF();
    } else {
        Buzzer_ON();
    }
}