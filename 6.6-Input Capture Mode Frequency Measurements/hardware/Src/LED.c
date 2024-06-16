//
// Created by General_K1ng on 2024/4/25.
//

#include "stm32f10x.h"

/**
 * @brief 初始化LED
 *
 * 该函数用于初始化LED相关的GPIO端口，使能GPIOA时钟，配置GPIOA的PIN1和PIN2为输出模式，并设置为高电平。
 *
 * @param 无
 * @return 无
 */
void LED_Init(void) {
    // 启用GPIOA的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 配置GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2; // 配置PIN1和PIN2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 输出模式，推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 高速，50MHz

    // 根据结构体参数初始化GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 将PIN1和PIN2设置为高电平
    GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}


void LED1_ON(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_OFF(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED1_Turn(void) {
    if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0) {
        LED1_OFF();
    } else {
        LED1_ON();
    }
}

void LED2_ON(void) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void) {
    GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED2_Turn(void) {
    if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0) {
        LED2_OFF();
    } else {
        LED2_ON();
    }
}