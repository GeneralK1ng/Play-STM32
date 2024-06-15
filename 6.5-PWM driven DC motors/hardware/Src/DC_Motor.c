//
// Created by General_K1ng on 2024/6/15.
//

#include "stm32f10x.h"
#include "PWM.h"

void DC_Motor_Init(void) {
    // 启用GPIOA的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 配置GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5; // 配置PIN1和PIN2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 输出模式，推挽
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 高速，50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    PWM_Init();
}

void DC_Motor_SetSpeed(int8_t speed) {
    if (speed <= 0) {
        GPIO_SetBits(GPIOA, GPIO_Pin_4);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        PWM_SetCompare3(speed);
    } else {
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
        GPIO_SetBits(GPIOA, GPIO_Pin_5);
        PWM_SetCompare3(-speed);
    }
}