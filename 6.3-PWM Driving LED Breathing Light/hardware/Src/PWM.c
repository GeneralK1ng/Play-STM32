//
// Created by General_K1ng on 2024/6/14.
//
#include "stm32f10x.h"

void PWM_Init(void) {
    // 启用 TIM2 的时钟，这是使用TIM2的前提
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    // 启用 GPIOA 的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 配置GPIO初始化结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // 配置PIN0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 高速，50MHz

    // 根据结构体参数初始化GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    // 内部时钟，上电后默认使用，其实可以不调用本函数
    TIM_InternalClockConfig(TIM2);

    // 初始化定时器配置结构体
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;    // 设置定时器周期，定时器最大值为10000，即 ARR
    TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;    // 设置预分频器，将系统时钟分频到7200Hz，即 PSC
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;    // 设置时钟分频因子
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;    // 设置定时器计数模式为向上计数
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;    // 设置重复计数器，本例中未使用

    // 根据配置结构体初始化定时器2
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure); // 初始化结构体

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;  // 设置占空比，占空比为 50，即定时器输出为低电平，即 CCR

    /*
     * PWM频率：Freq = CK_PSC / (PSC + 1) / (ARR + 1)
     * PWM占空比：Duty = CCR / (ARR + 1)
     * PWM分辨率: Reso = 1 / (ARR + 1)
     * */

    TIM_OC1Init(TIM2, &TIM_OCInitStructure);

    // 启用定时器2
    TIM_Cmd(TIM2, ENABLE);
}

void PWM_SetCompare1(uint16_t Compare) {
    TIM_SetCompare1(TIM2, Compare);
}