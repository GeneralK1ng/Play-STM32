//
// Created by General_K1ng on 2024/6/16.
//
#include "stm32f10x.h"

/**
 * 初始化IC（Input Capture）功能。
 * 该函数配置了TIM3以及与其相关的GPIO，用于捕获外部输入信号。
 *
 * 注意：此处的IC初始化是针对特定硬件和应用需求的，不适用于所有情况。
 */
void IC_Init(void) {
    /* 启用TIM3和GPIOA的时钟，这是配置它们之前必需的步骤。 */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* 配置GPIOA的PIN6为输入模式，用于捕获输入信号。 */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; /* 上拉输入模式。 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; /* 配置PIN6。 */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; /* GPIO速度设置为50MHz。 */
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* 配置TIM3内部时钟。 */
    TIM_InternalClockConfig(TIM3);

    /* 配置TIM3的基本定时器参数。 */
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1; /* 定时器周期设为65535。 */
    TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1; /* 预分频器设为35。 */
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /* 时钟分频因子设为1。 */
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; /* 定时器计数模式设为向上计数。 */
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; /* 循环计数器设为0。 */
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    /* 配置TIM3的输入捕获通道1。 */
    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1; /* 选择TIM3的通道1。 */
    TIM_ICInitStructure.TIM_ICFilter = 0xF; /* 输入滤波器设为0xF。 */
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; /* 输入极性设为上升沿。 */
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; /* 输入捕获预分频器设为不分频。 */
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; /* 输入捕获信号选择为直接TI。 */
    TIM_ICInit(TIM3, &TIM_ICInitStructure);

    /* 选择TIM3的输入触发源为TI1FP1，并设置TIM3的从机模式为重置模式。 */
    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);

    /* 启用TIM3。 */
    TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void) {
    return 2000000 / TIM3->CCR1;
}