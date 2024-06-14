//
// Created by General_K1ng on 2024/4/25.
//
#include "stm32f10x.h"

uint16_t CountSensor_Count;

/**
 * @brief 初始化计数传感器
 *
 * 该函数主要用于配置GPIO引脚、EXTI中断和NVIC中断控制器，以初始化计数传感器。
 * 具体步骤包括：开启时钟、配置GPIO引脚为上拉输入、配置EXTI中断线、配置NVIC中断。
 *
 * @param 无
 * @return 无
 */
void CountSensor_Init(void){
    // 开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);

    EXTI_InitTypeDef EXTI_InitStructure;
    EXTI_InitStructure.EXTI_Line = EXTI_Line14;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    EXTI_Init(&EXTI_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_GetCount(void){
    return CountSensor_Count;
}


void EXTI15_10_IRQHandler(void){
    if (EXTI_GetFlagStatus(EXTI_Line14) == SET) {
        CountSensor_Count++;
        EXTI_ClearITPendingBit(EXTI_Line14);
    }
}