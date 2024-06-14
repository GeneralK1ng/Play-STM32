//
// Created by General_K1ng on 2024/6/14.
//
#include "stm32f10x.h"

/**
 * 初始化定时器2
 * 该函数用于配置定时器2的时钟源、定时器周期、预分频器、计数模式等参数，
 * 并开启定时器2的中断服务及 NVIC 中断配置。
 */
void Timer_Init(void) {
    // 启用TIM2的时钟，这是使用TIM2的前提
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 内部时钟，上电后默认使用，其实可以不调用本函数
    TIM_InternalClockConfig(TIM2);

    // 初始化定时器配置结构体
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    // 设置定时器周期，定时器最大值为10000
    TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
    // 设置预分频器，将系统时钟分频到7200Hz
    TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;
    // 设置时钟分频因子
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    // 设置定时器计数模式为向上计数
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    // 设置重复计数器，本例中未使用
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;

    // 根据配置结构体初始化定时器2
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    // 清除定时器2的更新中断标志位
    // 因为在定时器初始化后，会默认建立一个更新触发事件，也就是会立刻触发一次中断
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);

    // 开启定时器2的更新中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    // 配置 NVIC 的中断优先级分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    // 初始化 NVIC 结构体
    NVIC_InitTypeDef NVIC_InitStructure;
    // 设置中断通道为TIM2
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    // 开启TIM2中断
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    // 设置抢占优先级为2
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    // 设置子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;

    // 根据配置结构体初始化 NVIC
    NVIC_Init(&NVIC_InitStructure);

    // 启用定时器2
    TIM_Cmd(TIM2, ENABLE);
}


/*
void TIM2_IRQHandler(void) {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}*/
